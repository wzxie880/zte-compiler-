import tvm
from tvm import te
from tvm import autotvm
from tvm import topi, tir
import numpy as np

import zte
from zte import get_env

env = get_env()

class conv2d_cpu:
    def __init__(self, data, kernel, strides, padding):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ric = te.reduce_axis((0, ishape[3]), name='ric')
        rkh = te.reduce_axis((0, kshape[1]), name='rkh')
        rkw = te.reduce_axis((0, kshape[2]), name='rkw')

        self.out = te.compute(
            (ishape[0], oheight, owidth, kshape[0]),
            lambda n, i, j, c: te.sum(
                self.pad_data[n, i * strides[0] + rkh, j * strides[0] + rkw, ric].astype("float32") * self.kernel[c, rkh, rkw, ric].astype("float32"),
                axis=[rkh, rkw, ric]
            ), name='Y'
        )

class conv2d_16:

    def __init__(self, data, kernel, strides, padding):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]

        # calculate padding parameter
        if (oheight * owidth) % gemm_size == 0:
            padded_length = oheight * owidth
            middle_pad = 0
        else:
            padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
            middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                         (padded_length // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel_2d, (output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if(reduction_repeat>128):
            if(reduction_repeat%128==0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif(reduction_repeat%72==0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int16") * self.weight[x, self.k0, self.k1, y, self.k2].astype("int16"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.middle = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="middle"
        )
        self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))
        # self.middle_reshape = te.compute(
        #     (padded_length, output_channel),
        #     lambda i, j: self.middle[i//8, j//8, i%8, j%8]
        # )
        # 
        # self.out = te.compute(
        #     (1, oheight, owidth, output_channel),
        #     lambda n, h, w, c: self.middle_reshape[n*oheight*owidth+h*owidth+w, c]
        # )
        # print(topi.utils.get_const_tuple(self.out.shape))

        class conv2d_16:

            def __init__(self, data, kernel, strides, padding):
                self.data = data
                self.kernel = kernel
                self.strides = strides
                self.padding = padding

                gemm_size = 8

                # shape get
                ishape = topi.utils.get_const_tuple(self.data.shape)
                kshape = topi.utils.get_const_tuple(self.kernel.shape)

                # output shape computation
                oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
                owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

                # padding for convolution
                if padding:
                    self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
                else:
                    self.pad_data = self.data

                ishape = topi.utils.get_const_tuple(self.pad_data.shape)

                input_channel = ishape[3]
                output_channel = kshape[0]
                window_size = kshape[1] * kshape[2]

                # calculate padding parameter
                if (oheight * owidth) % gemm_size == 0:
                    padded_length = oheight * owidth
                    middle_pad = 0
                else:
                    padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
                    middle_pad = padded_length - oheight * owidth

                # im2col, first transpose to 6-d
                self.mdata = te.compute(
                    (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
                    lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
                    name="mdata"
                )

                # reshape data and weight to 2d
                self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
                self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

                # pad data_2d to match [16, 16]
                self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

                # split data and weight with 16
                self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                                 (padded_length // gemm_size, gemm_size,
                                                  input_channel * window_size // gemm_size, gemm_size))
                self.kernel_4d = topi.reshape(self.kernel_2d, (
                output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

                # transpose data and weight to move two axis of 16 to the end
                self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
                self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

                A_shape = topi.utils.get_const_tuple(self.A.shape)
                B_shape = topi.utils.get_const_tuple(self.B.shape)

                reduction_repeat = A_shape[1]
                if (reduction_repeat > 128):
                    if (reduction_repeat % 128 == 0):
                        self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                        self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                    elif (reduction_repeat % 72 == 0):
                        self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                        self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                    else:
                        print("error")
                        self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                        self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
                else:
                    self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                    self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

                A1_shape = topi.utils.get_const_tuple(self.A1.shape)
                B1_shape = topi.utils.get_const_tuple(self.B1.shape)

                self.feature_input = te.compute(
                    A1_shape,
                    lambda x, r, i, y, j: self.A1[x, r, i, y, j],
                    name="feature_input"
                )

                self.weight_input = te.compute(
                    B1_shape,
                    lambda x, r, i, y, j: self.B1[x, r, i, y, j],
                    name="weight_input"
                )

                self.feature = te.compute(
                    A1_shape,
                    lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
                    name="feature"
                )

                self.weight = te.compute(
                    B1_shape,
                    lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
                    name="weight"
                )

                self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
                self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
                self.k2 = te.reduce_axis((0, gemm_size), name="k2")

                self.middle_buffer = te.compute(
                    (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
                    lambda i, x, j, y: te.sum(
                        self.feature[i, self.k0, self.k1, j, self.k2].astype("int16") * self.weight[
                            x, self.k0, self.k1, y, self.k2].astype("int16"),
                        axis=[self.k0, self.k1, self.k2]
                    ),
                    name="middle_buffer"
                )

                self.middle = te.compute(
                    (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
                    lambda i, x, j, y: self.middle_buffer[i, x, j, y],
                    name="middle"
                )
                self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
                self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
                self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

                self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))
                # self.middle_reshape = te.compute(
                #     (padded_length, output_channel),
                #     lambda i, j: self.middle[i//8, j//8, i%8, j%8]
                # )
                # 
                # self.out = te.compute(
                #     (1, oheight, owidth, output_channel),
                #     lambda n, h, w, c: self.middle_reshape[n*oheight*owidth+h*owidth+w, c]
                # )
                # print(topi.utils.get_const_tuple(self.out.shape))

class conv2d:

    def __init__(self, data, kernel, strides, padding):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]

        # calculate padding parameter
        if (oheight * owidth) % gemm_size == 0:
            padded_length = oheight * owidth
            middle_pad = 0
        else:
            padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
            middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                         (padded_length // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel_2d, (output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if(reduction_repeat>128):
            if(reduction_repeat%128==0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif(reduction_repeat%72==0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int32") * self.weight[x, self.k0, self.k1, y, self.k2].astype("int32"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.middle = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="middle"
        )
        self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))
        # self.middle_reshape = te.compute(
        #     (padded_length, output_channel),
        #     lambda i, j: self.middle[i//8, j//8, i%8, j%8]
        # )
        # 
        # self.out = te.compute(
        #     (1, oheight, owidth, output_channel),
        #     lambda n, h, w, c: self.middle_reshape[n*oheight*owidth+h*owidth+w, c]
        # )
        # print(topi.utils.get_const_tuple(self.out.shape))

        class conv2d_16:

            def __init__(self, data, kernel, strides, padding):
                self.data = data
                self.kernel = kernel
                self.strides = strides
                self.padding = padding

                gemm_size = 8

                # shape get
                ishape = topi.utils.get_const_tuple(self.data.shape)
                kshape = topi.utils.get_const_tuple(self.kernel.shape)

                # output shape computation
                oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
                owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

                # padding for convolution
                if padding:
                    self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
                else:
                    self.pad_data = self.data

                ishape = topi.utils.get_const_tuple(self.pad_data.shape)

                input_channel = ishape[3]
                output_channel = kshape[0]
                window_size = kshape[1] * kshape[2]

                # calculate padding parameter
                if (oheight * owidth) % gemm_size == 0:
                    padded_length = oheight * owidth
                    middle_pad = 0
                else:
                    padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
                    middle_pad = padded_length - oheight * owidth

                # im2col, first transpose to 6-d
                self.mdata = te.compute(
                    (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
                    lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
                    name="mdata"
                )

                # reshape data and weight to 2d
                self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
                self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

                # pad data_2d to match [16, 16]
                self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

                # split data and weight with 16
                self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                                 (padded_length // gemm_size, gemm_size,
                                                  input_channel * window_size // gemm_size, gemm_size))
                self.kernel_4d = topi.reshape(self.kernel_2d, (
                output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

                # transpose data and weight to move two axis of 16 to the end
                self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
                self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

                A_shape = topi.utils.get_const_tuple(self.A.shape)
                B_shape = topi.utils.get_const_tuple(self.B.shape)

                reduction_repeat = A_shape[1]
                if (reduction_repeat > 128):
                    if (reduction_repeat % 128 == 0):
                        self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                        self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                    elif (reduction_repeat % 72 == 0):
                        self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                        self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                    else:
                        print("error")
                        self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                        self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
                else:
                    self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                    self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

                A1_shape = topi.utils.get_const_tuple(self.A1.shape)
                B1_shape = topi.utils.get_const_tuple(self.B1.shape)

                self.feature_input = te.compute(
                    A1_shape,
                    lambda x, r, i, y, j: self.A1[x, r, i, y, j],
                    name="feature_input"
                )

                self.weight_input = te.compute(
                    B1_shape,
                    lambda x, r, i, y, j: self.B1[x, r, i, y, j],
                    name="weight_input"
                )

                self.feature = te.compute(
                    A1_shape,
                    lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
                    name="feature"
                )

                self.weight = te.compute(
                    B1_shape,
                    lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
                    name="weight"
                )

                self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
                self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
                self.k2 = te.reduce_axis((0, gemm_size), name="k2")

                self.middle_buffer = te.compute(
                    (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
                    lambda i, x, j, y: te.sum(
                        self.feature[i, self.k0, self.k1, j, self.k2].astype("int16") * self.weight[
                            x, self.k0, self.k1, y, self.k2].astype("int16"),
                        axis=[self.k0, self.k1, self.k2]
                    ),
                    name="middle_buffer"
                )

                self.middle = te.compute(
                    (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
                    lambda i, x, j, y: self.middle_buffer[i, x, j, y],
                    name="middle"
                )
                self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
                self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
                self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

                self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))
                # self.middle_reshape = te.compute(
                #     (padded_length, output_channel),
                #     lambda i, j: self.middle[i//8, j//8, i%8, j%8]
                # )
                # 
                # self.out = te.compute(
                #     (1, oheight, owidth, output_channel),
                #     lambda n, h, w, c: self.middle_reshape[n*oheight*owidth+h*owidth+w, c]
                # )
                # print(topi.utils.get_const_tuple(self.out.shape))
                
class conv2d_8hwc:

    def __init__(self, data, kernel, strides, padding):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        assert ishape[0] % 8 == 0
        assert ishape[3] % 8 == 0
        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        batch = ishape[0]
        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]
        padded_length = oheight * owidth * batch

        # calculate padding parameter
        # if (oheight * owidth) % gemm_size == 0:
        #     padded_length = oheight * owidth
        #     middle_pad = 0
        # else:
        #     padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
        #     middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[n, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        # self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        # self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        # self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata,
                                         (padded_length // gemm_size, gemm_size,
                                          input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel, (
        output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if (reduction_repeat > 128):
            if (reduction_repeat % 128 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif (reduction_repeat % 72 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int32") * self.weight[
                    x, self.k0, self.k1, y, self.k2].astype("int32"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.middle = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="middle"
        )
        self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        # self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        # self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.out = topi.reshape(self.middle_tran, (batch, oheight, owidth, output_channel))
        # self.middle_reshape = te.compute(
        #     (padded_length, output_channel),
        #     lambda i, j: self.middle[i//8, j//8, i%8, j%8]
        # )
        # 
        # self.out = te.compute(
        #     (1, oheight, owidth, output_channel),
        #     lambda n, h, w, c: self.middle_reshape[n*oheight*owidth+h*owidth+w, c]
        # )
        # print(topi.utils.get_const_tuple(self.out.shape))
        
class max_pooling:
    def __init__(self, data, strides, padding):
        self.data = data
        self.strides = strides
        self.padding = padding

        self.pad_data = topi.nn.pad(self.data, [0, self.padding[0], self.padding[1], 0], name="pad_data")

        self.vec0a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2, c],
            name="vec0a"
        )

        self.vec0b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2, c + 32],
            name="vec0b"
        )

        self.vec1a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2, c],
            name="vec1a"
        )

        self.vec1b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2, c + 32],
            name="vec1b"
        )

        self.vec2a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2, c],
            name="vec2a"
        )

        self.vec2b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2, c+32],
            name="vec2b"
        )

        self.vec3a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2 + 1, c],
            name="vec3a"
        )

        self.vec3b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2 + 1, c + 32],
            name="vec3b"
        )

        self.vec4a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2 + 1, c],
            name="vec4a"
        )

        self.vec4b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2 + 1, c+32],
            name="vec4b"
        )

        self.vec5a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2 + 1, c],
            name="vec5a"
        )

        self.vec5b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2 + 1, c+32],
            name="vec5b"
        )

        self.vec6a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2 + 2, c],
            name="vec6a"
        )

        self.vec6b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2 + 2, c+32],
            name="vec6b"
        )

        self.vec7a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2 + 2, c],
            name="vec7a"
        )

        self.vec7b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2 + 2, c+32],
            name="vec7b"
        )

        self.vec8a = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2 + 2, c],
            name="vec8a"
        )

        self.vec8b = te.compute(
            (1, 56, 56, 32),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2 + 2, c+32],
            name="vec8b"
        )

        self.vec0a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec0a[n, i, j, c], name="vec0_buf")
        self.vec1a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec1a[n, i, j, c], name="vec1_buf")
        self.vec2a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec2a[n, i, j, c], name="vec2_buf")
        self.vec3a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec3a[n, i, j, c], name="vec3_buf")
        self.vec4a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec4a[n, i, j, c], name="vec4_buf")
        self.vec5a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec5a[n, i, j, c], name="vec5_buf")
        self.vec6a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec6a[n, i, j, c], name="vec6_buf")
        self.vec7a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec7a[n, i, j, c], name="vec7_buf")
        self.vec8a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec8a[n, i, j, c], name="vec8_buf")

        self.vec0b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec0b[n, i, j, c], name="vec0_buf")
        self.vec1b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec1b[n, i, j, c], name="vec1_buf")
        self.vec2b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec2b[n, i, j, c], name="vec2_buf")
        self.vec3b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec3b[n, i, j, c], name="vec3_buf")
        self.vec4b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec4b[n, i, j, c], name="vec4_buf")
        self.vec5b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec5b[n, i, j, c], name="vec5_buf")
        self.vec6b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec6b[n, i, j, c], name="vec6_buf")
        self.vec7b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec7b[n, i, j, c], name="vec7_buf")
        self.vec8b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.vec8b[n, i, j, c], name="vec8_buf")

        self.middle1a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec0a_buf[n, i, j, c], self.vec1a_buf[n, i, j, c]), name="middel1")
        self.middle1a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle1a[n, i, j, c], name="middel1_buf")

        self.middle2a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec2a_buf[n, i, j, c], self.middle1a_buf[n, i, j, c]), name="middel2")
        self.middle2a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle2a[n, i, j, c], name="middel2_buf")

        self.middle3a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec3a_buf[n, i, j, c], self.middle2a_buf[n, i, j, c]), name="middel3")
        self.middle3a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle3a[n, i, j, c], name="middel3_buf")

        self.middle4a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec4a_buf[n, i, j, c], self.middle3a_buf[n, i, j, c]), name="middel4")
        self.middle4a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle4a[n, i, j, c], name="middel4_buf")

        self.middle5a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec5a_buf[n, i, j, c], self.middle4a_buf[n, i, j, c]), name="middel5")
        self.middle5a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle5a[n, i, j, c], name="middel5_buf")

        self.middle6a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec6a_buf[n, i, j, c], self.middle5a_buf[n, i, j, c]), name="middel6")
        self.middle6a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle6a[n, i, j, c], name="middel6_buf")

        self.middle7a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec7a_buf[n, i, j, c], self.middle6a_buf[n, i, j, c]), name="middel7")
        self.middle7a_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle7a[n, i, j, c], name="middel7_buf")

        self.middle8a = te.compute((1, 56, 56, 32), lambda n, i, j, c: te.max(self.vec8a_buf[n, i, j, c], self.middle7a_buf[n, i, j, c]), name="middel8")
        self.outa = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle8a[n, i, j, c], name="out")

        self.middle1b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec0b_buf[n, i, j, c], self.vec1b_buf[n, i, j, c]),
                                  name="middel1")
        self.middle1b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle1b[n, i, j, c], name="middel1_buf")

        self.middle2b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec2b_buf[n, i, j, c], self.middle1b_buf[n, i, j, c]),
                                  name="middel2")
        self.middle2b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle2b[n, i, j, c], name="middel2_buf")

        self.middle3b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec3b_buf[n, i, j, c], self.middle2b_buf[n, i, j, c]),
                                  name="middel3")
        self.middle3b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle3b[n, i, j, c], name="middel3_buf")

        self.middle4b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec4b_buf[n, i, j, c], self.middle3b_buf[n, i, j, c]),
                                  name="middel4")
        self.middle4b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle4b[n, i, j, c], name="middel4_buf")

        self.middle5b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec5b_buf[n, i, j, c], self.middle4b_buf[n, i, j, c]),
                                  name="middel5")
        self.middle5b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle5b[n, i, j, c], name="middel5_buf")

        self.middle6b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec6b_buf[n, i, j, c], self.middle5b_buf[n, i, j, c]),
                                  name="middel6")
        self.middle6b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle6b[n, i, j, c], name="middel6_buf")

        self.middle7b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec7b_buf[n, i, j, c], self.middle6b_buf[n, i, j, c]),
                                  name="middel7")
        self.middle7b_buf = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle7b[n, i, j, c], name="middel7_buf")

        self.middle8b = te.compute((1, 56, 56, 32),
                                  lambda n, i, j, c: te.max(self.vec8b_buf[n, i, j, c], self.middle7b_buf[n, i, j, c]),
                                  name="middel8")
        self.outb = te.compute((1, 56, 56, 32), lambda n, i, j, c: self.middle8b[n, i, j, c], name="out")

        self.out = te.compute(
            (1, 56, 56, 64),
            lambda n, i, j, c: te.if_then_else(
                c<32,
                self.outa[n, i, j, c],
                self.outb[n, i, j, c-32]
            )
        )


