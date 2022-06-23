#include "xcustom.h"

/// GEMM instruction
void zte_gemm_fp16(uint32_t Rd, uint32_t Rm, uint32_t Rn, uint32_t S, uint32_t K, uint32_t N, uint32_t M)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (S << 48) | (K << 32) | (N << 24) | (M << 16);
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_GEMM_FUNC_FP16);
}


void zte_gemm_int8(uint32_t Rd, uint32_t Rm, uint32_t Rn, uint32_t S, uint32_t K, uint32_t N, uint32_t M, uint32_t shift_d, uint32_t shift_n)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (shift_n << 57) | (shift_d << 56) | (S << 48) | (K << 32) | (N << 24) | (M << 16);
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_GEMM_FUNC_INT8);                                                            
}
    
/// ALU instructions
void zte_vadd_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VADD_FUNC_FP16)
}

void zte_vadd_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VADD_FUNC_INT8)
}

void zte_vsub_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VSUB_FUNC_FP16)
}

void zte_vsub_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VSUB_FUNC_INT8)
}

void zte_vmul_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMUL_FUNC_FP16) 
}

void zte_vmul_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMUL_FUNC_INT8)
}

void zte_vmax_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMAX_FUNC_FP16)
}

void zte_vmax_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = (mask << 16) | Rc;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMAX_FUNC_INT8)
}

void zte_vmin_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t  rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMIN_FUNC_FP16 );


}

void zte_vmin_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t  rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMIN_FUNC_INT8);

}

void zte_vand_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t  rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VAND_FUNC_FP16);
}

void zte_vand_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t  rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VAND_FUNC_INT8);
}

void zte_vor_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t  rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VOR_FUNC_FP16);
}

void zte_vor_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask)
{
    uint64_t  rs1, rs2;
    rs1 = (Rd << 40) | (Rm << 20) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VOR_FUNC_INT8);
}

/// VMOV instructions
void zte_vmov(uint32_t Rd, uint32_t Rn, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 30) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VMOV_FUNC);
}

void zte_vset_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 30) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VSET_FUNC_FP16);
}

void zte_vset_int8(uint32_t Rd, uint32_t Rn, uint32_t Rc, uint32_t mask)
{
    uint64_t rs1, rs2;
    rs1 = (Rd << 30) | Rn;
    rs2 = mask;
    ROCC_INSTRUCTION_0_R_R(0, ZTE_OPCODE, rs1, rs2, ZTE_VSET_FUNC_INT8);
}
