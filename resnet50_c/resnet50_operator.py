from __future__ import absolute_import, print_function

import argparse, json, os, requests, sys, time
from io import BytesIO
from os.path import join, isfile
from PIL import Image

from mxnet.gluon.model_zoo import vision
import numpy as np
from matplotlib import pyplot as plt

import tvm
from tvm import te,topi
from tvm import rpc, autotvm, relay
from tvm.contrib import graph_executor, utils, download
from tvm.contrib.debugger import debug_executor
from tvm.relay import transform

# import vta
# from vta.testing import simulator
# from vta.top import graph_pack

import op_sch
from op_sch.operators import conv2d_cpu, conv2d, max_pooling, arg_pooling, dense, add_tensor, add_num, mul_tensor, left_shift, \
    right_shift, relu, bn, bias_add, rshift_clip_cast, clip_cast, lshift_add_1, lshift_add_2, add_tensor_2

import op_sch.schedule as schedule
from op_sch.schedule import maxpool_schedule, conv_schedule, argpool_schedule,add_num_schedule,add_tensor_schedule,mul_tensor_schedule,left_shift_schedule,right_shift_schedule,relu_schedule
# Make sure that TVM was compiled with RPC=1
assert tvm.runtime.enabled("rpc")

import zte
from tvm.contrib import utils, download, graph_runtime
######################################################################

#    Beginning
input_data = tvm.te.placeholder((1, 224, 224, 3), dtype="float32", name="input_data")
kernel_1 = tvm.te.placeholder((64, 7, 7, 3), dtype="float32", name="kernel_1")
conv_1 = conv2d_cpu(data=input_data, kernel=kernel_1, strides=[2,2],padding=3)
conv_1_out = topi.transpose(conv_1.out, (0, 3, 1, 2))
tensor_1 = tvm.te.placeholder((64, 1, 1), dtype="float32", name="tensor_1")
add_1 = topi.add(lhs=conv_1_out,rhs=tensor_1)

relu_2 = topi.nn.relu(add_1)

maxpool_3 = topi.nn.pool2d(data=relu_2,kernel=[3,3],stride=[2,2],dilation=[1,1],padding=[1,1,1,1],pool_type="max")

## %4 annotation.stop_fusion

multiply_5 = topi.multiply(lhs=maxpool_3,rhs=16.)
round_6 = topi.round(multiply_5)

#clip_7 = topi.clip(x=round_6,a_min=-127,a_max=127)
#cast_8 = topi.cast(x=clip_7,dtype="int8")
clip_cast_8 = clip_cast(round_6)
clip_cast_8_out = topi.transpose(clip_cast_8.out, (0, 2, 3, 1))

kernel_9 = tvm.te.placeholder((64, 1, 1, 64), dtype="int8", name="kernel_9")
conv_9 = conv2d(data=clip_cast_8_out,kernel=kernel_9,strides=[1,1],padding=0)

tensor_11 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_11")
tensor_12 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_12")

result_14 = lshift_add_1(data=conv_9.out,shift_value=11,addnum=131072,tensor_a=tensor_11,tensor_b=tensor_12)
result_18 = rshift_clip_cast(data=result_14.out.out,shift_value=18)

kernel_19 = tvm.te.placeholder((64, 3, 3, 64), dtype="int8", name="kernel_19")
conv_19 = conv2d(data=result_18.out,kernel=kernel_19,strides=[1,1],padding=1)

tensor_20 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_20")
add_20 = add_tensor(data1=conv_19.out,data2=tensor_20)

relu_21 = relu(data=add_20.out)

add_22 = add_num(data1=relu_21.out,data2=64)

result_26 = rshift_clip_cast(data=add_22.out,shift_value=7)

kernel_27 = tvm.te.placeholder((256, 1, 1, 64), dtype="int8", name="kernel_27")
conv_27 = conv2d(data=result_26.out,kernel=kernel_27,strides=[1,1],padding=0)

tensor_29 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_29")
result_30 = lshift_add_2(data=conv_27.out,shift_value=8,addnum=32768,tensor_a=tensor_29)

result_34 = rshift_clip_cast(data=result_30.out.out,shift_value=16)
cast_35 = topi.cast(x=result_34.out,dtype="int32")

tensor_36 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_36")
multiply_36 = mul_tensor(data1=cast_35,data2=tensor_36)

tensor_37 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_37")
add_37 = add_tensor(data1=multiply_36.out,data2=tensor_37)
add_38 = add_num(data1=add_37.out,data2=8)

result_42 = rshift_clip_cast(data=add_38.out,shift_value=4)

#No.43Layer
multiply_44 = topi.multiply(lhs=maxpool_3,rhs=16.)
round_45 = topi.round(multiply_44)
clip_cast_47 = clip_cast(round_45)
clip_cast_47.out = topi.transpose(clip_cast_47.out, (0, 2, 3, 1))

kernel_48 = tvm.te.placeholder((256, 1, 1, 64), dtype="int8", name="kernel_48")
conv_48 = conv2d(data=clip_cast_47.out,kernel=kernel_48,strides=[1,1],padding=0)

tensor_49 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_49")
add_49 = add_tensor(data1=conv_48.out,data2=tensor_49)
add_50 = add_num(data1=add_49.out,data2=32)

result_54 = rshift_clip_cast(data=add_50.out,shift_value=6)

cast_55 = topi.cast(x=result_42.out,dtype="int32")
cast_56 = topi.cast(x=result_54.out,dtype="int32")

add_57 = add_tensor_2(data1=cast_55,data2=cast_56)
relu_58 = relu(add_57.out)

result_61 = clip_cast(relu_58.out)

kernel_62 = tvm.te.placeholder((64, 1, 1, 256), dtype="int8", name="kernel_62")
conv_62 = conv2d(data=result_61.out,kernel=kernel_62,strides=[1,1],padding=0)

tensor_64 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_64")
tensor_65 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_65")

result_67 = lshift_add_1(data=conv_62.out,shift_value=9,addnum=65536,tensor_a=tensor_64,tensor_b=tensor_65)
result_71 = rshift_clip_cast(data=result_67.out.out,shift_value=17)

kernel_72 = tvm.te.placeholder((64, 3, 3, 64), dtype="int8", name="kernel_72")
conv_72 = conv2d(data=result_71.out,kernel=kernel_72,strides=[1,1],padding=1)

tensor_73 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_73")
add_73 = add_tensor(data1=conv_72.out,data2=tensor_73)

relu_74 = relu(add_73.out)

add_75 = add_num(data1=relu_74.out,data2=128)

result_79 = rshift_clip_cast(data=add_75.out,shift_value=8)

kernel_80 = tvm.te.placeholder((256, 1, 1, 64), dtype="int8", name="kernel_80")
conv_80 = conv2d(data=result_79.out,kernel=kernel_80,strides=[1,1],padding=0)

tensor_82 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_82")
result_83 = lshift_add_2(data=conv_80.out,shift_value=8,addnum=32768,tensor_a=tensor_82)

result_87 = rshift_clip_cast(data=result_83.out.out,shift_value=16)
cast_88 = topi.cast(x=result_87.out,dtype="int32")

tensor_89 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_89")
multiply_89 = mul_tensor(data1=cast_88,data2=tensor_89)

tensor_90 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_90")
add_90 = add_tensor(data1=multiply_89.out,data2=tensor_90)
add_91 = add_num(data1=add_90.out,data2=8)

result_95 = rshift_clip_cast(data=add_91.out,shift_value=4)

cast_96 = result_61.out
cast_98 = topi.cast(x=result_95.out,dtype="int32")
cast_99 = topi.cast(x=cast_96,dtype="int32")

add_100 = add_tensor_2(data1=cast_98,data2=cast_99)
relu_101 = relu(data=add_100.out)

result_104 = clip_cast(data=relu_101.out)

kernel_105 = tvm.te.placeholder((64, 1, 1, 256), dtype="int8", name="kernel_105")
conv_105 = conv2d(data=result_104.out,kernel=kernel_105,strides=[1,1],padding=0)