class arg_pooling:
    def __init__(self, data, strides, padding):
        self.data = data
        self.strides = strides
        self.padding = padding

        self.pad_data = topi.nn.pad(self.data, [0, self.padding[0], self.padding[1], 0], name="pad_data")

        self.vec0 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2, c],
            name="vec0"
        )

        self.vec1 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2, c],
            name="vec1"
        )

        self.vec2 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2, c],
            name="vec2"
        )

        self.vec3 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2 + 1, c],
            name="vec3"
        )

        self.vec4 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2 + 1, c],
            name="vec4"
        )

        self.vec5 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2 + 1, c],
            name="vec5"
        )

        self.vec6 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2, j * 2 + 2, c],
            name="vec6"
        )

        self.vec7 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 1, j * 2 + 2, c],
            name="vec7"
        )

        self.vec8 = te.compute(
            (1, 3, 3, 8),
            lambda n, i, j, c: self.pad_data[n, i * 2 + 2, j * 2 + 2, c],
            name="vec8"
        )

        self.vec0_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec0[n, i, j, c], name="vec0_buf")
        self.vec1_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec1[n, i, j, c], name="vec1_buf")
        self.vec2_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec2[n, i, j, c], name="vec2_buf")
        self.vec3_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec3[n, i, j, c], name="vec3_buf")
        self.vec4_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec4[n, i, j, c], name="vec4_buf")
        self.vec5_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec5[n, i, j, c], name="vec5_buf")
        self.vec6_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec6[n, i, j, c], name="vec6_buf")
        self.vec7_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec7[n, i, j, c], name="vec7_buf")
        self.vec8_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.vec8[n, i, j, c], name="vec8_buf")

        self.middle1 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec0_buf[n, i, j, c], self.vec1_buf[n, i, j, c]),
                                  name="middel1")
        self.middle1_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle1[n, i, j, c], name="middel1_buf")

        self.middle2 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec2_buf[n, i, j, c], self.middle1_buf[n, i, j, c]),
                                  name="middel2")
        self.middle2_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle2[n, i, j, c], name="middel2_buf")

        self.middle3 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec3_buf[n, i, j, c], self.middle2_buf[n, i, j, c]),
                                  name="middel3")
        self.middle3_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle3[n, i, j, c], name="middel3_buf")

        self.middle4 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec4_buf[n, i, j, c], self.middle3_buf[n, i, j, c]),
                                  name="middel4")
        self.middle4_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle4[n, i, j, c], name="middel4_buf")

        self.middle5 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec5_buf[n, i, j, c], self.middle4_buf[n, i, j, c]),
                                  name="middel5")
        self.middle5_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle5[n, i, j, c], name="middel5_buf")

        self.middle6 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec6_buf[n, i, j, c], self.middle5_buf[n, i, j, c]),
                                  name="middel6")
        self.middle6_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle6[n, i, j, c], name="middel6_buf")

        self.middle7 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec7_buf[n, i, j, c], self.middle6_buf[n, i, j, c]),
                                  name="middel7")
        self.middle7_buf = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle7[n, i, j, c], name="middel7_buf")

        self.middle8 = te.compute((1, 3, 3, 8),
                                  lambda n, i, j, c: te.sum(self.vec8_buf[n, i, j, c], self.middle7_buf[n, i, j, c]),
                                  name="middel8")
        self.out = te.compute((1, 3, 3, 8), lambda n, i, j, c: self.middle8[n, i, j, c], name="out")


