# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
"""VTA related intrinsics"""
from __future__ import absolute_import as _abs

import tvm
from tvm import te


def gemm(env, mock=False):
    """Matrix-matrix multiply intrinsic

    Parameters
    ----------
    env : Environment
        The Environment

    mock : bool
        Whether create a mock version.
    """
    # m = tvm.tir.Var(name="m", dtype="int32")
    # n = tvm.tir.Var(name="n", dtype="int32")
    k = tvm.tir.Var(name="k", dtype="int32")
    wgt_lanes = env.WGT_ELEM_BITS // env.WGT_WIDTH
    # assert wgt_lanes == env.BLOCK_OUT * env.BLOCK_IN
    # wgt_shape = (n, k, 8, 8)
    wgt_shape = (k, 8, 8)
    # wgt_shape = (2, 2, 8, 8)
    # assert wgt_shape[0] * wgt_shape[1] == wgt_lanes

    inp_lanes = env.INP_ELEM_BITS // env.INP_WIDTH
    # assert inp_lanes == env.BLOCK_OUT * env.BLOCK_IN
    # inp_shape = (m, k, 8, 8)
    inp_shape = (k, 8, 8)
    # inp_shape = (2, 2, 8, 8)
    # assert inp_shape[0] * inp_shape[1] == inp_lanes

    out_lanes = env.ACC_ELEM_BITS // env.ACC_WIDTH
    # assert out_lanes == env.BLOCK_OUT * env.BLOCK_IN
    # out_shape = (m, n, 8, 8)
    out_shape = (8, 8)
    # out_shape = (2, 2, 8, 8)
    # assert out_shape[0] * out_shape[1] == out_lanes

    wgt = te.placeholder(
        (wgt_shape[0], wgt_shape[1], wgt_shape[2]), dtype="int%d" % env.WGT_WIDTH, name=env.wgt_scope
    )
    inp = te.placeholder(
        (inp_shape[0], inp_shape[1], inp_shape[2]), dtype="int%d" % env.INP_WIDTH, name=env.inp_scope
    )
    k1 = te.reduce_axis((0, wgt_shape[0]), name="k1")
    k2 = te.reduce_axis((0, wgt_shape[2]), name="k2")
    out_dtype = "int%d" % env.ACC_WIDTH
    out = te.compute(
        (out_shape[0], out_shape[1]),
        lambda i, j: te.sum(
            inp[k1, i, k2].astype(out_dtype) * wgt[k1, j, k2].astype(out_dtype),
            axis=[k1, k2]),
        name="out",
    )
    # print(m, "fuck")

    strides_wgt = tvm.tir.Var("s_wgt", "int32");
    strides = te.var("s1")
    wgt_layout = tvm.tir.decl_buffer(
        wgt.shape,
        wgt.dtype,
        env.wgt_scope,
        scope=env.wgt_scope,
        offset_factor=wgt_lanes,
        data_alignment=wgt_lanes,
        # strides=[strides_wgt, 1]
    )

    strides_inp = tvm.tir.Var("s_inp", "int32");
    inp_layout = tvm.tir.decl_buffer(
        inp.shape,
        inp.dtype,
        env.inp_scope,
        scope=env.inp_scope,
        offset_factor=inp_lanes,
        data_alignment=inp_lanes,
        # strides=[strides_inp, 1, 1, 1]
        # strides=[strides_inp, strides_inp, 8, 8]
    )

    strides_out = tvm.tir.Var("s_out", "int32");
    out_layout = tvm.tir.decl_buffer(
        out.shape,
        out.dtype,
        env.mid_scopeA,
        scope=env.mid_scopeA,
        offset_factor=out_lanes,
        data_alignment=out_lanes,
        # strides=[strides_out, 1]
    )

    # tvm.ir.Op.get("zte_gemm_fp16")
    # tvm.ir.register_op_attr("tir.zte_gemm_fp16", "TCallEffectKind", tvm.tir.CallEffectKind.Opaque)
    # tvm.ir.register_op_attr("tir.zte_gemm_fp16", "TGlobalSymbol", "tir.zte_gemm_fp16")

    def intrin_func(ins, outs):
        """Matrix-matrix multiply intrinsic function"""
        dinp, dwgt = ins
        dout = outs[0]

        def _body():
            irb = tvm.tir.ir_builder.create()
            dev = env.dev
            irb.scope_attr(dev.zte_axis, "zte_uop_scope", tvm.tir.StringImm("zte_gemm"))
            irb.emit(
                tvm.tir.call_intrin(
                    "int32",
                    "tir.zte_gemm_fp16",
                    # 0,
                    # 0,
                    # dout.access_ptr("rw", "int32"),
                    # dinp.access_ptr("r", "int32"),
                    # dwgt.access_ptr("r", "int32"),
                    # tvm.tir.const(0x20020000, "int64")+dinp.access_ptr("rw", "int64")*2,
                    # tvm.tir.const(0x20040000, "int64")+dwgt.access_ptr("rw", "int64")*16,
                    # tvm.tir.const(0x20060000, "int64")+dout.access_ptr("rw", "int64")*2,
                    tvm.tir.const(0x20020000, "int64"),
                    tvm.tir.const(0x20040000, "int64"),
                    tvm.tir.const(0x20060000, "int64"),
                    # m,
                    tvm.tir.const(1, "int64"),
                    k,
                    tvm.tir.const(1, "int64"),
                    # n,
                    tvm.tir.const(0, "int64"),
                    # tvm.tir.const(1, "int64"),
                    # tvm.tir.const(1, "int64"),
                    "shit"
                )
            )
            return irb.get()

        def _reduce_reset():
            irb = tvm.tir.ir_builder.create()
            dev = env.dev
            irb.scope_attr(dev.zte_axis, "zte_uop_scope", tvm.tir.StringImm("zte_gemm"))
            irb.emit(
                tvm.tir.call_intrin(
                    "int32",
                    "tir.zte_gemm_fp16",
                    tvm.tir.const(0x20020000, "int64"),
                    tvm.tir.const(0x20040000, "int64"),
                    tvm.tir.const(0x20060000, "int64"),
                    tvm.tir.const(1, "int64"),
                    tvm.tir.const(1, "int64"),
                    tvm.tir.const(1, "int64"),
                    tvm.tir.const(1, "int64"),
                )
            )
            return irb.get()

        def _reduce_update():
            irb = tvm.tir.ir_builder.create()
            dev = env.dev
            irb.scope_attr(dev.zte_axis, "zte_uop_scope", tvm.tir.StringImm("zte_gemm"))
            irb.emit(
                tvm.tir.call_intrin(
                    "int32",
                    "tir.zte_gemm_fp16",
                    # 0,
                    # 0,
                    # dout.access_ptr("rw", "int32"),
                    # dinp.access_ptr("r", "int32"),
                    # dwgt.access_ptr("r", "int32"),
                    # tvm.tir.const(0x20020000, "int64")+dinp.access_ptr("rw", "int64")*2,
                    # tvm.tir.const(0x20040000, "int64")+dwgt.access_ptr("rw", "int64")*16,
                    # tvm.tir.const(0x20060000, "int64")+dout.access_ptr("rw", "int64")*2,
                    tvm.tir.const(0x20020000, "int64"),
                    tvm.tir.const(0x20040000, "int64"),
                    tvm.tir.const(0x20060000, "int64"),
                    # m,
                    tvm.tir.const(1, "int64"),
                    k,
                    tvm.tir.const(1, "int64"),
                    # n,
                    tvm.tir.const(0, "int64"),
                    # "fuck"
                    # tvm.tir.const(1, "int64"),
                    # tvm.tir.const(1, "int64"),
                )
            )
            return irb.get()

        # def instr(index):
        #     """Generate matrix-matrix multiply VTA instruction"""
        #     irb = tvm.tir.ir_builder.create()
        #     dev = env.dev
        #     irb.scope_attr(dev.zte_axis, "zte_uop_scope", tvm.tir.StringImm("zte_gemm"))
        #     if index in (0, 2):
        #         irb.emit(
        #             tvm.tir.call_extern(
        #                 "int16",
        #                 "zte_gemm_fp16",
        #                 0,
        #                 0,
        #                 dout.access_ptr("rw", "int16"),
        #                 dinp.access_ptr("r", "int16"),
        #                 dwgt.access_ptr("r", "int16"),
        #                 0,
        #                 0,
        #                 0,
        #             )
        #         )
        #     else:
        #         irb.emit(
        #             tvm.tir.call_extern(
        #                 "int16",
        #                 "zte_gemm_fp16",
        #                 0,
        #                 1,
        #                 dout.access_ptr("rw", "int16"),
        #                 0,
        #                 0,
        #                 0,
        #                 0,
        #                 0,
        #             )
        #         )
        #     return irb.get()
        #
        # # return a triple of normal-set, reset, update
        # nop = tvm.tir.Evaluate(0)
        # if mock:
        #     return (nop, nop, nop)
        # return (instr(0),
        #         instr(1),
        #         instr(2))

        return _body(), _reduce_reset(), _reduce_update()

        def instr(index):
            """Generate matrix-matrix multiply VTA instruction"""
            irb = tvm.tir.ir_builder.create()
            dev = env.dev
            irb.scope_attr(dev.vta_axis, "coproc_scope", dev.get_task_qid(dev.QID_COMPUTE))
            irb.scope_attr(dev.vta_axis, "coproc_uop_scope", dev.vta_push_uop)
            if index in (0, 2):
                irb.emit(
                    tvm.tir.call_intrin(
                        "int32",
                        "tir.zte.uop_push",
                        0,
                        0,
                        dout.access_ptr("rw", "int32"),
                        dinp.access_ptr("r", "int32"),
                        dwgt.access_ptr("r", "int32"),
                        0,
                        0,
                        0,
                    )
                )
            else:
                irb.emit(
                    tvm.tir.call_intrin(
                        "int32",
                        "tir.zte.uop_push",
                        0,
                        1,
                        dout.access_ptr("rw", "int32"),
                        0,
                        0,
                        0,
                        0,
                        0,
                    )
                )
            return irb.get()

        # return a triple of normal-set, reset, update
        nop = tvm.tir.Evaluate(0)
        if mock:
            return (nop, nop, nop)
        return (instr(0), instr(1), instr(2))


    return te.decl_tensor_intrin(
        out.op, intrin_func, name="GEMM", binds={inp: inp_layout, wgt: wgt_layout, out: out_layout}
    )