tensor_107 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_107")
tensor_108 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_108")

result_110 = lshift_add_1(data=conv_105.out,shift_value=8,addnum=65536,tensor_a=tensor_107,tensor_b=tensor_108)
result_114 = rshift_clip_cast(data=result_110.out.out,shift_value=17)

kernel_115 = tvm.te.placeholder((64, 3, 3, 64), dtype="int8", name="kernel_115")
conv_115 = conv2d(data=result_114.out,kernel=kernel_115,strides=[1,1],padding=1)

tensor_116 = tvm.te.placeholder((64, 1, 1), dtype="int32", name="tensor_116")
add_116 = add_tensor(data1=conv_115.out,data2=tensor_116)
relu_117 = relu(data=add_116.out)
add_118 = add_num(data1=relu_117.out,data2=64)

result_122 = rshift_clip_cast(data=add_118.out,shift_value=7)

kernel_123 = tvm.te.placeholder((256, 1, 1, 64), dtype="int8", name="kernel_123")
conv_123 = conv2d(data=result_122.out,kernel=kernel_123,strides=[1,1],padding=0)

tensor_125 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_125")
result_126 = lshift_add_2(data=conv_123.out,shift_value=8,addnum=32768,tensor_a=tensor_125)

result_130 = rshift_clip_cast(data=result_126.out.out,shift_value=16)
cast_131 = topi.cast(x=result_130.out,dtype="int32")

tensor_132 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_132")
multiply_132 = mul_tensor(data1=cast_131,data2=tensor_132)

tensor_133 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_133")
add_133 = add_tensor(data1=multiply_132.out,data2=tensor_133)
add_134 = add_num(data1=add_133.out,data2=8)

result_138 = rshift_clip_cast(data=add_134.out,shift_value=4)

cast_139 = result_104.out
cast_141 = topi.cast(x=result_138.out,dtype="int32")
cast_142 = topi.cast(x=cast_139,dtype="int32")
add_143 = add_tensor_2(data1=cast_141,data2=cast_142)
relu_144 = relu(data=add_143.out)
result_147 = clip_cast(data=relu_144.out)

kernel_148 = tvm.te.placeholder((128, 1, 1, 256), dtype="int8", name="kernel_148")
conv_148 = conv2d(data=result_147.out,kernel=kernel_148,strides=[2,2],padding=0)

tensor_150 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_150")
tensor_151 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_151")

result_153 = lshift_add_1(data=conv_148.out,shift_value=12,addnum=262144,tensor_a=tensor_150,tensor_b=tensor_151)
result_157 = rshift_clip_cast(data=result_153.out.out,shift_value=19)

kernel_158 = tvm.te.placeholder((128, 3, 3, 128), dtype="int8", name="kernel_158")
conv_158 = conv2d(data=result_157.out,kernel=kernel_158,strides=[1,1],padding=1)

tensor_159 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_159")
add_159 = add_tensor(data1=conv_158.out,data2=tensor_159)
relu_160 = relu(data=add_159.out)
add_161 = add_num(data1=relu_160.out,data2=64)

result_165 = rshift_clip_cast(data=add_161.out,shift_value=7)

kernel_166 = tvm.te.placeholder((512, 1, 1, 128), dtype="int8", name="kernel_166")
conv_166 = conv2d(data=result_165.out,kernel=kernel_166,strides=[1,1],padding=0)

tensor_168 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_168")
result_169 = lshift_add_2(data=conv_166.out,shift_value=10,addnum=131072,tensor_a=tensor_168)
result_173 = rshift_clip_cast(data=result_169.out.out,shift_value=18)

cast_174 = topi.cast(x=result_173.out,dtype="int32")

tensor_175 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_175")
multiply_175 = mul_tensor(data1=cast_174,data2=tensor_175)

tensor_176 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_176")
add_176 = add_tensor(data1=multiply_175.out,data2=tensor_176)
add_177 = add_num(data1=add_176.out,data2=8)

result_181 = rshift_clip_cast(data=add_177.out,shift_value=4)

cast_182 = result_147.out

kernel_184 = tvm.te.placeholder((512, 1, 1, 256), dtype="int8", name="kernel_184")
conv_184 = conv2d(data=cast_182,kernel=kernel_184,strides=[2,2],padding=0)

tensor_185 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_185")
add_185 = add_tensor(data1=conv_184.out,data2=tensor_185)
add_186 = add_num(data1=add_185.out,data2=64)

result_190 = rshift_clip_cast(data=add_186.out,shift_value=7)

cast_191 = topi.cast(x=result_181.out,dtype="int32")
cast_192 = topi.cast(x=result_190.out,dtype="int32")
add_193 = add_tensor_2(data1=cast_191,data2=cast_192)
relu_194 = relu(data=add_193.out)
result_197 = clip_cast(data=relu_194.out)

kernel_198 = tvm.te.placeholder((128, 1, 1, 512), dtype="int8", name="kernel_198")
conv_198 = conv2d(data=result_197.out,kernel=kernel_198,strides=[1,1],padding=0)

tensor_200 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_200")
tensor_201 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_201")

result_203 = lshift_add_1(data=conv_198.out,shift_value=11,addnum=262144,tensor_a=tensor_200,tensor_b=tensor_201)
result_207 = rshift_clip_cast(data=result_203.out.out,shift_value=19)

kernel_208 = tvm.te.placeholder((128, 3, 3, 128), dtype="int8", name="kernel_208")
conv_208 = conv2d(data=result_207.out,kernel=kernel_208,strides=[1,1],padding=1)

tensor_209 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_209")
add_209 = add_tensor(data1=conv_208.out,data2=tensor_209)
relu_210 = relu(data=add_209.out)
add_211 = add_num(data1=relu_210.out,data2=64)

result_215 = rshift_clip_cast(data=add_211.out,shift_value=7)

kernel_216 = tvm.te.placeholder((512, 1, 1, 128), dtype="int8", name="kernel_216")
conv_216 = conv2d(data=result_215.out,kernel=kernel_216,strides=[1,1],padding=0)

tensor_218 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_218")
result_219 = lshift_add_2(data=conv_216.out,shift_value=10,addnum=131072,tensor_a=tensor_218)
result_223 = rshift_clip_cast(data=result_219.out.out,shift_value=18)

cast_224 = topi.cast(x=result_223.out,dtype="int32")

tensor_225 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_225")
multiply_225 = mul_tensor(data1=cast_224,data2=tensor_225)

tensor_226 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_226")
add_226 = add_tensor(data1=multiply_225.out,data2=tensor_226)
add_227 = add_num(data1=add_226.out,data2=8)

result_231 = rshift_clip_cast(data=add_227.out,shift_value=4)

cast_232 = result_197.out

cast_234 = topi.cast(x=result_231.out,dtype="int32")
cast_235 = topi.cast(x=result_197.out,dtype="int32")
add_236 = add_tensor_2(data1=cast_234,data2=cast_235)
relu_237 = relu(data=add_236.out)
result_240 = clip_cast(data=relu_237.out)

kernel_241 = tvm.te.placeholder((128, 1, 1, 512), dtype="int8", name="kernel_241")
conv_241 = conv2d(data=result_240.out,kernel=kernel_241,strides=[1,1],padding=0)

tensor_243 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_243")
tensor_244 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_244")

result_246 = lshift_add_1(data=conv_241.out,shift_value=11,addnum=262144,tensor_a=tensor_243,tensor_b=tensor_244)
result_250 = rshift_clip_cast(data=result_246.out.out,shift_value=19)

kernel_251 = tvm.te.placeholder((128, 3, 3, 128), dtype="int8", name="kernel_251")
conv_251 = conv2d(data=result_250.out,kernel=kernel_251,strides=[1,1],padding=1)

tensor_252 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_252")
add_252 = add_tensor(data1=conv_251.out,data2=tensor_252)
relu_253 = relu(data=add_252.out)
add_254 = add_num(data1=relu_253.out,data2=32)