class dense:
    def __init__(self, data, weight, bias):
        self.data = data
        self.weight = weight
        self.bias = bias

        dshape = topi.utils.get_const_tuple(self.data.shape)
        wshape = topi.utils.get_const_tuple(self.weight.shape)

        self.data_flatten = topi.reshape(self.data, (dshape[0], dshape[1] * dshape[2] * dshape[3]))
        dshape = topi.utils.get_const_tuple(self.data_flatten.shape)
        # print(dshape)

        self.k = te.reduce_axis((0, wshape[1]))
        self.middle = te.compute(
            (dshape[0], wshape[0]),
            lambda i, j: te.sum(
                self.data_flatten[i, self.k] * self.weight[j, self.k],
                axis=[self.k]
            ),
        )

        self.out = te.compute(
            (dshape[0], wshape[0]),
            lambda i, j: self.middle[i, j] + self.bias[j],
        )

class add_num:
    def __init__(self, data1,data2):
        self.data1=data1
        self.data2=data2

        dshape = topi.utils.get_const_tuple(self.data1.shape)
        self.data2_i = te.compute(dshape, lambda n, h, w, c: self.data2, "data2_i")
        self.data1_in = te.compute(dshape, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape, lambda n, h, w, c: self.data2_i[n,h,w,c], "data2_in")

        self.cout = te.compute(
        dshape,
        lambda n, h, w, c: self.data1_in[n, h, w, c] + self.data2_in[n, h, w, c],
        name="cout")

        self.out = te.compute(dshape, lambda n, h, w, c: self.cout[n, h, w, c], "out")

