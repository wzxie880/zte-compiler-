#include "rocc.h"
#include <stdint.h>
#include <stdio.h>

#define data_grain_byte 4
#define gemm_size 8    
#define MAX 64
#define MIN 0

#define ve_size 8
#define ve_num 4

// typedef unsigned char gemm_in_t;
// typedef unsigned short gemm_out_t;
// typedef unsigned short ve_t;

typedef unsigned char gemm_in_t;
typedef unsigned short gemm_out_t;
typedef unsigned int ve_t;

#define ADD  1
#define SUB  2
#define MUL  3
#define MAX  5
#define MIN  6
#define AND  7
#define OR   8
#define SR 9
#define SL 10

const uint16_t scale = 1;
const uint16_t loop = 1;
const uint16_t loop1 = 20;
const uint64_t DDR      = 0x0;
const uint64_t InputA   = 0x20000000;
const uint64_t InputB   = 0x20010000;
const uint64_t FeatureA = 0x20020000;
const uint64_t FeatureB = 0x20030000;
const uint64_t WeightA  = 0x20040000;
const uint64_t WeightB  = 0x20050000;
const uint64_t MiddleA  = 0x20060000;
const uint64_t MiddleB  = 0x20070000;
const uint64_t OutputA   = 0x20080000;
const uint64_t OutputB   = 0x20090000;

void gemm(uint64_t rm,uint64_t rn,uint64_t rd,uint64_t M,uint64_t K,uint64_t N,uint64_t S){
  rm = rm & 0xfffff;
  rn = rn & 0xfffff;
  rd = rd & 0xfffff;
  uint64_t rs1 = (rd << 40) + (rm << 20) + rn;
  uint64_t rs2 = (M << 16) | (N << 24) | (K << 32) | (S << 48);
  ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, 0x0);
}

void write_reg(uint64_t reg_index,uint64_t value){
  ROCC_INSTRUCTION_I_R_R(3, 0, reg_index, value, 0x76);
}

uint64_t mask1(uint64_t src1_repeat,uint64_t src1_share1,uint64_t src1_gap,uint64_t src1_share2,uint64_t src2_repeat,uint64_t src2_share1,uint64_t src2_gap,uint64_t src2_share2,uint64_t dest_repeat,uint64_t dest_share1,uint64_t dest_gap,uint64_t dest_share2){
    
    dest_repeat = dest_repeat & (0b1111111);
    dest_share1 = dest_share1 & 0b1;
    dest_gap = dest_gap & (0b1111111);
    dest_share2 = dest_share2 & (0b1);

    src1_repeat = src1_repeat & (0b1111111);
    src1_share1 = src1_share1 & 0b1;
    src1_gap = src1_gap & (0b1111111);
    src1_share2 = src1_share2 & (0b1);

    src2_repeat = src2_repeat & (0b1111111);
    src2_share1 = src2_share1 & 0b1;
    src2_gap = src2_gap & (0b1111111);
    src2_share2 = src2_share2 & (0b1);

    return dest_repeat | dest_share1 << 7 | dest_gap << 8 | dest_share2 << 15 | src1_repeat << 16 | src2_share1 << 23 | src1_gap << 24 | src1_share2 << 31 | src2_repeat << 32 | src2_share1 << 39 | src2_gap << 40 | src2_share2 << 47;

}

void ve(int funct,uint64_t rm,uint64_t rn,uint64_t rd,uint64_t length,uint64_t mask1){
  rm = rm & 0xfffff;
  rn = rn & 0xfffff;
  rd = rd & 0xfffff;
  uint64_t rs1 = (rd << 40) + (rm << 20) + rn;
  uint64_t rs2 = (mask1 << 16) + length;
  switch(funct){
    case ADD:ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, ADD << 2);break;
    case SUB:ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, SUB << 2);break;
    case MUL:ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, MUL << 2);break;
    case MAX:ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, MAX << 2);break;
    case MIN:ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, MIN << 2);break;
    case AND:ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, AND << 2);break;
    case OR :ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, OR  << 2);break;
    case SR :ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, SR  << 2);break;
    case SL :ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, SL  << 2);break;
  }
  
}

uint64_t mask2(uint64_t src_repeat,uint64_t src_gap,uint64_t src_load,uint64_t des_repeat,uint64_t des_gap,uint64_t des_store){

  uint64_t mask_src = src_repeat + (src_gap << 11) + (src_load << 21);
  uint64_t mask_des = des_repeat + (des_gap << 11) + (des_store << 21);
  uint64_t mask2 = mask_des + (mask_src << 24);
  //printf("mask_src : 0x%" PRIx64 "\n", mask_src);
  //printf("mask_des : 0x%" PRIx64 "\n", mask_des);
  //printf("mask2 : 0x%" PRIx64 "\n", mask2);
  //printf("\n");
  return mask2;
}

void move(uint64_t src,uint64_t des,uint64_t length,uint64_t mask2){
  uint64_t rs1 = (des << 30) + src;
  uint64_t rs2 = (mask2 << 16) + length;
  // printf("src    : 0x%" PRIx64 "\n", src);
  // printf("des    : 0x%" PRIx64 "\n", des);
  // printf("length : 0x%" PRIx64 "\n", length);
  //printf("rs2 : 0x%" PRIx64 "\n", rs2);
  // printf("\n");
  ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, 0x78);
}

void load(void* mem_addr,uint64_t rocc_addr,uint64_t length,uint64_t bias){
  uint64_t mask_load_ex  = mask2(1,0,1,1,0,0);
  uint64_t mem_addr_int=(uint64_t)mem_addr+bias;
  write_reg(0,mem_addr_int);
  asm volatile("fence"); 
  move(0,rocc_addr,length,mask_load_ex);
  asm volatile("fence"); 
}

void store(void* mem_addr,uint64_t rocc_addr,uint64_t length,uint64_t bias){
  uint64_t mask_store_ex = mask2(1,0,0,1,0,1);
  uint64_t mem_addr_int=(uint64_t)mem_addr+bias;
  write_reg(1,mem_addr_int);
  asm volatile("fence"); 
  move(rocc_addr,0,length,mask_store_ex);
  asm volatile("fence"); 
}

int time_start(){
  // op 
  //rd = 1   rs1 rs2 
  //func = 1
  int t;
  ROCC_INSTRUCTION_R_I_I(3, t, 0, 0, 1);
  // printf("%d\n",t);
  return t;

}
int time_end(){
  // op 
  //rd = 1   rs1 rs2 
  //func = 1
  int t;
  ROCC_INSTRUCTION_R_I_I(3, t, 0, 0, 0x79);
  // printf("%d\n",t);
  return t;

}

void nop(){
  for(int j=0;j<loop1;j++){
    printf("%d", j);
  }
  printf("\n");
  printf("%d", loop1);
}

uint64_t reg_index2addr(uint64_t index){
  return index * 8;
}