result_258 = rshift_clip_cast(data=add_254.out,shift_value=6)

kernel_259 = tvm.te.placeholder((512, 1, 1, 128), dtype="int8", name="kernel_259")
conv_259 = conv2d(data=result_258.out,kernel=kernel_259,strides=[1,1],padding=0)

tensor_261 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_261")
result_262 = lshift_add_2(data=conv_259.out,shift_value=10,addnum=131072,tensor_a=tensor_261)
result_266 = rshift_clip_cast(data=result_262.out.out,shift_value=18)

cast_267 = topi.cast(x=result_266.out,dtype="int32")

tensor_268 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_268")
multiply_268 = mul_tensor(data1=cast_267,data2=tensor_268)

tensor_269 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_269")
add_269 = add_tensor(data1=multiply_268.out,data2=tensor_269)
add_270 = add_num(data1=add_269.out,data2=8)

result_274 = rshift_clip_cast(data=add_270.out,shift_value=4)

cast_275 = result_240.out

cast_277 = topi.cast(x=result_274.out,dtype="int32")
cast_278 = topi.cast(x=result_240.out,dtype="int32")
add_279 = add_tensor_2(data1=cast_277,data2=cast_278)
relu_280 = relu(data=add_279.out)
result_283 = clip_cast(data=relu_280.out)

kernel_284 = tvm.te.placeholder((128, 1, 1, 512), dtype="int8", name="kernel_284")
conv_284 = conv2d(data=result_283.out,kernel=kernel_284,strides=[1,1],padding=0)

tensor_286 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_286")
tensor_287 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_287")

result_289 = lshift_add_1(data=conv_284.out,shift_value=11,addnum=262144,tensor_a=tensor_286,tensor_b=tensor_287)
result_293 = rshift_clip_cast(data=result_289.out.out,shift_value=19)

kernel_294 = tvm.te.placeholder((128, 3, 3, 128), dtype="int8", name="kernel_294")
conv_294 = conv2d(data=result_293.out,kernel=kernel_294,strides=[1,1],padding=1)

tensor_295 = tvm.te.placeholder((128, 1, 1), dtype="int32", name="tensor_295")
add_295 = add_tensor(data1=conv_294.out,data2=tensor_295)
relu_296 = relu(data=add_295.out)
add_297 = add_num(data1=relu_296.out,data2=128)

result_301 = rshift_clip_cast(data=add_297.out,shift_value=8)

kernel_302 = tvm.te.placeholder((512, 1, 1, 128), dtype="int8", name="kernel_302")
conv_302 = conv2d(data=result_301.out,kernel=kernel_302,strides=[1,1],padding=0)

tensor_304 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_304")
result_305 = lshift_add_2(data=conv_302.out,shift_value=10,addnum=131072,tensor_a=tensor_304)
result_309 = rshift_clip_cast(data=result_305.out.out,shift_value=18)

cast_310 = topi.cast(x=result_309.out,dtype="int32")

tensor_311 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_311")
multiply_311 = mul_tensor(data1=cast_310,data2=tensor_311)

tensor_312 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_312")
add_312 = add_tensor(data1=multiply_311.out,data2=tensor_312)
add_313 = add_num(data1=add_312.out,data2=8)

result_317 = rshift_clip_cast(data=add_313.out,shift_value=4)

cast_318 = result_283.out

cast_320 = topi.cast(x=result_317.out,dtype="int32")
cast_321 = topi.cast(x=result_283.out,dtype="int32")
add_322 = add_tensor_2(data1=cast_320,data2=cast_321)
relu_323 = relu(data=add_322.out)
result_326 = clip_cast(data=relu_323.out)

kernel_327 = tvm.te.placeholder((256, 1, 1, 512), dtype="int8", name="kernel_327")
conv_327 = conv2d(data=result_326.out,kernel=kernel_327,strides=[2,2],padding=0)

tensor_329 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_329")
tensor_330 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_330")

result_332 = lshift_add_1(data=conv_327.out,shift_value=12,addnum=524288,tensor_a=tensor_329,tensor_b=tensor_330)
result_336 = rshift_clip_cast(data=result_332.out.out,shift_value=20)

kernel_337 = tvm.te.placeholder((256, 3, 3, 256), dtype="int8", name="kernel_337")
conv_337 = conv2d(data=result_336.out,kernel=kernel_337,strides=[1,1],padding=1)

tensor_338 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_338")
add_338 = add_tensor(data1=conv_337.out,data2=tensor_338)
relu_339 = relu(data=add_338.out)
add_340 = add_num(data1=relu_339.out,data2=128)

result_344 = rshift_clip_cast(data=add_340.out,shift_value=8)

kernel_345 = tvm.te.placeholder((1024, 1, 1, 256), dtype="int8", name="kernel_345")
conv_345 = conv2d(data=result_344.out,kernel=kernel_345,strides=[1,1],padding=0)

tensor_347 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_347")
result_348 = lshift_add_2(data=conv_345.out,shift_value=12,addnum=262144,tensor_a=tensor_347)
result_352 = rshift_clip_cast(data=result_348.out.out,shift_value=19)

cast_353 = topi.cast(x=result_352.out,dtype="int32")

tensor_354 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_354")
multiply_354 = mul_tensor(data1=cast_353,data2=tensor_354)

tensor_355 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_355")
add_355 = add_tensor(data1=multiply_354.out,data2=tensor_355)
add_356 = add_num(data1=add_355.out,data2=8)

result_360 = rshift_clip_cast(data=add_356.out,shift_value=4)

cast_361 = result_326.out

kernel_363 = tvm.te.placeholder((1024, 1, 1, 512), dtype="int8", name="kernel_363")
conv_363 = conv2d(data=cast_361,kernel=kernel_363,strides=[2,2],padding=0)

tensor_364 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_364")
add_364 = add_tensor(data1=conv_363.out,data2=tensor_364)
add_365 = add_num(data1=add_364.out,data2=64)

result_369 = rshift_clip_cast(data=add_365.out,shift_value=7)

cast_370 = topi.cast(x=result_360.out,dtype="int32")
cast_371 = topi.cast(x=result_369.out,dtype="int32")
add_372 = add_tensor_2(data1=cast_370,data2=cast_371)
relu_373 = relu(data=add_372.out)
result_376 = clip_cast(data=relu_373.out)

kernel_377 = tvm.te.placeholder((256, 1, 1, 1024), dtype="int8", name="kernel_377")
conv_377 = conv2d(data=result_376.out,kernel=kernel_377,strides=[1,1],padding=0)

tensor_379 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_379")
tensor_380 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_380")

result_382 = lshift_add_1(data=conv_377.out,shift_value=12,addnum=524288,tensor_a=tensor_379,tensor_b=tensor_380)
result_386 = rshift_clip_cast(data=result_382.out.out,shift_value=20)

kernel_387 = tvm.te.placeholder((256, 3, 3, 256), dtype="int8", name="kernel_387")
conv_387 = conv2d(data=result_386.out,kernel=kernel_387,strides=[1,1],padding=1)

tensor_388 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_388")
add_388 = add_tensor(data1=conv_387.out,data2=tensor_388)
relu_389 = relu(data=add_388.out)
add_390 = add_num(data1=relu_389.out,data2=128)

result_394 = rshift_clip_cast(data=add_390.out,shift_value=8)

kernel_395 = tvm.te.placeholder((1024, 1, 1, 256), dtype="int8", name="kernel_395")
conv_395 = conv2d(data=result_394.out,kernel=kernel_395,strides=[1,1],padding=0)

tensor_397 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_397")
result_398 = lshift_add_2(data=conv_395.out,shift_value=10,addnum=131072,tensor_a=tensor_397)
result_402 = rshift_clip_cast(data=result_398.out.out,shift_value=18)

cast_403 = topi.cast(x=result_402.out,dtype="int32")