class add_num_re:
    def __init__(self, data1,data2):
        self.data1=data1
        self.data2=data2

        dshape = topi.utils.get_const_tuple(self.data1.shape)

        self.data1_in = te.compute(dshape, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape, lambda n, h, w, c: self.data2, "data2_in")

        self.out = te.compute(
        dshape,
        lambda n, h, w, c: self.data1_in[n, h, w, c] + self.data2_in[n, h, w, c],
        name="out")

        self.cout = te.compute(dshape, lambda n, h, w, c: self.out[n, h, w, c], "cout")

class add_tensor:
    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2
        
        print(type(self.data1))
        dshape1 = topi.utils.get_const_tuple(self.data1.shape)
        dshape2 = topi.utils.get_const_tuple(self.data2.shape)
        # n=int(n)
        # h=int(h)
        # w=int(w)
        # c=int(c)
        self.data2_i = te.compute(dshape1, lambda n, h, w, c: self.data2[c, 0, 0], "data2_i")

        self.data1_in = te.compute(dshape1, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape1, lambda n, h, w, c: self.data2_i[n, h, w, c], "data2_in")

        self.cout = te.compute(
            dshape1,
            lambda n, h, w, c: self.data1_in[n, h, w, c] + self.data2_in[n, h, w, c],
            name="cout")

        self.out = te.compute(dshape1, lambda n, h, w, c: self.cout[n, h, w, c], "out")

class mul_tensor:
    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

        dshape1 = topi.utils.get_const_tuple(self.data1.shape)
        dshape2 = topi.utils.get_const_tuple(self.data2.shape)

        self.data2_i = te.compute(dshape1, lambda n, h, w, c: self.data2[c, 0, 0], "data2_i")

        self.data1_in = te.compute(dshape1, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape1, lambda n, h, w, c: self.data2_i[n, h, w, c], "data2_in")

        self.cout = te.compute(
            dshape1,
            lambda n, h, w, c: self.data1_in[n, h, w, c] * self.data2_in[n, h, w, c],
            name="cout")

        self.out = te.compute(dshape1, lambda n, h, w, c: self.cout[n, h, w, c], "out")

class left_shift:
    def __init__(self, lhs,rhs):
        self.data1=lhs
        self.data2=rhs

        dshape = topi.utils.get_const_tuple(self.data1.shape)
        self.data2_i = te.compute(dshape, lambda n, h, w, c: self.data2, "data2_i")
        self.data1_in = te.compute(dshape, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape, lambda n, h, w, c: self.data2_i[n,h,w,c], "data2_in")

        self.cout = te.compute(
        dshape,
        lambda n, h, w, c: self.data1_in[n, h, w, c] << self.data2_in[n, h, w, c],
        name="cout")

        self.out = te.compute(dshape, lambda n, h, w, c: self.cout[n, h, w, c], "out")

class right_shift:
    def __init__(self, lhs,rhs):
        self.data1=lhs
        self.data2=rhs

        dshape = topi.utils.get_const_tuple(self.data1.shape)
        self.data2_i = te.compute(dshape, lambda n, h, w, c: self.data2, "data2_i")
        self.data1_in = te.compute(dshape, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape, lambda n, h, w, c: self.data2_i[n,h,w,c], "data2_in")

        self.cout = te.compute(
        dshape,
        lambda n, h, w, c: self.data1_in[n, h, w, c] >> self.data2_in[n, h, w, c],
        name="cout")

        self.out = te.compute(dshape, lambda n, h, w, c: self.cout[n, h, w, c], "out")

class rshift_clip_cast:
    def __init__(self,data, shift_value):
        self.data = data
        self.shift_value = shift_value
        self.mid1 = right_shift(lhs=self.data,rhs=self.shift_value)
        self.clip = topi.clip(x=self.mid1.out,a_min=-127,a_max=127)
        self.out = topi.cast(x=self.clip,dtype="int8")

class relu:
    def __init__(self, data):
        self.data1 = data
        self.data2 = tir.const(0)

        dshape = topi.utils.get_const_tuple(self.data1.shape)
        self.zeros = te.compute(dshape, lambda n, h, w, c: self.data2, "data2_in")
        self.data1_in = te.compute(dshape, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape, lambda n, h, w, c: self.zeros[n, h, w, c], "data2_in")
        self.cout = te.compute(
            dshape,
            lambda n,h,w,c: tvm.te.max(self.data1_in[n,h,w,c], self.data2_in[n,h,w,c]),
            name="cout"
        )
        self.out = te.compute(dshape, lambda n, h, w, c: self.cout[n, h, w, c], "out")


class bn:
    def __init__(self, data, gamma, beta, moving_mean, moving_var, epsilon=1e-5):
        self.data = data
        self.gamma = gamma
        self.beta = beta
        self.moving_mean = moving_mean
        self.moving_var = moving_var

        dshape = topi.utils.get_const_tuple(self.data.shape)

        self.mdata1 = te.compute(
            self.moving_var.shape,
            lambda c: tvm.te.sqrt(self.moving_var[c] + epsilon),
            name="mdata1"
        )

        self.mdata2 = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.div((self.data[n, h, w, c] - self.moving_mean[c]), self.mdata1[c]),
            name="mdata2"
        )

        self.out = te.compute(
            dshape,
            lambda n, h, w, c: self.mdata2[n, h, w, c] * self.gamma[c] + self.beta[c],
            name="out"
        )


class bias_add:
    def __init__(self, data, bias):
        self.data = data
        self.bias = bias

        dshape = topi.utils.get_const_tuple(self.data.shape)

        self.out = te.compute(
            dshape,
            lambda n, i, j, c: self.data[n, i, j, c] + self.bias[n],
            name="out"
        )

class clip_cast:
    def __init__(self, data):
        self.data = data
        self.clip = topi.clip(x=self.data,a_min=-127,a_max=127)
        self.out = topi.cast(x=self.clip,dtype="int8")

#fusion left_shift + add_tensor + add_tensor + relu + add_num
class lshift_add_1:
    def __init__(self,data,shift_value,addnum,tensor_a,tensor_b):
        self.data = data
        self.tensor_a =tensor_a
        self.tensor_b =tensor_b
        self.shift_value = shift_value
        self.addnum = addnum

        self.mid1 = left_shift(lhs=self.data,rhs=self.shift_value)
        self.mid2 = add_tensor(data1=self.mid1.out,data2=self.tensor_a)
        self.mid3 = add_tensor(data1=self.mid2.out,data2=self.tensor_b)
        self.mid4 = relu(data=self.mid3.out)
        self.out = add_num(data1=self.mid4.out,data2=self.addnum)

