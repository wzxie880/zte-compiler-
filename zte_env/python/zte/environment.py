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
"""Configurable zte Hareware Environment scope."""
# pylint: disable=invalid-name, exec-used
from __future__ import absolute_import as _abs

import os
import json
import copy
import tvm
from tvm import te
from . import intrin
from .intrin_impl import intrin_impl


class DevContext(object):
    """Internal development context

    This contains all the non-user facing compiler
    internal context that is hold by the Environment.

    Parameters
    ----------
    env : Environment
        The environment hosting the DevContext

    Note
    ----
    This class is introduced so we have a clear separation
    of developer related, and user facing attributes.
    """
    # define ADD  1
    # define SUB  2
    # define MUL  3
    # define MAX  5
    # define MIN  6
    # define AND  7
    # define OR   8
    # Memory id for DMA
    MEM_ID_UOP = 0
    MEM_ID_WGT = 1
    MEM_ID_INP = 2
    MEM_ID_ACC = 3
    MEM_ID_OUT = 4
    MEM_ID_INPUTA = 5
    MEM_ID_INPUTB = 6
    # zte ALU Opcodes
    ALU_OPCODE_MIN = 0
    ALU_OPCODE_MAX = 1
    ALU_OPCODE_ADD = 2
    ALU_OPCODE_SHR = 3
    # Task queue id (pipeline stage)
    QID_LOAD_INP = 1
    QID_LOAD_WGT = 1
    QID_LOAD_OUT = 2
    QID_STORE_OUT = 3
    QID_COMPUTE = 2

    def __init__(self, env):
        self.zte_axis = te.thread_axis("zte")
        #self.zte_push_uop = tvm.tir.StringImm("VTAPushGEMMOp")
        ctx = tvm.tir.call_intrin("handle", "tir.zte.command_handle")
        print("ctx",ctx)
        self.command_handle = tvm.tir.Call("handle", "tir.tvm_thread_context", [ctx])
        self.DEBUG_NO_SYNC = False
        env._dev_ctx = self
        self.gemm = intrin.gemm(env, env.mock_mode)

    def get_task_qid(self, qid):
        """Get transformed queue index."""
        return 1 if self.DEBUG_NO_SYNC else qid