tensor_404 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_404")
multiply_404 = mul_tensor(data1=cast_403,data2=tensor_404)

tensor_405 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_405")
add_405 = add_tensor(data1=multiply_404.out,data2=tensor_405)
add_406 = add_num(data1=add_405.out,data2=8)

result_410 = rshift_clip_cast(data=add_406.out,shift_value=4)

cast_411 = result_376.out

cast_413 = topi.cast(x=result_410.out,dtype="int32")
cast_414 = topi.cast(x=result_376.out,dtype="int32")
add_415 = add_tensor_2(data1=cast_413,data2=cast_414)
relu_416 = relu(data=add_415.out)
result_419 = clip_cast(data=relu_416.out)

kernel_420 = tvm.te.placeholder((256, 1, 1, 1024), dtype="int8", name="kernel_420")
conv_420 = conv2d(data=result_419.out,kernel=kernel_420,strides=[1,1],padding=0)

tensor_422 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_422")
tensor_423 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_423")

result_425 = lshift_add_1(data=conv_420.out,shift_value=12,addnum=524288,tensor_a=tensor_422,tensor_b=tensor_423)
result_429 = rshift_clip_cast(data=result_425.out.out,shift_value=20)

kernel_430 = tvm.te.placeholder((256, 3, 3, 256), dtype="int8", name="kernel_430")
conv_430 = conv2d(data=result_429.out,kernel=kernel_430,strides=[1,1],padding=1)

tensor_431 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_431")
add_431 = add_tensor(data1=conv_430.out,data2=tensor_431)
relu_432 = relu(data=add_431.out)
add_433 = add_num(data1=relu_432.out,data2=64)

result_437 = rshift_clip_cast(data=add_433.out,shift_value=7)

kernel_438 = tvm.te.placeholder((1024, 1, 1, 256), dtype="int8", name="kernel_438")
conv_438 = conv2d(data=result_437.out,kernel=kernel_438,strides=[1,1],padding=0)

tensor_440 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_440")
result_441 = lshift_add_2(data=conv_438.out,shift_value=10,addnum=131072,tensor_a=tensor_440)
result_445 = rshift_clip_cast(data=result_441.out.out,shift_value=18)

cast_446 = topi.cast(x=result_445.out,dtype="int32")

tensor_447 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_447")
multiply_447 = mul_tensor(data1=cast_446,data2=tensor_447)

tensor_448 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_448")
add_448 = add_tensor(data1=multiply_447.out,data2=tensor_448)
add_449 = add_num(data1=add_448.out,data2=8)

result_453 = rshift_clip_cast(data=add_449.out,shift_value=4)

cast_454 = result_419.out

cast_456 = topi.cast(x=result_453.out,dtype="int32")
cast_457 = topi.cast(x=result_419.out,dtype="int32")
add_458 = add_tensor_2(data1=cast_456,data2=cast_457)
relu_459 = relu(data=add_458.out)
result_462 = clip_cast(data=relu_459.out)

kernel_463 = tvm.te.placeholder((256, 1, 1, 1024), dtype="int8", name="kernel_463")
conv_463 = conv2d(data=result_462.out,kernel=kernel_463,strides=[1,1],padding=0)

tensor_465 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_465")
tensor_466 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_466")

result_468 = lshift_add_1(data=conv_463.out,shift_value=12,addnum=524288,tensor_a=tensor_465,tensor_b=tensor_466)
result_472 = rshift_clip_cast(data=result_468.out.out,shift_value=20)

kernel_473 = tvm.te.placeholder((256, 3, 3, 256), dtype="int8", name="kernel_473")
conv_473 = conv2d(data=result_472.out,kernel=kernel_473,strides=[1,1],padding=1)

tensor_474 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_474")
add_474 = add_tensor(data1=conv_473.out,data2=tensor_474)
relu_475 = relu(data=add_474.out)
add_476 = add_num(data1=relu_475.out,data2=64)

result_480 = rshift_clip_cast(data=add_476.out,shift_value=7)

kernel_481 = tvm.te.placeholder((1024, 1, 1, 256), dtype="int8", name="kernel_481")
conv_481 = conv2d(data=result_480.out,kernel=kernel_481,strides=[1,1],padding=0)

tensor_483 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_483")
result_484 = lshift_add_2(data=conv_481.out,shift_value=10,addnum=131072,tensor_a=tensor_483)
result_488 = rshift_clip_cast(data=result_484.out.out,shift_value=18)

cast_489 = topi.cast(x=result_488.out,dtype="int32")

tensor_490 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_490")
multiply_490 = mul_tensor(data1=cast_489,data2=tensor_490)

tensor_491 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_491")
add_491 = add_tensor(data1=multiply_490.out,data2=tensor_491)
add_492 = add_num(data1=add_491.out,data2=8)

result_496 = rshift_clip_cast(data=add_492.out,shift_value=4)

cast_497 = result_462.out

cast_499 = topi.cast(x=result_496.out,dtype="int32")
cast_500 = topi.cast(x=result_462.out,dtype="int32")
add_501 = add_tensor_2(data1=cast_499,data2=cast_500)
relu_502 = relu(data=add_501.out)
result_505 = clip_cast(data=relu_502.out)

kernel_506 = tvm.te.placeholder((256, 1, 1, 1024), dtype="int8", name="kernel_506")
conv_506 = conv2d(data=result_505.out,kernel=kernel_506,strides=[1,1],padding=0)

tensor_508 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_508")
tensor_509 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_509")

result_511 = lshift_add_1(data=conv_506.out,shift_value=12,addnum=524288,tensor_a=tensor_508,tensor_b=tensor_509)
result_515 = rshift_clip_cast(data=result_511.out.out,shift_value=20)

kernel_516 = tvm.te.placeholder((256, 3, 3, 256), dtype="int8", name="kernel_516")
conv_516 = conv2d(data=result_515.out,kernel=kernel_516,strides=[1,1],padding=1)

tensor_517 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_517")
add_517 = add_tensor(data1=conv_516.out,data2=tensor_517)
relu_518 = relu(data=add_517.out)
add_519 = add_num(data1=relu_518.out,data2=16)

result_523 = rshift_clip_cast(data=add_519.out,shift_value=5)

kernel_524 = tvm.te.placeholder((1024, 1, 1, 256), dtype="int8", name="kernel_524")
conv_524 = conv2d(data=result_523.out,kernel=kernel_524,strides=[1,1],padding=0)

tensor_526 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_526")
result_527 = lshift_add_2(data=conv_524.out,shift_value=11,addnum=262144,tensor_a=tensor_526)
result_531 = rshift_clip_cast(data=result_527.out.out,shift_value=19)

cast_532 = topi.cast(x=result_531.out,dtype="int32")

tensor_533 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_533")
multiply_533 = mul_tensor(data1=cast_532,data2=tensor_533)

tensor_534 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_534")
add_534 = add_tensor(data1=multiply_533.out,data2=tensor_534)
add_535 = add_num(data1=add_534.out,data2=8)

result_539 = rshift_clip_cast(data=add_535.out,shift_value=4)

cast_540 = result_505.out

cast_542 = topi.cast(x=result_539.out,dtype="int32")
cast_543 = topi.cast(x=result_505.out,dtype="int32")
add_544 = add_tensor_2(data1=cast_542,data2=cast_543)
relu_545 = relu(data=add_544.out)
result_548 = clip_cast(data=relu_545.out)

kernel_549 = tvm.te.placeholder((256, 1, 1, 1024), dtype="int8", name="kernel_549")
conv_549 = conv2d(data=result_548.out,kernel=kernel_549,strides=[1,1],padding=0)

tensor_551 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_551")
tensor_552 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_552")

result_554 = lshift_add_1(data=conv_549.out,shift_value=12,addnum=524288,tensor_a=tensor_551,tensor_b=tensor_552)
result_558 = rshift_clip_cast(data=result_554.out.out,shift_value=20)