# fusion left_shift + add_tensor + add_num
class lshift_add_2:
    def __init__(self,data,shift_value,addnum,tensor_a):
        self.data = data
        self.tensor_a =tensor_a
        self.shift_value = shift_value
        self.addnum = addnum

        self.mid1 = left_shift(lhs=self.data,rhs=self.shift_value)
        self.mid2 = add_tensor(data1=self.mid1.out,data2=self.tensor_a)
        self.out = add_num(data1=self.mid2.out,data2=self.addnum)

class add_tensor_2:
    def __init__(self,data1,data2):
        self.data1 = data1
        self.data2 = data2

        dshape1 = topi.utils.get_const_tuple(self.data1.shape)
        dshape2 = topi.utils.get_const_tuple(self.data2.shape)

        self.data1_in = te.compute(dshape1, lambda n, h, w, c: self.data1[n, h, w, c], "data1_in")
        self.data2_in = te.compute(dshape2, lambda n, h, w, c: self.data2[n, h, w, c], "data2_in")

        self.cout = te.compute(
            dshape1,
            lambda n, h, w, c: self.data1_in[n, h, w, c] + self.data2_in[n, h, w, c],
            name="cout")

        self.out = te.compute(dshape1, lambda n, h, w, c: self.cout[n, h, w, c], "out")

class fuse_op1:
    # conv2d_leftshift_add_add_relu_add_rshift_clip
    def __init__(self, data, kernel, strides, padding, lshift, add_tensor1, add_tensor2, add_num, rshift):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding
        self.lshift = lshift
        self.add_tensor1 = add_tensor1
        self.add_tensor2 = add_tensor2
        self.add_num = add_num
        self.rshift = rshift

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]

        # calculate padding parameter
        if (oheight * owidth) % gemm_size == 0:
            padded_length = oheight * owidth
            middle_pad = 0
        else:
            padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
            middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                         (padded_length // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel_2d, (output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if(reduction_repeat>128):
            if(reduction_repeat%128==0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif(reduction_repeat%72==0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int32") * self.weight[x, self.k0, self.k1, y, self.k2].astype("int32"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.middle = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="middle"
        )
        self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.conv_out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))
        # print(topi.utils.get_const_tuple(self.out.shape))

        # self.middle_reshape = te.compute(
        #     (padded_length, output_channel),
        #     lambda i, j: self.middle[i//8, j//8, i%8, j%8]
        # )
        #
        # self.conv_out = te.compute(
        #     (1, oheight, owidth, output_channel),
        #     lambda n, h, w, c: self.middle_reshape[n*oheight*owidth+h*owidth+w, c]
        # )

        ################### left shift #######################
        dshape = topi.utils.get_const_tuple(self.conv_out.shape)
        self.lshift_4d = te.compute(dshape, lambda n, h, w, c: self.lshift, "lshift")
        self.lshift_buffer = te.compute(dshape, lambda n, h, w, c: self.lshift_4d[n, h, w, c], "lshift_buffer")

        self.lshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.conv_out[n, h, w, c] << self.lshift_buffer[n, h, w, c],
            name="lshift_out")

        self.lshift_out_buffer = te.compute(
            dshape,
            lambda n, h, w, c: self.lshift_out[n, h, w, c]
        )
        ################### add_tensor1 #######################
        dshape1 = topi.utils.get_const_tuple(self.lshift_out.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor1.shape)

        self.add_tensor1_4d = te.compute(dshape1, lambda n, h, w, c: self.add_tensor1[c, 0, 0], "dadd_tensor1_4d")

        self.add_tensor1_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor1_4d[n, h, w, c], "add_tensor1_buffer")

        self.add_tensor1_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.lshift_out_buffer[n, h, w, c] + self.add_tensor1_buffer[n, h, w, c],
            name="add_tensor1_out")

        self.add_tensor1_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out[n, h, w, c]
        )

        ################### add_tensor2 #######################
        dshape1 = topi.utils.get_const_tuple(self.add_tensor1_out.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor2.shape)

        self.add_tensor2_4d = te.compute(dshape1, lambda n, h, w, c: self.add_tensor2[c, 0, 0], "add_tensor2_4d")

        self.add_tensor2_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor2_4d[n, h, w, c], "add_tensor2_buffer")

        self.add_tensor2_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out_buffer[n, h, w, c] + self.add_tensor2_buffer[n, h, w, c],
            name="add_tensor2_out")

        self.add_tensor2_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor2_out[n, h, w, c]
        )

        ################### relu #######################
        dshape = topi.utils.get_const_tuple(self.add_tensor2_out.shape)

        self.zeros = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(0), "zeros")

        self.zero_buffer = te.compute(dshape, lambda n, h, w, c: self.zeros[n, h, w, c], "zero_buffer")

        self.relu_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.add_tensor2_out_buffer[n, h, w, c], self.zero_buffer[n, h, w, c]),
            name="relu_out"
        )

        self.relu_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.relu_out[n, h, w, c]
        )

        ################### add_num #######################
        dshape = topi.utils.get_const_tuple(self.relu_out.shape)
        self.add_num_4d = te.compute(dshape, lambda n, h, w, c: self.add_num, "add_num_4d")
        self.add_num_buffer = te.compute(dshape, lambda n, h, w, c: self.add_num_4d[n, h, w, c], "add_num_buffer")

        self.add_num_out = te.compute(
            dshape,
            lambda n, h, w, c: self.relu_out_buffer[n, h, w, c] + self.add_num_buffer[n, h, w, c],
            name="add_num_out")

        self.add_num_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_num_out[n, h, w, c]
        )

        ################### right_shift #######################
        dshape = topi.utils.get_const_tuple(self.add_num_out.shape)

        self.rshift_4d = te.compute(dshape, lambda n, h, w, c: self.rshift, "data2_in")
        self.rshift_buffer = te.compute(dshape, lambda n, h, w, c: self.rshift_4d[n, h, w, c], "rshift_buffer")

        self.rshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_num_out_buffer[n, h, w, c] >> self.rshift_buffer[n, h, w, c],
            name="rshift_out")

        self.rshift_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.rshift_out[n, h, w, c]
        )

        ################### clip #######################

        self.max_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(127.), "max_value")
        self.min_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(-127.), "min_value")

        self.max_value_buffer = te.compute(dshape, lambda n, h, w, c: self.max_value[n,h,w,c], "max_value_buffer")
        self.min_value_buffer = te.compute(dshape, lambda n, h, w, c: self.min_value[n,h,w,c], "min_value_buffer")

        self.clip_max_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.min(self.rshift_out_buffer[n,h,w,c],  self.max_value_buffer[n,h,w,c]),
            name="clip_max_out")

        self.clip_middle_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_max_out[n,h,w,c], "clip_middle_buffer")

        self.clip_min_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.clip_middle_buffer[n,h,w,c],  self.min_value_buffer[n,h,w,c]),
            name="clip_min_out")

        self.out = te.compute(dshape, lambda n, h, w, c: self.clip_min_out[n, h, w, c], name="out")

