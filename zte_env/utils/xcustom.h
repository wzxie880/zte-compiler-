#ifndef XCUSTOM_H_
#define XCUSTOM_H_

/// custom instructions are defined in this file
/// copy from GEMMINI, but modified to fit our requirements
#include <stdint.h>


#define STR1(x) #x
#ifndef STR
#define STR(x) STR1(x)
#endif

#define CAT_(A, B) A##B
#define CAT(A, B) CAT_(A, B)

/** Assembly macro for creating "raw" Rocket Custom Coproessor (RoCC)
  * assembly language instructions that will return data in rd. These
  * are to be used only in assembly language programs (not C/C++).
  *
  * Example:
  *
  * Consider the following macro consisting of a CUSTOM_0 instruction
  * with func7 "42" that is doing some operation of "a0 = op(a1, a2)":
  *
  *     ROCC_INSTRUCTION_RAW_R_R_R(0, a0, a1, a2, 42)
  *
  * This will produce the following pseudo assembly language
  * instruction:
  *
  *     .insn r CUSTOM_0, 7, 42, a0, a1, a2
  *
  * @param x the custom instruction number: 0, 1, 2, or 3
  * @param opcode the opcode of custom instruction
  * @param rd the destination register, e.g., a0 or x10
  * @param rs1 the first source register, e.g., a0 or x10
  * @param rs2 the second source register, e.g., a0 or x10
  * @param func7 the value of the func7 field
  * @return a raw .insn RoCC instruction
  */
#define ROCC_INSTRUCTION_RAW_R_R_R(x, opcode, rd, rs1, rs2, func7) \
  .insn r CAT(CUSTOM_, x), opcode, func7, rd, rs1, rs2

/** Assembly macro for creating "raw" Rocket Custom Coproessor (RoCC)
  * assembly language instructions that will *NOT* return data in rd.
  * These are to be used only in assembly language programs (not
  * C/C++).
  *
  * Example:
  *
  * Consider the following macro consisting of a CUSTOM_1 instruction
  * with func7 "42" that is doing some operation of "op(a1, a2)". *NO*
  * data is returned:
  *
  *     ROCC_INSTRUCTION_RAW_R_R_R(1, a1, a2, 42)
  *
  * This will produce the following pseudo assembly language
  * instruction:
  *
  *     .insn r CUSTOM_1, 3, 42, x0, a1, a2
  *
  * @param x the custom instruction number: 0, 1, 2, or 3a
  * @param opcode the opcode of the custom instruction
  * @param rs1 the first source register, e.g., a0 or x10
  * @param rs2 the second source register, e.g., a0 or x10
  * @param func7 the value of the func7 field
  * @return a raw .insn RoCC instruction
  */
#define ROCC_INSTRUCTION_RAW_0_R_R(x, opcode, rs1, rs2, func7) \
  .insn r CAT(CUSTOM_, x), opcode, func7, x0, rs1, rs2

/** C/C++ inline assembly macro for creating Rocket Custom Coprocessor
  * (RoCC) instructions that return data in rd. These are to be used
  * only in C/C++ programs (not bare assembly).
  *
  * This is equivalent to ROCC_INSTRUCTION_R_R_R. See it's
  * documentation.
  */
#define ROCC_INSTRUCTION(x, opcode, rd, rs1, rs2, func7) \
  ROCC_INSTRUCTION_R_R_R(x, opcode, rd, rs1, rs2, func7)

/** C/C++ inline assembly macro for creating Rocket Custom Coprocessor
  * (RoCC) instructions that return data in C variable rd. 
  * These are to be used only in C/C++ programs (not bare assembly).
  *
  * Example:
  *
  * Consider the following macro consisting of a CUSTOM_2 instruction
  * with func7 "42" that is doing some operation of "a0 = op(a1, a2)"
  * (where a0, a1, and a2 are variables defined in C):
  *
  *     ROCC_INSTRUCTION(2, a0, a1, a2, 42)
  *
  * This will produce the following inline assembly:
  *
  *     asm volatile(
  *         ".insn r CUSTOM_2, 0x7, 42, %0, %1, %2"
  *         : "=r"(rd)
  *         : "r"(rs1), "r"(rs2));
  *
  * @param x the custom instruction number: 0, 1, 2, or 3
  * @param opcode the opcode of custom instruction
  * @param rd the C variable to capture as destination operand
  * @param rs1 the C variable to capture for first source register
  * @param rs2 the C variable to capture for second source register
  * @param func7 the value of the func7 field
  * @return an inline assembly RoCC instruction
  */
#define ROCC_INSTRUCTION_R_R_R(x, opcode, rd, rs1, rs2, func7)                               \
  {                                                                                  \
    asm volatile(                                                                    \
        ".insn r " STR(CAT(CUSTOM_, x)) ", " STR(0x(opcode)) ", " STR(func7) ", %0, %1, %2" \
        : "=r"(rd)                                                                   \
        : "r"(rs1), "r"(rs2));                                                       \
  }