kernel_559 = tvm.te.placeholder((256, 3, 3, 256), dtype="int8", name="kernel_559")
conv_559 = conv2d(data=result_558.out,kernel=kernel_559,strides=[1,1],padding=1)

tensor_560 = tvm.te.placeholder((256, 1, 1), dtype="int32", name="tensor_560")
add_560 = add_tensor(data1=conv_559.out,data2=tensor_560)
relu_561 = relu(data=add_560.out)
add_562 = add_num(data1=relu_561.out,data2=64)

result_566 = rshift_clip_cast(data=add_562.out,shift_value=7)

kernel_567 = tvm.te.placeholder((1024, 1, 1, 256), dtype="int8", name="kernel_567")
conv_567 = conv2d(data=result_566.out,kernel=kernel_567,strides=[1,1],padding=0)

tensor_569 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_569")
result_570 = lshift_add_2(data=conv_567.out,shift_value=9,addnum=131072,tensor_a=tensor_569)
result_574 = rshift_clip_cast(data=result_570.out.out,shift_value=18)

cast_575 = topi.cast(x=result_574.out,dtype="int32")

tensor_576 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_576")
multiply_576 = mul_tensor(data1=cast_575,data2=tensor_576)

tensor_577 = tvm.te.placeholder((1024, 1, 1), dtype="int32", name="tensor_577")
add_577 = add_tensor(data1=multiply_576.out,data2=tensor_577)
add_578 = add_num(data1=add_577.out,data2=8)

result_582 = rshift_clip_cast(data=add_578.out,shift_value=4)

cast_583 = result_548.out

cast_585 = topi.cast(x=result_582.out,dtype="int32")
cast_586 = topi.cast(x=result_548.out,dtype="int32")
add_587 = add_tensor_2(data1=cast_585,data2=cast_586)
relu_588 = relu(data=add_587.out)
result_591 = clip_cast(data=relu_588.out)

kernel_592 = tvm.te.placeholder((512, 1, 1, 1024), dtype="int8", name="kernel_592")
conv_592 = conv2d(data=result_591.out,kernel=kernel_592,strides=[2,2],padding=0)

tensor_594 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_594")
tensor_595 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_595")

result_597 = lshift_add_1(data=conv_592.out,shift_value=18,addnum=33554432,tensor_a=tensor_594,tensor_b=tensor_595)
result_601 = rshift_clip_cast(data=result_597.out.out,shift_value=26)

kernel_602 = tvm.te.placeholder((512, 3, 3, 512), dtype="int8", name="kernel_602")
conv_602 = conv2d(data=result_601.out,kernel=kernel_602,strides=[1,1],padding=1)

tensor_603 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_603")
add_603 = add_tensor(data1=conv_602.out,data2=tensor_603)
relu_604 = relu(data=add_603.out)
add_605 = add_num(data1=relu_604.out,data2=64)

result_609 = rshift_clip_cast(data=add_605.out,shift_value=7)

kernel_610 = tvm.te.placeholder((2048, 1, 1, 512), dtype="int8", name="kernel_610")
conv_610 = conv2d(data=result_609.out,kernel=kernel_610,strides=[1,1],padding=0)

tensor_612 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_612")
result_613 = lshift_add_2(data=conv_610.out,shift_value=17,addnum=16777216,tensor_a=tensor_612)
result_617 = rshift_clip_cast(data=result_613.out.out,shift_value=25)

cast_618 = topi.cast(x=result_617.out,dtype="int32")

tensor_619 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_619")
multiply_619 = mul_tensor(data1=cast_618,data2=tensor_619)

tensor_620 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_620")
add_620 = add_tensor(data1=multiply_619.out,data2=tensor_620)
add_621 = add_num(data1=add_620.out,data2=8)

result_625 = rshift_clip_cast(data=add_621.out,shift_value=4)

cast_626 = result_591.out

kernel_628 = tvm.te.placeholder((2048, 1, 1, 1024), dtype="int8", name="kernel_628")
conv_628 = conv2d(data=cast_626,kernel=kernel_628,strides=[2,2],padding=0)

tensor_629 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_629")
add_629 = add_tensor(data1=conv_628.out,data2=tensor_629)
add_630 = add_num(data1=add_629.out,data2=64)

result_634 = rshift_clip_cast(data=add_630.out,shift_value=7)

cast_635 = topi.cast(x=result_625.out,dtype="int32")
cast_636 = topi.cast(x=result_634.out,dtype="int32")
add_637 = add_tensor_2(data1=cast_635,data2=cast_636)
relu_638 = relu(data=add_637.out)
result_641 = clip_cast(data=relu_638.out)

kernel_642 = tvm.te.placeholder((512, 1, 1, 2048), dtype="int8", name="kernel_642")
conv_642 = conv2d(data=result_641.out,kernel=kernel_642,strides=[1,1],padding=0)

tensor_644 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_644")
tensor_645 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_645")

result_647 = lshift_add_1(data=conv_642.out,shift_value=18,addnum=16777216,tensor_a=tensor_644,tensor_b=tensor_645)
result_651 = rshift_clip_cast(data=result_647.out.out,shift_value=25)

kernel_652 = tvm.te.placeholder((512, 3, 3, 512), dtype="int8", name="kernel_652")
conv_652 = conv2d(data=result_651.out,kernel=kernel_652,strides=[1,1],padding=1)

tensor_653 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_653")
add_653 = add_tensor(data1=conv_652.out,data2=tensor_653)
relu_654 = relu(data=add_653.out)
add_655 = add_num(data1=relu_654.out,data2=32)

result_659 = rshift_clip_cast(data=add_655.out,shift_value=6)

kernel_660 = tvm.te.placeholder((2048, 1, 1, 512), dtype="int8", name="kernel_660")
conv_660 = conv2d(data=result_659.out,kernel=kernel_660,strides=[1,1],padding=0)

tensor_662 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_662")
result_663 = lshift_add_2(data=conv_660.out,shift_value=16,addnum=8388608,tensor_a=tensor_662)
result_667 = rshift_clip_cast(data=result_663.out.out,shift_value=24)

cast_668 = topi.cast(x=result_667.out,dtype="int32")

tensor_669 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_669")
multiply_669 = mul_tensor(data1=cast_668,data2=tensor_669)

tensor_670 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_670")
add_670 = add_tensor(data1=multiply_669.out,data2=tensor_670)
add_671 = add_num(data1=add_670.out,data2=8)

result_675 = rshift_clip_cast(data=add_671.out,shift_value=4)

cast_676 = result_641.out

cast_678 = topi.cast(x=result_675.out,dtype="int32")
cast_679 = topi.cast(x=result_641.out,dtype="int32")
add_680 = add_tensor_2(data1=cast_678,data2=cast_679)
relu_681 = relu(data=add_680.out)
result_684 = clip_cast(data=relu_681.out)

kernel_685 = tvm.te.placeholder((512, 1, 1, 2048), dtype="int8", name="kernel_685")
conv_685 = conv2d(data=result_684.out,kernel=kernel_685,strides=[1,1],padding=0)

tensor_687 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_687")
tensor_688 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_688")

result_690 = lshift_add_1(data=conv_685.out,shift_value=18,addnum=16777216,tensor_a=tensor_687,tensor_b=tensor_688)
result_694 = rshift_clip_cast(data=result_690.out.out,shift_value=25)

kernel_695 = tvm.te.placeholder((512, 3, 3, 512), dtype="int8", name="kernel_695")
conv_695 = conv2d(data=result_694.out,kernel=kernel_695,strides=[1,1],padding=1)

tensor_696 = tvm.te.placeholder((512, 1, 1), dtype="int32", name="tensor_696")
add_696 = add_tensor(data1=conv_695.out,data2=tensor_696)
relu_697 = relu(data=add_696.out)
add_698 = add_num(data1=relu_697.out,data2=64)

result_702 = rshift_clip_cast(data=add_698.out,shift_value=7)