class op_fuse3:
    # conv2d_leftshift_add_add_num_rshift_clip
    def __init__(self, data, kernel, strides, padding, lshift, add_tensor1, add_num, rshift):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding
        self.lshift = lshift
        self.add_tensor1 = add_tensor1
        self.add_num = add_num
        self.rshift = rshift

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]

        # calculate padding parameter
        if (oheight * owidth) % gemm_size == 0:
            padded_length = oheight * owidth
            middle_pad = 0
        else:
            padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
            middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                         (padded_length // gemm_size, gemm_size,
                                          input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel_2d, (
        output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if (reduction_repeat > 128):
            if (reduction_repeat % 128 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif (reduction_repeat % 72 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int32") * self.weight[
                    x, self.k0, self.k1, y, self.k2].astype("int32"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.conv_out = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="conv_out"
        )
        # self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        # self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        # self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")
        #
        # self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))

        ################### left shift #######################
        dshape = topi.utils.get_const_tuple(self.conv_out.shape)
        self.lshift_4d = te.compute(dshape, lambda n, h, w, c: self.lshift, "lshift")
        self.lshift_buffer = te.compute(dshape, lambda n, h, w, c: self.lshift_4d[n, h, w, c], "lshift_buffer")

        self.lshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.conv_out[n, h, w, c] << self.lshift_buffer[n, h, w, c],
            name="lshift_out")

        self.lshift_out_buffer = te.compute(
            dshape,
            lambda n, h, w, c: self.lshift_out[n, h, w, c]
        )
        ################### add_tensor1 #######################
        dshape1 = topi.utils.get_const_tuple(self.lshift_out.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor1.shape)


        self.add_tensor1_4d = te.compute(dshape1, lambda n, h, w, c : self.add_tensor1[h*8+c, 0, 0], "add_tensor1_4d")

        self.add_tensor1_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor1_4d[n, h, w, c], "add_tensor1_buffer")

        self.add_tensor1_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.lshift_out_buffer[n, h, w, c] + self.add_tensor1_buffer[n, h, w, c],
            name="add_tensor1_out")

        self.add_tensor1_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out[n, h, w, c]
        )

        ################### add_num #######################
        dshape = topi.utils.get_const_tuple(self.add_tensor1_out_buffer.shape)
        self.add_num_4d = te.compute(dshape, lambda n, h, w, c: self.add_num, "add_num_4d")
        self.add_num_buffer = te.compute(dshape, lambda n, h, w, c: self.add_num_4d[n, h, w, c], "add_num_buffer")

        self.add_num_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_tensor1_out_buffer[n, h, w, c] + self.add_num_buffer[n, h, w, c],
            name="add_num_out")

        self.add_num_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_num_out[n, h, w, c]
        )




        ################### right_shift #######################
        dshape = topi.utils.get_const_tuple(self.add_num_out.shape)

        self.rshift_4d = te.compute(dshape, lambda n, h, w, c: self.rshift, "data2_in")
        self.rshift_buffer = te.compute(dshape, lambda n, h, w, c: self.rshift_4d[n, h, w, c], "rshift_buffer")

        self.rshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_num_out_buffer[n, h, w, c] >> self.rshift_buffer[n, h, w, c],
            name="rshift_out")

        self.rshift_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.rshift_out[n, h, w, c]
        )

        ################### clip #######################

        self.max_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(127), "max_value")
        self.min_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(-127), "min_value")

        self.max_value_buffer = te.compute(dshape, lambda n, h, w, c: self.max_value[n,h,w,c], "max_value_buffer")
        self.min_value_buffer = te.compute(dshape, lambda n, h, w, c: self.min_value[n,h,w,c], "min_value_buffer")

        self.clip_max_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.min(self.rshift_out_buffer[n,h,w,c],  self.max_value_buffer[n,h,w,c]),
            name="clip_max_out")

        self.clip_middle_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_max_out[n,h,w,c], "clip_middle_buffer")

        self.clip_min_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.clip_middle_buffer[n,h,w,c],  self.min_value_buffer[n,h,w,c]),
            name="clip_min_out")

        self.out_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_min_out[n, h, w, c], name="out_buffer")

        self.middle_tran = topi.transpose(self.out_buffer, (0, 2, 1, 3))
        self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))

class fuse_op1_new:

    def __init__(self, data, kernel, strides, padding, lshift, add_tensor1, add_tensor2, add_num, rshift):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding
        self.lshift = lshift
        self.add_tensor1 = add_tensor1
        self.add_tensor2 = add_tensor2
        self.add_num = add_num
        self.rshift = rshift

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]

        # calculate padding parameter
        if (oheight * owidth) % gemm_size == 0:
            padded_length = oheight * owidth
            middle_pad = 0
        else:
            padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
            middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                         (padded_length // gemm_size, gemm_size,
                                          input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel_2d, (
        output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if (reduction_repeat > 128):
            if (reduction_repeat % 128 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif (reduction_repeat % 72 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int32") * self.weight[
                    x, self.k0, self.k1, y, self.k2].astype("int32"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.conv_out = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="conv_out"
        )
        # self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        # self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        # self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")
        #
        # self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))

        ################### left shift #######################
        dshape = topi.utils.get_const_tuple(self.conv_out.shape)
        self.lshift_4d = te.compute(dshape, lambda n, h, w, c: self.lshift, "lshift")
        self.lshift_buffer = te.compute(dshape, lambda n, h, w, c: self.lshift_4d[n, h, w, c], "lshift_buffer")

        self.lshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.conv_out[n, h, w, c] << self.lshift_buffer[n, h, w, c],
            name="lshift_out")

        self.lshift_out_buffer = te.compute(
            dshape,
            lambda n, h, w, c: self.lshift_out[n, h, w, c]
        )
        ################### add_tensor1 #######################
        dshape1 = topi.utils.get_const_tuple(self.lshift_out.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor1.shape)


        self.add_tensor1_4d = te.compute(dshape1, lambda n, h, w, c : self.add_tensor1[h*8+c, 0, 0], "add_tensor1_4d")

        self.add_tensor1_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor1_4d[n, h, w, c], "add_tensor1_buffer")

        self.add_tensor1_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.lshift_out_buffer[n, h, w, c] + self.add_tensor1_buffer[n, h, w, c],
            name="add_tensor1_out")

        self.add_tensor1_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out[n, h, w, c]
        )

        ################### add_tensor2 #######################
        dshape1 = topi.utils.get_const_tuple(self.add_tensor1_out.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor2.shape)

        self.add_tensor2_4d = te.compute(dshape1, lambda n, h, w, c: self.add_tensor2[h*8+c, 0, 0], "add_tensor2_4d")

        self.add_tensor2_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor2_4d[n, h, w, c], "add_tensor2_buffer")

        self.add_tensor2_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out_buffer[n, h, w, c] + self.add_tensor2_buffer[n, h, w, c],
            name="add_tensor2_out")

        self.add_tensor2_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor2_out[n, h, w, c]
        )

        ################### relu #######################
        dshape = topi.utils.get_const_tuple(self.add_tensor2_out.shape)

        self.zeros = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(0), "zeros")

        self.zero_buffer = te.compute(dshape, lambda n, h, w, c: self.zeros[n, h, w, c], "zero_buffer")

        self.relu_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.add_tensor2_out_buffer[n, h, w, c], self.zero_buffer[n, h, w, c]),
            name="relu_out"
        )

        self.relu_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.relu_out[n, h, w, c]
        )

        ################### add_num #######################
        dshape = topi.utils.get_const_tuple(self.relu_out.shape)
        self.add_num_4d = te.compute(dshape, lambda n, h, w, c: self.add_num, "add_num_4d")
        self.add_num_buffer = te.compute(dshape, lambda n, h, w, c: self.add_num_4d[n, h, w, c], "add_num_buffer")

        self.add_num_out = te.compute(
            dshape,
            lambda n, h, w, c: self.relu_out_buffer[n, h, w, c] + self.add_num_buffer[n, h, w, c],
            name="add_num_out")

        self.add_num_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_num_out[n, h, w, c]
        )

        ################### right_shift #######################
        dshape = topi.utils.get_const_tuple(self.add_num_out.shape)

        self.rshift_4d = te.compute(dshape, lambda n, h, w, c: self.rshift, "data2_in")
        self.rshift_buffer = te.compute(dshape, lambda n, h, w, c: self.rshift_4d[n, h, w, c], "rshift_buffer")

        self.rshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_num_out_buffer[n, h, w, c] >> self.rshift_buffer[n, h, w, c],
            name="rshift_out")

        self.rshift_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.rshift_out[n, h, w, c]
        )

        ################### clip #######################

        self.max_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(127.), "max_value")
        self.min_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(-127.), "min_value")

        self.max_value_buffer = te.compute(dshape, lambda n, h, w, c: self.max_value[n,h,w,c], "max_value_buffer")
        self.min_value_buffer = te.compute(dshape, lambda n, h, w, c: self.min_value[n,h,w,c], "min_value_buffer")

        self.clip_max_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.min(self.rshift_out_buffer[n,h,w,c],  self.max_value_buffer[n,h,w,c]),
            name="clip_max_out")

        self.clip_middle_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_max_out[n,h,w,c], "clip_middle_buffer")

        self.clip_min_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.clip_middle_buffer[n,h,w,c],  self.min_value_buffer[n,h,w,c]),
            name="clip_min_out")

        self.out_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_min_out[n, h, w, c], name="out_buffer")

        self.middle_tran = topi.transpose(self.out_buffer, (0, 2, 1, 3))
        self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))