class Environment(object):
    """Hardware configuration object.

    This object contains all the information
    needed for compiling to a specific zte backend.

    Parameters
    ----------
    cfg : dict of str to value.
        The configuration parameters.

    Example
    --------
    .. code-block:: python

      # the following code reconfigures the environment
      # temporarily to attributes specified in new_cfg.json
      new_cfg = json.load(json.load(open("new_cfg.json")))
      with zte.Environment(new_cfg):
          # env works on the new environment
          env = zte.get_env()
    """

    current = None
    # constants
    MAX_XFER = 1 << 22
    # debug flags
    DEBUG_DUMP_INSN = 1 << 1
    DEBUG_DUMP_UOP = 1 << 2
    DEBUG_SKIP_READ_BARRIER = 1 << 3
    DEBUG_SKIP_WRITE_BARRIER = 1 << 4
    # memory scopes
    inp_scope = "local.inp1_buffer"
    param_scopeA = "local.param_bufferA"
    param_scopeB = "local.param_bufferB"
    wgt_scope = "local.wgt1_buffer"
    mid_scopeA = "local.mid_bufferA"
    mid_scopeB = "local.mid_bufferB"
    input_scopeA = "local.input_bufferA"
    input_scopeB = "local.input_bufferB"
    output_scopeA = "local.output_bufferA"
    output_scopeB = "local.output_bufferB"
    DDR4A = "local.ddr4A"
    DDR4B = "local.ddr4B"

    # initialization function
    def __init__(self):
        # data type width
        self.INP_WIDTH = 8
        self.WGT_WIDTH = 8

        self.ACC_WIDTH = 32
        self.OUT_WIDTH = 32
        # tensor intrinsic shape
        self.BATCH = 1
        self.BLOCK_IN = 8
        self.BLOCK_OUT = 8
        # buffer size
        self.UOP_BUFF_SIZE = 1 << 15
        self.INP_BUFF_SIZE = 64 * 1024 * 1024
        self.WGT_BUFF_SIZE = 64 * 1024 * 1024
        self.ACC_BUFF_SIZE = 128 * 1024 *1024
        self.OUT_BUFF_SIZE = 128 * 1024 *1024
        self.INPUT_BUFF_SIZE = 100 * 1024 * 1024
        self.DDR4_BUFF_SIZE = 4 * 1024 * 1024 * 1024
        # bytes per buffer
        self.INP_ELEM_BITS = self.BATCH * self.BLOCK_IN * self.INP_WIDTH
        self.WGT_ELEM_BITS = self.BLOCK_OUT * self.BLOCK_IN * self.WGT_WIDTH
        self.ACC_ELEM_BITS = self.BATCH * self.BLOCK_OUT * self.ACC_WIDTH
        self.OUT_ELEM_BITS = self.BATCH * self.BLOCK_OUT * self.OUT_WIDTH
        # self.INP_ELEM_BITS = self.BATCH * self.BLOCK_IN
        # self.WGT_ELEM_BITS = self.BLOCK_OUT * self.BLOCK_IN
        # self.ACC_ELEM_BITS = self.BATCH * self.BLOCK_OUT
        # self.OUT_ELEM_BITS = self.BATCH * self.BLOCK_OUT
        self.INPUT_ELEM_BITS = 128
        self.DDR_ELEM_BITS = 128

        self.INP_ELEM_BYTES = self.INP_ELEM_BITS // 8
        self.WGT_ELEM_BYTES = self.WGT_ELEM_BITS // 8
        self.ACC_ELEM_BYTES = self.ACC_ELEM_BITS // 8
        self.OUT_ELEM_BYTES = self.OUT_ELEM_BITS // 8
        self.INPUT_ELEM_BYTES = self.INPUT_ELEM_BITS // 8
        # dtypes
        self.acc_dtype = "int%d" % self.ACC_WIDTH
        self.inp_dtype = "int%d" % self.INP_WIDTH
        self.wgt_dtype = "int%d" % self.WGT_WIDTH
        self.out_dtype = "int%d" % self.OUT_WIDTH

        # lazy cached members
        self.mock_mode = False
        self._mock_env = None
        self._dev_ctx = None
        self._last_env = None

        self.TARGET = "sim"

    def __enter__(self):
        self._last_env = Environment.current
        Environment.current = self
        return self

    def __exit__(self, ptype, value, trace):
        Environment.current = self._last_env

    @property
    def cfg_dict(self):
        return self.pkg.cfg_dict

    @property
    def dev(self):
        """Developer context"""
        if self._dev_ctx is None:
            self._dev_ctx = DevContext(self)
        return self._dev_ctx

    @property
    def mock(self):
        """A mock version of the Environment

        The ALU, dma_copy and intrinsics will be
        mocked to be nop.
        """
        if self.mock_mode:
            return self
        if self._mock_env is None:
            self._mock_env = copy.copy(self)
            self._mock_env._dev_ctx = None
            self._mock_env.mock_mode = True
        return self._mock_env

    @property
    def dma_copy(self):
        """DMA copy pragma"""
        return "dma_copy" if not self.mock_mode else "skip_dma_copy"

    @property
    def alu(self):
        """ALU pragma"""
        return "alu" if not self.mock_mode else "skip_alu"

    @property
    def gemm(self):
        """GEMM intrinsic"""
        return self.dev.gemm

    # @property
    # def target(self):
    #     """return tvm.target.Target("llvm  -mtriple=riscv64-unknown-linux-gnu -device=zte -mcpu=riscv64 -model=f37x")"""
    #     return tvm.target.Target("c -device=zte -runtime=c -march=riscv64 --system-lib")

    @property
    def target(self):
        #return tvm.target.Target("llvm  -mtriple=riscv64-unknown-linux-gnu -device=zte -mcpu=rv64i -mfloat-abi=lp64 -model=f37x")
        #return tvm.target.Target("llvm  -mtriple=riscv64-unknown-linux-gnu -device=zte -mcpu=riscv64 -model=f37x")
        return tvm.target.Target("c -device=zte -runtime=c -march=rv64i --system-lib")

    @property
    def target_host(self):
        """The target host"""
        if self.TARGET in ["pynq", "de10nano"]:
            return "llvm -mtriple=armv7-none-linux-gnueabihf"
        if self.TARGET == "ultra96":
            return "llvm -mtriple=aarch64-linux-gnu"
        if self.TARGET in ["sim", "tsim"]:
            return "llvm"
        if self.TARGET in ["zte"]:
            return "c"
        raise ValueError("Unknown target %s" % self.TARGET)

    # @property
    # def target_host(self):
    #     """The target host"""
    #     if self.TARGET in ["zte"]:
    #         return "llvm -mtriple=risc-v"
    #     if self.TARGET in ["sim", "tsim"]:
    #         return "c"
    #     raise ValueError("Unknown target %s" % self.TARGET)

    @property
    def target_zte_cpu(self):
        return tvm.target.arm_cpu(model=self.TARGET)


