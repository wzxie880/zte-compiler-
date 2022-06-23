import tvm
from tvm import te
from tvm import autotvm
from tvm import topi

import zte
from zte import get_env

env = get_env()

def superop_schedule(s, superop):
    s[superop.feature_input].set_scope(env.input_scopeA)
    s[superop.weight_input].set_scope(env.input_scopeB)
    s[superop.feature].set_scope(env.inp_scope)
    s[superop.weight].set_scope(env.wgt_scope)
    s[superop.middle_buffer].set_scope(env.mid_scopeA)
    # s[superop.middle].set_scope(env.output_scopeA)
    # s[superop.middle_tran].set_scope(env.mid_scopeA)
    # s[superop.middle_reshape].set_scope(env.output_scopeA)
    # s[superop.middle_unpad].set_scope(env.mid_scopeA)
    s[superop.conv_out].set_scope(env.mid_scopeB)

    s[superop.feature_input].pragma(s[superop.feature_input].op.axis[2], env.dma_copy)
    s[superop.weight_input].pragma(s[superop.weight_input].op.axis[2], env.dma_copy)
    s[superop.feature].pragma(s[superop.feature].op.axis[2], env.dma_copy)
    s[superop.weight].pragma(s[superop.weight].op.axis[2], env.dma_copy)
    # s[superop.middle].pragma(s[superop.middle].op.axis[2], env.dma_copy)
    # s[superop.middle_tran].pragma(s[superop.middle_tran].op.axis[2], env.dma_copy)
    # s[superop.middle_reshape].pragma(s[superop.middle_reshape].op.axis[1], env.dma_copy)
    # s[superop.middle_unpad].pragma(s[superop.middle_unpad].op.axis[1], env.dma_copy)
    s[superop.conv_out].pragma(s[superop.conv_out].op.axis[2], env.dma_copy)

    i, x, j, y = s[superop.middle_buffer].op.axis
    s[superop.middle_buffer].reorder(i, x, superop.k0, superop.k1, j, y, superop.k2)

    s[superop.feature_input].compute_at(s[superop.middle_buffer], superop.k0)
    s[superop.weight_input].compute_at(s[superop.middle_buffer], superop.k0)
    s[superop.feature].compute_at(s[superop.middle_buffer], superop.k0)
    s[superop.weight].compute_at(s[superop.middle_buffer], superop.k0)
    s[superop.middle_buffer].compute_at(s[superop.conv_out], s[superop.conv_out].op.axis[1])
    # s[superop.middle].compute_at(s[superop.middle_tran], s[superop.middle_tran].op.axis[0])
    # s[superop.middle_tran].compute_at(s[superop.middle_reshape], s[superop.middle_reshape].op.axis[0])

    s[superop.middle_buffer].tensorize(superop.k1, env.gemm)

    ################### left shift #######################
    s[superop.lshift_buffer].set_scope(env.mid_scopeA)
    
    s[superop.lshift_out].set_scope(env.output_scopeA)
    s[superop.lshift_out_buffer].set_scope(env.mid_scopeB)
    # s[superop.middle_reshape].set_scope(env.input_scopeA)
    # s[superop.conv_out].set_scope(env.mid_scopeA)

    s[superop.lshift_buffer].pragma(s[superop.lshift_buffer].op.axis[2], env.dma_copy)
    s[superop.lshift_out_buffer].pragma(s[superop.lshift_out_buffer].op.axis[2], env.dma_copy)

    s[superop.conv_out].compute_at(s[superop.lshift_out], s[superop.lshift_out].op.axis[1])
    s[superop.lshift_buffer].compute_at(s[superop.lshift_out], s[superop.lshift_out].op.axis[1])
    s[superop.lshift_out].compute_at(s[superop.lshift_out_buffer], s[superop.lshift_out_buffer].op.axis[1])


    s[superop.lshift_out].pragma(s[superop.lshift_out].op.axis[2], env.alu)
    
    ################### add_tensor1 #######################
    s[superop.add_tensor1_buffer].set_scope(env.mid_scopeA)
    s[superop.add_tensor1_out].set_scope(env.output_scopeA)
    s[superop.add_tensor1_out_buffer].set_scope(env.mid_scopeB)


    s[superop.add_tensor1_buffer].pragma(s[superop.add_tensor1_buffer].op.axis[2], env.dma_copy)
    s[superop.add_tensor1_out_buffer].pragma(s[superop.add_tensor1_out_buffer].op.axis[2], env.dma_copy)

    s[superop.lshift_out_buffer].compute_at(s[superop.add_tensor1_out], s[superop.add_tensor1_out].op.axis[1])
    s[superop.add_tensor1_buffer].compute_at(s[superop.add_tensor1_out], s[superop.add_tensor1_out].op.axis[1])
    s[superop.add_tensor1_out].compute_at(s[superop.add_tensor1_out_buffer], s[superop.add_tensor1_out_buffer].op.axis[1])


    s[superop.add_tensor1_out].pragma(s[superop.add_tensor1_out].op.axis[2], env.alu)

    ################### add_tensor2 #######################
    s[superop.add_tensor2_buffer].set_scope(env.mid_scopeA)
    s[superop.add_tensor2_out].set_scope(env.output_scopeA)
    s[superop.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[superop.add_tensor2_buffer].pragma(s[superop.add_tensor2_buffer].op.axis[2], env.dma_copy)
    s[superop.add_tensor2_out_buffer].pragma(s[superop.add_tensor2_out_buffer].op.axis[2], env.dma_copy)

    s[superop.add_tensor1_out_buffer].compute_at(s[superop.add_tensor2_out], s[superop.add_tensor2_out].op.axis[1])
    s[superop.add_tensor2_buffer].compute_at(s[superop.add_tensor2_out], s[superop.add_tensor2_out].op.axis[1])
    s[superop.add_tensor2_out].compute_at(s[superop.add_tensor2_out_buffer], s[superop.add_tensor2_out_buffer].op.axis[1])

    s[superop.add_tensor2_out].pragma(s[superop.add_tensor2_out].op.axis[2], env.alu)

    ################### relu #######################
    s[superop.zero_buffer].set_scope(env.mid_scopeA)
    s[superop.relu_out].set_scope(env.output_scopeA)
    s[superop.relu_out_buffer].set_scope(env.mid_scopeB)


    s[superop.zero_buffer].pragma(s[superop.zero_buffer].op.axis[2], env.dma_copy)
    s[superop.relu_out_buffer].pragma(s[superop.relu_out_buffer].op.axis[2], env.dma_copy)

    s[superop.add_tensor2_out_buffer].compute_at(s[superop.relu_out_buffer], s[superop.relu_out_buffer].op.axis[1])
    s[superop.zero_buffer].compute_at(s[superop.relu_out_buffer], s[superop.relu_out_buffer].op.axis[1])
    s[superop.relu_out].compute_at(s[superop.relu_out_buffer], s[superop.relu_out_buffer].op.axis[1])

    s[superop.relu_out].pragma(s[superop.relu_out].op.axis[2], env.alu)

    ################### add_num #######################
    s[superop.add_num_buffer].set_scope(env.mid_scopeA)
    s[superop.add_num_out].set_scope(env.output_scopeA)
    s[superop.add_num_out_buffer].set_scope(env.mid_scopeB)

    s[superop.add_num_buffer].pragma(s[superop.add_num_buffer].op.axis[2], env.dma_copy)
    s[superop.add_num_out_buffer].pragma(s[superop.add_num_out_buffer].op.axis[2], env.dma_copy)

    s[superop.relu_out_buffer].compute_at(s[superop.add_num_out_buffer], s[superop.add_num_out_buffer].op.axis[1])
    s[superop.add_num_buffer].compute_at(s[superop.add_num_out_buffer], s[superop.add_num_out_buffer].op.axis[1])
    s[superop.add_num_out].compute_at(s[superop.add_num_out_buffer], s[superop.add_num_out_buffer].op.axis[1])

    s[superop.add_num_out].pragma(s[superop.add_num_out].op.axis[2], env.alu)

    ################### rshift #######################
    s[superop.rshift_buffer].set_scope(env.mid_scopeA)
    s[superop.rshift_out].set_scope(env.output_scopeA)
    s[superop.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[superop.rshift_buffer].pragma(s[superop.rshift_buffer].op.axis[2], env.dma_copy)
    s[superop.rshift_out_buffer].pragma(s[superop.rshift_out_buffer].op.axis[2], env.dma_copy)

    s[superop.add_num_out_buffer].compute_at(s[superop.rshift_out_buffer], s[superop.rshift_out_buffer].op.axis[1])
    s[superop.rshift_buffer].compute_at(s[superop.rshift_out_buffer], s[superop.rshift_out_buffer].op.axis[1])
    s[superop.rshift_out].compute_at(s[superop.rshift_out_buffer], s[superop.rshift_out_buffer].op.axis[1])

    s[superop.rshift_out].pragma(s[superop.rshift_out].op.axis[2], env.alu)

    ################### clip #######################
    s[superop.max_value_buffer].set_scope(env.mid_scopeA)
    s[superop.min_value_buffer].set_scope(env.mid_scopeA)
    s[superop.clip_max_out].set_scope(env.output_scopeA)
    s[superop.clip_min_out].set_scope(env.output_scopeA)
    s[superop.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[superop.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[superop.max_value_buffer].pragma(s[superop.max_value_buffer].op.axis[2], env.dma_copy)
    s[superop.min_value_buffer].pragma(s[superop.min_value_buffer].op.axis[2], env.dma_copy)
    s[superop.clip_middle_buffer].pragma(s[superop.clip_middle_buffer].op.axis[2], env.dma_copy)
    s[superop.out_buffer].pragma(s[superop.out_buffer].op.axis[2], env.dma_copy)

    s[superop.rshift_out_buffer].compute_at(s[superop.out_buffer], s[superop.out_buffer].op.axis[1])
    s[superop.max_value_buffer].compute_at(s[superop.out_buffer], s[superop.out_buffer].op.axis[1])
    s[superop.min_value_buffer].compute_at(s[superop.out_buffer], s[superop.out_buffer].op.axis[1])
    s[superop.clip_max_out].compute_at(s[superop.out_buffer], s[superop.out_buffer].op.axis[1])
    s[superop.clip_min_out].compute_at(s[superop.out_buffer], s[superop.out_buffer].op.axis[1])
    s[superop.clip_middle_buffer].compute_at(s[superop.out_buffer], s[superop.out_buffer].op.axis[1])


    s[superop.clip_max_out].pragma(s[superop.clip_max_out].op.axis[2], env.alu)
    s[superop.clip_min_out].pragma(s[superop.clip_min_out].op.axis[2], env.alu)

    return s


def fuse_op2_schedule(s, fuse_op2):
    s[fuse_op2.feature_input].set_scope(env.input_scopeA)
    s[fuse_op2.weight_input].set_scope(env.input_scopeB)
    s[fuse_op2.feature].set_scope(env.inp_scope)
    s[fuse_op2.weight].set_scope(env.wgt_scope)
    s[fuse_op2.middle_buffer].set_scope(env.mid_scopeA)
    # s[fuse_op2.middle].set_scope(env.output_scopeA)
    # s[fuse_op2.middle_tran].set_scope(env.mid_scopeA)
    # s[fuse_op2.middle_reshape].set_scope(env.output_scopeA)
    # s[fuse_op2.middle_unpad].set_scope(env.mid_scopeA)
    s[fuse_op2.conv_out].set_scope(env.mid_scopeB)

    s[fuse_op2.feature_input].pragma(s[fuse_op2.feature_input].op.axis[2], env.dma_copy)
    s[fuse_op2.weight_input].pragma(s[fuse_op2.weight_input].op.axis[2], env.dma_copy)
    s[fuse_op2.feature].pragma(s[fuse_op2.feature].op.axis[2], env.dma_copy)
    s[fuse_op2.weight].pragma(s[fuse_op2.weight].op.axis[2], env.dma_copy)
    # s[fuse_op2.middle].pragma(s[fuse_op2.middle].op.axis[2], env.dma_copy)
    # s[fuse_op2.middle_tran].pragma(s[fuse_op2.middle_tran].op.axis[2], env.dma_copy)
    # s[fuse_op2.middle_reshape].pragma(s[fuse_op2.middle_reshape].op.axis[1], env.dma_copy)
    # s[fuse_op2.middle_unpad].pragma(s[fuse_op2.middle_unpad].op.axis[1], env.dma_copy)
    s[fuse_op2.conv_out].pragma(s[fuse_op2.conv_out].op.axis[2], env.dma_copy)

    i, x, j, y = s[fuse_op2.middle_buffer].op.axis
    s[fuse_op2.middle_buffer].reorder(i, x, fuse_op2.k0, fuse_op2.k1, j, y, fuse_op2.k2)

    s[fuse_op2.feature_input].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.weight_input].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.feature].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.weight].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.middle_buffer].compute_at(s[fuse_op2.conv_out], s[fuse_op2.conv_out].op.axis[1])
    # s[fuse_op2.middle].compute_at(s[fuse_op2.middle_tran], s[fuse_op2.middle_tran].op.axis[0])
    # s[fuse_op2.middle_tran].compute_at(s[fuse_op2.middle_reshape], s[fuse_op2.middle_reshape].op.axis[0])

    s[fuse_op2.middle_buffer].tensorize(fuse_op2.k1, env.gemm)

    ################### add_tensor2 #######################
    s[fuse_op2.add_tensor2_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.add_tensor2_out].set_scope(env.output_scopeA)
    s[fuse_op2.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op2.conv_out].pragma(s[fuse_op2.conv_out].op.axis[2], env.dma_copy)
    s[fuse_op2.add_tensor2_buffer].pragma(s[fuse_op2.add_tensor2_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.add_tensor2_out_buffer].pragma(s[fuse_op2.add_tensor2_out_buffer].op.axis[2], env.dma_copy)


    s[fuse_op2.conv_out].compute_at(s[fuse_op2.add_tensor2_out], s[fuse_op2.add_tensor2_out].op.axis[1])
    s[fuse_op2.add_tensor2_buffer].compute_at(s[fuse_op2.add_tensor2_out], s[fuse_op2.add_tensor2_out].op.axis[1])
    s[fuse_op2.add_tensor2_out].compute_at(s[fuse_op2.add_tensor2_out_buffer],s[fuse_op2.add_tensor2_out_buffer].op.axis[1])

    s[fuse_op2.add_tensor2_out].pragma(s[fuse_op2.add_tensor2_out].op.axis[2], env.alu)

    ################### relu #######################
    s[fuse_op2.zero_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.relu_out].set_scope(env.output_scopeA)
    s[fuse_op2.relu_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.zero_buffer].pragma(s[fuse_op2.zero_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.relu_out_buffer].pragma(s[fuse_op2.relu_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.add_tensor2_out_buffer].compute_at(s[fuse_op2.relu_out_buffer], s[fuse_op2.relu_out_buffer].op.axis[1])
    s[fuse_op2.zero_buffer].compute_at(s[fuse_op2.relu_out_buffer], s[fuse_op2.relu_out_buffer].op.axis[1])
    s[fuse_op2.relu_out].compute_at(s[fuse_op2.relu_out_buffer], s[fuse_op2.relu_out_buffer].op.axis[1])

    s[fuse_op2.relu_out].pragma(s[fuse_op2.relu_out].op.axis[2], env.alu)

    ################### add_num #######################
    s[fuse_op2.add_num_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.add_num_out].set_scope(env.output_scopeA)
    s[fuse_op2.add_num_out_buffer].set_scope(env.mid_scopeA)

    s[fuse_op2.add_num_buffer].pragma(s[fuse_op2.add_num_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.add_num_out_buffer].pragma(s[fuse_op2.add_num_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.relu_out_buffer].compute_at(s[fuse_op2.add_num_out_buffer], s[fuse_op2.add_num_out_buffer].op.axis[1])
    s[fuse_op2.add_num_buffer].compute_at(s[fuse_op2.add_num_out_buffer], s[fuse_op2.add_num_out_buffer].op.axis[1])
    s[fuse_op2.add_num_out].compute_at(s[fuse_op2.add_num_out_buffer], s[fuse_op2.add_num_out_buffer].op.axis[1])

    s[fuse_op2.add_num_out].pragma(s[fuse_op2.add_num_out].op.axis[2], env.alu)

    ################### rshift #######################
    s[fuse_op2.rshift_buffer].set_scope(env.mid_scopeB)
    s[fuse_op2.rshift_out].set_scope(env.output_scopeA)
    s[fuse_op2.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.rshift_buffer].pragma(s[fuse_op2.rshift_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.rshift_out_buffer].pragma(s[fuse_op2.rshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.add_num_out_buffer].compute_at(s[fuse_op2.rshift_out_buffer], s[fuse_op2.rshift_out_buffer].op.axis[1])
    s[fuse_op2.rshift_buffer].compute_at(s[fuse_op2.rshift_out_buffer], s[fuse_op2.rshift_out_buffer].op.axis[1])
    s[fuse_op2.rshift_out].compute_at(s[fuse_op2.rshift_out_buffer], s[fuse_op2.rshift_out_buffer].op.axis[1])

    s[fuse_op2.rshift_out].pragma(s[fuse_op2.rshift_out].op.axis[2], env.alu)

    ################### clip #######################
    s[fuse_op2.max_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.min_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.clip_max_out].set_scope(env.output_scopeA)
    s[fuse_op2.clip_min_out].set_scope(env.output_scopeA)
    s[fuse_op2.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op2.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.max_value_buffer].pragma(s[fuse_op2.max_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.min_value_buffer].pragma(s[fuse_op2.min_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.clip_middle_buffer].pragma(s[fuse_op2.clip_middle_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.out_buffer].pragma(s[fuse_op2.out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.rshift_out_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.max_value_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.min_value_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.clip_max_out].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.clip_min_out].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.clip_middle_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])

    s[fuse_op2.clip_max_out].pragma(s[fuse_op2.clip_max_out].op.axis[2], env.alu)
    s[fuse_op2.clip_min_out].pragma(s[fuse_op2.clip_min_out].op.axis[2], env.alu)

    return s


def fuse_op2_schedule_new(s, fuse_op2):
    s[fuse_op2.feature_input].set_scope(env.input_scopeA)
    s[fuse_op2.weight_input].set_scope(env.input_scopeB)
    s[fuse_op2.feature].set_scope(env.inp_scope)
    s[fuse_op2.weight].set_scope(env.wgt_scope)
    s[fuse_op2.middle_buffer].set_scope(env.mid_scopeA)
    # s[fuse_op2.middle].set_scope(env.output_scopeA)
    # s[fuse_op2.middle_tran].set_scope(env.mid_scopeA)
    # s[fuse_op2.middle_reshape].set_scope(env.output_scopeA)
    # s[fuse_op2.middle_unpad].set_scope(env.mid_scopeA)
    s[fuse_op2.conv_out].set_scope(env.mid_scopeB)

    s[fuse_op2.feature_input].pragma(s[fuse_op2.feature_input].op.axis[2], env.dma_copy)
    s[fuse_op2.weight_input].pragma(s[fuse_op2.weight_input].op.axis[2], env.dma_copy)
    s[fuse_op2.feature].pragma(s[fuse_op2.feature].op.axis[2], env.dma_copy)
    s[fuse_op2.weight].pragma(s[fuse_op2.weight].op.axis[2], env.dma_copy)
    # s[fuse_op2.middle].pragma(s[fuse_op2.middle].op.axis[2], env.dma_copy)
    # s[fuse_op2.middle_tran].pragma(s[fuse_op2.middle_tran].op.axis[2], env.dma_copy)
    # s[fuse_op2.middle_reshape].pragma(s[fuse_op2.middle_reshape].op.axis[1], env.dma_copy)
    # s[fuse_op2.middle_unpad].pragma(s[fuse_op2.middle_unpad].op.axis[1], env.dma_copy)
    s[fuse_op2.conv_out].pragma(s[fuse_op2.conv_out].op.axis[2], env.dma_copy)

    i, x, j, y = s[fuse_op2.middle_buffer].op.axis
    s[fuse_op2.middle_buffer].reorder(i, x, fuse_op2.k0, fuse_op2.k1, j, y, fuse_op2.k2)

    s[fuse_op2.feature_input].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.weight_input].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.feature].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.weight].compute_at(s[fuse_op2.middle_buffer], fuse_op2.k0)
    s[fuse_op2.middle_buffer].compute_at(s[fuse_op2.conv_out], s[fuse_op2.conv_out].op.axis[1])
    # s[fuse_op2.middle].compute_at(s[fuse_op2.middle_tran], s[fuse_op2.middle_tran].op.axis[0])
    # s[fuse_op2.middle_tran].compute_at(s[fuse_op2.middle_reshape], s[fuse_op2.middle_reshape].op.axis[0])

    s[fuse_op2.middle_buffer].tensorize(fuse_op2.k1, env.gemm)

    ################### add_tensor2 #######################
    s[fuse_op2.add_tensor2_buffer].set_scope(env.input_scopeA)
    s[fuse_op2.add_tensor2_4d].set_scope(env.mid_scopeA)
    s[fuse_op2.add_tensor2_out].set_scope(env.output_scopeA)
    s[fuse_op2.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op2.conv_out].pragma(s[fuse_op2.conv_out].op.axis[2], env.dma_copy)
    s[fuse_op2.add_tensor2_buffer].pragma(s[fuse_op2.add_tensor2_buffer].op.axis[0], env.dma_copy)
    s[fuse_op2.add_tensor2_4d].pragma(s[fuse_op2.add_tensor2_4d].op.axis[3], env.dma_copy)
    s[fuse_op2.add_tensor2_out_buffer].pragma(s[fuse_op2.add_tensor2_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.conv_out].compute_at(s[fuse_op2.add_tensor2_out], s[fuse_op2.add_tensor2_out].op.axis[1])
    # s[fuse_op2.add_tensor2_buffer].compute_at(s[fuse_op2.add_tensor2_out], s[fuse_op2.add_tensor2_out].op.axis[1])
    s[fuse_op2.add_tensor2_4d].compute_at(s[fuse_op2.add_tensor2_out], s[fuse_op2.add_tensor2_out].op.axis[1])
    s[fuse_op2.add_tensor2_out].compute_at(s[fuse_op2.add_tensor2_out_buffer], s[fuse_op2.add_tensor2_out_buffer].op.axis[1])

    s[fuse_op2.add_tensor2_out].pragma(s[fuse_op2.add_tensor2_out].op.axis[2], env.alu)

    ################### relu #######################
    s[fuse_op2.zero_buffer].set_scope(env.input_scopeA)
    s[fuse_op2.zero_4d].set_scope(env.mid_scopeA)
    s[fuse_op2.relu_out].set_scope(env.output_scopeA)
    s[fuse_op2.relu_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.zero_buffer].pragma(s[fuse_op2.zero_buffer].op.axis[0], env.dma_copy)
    s[fuse_op2.zero_4d].pragma(s[fuse_op2.zero_4d].op.axis[3], env.dma_copy)
    s[fuse_op2.relu_out_buffer].pragma(s[fuse_op2.relu_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.add_tensor2_out_buffer].compute_at(s[fuse_op2.relu_out_buffer], s[fuse_op2.relu_out_buffer].op.axis[1])
    s[fuse_op2.zero_4d].compute_at(s[fuse_op2.relu_out_buffer], s[fuse_op2.relu_out_buffer].op.axis[1])
    s[fuse_op2.relu_out].compute_at(s[fuse_op2.relu_out_buffer], s[fuse_op2.relu_out_buffer].op.axis[1])

    s[fuse_op2.relu_out].pragma(s[fuse_op2.relu_out].op.axis[2], env.alu)

    ################### add_num #######################
    s[fuse_op2.add_num_buffer].set_scope(env.input_scopeA)
    s[fuse_op2.add_num_4d].set_scope(env.mid_scopeA)
    s[fuse_op2.add_num_out].set_scope(env.output_scopeA)
    s[fuse_op2.add_num_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.add_num_buffer].pragma(s[fuse_op2.add_num_buffer].op.axis[0], env.dma_copy)
    s[fuse_op2.add_num_4d].pragma(s[fuse_op2.add_num_4d].op.axis[3], env.dma_copy)
    s[fuse_op2.add_num_out_buffer].pragma(s[fuse_op2.add_num_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.add_num_buffer].compute_at(s[fuse_op2.add_num_out_buffer], s[fuse_op2.add_num_out_buffer].op.axis[1])
    s[fuse_op2.relu_out_buffer].compute_at(s[fuse_op2.add_num_out_buffer],
                                                  s[fuse_op2.add_num_out_buffer].op.axis[1])
    s[fuse_op2.add_num_4d].compute_at(s[fuse_op2.add_num_out_buffer], s[fuse_op2.add_num_out_buffer].op.axis[1])
    s[fuse_op2.add_num_out].compute_at(s[fuse_op2.add_num_out_buffer], s[fuse_op2.add_num_out_buffer].op.axis[1])

    s[fuse_op2.add_num_out].pragma(s[fuse_op2.add_num_out].op.axis[2], env.alu)

    ################### rshift #######################
    s[fuse_op2.rshift_buffer].set_scope(env.input_scopeA)
    s[fuse_op2.rshift_4d].set_scope(env.mid_scopeA)
    s[fuse_op2.rshift_out].set_scope(env.output_scopeA)
    s[fuse_op2.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.rshift_buffer].pragma(s[fuse_op2.rshift_buffer].op.axis[0], env.dma_copy)
    s[fuse_op2.rshift_4d].pragma(s[fuse_op2.rshift_4d].op.axis[3], env.dma_copy)
    s[fuse_op2.rshift_out_buffer].pragma(s[fuse_op2.rshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.add_num_out_buffer].compute_at(s[fuse_op2.rshift_out_buffer], s[fuse_op2.rshift_out_buffer].op.axis[1])
    s[fuse_op2.rshift_4d].compute_at(s[fuse_op2.rshift_out_buffer], s[fuse_op2.rshift_out_buffer].op.axis[1])
    s[fuse_op2.rshift_out].compute_at(s[fuse_op2.rshift_out_buffer], s[fuse_op2.rshift_out_buffer].op.axis[1])

    s[fuse_op2.rshift_out].pragma(s[fuse_op2.rshift_out].op.axis[2], env.alu)

    ################### clip #######################
    s[fuse_op2.max_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.min_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op2.clip_max_out].set_scope(env.output_scopeA)
    s[fuse_op2.clip_min_out].set_scope(env.output_scopeA)
    s[fuse_op2.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op2.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op2.max_value_buffer].pragma(s[fuse_op2.max_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.min_value_buffer].pragma(s[fuse_op2.min_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.clip_middle_buffer].pragma(s[fuse_op2.clip_middle_buffer].op.axis[2], env.dma_copy)
    s[fuse_op2.out_buffer].pragma(s[fuse_op2.out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op2.rshift_out_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.max_value_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.min_value_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.clip_max_out].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.clip_min_out].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])
    s[fuse_op2.clip_middle_buffer].compute_at(s[fuse_op2.out_buffer], s[fuse_op2.out_buffer].op.axis[1])

    s[fuse_op2.clip_max_out].pragma(s[fuse_op2.clip_max_out].op.axis[2], env.alu)
    s[fuse_op2.clip_min_out].pragma(s[fuse_op2.clip_min_out].op.axis[2], env.alu)

    return s


def fuse_op3_schedule(s, fuse_op3):
    s[fuse_op3.feature_input].set_scope(env.input_scopeA)
    s[fuse_op3.weight_input].set_scope(env.input_scopeB)
    s[fuse_op3.feature].set_scope(env.inp_scope)
    s[fuse_op3.weight].set_scope(env.wgt_scope)
    s[fuse_op3.middle_buffer].set_scope(env.mid_scopeA)
    # s[fuse_op3.middle].set_scope(env.output_scopeA)
    # s[fuse_op3.middle_tran].set_scope(env.mid_scopeA)
    # s[fuse_op3.middle_reshape].set_scope(env.output_scopeA)
    # s[fuse_op3.middle_unpad].set_scope(env.mid_scopeA)
    s[fuse_op3.conv_out].set_scope(env.mid_scopeB)

    s[fuse_op3.feature_input].pragma(s[fuse_op3.feature_input].op.axis[2], env.dma_copy)
    s[fuse_op3.weight_input].pragma(s[fuse_op3.weight_input].op.axis[2], env.dma_copy)
    s[fuse_op3.feature].pragma(s[fuse_op3.feature].op.axis[2], env.dma_copy)
    s[fuse_op3.weight].pragma(s[fuse_op3.weight].op.axis[2], env.dma_copy)
    # s[fuse_op3.middle].pragma(s[fuse_op3.middle].op.axis[2], env.dma_copy)
    # s[fuse_op3.middle_tran].pragma(s[fuse_op3.middle_tran].op.axis[2], env.dma_copy)
    # s[fuse_op3.middle_reshape].pragma(s[fuse_op3.middle_reshape].op.axis[1], env.dma_copy)
    # s[fuse_op3.middle_unpad].pragma(s[fuse_op3.middle_unpad].op.axis[1], env.dma_copy)
    s[fuse_op3.conv_out].pragma(s[fuse_op3.conv_out].op.axis[2], env.dma_copy)

    i, x, j, y = s[fuse_op3.middle_buffer].op.axis
    s[fuse_op3.middle_buffer].reorder(i, x, fuse_op3.k0, fuse_op3.k1, j, y, fuse_op3.k2)

    s[fuse_op3.feature_input].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.weight_input].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.feature].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.weight].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.middle_buffer].compute_at(s[fuse_op3.conv_out], s[fuse_op3.conv_out].op.axis[1])
    # s[fuse_op3.middle].compute_at(s[fuse_op3.middle_tran], s[fuse_op3.middle_tran].op.axis[0])
    # s[fuse_op3.middle_tran].compute_at(s[fuse_op3.middle_reshape], s[fuse_op3.middle_reshape].op.axis[0])

    s[fuse_op3.middle_buffer].tensorize(fuse_op3.k1, env.gemm)

    ################### left shift #######################
    s[fuse_op3.lshift_buffer].set_scope(env.mid_scopeA)

    s[fuse_op3.lshift_out].set_scope(env.output_scopeA)
    s[fuse_op3.lshift_out_buffer].set_scope(env.mid_scopeB)
    # s[fuse_op3.middle_reshape].set_scope(env.input_scopeA)
    # s[fuse_op3.conv_out].set_scope(env.mid_scopeA)

    s[fuse_op3.lshift_buffer].pragma(s[fuse_op3.lshift_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.lshift_out_buffer].pragma(s[fuse_op3.lshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.conv_out].compute_at(s[fuse_op3.lshift_out], s[fuse_op3.lshift_out].op.axis[1])
    s[fuse_op3.lshift_buffer].compute_at(s[fuse_op3.lshift_out], s[fuse_op3.lshift_out].op.axis[1])
    s[fuse_op3.lshift_out].compute_at(s[fuse_op3.lshift_out_buffer], s[fuse_op3.lshift_out_buffer].op.axis[1])

    s[fuse_op3.lshift_out].pragma(s[fuse_op3.lshift_out].op.axis[2], env.alu)

    ################### add_tensor1 #######################
    s[fuse_op3.add_tensor1_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.add_tensor1_out].set_scope(env.output_scopeA)
    s[fuse_op3.add_tensor1_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.add_tensor1_buffer].pragma(s[fuse_op3.add_tensor1_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.add_tensor1_out_buffer].pragma(s[fuse_op3.add_tensor1_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.lshift_out_buffer].compute_at(s[fuse_op3.add_tensor1_out], s[fuse_op3.add_tensor1_out].op.axis[1])
    s[fuse_op3.add_tensor1_buffer].compute_at(s[fuse_op3.add_tensor1_out], s[fuse_op3.add_tensor1_out].op.axis[1])
    s[fuse_op3.add_tensor1_out].compute_at(s[fuse_op3.add_tensor1_out_buffer],s[fuse_op3.add_tensor1_out_buffer].op.axis[1])

    s[fuse_op3.add_tensor1_out].pragma(s[fuse_op3.add_tensor1_out].op.axis[2], env.alu)


    ################### add_num #######################
    s[fuse_op3.add_num_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.add_num_out].set_scope(env.output_scopeA)
    s[fuse_op3.add_num_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.add_num_buffer].pragma(s[fuse_op3.add_num_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.add_num_out_buffer].pragma(s[fuse_op3.add_num_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.add_tensor1_out_buffer].compute_at(s[fuse_op3.add_num_out_buffer], s[fuse_op3.add_num_out_buffer].op.axis[1])
    s[fuse_op3.add_num_buffer].compute_at(s[fuse_op3.add_num_out_buffer], s[fuse_op3.add_num_out_buffer].op.axis[1])
    s[fuse_op3.add_num_out].compute_at(s[fuse_op3.add_num_out_buffer], s[fuse_op3.add_num_out_buffer].op.axis[1])

    s[fuse_op3.add_num_out].pragma(s[fuse_op3.add_num_out].op.axis[2], env.alu)

    ################### rshift #######################
    s[fuse_op3.rshift_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.rshift_out].set_scope(env.output_scopeA)
    s[fuse_op3.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.rshift_buffer].pragma(s[fuse_op3.rshift_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.rshift_out_buffer].pragma(s[fuse_op3.rshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.add_num_out_buffer].compute_at(s[fuse_op3.rshift_out_buffer], s[fuse_op3.rshift_out_buffer].op.axis[1])
    s[fuse_op3.rshift_buffer].compute_at(s[fuse_op3.rshift_out_buffer], s[fuse_op3.rshift_out_buffer].op.axis[1])
    s[fuse_op3.rshift_out].compute_at(s[fuse_op3.rshift_out_buffer], s[fuse_op3.rshift_out_buffer].op.axis[1])

    s[fuse_op3.rshift_out].pragma(s[fuse_op3.rshift_out].op.axis[2], env.alu)

    ################### clip #######################
    s[fuse_op3.max_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.min_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.clip_max_out].set_scope(env.output_scopeA)
    s[fuse_op3.clip_min_out].set_scope(env.output_scopeA)
    s[fuse_op3.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op3.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.max_value_buffer].pragma(s[fuse_op3.max_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.min_value_buffer].pragma(s[fuse_op3.min_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.clip_middle_buffer].pragma(s[fuse_op3.clip_middle_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.out_buffer].pragma(s[fuse_op3.out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.rshift_out_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.max_value_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.min_value_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.clip_max_out].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.clip_min_out].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.clip_middle_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])

    s[fuse_op3.clip_max_out].pragma(s[fuse_op3.clip_max_out].op.axis[2], env.alu)
    s[fuse_op3.clip_min_out].pragma(s[fuse_op3.clip_min_out].op.axis[2], env.alu)

    return s

def fuse_op3_schedule_new(s, fuse_op3):
    s[fuse_op3.feature_input].set_scope(env.input_scopeA)
    s[fuse_op3.weight_input].set_scope(env.input_scopeB)
    s[fuse_op3.feature].set_scope(env.inp_scope)
    s[fuse_op3.weight].set_scope(env.wgt_scope)
    s[fuse_op3.middle_buffer].set_scope(env.mid_scopeA)
    # s[fuse_op3.middle].set_scope(env.output_scopeA)
    # s[fuse_op3.middle_tran].set_scope(env.mid_scopeA)
    # s[fuse_op3.middle_reshape].set_scope(env.output_scopeA)
    # s[fuse_op3.middle_unpad].set_scope(env.mid_scopeA)
    s[fuse_op3.conv_out].set_scope(env.mid_scopeB)

    s[fuse_op3.feature_input].pragma(s[fuse_op3.feature_input].op.axis[2], env.dma_copy)
    s[fuse_op3.weight_input].pragma(s[fuse_op3.weight_input].op.axis[2], env.dma_copy)
    s[fuse_op3.feature].pragma(s[fuse_op3.feature].op.axis[2], env.dma_copy)
    s[fuse_op3.weight].pragma(s[fuse_op3.weight].op.axis[2], env.dma_copy)
    # s[fuse_op3.middle].pragma(s[fuse_op3.middle].op.axis[2], env.dma_copy)
    # s[fuse_op3.middle_tran].pragma(s[fuse_op3.middle_tran].op.axis[2], env.dma_copy)
    # s[fuse_op3.middle_reshape].pragma(s[fuse_op3.middle_reshape].op.axis[1], env.dma_copy)
    # s[fuse_op3.middle_unpad].pragma(s[fuse_op3.middle_unpad].op.axis[1], env.dma_copy)
    s[fuse_op3.conv_out].pragma(s[fuse_op3.conv_out].op.axis[2], env.dma_copy)

    i, x, j, y = s[fuse_op3.middle_buffer].op.axis
    s[fuse_op3.middle_buffer].reorder(i, x, fuse_op3.k0, fuse_op3.k1, j, y, fuse_op3.k2)

    s[fuse_op3.feature_input].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.weight_input].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.feature].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.weight].compute_at(s[fuse_op3.middle_buffer], fuse_op3.k0)
    s[fuse_op3.middle_buffer].compute_at(s[fuse_op3.conv_out], s[fuse_op3.conv_out].op.axis[1])
    # s[fuse_op3.middle].compute_at(s[fuse_op3.middle_tran], s[fuse_op3.middle_tran].op.axis[0])
    # s[fuse_op3.middle_tran].compute_at(s[fuse_op3.middle_reshape], s[fuse_op3.middle_reshape].op.axis[0])

    s[fuse_op3.middle_buffer].tensorize(fuse_op3.k1, env.gemm)

    ################### left shift #######################
    s[fuse_op3.lshift_buffer].set_scope(env.input_scopeA)
    s[fuse_op3.lshift_4d].set_scope(env.mid_scopeA)
    s[fuse_op3.lshift_out].set_scope(env.output_scopeA)
    s[fuse_op3.lshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.lshift_buffer].pragma(s[fuse_op3.lshift_buffer].op.axis[0], env.dma_copy)
    s[fuse_op3.lshift_4d].pragma(s[fuse_op3.lshift_4d].op.axis[3], env.dma_copy)
    s[fuse_op3.lshift_out_buffer].pragma(s[fuse_op3.lshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.conv_out].compute_at(s[fuse_op3.lshift_out_buffer], s[fuse_op3.lshift_out_buffer].op.axis[1])
    s[fuse_op3.lshift_4d].compute_at(s[fuse_op3.lshift_out_buffer], s[fuse_op3.lshift_out_buffer].op.axis[1])
    s[fuse_op3.lshift_out].compute_at(s[fuse_op3.lshift_out_buffer], s[fuse_op3.lshift_out_buffer].op.axis[1])

    s[fuse_op3.lshift_out].pragma(s[fuse_op3.lshift_out].op.axis[2], env.alu)

    ################### add_tensor1 #######################
    s[fuse_op3.add_tensor1_buffer].set_scope(env.input_scopeA)
    s[fuse_op3.add_tensor1_4d].set_scope(env.mid_scopeA)
    s[fuse_op3.add_tensor1_out].set_scope(env.output_scopeA)
    s[fuse_op3.add_tensor1_out_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op3.conv_out].pragma(s[fuse_op3.conv_out].op.axis[2], env.dma_copy)
    s[fuse_op3.add_tensor1_buffer].pragma(s[fuse_op3.add_tensor1_buffer].op.axis[0], env.dma_copy)
    s[fuse_op3.add_tensor1_4d].pragma(s[fuse_op3.add_tensor1_4d].op.axis[3], env.dma_copy)
    s[fuse_op3.add_tensor1_out_buffer].pragma(s[fuse_op3.add_tensor1_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.lshift_out_buffer].compute_at(s[fuse_op3.add_tensor1_out], s[fuse_op3.add_tensor1_out].op.axis[1])
    # s[fuse_op3.add_tensor1_buffer].compute_at(s[fuse_op3.add_tensor1_out], s[fuse_op3.add_tensor1_out].op.axis[1])
    s[fuse_op3.add_tensor1_4d].compute_at(s[fuse_op3.add_tensor1_out], s[fuse_op3.add_tensor1_out].op.axis[1])
    s[fuse_op3.add_tensor1_out].compute_at(s[fuse_op3.add_tensor1_out_buffer],
                                           s[fuse_op3.add_tensor1_out_buffer].op.axis[1])

    s[fuse_op3.add_tensor1_out].pragma(s[fuse_op3.add_tensor1_out].op.axis[2], env.alu)


    ################### add_num #######################
    s[fuse_op3.add_num_buffer].set_scope(env.input_scopeA)
    s[fuse_op3.add_num_4d].set_scope(env.mid_scopeA)
    s[fuse_op3.add_num_out].set_scope(env.output_scopeA)
    s[fuse_op3.add_num_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.add_num_buffer].pragma(s[fuse_op3.add_num_buffer].op.axis[0], env.dma_copy)
    s[fuse_op3.add_num_4d].pragma(s[fuse_op3.add_num_4d].op.axis[3], env.dma_copy)
    s[fuse_op3.add_num_out_buffer].pragma(s[fuse_op3.add_num_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.add_num_buffer].compute_at(s[fuse_op3.add_num_out_buffer], s[fuse_op3.add_num_out_buffer].op.axis[1])
    s[fuse_op3.add_tensor1_out_buffer].compute_at(s[fuse_op3.add_num_out_buffer],
                                           s[fuse_op3.add_num_out_buffer].op.axis[1])
    s[fuse_op3.add_num_4d].compute_at(s[fuse_op3.add_num_out_buffer], s[fuse_op3.add_num_out_buffer].op.axis[1])
    s[fuse_op3.add_num_out].compute_at(s[fuse_op3.add_num_out_buffer], s[fuse_op3.add_num_out_buffer].op.axis[1])

    s[fuse_op3.add_num_out].pragma(s[fuse_op3.add_num_out].op.axis[2], env.alu)

    ################### rshift #######################
    s[fuse_op3.rshift_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.rshift_out].set_scope(env.output_scopeA)
    s[fuse_op3.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.rshift_buffer].pragma(s[fuse_op3.rshift_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.rshift_out_buffer].pragma(s[fuse_op3.rshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.add_num_out_buffer].compute_at(s[fuse_op3.rshift_out_buffer], s[fuse_op3.rshift_out_buffer].op.axis[1])
    s[fuse_op3.rshift_buffer].compute_at(s[fuse_op3.rshift_out_buffer], s[fuse_op3.rshift_out_buffer].op.axis[1])
    s[fuse_op3.rshift_out].compute_at(s[fuse_op3.rshift_out_buffer], s[fuse_op3.rshift_out_buffer].op.axis[1])

    s[fuse_op3.rshift_out].pragma(s[fuse_op3.rshift_out].op.axis[2], env.alu)

    ################### clip #######################
    s[fuse_op3.max_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.min_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op3.clip_max_out].set_scope(env.output_scopeA)
    s[fuse_op3.clip_min_out].set_scope(env.output_scopeA)
    s[fuse_op3.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op3.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op3.max_value_buffer].pragma(s[fuse_op3.max_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.min_value_buffer].pragma(s[fuse_op3.min_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.clip_middle_buffer].pragma(s[fuse_op3.clip_middle_buffer].op.axis[2], env.dma_copy)
    s[fuse_op3.out_buffer].pragma(s[fuse_op3.out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op3.rshift_out_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.max_value_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.min_value_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.clip_max_out].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.clip_min_out].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])
    s[fuse_op3.clip_middle_buffer].compute_at(s[fuse_op3.out_buffer], s[fuse_op3.out_buffer].op.axis[1])

    s[fuse_op3.clip_max_out].pragma(s[fuse_op3.clip_max_out].op.axis[2], env.alu)
    s[fuse_op3.clip_min_out].pragma(s[fuse_op3.clip_min_out].op.axis[2], env.alu)

    return s
    
def fuse_op4_schedule(s, fuse_op4):
    s[fuse_op4.data_buffer].set_scope(env.mid_scopeB)
    s[fuse_op4.mul_tensor1_buffer].set_scope(env.param_scopeA)
    s[fuse_op4.mul_tensor1_4d].set_scope(env.mid_scopeA)
    s[fuse_op4.mul_tensor1_out].set_scope(env.output_scopeA)
    s[fuse_op4.mul_tensor1_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op4.data_buffer].pragma(s[fuse_op4.data_buffer].op.axis[3], env.dma_copy)
    s[fuse_op4.mul_tensor1_buffer].pragma(s[fuse_op4.mul_tensor1_buffer].op.axis[0], env.dma_copy)
    s[fuse_op4.mul_tensor1_4d].pragma(s[fuse_op4.mul_tensor1_4d].op.axis[3], env.dma_copy)
    s[fuse_op4.mul_tensor1_out_buffer].pragma(s[fuse_op4.mul_tensor1_out_buffer].op.axis[3], env.dma_copy)

    s[fuse_op4.data_buffer].compute_at(s[fuse_op4.mul_tensor1_out], s[fuse_op4.mul_tensor1_out].op.axis[2])

    s[fuse_op4.mul_tensor1_buffer].compute_at(s[fuse_op4.mul_tensor1_out], s[fuse_op4.mul_tensor1_out].op.axis[2])

    s[fuse_op4.mul_tensor1_4d].compute_at(s[fuse_op4.mul_tensor1_out], s[fuse_op4.mul_tensor1_out].op.axis[2])
    s[fuse_op4.mul_tensor1_out].compute_at(s[fuse_op4.mul_tensor1_out_buffer],s[fuse_op4.mul_tensor1_out_buffer].op.axis[2])
    #
    s[fuse_op4.mul_tensor1_out].pragma(s[fuse_op4.mul_tensor1_out].op.axis[3], env.alu)

    ################### add_tensor1 #######################
    s[fuse_op4.add_tensor1_buffer].set_scope(env.param_scopeA)
    s[fuse_op4.add_tensor1_4d].set_scope(env.mid_scopeA)
    s[fuse_op4.add_tensor1_out].set_scope(env.output_scopeA)
    s[fuse_op4.add_tensor1_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op4.add_tensor1_buffer].pragma(s[fuse_op4.add_tensor1_buffer].op.axis[0], env.dma_copy)
    s[fuse_op4.add_tensor1_4d].pragma(s[fuse_op4.add_tensor1_4d].op.axis[3], env.dma_copy)
    s[fuse_op4.add_tensor1_out_buffer].pragma(s[fuse_op4.add_tensor1_out_buffer].op.axis[3], env.dma_copy)

    s[fuse_op4.add_tensor1_buffer].compute_at(s[fuse_op4.add_tensor1_out], s[fuse_op4.add_tensor1_out].op.axis[2])
    s[fuse_op4.mul_tensor1_out_buffer].compute_at(s[fuse_op4.add_tensor1_out], s[fuse_op4.add_tensor1_out].op.axis[2])
    s[fuse_op4.add_tensor1_4d].compute_at(s[fuse_op4.add_tensor1_out], s[fuse_op4.add_tensor1_out].op.axis[2])
    s[fuse_op4.add_tensor1_out].compute_at(s[fuse_op4.add_tensor1_out_buffer],s[fuse_op4.add_tensor1_out_buffer].op.axis[2])

    s[fuse_op4.add_tensor1_out].pragma(s[fuse_op4.add_tensor1_out].op.axis[3], env.alu)


    ################### add_num #######################
    s[fuse_op4.add_num_buffer].set_scope(env.param_scopeA)
    s[fuse_op4.add_num_4d].set_scope(env.mid_scopeA)
    s[fuse_op4.add_num_out].set_scope(env.output_scopeA)
    s[fuse_op4.add_num_out_buffer].set_scope(env.mid_scopeA)

    s[fuse_op4.add_num_buffer].pragma(s[fuse_op4.add_num_buffer].op.axis[0], env.dma_copy)
    s[fuse_op4.add_num_4d].pragma(s[fuse_op4.add_num_4d].op.axis[3], env.dma_copy)
    s[fuse_op4.add_num_out_buffer].pragma(s[fuse_op4.add_num_out_buffer].op.axis[3], env.dma_copy)

    s[fuse_op4.add_num_buffer].compute_at(s[fuse_op4.add_num_out_buffer], s[fuse_op4.add_num_out_buffer].op.axis[2])
    s[fuse_op4.add_tensor1_out_buffer].compute_at(s[fuse_op4.add_num_out_buffer], s[fuse_op4.add_num_out_buffer].op.axis[2])
    s[fuse_op4.add_num_4d].compute_at(s[fuse_op4.add_num_out_buffer], s[fuse_op4.add_num_out_buffer].op.axis[2])
    s[fuse_op4.add_num_out].compute_at(s[fuse_op4.add_num_out_buffer], s[fuse_op4.add_num_out_buffer].op.axis[2])

    s[fuse_op4.add_num_out].pragma(s[fuse_op4.add_num_out].op.axis[3], env.alu)

    ################### rshift #######################
    # s[fuse_op4.rshift_buffer].set_scope(env.mid_scopeA)
    # s[fuse_op4.rshift_out].set_scope(env.output_scopeA)
    # s[fuse_op4.rshift_out_buffer].set_scope(env.mid_scopeB)
    #
    # s[fuse_op4.rshift_buffer].pragma(s[fuse_op4.rshift_buffer].op.axis[3], env.dma_copy)
    # s[fuse_op4.rshift_out_buffer].pragma(s[fuse_op4.rshift_out_buffer].op.axis[3], env.dma_copy)
    #
    # s[fuse_op4.add_num_out_buffer].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])
    # s[fuse_op4.rshift_buffer].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])
    # s[fuse_op4.rshift_out].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])
    #
    # s[fuse_op4.rshift_out].pragma(s[fuse_op4.rshift_out].op.axis[3], env.alu)

    s[fuse_op4.rshift_buffer].set_scope(env.param_scopeB)
    s[fuse_op4.rshift_4d].set_scope(env.mid_scopeB)
    s[fuse_op4.rshift_out].set_scope(env.output_scopeA)
    s[fuse_op4.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op4.rshift_buffer].pragma(s[fuse_op4.rshift_buffer].op.axis[0], env.dma_copy)
    s[fuse_op4.rshift_4d].pragma(s[fuse_op4.rshift_4d].op.axis[3], env.dma_copy)
    s[fuse_op4.rshift_out_buffer].pragma(s[fuse_op4.rshift_out_buffer].op.axis[3], env.dma_copy)
    
    s[fuse_op4.rshift_buffer].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])
    s[fuse_op4.add_num_out_buffer].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])
    s[fuse_op4.rshift_4d].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])
    s[fuse_op4.rshift_out].compute_at(s[fuse_op4.rshift_out_buffer], s[fuse_op4.rshift_out_buffer].op.axis[2])

    s[fuse_op4.rshift_out].pragma(s[fuse_op4.rshift_out].op.axis[3], env.alu)
    ################### clip #######################
    s[fuse_op4.max_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op4.min_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op4.clip_max_out].set_scope(env.output_scopeA)
    s[fuse_op4.clip_min_out].set_scope(env.output_scopeA)
    s[fuse_op4.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op4.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op4.max_value_buffer].pragma(s[fuse_op4.max_value_buffer].op.axis[3], env.dma_copy)
    s[fuse_op4.min_value_buffer].pragma(s[fuse_op4.min_value_buffer].op.axis[3], env.dma_copy)
    s[fuse_op4.clip_middle_buffer].pragma(s[fuse_op4.clip_middle_buffer].op.axis[3], env.dma_copy)
    s[fuse_op4.out].pragma(s[fuse_op4.out].op.axis[3], env.dma_copy)

    s[fuse_op4.rshift_out_buffer].compute_at(s[fuse_op4.out], s[fuse_op4.out].op.axis[2])
    s[fuse_op4.max_value_buffer].compute_at(s[fuse_op4.out], s[fuse_op4.out].op.axis[2])
    s[fuse_op4.min_value_buffer].compute_at(s[fuse_op4.out], s[fuse_op4.out].op.axis[2])
    s[fuse_op4.clip_max_out].compute_at(s[fuse_op4.out], s[fuse_op4.out].op.axis[2])
    s[fuse_op4.clip_min_out].compute_at(s[fuse_op4.out], s[fuse_op4.out].op.axis[2])
    s[fuse_op4.clip_middle_buffer].compute_at(s[fuse_op4.out], s[fuse_op4.out].op.axis[2])

    s[fuse_op4.clip_max_out].pragma(s[fuse_op4.clip_max_out].op.axis[3], env.alu)
    s[fuse_op4.clip_min_out].pragma(s[fuse_op4.clip_min_out].op.axis[3], env.alu)

    return s


def fuse_op5_schedule(s, fuse_op5):
    s[fuse_op5.feature_input].set_scope(env.input_scopeA)
    s[fuse_op5.weight_input].set_scope(env.input_scopeB)
    s[fuse_op5.feature].set_scope(env.inp_scope)
    s[fuse_op5.weight].set_scope(env.wgt_scope)
    s[fuse_op5.middle_buffer].set_scope(env.mid_scopeA)
    # s[fuse_op5.middle].set_scope(env.output_scopeA)
    # s[fuse_op5.middle_tran].set_scope(env.mid_scopeA)
    # s[fuse_op5.middle_reshape].set_scope(env.output_scopeA)
    # s[fuse_op5.middle_unpad].set_scope(env.mid_scopeA)
    s[fuse_op5.conv_out].set_scope(env.mid_scopeB)

    s[fuse_op5.feature_input].pragma(s[fuse_op5.feature_input].op.axis[2], env.dma_copy)
    s[fuse_op5.weight_input].pragma(s[fuse_op5.weight_input].op.axis[2], env.dma_copy)
    s[fuse_op5.feature].pragma(s[fuse_op5.feature].op.axis[2], env.dma_copy)
    s[fuse_op5.weight].pragma(s[fuse_op5.weight].op.axis[2], env.dma_copy)
    # s[fuse_op5.middle].pragma(s[fuse_op5.middle].op.axis[2], env.dma_copy)
    # s[fuse_op5.middle_tran].pragma(s[fuse_op5.middle_tran].op.axis[2], env.dma_copy)
    # s[fuse_op5.middle_reshape].pragma(s[fuse_op5.middle_reshape].op.axis[1], env.dma_copy)
    # s[fuse_op5.middle_unpad].pragma(s[fuse_op5.middle_unpad].op.axis[1], env.dma_copy)
    s[fuse_op5.conv_out].pragma(s[fuse_op5.conv_out].op.axis[2], env.dma_copy)

    i, x, j, y = s[fuse_op5.middle_buffer].op.axis
    s[fuse_op5.middle_buffer].reorder(i, x, fuse_op5.k0, fuse_op5.k1, j, y, fuse_op5.k2)

    s[fuse_op5.feature_input].compute_at(s[fuse_op5.middle_buffer], fuse_op5.k0)
    s[fuse_op5.weight_input].compute_at(s[fuse_op5.middle_buffer], fuse_op5.k0)
    s[fuse_op5.feature].compute_at(s[fuse_op5.middle_buffer], fuse_op5.k0)
    s[fuse_op5.weight].compute_at(s[fuse_op5.middle_buffer], fuse_op5.k0)
    s[fuse_op5.middle_buffer].compute_at(s[fuse_op5.conv_out], s[fuse_op5.conv_out].op.axis[1])
    # s[fuse_op5.middle].compute_at(s[fuse_op5.middle_tran], s[fuse_op5.middle_tran].op.axis[0])
    # s[fuse_op5.middle_tran].compute_at(s[fuse_op5.middle_reshape], s[fuse_op5.middle_reshape].op.axis[0])

    s[fuse_op5.middle_buffer].tensorize(fuse_op5.k1, env.gemm)



    ################### add_tensor1 #######################
    s[fuse_op5.add_tensor1_buffer].set_scope(env.mid_scopeA)
    s[fuse_op5.add_tensor1_out].set_scope(env.output_scopeA)
    s[fuse_op5.add_tensor1_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op5.add_tensor1_buffer].pragma(s[fuse_op5.add_tensor1_buffer].op.axis[2], env.dma_copy)
    s[fuse_op5.add_tensor1_out_buffer].pragma(s[fuse_op5.add_tensor1_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op5.conv_out].compute_at(s[fuse_op5.add_tensor1_out], s[fuse_op5.add_tensor1_out].op.axis[1])
    s[fuse_op5.add_tensor1_buffer].compute_at(s[fuse_op5.add_tensor1_out], s[fuse_op5.add_tensor1_out].op.axis[1])
    s[fuse_op5.add_tensor1_out].compute_at(s[fuse_op5.add_tensor1_out_buffer],s[fuse_op5.add_tensor1_out_buffer].op.axis[1])

    s[fuse_op5.add_tensor1_out].pragma(s[fuse_op5.add_tensor1_out].op.axis[2], env.alu)


    ################### add_num #######################
    s[fuse_op5.add_num_buffer].set_scope(env.mid_scopeA)
    s[fuse_op5.add_num_out].set_scope(env.output_scopeA)
    s[fuse_op5.add_num_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op5.add_num_buffer].pragma(s[fuse_op5.add_num_buffer].op.axis[2], env.dma_copy)
    s[fuse_op5.add_num_out_buffer].pragma(s[fuse_op5.add_num_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op5.add_tensor1_out_buffer].compute_at(s[fuse_op5.add_num_out_buffer], s[fuse_op5.add_num_out_buffer].op.axis[1])
    s[fuse_op5.add_num_buffer].compute_at(s[fuse_op5.add_num_out_buffer], s[fuse_op5.add_num_out_buffer].op.axis[1])
    s[fuse_op5.add_num_out].compute_at(s[fuse_op5.add_num_out_buffer], s[fuse_op5.add_num_out_buffer].op.axis[1])

    s[fuse_op5.add_num_out].pragma(s[fuse_op5.add_num_out].op.axis[2], env.alu)

    ################### rshift #######################
    s[fuse_op5.rshift_buffer].set_scope(env.mid_scopeA)
    s[fuse_op5.rshift_out].set_scope(env.output_scopeA)
    s[fuse_op5.rshift_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op5.rshift_buffer].pragma(s[fuse_op5.rshift_buffer].op.axis[2], env.dma_copy)
    s[fuse_op5.rshift_out_buffer].pragma(s[fuse_op5.rshift_out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op5.add_num_out_buffer].compute_at(s[fuse_op5.rshift_out_buffer], s[fuse_op5.rshift_out_buffer].op.axis[1])
    s[fuse_op5.rshift_buffer].compute_at(s[fuse_op5.rshift_out_buffer], s[fuse_op5.rshift_out_buffer].op.axis[1])
    s[fuse_op5.rshift_out].compute_at(s[fuse_op5.rshift_out_buffer], s[fuse_op5.rshift_out_buffer].op.axis[1])

    s[fuse_op5.rshift_out].pragma(s[fuse_op5.rshift_out].op.axis[2], env.alu)

    ################### clip #######################
    s[fuse_op5.max_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op5.min_value_buffer].set_scope(env.mid_scopeA)
    s[fuse_op5.clip_max_out].set_scope(env.output_scopeA)
    s[fuse_op5.clip_min_out].set_scope(env.output_scopeA)
    s[fuse_op5.clip_middle_buffer].set_scope(env.mid_scopeB)

    # s[fuse_op5.add_tensor2_out_buffer].set_scope(env.mid_scopeB)

    s[fuse_op5.max_value_buffer].pragma(s[fuse_op5.max_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op5.min_value_buffer].pragma(s[fuse_op5.min_value_buffer].op.axis[2], env.dma_copy)
    s[fuse_op5.clip_middle_buffer].pragma(s[fuse_op5.clip_middle_buffer].op.axis[2], env.dma_copy)
    s[fuse_op5.out_buffer].pragma(s[fuse_op5.out_buffer].op.axis[2], env.dma_copy)

    s[fuse_op5.rshift_out_buffer].compute_at(s[fuse_op5.out_buffer], s[fuse_op5.out_buffer].op.axis[1])
    s[fuse_op5.max_value_buffer].compute_at(s[fuse_op5.out_buffer], s[fuse_op5.out_buffer].op.axis[1])
    s[fuse_op5.min_value_buffer].compute_at(s[fuse_op5.out_buffer], s[fuse_op5.out_buffer].op.axis[1])
    s[fuse_op5.clip_max_out].compute_at(s[fuse_op5.out_buffer], s[fuse_op5.out_buffer].op.axis[1])
    s[fuse_op5.clip_min_out].compute_at(s[fuse_op5.out_buffer], s[fuse_op5.out_buffer].op.axis[1])
    s[fuse_op5.clip_middle_buffer].compute_at(s[fuse_op5.out_buffer], s[fuse_op5.out_buffer].op.axis[1])

    s[fuse_op5.clip_max_out].pragma(s[fuse_op5.clip_max_out].op.axis[2], env.alu)
    s[fuse_op5.clip_min_out].pragma(s[fuse_op5.clip_min_out].op.axis[2], env.alu)

    return s

def conv_schedule(s, conv):
    s[conv.feature_input].set_scope(env.input_scopeA)
    s[conv.weight_input].set_scope(env.input_scopeB)
    s[conv.feature].set_scope(env.inp_scope)
    s[conv.weight].set_scope(env.wgt_scope)
    s[conv.middle_buffer].set_scope(env.mid_scopeA)

    s[conv.feature_input].pragma(s[conv.feature_input].op.axis[0], env.dma_copy)
    s[conv.weight_input].pragma(s[conv.weight_input].op.axis[0], env.dma_copy)
    s[conv.feature].pragma(s[conv.feature].op.axis[2], env.dma_copy)
    s[conv.weight].pragma(s[conv.weight].op.axis[2], env.dma_copy)
    s[conv.middle].pragma(s[conv.middle].op.axis[2], env.dma_copy)

    i, x, j, y = s[conv.middle_buffer].op.axis
    s[conv.middle_buffer].reorder(i, x, conv.k0, conv.k1, j, y, conv.k2)

    s[conv.feature].compute_at(s[conv.middle_buffer], conv.k0)
    s[conv.weight].compute_at(s[conv.middle_buffer], conv.k0)
    s[conv.middle_buffer].compute_at(s[conv.middle], s[conv.middle].op.axis[1])
    
    s[conv.middle_buffer].tensorize(conv.k1, env.gemm)
    
    return s


def maxpool_schedule(s, maxpool):

    s[maxpool.vec0a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec1a_buf].set_scope(env.mid_scopeB)
    s[maxpool.vec2a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec3a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec4a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec5a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec6a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec7a_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec8a_buf].set_scope(env.mid_scopeA)

    s[maxpool.middle1a].set_scope(env.output_scopeA)
    s[maxpool.middle2a].set_scope(env.output_scopeA)
    s[maxpool.middle3a].set_scope(env.output_scopeA)
    s[maxpool.middle4a].set_scope(env.output_scopeA)
    s[maxpool.middle5a].set_scope(env.output_scopeA)
    s[maxpool.middle6a].set_scope(env.output_scopeA)
    s[maxpool.middle7a].set_scope(env.output_scopeA)
    s[maxpool.middle8a].set_scope(env.output_scopeA)

    s[maxpool.middle1a_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle2a_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle3a_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle4a_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle5a_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle6a_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle7a_buf].set_scope(env.mid_scopeB)

    s[maxpool.vec0a_buf].pragma(s[maxpool.vec0a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec1a_buf].pragma(s[maxpool.vec1a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec2a_buf].pragma(s[maxpool.vec2a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec3a_buf].pragma(s[maxpool.vec3a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec4a_buf].pragma(s[maxpool.vec4a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec5a_buf].pragma(s[maxpool.vec5a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec6a_buf].pragma(s[maxpool.vec6a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec7a_buf].pragma(s[maxpool.vec7a_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec8a_buf].pragma(s[maxpool.vec8a_buf].op.axis[0], env.dma_copy)

    s[maxpool.middle1a_buf].pragma(s[maxpool.middle1a_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle2a_buf].pragma(s[maxpool.middle2a_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle3a_buf].pragma(s[maxpool.middle3a_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle4a_buf].pragma(s[maxpool.middle4a_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle5a_buf].pragma(s[maxpool.middle5a_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle6a_buf].pragma(s[maxpool.middle6a_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle7a_buf].pragma(s[maxpool.middle7a_buf].op.axis[0], env.dma_copy)

    s[maxpool.middle1a].pragma(s[maxpool.middle1a].op.axis[1], env.alu)
    s[maxpool.middle2a].pragma(s[maxpool.middle2a].op.axis[1], env.alu)
    s[maxpool.middle3a].pragma(s[maxpool.middle3a].op.axis[1], env.alu)
    s[maxpool.middle4a].pragma(s[maxpool.middle4a].op.axis[1], env.alu)
    s[maxpool.middle5a].pragma(s[maxpool.middle5a].op.axis[1], env.alu)
    s[maxpool.middle6a].pragma(s[maxpool.middle6a].op.axis[1], env.alu)
    s[maxpool.middle7a].pragma(s[maxpool.middle7a].op.axis[1], env.alu)
    s[maxpool.middle8a].pragma(s[maxpool.middle8a].op.axis[1], env.alu)

    s[maxpool.vec0a_buf].compute_at(s[maxpool.middle1a], maxpool.middle1a.op.axis[0])
    s[maxpool.vec1a_buf].compute_at(s[maxpool.middle1a], maxpool.middle1a.op.axis[0])
    s[maxpool.vec2a_buf].compute_at(s[maxpool.middle2a], maxpool.middle2a.op.axis[0])
    s[maxpool.vec3a_buf].compute_at(s[maxpool.middle3a], maxpool.middle3a.op.axis[0])
    s[maxpool.vec4a_buf].compute_at(s[maxpool.middle4a], maxpool.middle4a.op.axis[0])
    s[maxpool.vec5a_buf].compute_at(s[maxpool.middle5a], maxpool.middle5a.op.axis[0])
    s[maxpool.vec6a_buf].compute_at(s[maxpool.middle6a], maxpool.middle6a.op.axis[0])
    s[maxpool.vec7a_buf].compute_at(s[maxpool.middle7a], maxpool.middle7a.op.axis[0])
    s[maxpool.vec8a_buf].compute_at(s[maxpool.middle8a], maxpool.middle8a.op.axis[0])

    s[maxpool.outa].pragma(s[maxpool.outa].op.axis[0], env.dma_copy)

    s[maxpool.vec0b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec1b_buf].set_scope(env.mid_scopeB)
    s[maxpool.vec2b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec3b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec4b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec5b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec6b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec7b_buf].set_scope(env.mid_scopeA)
    s[maxpool.vec8b_buf].set_scope(env.mid_scopeA)

    s[maxpool.middle1b].set_scope(env.output_scopeA)
    s[maxpool.middle2b].set_scope(env.output_scopeA)
    s[maxpool.middle3b].set_scope(env.output_scopeA)
    s[maxpool.middle4b].set_scope(env.output_scopeA)
    s[maxpool.middle5b].set_scope(env.output_scopeA)
    s[maxpool.middle6b].set_scope(env.output_scopeA)
    s[maxpool.middle7b].set_scope(env.output_scopeA)
    s[maxpool.middle8b].set_scope(env.output_scopeA)

    s[maxpool.middle1b_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle2b_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle3b_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle4b_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle5b_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle6b_buf].set_scope(env.mid_scopeB)
    s[maxpool.middle7b_buf].set_scope(env.mid_scopeB)

    s[maxpool.vec0b_buf].pragma(s[maxpool.vec0b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec1b_buf].pragma(s[maxpool.vec1b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec2b_buf].pragma(s[maxpool.vec2b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec3b_buf].pragma(s[maxpool.vec3b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec4b_buf].pragma(s[maxpool.vec4b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec5b_buf].pragma(s[maxpool.vec5b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec6b_buf].pragma(s[maxpool.vec6b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec7b_buf].pragma(s[maxpool.vec7b_buf].op.axis[0], env.dma_copy)
    s[maxpool.vec8b_buf].pragma(s[maxpool.vec8b_buf].op.axis[0], env.dma_copy)

    s[maxpool.middle1b_buf].pragma(s[maxpool.middle1b_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle2b_buf].pragma(s[maxpool.middle2b_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle3b_buf].pragma(s[maxpool.middle3b_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle4b_buf].pragma(s[maxpool.middle4b_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle5b_buf].pragma(s[maxpool.middle5b_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle6b_buf].pragma(s[maxpool.middle6b_buf].op.axis[0], env.dma_copy)
    s[maxpool.middle7b_buf].pragma(s[maxpool.middle7b_buf].op.axis[0], env.dma_copy)

    s[maxpool.middle1b].pragma(s[maxpool.middle1b].op.axis[1], env.alu)
    s[maxpool.middle2b].pragma(s[maxpool.middle2b].op.axis[1], env.alu)
    s[maxpool.middle3b].pragma(s[maxpool.middle3b].op.axis[1], env.alu)
    s[maxpool.middle4b].pragma(s[maxpool.middle4b].op.axis[1], env.alu)
    s[maxpool.middle5b].pragma(s[maxpool.middle5b].op.axis[1], env.alu)
    s[maxpool.middle6b].pragma(s[maxpool.middle6b].op.axis[1], env.alu)
    s[maxpool.middle7b].pragma(s[maxpool.middle7b].op.axis[1], env.alu)
    s[maxpool.middle8b].pragma(s[maxpool.middle8b].op.axis[1], env.alu)

    s[maxpool.vec0b_buf].compute_at(s[maxpool.middle1b], maxpool.middle1b.op.axis[0])
    s[maxpool.vec1b_buf].compute_at(s[maxpool.middle1b], maxpool.middle1b.op.axis[0])
    s[maxpool.vec2b_buf].compute_at(s[maxpool.middle2b], maxpool.middle2b.op.axis[0])
    s[maxpool.vec3b_buf].compute_at(s[maxpool.middle3b], maxpool.middle3b.op.axis[0])
    s[maxpool.vec4b_buf].compute_at(s[maxpool.middle4b], maxpool.middle4b.op.axis[0])
    s[maxpool.vec5b_buf].compute_at(s[maxpool.middle5b], maxpool.middle5b.op.axis[0])
    s[maxpool.vec6b_buf].compute_at(s[maxpool.middle6b], maxpool.middle6b.op.axis[0])
    s[maxpool.vec7b_buf].compute_at(s[maxpool.middle7b], maxpool.middle7b.op.axis[0])
    s[maxpool.vec8b_buf].compute_at(s[maxpool.middle8b], maxpool.middle8b.op.axis[0])

    s[maxpool.outb].pragma(s[maxpool.outb].op.axis[0], env.dma_copy)

    return s

def argpool_schedule(s, argpool):
    s[argpool.vec0_buf].set_scope(env.mid_scopeA)

    s[argpool.vec1_buf].set_scope(env.mid_scopeB)

    s[argpool.vec2_buf].set_scope(env.mid_scopeA)
    s[argpool.vec3_buf].set_scope(env.mid_scopeA)
    s[argpool.vec4_buf].set_scope(env.mid_scopeA)
    s[argpool.vec5_buf].set_scope(env.mid_scopeA)
    s[argpool.vec6_buf].set_scope(env.mid_scopeA)
    s[argpool.vec7_buf].set_scope(env.mid_scopeA)
    s[argpool.vec8_buf].set_scope(env.mid_scopeA)

    s[argpool.middle1].set_scope(env.output_scopeA)
    s[argpool.middle2].set_scope(env.output_scopeA)
    s[argpool.middle3].set_scope(env.output_scopeA)
    s[argpool.middle4].set_scope(env.output_scopeA)
    s[argpool.middle5].set_scope(env.output_scopeA)
    s[argpool.middle6].set_scope(env.output_scopeA)
    s[argpool.middle7].set_scope(env.output_scopeA)
    s[argpool.middle8].set_scope(env.output_scopeA)

    s[argpool.middle1_buf].set_scope(env.mid_scopeB)
    s[argpool.middle2_buf].set_scope(env.mid_scopeB)
    s[argpool.middle3_buf].set_scope(env.mid_scopeB)
    s[argpool.middle4_buf].set_scope(env.mid_scopeB)
    s[argpool.middle5_buf].set_scope(env.mid_scopeB)
    s[argpool.middle6_buf].set_scope(env.mid_scopeB)
    s[argpool.middle7_buf].set_scope(env.mid_scopeB)

    s[argpool.vec0_buf].pragma(s[argpool.vec0_buf].op.axis[0], env.dma_copy)
    s[argpool.vec1_buf].pragma(s[argpool.vec1_buf].op.axis[0], env.dma_copy)
    s[argpool.vec2_buf].pragma(s[argpool.vec2_buf].op.axis[0], env.dma_copy)
    s[argpool.vec3_buf].pragma(s[argpool.vec3_buf].op.axis[0], env.dma_copy)
    s[argpool.vec4_buf].pragma(s[argpool.vec4_buf].op.axis[0], env.dma_copy)
    s[argpool.vec5_buf].pragma(s[argpool.vec5_buf].op.axis[0], env.dma_copy)
    s[argpool.vec6_buf].pragma(s[argpool.vec6_buf].op.axis[0], env.dma_copy)
    s[argpool.vec7_buf].pragma(s[argpool.vec7_buf].op.axis[0], env.dma_copy)
    s[argpool.vec8_buf].pragma(s[argpool.vec8_buf].op.axis[0], env.dma_copy)

    s[argpool.middle1_buf].pragma(s[argpool.middle1_buf].op.axis[0], env.dma_copy)
    s[argpool.middle2_buf].pragma(s[argpool.middle2_buf].op.axis[0], env.dma_copy)
    s[argpool.middle3_buf].pragma(s[argpool.middle3_buf].op.axis[0], env.dma_copy)
    s[argpool.middle4_buf].pragma(s[argpool.middle4_buf].op.axis[0], env.dma_copy)
    s[argpool.middle5_buf].pragma(s[argpool.middle5_buf].op.axis[0], env.dma_copy)
    s[argpool.middle6_buf].pragma(s[argpool.middle6_buf].op.axis[0], env.dma_copy)
    s[argpool.middle7_buf].pragma(s[argpool.middle7_buf].op.axis[0], env.dma_copy)

    s[argpool.middle1].pragma(s[argpool.middle1].op.axis[1], env.alu)
    s[argpool.middle2].pragma(s[argpool.middle2].op.axis[1], env.alu)
    s[argpool.middle3].pragma(s[argpool.middle3].op.axis[1], env.alu)
    s[argpool.middle4].pragma(s[argpool.middle4].op.axis[1], env.alu)
    s[argpool.middle5].pragma(s[argpool.middle5].op.axis[1], env.alu)
    s[argpool.middle6].pragma(s[argpool.middle6].op.axis[1], env.alu)
    s[argpool.middle7].pragma(s[argpool.middle7].op.axis[1], env.alu)
    s[argpool.middle8].pragma(s[argpool.middle8].op.axis[1], env.alu)

    s[argpool.vec0_buf].compute_at(s[argpool.middle1], argpool.middle1.op.axis[0])
    s[argpool.vec1_buf].compute_at(s[argpool.middle1], argpool.middle1.op.axis[0])
    s[argpool.vec2_buf].compute_at(s[argpool.middle2], argpool.middle2.op.axis[0])
    s[argpool.vec3_buf].compute_at(s[argpool.middle3], argpool.middle3.op.axis[0])
    s[argpool.vec4_buf].compute_at(s[argpool.middle4], argpool.middle4.op.axis[0])
    s[argpool.vec5_buf].compute_at(s[argpool.middle5], argpool.middle5.op.axis[0])
    s[argpool.vec6_buf].compute_at(s[argpool.middle6], argpool.middle6.op.axis[0])
    s[argpool.vec7_buf].compute_at(s[argpool.middle7], argpool.middle7.op.axis[0])
    s[argpool.vec8_buf].compute_at(s[argpool.middle8], argpool.middle8.op.axis[0])

    s[argpool.out].pragma(s[argpool.out].op.axis[0], env.dma_copy)

    return s

def add_num_schedule(s, add_num):
    s[add_num.data1_in].compute_at(s[add_num.cout], add_num.cout.op.axis[1])
    s[add_num.data2_in].compute_at(s[add_num.cout], add_num.cout.op.axis[1])
    s[add_num.cout].compute_at(s[add_num.out], add_num.out.op.axis[1])

    s[add_num.data1_in].set_scope(env.mid_scopeA)
    s[add_num.data2_in].set_scope(env.mid_scopeB)

    s[add_num.cout].set_scope(env.output_scopeA)

    # s[cout].set_scope(env.acc_scope)
    s[add_num.data1_in].pragma(s[add_num.data1_in].op.axis[1], env.dma_copy)
    s[add_num.data2_in].pragma(s[add_num.data2_in].op.axis[1], env.dma_copy)
    s[add_num.cout].pragma(s[add_num.cout].op.axis[2], env.alu)
    s[add_num.out].pragma(s[add_num.out].op.axis[2], env.dma_copy)

    return s

def add_tensor_schedule(s, add_tensor):
    s[add_tensor.data1_in].compute_at(s[add_tensor.cout], add_tensor.cout.op.axis[1])
    s[add_tensor.data2_in].compute_at(s[add_tensor.cout], add_tensor.cout.op.axis[1])
    s[add_tensor.cout].compute_at(s[add_tensor.out], add_tensor.out.op.axis[1])

    s[add_tensor.data1_in].set_scope(env.mid_scopeA)
    s[add_tensor.data2_in].set_scope(env.mid_scopeB)

    s[add_tensor.cout].set_scope(env.output_scopeA)

    # s[cout].set_scope(env.acc_scope)
    s[add_tensor.data1_in].pragma(s[add_tensor.data1_in].op.axis[1], env.dma_copy)
    s[add_tensor.data2_in].pragma(s[add_tensor.data2_in].op.axis[1], env.dma_copy)
    s[add_tensor.cout].pragma(s[add_tensor.cout].op.axis[2], env.alu)
    s[add_tensor.out].pragma(s[add_tensor.out].op.axis[2], env.dma_copy)

    return s

def mul_tensor_schedule(s, mul_tensor):
    s[mul_tensor.data1_in].compute_at(s[mul_tensor.cout], mul_tensor.cout.op.axis[1])
    s[mul_tensor.data2_in].compute_at(s[mul_tensor.cout], mul_tensor.cout.op.axis[1])
    s[mul_tensor.cout].compute_at(s[mul_tensor.out], mul_tensor.out.op.axis[1])

    s[mul_tensor.data1_in].set_scope(env.mid_scopeA)
    s[mul_tensor.data2_in].set_scope(env.mid_scopeB)

    s[mul_tensor.cout].set_scope(env.output_scopeA)

    # s[cout].set_scope(env.acc_scope)
    s[mul_tensor.data1_in].pragma(s[mul_tensor.data1_in].op.axis[1], env.dma_copy)
    s[mul_tensor.data2_in].pragma(s[mul_tensor.data2_in].op.axis[1], env.dma_copy)
    s[mul_tensor.cout].pragma(s[mul_tensor.cout].op.axis[2], env.alu)
    s[mul_tensor.out].pragma(s[mul_tensor.out].op.axis[2], env.dma_copy)

    return s

def left_shift_schedule(s, left_shift):
    s[left_shift.data1_in].compute_at(s[left_shift.out], left_shift.out.op.axis[1])
    s[left_shift.data2_in].compute_at(s[left_shift.out], left_shift.out.op.axis[1])
    s[left_shift.cout].compute_at(s[left_shift.out], left_shift.out.op.axis[1])

    s[left_shift.data1_in].set_scope(env.mid_scopeA)
    s[left_shift.data2_in].set_scope(env.mid_scopeB)

    s[left_shift.cout].set_scope(env.output_scopeA)

    # s[cout].set_scope(env.acc_scope)
    s[left_shift.data1_in].pragma(s[left_shift.data1_in].op.axis[1], env.dma_copy)
    s[left_shift.data2_in].pragma(s[left_shift.data2_in].op.axis[1], env.dma_copy)
    s[left_shift.cout].pragma(s[left_shift.cout].op.axis[2], env.alu)
    s[left_shift.out].pragma(s[left_shift.out].op.axis[2], env.dma_copy)

    return s

def right_shift_schedule(s, right_shift):
    s[right_shift.data1_in].compute_at(s[right_shift.out], right_shift.out.op.axis[1])
    s[right_shift.data2_in].compute_at(s[right_shift.out], right_shift.out.op.axis[1])
    s[right_shift.cout].compute_at(s[right_shift.out], right_shift.out.op.axis[1])

    s[right_shift.data1_in].set_scope(env.mid_scopeA)
    s[right_shift.data2_in].set_scope(env.mid_scopeB)

    s[right_shift.cout].set_scope(env.output_scopeA)

    # s[cout].set_scope(env.acc_scope)
    s[right_shift.data1_in].pragma(s[right_shift.data1_in].op.axis[1], env.dma_copy)
    s[right_shift.data2_in].pragma(s[right_shift.data2_in].op.axis[1], env.dma_copy)
    s[right_shift.cout].pragma(s[right_shift.cout].op.axis[2], env.alu)
    s[right_shift.out].pragma(s[right_shift.out].op.axis[2], env.dma_copy)

    return s

def relu_schedule(s, relu):
    s[relu.data1_in].compute_at(s[relu.cout], relu.cout.op.axis[1])
    s[relu.data2_in].compute_at(s[relu.cout], relu.cout.op.axis[1])
    s[relu.cout].compute_at(s[relu.out], relu.out.op.axis[1])

    s[relu.data1_in].set_scope(env.mid_scopeA)
    s[relu.data2_in].set_scope(env.mid_scopeB)

    s[relu.cout].set_scope(env.output_scopeA)

    # s[cout].set_scope(env.acc_scope)
    s[relu.data1_in].pragma(s[relu.data1_in].op.axis[1], env.dma_copy)
    s[relu.data2_in].pragma(s[relu.data2_in].op.axis[1], env.dma_copy)
    s[relu.cout].pragma(s[relu.cout].op.axis[2], env.alu)
    s[relu.out].pragma(s[relu.out].op.axis[2], env.dma_copy)

    return s