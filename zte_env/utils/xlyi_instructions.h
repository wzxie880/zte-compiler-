#include "rocc.h"
#include <stdint.h>

#define gemm_size 16     
#define MAX 255
#define MIN 0

#define ve_size 16
#define ve_num 8

typedef unsigned char gemm_t;
typedef unsigned short gemm_out_t;
typedef unsigned short ve_t;


#define ADD  1
#define SUB  2
#define MUL  3
#define MAX  5
#define MIN  6
#define AND  7
#define OR   8

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

void gemm1(uint64_t rm,uint64_t rn,uint64_t rd,uint64_t M,uint64_t K,uint64_t N, uint64_t i, uint64_t x, uint64_t rv){
     gemm((int64_t)537001984+16*rv+32*i, (int64_t)537133056+x*32+rv*16, (int64_t)537264128+i*64+x*32, (int64_t)1, (int64_t)1, (int64_t)1);
     gemm((int64_t)537001984+16*rv+32*i, (int64_t)537133056+x*32+rv*16, (int64_t)537329664+i*64+x*32, (int64_t)1, (int64_t)1, (int64_t)1);
     ve(1,537264128,537329664,537395200,128,0);
}

void gemm(uint64_t rm,uint64_t rn,uint64_t rd,uint64_t M,uint64_t K,uint64_t N){
  rm = rm & 0xfffff;
  rn = rn & 0xfffff;
  rd = rd & 0xfffff;
  uint64_t rs1 = (rd << 40) + (rm << 20) + rn;
  uint64_t rs2 = (M << 16) | (N << 24) | (K << 32);
  ROCC_INSTRUCTION_I_R_R(3, 0, rs1, rs2, 0x0);
}

void write_reg(uint64_t reg_index,uint64_t value){
  ROCC_INSTRUCTION_I_R_R(3, 0, reg_index, value, 0x76);
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

void load(void* mem_addr,uint64_t rocc_addr,uint64_t length){
  uint64_t mask_load_ex  = mask2(1,0,1,1,0,0);
  uint64_t mem_addr_int=(uint64_t)mem_addr;
  write_reg(0,mem_addr_int);
  move(0,rocc_addr,length,mask_load_ex);
}

void store(void* mem_addr,uint64_t rocc_addr,uint64_t length){
  uint64_t mask_store_ex = mask2(1,0,0,1,0,1);
  uint64_t mem_addr_int=(uint64_t)mem_addr;
  write_reg(1,mem_addr_int);
  move(rocc_addr,0,length,mask_store_ex);
}

uint64_t reg_index2addr(uint64_t index){
  return index * 8;
}