def get_env():
    """Get the current zte Environment.

    Returns
    -------
    env : Environment
        The current environment.
    """
    return Environment.current

strides = te.var("s1")
# The memory information for the compiler
@tvm.register_func("tvm.info.mem.%s" % Environment.inp_scope)
def mem_info_inp_buffer():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.INP_ELEM_BITS,
        max_simd_bits=spec.INP_ELEM_BITS,
        max_num_bits=spec.INP_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )


@tvm.register_func("tvm.info.mem.%s" % Environment.wgt_scope)
def mem_info_wgt_buffer():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.WGT_ELEM_BITS,
        max_simd_bits=spec.WGT_ELEM_BITS,
        max_num_bits=spec.WGT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )


@tvm.register_func("tvm.info.mem.%s" % Environment.mid_scopeA)
def mem_info_acc_bufferA():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.ACC_ELEM_BITS,
        max_simd_bits=spec.ACC_ELEM_BITS,
        max_num_bits=spec.ACC_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.mid_scopeB)
def mem_info_acc_bufferB():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.ACC_ELEM_BITS,
        max_simd_bits=spec.ACC_ELEM_BITS,
        max_num_bits=spec.ACC_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.input_scopeA)
def mem_info_input_buffer_A():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.INPUT_ELEM_BITS,
        max_simd_bits=spec.INPUT_ELEM_BITS,
        max_num_bits=spec.INPUT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.input_scopeB)
def mem_info_input_buffer_B():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.INPUT_ELEM_BITS,
        max_simd_bits=spec.INPUT_ELEM_BITS,
        max_num_bits=spec.INPUT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.param_scopeA)
def mem_info_param_burffe_A():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.INPUT_ELEM_BITS,
        max_simd_bits=spec.INPUT_ELEM_BITS,
        max_num_bits=spec.INPUT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.param_scopeB)
def mem_info_param_buffer_B():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.INPUT_ELEM_BITS,
        max_simd_bits=spec.INPUT_ELEM_BITS,
        max_num_bits=spec.INPUT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.output_scopeA)
def mem_info_outputbufferA():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.OUT_ELEM_BITS,
        max_simd_bits=spec.OUT_ELEM_BITS,
        max_num_bits=spec.OUT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.output_scopeB)
def mem_info_outputbufferB():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.OUT_ELEM_BITS,
        max_simd_bits=spec.OUT_ELEM_BITS,
        max_num_bits=spec.OUT_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.DDR4A)
def mem_info_DDR4A():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.DDR_ELEM_BITS,
        max_simd_bits=spec.DDR_ELEM_BITS,
        max_num_bits=spec.DDR4_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

@tvm.register_func("tvm.info.mem.%s" % Environment.DDR4B)
def mem_info_DDR4B():
    spec = get_env()
    return tvm.ir.make_node(
        "MemoryInfo",
        unit_bits=spec.DDR_ELEM_BITS,
        max_simd_bits=spec.DDR_ELEM_BITS,
        max_num_bits=spec.DDR4_BUFF_SIZE * 8,
        head_address=None,
        # strides=[strides, 1]
    )

# TVM related registration
@tvm.register_func("tvm.intrin.rule.default.zte.coproc_sync")
def coproc_sync(op):
    _ = op
    return tvm.tir.call_extern(
        "int32",
        "zteSynchronize",
        get_env().dev.command_handle,
        tvm.runtime.const(1 << 31, dtype="uint32"),
    )


@tvm.register_func("tvm.intrin.rule.default.zte.coproc_dep_push")
def coproc_dep_push(op):
    return tvm.tir.call_extern(
        "int32", "zteDepPush", get_env().dev.command_handle, op.args[0], op.args[1]
    )


@tvm.register_func("tvm.intrin.rule.default.zte.coproc_dep_pop")
def coproc_dep_pop(op):
    return tvm.tir.call_extern(
        "int32", "zteDepPop", get_env().dev.command_handle, op.args[0], op.args[1]
    )


def _init_env():
    return Environment()


Environment.current = _init_env()