kernel_703 = tvm.te.placeholder((2048, 1, 1, 512), dtype="int8", name="kernel_703")
conv_703 = conv2d(data=result_702.out,kernel=kernel_703,strides=[1,1],padding=0)

tensor_705 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_705")
result_706 = lshift_add_2(data=conv_703.out,shift_value=17,addnum=8388608,tensor_a=tensor_705)
result_710 = rshift_clip_cast(data=result_706.out.out,shift_value=24)

cast_711 = topi.cast(x=result_710.out,dtype="int32")

tensor_712 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_712")
multiply_712 = mul_tensor(data1=cast_711,data2=tensor_712)

tensor_714 = tvm.te.placeholder((2048, 1, 1), dtype="int32", name="tensor_714")
result_715 = lshift_add_2(data=multiply_712.out,shift_value=1,addnum=4,tensor_a=tensor_714)
result_719 = rshift_clip_cast(data=result_715.out.out,shift_value=3)

cast_720 = result_684.out

cast_722 = topi.cast(x=result_719.out,dtype="int32")
cast_723 = topi.cast(x=result_684.out,dtype="int32")
add_724 = add_tensor_2(data1=cast_722,data2=cast_723)
relu_725 = relu(data=add_724.out)

cast_726 = topi.cast(x=relu_725.out,dtype="int8")
cast_728 = topi.cast(x=cast_726,dtype="int32")

cast_728 = topi.transpose(cast_728, (0, 3, 1, 2))

avgpool_729 = topi.nn.global_pool(data=cast_728,pool_type="avg",layout="NCHW")
batch_730 = topi.nn.flatten(data=avgpool_729)
cast_731 = topi.cast(x=batch_730,dtype="float32")
multiply_732 = topi.multiply(lhs=cast_731,rhs=0.0625)

tensor_733 = tvm.te.placeholder((1000,2048), dtype="float32", name="tensor_733")
tensor_734 = tvm.te.placeholder((1000,), dtype="float32", name="tensor_734")

dense_733 = topi.nn.dense(data=multiply_732,weight=tensor_733,bias=None,out_dtype=None,auto_scheduler_rewritten_layout="")
final = topi.add(lhs=dense_733,rhs=tensor_734)
##########
### Ending
s = te.create_schedule(final.op)









# target = "llvm"

m = [conv_1.data,conv_1.kernel,tensor_1,conv_9.kernel,tensor_11,tensor_12,conv_19.kernel,tensor_20,kernel_27,tensor_29,
     tensor_36,tensor_37,kernel_48,tensor_49,kernel_62,tensor_64,tensor_65,kernel_72,tensor_73,kernel_80,tensor_82,
     tensor_89,tensor_90,kernel_105,tensor_107,tensor_108,kernel_115,tensor_116,kernel_123,tensor_125,tensor_132,
     tensor_133,kernel_148,tensor_150,tensor_151,kernel_158,tensor_159,kernel_166,tensor_168,tensor_175,tensor_176,
     kernel_184,tensor_185,kernel_198,tensor_200,tensor_201,kernel_208,tensor_209,kernel_216,tensor_218,tensor_225,
     tensor_226,kernel_241,tensor_243,tensor_244,kernel_251,tensor_252,kernel_259,tensor_261,tensor_268,tensor_269,
     kernel_284,tensor_286,tensor_287,kernel_294,tensor_295,kernel_302,tensor_304,tensor_311,tensor_312,kernel_327,
     tensor_329,tensor_330,kernel_337,tensor_338,kernel_345,tensor_347,tensor_354,tensor_355,kernel_363,tensor_364,
     kernel_377,tensor_379,tensor_380,kernel_387,tensor_388,kernel_395,tensor_397,tensor_404,tensor_405,kernel_420,
     tensor_422,tensor_423,kernel_430,tensor_431,kernel_438,tensor_440,tensor_447,tensor_448,kernel_463,tensor_465,
     tensor_466,kernel_473,tensor_474,kernel_481,tensor_483,tensor_490,tensor_491,kernel_506,tensor_508,tensor_509,
     kernel_516,tensor_517,kernel_524,tensor_526,tensor_533,tensor_534,kernel_549,tensor_551,tensor_552,kernel_559,
     tensor_560,kernel_567,tensor_569,tensor_576,tensor_577,kernel_592,tensor_594,tensor_595,kernel_602,tensor_603,
     kernel_610,tensor_612,tensor_619,tensor_620,kernel_628,tensor_629,kernel_642,tensor_644,tensor_645,kernel_652,
     tensor_653,kernel_660,tensor_662,tensor_669,tensor_670,kernel_685,tensor_687,tensor_688,kernel_695,tensor_696,
     kernel_703,tensor_705,tensor_712,tensor_714,tensor_733,tensor_734,final]




# func = tvm.build(s, m, target=target, name="resnet50")