/** C/C++ inline assembly macro for creating Rocket Custom Coprocessor
  * (RoCC) instructions that return data in C variable rd.
  * These are to be used only in C/C++ programs (not bare assembly).
  *
  * Example:
  *
  * Consider the following macro consisting of a CUSTOM_3 instruction
  * with func7 "42" that is doing some operation of "a0 = op(a1, a2)"
  * (where a0, a1, and a2 are variables defined in C):
  *
  *     ROCC_INSTRUCTION(3, a0, a1, a2, 42)
  *
  * This will produce the following inline assembly:
  *
  *     asm volatile(
  *         ".insn r CUSTOM_3, 0x7, 42, %0, %1, %2"
  *         :: "r"(rs1), "r"(rs2));
  *
  * @param x the custom instruction number: 0, 1, 2, or 3
  * @param rs1 the C variable to capture for first source register
  * @param rs2 the C variable to capture for second source register
  * @param funct7 the value of the funct7 f
  * @return an inline assembly RoCC instruction
  */
#define ROCC_INSTRUCTION_0_R_R(x, opcode, rs1, rs2, func7)                                   \
  {                                                                                  \
    asm volatile(                                                                    \
        ".insn r " STR(CAT(CUSTOM_, x)) ", " STR(0x(opcode)) ", " STR(func7) ", x0, %0, %1" \
        :                                                                            \
        : "r"(rs1), "r"(rs2));                                                       \
  }

// [TODO] fix these to align with the above approach
// Macro to pass rs2_ as an immediate
/*
#define ROCC_INSTRUCTION_R_R_I(XCUSTOM_, rd_, rs1_, rs2_, funct_) \
  asm volatile (XCUSTOM_" %[rd], %[rs1], %[rs2], %[funct]"        \
                : [rd] "=r" (rd_)                                 \
                : [rs1] "r" (rs1_), [rs2] "i" (rs2_), [funct] "i" (funct_))
// Macro to pass rs1_ and rs2_ as immediates
#define ROCC_INSTRUCTION_R_I_I(XCUSTOM_, rd_, rs1_, rs2_, funct_) \
  asm volatile (XCUSTOM_" %[rd], %[rs1], %[rs2], %[funct]"        \
                : [rd] "=r" (rd_)                                 \
                : [rs1] "i" (rs1_), [rs2] "i" (rs2_), [funct] "i" (funct_))
*/

#define ZTE_OPCODE 711  // 0x1111011

#define ZTE_GEMM_FUNC_FP16 0
#define ZTE_GEMM_FUNC_INT8 1

#define ZTE_VADD_FUNC_FP16 4
#define ZTE_VADD_FUNC_INT8 5
#define ZTE_VSUB_FUNC_FP16 8
#define ZTE_VSUB_FUNC_INT8 9
#define ZTE_VSUB_FUNC_INT12 A

#define ZTE_VMUL_FUNC_FP16 C
#define ZTE_VMUL_FUNC_INT8 D
#define ZTE_VMUL_FUNC_INT12 E

#define ZTE_VMAX_FUNC_FP16 10
#define ZTE_VMAX_FUNC_INT8 11

#define ZTE_VMIN_FUNC_FP16 14
#define ZTE_VMIN_FUNC_INT8 15

#define ZTE_VAND_FUNC_FP16 18
#define ZTE_VAND_FUNC_INT8 19

#define ZTE_VOR_FUNC_FP16 1C
#define ZTE_VOR_FUNC_INT8 1D

#define ZTE_TAGSET_FUNC 5C
#define ZTE_TAGCHK_FUNC 5D
#define ZTE_TAGCLR_FUNC 5E

#define ZTE_VMOV_FUNC 78
#define ZTE_VSET_FUNC_FP16 7C
#define ZTE_VSET_FUNC_INT8 7D

/// GEMM instruction
void zte_gemm_fp16(uint32_t Rd, uint32_t Rm, uint32_t Rn, uint32_t S, uint32_t K, uint32_t N, uint32_t M);
void zte_gemm_int8(uint32_t Rd, uint32_t Rm, uint32_t Rn, uint32_t S, uint32_t K, uint32_t N, uint32_t M, uint32_t shift_d, uint32_t shift_n);

/// ALU instructions
void zte_vadd_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vadd_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

void zte_vsub_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vsub_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

void zte_vmul_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vmul_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

void zte_vmax_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vmax_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

void zte_vmin_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vmin_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

void zte_vand_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vand_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

void zte_vor_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);
void zte_vor_int8(uint32_t Rd, uint32_t Rn, uint32_t Rm, uint32_t Rc, uint32_t mask);

/// VMOV instructions
void zte_vmov(uint32_t Rd, uint32_t Rn, uint32_t mask);
void zte_vset_fp16(uint32_t Rd, uint32_t Rn, uint32_t Rc, uint32_t mask);
void zte_vset_int8(uint32_t Rd, uint32_t Rn, uint32_t Rc, uint32_t mask);

/// synchronize instructions

#endif