class fuse_op4:

    def __init__(self, data, mul_tensor1,add_tensor1, add_num, rshift):
        self.data = data
        self.mul_tensor1 = mul_tensor1
        self.add_tensor1 = add_tensor1
        self.add_num = add_num
        self.rshift = rshift


        ################### multiply #######################
        dshape = topi.utils.get_const_tuple(self.data.shape)
        self.data_buffer = te.compute(dshape, lambda n, h, w, c: self.data[n, h, w, c], "data_buffer")
        self.mul_tensor1_4d = te.compute(dshape, lambda n, h, w, c : self.mul_tensor1[c, 0, 0], "mul_tensor1_4d")

        self.mul_tensor1_buffer = te.compute(dshape, lambda n, h, w, c: self.mul_tensor1_4d[n, h, w, c], "mul_tensor1_buffer")

        self.mul_tensor1_out = te.compute(
            dshape,
            lambda n, h, w, c: self.data_buffer[n, h, w, c] * self.mul_tensor1_buffer[n, h, w, c],
            name="mul_tensor1_out")

        self.mul_tensor1_out_buffer = te.compute(
            dshape,
            lambda n, h, w, c: self.mul_tensor1_out[n, h, w, c]
        )
        ################### add_tensor1 #######################
        dshape1 = topi.utils.get_const_tuple(self.mul_tensor1_out_buffer.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor1.shape)


        self.add_tensor1_4d = te.compute(dshape1, lambda n, h, w, c : self.add_tensor1[c, 0, 0], "add_tensor1_4d")

        self.add_tensor1_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor1_4d[n, h, w, c], "add_tensor1_buffer")

        self.add_tensor1_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.mul_tensor1_out_buffer[n, h, w, c] + self.add_tensor1_buffer[n, h, w, c],
            name="add_tensor1_out")

        self.add_tensor1_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out[n, h, w, c]
        )

        ################### add_num #######################
        dshape = topi.utils.get_const_tuple(self.add_tensor1_out_buffer.shape)
        self.add_num_4d = te.compute(dshape, lambda n, h, w, c: self.add_num, "add_num_4d")
        self.add_num_buffer = te.compute(dshape, lambda n, h, w, c: self.add_num_4d[n, h, w, c], "add_num_buffer")

        self.add_num_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_tensor1_out_buffer[n, h, w, c] + self.add_num_buffer[n, h, w, c],
            name="add_num_out")

        self.add_num_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_num_out[n, h, w, c]
        )




        ################### right_shift #######################
        dshape = topi.utils.get_const_tuple(self.add_num_out.shape)

        self.rshift_4d = te.compute(dshape, lambda n, h, w, c: self.rshift, "data2_in")
        self.rshift_buffer = te.compute(dshape, lambda n, h, w, c: self.rshift_4d[n, h, w, c], "rshift_buffer")

        self.rshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_num_out_buffer[n, h, w, c] >> self.rshift_buffer[n, h, w, c],
            name="rshift_out")

        self.rshift_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.rshift_out[n, h, w, c]
        )

        ################### clip #######################

        self.max_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(127.), "max_value")
        self.min_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(-127.), "min_value")

        self.max_value_buffer = te.compute(dshape, lambda n, h, w, c: self.max_value[n,h,w,c], "max_value_buffer")
        self.min_value_buffer = te.compute(dshape, lambda n, h, w, c: self.min_value[n,h,w,c], "min_value_buffer")

        self.clip_max_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.min(self.rshift_out_buffer[n,h,w,c],  self.max_value_buffer[n,h,w,c]),
            name="clip_max_out")

        self.clip_middle_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_max_out[n,h,w,c], "clip_middle_buffer")

        self.clip_min_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.clip_middle_buffer[n,h,w,c],  self.min_value_buffer[n,h,w,c]),
            name="clip_min_out")

        self.out = te.compute(dshape, lambda n, h, w, c: self.clip_min_out[n, h, w, c], name="out")