s = conv_schedule(s,conv_9)
s = left_shift_schedule(s,result_14.mid1)
s = add_tensor_schedule(s,result_14.mid2)
s = add_num_schedule(s,result_14.out)
s = right_shift_schedule(s,result_18.mid1)
s = conv_schedule(s,conv_19)
s = add_tensor_schedule(s,add_20)
s = relu_schedule(s,relu_21)
s = add_num_schedule(s,add_22)
s = right_shift_schedule(s,result_26.mid1)
s = conv_schedule(s,conv_27)
s = left_shift_schedule(s,result_30.mid1)
s = add_tensor_schedule(s,result_30.mid2)
s = add_num_schedule(s,result_30.out)
s = right_shift_schedule(s,result_34.mid1)
s = mul_tensor_schedule(s,multiply_36)
s = add_tensor_schedule(s,add_37)
s = add_num_schedule(s,add_38)
s = right_shift_schedule(s,result_42.mid1)
s = conv_schedule(s,conv_48)
s = add_tensor_schedule(s,add_49)
s = add_num_schedule(s,add_50)
s = right_shift_schedule(s,result_54.mid1)
s = add_tensor_schedule(s,add_57)
s = relu_schedule(s,relu_58)
s = conv_schedule(s,conv_62)
s = left_shift_schedule(s,result_67.mid1)
s = add_tensor_schedule(s,result_67.mid2)
s = add_tensor_schedule(s,result_67.mid3)
s = relu_schedule(s,result_67.mid4)
s = add_num_schedule(s,result_67.out)
s = right_shift_schedule(s,result_71.mid1)
s = conv_schedule(s,conv_72)
s = add_tensor_schedule(s,add_73)
s = relu_schedule(s,relu_74)
s = add_num_schedule(s,add_75)
s = right_shift_schedule(s,result_79.mid1)
s = conv_schedule(s,conv_80)
s = left_shift_schedule(s,result_83.mid1)
s = add_tensor_schedule(s,result_83.mid2)
s = add_num_schedule(s,result_83.out)
s = right_shift_schedule(s,result_87.mid1)
s = mul_tensor_schedule(s,multiply_89)
s = add_tensor_schedule(s, add_90)
s = add_num_schedule(s,add_91)
s = right_shift_schedule(s,result_95.mid1)
s = add_tensor_schedule(s,add_100)
s = relu_schedule(s,relu_101)
s = conv_schedule(s,conv_105)
s = left_shift_schedule(s,result_110.mid1)
s = add_tensor_schedule(s,result_110.mid2)
s = add_tensor_schedule(s,result_110.mid3)
s = relu_schedule(s,result_110.mid4)
s = add_num_schedule(s,result_110.out)
s = right_shift_schedule(s,result_114.mid1)
s = conv_schedule(s,conv_115)
s = add_tensor_schedule(s,add_116)
s = relu_schedule(s,relu_117)
s = add_num_schedule(s,add_118)
s = right_shift_schedule(s,result_122.mid1)
s = conv_schedule(s,conv_123)
s = left_shift_schedule(s,result_126.mid1)
s = add_tensor_schedule(s,result_126.mid2)
s = add_num_schedule(s,result_126.out)
s = right_shift_schedule(s,result_130.mid1)
s = mul_tensor_schedule(s,multiply_132)
s = add_tensor_schedule(s,add_133)
s = add_num_schedule(s,add_134)
s = right_shift_schedule(s,result_138.mid1)
s = add_tensor_schedule(s,add_143)
s = relu_schedule(s,relu_144)
s = conv_schedule(s,conv_148)
s = left_shift_schedule(s,result_153.mid1)
s = add_tensor_schedule(s,result_153.mid2)
s = add_tensor_schedule(s,result_153.mid3)
s = relu_schedule(s,result_153.mid4)
s = add_num_schedule(s,result_153.out)
s = right_shift_schedule(s,result_157.mid1)
s = conv_schedule(s,conv_158)
s = add_tensor_schedule(s,add_159)
s = relu_schedule(s,relu_160)
s = add_num_schedule(s,add_161)
s = right_shift_schedule(s,result_165.mid1)
s = conv_schedule(s,conv_166)
s = left_shift_schedule(s,result_169.mid1)
s = add_tensor_schedule(s,result_169.mid2)
s = add_num_schedule(s,result_169.out)
s = right_shift_schedule(s,result_173.mid1)
s = mul_tensor_schedule(s,multiply_175)
s = add_tensor_schedule(s,add_176)
s = add_num_schedule(s,add_177)
s = right_shift_schedule(s,result_181.mid1)
s = conv_schedule(s,conv_184)
s = add_tensor_schedule(s,add_185)
s = add_num_schedule(s,add_186)
s = right_shift_schedule(s,result_190.mid1)
s = add_tensor_schedule(s,add_193)
s = relu_schedule(s,relu_194)
s = conv_schedule(s,conv_198)
s = left_shift_schedule(s,result_203.mid1)
s = add_tensor_schedule(s,result_203.mid2)
s = add_tensor_schedule(s,result_203.mid3)
s = relu_schedule(s,result_203.mid4)
s = add_num_schedule(s,result_203.out)
s = right_shift_schedule(s,result_207.mid1)
s = conv_schedule(s,conv_208)
s = add_tensor_schedule(s,add_209)
s = relu_schedule(s,relu_210)
s = add_num_schedule(s,add_211)
s = right_shift_schedule(s,result_215.mid1)
s = conv_schedule(s,conv_216)
s = left_shift_schedule(s,result_219.mid1)
s = add_tensor_schedule(s,result_219.mid2)
s = add_num_schedule(s,result_219.out)
s = right_shift_schedule(s,result_223.mid1)
s = mul_tensor_schedule(s,multiply_225)
s = add_tensor_schedule(s,add_226)
s = add_num_schedule(s,add_227)
s = right_shift_schedule(s,result_231.mid1)
s = add_tensor_schedule(s,add_236)
s = relu_schedule(s,relu_237)
s = conv_schedule(s,conv_241)
s = left_shift_schedule(s,result_246.mid1)
s = add_tensor_schedule(s,result_246.mid2)
s = add_tensor_schedule(s,result_246.mid3)
s = relu_schedule(s,result_246.mid4)
s = add_num_schedule(s,result_246.out)
s = right_shift_schedule(s,result_250.mid1)
s = conv_schedule(s,conv_251)
s = add_tensor_schedule(s,add_252)
s = relu_schedule(s,relu_253)
s = add_num_schedule(s,add_254)
s = right_shift_schedule(s,result_258.mid1)
s = conv_schedule(s,conv_259)
s = left_shift_schedule(s,result_262.mid1)
s = add_tensor_schedule(s,result_262.mid2)
s = add_num_schedule(s,result_262.out)
s = right_shift_schedule(s,result_266.mid1)
s = mul_tensor_schedule(s,multiply_268)
s = add_tensor_schedule(s,add_269)
s = add_num_schedule(s,add_270)
s = right_shift_schedule(s,result_274.mid1)
s = add_tensor_schedule(s,add_279)
s = relu_schedule(s,relu_280)
s = conv_schedule(s,conv_284)
s = left_shift_schedule(s,result_289.mid1)
s = add_tensor_schedule(s,result_289.mid2)
s = add_tensor_schedule(s,result_289.mid3)
s = relu_schedule(s,result_289.mid4)
s = add_num_schedule(s,result_289.out)
s = right_shift_schedule(s,result_293.mid1)
s = conv_schedule(s,conv_294)
s = add_tensor_schedule(s,add_295)
s = relu_schedule(s,relu_296)
s = add_num_schedule(s,add_297)
s = right_shift_schedule(s,result_301.mid1)
s = conv_schedule(s,conv_302)
s = left_shift_schedule(s,result_305.mid1)
s = add_tensor_schedule(s,result_305.mid2)
s = add_num_schedule(s,result_305.out)
s = right_shift_schedule(s,result_309.mid1)
s = mul_tensor_schedule(s,multiply_311)
s = add_tensor_schedule(s,add_312)
s = add_num_schedule(s,add_313)
s = right_shift_schedule(s,result_317.mid1)
s = add_tensor_schedule(s,add_322)
s = relu_schedule(s,relu_323)
s = conv_schedule(s,conv_327)
s = left_shift_schedule(s,result_332.mid1)
s = add_tensor_schedule(s,result_332.mid2)
s = add_tensor_schedule(s,result_332.mid3)
s = relu_schedule(s,result_332.mid4)
s = add_num_schedule(s,result_332.out)
s = right_shift_schedule(s,result_336.mid1)
s = conv_schedule(s,conv_337)
s = add_tensor_schedule(s,add_338)
s = relu_schedule(s,relu_339)
s = add_num_schedule(s,add_340)
s = right_shift_schedule(s,result_344.mid1)
s = conv_schedule(s,conv_345)
s = left_shift_schedule(s,result_348.mid1)
s = add_tensor_schedule(s,result_348.mid2)
s = add_num_schedule(s,result_348.out)
s = right_shift_schedule(s,result_352.mid1)
s = mul_tensor_schedule(s,multiply_354)
s = add_tensor_schedule(s,add_355)
s = add_num_schedule(s,add_356)
s = right_shift_schedule(s,result_360.mid1)
s = conv_schedule(s,conv_363)
s = add_tensor_schedule(s,add_364)
s = add_num_schedule(s,add_365)
s = right_shift_schedule(s,result_369.mid1)
s = add_tensor_schedule(s,add_372)
s = relu_schedule(s,relu_373)
s = conv_schedule(s,conv_377)
s = left_shift_schedule(s,result_382.mid1)
s = add_tensor_schedule(s,result_382.mid2)
s = add_tensor_schedule(s,result_382.mid3)
s = relu_schedule(s,result_382.mid4)
s = add_num_schedule(s,result_382.out)
s = right_shift_schedule(s,result_386.mid1)
s = conv_schedule(s,conv_387)
s = add_tensor_schedule(s,add_388)
s = relu_schedule(s,relu_389)
s = add_num_schedule(s,add_390)
s = right_shift_schedule(s,result_394.mid1)
s = conv_schedule(s,conv_395)
s = left_shift_schedule(s,result_398.mid1)
s = add_tensor_schedule(s,result_398.mid2)
s = add_num_schedule(s,result_398.out)
s = right_shift_schedule(s,result_402.mid1)
s = mul_tensor_schedule(s,multiply_404)
s = add_tensor_schedule(s,add_405)
s = add_num_schedule(s,add_406)
s = right_shift_schedule(s,result_410.mid1)
s = add_tensor_schedule(s,add_415)
s = relu_schedule(s,relu_416)
s = conv_schedule(s,conv_420)
s = left_shift_schedule(s,result_425.mid1)
s = add_tensor_schedule(s,result_425.mid2)
s = add_tensor_schedule(s,result_425.mid3)
s = relu_schedule(s,result_425.mid4)
s = add_num_schedule(s,result_425.out)
s = right_shift_schedule(s,result_429.mid1)
s = conv_schedule(s,conv_430)
s = add_tensor_schedule(s,add_431)
s = relu_schedule(s,relu_432)
s = add_num_schedule(s,add_433)
s = right_shift_schedule(s,result_437.mid1)
s = conv_schedule(s,conv_438)
s = left_shift_schedule(s,result_441.mid1)
s = add_tensor_schedule(s,result_441.mid2)
s = add_num_schedule(s,result_441.out)
s = right_shift_schedule(s,result_445.mid1)
s = mul_tensor_schedule(s,multiply_447)
s = add_tensor_schedule(s,add_448)
s = add_num_schedule(s,add_449)
s = right_shift_schedule(s,result_453.mid1)
s = add_tensor_schedule(s,add_458)
s = relu_schedule(s,relu_459)
s = conv_schedule(s,conv_463)
s = left_shift_schedule(s,result_468.mid1)
s = add_tensor_schedule(s,result_468.mid2)
s = add_tensor_schedule(s,result_468.mid3)
s = relu_schedule(s,result_468.mid4)
s = add_num_schedule(s,result_468.out)
s = right_shift_schedule(s,result_472.mid1)
s = conv_schedule(s,conv_473)
s = add_tensor_schedule(s,add_474)
s = relu_schedule(s,relu_475)
s = add_num_schedule(s,add_476)
s = right_shift_schedule(s,result_480.mid1)
s = conv_schedule(s,conv_481)
s = left_shift_schedule(s,result_484.mid1)
s = add_tensor_schedule(s,result_484.mid2)
s = add_num_schedule(s,result_484.out)
s = right_shift_schedule(s,result_488.mid1)
s = mul_tensor_schedule(s,multiply_490)
s = add_tensor_schedule(s,add_491)
s = add_num_schedule(s,add_492)
s = right_shift_schedule(s,result_496.mid1)
s = add_tensor_schedule(s,add_501)
s = relu_schedule(s,relu_502)
s = conv_schedule(s,conv_506)
s = left_shift_schedule(s,result_511.mid1)
s = add_tensor_schedule(s,result_511.mid2)
s = add_tensor_schedule(s,result_511.mid3)
s = relu_schedule(s,result_511.mid4)
s = add_num_schedule(s,result_511.out)
s = right_shift_schedule(s,result_515.mid1)
s = conv_schedule(s,conv_516)
s = add_tensor_schedule(s,add_517)
s = relu_schedule(s,relu_518)
s = add_num_schedule(s,add_519)
s = right_shift_schedule(s,result_523.mid1)
s = conv_schedule(s,conv_524)
s = left_shift_schedule(s,result_527.mid1)
s = add_tensor_schedule(s,result_527.mid2)
s = add_num_schedule(s,result_527.out)
s = right_shift_schedule(s,result_531.mid1)
s = mul_tensor_schedule(s,multiply_533)
s = add_tensor_schedule(s,add_534)
s = add_num_schedule(s,add_535)
s = right_shift_schedule(s,result_539.mid1)
s = add_tensor_schedule(s,add_544)
s = relu_schedule(s,relu_545)
s = conv_schedule(s,conv_549)
s = left_shift_schedule(s,result_554.mid1)
s = add_tensor_schedule(s,result_554.mid2)
s = add_tensor_schedule(s,result_554.mid3)
s = relu_schedule(s,result_554.mid4)
s = add_num_schedule(s,result_554.out)
s = right_shift_schedule(s,result_558.mid1)
s = conv_schedule(s,conv_559)
s = add_tensor_schedule(s,add_560)
s = relu_schedule(s,relu_561)
s = add_num_schedule(s,add_562)
s = right_shift_schedule(s,result_566.mid1)
s = conv_schedule(s,conv_567)
s = left_shift_schedule(s,result_570.mid1)
s = add_tensor_schedule(s,result_570.mid2)
s = add_num_schedule(s,result_570.out)
s = right_shift_schedule(s,result_574.mid1)
s = mul_tensor_schedule(s,multiply_576)
s = add_tensor_schedule(s,add_577)
s = add_num_schedule(s,add_578)
s = right_shift_schedule(s,result_582.mid1)
s = add_tensor_schedule(s,add_587)
s = relu_schedule(s,relu_588)
s = conv_schedule(s,conv_592)
s = left_shift_schedule(s,result_597.mid1)
s = add_tensor_schedule(s,result_597.mid2)
s = add_tensor_schedule(s,result_597.mid3)
s = relu_schedule(s,result_597.mid4)
s = add_num_schedule(s,result_597.out)
s = right_shift_schedule(s,result_601.mid1)
s = conv_schedule(s,conv_602)
s = add_tensor_schedule(s,add_603)
s = relu_schedule(s,relu_604)
s = add_num_schedule(s,add_605)
s = right_shift_schedule(s,result_609.mid1)
s = conv_schedule(s,conv_610)
s = left_shift_schedule(s,result_613.mid1)
s = add_tensor_schedule(s,result_613.mid2)
s = add_num_schedule(s,result_613.out)
s = right_shift_schedule(s,result_617.mid1)
s = mul_tensor_schedule(s,multiply_619)
s = add_tensor_schedule(s,add_620)
s = add_num_schedule(s,add_621)
s = right_shift_schedule(s,result_625.mid1)
s = conv_schedule(s,conv_628)
s = add_tensor_schedule(s,add_629)
s = add_num_schedule(s,add_630)
s = right_shift_schedule(s,result_634.mid1)
s = add_tensor_schedule(s,add_637)
s = relu_schedule(s,relu_638)
s = conv_schedule(s,conv_642)
s = left_shift_schedule(s,result_647.mid1)
s = add_tensor_schedule(s,result_647.mid2)
s = add_tensor_schedule(s,result_647.mid3)
s = relu_schedule(s,result_647.mid4)
s = add_num_schedule(s,result_647.out)
s = right_shift_schedule(s,result_651.mid1)
s = conv_schedule(s,conv_652)
s = add_tensor_schedule(s,add_653)
s = relu_schedule(s,relu_654)
s = add_num_schedule(s,add_655)
s = right_shift_schedule(s,result_659.mid1)
s = conv_schedule(s,conv_660)
s = left_shift_schedule(s,result_663.mid1)
s = add_tensor_schedule(s,result_663.mid2)
s = add_num_schedule(s,result_663.out)
s = right_shift_schedule(s,result_667.mid1)
s = mul_tensor_schedule(s,multiply_669)
s = add_tensor_schedule(s,add_670)
s = add_num_schedule(s,add_671)
s = right_shift_schedule(s,result_675.mid1)
s = add_tensor_schedule(s,add_680)
s = relu_schedule(s,relu_681)
s = conv_schedule(s,conv_685)
s = left_shift_schedule(s,result_690.mid1)
s = add_tensor_schedule(s,result_690.mid2)
s = add_tensor_schedule(s,result_690.mid3)
s = relu_schedule(s,result_690.mid4)
s = add_num_schedule(s,result_690.out)
s = right_shift_schedule(s,result_694.mid1)
s = conv_schedule(s,conv_695)
s = add_tensor_schedule(s,add_696)
s = relu_schedule(s,relu_697)
s = add_num_schedule(s,add_698)
s = right_shift_schedule(s,result_702.mid1)
s = conv_schedule(s,conv_703)
s = left_shift_schedule(s,result_706.mid1)
s = add_tensor_schedule(s,result_706.mid2)
s = add_num_schedule(s,result_706.out)
s = right_shift_schedule(s,result_710.mid1)
s = mul_tensor_schedule(s,multiply_712)
s = left_shift_schedule(s,result_715.mid1)
s = add_tensor_schedule(s,result_715.mid2)
s = add_num_schedule(s,result_715.out)
s = right_shift_schedule(s,result_719.mid1)
s = add_tensor_schedule(s,add_724)
s = relu_schedule(s,relu_725)

print(tvm.lower(s, m, simple_mode=True))

target = "c"
func0 = zte.build(s, m, target=target)
func0.save("resnet50.c")

