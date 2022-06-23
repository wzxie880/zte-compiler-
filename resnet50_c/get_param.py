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
"""
Deploy Pretrained Vision Model from MxNet on VTA
================================================
**Author**: `Thierry Moreau <https://homes.cs.washington.edu/~moreau/>`_

This tutorial provides an end-to-end demo, on how to run ImageNet classification
inference onto the VTA accelerator design to perform ImageNet classification tasks.
It showcases Relay as a front end compiler that can perform quantization (VTA
only supports int8/32 inference) as well as graph packing (in order to enable
tensorization in the core) to massage the compute graph for the hardware target.
"""

######################################################################
# Install dependencies
# --------------------
# To use the autotvm package in tvm, we need to install some extra dependencies.
# (change "3" to "2" if you use python2):
#
# .. code-block:: bash
#
#   pip3 install --user mxnet requests "Pillow<7"
#
# Now return to the python code. Import packages.

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

import vta
from vta.testing import simulator
from vta.top import graph_pack

#import operators
#from operators import conv2d_cpu, conv2d, max_pooling, arg_pooling, dense, add_tensor, mul_tensor, left_shift, right_shift, relu, bn, bias_add

# Make sure that TVM was compiled with RPC=1
assert tvm.runtime.enabled("rpc")

######################################################################
# Define the platform and model targets
# -------------------------------------
# Execute on CPU vs. VTA, and define the model.

# Load VTA parameters from the 3rdparty/vta-hw/config/vta_config.json file
env = vta.get_env()

# Set ``device=arm_cpu`` to run inference on the CPU
# or ``device=vta`` to run inference on the FPGA.
device = "vta"
target = env.target if device == "vta" else env.target_vta_cpu

# Dictionary lookup for when to start/end bit packing
pack_dict = {
    "resnet18_v1": ["nn.max_pool2d", "nn.global_avg_pool2d"],
    "resnet34_v1": ["nn.max_pool2d", "nn.global_avg_pool2d"],
    "resnet18_v2": ["nn.max_pool2d", "nn.global_avg_pool2d"],
    "resnet34_v2": ["nn.max_pool2d", "nn.global_avg_pool2d"],
    "resnet50_v1": ["nn.max_pool2d", "nn.global_avg_pool2d"],
    "resnet101_v2": ["nn.max_pool2d", "nn.global_avg_pool2d"],
}

# Name of Gluon model to compile
# The ``start_pack`` and ``stop_pack`` labels indicate where
# to start and end the graph packing relay pass: in other words
# where to start and finish offloading to VTA.
model = "resnet18_v1"
assert model in pack_dict

with autotvm.tophub.context(target):

    # Populate the shape and data type dictionary for ImageNet classifier input
    dtype_dict = {"data": "float32"}
    shape_dict = {"data": (env.BATCH, 3, 224, 224)}

    # Get off the shelf gluon model, and convert to relay
    gluon_model = vision.get_model(model, pretrained=True)

    # Measure build start time
    build_start = time.time()

    # Start front end compilation
    mod, params = relay.frontend.from_mxnet(gluon_model, shape_dict)

    # Update shape and type dictionary
    shape_dict.update({k: v.shape for k, v in params.items()})
    dtype_dict.update({k: str(v.dtype) for k, v in params.items()})
    print(target.device_name)
    if target.device_name == "vta":
        # Perform quantization in Relay
        # Note: We set opt_level to 3 in order to fold batch norm
        with tvm.transform.PassContext(opt_level=3):
            with relay.quantize.qconfig(global_scale=8.0, skip_conv_layers=[0]):
                mod = relay.quantize.quantize(mod, params=params)
                print(type(mod))
            # Perform graph packing and constant folding for VTA target
            assert env.BLOCK_IN == env.BLOCK_OUT
            # do device annotation if target is intelfocl or sim
            # relay_prog = graph_pack(
            #     mod["main"],
            #     env.BATCH,
            #     env.BLOCK_OUT,
            #     env.WGT_WIDTH,
            #     start_name=pack_dict[model][0],
            #     stop_name=pack_dict[model][1],
            #     device_annot=(env.TARGET == "intelfocl" or env.TARGET == "sim"),
            # )
            relay_prog = mod["main"]
    else:
        relay_prog = mod["main"]

    # Compile Relay program with AlterOpLayout disabled
    if target.device_name != "vta":
        with tvm.transform.PassContext(opt_level=3, disabled_pass={"AlterOpLayout"}):
            graph, lib, params0 = relay.build(
                relay_prog, target="llvm", params=params, target_host=env.target_host
            )
    else:
        if env.TARGET == "intelfocl" or env.TARGET == "sim":
            # multiple targets to run both on cpu and vta
            target = {"cpu": env.target_vta_cpu, "ext_dev": target}
        with vta.build_config(opt_level=3, disabled_pass={"AlterOpLayout"}):
            graph, lib, params0 = relay.build(
                relay_prog, target="llvm", params=params
            )

# np.savetxt("p0.txt",params['p0'])、
np.set_printoptions(threshold=sys.maxsize)
# params_np0=params['p0'].asnumpy()
def save(dict):
    if isinstance(dict, str):
        dict = eval(dict)
    with open('p.txt', 'w', encoding='utf-8') as f:
        f.write(str(dict))  # dict to str

def load():
    with open('p.txt', 'r', encoding='utf-8') as f:
        dict = eval(f.read())
        # print(dict['p0'])

np.save('params.npy',params0)
save(param0)
# np.savetxt("p0.txt",params_np0)
# load()
# print(params['p0'])

# np.save("params.npy",params)

# remote = rpc.LocalSession()
# dev = remote.cpu()

# resnetv20_batchnorm0_gamma = params['p109']
# print(resnetv20_batchnorm0_gamma)
# a = tvm.nd.array(resnetv20_batchnorm0_gamma, dev)
# print(a.dtype)
# print(params.keys())
# print(type(graph))
# ccode = lib.get_source()
# def text_save(content, filename, mode='a'):
#     # Try to save a list variable in txt file.
#     file = open(filename, mode)
#     for i in range(len(content)):
#         file.write(str(content[i]))
#     file.close()


# text_save(params, 'resnet.c')
# pycode = tvm.relay.testing.to_python(mod)
# remote = rpc.LocalSession()
# ctx = remote.ext_dev(0)
# m = graph_executor.create(graph, lib, ctx)