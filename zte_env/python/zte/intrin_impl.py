""" import ll code directly """
""" compile the code in the utils directory through ./compile """
""" The code is put in the directory $TVM_HOME/zte/python/zte """

import os

def intrin_impl():
    tvm_home = os.getenv("TVM_HOME")
    xcustom_ll ="/home/wzxie/tvm/tvm_compiler"  + "/zte/python/zte/xcustom.ll"
    with open(xcustom_ll, "r") as f:
        ll_code = f.read();

    return ll_code;