class fuse_op5:
    # conv2d_add_add_num_rshift_clip
    def __init__(self, data, kernel, strides, padding, add_tensor1, add_num, rshift):
        self.data = data
        self.kernel = kernel
        self.strides = strides
        self.padding = padding

        self.add_tensor1 = add_tensor1

        self.add_num = add_num
        self.rshift = rshift

        gemm_size = 8

        # shape get
        ishape = topi.utils.get_const_tuple(self.data.shape)
        kshape = topi.utils.get_const_tuple(self.kernel.shape)

        # output shape computation
        oheight = topi.utils.get_const_int(self.data.shape[1] // strides[0])
        owidth = topi.utils.get_const_int(self.data.shape[2] // strides[1])

        # padding for convolution
        if padding:
            self.pad_data = topi.nn.pad(self.data, [0, self.padding, self.padding, 0], name="pad_data")
        else:
            self.pad_data = self.data

        ishape = topi.utils.get_const_tuple(self.pad_data.shape)

        input_channel = ishape[3]
        output_channel = kshape[0]
        window_size = kshape[1] * kshape[2]

        # calculate padding parameter
        if (oheight * owidth) % gemm_size == 0:
            padded_length = oheight * owidth
            middle_pad = 0
        else:
            padded_length = ((oheight * owidth) // gemm_size + 1) * gemm_size
            middle_pad = padded_length - oheight * owidth

        # im2col, first transpose to 6-d
        self.mdata = te.compute(
            (ishape[0], oheight, owidth, kshape[1], kshape[2], input_channel),
            lambda n, o1, o2, k1, k2, c: self.pad_data[0, k1 + o1 * strides[0], k2 + o2 * strides[1], c],
            name="mdata"
        )

        # reshape data and weight to 2d
        self.mdata_2d = topi.reshape(self.mdata, (ishape[0] * oheight * owidth, input_channel * window_size))
        self.kernel_2d = topi.reshape(self.kernel, (output_channel, input_channel * window_size))

        # pad data_2d to match [16, 16]
        self.mdata_pad = topi.nn.pad(self.mdata_2d, [0, 0], [middle_pad, 0], name="mdata_pad")

        # split data and weight with 16
        self.mdata_pad_4d = topi.reshape(self.mdata_pad,
                                         (padded_length // gemm_size, gemm_size,
                                          input_channel * window_size // gemm_size, gemm_size))
        self.kernel_4d = topi.reshape(self.kernel_2d, (
        output_channel // gemm_size, gemm_size, input_channel * window_size // gemm_size, gemm_size))

        # transpose data and weight to move two axis of 16 to the end
        self.A = topi.transpose(self.mdata_pad_4d, (0, 2, 1, 3))
        self.B = topi.transpose(self.kernel_4d, (0, 2, 1, 3))

        A_shape = topi.utils.get_const_tuple(self.A.shape)
        B_shape = topi.utils.get_const_tuple(self.B.shape)

        reduction_repeat = A_shape[1]
        if (reduction_repeat > 128):
            if (reduction_repeat % 128 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 128, 128, gemm_size, gemm_size))
            elif (reduction_repeat % 72 == 0):
                self.A1 = topi.reshape(self.A, (A_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], reduction_repeat // 72, 72, gemm_size, gemm_size))
            else:
                print("error")
                self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
                self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))
        else:
            self.A1 = topi.reshape(self.A, (A_shape[0], 1, A_shape[1], gemm_size, gemm_size))
            self.B1 = topi.reshape(self.B, (B_shape[0], 1, B_shape[1], gemm_size, gemm_size))

        A1_shape = topi.utils.get_const_tuple(self.A1.shape)
        B1_shape = topi.utils.get_const_tuple(self.B1.shape)

        self.feature_input = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.A1[x, r, i, y, j],
            name="feature_input"
        )

        self.weight_input = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.B1[x, r, i, y, j],
            name="weight_input"
        )

        self.feature = te.compute(
            A1_shape,
            lambda x, r, i, y, j: self.feature_input[x, r, i, y, j],
            name="feature"
        )

        self.weight = te.compute(
            B1_shape,
            lambda x, r, i, y, j: self.weight_input[x, r, i, y, j],
            name="weight"
        )

        self.k0 = te.reduce_axis((0, A1_shape[1]), name="k0")
        self.k1 = te.reduce_axis((0, A1_shape[2]), name="k1")
        self.k2 = te.reduce_axis((0, gemm_size), name="k2")

        self.middle_buffer = te.compute(
            (A1_shape[0], B1_shape[0], gemm_size, gemm_size),
            lambda i, x, j, y: te.sum(
                self.feature[i, self.k0, self.k1, j, self.k2].astype("int32") * self.weight[
                    x, self.k0, self.k1, y, self.k2].astype("int32"),
                axis=[self.k0, self.k1, self.k2]
            ),
            name="middle_buffer"
        )

        self.conv_out = te.compute(
            (padded_length // gemm_size, output_channel // gemm_size, gemm_size, gemm_size),
            lambda i, x, j, y: self.middle_buffer[i, x, j, y],
            name="conv_out"
        )
        # self.middle_tran = topi.transpose(self.middle, (0, 2, 1, 3))
        # self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        # self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")
        #
        # self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))


        ################### add_tensor1 #######################
        dshape1 = topi.utils.get_const_tuple(self.conv_out.shape)
        dshape2 = topi.utils.get_const_tuple(self.add_tensor1.shape)


        self.add_tensor1_4d = te.compute(dshape1, lambda n, h, w, c : self.add_tensor1[h*8+c, 0, 0], "add_tensor1_4d")

        self.add_tensor1_buffer = te.compute(dshape1, lambda n, h, w, c: self.add_tensor1_4d[n, h, w, c], "add_tensor1_buffer")

        self.add_tensor1_out = te.compute(
            dshape1,
            lambda n, h, w, c: self.conv_out[n, h, w, c] + self.add_tensor1_buffer[n, h, w, c],
            name="add_tensor1_out")

        self.add_tensor1_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_tensor1_out[n, h, w, c]
        )





        ################### add_num #######################
        dshape = topi.utils.get_const_tuple(self.add_tensor1_out_buffer.shape)
        self.add_num_4d = te.compute(dshape, lambda n, h, w, c: self.add_num, "add_num_4d")
        self.add_num_buffer = te.compute(dshape, lambda n, h, w, c: self.add_num_4d[n, h, w, c], "add_num_buffer")

        self.add_num_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_tensor1_out_buffer[n, h, w, c] + self.add_num_buffer[n, h, w, c],
            name="add_num_out")

        self.add_num_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.add_num_out[n, h, w, c]
        )

        ################### right_shift #######################
        dshape = topi.utils.get_const_tuple(self.add_num_out.shape)

        self.rshift_4d = te.compute(dshape, lambda n, h, w, c: self.rshift, "data2_in")
        self.rshift_buffer = te.compute(dshape, lambda n, h, w, c: self.rshift_4d[n, h, w, c], "rshift_buffer")

        self.rshift_out = te.compute(
            dshape,
            lambda n, h, w, c: self.add_num_out_buffer[n, h, w, c] >> self.rshift_buffer[n, h, w, c],
            name="rshift_out")

        self.rshift_out_buffer = te.compute(
            dshape1,
            lambda n, h, w, c: self.rshift_out[n, h, w, c]
        )

        ################### clip #######################

        self.max_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(127.), "max_value")
        self.min_value = te.compute(dshape, lambda n, h, w, c: tvm.tir.const(-127.), "min_value")

        self.max_value_buffer = te.compute(dshape, lambda n, h, w, c: self.max_value[n,h,w,c], "max_value_buffer")
        self.min_value_buffer = te.compute(dshape, lambda n, h, w, c: self.min_value[n,h,w,c], "min_value_buffer")

        self.clip_max_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.min(self.rshift_out_buffer[n,h,w,c],  self.max_value_buffer[n,h,w,c]),
            name="clip_max_out")

        self.clip_middle_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_max_out[n,h,w,c], "clip_middle_buffer")

        self.clip_min_out = te.compute(
            dshape,
            lambda n, h, w, c: tvm.te.max(self.clip_middle_buffer[n,h,w,c],  self.min_value_buffer[n,h,w,c]),
            name="clip_min_out")

        self.out_buffer = te.compute(dshape, lambda n, h, w, c: self.clip_min_out[n, h, w, c], name="out_buffer")

        self.middle_tran = topi.transpose(self.out_buffer, (0, 2, 1, 3))
        self.middle_reshape = topi.reshape(self.middle_tran, (padded_length, output_channel))
        self.middle_unpad = topi.nn.pad(self.middle_reshape, [0, 0], [-middle_pad, 0], name="middle_unpad")

        self.out = topi.reshape(self.middle_unpad, (1, oheight, owidth, output_channel))