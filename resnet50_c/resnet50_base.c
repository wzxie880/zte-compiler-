// tvm target: c -keys=cpu -link-params=0
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t default_function(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int32_t arg4_code = ((int32_t*)arg_type_ids)[(4)];
  void* arg5 = (((TVMValue*)args)[5].v_handle);
  int32_t arg5_code = ((int32_t*)arg_type_ids)[(5)];
  void* arg6 = (((TVMValue*)args)[6].v_handle);
  int32_t arg6_code = ((int32_t*)arg_type_ids)[(6)];
  void* arg7 = (((TVMValue*)args)[7].v_handle);
  int32_t arg7_code = ((int32_t*)arg_type_ids)[(7)];
  void* arg8 = (((TVMValue*)args)[8].v_handle);
  int32_t arg8_code = ((int32_t*)arg_type_ids)[(8)];
  void* arg9 = (((TVMValue*)args)[9].v_handle);
  int32_t arg9_code = ((int32_t*)arg_type_ids)[(9)];
  void* arg10 = (((TVMValue*)args)[10].v_handle);
  int32_t arg10_code = ((int32_t*)arg_type_ids)[(10)];
  void* arg11 = (((TVMValue*)args)[11].v_handle);
  int32_t arg11_code = ((int32_t*)arg_type_ids)[(11)];
  void* arg12 = (((TVMValue*)args)[12].v_handle);
  int32_t arg12_code = ((int32_t*)arg_type_ids)[(12)];
  void* arg13 = (((TVMValue*)args)[13].v_handle);
  int32_t arg13_code = ((int32_t*)arg_type_ids)[(13)];
  void* arg14 = (((TVMValue*)args)[14].v_handle);
  int32_t arg14_code = ((int32_t*)arg_type_ids)[(14)];
  void* arg15 = (((TVMValue*)args)[15].v_handle);
  int32_t arg15_code = ((int32_t*)arg_type_ids)[(15)];
  void* arg16 = (((TVMValue*)args)[16].v_handle);
  int32_t arg16_code = ((int32_t*)arg_type_ids)[(16)];
  void* arg17 = (((TVMValue*)args)[17].v_handle);
  int32_t arg17_code = ((int32_t*)arg_type_ids)[(17)];
  void* arg18 = (((TVMValue*)args)[18].v_handle);
  int32_t arg18_code = ((int32_t*)arg_type_ids)[(18)];
  void* arg19 = (((TVMValue*)args)[19].v_handle);
  int32_t arg19_code = ((int32_t*)arg_type_ids)[(19)];
  void* arg20 = (((TVMValue*)args)[20].v_handle);
  int32_t arg20_code = ((int32_t*)arg_type_ids)[(20)];
  void* arg21 = (((TVMValue*)args)[21].v_handle);
  int32_t arg21_code = ((int32_t*)arg_type_ids)[(21)];
  void* arg22 = (((TVMValue*)args)[22].v_handle);
  int32_t arg22_code = ((int32_t*)arg_type_ids)[(22)];
  void* arg23 = (((TVMValue*)args)[23].v_handle);
  int32_t arg23_code = ((int32_t*)arg_type_ids)[(23)];
  void* arg24 = (((TVMValue*)args)[24].v_handle);
  int32_t arg24_code = ((int32_t*)arg_type_ids)[(24)];
  void* arg25 = (((TVMValue*)args)[25].v_handle);
  int32_t arg25_code = ((int32_t*)arg_type_ids)[(25)];
  void* arg26 = (((TVMValue*)args)[26].v_handle);
  int32_t arg26_code = ((int32_t*)arg_type_ids)[(26)];
  void* arg27 = (((TVMValue*)args)[27].v_handle);
  int32_t arg27_code = ((int32_t*)arg_type_ids)[(27)];
  void* arg28 = (((TVMValue*)args)[28].v_handle);
  int32_t arg28_code = ((int32_t*)arg_type_ids)[(28)];
  void* arg29 = (((TVMValue*)args)[29].v_handle);
  int32_t arg29_code = ((int32_t*)arg_type_ids)[(29)];
  void* arg30 = (((TVMValue*)args)[30].v_handle);
  int32_t arg30_code = ((int32_t*)arg_type_ids)[(30)];
  void* arg31 = (((TVMValue*)args)[31].v_handle);
  int32_t arg31_code = ((int32_t*)arg_type_ids)[(31)];
  void* arg32 = (((TVMValue*)args)[32].v_handle);
  int32_t arg32_code = ((int32_t*)arg_type_ids)[(32)];
  void* arg33 = (((TVMValue*)args)[33].v_handle);
  int32_t arg33_code = ((int32_t*)arg_type_ids)[(33)];
  void* arg34 = (((TVMValue*)args)[34].v_handle);
  int32_t arg34_code = ((int32_t*)arg_type_ids)[(34)];
  void* arg35 = (((TVMValue*)args)[35].v_handle);
  int32_t arg35_code = ((int32_t*)arg_type_ids)[(35)];
  void* arg36 = (((TVMValue*)args)[36].v_handle);
  int32_t arg36_code = ((int32_t*)arg_type_ids)[(36)];
  void* arg37 = (((TVMValue*)args)[37].v_handle);
  int32_t arg37_code = ((int32_t*)arg_type_ids)[(37)];
  void* arg38 = (((TVMValue*)args)[38].v_handle);
  int32_t arg38_code = ((int32_t*)arg_type_ids)[(38)];
  void* arg39 = (((TVMValue*)args)[39].v_handle);
  int32_t arg39_code = ((int32_t*)arg_type_ids)[(39)];
  void* arg40 = (((TVMValue*)args)[40].v_handle);
  int32_t arg40_code = ((int32_t*)arg_type_ids)[(40)];
  void* arg41 = (((TVMValue*)args)[41].v_handle);
  int32_t arg41_code = ((int32_t*)arg_type_ids)[(41)];
  void* arg42 = (((TVMValue*)args)[42].v_handle);
  int32_t arg42_code = ((int32_t*)arg_type_ids)[(42)];
  void* arg43 = (((TVMValue*)args)[43].v_handle);
  int32_t arg43_code = ((int32_t*)arg_type_ids)[(43)];
  void* arg44 = (((TVMValue*)args)[44].v_handle);
  int32_t arg44_code = ((int32_t*)arg_type_ids)[(44)];
  void* arg45 = (((TVMValue*)args)[45].v_handle);
  int32_t arg45_code = ((int32_t*)arg_type_ids)[(45)];
  void* arg46 = (((TVMValue*)args)[46].v_handle);
  int32_t arg46_code = ((int32_t*)arg_type_ids)[(46)];
  void* arg47 = (((TVMValue*)args)[47].v_handle);
  int32_t arg47_code = ((int32_t*)arg_type_ids)[(47)];
  void* arg48 = (((TVMValue*)args)[48].v_handle);
  int32_t arg48_code = ((int32_t*)arg_type_ids)[(48)];
  void* arg49 = (((TVMValue*)args)[49].v_handle);
  int32_t arg49_code = ((int32_t*)arg_type_ids)[(49)];
  void* arg50 = (((TVMValue*)args)[50].v_handle);
  int32_t arg50_code = ((int32_t*)arg_type_ids)[(50)];
  void* arg51 = (((TVMValue*)args)[51].v_handle);
  int32_t arg51_code = ((int32_t*)arg_type_ids)[(51)];
  void* arg52 = (((TVMValue*)args)[52].v_handle);
  int32_t arg52_code = ((int32_t*)arg_type_ids)[(52)];
  void* arg53 = (((TVMValue*)args)[53].v_handle);
  int32_t arg53_code = ((int32_t*)arg_type_ids)[(53)];
  void* arg54 = (((TVMValue*)args)[54].v_handle);
  int32_t arg54_code = ((int32_t*)arg_type_ids)[(54)];
  void* arg55 = (((TVMValue*)args)[55].v_handle);
  int32_t arg55_code = ((int32_t*)arg_type_ids)[(55)];
  void* arg56 = (((TVMValue*)args)[56].v_handle);
  int32_t arg56_code = ((int32_t*)arg_type_ids)[(56)];
  void* arg57 = (((TVMValue*)args)[57].v_handle);
  int32_t arg57_code = ((int32_t*)arg_type_ids)[(57)];
  void* arg58 = (((TVMValue*)args)[58].v_handle);
  int32_t arg58_code = ((int32_t*)arg_type_ids)[(58)];
  void* arg59 = (((TVMValue*)args)[59].v_handle);
  int32_t arg59_code = ((int32_t*)arg_type_ids)[(59)];
  void* arg60 = (((TVMValue*)args)[60].v_handle);
  int32_t arg60_code = ((int32_t*)arg_type_ids)[(60)];
  void* arg61 = (((TVMValue*)args)[61].v_handle);
  int32_t arg61_code = ((int32_t*)arg_type_ids)[(61)];
  void* arg62 = (((TVMValue*)args)[62].v_handle);
  int32_t arg62_code = ((int32_t*)arg_type_ids)[(62)];
  void* arg63 = (((TVMValue*)args)[63].v_handle);
  int32_t arg63_code = ((int32_t*)arg_type_ids)[(63)];
  void* arg64 = (((TVMValue*)args)[64].v_handle);
  int32_t arg64_code = ((int32_t*)arg_type_ids)[(64)];
  void* arg65 = (((TVMValue*)args)[65].v_handle);
  int32_t arg65_code = ((int32_t*)arg_type_ids)[(65)];
  void* arg66 = (((TVMValue*)args)[66].v_handle);
  int32_t arg66_code = ((int32_t*)arg_type_ids)[(66)];
  void* arg67 = (((TVMValue*)args)[67].v_handle);
  int32_t arg67_code = ((int32_t*)arg_type_ids)[(67)];
  void* arg68 = (((TVMValue*)args)[68].v_handle);
  int32_t arg68_code = ((int32_t*)arg_type_ids)[(68)];
  void* arg69 = (((TVMValue*)args)[69].v_handle);
  int32_t arg69_code = ((int32_t*)arg_type_ids)[(69)];
  void* arg70 = (((TVMValue*)args)[70].v_handle);
  int32_t arg70_code = ((int32_t*)arg_type_ids)[(70)];
  void* arg71 = (((TVMValue*)args)[71].v_handle);
  int32_t arg71_code = ((int32_t*)arg_type_ids)[(71)];
  void* arg72 = (((TVMValue*)args)[72].v_handle);
  int32_t arg72_code = ((int32_t*)arg_type_ids)[(72)];
  void* arg73 = (((TVMValue*)args)[73].v_handle);
  int32_t arg73_code = ((int32_t*)arg_type_ids)[(73)];
  void* arg74 = (((TVMValue*)args)[74].v_handle);
  int32_t arg74_code = ((int32_t*)arg_type_ids)[(74)];
  void* arg75 = (((TVMValue*)args)[75].v_handle);
  int32_t arg75_code = ((int32_t*)arg_type_ids)[(75)];
  void* arg76 = (((TVMValue*)args)[76].v_handle);
  int32_t arg76_code = ((int32_t*)arg_type_ids)[(76)];
  void* arg77 = (((TVMValue*)args)[77].v_handle);
  int32_t arg77_code = ((int32_t*)arg_type_ids)[(77)];
  void* arg78 = (((TVMValue*)args)[78].v_handle);
  int32_t arg78_code = ((int32_t*)arg_type_ids)[(78)];
  void* arg79 = (((TVMValue*)args)[79].v_handle);
  int32_t arg79_code = ((int32_t*)arg_type_ids)[(79)];
  void* arg80 = (((TVMValue*)args)[80].v_handle);
  int32_t arg80_code = ((int32_t*)arg_type_ids)[(80)];
  void* arg81 = (((TVMValue*)args)[81].v_handle);
  int32_t arg81_code = ((int32_t*)arg_type_ids)[(81)];
  void* arg82 = (((TVMValue*)args)[82].v_handle);
  int32_t arg82_code = ((int32_t*)arg_type_ids)[(82)];
  void* arg83 = (((TVMValue*)args)[83].v_handle);
  int32_t arg83_code = ((int32_t*)arg_type_ids)[(83)];
  void* arg84 = (((TVMValue*)args)[84].v_handle);
  int32_t arg84_code = ((int32_t*)arg_type_ids)[(84)];
  void* arg85 = (((TVMValue*)args)[85].v_handle);
  int32_t arg85_code = ((int32_t*)arg_type_ids)[(85)];
  void* arg86 = (((TVMValue*)args)[86].v_handle);
  int32_t arg86_code = ((int32_t*)arg_type_ids)[(86)];
  void* arg87 = (((TVMValue*)args)[87].v_handle);
  int32_t arg87_code = ((int32_t*)arg_type_ids)[(87)];
  void* arg88 = (((TVMValue*)args)[88].v_handle);
  int32_t arg88_code = ((int32_t*)arg_type_ids)[(88)];
  void* arg89 = (((TVMValue*)args)[89].v_handle);
  int32_t arg89_code = ((int32_t*)arg_type_ids)[(89)];
  void* arg90 = (((TVMValue*)args)[90].v_handle);
  int32_t arg90_code = ((int32_t*)arg_type_ids)[(90)];
  void* arg91 = (((TVMValue*)args)[91].v_handle);
  int32_t arg91_code = ((int32_t*)arg_type_ids)[(91)];
  void* arg92 = (((TVMValue*)args)[92].v_handle);
  int32_t arg92_code = ((int32_t*)arg_type_ids)[(92)];
  void* arg93 = (((TVMValue*)args)[93].v_handle);
  int32_t arg93_code = ((int32_t*)arg_type_ids)[(93)];
  void* arg94 = (((TVMValue*)args)[94].v_handle);
  int32_t arg94_code = ((int32_t*)arg_type_ids)[(94)];
  void* arg95 = (((TVMValue*)args)[95].v_handle);
  int32_t arg95_code = ((int32_t*)arg_type_ids)[(95)];
  void* arg96 = (((TVMValue*)args)[96].v_handle);
  int32_t arg96_code = ((int32_t*)arg_type_ids)[(96)];
  void* arg97 = (((TVMValue*)args)[97].v_handle);
  int32_t arg97_code = ((int32_t*)arg_type_ids)[(97)];
  void* arg98 = (((TVMValue*)args)[98].v_handle);
  int32_t arg98_code = ((int32_t*)arg_type_ids)[(98)];
  void* arg99 = (((TVMValue*)args)[99].v_handle);
  int32_t arg99_code = ((int32_t*)arg_type_ids)[(99)];
  void* arg100 = (((TVMValue*)args)[100].v_handle);
  int32_t arg100_code = ((int32_t*)arg_type_ids)[(100)];
  void* arg101 = (((TVMValue*)args)[101].v_handle);
  int32_t arg101_code = ((int32_t*)arg_type_ids)[(101)];
  void* arg102 = (((TVMValue*)args)[102].v_handle);
  int32_t arg102_code = ((int32_t*)arg_type_ids)[(102)];
  void* arg103 = (((TVMValue*)args)[103].v_handle);
  int32_t arg103_code = ((int32_t*)arg_type_ids)[(103)];
  void* arg104 = (((TVMValue*)args)[104].v_handle);
  int32_t arg104_code = ((int32_t*)arg_type_ids)[(104)];
  void* arg105 = (((TVMValue*)args)[105].v_handle);
  int32_t arg105_code = ((int32_t*)arg_type_ids)[(105)];
  void* arg106 = (((TVMValue*)args)[106].v_handle);
  int32_t arg106_code = ((int32_t*)arg_type_ids)[(106)];
  void* arg107 = (((TVMValue*)args)[107].v_handle);
  int32_t arg107_code = ((int32_t*)arg_type_ids)[(107)];
  void* arg108 = (((TVMValue*)args)[108].v_handle);
  int32_t arg108_code = ((int32_t*)arg_type_ids)[(108)];
  void* arg109 = (((TVMValue*)args)[109].v_handle);
  int32_t arg109_code = ((int32_t*)arg_type_ids)[(109)];
  void* arg110 = (((TVMValue*)args)[110].v_handle);
  int32_t arg110_code = ((int32_t*)arg_type_ids)[(110)];
  void* arg111 = (((TVMValue*)args)[111].v_handle);
  int32_t arg111_code = ((int32_t*)arg_type_ids)[(111)];
  void* arg112 = (((TVMValue*)args)[112].v_handle);
  int32_t arg112_code = ((int32_t*)arg_type_ids)[(112)];
  void* arg113 = (((TVMValue*)args)[113].v_handle);
  int32_t arg113_code = ((int32_t*)arg_type_ids)[(113)];
  void* arg114 = (((TVMValue*)args)[114].v_handle);
  int32_t arg114_code = ((int32_t*)arg_type_ids)[(114)];
  void* arg115 = (((TVMValue*)args)[115].v_handle);
  int32_t arg115_code = ((int32_t*)arg_type_ids)[(115)];
  void* arg116 = (((TVMValue*)args)[116].v_handle);
  int32_t arg116_code = ((int32_t*)arg_type_ids)[(116)];
  void* arg117 = (((TVMValue*)args)[117].v_handle);
  int32_t arg117_code = ((int32_t*)arg_type_ids)[(117)];
  void* arg118 = (((TVMValue*)args)[118].v_handle);
  int32_t arg118_code = ((int32_t*)arg_type_ids)[(118)];
  void* arg119 = (((TVMValue*)args)[119].v_handle);
  int32_t arg119_code = ((int32_t*)arg_type_ids)[(119)];
  void* arg120 = (((TVMValue*)args)[120].v_handle);
  int32_t arg120_code = ((int32_t*)arg_type_ids)[(120)];
  void* arg121 = (((TVMValue*)args)[121].v_handle);
  int32_t arg121_code = ((int32_t*)arg_type_ids)[(121)];
  void* arg122 = (((TVMValue*)args)[122].v_handle);
  int32_t arg122_code = ((int32_t*)arg_type_ids)[(122)];
  void* arg123 = (((TVMValue*)args)[123].v_handle);
  int32_t arg123_code = ((int32_t*)arg_type_ids)[(123)];
  void* arg124 = (((TVMValue*)args)[124].v_handle);
  int32_t arg124_code = ((int32_t*)arg_type_ids)[(124)];
  void* arg125 = (((TVMValue*)args)[125].v_handle);
  int32_t arg125_code = ((int32_t*)arg_type_ids)[(125)];
  void* arg126 = (((TVMValue*)args)[126].v_handle);
  int32_t arg126_code = ((int32_t*)arg_type_ids)[(126)];
  void* arg127 = (((TVMValue*)args)[127].v_handle);
  int32_t arg127_code = ((int32_t*)arg_type_ids)[(127)];
  void* arg128 = (((TVMValue*)args)[128].v_handle);
  int32_t arg128_code = ((int32_t*)arg_type_ids)[(128)];
  void* arg129 = (((TVMValue*)args)[129].v_handle);
  int32_t arg129_code = ((int32_t*)arg_type_ids)[(129)];
  void* arg130 = (((TVMValue*)args)[130].v_handle);
  int32_t arg130_code = ((int32_t*)arg_type_ids)[(130)];
  void* arg131 = (((TVMValue*)args)[131].v_handle);
  int32_t arg131_code = ((int32_t*)arg_type_ids)[(131)];
  void* arg132 = (((TVMValue*)args)[132].v_handle);
  int32_t arg132_code = ((int32_t*)arg_type_ids)[(132)];
  void* arg133 = (((TVMValue*)args)[133].v_handle);
  int32_t arg133_code = ((int32_t*)arg_type_ids)[(133)];
  void* arg134 = (((TVMValue*)args)[134].v_handle);
  int32_t arg134_code = ((int32_t*)arg_type_ids)[(134)];
  void* arg135 = (((TVMValue*)args)[135].v_handle);
  int32_t arg135_code = ((int32_t*)arg_type_ids)[(135)];
  void* arg136 = (((TVMValue*)args)[136].v_handle);
  int32_t arg136_code = ((int32_t*)arg_type_ids)[(136)];
  void* arg137 = (((TVMValue*)args)[137].v_handle);
  int32_t arg137_code = ((int32_t*)arg_type_ids)[(137)];
  void* arg138 = (((TVMValue*)args)[138].v_handle);
  int32_t arg138_code = ((int32_t*)arg_type_ids)[(138)];
  void* arg139 = (((TVMValue*)args)[139].v_handle);
  int32_t arg139_code = ((int32_t*)arg_type_ids)[(139)];
  void* arg140 = (((TVMValue*)args)[140].v_handle);
  int32_t arg140_code = ((int32_t*)arg_type_ids)[(140)];
  void* arg141 = (((TVMValue*)args)[141].v_handle);
  int32_t arg141_code = ((int32_t*)arg_type_ids)[(141)];
  void* arg142 = (((TVMValue*)args)[142].v_handle);
  int32_t arg142_code = ((int32_t*)arg_type_ids)[(142)];
  void* arg143 = (((TVMValue*)args)[143].v_handle);
  int32_t arg143_code = ((int32_t*)arg_type_ids)[(143)];
  void* arg144 = (((TVMValue*)args)[144].v_handle);
  int32_t arg144_code = ((int32_t*)arg_type_ids)[(144)];
  void* arg145 = (((TVMValue*)args)[145].v_handle);
  int32_t arg145_code = ((int32_t*)arg_type_ids)[(145)];
  void* arg146 = (((TVMValue*)args)[146].v_handle);
  int32_t arg146_code = ((int32_t*)arg_type_ids)[(146)];
  void* arg147 = (((TVMValue*)args)[147].v_handle);
  int32_t arg147_code = ((int32_t*)arg_type_ids)[(147)];
  void* arg148 = (((TVMValue*)args)[148].v_handle);
  int32_t arg148_code = ((int32_t*)arg_type_ids)[(148)];
  void* arg149 = (((TVMValue*)args)[149].v_handle);
  int32_t arg149_code = ((int32_t*)arg_type_ids)[(149)];
  void* arg150 = (((TVMValue*)args)[150].v_handle);
  int32_t arg150_code = ((int32_t*)arg_type_ids)[(150)];
  void* arg151 = (((TVMValue*)args)[151].v_handle);
  int32_t arg151_code = ((int32_t*)arg_type_ids)[(151)];
  void* arg152 = (((TVMValue*)args)[152].v_handle);
  int32_t arg152_code = ((int32_t*)arg_type_ids)[(152)];
  void* arg153 = (((TVMValue*)args)[153].v_handle);
  int32_t arg153_code = ((int32_t*)arg_type_ids)[(153)];
  void* arg154 = (((TVMValue*)args)[154].v_handle);
  int32_t arg154_code = ((int32_t*)arg_type_ids)[(154)];
  void* arg155 = (((TVMValue*)args)[155].v_handle);
  int32_t arg155_code = ((int32_t*)arg_type_ids)[(155)];
  void* arg156 = (((TVMValue*)args)[156].v_handle);
  int32_t arg156_code = ((int32_t*)arg_type_ids)[(156)];
  void* arg157 = (((TVMValue*)args)[157].v_handle);
  int32_t arg157_code = ((int32_t*)arg_type_ids)[(157)];
  void* input_data = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* kernel_1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* tensor_1 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* kernel_9 = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  void* tensor_11 = (((DLTensor*)arg4)[0].data);
  void* arg4_shape = (((DLTensor*)arg4)[0].shape);
  void* arg4_strides = (((DLTensor*)arg4)[0].strides);
  void* tensor_12 = (((DLTensor*)arg5)[0].data);
  void* arg5_shape = (((DLTensor*)arg5)[0].shape);
  void* arg5_strides = (((DLTensor*)arg5)[0].strides);
  void* kernel_19 = (((DLTensor*)arg6)[0].data);
  void* arg6_shape = (((DLTensor*)arg6)[0].shape);
  void* arg6_strides = (((DLTensor*)arg6)[0].strides);
  void* tensor_20 = (((DLTensor*)arg7)[0].data);
  void* arg7_shape = (((DLTensor*)arg7)[0].shape);
  void* arg7_strides = (((DLTensor*)arg7)[0].strides);
  void* kernel_27 = (((DLTensor*)arg8)[0].data);
  void* arg8_shape = (((DLTensor*)arg8)[0].shape);
  void* arg8_strides = (((DLTensor*)arg8)[0].strides);
  void* tensor_29 = (((DLTensor*)arg9)[0].data);
  void* arg9_shape = (((DLTensor*)arg9)[0].shape);
  void* arg9_strides = (((DLTensor*)arg9)[0].strides);
  void* tensor_36 = (((DLTensor*)arg10)[0].data);
  void* arg10_shape = (((DLTensor*)arg10)[0].shape);
  void* arg10_strides = (((DLTensor*)arg10)[0].strides);
  void* tensor_37 = (((DLTensor*)arg11)[0].data);
  void* arg11_shape = (((DLTensor*)arg11)[0].shape);
  void* arg11_strides = (((DLTensor*)arg11)[0].strides);
  void* kernel_48 = (((DLTensor*)arg12)[0].data);
  void* arg12_shape = (((DLTensor*)arg12)[0].shape);
  void* arg12_strides = (((DLTensor*)arg12)[0].strides);
  void* tensor_49 = (((DLTensor*)arg13)[0].data);
  void* arg13_shape = (((DLTensor*)arg13)[0].shape);
  void* arg13_strides = (((DLTensor*)arg13)[0].strides);
  void* kernel_62 = (((DLTensor*)arg14)[0].data);
  void* arg14_shape = (((DLTensor*)arg14)[0].shape);
  void* arg14_strides = (((DLTensor*)arg14)[0].strides);
  void* tensor_64 = (((DLTensor*)arg15)[0].data);
  void* arg15_shape = (((DLTensor*)arg15)[0].shape);
  void* arg15_strides = (((DLTensor*)arg15)[0].strides);
  void* tensor_65 = (((DLTensor*)arg16)[0].data);
  void* arg16_shape = (((DLTensor*)arg16)[0].shape);
  void* arg16_strides = (((DLTensor*)arg16)[0].strides);
  void* kernel_72 = (((DLTensor*)arg17)[0].data);
  void* arg17_shape = (((DLTensor*)arg17)[0].shape);
  void* arg17_strides = (((DLTensor*)arg17)[0].strides);
  void* tensor_73 = (((DLTensor*)arg18)[0].data);
  void* arg18_shape = (((DLTensor*)arg18)[0].shape);
  void* arg18_strides = (((DLTensor*)arg18)[0].strides);
  void* kernel_80 = (((DLTensor*)arg19)[0].data);
  void* arg19_shape = (((DLTensor*)arg19)[0].shape);
  void* arg19_strides = (((DLTensor*)arg19)[0].strides);
  void* tensor_82 = (((DLTensor*)arg20)[0].data);
  void* arg20_shape = (((DLTensor*)arg20)[0].shape);
  void* arg20_strides = (((DLTensor*)arg20)[0].strides);
  void* tensor_89 = (((DLTensor*)arg21)[0].data);
  void* arg21_shape = (((DLTensor*)arg21)[0].shape);
  void* arg21_strides = (((DLTensor*)arg21)[0].strides);
  void* tensor_90 = (((DLTensor*)arg22)[0].data);
  void* arg22_shape = (((DLTensor*)arg22)[0].shape);
  void* arg22_strides = (((DLTensor*)arg22)[0].strides);
  void* kernel_105 = (((DLTensor*)arg23)[0].data);
  void* arg23_shape = (((DLTensor*)arg23)[0].shape);
  void* arg23_strides = (((DLTensor*)arg23)[0].strides);
  void* tensor_107 = (((DLTensor*)arg24)[0].data);
  void* arg24_shape = (((DLTensor*)arg24)[0].shape);
  void* arg24_strides = (((DLTensor*)arg24)[0].strides);
  void* tensor_108 = (((DLTensor*)arg25)[0].data);
  void* arg25_shape = (((DLTensor*)arg25)[0].shape);
  void* arg25_strides = (((DLTensor*)arg25)[0].strides);
  void* kernel_115 = (((DLTensor*)arg26)[0].data);
  void* arg26_shape = (((DLTensor*)arg26)[0].shape);
  void* arg26_strides = (((DLTensor*)arg26)[0].strides);
  void* tensor_116 = (((DLTensor*)arg27)[0].data);
  void* arg27_shape = (((DLTensor*)arg27)[0].shape);
  void* arg27_strides = (((DLTensor*)arg27)[0].strides);
  void* kernel_123 = (((DLTensor*)arg28)[0].data);
  void* arg28_shape = (((DLTensor*)arg28)[0].shape);
  void* arg28_strides = (((DLTensor*)arg28)[0].strides);
  void* tensor_125 = (((DLTensor*)arg29)[0].data);
  void* arg29_shape = (((DLTensor*)arg29)[0].shape);
  void* arg29_strides = (((DLTensor*)arg29)[0].strides);
  void* tensor_132 = (((DLTensor*)arg30)[0].data);
  void* arg30_shape = (((DLTensor*)arg30)[0].shape);
  void* arg30_strides = (((DLTensor*)arg30)[0].strides);
  void* tensor_133 = (((DLTensor*)arg31)[0].data);
  void* arg31_shape = (((DLTensor*)arg31)[0].shape);
  void* arg31_strides = (((DLTensor*)arg31)[0].strides);
  void* kernel_148 = (((DLTensor*)arg32)[0].data);
  void* arg32_shape = (((DLTensor*)arg32)[0].shape);
  void* arg32_strides = (((DLTensor*)arg32)[0].strides);
  void* tensor_150 = (((DLTensor*)arg33)[0].data);
  void* arg33_shape = (((DLTensor*)arg33)[0].shape);
  void* arg33_strides = (((DLTensor*)arg33)[0].strides);
  void* tensor_151 = (((DLTensor*)arg34)[0].data);
  void* arg34_shape = (((DLTensor*)arg34)[0].shape);
  void* arg34_strides = (((DLTensor*)arg34)[0].strides);
  void* kernel_158 = (((DLTensor*)arg35)[0].data);
  void* arg35_shape = (((DLTensor*)arg35)[0].shape);
  void* arg35_strides = (((DLTensor*)arg35)[0].strides);
  void* tensor_159 = (((DLTensor*)arg36)[0].data);
  void* arg36_shape = (((DLTensor*)arg36)[0].shape);
  void* arg36_strides = (((DLTensor*)arg36)[0].strides);
  void* kernel_166 = (((DLTensor*)arg37)[0].data);
  void* arg37_shape = (((DLTensor*)arg37)[0].shape);
  void* arg37_strides = (((DLTensor*)arg37)[0].strides);
  void* tensor_168 = (((DLTensor*)arg38)[0].data);
  void* arg38_shape = (((DLTensor*)arg38)[0].shape);
  void* arg38_strides = (((DLTensor*)arg38)[0].strides);
  void* tensor_175 = (((DLTensor*)arg39)[0].data);
  void* arg39_shape = (((DLTensor*)arg39)[0].shape);
  void* arg39_strides = (((DLTensor*)arg39)[0].strides);
  void* tensor_176 = (((DLTensor*)arg40)[0].data);
  void* arg40_shape = (((DLTensor*)arg40)[0].shape);
  void* arg40_strides = (((DLTensor*)arg40)[0].strides);
  void* kernel_184 = (((DLTensor*)arg41)[0].data);
  void* arg41_shape = (((DLTensor*)arg41)[0].shape);
  void* arg41_strides = (((DLTensor*)arg41)[0].strides);
  void* tensor_185 = (((DLTensor*)arg42)[0].data);
  void* arg42_shape = (((DLTensor*)arg42)[0].shape);
  void* arg42_strides = (((DLTensor*)arg42)[0].strides);
  void* kernel_198 = (((DLTensor*)arg43)[0].data);
  void* arg43_shape = (((DLTensor*)arg43)[0].shape);
  void* arg43_strides = (((DLTensor*)arg43)[0].strides);
  void* tensor_200 = (((DLTensor*)arg44)[0].data);
  void* arg44_shape = (((DLTensor*)arg44)[0].shape);
  void* arg44_strides = (((DLTensor*)arg44)[0].strides);
  void* tensor_201 = (((DLTensor*)arg45)[0].data);
  void* arg45_shape = (((DLTensor*)arg45)[0].shape);
  void* arg45_strides = (((DLTensor*)arg45)[0].strides);
  void* kernel_208 = (((DLTensor*)arg46)[0].data);
  void* arg46_shape = (((DLTensor*)arg46)[0].shape);
  void* arg46_strides = (((DLTensor*)arg46)[0].strides);
  void* tensor_209 = (((DLTensor*)arg47)[0].data);
  void* arg47_shape = (((DLTensor*)arg47)[0].shape);
  void* arg47_strides = (((DLTensor*)arg47)[0].strides);
  void* kernel_216 = (((DLTensor*)arg48)[0].data);
  void* arg48_shape = (((DLTensor*)arg48)[0].shape);
  void* arg48_strides = (((DLTensor*)arg48)[0].strides);
  void* tensor_218 = (((DLTensor*)arg49)[0].data);
  void* arg49_shape = (((DLTensor*)arg49)[0].shape);
  void* arg49_strides = (((DLTensor*)arg49)[0].strides);
  void* tensor_225 = (((DLTensor*)arg50)[0].data);
  void* arg50_shape = (((DLTensor*)arg50)[0].shape);
  void* arg50_strides = (((DLTensor*)arg50)[0].strides);
  void* tensor_226 = (((DLTensor*)arg51)[0].data);
  void* arg51_shape = (((DLTensor*)arg51)[0].shape);
  void* arg51_strides = (((DLTensor*)arg51)[0].strides);
  void* kernel_241 = (((DLTensor*)arg52)[0].data);
  void* arg52_shape = (((DLTensor*)arg52)[0].shape);
  void* arg52_strides = (((DLTensor*)arg52)[0].strides);
  void* tensor_243 = (((DLTensor*)arg53)[0].data);
  void* arg53_shape = (((DLTensor*)arg53)[0].shape);
  void* arg53_strides = (((DLTensor*)arg53)[0].strides);
  void* tensor_244 = (((DLTensor*)arg54)[0].data);
  void* arg54_shape = (((DLTensor*)arg54)[0].shape);
  void* arg54_strides = (((DLTensor*)arg54)[0].strides);
  void* kernel_251 = (((DLTensor*)arg55)[0].data);
  void* arg55_shape = (((DLTensor*)arg55)[0].shape);
  void* arg55_strides = (((DLTensor*)arg55)[0].strides);
  void* tensor_252 = (((DLTensor*)arg56)[0].data);
  void* arg56_shape = (((DLTensor*)arg56)[0].shape);
  void* arg56_strides = (((DLTensor*)arg56)[0].strides);
  void* kernel_259 = (((DLTensor*)arg57)[0].data);
  void* arg57_shape = (((DLTensor*)arg57)[0].shape);
  void* arg57_strides = (((DLTensor*)arg57)[0].strides);
  void* tensor_261 = (((DLTensor*)arg58)[0].data);
  void* arg58_shape = (((DLTensor*)arg58)[0].shape);
  void* arg58_strides = (((DLTensor*)arg58)[0].strides);
  void* tensor_268 = (((DLTensor*)arg59)[0].data);
  void* arg59_shape = (((DLTensor*)arg59)[0].shape);
  void* arg59_strides = (((DLTensor*)arg59)[0].strides);
  void* tensor_269 = (((DLTensor*)arg60)[0].data);
  void* arg60_shape = (((DLTensor*)arg60)[0].shape);
  void* arg60_strides = (((DLTensor*)arg60)[0].strides);
  void* kernel_284 = (((DLTensor*)arg61)[0].data);
  void* arg61_shape = (((DLTensor*)arg61)[0].shape);
  void* arg61_strides = (((DLTensor*)arg61)[0].strides);
  void* tensor_286 = (((DLTensor*)arg62)[0].data);
  void* arg62_shape = (((DLTensor*)arg62)[0].shape);
  void* arg62_strides = (((DLTensor*)arg62)[0].strides);
  void* tensor_287 = (((DLTensor*)arg63)[0].data);
  void* arg63_shape = (((DLTensor*)arg63)[0].shape);
  void* arg63_strides = (((DLTensor*)arg63)[0].strides);
  void* kernel_294 = (((DLTensor*)arg64)[0].data);
  void* arg64_shape = (((DLTensor*)arg64)[0].shape);
  void* arg64_strides = (((DLTensor*)arg64)[0].strides);
  void* tensor_295 = (((DLTensor*)arg65)[0].data);
  void* arg65_shape = (((DLTensor*)arg65)[0].shape);
  void* arg65_strides = (((DLTensor*)arg65)[0].strides);
  void* kernel_302 = (((DLTensor*)arg66)[0].data);
  void* arg66_shape = (((DLTensor*)arg66)[0].shape);
  void* arg66_strides = (((DLTensor*)arg66)[0].strides);
  void* tensor_304 = (((DLTensor*)arg67)[0].data);
  void* arg67_shape = (((DLTensor*)arg67)[0].shape);
  void* arg67_strides = (((DLTensor*)arg67)[0].strides);
  void* tensor_311 = (((DLTensor*)arg68)[0].data);
  void* arg68_shape = (((DLTensor*)arg68)[0].shape);
  void* arg68_strides = (((DLTensor*)arg68)[0].strides);
  void* tensor_312 = (((DLTensor*)arg69)[0].data);
  void* arg69_shape = (((DLTensor*)arg69)[0].shape);
  void* arg69_strides = (((DLTensor*)arg69)[0].strides);
  void* kernel_327 = (((DLTensor*)arg70)[0].data);
  void* arg70_shape = (((DLTensor*)arg70)[0].shape);
  void* arg70_strides = (((DLTensor*)arg70)[0].strides);
  void* tensor_329 = (((DLTensor*)arg71)[0].data);
  void* arg71_shape = (((DLTensor*)arg71)[0].shape);
  void* arg71_strides = (((DLTensor*)arg71)[0].strides);
  void* tensor_330 = (((DLTensor*)arg72)[0].data);
  void* arg72_shape = (((DLTensor*)arg72)[0].shape);
  void* arg72_strides = (((DLTensor*)arg72)[0].strides);
  void* kernel_337 = (((DLTensor*)arg73)[0].data);
  void* arg73_shape = (((DLTensor*)arg73)[0].shape);
  void* arg73_strides = (((DLTensor*)arg73)[0].strides);
  void* tensor_338 = (((DLTensor*)arg74)[0].data);
  void* arg74_shape = (((DLTensor*)arg74)[0].shape);
  void* arg74_strides = (((DLTensor*)arg74)[0].strides);
  void* kernel_345 = (((DLTensor*)arg75)[0].data);
  void* arg75_shape = (((DLTensor*)arg75)[0].shape);
  void* arg75_strides = (((DLTensor*)arg75)[0].strides);
  void* tensor_347 = (((DLTensor*)arg76)[0].data);
  void* arg76_shape = (((DLTensor*)arg76)[0].shape);
  void* arg76_strides = (((DLTensor*)arg76)[0].strides);
  void* tensor_354 = (((DLTensor*)arg77)[0].data);
  void* arg77_shape = (((DLTensor*)arg77)[0].shape);
  void* arg77_strides = (((DLTensor*)arg77)[0].strides);
  void* tensor_355 = (((DLTensor*)arg78)[0].data);
  void* arg78_shape = (((DLTensor*)arg78)[0].shape);
  void* arg78_strides = (((DLTensor*)arg78)[0].strides);
  void* kernel_363 = (((DLTensor*)arg79)[0].data);
  void* arg79_shape = (((DLTensor*)arg79)[0].shape);
  void* arg79_strides = (((DLTensor*)arg79)[0].strides);
  void* tensor_364 = (((DLTensor*)arg80)[0].data);
  void* arg80_shape = (((DLTensor*)arg80)[0].shape);
  void* arg80_strides = (((DLTensor*)arg80)[0].strides);
  void* kernel_377 = (((DLTensor*)arg81)[0].data);
  void* arg81_shape = (((DLTensor*)arg81)[0].shape);
  void* arg81_strides = (((DLTensor*)arg81)[0].strides);
  void* tensor_379 = (((DLTensor*)arg82)[0].data);
  void* arg82_shape = (((DLTensor*)arg82)[0].shape);
  void* arg82_strides = (((DLTensor*)arg82)[0].strides);
  void* tensor_380 = (((DLTensor*)arg83)[0].data);
  void* arg83_shape = (((DLTensor*)arg83)[0].shape);
  void* arg83_strides = (((DLTensor*)arg83)[0].strides);
  void* kernel_387 = (((DLTensor*)arg84)[0].data);
  void* arg84_shape = (((DLTensor*)arg84)[0].shape);
  void* arg84_strides = (((DLTensor*)arg84)[0].strides);
  void* tensor_388 = (((DLTensor*)arg85)[0].data);
  void* arg85_shape = (((DLTensor*)arg85)[0].shape);
  void* arg85_strides = (((DLTensor*)arg85)[0].strides);
  void* kernel_395 = (((DLTensor*)arg86)[0].data);
  void* arg86_shape = (((DLTensor*)arg86)[0].shape);
  void* arg86_strides = (((DLTensor*)arg86)[0].strides);
  void* tensor_397 = (((DLTensor*)arg87)[0].data);
  void* arg87_shape = (((DLTensor*)arg87)[0].shape);
  void* arg87_strides = (((DLTensor*)arg87)[0].strides);
  void* tensor_404 = (((DLTensor*)arg88)[0].data);
  void* arg88_shape = (((DLTensor*)arg88)[0].shape);
  void* arg88_strides = (((DLTensor*)arg88)[0].strides);
  void* tensor_405 = (((DLTensor*)arg89)[0].data);
  void* arg89_shape = (((DLTensor*)arg89)[0].shape);
  void* arg89_strides = (((DLTensor*)arg89)[0].strides);
  void* kernel_420 = (((DLTensor*)arg90)[0].data);
  void* arg90_shape = (((DLTensor*)arg90)[0].shape);
  void* arg90_strides = (((DLTensor*)arg90)[0].strides);
  void* tensor_422 = (((DLTensor*)arg91)[0].data);
  void* arg91_shape = (((DLTensor*)arg91)[0].shape);
  void* arg91_strides = (((DLTensor*)arg91)[0].strides);
  void* tensor_423 = (((DLTensor*)arg92)[0].data);
  void* arg92_shape = (((DLTensor*)arg92)[0].shape);
  void* arg92_strides = (((DLTensor*)arg92)[0].strides);
  void* kernel_430 = (((DLTensor*)arg93)[0].data);
  void* arg93_shape = (((DLTensor*)arg93)[0].shape);
  void* arg93_strides = (((DLTensor*)arg93)[0].strides);
  void* tensor_431 = (((DLTensor*)arg94)[0].data);
  void* arg94_shape = (((DLTensor*)arg94)[0].shape);
  void* arg94_strides = (((DLTensor*)arg94)[0].strides);
  void* kernel_438 = (((DLTensor*)arg95)[0].data);
  void* arg95_shape = (((DLTensor*)arg95)[0].shape);
  void* arg95_strides = (((DLTensor*)arg95)[0].strides);
  void* tensor_440 = (((DLTensor*)arg96)[0].data);
  void* arg96_shape = (((DLTensor*)arg96)[0].shape);
  void* arg96_strides = (((DLTensor*)arg96)[0].strides);
  void* tensor_447 = (((DLTensor*)arg97)[0].data);
  void* arg97_shape = (((DLTensor*)arg97)[0].shape);
  void* arg97_strides = (((DLTensor*)arg97)[0].strides);
  void* tensor_448 = (((DLTensor*)arg98)[0].data);
  void* arg98_shape = (((DLTensor*)arg98)[0].shape);
  void* arg98_strides = (((DLTensor*)arg98)[0].strides);
  void* kernel_463 = (((DLTensor*)arg99)[0].data);
  void* arg99_shape = (((DLTensor*)arg99)[0].shape);
  void* arg99_strides = (((DLTensor*)arg99)[0].strides);
  void* tensor_465 = (((DLTensor*)arg100)[0].data);
  void* arg100_shape = (((DLTensor*)arg100)[0].shape);
  void* arg100_strides = (((DLTensor*)arg100)[0].strides);
  void* tensor_466 = (((DLTensor*)arg101)[0].data);
  void* arg101_shape = (((DLTensor*)arg101)[0].shape);
  void* arg101_strides = (((DLTensor*)arg101)[0].strides);
  void* kernel_473 = (((DLTensor*)arg102)[0].data);
  void* arg102_shape = (((DLTensor*)arg102)[0].shape);
  void* arg102_strides = (((DLTensor*)arg102)[0].strides);
  void* tensor_474 = (((DLTensor*)arg103)[0].data);
  void* arg103_shape = (((DLTensor*)arg103)[0].shape);
  void* arg103_strides = (((DLTensor*)arg103)[0].strides);
  void* kernel_481 = (((DLTensor*)arg104)[0].data);
  void* arg104_shape = (((DLTensor*)arg104)[0].shape);
  void* arg104_strides = (((DLTensor*)arg104)[0].strides);
  void* tensor_483 = (((DLTensor*)arg105)[0].data);
  void* arg105_shape = (((DLTensor*)arg105)[0].shape);
  void* arg105_strides = (((DLTensor*)arg105)[0].strides);
  void* tensor_490 = (((DLTensor*)arg106)[0].data);
  void* arg106_shape = (((DLTensor*)arg106)[0].shape);
  void* arg106_strides = (((DLTensor*)arg106)[0].strides);
  void* tensor_491 = (((DLTensor*)arg107)[0].data);
  void* arg107_shape = (((DLTensor*)arg107)[0].shape);
  void* arg107_strides = (((DLTensor*)arg107)[0].strides);
  void* kernel_506 = (((DLTensor*)arg108)[0].data);
  void* arg108_shape = (((DLTensor*)arg108)[0].shape);
  void* arg108_strides = (((DLTensor*)arg108)[0].strides);
  void* tensor_508 = (((DLTensor*)arg109)[0].data);
  void* arg109_shape = (((DLTensor*)arg109)[0].shape);
  void* arg109_strides = (((DLTensor*)arg109)[0].strides);
  void* tensor_509 = (((DLTensor*)arg110)[0].data);
  void* arg110_shape = (((DLTensor*)arg110)[0].shape);
  void* arg110_strides = (((DLTensor*)arg110)[0].strides);
  void* kernel_516 = (((DLTensor*)arg111)[0].data);
  void* arg111_shape = (((DLTensor*)arg111)[0].shape);
  void* arg111_strides = (((DLTensor*)arg111)[0].strides);
  void* tensor_517 = (((DLTensor*)arg112)[0].data);
  void* arg112_shape = (((DLTensor*)arg112)[0].shape);
  void* arg112_strides = (((DLTensor*)arg112)[0].strides);
  void* kernel_524 = (((DLTensor*)arg113)[0].data);
  void* arg113_shape = (((DLTensor*)arg113)[0].shape);
  void* arg113_strides = (((DLTensor*)arg113)[0].strides);
  void* tensor_526 = (((DLTensor*)arg114)[0].data);
  void* arg114_shape = (((DLTensor*)arg114)[0].shape);
  void* arg114_strides = (((DLTensor*)arg114)[0].strides);
  void* tensor_533 = (((DLTensor*)arg115)[0].data);
  void* arg115_shape = (((DLTensor*)arg115)[0].shape);
  void* arg115_strides = (((DLTensor*)arg115)[0].strides);
  void* tensor_534 = (((DLTensor*)arg116)[0].data);
  void* arg116_shape = (((DLTensor*)arg116)[0].shape);
  void* arg116_strides = (((DLTensor*)arg116)[0].strides);
  void* kernel_549 = (((DLTensor*)arg117)[0].data);
  void* arg117_shape = (((DLTensor*)arg117)[0].shape);
  void* arg117_strides = (((DLTensor*)arg117)[0].strides);
  void* tensor_551 = (((DLTensor*)arg118)[0].data);
  void* arg118_shape = (((DLTensor*)arg118)[0].shape);
  void* arg118_strides = (((DLTensor*)arg118)[0].strides);
  void* tensor_552 = (((DLTensor*)arg119)[0].data);
  void* arg119_shape = (((DLTensor*)arg119)[0].shape);
  void* arg119_strides = (((DLTensor*)arg119)[0].strides);
  void* kernel_559 = (((DLTensor*)arg120)[0].data);
  void* arg120_shape = (((DLTensor*)arg120)[0].shape);
  void* arg120_strides = (((DLTensor*)arg120)[0].strides);
  void* tensor_560 = (((DLTensor*)arg121)[0].data);
  void* arg121_shape = (((DLTensor*)arg121)[0].shape);
  void* arg121_strides = (((DLTensor*)arg121)[0].strides);
  void* kernel_567 = (((DLTensor*)arg122)[0].data);
  void* arg122_shape = (((DLTensor*)arg122)[0].shape);
  void* arg122_strides = (((DLTensor*)arg122)[0].strides);
  void* tensor_569 = (((DLTensor*)arg123)[0].data);
  void* arg123_shape = (((DLTensor*)arg123)[0].shape);
  void* arg123_strides = (((DLTensor*)arg123)[0].strides);
  void* tensor_576 = (((DLTensor*)arg124)[0].data);
  void* arg124_shape = (((DLTensor*)arg124)[0].shape);
  void* arg124_strides = (((DLTensor*)arg124)[0].strides);
  void* tensor_577 = (((DLTensor*)arg125)[0].data);
  void* arg125_shape = (((DLTensor*)arg125)[0].shape);
  void* arg125_strides = (((DLTensor*)arg125)[0].strides);
  void* kernel_592 = (((DLTensor*)arg126)[0].data);
  void* arg126_shape = (((DLTensor*)arg126)[0].shape);
  void* arg126_strides = (((DLTensor*)arg126)[0].strides);
  void* tensor_594 = (((DLTensor*)arg127)[0].data);
  void* arg127_shape = (((DLTensor*)arg127)[0].shape);
  void* arg127_strides = (((DLTensor*)arg127)[0].strides);
  void* tensor_595 = (((DLTensor*)arg128)[0].data);
  void* arg128_shape = (((DLTensor*)arg128)[0].shape);
  void* arg128_strides = (((DLTensor*)arg128)[0].strides);
  void* kernel_602 = (((DLTensor*)arg129)[0].data);
  void* arg129_shape = (((DLTensor*)arg129)[0].shape);
  void* arg129_strides = (((DLTensor*)arg129)[0].strides);
  void* tensor_603 = (((DLTensor*)arg130)[0].data);
  void* arg130_shape = (((DLTensor*)arg130)[0].shape);
  void* arg130_strides = (((DLTensor*)arg130)[0].strides);
  void* kernel_610 = (((DLTensor*)arg131)[0].data);
  void* arg131_shape = (((DLTensor*)arg131)[0].shape);
  void* arg131_strides = (((DLTensor*)arg131)[0].strides);
  void* tensor_612 = (((DLTensor*)arg132)[0].data);
  void* arg132_shape = (((DLTensor*)arg132)[0].shape);
  void* arg132_strides = (((DLTensor*)arg132)[0].strides);
  void* tensor_619 = (((DLTensor*)arg133)[0].data);
  void* arg133_shape = (((DLTensor*)arg133)[0].shape);
  void* arg133_strides = (((DLTensor*)arg133)[0].strides);
  void* tensor_620 = (((DLTensor*)arg134)[0].data);
  void* arg134_shape = (((DLTensor*)arg134)[0].shape);
  void* arg134_strides = (((DLTensor*)arg134)[0].strides);
  void* kernel_628 = (((DLTensor*)arg135)[0].data);
  void* arg135_shape = (((DLTensor*)arg135)[0].shape);
  void* arg135_strides = (((DLTensor*)arg135)[0].strides);
  void* tensor_629 = (((DLTensor*)arg136)[0].data);
  void* arg136_shape = (((DLTensor*)arg136)[0].shape);
  void* arg136_strides = (((DLTensor*)arg136)[0].strides);
  void* kernel_642 = (((DLTensor*)arg137)[0].data);
  void* arg137_shape = (((DLTensor*)arg137)[0].shape);
  void* arg137_strides = (((DLTensor*)arg137)[0].strides);
  void* tensor_644 = (((DLTensor*)arg138)[0].data);
  void* arg138_shape = (((DLTensor*)arg138)[0].shape);
  void* arg138_strides = (((DLTensor*)arg138)[0].strides);
  void* tensor_645 = (((DLTensor*)arg139)[0].data);
  void* arg139_shape = (((DLTensor*)arg139)[0].shape);
  void* arg139_strides = (((DLTensor*)arg139)[0].strides);
  void* kernel_652 = (((DLTensor*)arg140)[0].data);
  void* arg140_shape = (((DLTensor*)arg140)[0].shape);
  void* arg140_strides = (((DLTensor*)arg140)[0].strides);
  void* tensor_653 = (((DLTensor*)arg141)[0].data);
  void* arg141_shape = (((DLTensor*)arg141)[0].shape);
  void* arg141_strides = (((DLTensor*)arg141)[0].strides);
  void* kernel_660 = (((DLTensor*)arg142)[0].data);
  void* arg142_shape = (((DLTensor*)arg142)[0].shape);
  void* arg142_strides = (((DLTensor*)arg142)[0].strides);
  void* tensor_662 = (((DLTensor*)arg143)[0].data);
  void* arg143_shape = (((DLTensor*)arg143)[0].shape);
  void* arg143_strides = (((DLTensor*)arg143)[0].strides);
  void* tensor_669 = (((DLTensor*)arg144)[0].data);
  void* arg144_shape = (((DLTensor*)arg144)[0].shape);
  void* arg144_strides = (((DLTensor*)arg144)[0].strides);
  void* tensor_670 = (((DLTensor*)arg145)[0].data);
  void* arg145_shape = (((DLTensor*)arg145)[0].shape);
  void* arg145_strides = (((DLTensor*)arg145)[0].strides);
  void* kernel_685 = (((DLTensor*)arg146)[0].data);
  void* arg146_shape = (((DLTensor*)arg146)[0].shape);
  void* arg146_strides = (((DLTensor*)arg146)[0].strides);
  void* tensor_687 = (((DLTensor*)arg147)[0].data);
  void* arg147_shape = (((DLTensor*)arg147)[0].shape);
  void* arg147_strides = (((DLTensor*)arg147)[0].strides);
  void* tensor_688 = (((DLTensor*)arg148)[0].data);
  void* arg148_shape = (((DLTensor*)arg148)[0].shape);
  void* arg148_strides = (((DLTensor*)arg148)[0].strides);
  void* kernel_695 = (((DLTensor*)arg149)[0].data);
  void* arg149_shape = (((DLTensor*)arg149)[0].shape);
  void* arg149_strides = (((DLTensor*)arg149)[0].strides);
  void* tensor_696 = (((DLTensor*)arg150)[0].data);
  void* arg150_shape = (((DLTensor*)arg150)[0].shape);
  void* arg150_strides = (((DLTensor*)arg150)[0].strides);
  void* kernel_703 = (((DLTensor*)arg151)[0].data);
  void* arg151_shape = (((DLTensor*)arg151)[0].shape);
  void* arg151_strides = (((DLTensor*)arg151)[0].strides);
  void* tensor_705 = (((DLTensor*)arg152)[0].data);
  void* arg152_shape = (((DLTensor*)arg152)[0].shape);
  void* arg152_strides = (((DLTensor*)arg152)[0].strides);
  void* tensor_712 = (((DLTensor*)arg153)[0].data);
  void* arg153_shape = (((DLTensor*)arg153)[0].shape);
  void* arg153_strides = (((DLTensor*)arg153)[0].strides);
  void* tensor_714 = (((DLTensor*)arg154)[0].data);
  void* arg154_shape = (((DLTensor*)arg154)[0].shape);
  void* arg154_strides = (((DLTensor*)arg154)[0].strides);
  void* tensor_733 = (((DLTensor*)arg155)[0].data);
  void* arg155_shape = (((DLTensor*)arg155)[0].shape);
  void* arg155_strides = (((DLTensor*)arg155)[0].strides);
  void* tensor_734 = (((DLTensor*)arg156)[0].data);
  void* arg156_shape = (((DLTensor*)arg156)[0].shape);
  void* arg156_strides = (((DLTensor*)arg156)[0].strides);
  void* T_add = (((DLTensor*)arg157)[0].data);
  void* arg157_shape = (((DLTensor*)arg157)[0].shape);
  void* arg157_strides = (((DLTensor*)arg157)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  if (!(arg4_strides == NULL)) {
  }
  if (!(arg5_strides == NULL)) {
  }
  if (!(arg6_strides == NULL)) {
  }
  if (!(arg7_strides == NULL)) {
  }
  if (!(arg8_strides == NULL)) {
  }
  if (!(arg9_strides == NULL)) {
  }
  if (!(arg10_strides == NULL)) {
  }
  if (!(arg11_strides == NULL)) {
  }
  if (!(arg12_strides == NULL)) {
  }
  if (!(arg13_strides == NULL)) {
  }
  if (!(arg14_strides == NULL)) {
  }
  if (!(arg15_strides == NULL)) {
  }
  if (!(arg16_strides == NULL)) {
  }
  if (!(arg17_strides == NULL)) {
  }
  if (!(arg18_strides == NULL)) {
  }
  if (!(arg19_strides == NULL)) {
  }
  if (!(arg20_strides == NULL)) {
  }
  if (!(arg21_strides == NULL)) {
  }
  if (!(arg22_strides == NULL)) {
  }
  if (!(arg23_strides == NULL)) {
  }
  if (!(arg24_strides == NULL)) {
  }
  if (!(arg25_strides == NULL)) {
  }
  if (!(arg26_strides == NULL)) {
  }
  if (!(arg27_strides == NULL)) {
  }
  if (!(arg28_strides == NULL)) {
  }
  if (!(arg29_strides == NULL)) {
  }
  if (!(arg30_strides == NULL)) {
  }
  if (!(arg31_strides == NULL)) {
  }
  if (!(arg32_strides == NULL)) {
  }
  if (!(arg33_strides == NULL)) {
  }
  if (!(arg34_strides == NULL)) {
  }
  if (!(arg35_strides == NULL)) {
  }
  if (!(arg36_strides == NULL)) {
  }
  if (!(arg37_strides == NULL)) {
  }
  if (!(arg38_strides == NULL)) {
  }
  if (!(arg39_strides == NULL)) {
  }
  if (!(arg40_strides == NULL)) {
  }
  if (!(arg41_strides == NULL)) {
  }
  if (!(arg42_strides == NULL)) {
  }
  if (!(arg43_strides == NULL)) {
  }
  if (!(arg44_strides == NULL)) {
  }
  if (!(arg45_strides == NULL)) {
  }
  if (!(arg46_strides == NULL)) {
  }
  if (!(arg47_strides == NULL)) {
  }
  if (!(arg48_strides == NULL)) {
  }
  if (!(arg49_strides == NULL)) {
  }
  if (!(arg50_strides == NULL)) {
  }
  if (!(arg51_strides == NULL)) {
  }
  if (!(arg52_strides == NULL)) {
  }
  if (!(arg53_strides == NULL)) {
  }
  if (!(arg54_strides == NULL)) {
  }
  if (!(arg55_strides == NULL)) {
  }
  if (!(arg56_strides == NULL)) {
  }
  if (!(arg57_strides == NULL)) {
  }
  if (!(arg58_strides == NULL)) {
  }
  if (!(arg59_strides == NULL)) {
  }
  if (!(arg60_strides == NULL)) {
  }
  if (!(arg61_strides == NULL)) {
  }
  if (!(arg62_strides == NULL)) {
  }
  if (!(arg63_strides == NULL)) {
  }
  if (!(arg64_strides == NULL)) {
  }
  if (!(arg65_strides == NULL)) {
  }
  if (!(arg66_strides == NULL)) {
  }
  if (!(arg67_strides == NULL)) {
  }
  if (!(arg68_strides == NULL)) {
  }
  if (!(arg69_strides == NULL)) {
  }
  if (!(arg70_strides == NULL)) {
  }
  if (!(arg71_strides == NULL)) {
  }
  if (!(arg72_strides == NULL)) {
  }
  if (!(arg73_strides == NULL)) {
  }
  if (!(arg74_strides == NULL)) {
  }
  if (!(arg75_strides == NULL)) {
  }
  if (!(arg76_strides == NULL)) {
  }
  if (!(arg77_strides == NULL)) {
  }
  if (!(arg78_strides == NULL)) {
  }
  if (!(arg79_strides == NULL)) {
  }
  if (!(arg80_strides == NULL)) {
  }
  if (!(arg81_strides == NULL)) {
  }
  if (!(arg82_strides == NULL)) {
  }
  if (!(arg83_strides == NULL)) {
  }
  if (!(arg84_strides == NULL)) {
  }
  if (!(arg85_strides == NULL)) {
  }
  if (!(arg86_strides == NULL)) {
  }
  if (!(arg87_strides == NULL)) {
  }
  if (!(arg88_strides == NULL)) {
  }
  if (!(arg89_strides == NULL)) {
  }
  if (!(arg90_strides == NULL)) {
  }
  if (!(arg91_strides == NULL)) {
  }
  if (!(arg92_strides == NULL)) {
  }
  if (!(arg93_strides == NULL)) {
  }
  if (!(arg94_strides == NULL)) {
  }
  if (!(arg95_strides == NULL)) {
  }
  if (!(arg96_strides == NULL)) {
  }
  if (!(arg97_strides == NULL)) {
  }
  if (!(arg98_strides == NULL)) {
  }
  if (!(arg99_strides == NULL)) {
  }
  if (!(arg100_strides == NULL)) {
  }
  if (!(arg101_strides == NULL)) {
  }
  if (!(arg102_strides == NULL)) {
  }
  if (!(arg103_strides == NULL)) {
  }
  if (!(arg104_strides == NULL)) {
  }
  if (!(arg105_strides == NULL)) {
  }
  if (!(arg106_strides == NULL)) {
  }
  if (!(arg107_strides == NULL)) {
  }
  if (!(arg108_strides == NULL)) {
  }
  if (!(arg109_strides == NULL)) {
  }
  if (!(arg110_strides == NULL)) {
  }
  if (!(arg111_strides == NULL)) {
  }
  if (!(arg112_strides == NULL)) {
  }
  if (!(arg113_strides == NULL)) {
  }
  if (!(arg114_strides == NULL)) {
  }
  if (!(arg115_strides == NULL)) {
  }
  if (!(arg116_strides == NULL)) {
  }
  if (!(arg117_strides == NULL)) {
  }
  if (!(arg118_strides == NULL)) {
  }
  if (!(arg119_strides == NULL)) {
  }
  if (!(arg120_strides == NULL)) {
  }
  if (!(arg121_strides == NULL)) {
  }
  if (!(arg122_strides == NULL)) {
  }
  if (!(arg123_strides == NULL)) {
  }
  if (!(arg124_strides == NULL)) {
  }
  if (!(arg125_strides == NULL)) {
  }
  if (!(arg126_strides == NULL)) {
  }
  if (!(arg127_strides == NULL)) {
  }
  if (!(arg128_strides == NULL)) {
  }
  if (!(arg129_strides == NULL)) {
  }
  if (!(arg130_strides == NULL)) {
  }
  if (!(arg131_strides == NULL)) {
  }
  if (!(arg132_strides == NULL)) {
  }
  if (!(arg133_strides == NULL)) {
  }
  if (!(arg134_strides == NULL)) {
  }
  if (!(arg135_strides == NULL)) {
  }
  if (!(arg136_strides == NULL)) {
  }
  if (!(arg137_strides == NULL)) {
  }
  if (!(arg138_strides == NULL)) {
  }
  if (!(arg139_strides == NULL)) {
  }
  if (!(arg140_strides == NULL)) {
  }
  if (!(arg141_strides == NULL)) {
  }
  if (!(arg142_strides == NULL)) {
  }
  if (!(arg143_strides == NULL)) {
  }
  if (!(arg144_strides == NULL)) {
  }
  if (!(arg145_strides == NULL)) {
  }
  if (!(arg146_strides == NULL)) {
  }
  if (!(arg147_strides == NULL)) {
  }
  if (!(arg148_strides == NULL)) {
  }
  if (!(arg149_strides == NULL)) {
  }
  if (!(arg150_strides == NULL)) {
  }
  if (!(arg151_strides == NULL)) {
  }
  if (!(arg152_strides == NULL)) {
  }
  if (!(arg153_strides == NULL)) {
  }
  if (!(arg154_strides == NULL)) {
  }
  if (!(arg155_strides == NULL)) {
  }
  if (!(arg156_strides == NULL)) {
  }
  if (!(arg157_strides == NULL)) {
  }
  void* pad_data = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)3211264, 2, 32);
  if (pad_data == NULL) {
    return -1;
  }
  void* Y = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)3268864, 2, 32);
  if (Y == NULL) {
    return -1;
  }
  void* compute = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)802816, 2, 32);
  if (compute == NULL) {
    return -1;
  }
  void* compute1 = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1806336, 0, 8);
  if (compute1 == NULL) {
    return -1;
  }
  void* T_reshape = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)197120, 0, 8);
  if (T_reshape == NULL) {
    return -1;
  }
  void* T_reshape1 = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)102400, 0, 8);
  if (T_reshape1 == NULL) {
    return -1;
  }
  void* feature_input = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1908736, 0, 8);
  if (feature_input == NULL) {
    return -1;
  }
  void* weight_input = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)2359296, 0, 8);
  if (weight_input == NULL) {
    return -1;
  }
  void* feature = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)8192, 0, 8);
  if (feature == NULL) {
    return -1;
  }
  void* weight = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)8192, 0, 8);
  if (weight == NULL) {
    return -1;
  }
  void* out = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)3211264, 0, 32);
  if (out == NULL) {
    return -1;
  }
  void* data1_in = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)57344, 0, 32);
  if (data1_in == NULL) {
    return -1;
  }
  void* data2_in = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)57344, 0, 32);
  if (data2_in == NULL) {
    return -1;
  }
  void* cout = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)57344, 0, 32);
  if (cout == NULL) {
    return -1;
  }
  void* out1 = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)3211264, 0, 32);
  if (out1 == NULL) {
    return -1;
  }
  void* out2 = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)100352, 0, 32);
  if (out2 == NULL) {
    return -1;
  }
  void* T_matmul_NT = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)4000, 2, 32);
  if (T_matmul_NT == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 229; ++i1) {
    for (int32_t i2 = 0; i2 < 229; ++i2) {
      for (int32_t i3 = 0; i3 < 3; ++i3) {
        ((float*)pad_data)[((((i1 * 687) + (i2 * 3)) + i3))] = (((((3 <= i1) && (i1 < 227)) && (3 <= i2)) && (i2 < 227)) ? ((float*)input_data)[(((((i1 * 672) + (i2 * 3)) + i3) - 2025))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i = 0; i < 112; ++i) {
    for (int32_t j = 0; j < 112; ++j) {
      for (int32_t c = 0; c < 64; ++c) {
        ((float*)Y)[((((i * 7168) + (j * 64)) + c))] = 0.000000e+00f;
        for (int32_t rkh = 0; rkh < 7; ++rkh) {
          for (int32_t rkw = 0; rkw < 7; ++rkw) {
            for (int32_t ric = 0; ric < 3; ++ric) {
              ((float*)Y)[((((i * 7168) + (j * 64)) + c))] = (((float*)Y)[((((i * 7168) + (j * 64)) + c))] + (((float*)pad_data)[((((((i * 1374) + (rkh * 687)) + (j * 6)) + (rkw * 3)) + ric))] * ((float*)kernel_1)[(((((c * 147) + (rkh * 21)) + (rkw * 3)) + ric))]));
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 64; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 112; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 112; ++ax3) {
        ((float*)pad_data)[((((ax1 * 12544) + (ax2 * 112)) + ax3))] = ((float*)Y)[((((ax2 * 7168) + (ax3 * 64)) + ax1))];
      }
    }
  }
  for (int32_t ax11 = 0; ax11 < 64; ++ax11) {
    for (int32_t ax21 = 0; ax21 < 112; ++ax21) {
      for (int32_t ax31 = 0; ax31 < 112; ++ax31) {
        ((float*)pad_data)[((((ax11 * 12544) + (ax21 * 112)) + ax31))] = (((float*)pad_data)[((((ax11 * 12544) + (ax21 * 112)) + ax31))] + ((float*)tensor_1)[(ax11)]);
      }
    }
  }
  for (int32_t i11 = 0; i11 < 64; ++i11) {
    for (int32_t i21 = 0; i21 < 112; ++i21) {
      for (int32_t i31 = 0; i31 < 112; ++i31) {
        float _1 = ((float*)pad_data)[((((i11 * 12544) + (i21 * 112)) + i31))];
        ((float*)pad_data)[((((i11 * 12544) + (i21 * 112)) + i31))] = ((_1) > (0.000000e+00f) ? (_1) : (0.000000e+00f));
      }
    }
  }
  for (int32_t ax12 = 0; ax12 < 64; ++ax12) {
    for (int32_t ax22 = 0; ax22 < 113; ++ax22) {
      for (int32_t ax32 = 0; ax32 < 113; ++ax32) {
        ((float*)Y)[((((ax12 * 12769) + (ax22 * 113)) + ax32))] = (((1 <= ax22) && (1 <= ax32)) ? ((float*)pad_data)[(((((ax12 * 12544) + (ax22 * 112)) + ax32) - 113))] : -3.402823e+38f);
      }
    }
  }
  for (int32_t ax13 = 0; ax13 < 64; ++ax13) {
    for (int32_t ax23 = 0; ax23 < 56; ++ax23) {
      for (int32_t ax33 = 0; ax33 < 56; ++ax33) {
        ((float*)pad_data)[((((ax13 * 3136) + (ax23 * 56)) + ax33))] = -3.402823e+38f;
        for (int32_t rv0 = 0; rv0 < 3; ++rv0) {
          for (int32_t rv1 = 0; rv1 < 3; ++rv1) {
            float _2 = ((float*)pad_data)[((((ax13 * 3136) + (ax23 * 56)) + ax33))];
            float _3 = ((float*)Y)[((((((ax13 * 12769) + (ax23 * 226)) + (rv0 * 113)) + (ax33 * 2)) + rv1))];
            ((float*)pad_data)[((((ax13 * 3136) + (ax23 * 56)) + ax33))] = ((_2) > (_3) ? (_2) : (_3));
          }
        }
      }
    }
  }
  for (int32_t ax14 = 0; ax14 < 64; ++ax14) {
    for (int32_t ax24 = 0; ax24 < 56; ++ax24) {
      for (int32_t ax34 = 0; ax34 < 56; ++ax34) {
        ((float*)Y)[((((ax14 * 3136) + (ax24 * 56)) + ax34))] = (((float*)pad_data)[((((ax14 * 3136) + (ax24 * 56)) + ax34))] * 1.600000e+01f);
      }
    }
  }
  for (int32_t i12 = 0; i12 < 64; ++i12) {
    for (int32_t i22 = 0; i22 < 56; ++i22) {
      for (int32_t i32 = 0; i32 < 56; ++i32) {
        ((float*)compute)[((((i12 * 3136) + (i22 * 56)) + i32))] = roundf(((float*)Y)[((((i12 * 3136) + (i22 * 56)) + i32))]);
      }
    }
  }
  for (int32_t i13 = 0; i13 < 64; ++i13) {
    for (int32_t i23 = 0; i23 < 56; ++i23) {
      for (int32_t i33 = 0; i33 < 56; ++i33) {
        float _4 = ((float*)compute)[((((i13 * 3136) + (i23 * 56)) + i33))];
        float _5 = (_4) < (1.270000e+02f) ? (_4) : (1.270000e+02f);
        ((float*)compute)[((((i13 * 3136) + (i23 * 56)) + i33))] = ((_5) > (-1.270000e+02f) ? (_5) : (-1.270000e+02f));
      }
    }
  }
  for (int32_t i14 = 0; i14 < 64; ++i14) {
    for (int32_t i24 = 0; i24 < 56; ++i24) {
      for (int32_t i34 = 0; i34 < 56; ++i34) {
        ((int8_t*)compute1)[((((i14 * 3136) + (i24 * 56)) + i34))] = ((int8_t)((float*)compute)[((((i14 * 3136) + (i24 * 56)) + i34))]);
      }
    }
  }
  for (int32_t ax15 = 0; ax15 < 56; ++ax15) {
    for (int32_t ax25 = 0; ax25 < 56; ++ax25) {
      for (int32_t ax35 = 0; ax35 < 64; ++ax35) {
        ((int8_t*)compute)[((((ax15 * 3584) + (ax25 * 64)) + ax35))] = ((int8_t*)compute1)[((((ax35 * 3136) + (ax15 * 56)) + ax25))];
      }
    }
  }
  for (int32_t o1 = 0; o1 < 56; ++o1) {
    for (int32_t o2 = 0; o2 < 56; ++o2) {
      for (int32_t c1 = 0; c1 < 64; ++c1) {
        ((int8_t*)compute1)[((((o1 * 3584) + (o2 * 64)) + c1))] = ((int8_t*)compute)[((((o1 * 3584) + (o2 * 64)) + c1))];
      }
    }
  }
  for (int32_t ax0 = 0; ax0 < 392; ++ax0) {
    for (int32_t ax16 = 0; ax16 < 8; ++ax16) {
      for (int32_t ax26 = 0; ax26 < 8; ++ax26) {
        for (int32_t ax36 = 0; ax36 < 8; ++ax36) {
          ((int8_t*)compute)[(((((ax0 * 512) + (ax16 * 64)) + (ax26 * 8)) + ax36))] = ((int8_t*)compute1)[(((((ax0 * 512) + (ax16 * 64)) + (ax26 * 8)) + ax36))];
        }
      }
    }
  }
  for (int32_t ax01 = 0; ax01 < 392; ++ax01) {
    for (int32_t ax17 = 0; ax17 < 8; ++ax17) {
      for (int32_t ax27 = 0; ax27 < 8; ++ax27) {
        for (int32_t ax37 = 0; ax37 < 8; ++ax37) {
          ((int8_t*)compute1)[(((((ax01 * 512) + (ax17 * 64)) + (ax27 * 8)) + ax37))] = ((int8_t*)compute)[(((((ax01 * 512) + (ax27 * 64)) + (ax17 * 8)) + ax37))];
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 25088, 0);
  for (int32_t ax02 = 0; ax02 < 64; ++ax02) {
    for (int32_t ax18 = 0; ax18 < 64; ++ax18) {
      ((int8_t*)T_reshape)[(((ax02 * 64) + ax18))] = ((int8_t*)kernel_9)[(((ax02 * 64) + ax18))];
    }
  }
  for (int32_t ax03 = 0; ax03 < 8; ++ax03) {
    for (int32_t ax19 = 0; ax19 < 8; ++ax19) {
      for (int32_t ax28 = 0; ax28 < 8; ++ax28) {
        for (int32_t ax38 = 0; ax38 < 8; ++ax38) {
          ((int8_t*)T_reshape1)[(((((ax03 * 512) + (ax19 * 64)) + (ax28 * 8)) + ax38))] = ((int8_t*)T_reshape)[(((((ax03 * 512) + (ax19 * 64)) + (ax28 * 8)) + ax38))];
        }
      }
    }
  }
  for (int32_t ax04 = 0; ax04 < 8; ++ax04) {
    for (int32_t ax110 = 0; ax110 < 8; ++ax110) {
      for (int32_t ax29 = 0; ax29 < 8; ++ax29) {
        for (int32_t ax39 = 0; ax39 < 8; ++ax39) {
          ((int8_t*)T_reshape)[(((((ax04 * 512) + (ax110 * 64)) + (ax29 * 8)) + ax39))] = ((int8_t*)T_reshape1)[(((((ax04 * 512) + (ax29 * 64)) + (ax110 * 8)) + ax39))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 512, 0);
  for (int32_t i4 = 0; i4 < 392; ++i4) {
    for (int32_t x = 0; x < 8; ++x) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i4 * 32)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 64, 0);
      (void)move(((((int64_t)(x * 32)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 64, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 8, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i4 * 2048) + (x * 256)));
    }
  }
  for (int32_t ax05 = 0; ax05 < 392; ++ax05) {
    for (int32_t ax111 = 0; ax111 < 8; ++ax111) {
      for (int32_t ax210 = 0; ax210 < 8; ++ax210) {
        for (int32_t ax310 = 0; ax310 < 8; ++ax310) {
          ((int32_t*)Y)[(((((ax05 * 512) + (ax111 * 64)) + (ax210 * 8)) + ax310))] = ((int32_t*)compute)[(((((ax05 * 512) + (ax210 * 64)) + (ax111 * 8)) + ax310))];
        }
      }
    }
  }
  for (int32_t ax06 = 0; ax06 < 3136; ++ax06) {
    for (int32_t ax112 = 0; ax112 < 64; ++ax112) {
      ((int32_t*)compute)[(((ax06 * 64) + ax112))] = ((int32_t*)Y)[(((ax06 * 64) + ax112))];
    }
  }
  for (int32_t i0 = 0; i0 < 3136; ++i0) {
    for (int32_t i15 = 0; i15 < 64; ++i15) {
      ((int32_t*)Y)[(((i0 * 64) + i15))] = ((int32_t*)compute)[(((i0 * 64) + i15))];
    }
  }
  for (int32_t ax113 = 0; ax113 < 56; ++ax113) {
    for (int32_t ax211 = 0; ax211 < 56; ++ax211) {
      for (int32_t ax311 = 0; ax311 < 64; ++ax311) {
        ((int32_t*)compute)[((((ax113 * 3584) + (ax211 * 64)) + ax311))] = ((int32_t*)Y)[((((ax113 * 3584) + (ax211 * 64)) + ax311))];
      }
    }
  }
  for (int32_t h = 0; h < 56; ++h) {
    for (int32_t w = 0; w < 56; ++w) {
      for (int32_t c2 = 0; c2 < 64; ++c2) {
        ((int32_t*)Y)[((((h * 3584) + (w * 64)) + c2))] = 11;
      }
    }
  }
  for (int32_t h1 = 0; h1 < 56; ++h1) {
    (void)load(compute, (int64_t)537264128, 1792, (h1 * 3584));
    (void)load(Y, (int64_t)537329664, 1792, (h1 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h1 * 14336));
  }
  for (int32_t h2 = 0; h2 < 56; ++h2) {
    for (int32_t w1 = 0; w1 < 56; ++w1) {
      for (int32_t c3 = 0; c3 < 64; ++c3) {
        ((int32_t*)compute)[((((h2 * 3584) + (w1 * 64)) + c3))] = ((int32_t*)tensor_11)[(c3)];
      }
    }
  }
  for (int32_t h3 = 0; h3 < 56; ++h3) {
    (void)load(out, (int64_t)537264128, 1792, (h3 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h3 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 1792, (h3 * 14336));
  }
  for (int32_t h4 = 0; h4 < 56; ++h4) {
    for (int32_t w2 = 0; w2 < 56; ++w2) {
      for (int32_t c4 = 0; c4 < 64; ++c4) {
        ((int32_t*)out)[((((h4 * 3584) + (w2 * 64)) + c4))] = ((int32_t*)Y)[((((h4 * 3584) + (w2 * 64)) + c4))];
      }
    }
  }
  for (int32_t h5 = 0; h5 < 56; ++h5) {
    for (int32_t w3 = 0; w3 < 56; ++w3) {
      for (int32_t c5 = 0; c5 < 64; ++c5) {
        ((int32_t*)compute)[((((h5 * 3584) + (w3 * 64)) + c5))] = ((int32_t*)tensor_12)[(c5)];
      }
    }
  }
  for (int32_t h6 = 0; h6 < 56; ++h6) {
    for (int32_t w4 = 0; w4 < 56; ++w4) {
      for (int32_t c6 = 0; c6 < 64; ++c6) {
        ((int32_t*)Y)[((((h6 * 3584) + (w4 * 64)) + c6))] = ((int32_t*)compute)[((((h6 * 3584) + (w4 * 64)) + c6))];
      }
    }
  }
  for (int32_t h7 = 0; h7 < 56; ++h7) {
    for (int32_t w5 = 0; w5 < 56; ++w5) {
      for (int32_t c7 = 0; c7 < 64; ++c7) {
        ((int32_t*)out)[((((h7 * 3584) + (w5 * 64)) + c7))] = (((int32_t*)out)[((((h7 * 3584) + (w5 * 64)) + c7))] + ((int32_t*)Y)[((((h7 * 3584) + (w5 * 64)) + c7))]);
      }
    }
  }
  for (int32_t h8 = 0; h8 < 56; ++h8) {
    for (int32_t w6 = 0; w6 < 56; ++w6) {
      for (int32_t c8 = 0; c8 < 64; ++c8) {
        ((int32_t*)compute)[((((h8 * 3584) + (w6 * 64)) + c8))] = 0;
      }
    }
  }
  for (int32_t h9 = 0; h9 < 56; ++h9) {
    for (int32_t w7 = 0; w7 < 56; ++w7) {
      for (int32_t c9 = 0; c9 < 64; ++c9) {
        ((int32_t*)Y)[((((h9 * 3584) + (w7 * 64)) + c9))] = ((int32_t*)compute)[((((h9 * 3584) + (w7 * 64)) + c9))];
      }
    }
  }
  for (int32_t h10 = 0; h10 < 56; ++h10) {
    for (int32_t w8 = 0; w8 < 56; ++w8) {
      for (int32_t c10 = 0; c10 < 64; ++c10) {
        int32_t _6 = ((int32_t*)out)[((((h10 * 3584) + (w8 * 64)) + c10))];
        int32_t _7 = ((int32_t*)Y)[((((h10 * 3584) + (w8 * 64)) + c10))];
        ((int32_t*)out)[((((h10 * 3584) + (w8 * 64)) + c10))] = ((_6) > (_7) ? (_6) : (_7));
      }
    }
  }
  for (int32_t h11 = 0; h11 < 56; ++h11) {
    for (int32_t w9 = 0; w9 < 56; ++w9) {
      for (int32_t c11 = 0; c11 < 64; ++c11) {
        ((int32_t*)compute)[((((h11 * 3584) + (w9 * 64)) + c11))] = 131072;
      }
    }
  }
  for (int32_t h12 = 0; h12 < 56; ++h12) {
    (void)load(out, (int64_t)537264128, 1792, (h12 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h12 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 1792, (h12 * 14336));
  }
  for (int32_t h13 = 0; h13 < 56; ++h13) {
    for (int32_t w10 = 0; w10 < 56; ++w10) {
      for (int32_t c12 = 0; c12 < 64; ++c12) {
        ((int32_t*)out)[((((h13 * 3584) + (w10 * 64)) + c12))] = 18;
      }
    }
  }
  for (int32_t h14 = 0; h14 < 56; ++h14) {
    (void)load(Y, (int64_t)537264128, 1792, (h14 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h14 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h14 * 14336));
  }
  for (int32_t i16 = 0; i16 < 56; ++i16) {
    for (int32_t i25 = 0; i25 < 56; ++i25) {
      for (int32_t i35 = 0; i35 < 64; ++i35) {
        int32_t _8 = ((int32_t*)compute)[((((i16 * 3584) + (i25 * 64)) + i35))];
        int32_t _9 = (_8) < (127) ? (_8) : (127);
        ((int32_t*)out)[((((i16 * 3584) + (i25 * 64)) + i35))] = ((_9) > (-127) ? (_9) : (-127));
      }
    }
  }
  for (int32_t i17 = 0; i17 < 56; ++i17) {
    for (int32_t i26 = 0; i26 < 56; ++i26) {
      for (int32_t i36 = 0; i36 < 64; ++i36) {
        ((int8_t*)compute1)[((((i17 * 3584) + (i26 * 64)) + i36))] = ((int8_t)((int32_t*)out)[((((i17 * 3584) + (i26 * 64)) + i36))]);
      }
    }
  }
  for (int32_t i18 = 0; i18 < 58; ++i18) {
    for (int32_t i27 = 0; i27 < 58; ++i27) {
      for (int32_t i37 = 0; i37 < 64; ++i37) {
        ((int8_t*)compute)[((((i18 * 3712) + (i27 * 64)) + i37))] = (((((1 <= i18) && (i18 < 57)) && (1 <= i27)) && (i27 < 57)) ? ((int8_t*)compute1)[(((((i18 * 3584) + (i27 * 64)) + i37) - 3648))] : (int8_t)0);
      }
    }
  }
  for (int32_t o11 = 0; o11 < 56; ++o11) {
    for (int32_t o21 = 0; o21 < 56; ++o21) {
      for (int32_t k1 = 0; k1 < 3; ++k1) {
        for (int32_t k2 = 0; k2 < 3; ++k2) {
          for (int32_t c13 = 0; c13 < 64; ++c13) {
            ((int8_t*)Y)[((((((o11 * 32256) + (o21 * 576)) + (k1 * 192)) + (k2 * 64)) + c13))] = ((int8_t*)compute)[((((((k1 * 3712) + (o11 * 3712)) + (k2 * 64)) + (o21 * 64)) + c13))];
          }
        }
      }
    }
  }
  for (int32_t ax07 = 0; ax07 < 3136; ++ax07) {
    for (int32_t ax114 = 0; ax114 < 576; ++ax114) {
      ((int8_t*)compute1)[(((ax07 * 576) + ax114))] = ((int8_t*)Y)[(((ax07 * 576) + ax114))];
    }
  }
  for (int32_t ax08 = 0; ax08 < 392; ++ax08) {
    for (int32_t ax115 = 0; ax115 < 8; ++ax115) {
      for (int32_t ax212 = 0; ax212 < 72; ++ax212) {
        for (int32_t ax312 = 0; ax312 < 8; ++ax312) {
          ((int8_t*)Y)[(((((ax08 * 4608) + (ax115 * 576)) + (ax212 * 8)) + ax312))] = ((int8_t*)compute1)[(((((ax08 * 4608) + (ax115 * 576)) + (ax212 * 8)) + ax312))];
        }
      }
    }
  }
  for (int32_t ax09 = 0; ax09 < 392; ++ax09) {
    for (int32_t ax116 = 0; ax116 < 72; ++ax116) {
      for (int32_t ax213 = 0; ax213 < 8; ++ax213) {
        for (int32_t ax313 = 0; ax313 < 8; ++ax313) {
          ((int8_t*)compute1)[(((((ax09 * 4608) + (ax116 * 64)) + (ax213 * 8)) + ax313))] = ((int8_t*)Y)[(((((ax09 * 4608) + (ax213 * 576)) + (ax116 * 8)) + ax313))];
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 225792, 0);
  for (int32_t ax010 = 0; ax010 < 64; ++ax010) {
    for (int32_t ax117 = 0; ax117 < 576; ++ax117) {
      ((int8_t*)T_reshape)[(((ax010 * 576) + ax117))] = ((int8_t*)kernel_19)[(((ax010 * 576) + ax117))];
    }
  }
  for (int32_t ax011 = 0; ax011 < 8; ++ax011) {
    for (int32_t ax118 = 0; ax118 < 8; ++ax118) {
      for (int32_t ax214 = 0; ax214 < 72; ++ax214) {
        for (int32_t ax314 = 0; ax314 < 8; ++ax314) {
          ((int8_t*)T_reshape1)[(((((ax011 * 4608) + (ax118 * 576)) + (ax214 * 8)) + ax314))] = ((int8_t*)T_reshape)[(((((ax011 * 4608) + (ax118 * 576)) + (ax214 * 8)) + ax314))];
        }
      }
    }
  }
  for (int32_t ax012 = 0; ax012 < 8; ++ax012) {
    for (int32_t ax119 = 0; ax119 < 72; ++ax119) {
      for (int32_t ax215 = 0; ax215 < 8; ++ax215) {
        for (int32_t ax315 = 0; ax315 < 8; ++ax315) {
          ((int8_t*)T_reshape)[(((((ax012 * 4608) + (ax119 * 64)) + (ax215 * 8)) + ax315))] = ((int8_t*)T_reshape1)[(((((ax012 * 4608) + (ax215 * 576)) + (ax119 * 8)) + ax315))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 4608, 0);
  for (int32_t i5 = 0; i5 < 392; ++i5) {
    for (int32_t x1 = 0; x1 < 8; ++x1) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i5 * 288)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
      (void)move(((((int64_t)(x1 * 288)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      (void)store(out, (int64_t)537264128, 32, ((i5 * 2048) + (x1 * 256)));
    }
  }
  for (int32_t ax013 = 0; ax013 < 392; ++ax013) {
    for (int32_t ax120 = 0; ax120 < 8; ++ax120) {
      for (int32_t ax216 = 0; ax216 < 8; ++ax216) {
        for (int32_t ax316 = 0; ax316 < 8; ++ax316) {
          ((int32_t*)compute)[(((((ax013 * 512) + (ax120 * 64)) + (ax216 * 8)) + ax316))] = ((int32_t*)out)[(((((ax013 * 512) + (ax216 * 64)) + (ax120 * 8)) + ax316))];
        }
      }
    }
  }
  for (int32_t ax014 = 0; ax014 < 3136; ++ax014) {
    for (int32_t ax121 = 0; ax121 < 64; ++ax121) {
      ((int32_t*)out)[(((ax014 * 64) + ax121))] = ((int32_t*)compute)[(((ax014 * 64) + ax121))];
    }
  }
  for (int32_t ax122 = 0; ax122 < 56; ++ax122) {
    for (int32_t ax217 = 0; ax217 < 56; ++ax217) {
      for (int32_t ax317 = 0; ax317 < 64; ++ax317) {
        ((int32_t*)compute)[((((ax122 * 3584) + (ax217 * 64)) + ax317))] = ((int32_t*)out)[((((ax122 * 3584) + (ax217 * 64)) + ax317))];
      }
    }
  }
  for (int32_t h15 = 0; h15 < 56; ++h15) {
    for (int32_t w11 = 0; w11 < 56; ++w11) {
      for (int32_t c14 = 0; c14 < 64; ++c14) {
        ((int32_t*)out)[((((h15 * 3584) + (w11 * 64)) + c14))] = ((int32_t*)tensor_20)[(c14)];
      }
    }
  }
  for (int32_t h16 = 0; h16 < 56; ++h16) {
    (void)load(compute, (int64_t)537264128, 1792, (h16 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h16 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 1792, (h16 * 14336));
  }
  for (int32_t h17 = 0; h17 < 56; ++h17) {
    for (int32_t w12 = 0; w12 < 56; ++w12) {
      for (int32_t c15 = 0; c15 < 64; ++c15) {
        ((int32_t*)compute)[((((h17 * 3584) + (w12 * 64)) + c15))] = 0;
      }
    }
  }
  for (int32_t h18 = 0; h18 < 56; ++h18) {
    (void)load(compute1, (int64_t)537264128, 1792, (h18 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h18 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h18 * 14336));
  }
  for (int32_t h19 = 0; h19 < 56; ++h19) {
    for (int32_t w13 = 0; w13 < 56; ++w13) {
      for (int32_t c16 = 0; c16 < 64; ++c16) {
        ((int32_t*)compute)[((((h19 * 3584) + (w13 * 64)) + c16))] = 64;
      }
    }
  }
  for (int32_t h20 = 0; h20 < 56; ++h20) {
    (void)load(out, (int64_t)537264128, 1792, (h20 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h20 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 1792, (h20 * 14336));
  }
  for (int32_t h21 = 0; h21 < 56; ++h21) {
    for (int32_t w14 = 0; w14 < 56; ++w14) {
      for (int32_t c17 = 0; c17 < 64; ++c17) {
        ((int32_t*)out)[((((h21 * 3584) + (w14 * 64)) + c17))] = 7;
      }
    }
  }
  for (int32_t h22 = 0; h22 < 56; ++h22) {
    (void)load(compute1, (int64_t)537264128, 1792, (h22 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h22 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h22 * 14336));
  }
  for (int32_t i19 = 0; i19 < 56; ++i19) {
    for (int32_t i28 = 0; i28 < 56; ++i28) {
      for (int32_t i38 = 0; i38 < 64; ++i38) {
        int32_t _10 = ((int32_t*)compute)[((((i19 * 3584) + (i28 * 64)) + i38))];
        int32_t _11 = (_10) < (127) ? (_10) : (127);
        ((int32_t*)out)[((((i19 * 3584) + (i28 * 64)) + i38))] = ((_11) > (-127) ? (_11) : (-127));
      }
    }
  }
  for (int32_t i110 = 0; i110 < 56; ++i110) {
    for (int32_t i29 = 0; i29 < 56; ++i29) {
      for (int32_t i39 = 0; i39 < 64; ++i39) {
        ((int8_t*)compute)[((((i110 * 3584) + (i29 * 64)) + i39))] = ((int8_t)((int32_t*)out)[((((i110 * 3584) + (i29 * 64)) + i39))]);
      }
    }
  }
  for (int32_t o12 = 0; o12 < 56; ++o12) {
    for (int32_t o22 = 0; o22 < 56; ++o22) {
      for (int32_t c18 = 0; c18 < 64; ++c18) {
        ((int8_t*)out)[((((o12 * 3584) + (o22 * 64)) + c18))] = ((int8_t*)compute)[((((o12 * 3584) + (o22 * 64)) + c18))];
      }
    }
  }
  for (int32_t ax015 = 0; ax015 < 3136; ++ax015) {
    for (int32_t ax123 = 0; ax123 < 64; ++ax123) {
      ((int8_t*)compute)[(((ax015 * 64) + ax123))] = ((int8_t*)out)[(((ax015 * 64) + ax123))];
    }
  }
  for (int32_t i01 = 0; i01 < 3136; ++i01) {
    for (int32_t i111 = 0; i111 < 64; ++i111) {
      ((int8_t*)out)[(((i01 * 64) + i111))] = ((int8_t*)compute)[(((i01 * 64) + i111))];
    }
  }
  for (int32_t ax016 = 0; ax016 < 392; ++ax016) {
    for (int32_t ax124 = 0; ax124 < 8; ++ax124) {
      for (int32_t ax218 = 0; ax218 < 8; ++ax218) {
        for (int32_t ax318 = 0; ax318 < 8; ++ax318) {
          ((int8_t*)compute)[(((((ax016 * 512) + (ax124 * 64)) + (ax218 * 8)) + ax318))] = ((int8_t*)out)[(((((ax016 * 512) + (ax124 * 64)) + (ax218 * 8)) + ax318))];
        }
      }
    }
  }
  for (int32_t ax017 = 0; ax017 < 392; ++ax017) {
    for (int32_t ax125 = 0; ax125 < 8; ++ax125) {
      for (int32_t ax219 = 0; ax219 < 8; ++ax219) {
        for (int32_t ax319 = 0; ax319 < 8; ++ax319) {
          ((int8_t*)out)[(((((ax017 * 512) + (ax125 * 64)) + (ax219 * 8)) + ax319))] = ((int8_t*)compute)[(((((ax017 * 512) + (ax219 * 64)) + (ax125 * 8)) + ax319))];
        }
      }
    }
  }
  for (int32_t ax018 = 0; ax018 < 392; ++ax018) {
    for (int32_t ax220 = 0; ax220 < 8; ++ax220) {
      for (int32_t ax320 = 0; ax320 < 8; ++ax320) {
        for (int32_t ax4 = 0; ax4 < 8; ++ax4) {
          ((int8_t*)compute)[(((((ax018 * 512) + (ax220 * 64)) + (ax320 * 8)) + ax4))] = ((int8_t*)out)[(((((ax018 * 512) + (ax220 * 64)) + (ax320 * 8)) + ax4))];
        }
      }
    }
  }
  (void)load(compute, (int64_t)536870912, 25088, 0);
  for (int32_t ax019 = 0; ax019 < 256; ++ax019) {
    for (int32_t ax126 = 0; ax126 < 64; ++ax126) {
      ((int8_t*)T_reshape1)[(((ax019 * 64) + ax126))] = ((int8_t*)kernel_27)[(((ax019 * 64) + ax126))];
    }
  }
  for (int32_t ax020 = 0; ax020 < 32; ++ax020) {
    for (int32_t ax127 = 0; ax127 < 8; ++ax127) {
      for (int32_t ax221 = 0; ax221 < 8; ++ax221) {
        for (int32_t ax321 = 0; ax321 < 8; ++ax321) {
          ((int8_t*)T_reshape)[(((((ax020 * 512) + (ax127 * 64)) + (ax221 * 8)) + ax321))] = ((int8_t*)T_reshape1)[(((((ax020 * 512) + (ax127 * 64)) + (ax221 * 8)) + ax321))];
        }
      }
    }
  }
  for (int32_t ax021 = 0; ax021 < 32; ++ax021) {
    for (int32_t ax128 = 0; ax128 < 8; ++ax128) {
      for (int32_t ax222 = 0; ax222 < 8; ++ax222) {
        for (int32_t ax322 = 0; ax322 < 8; ++ax322) {
          ((int8_t*)T_reshape1)[(((((ax021 * 512) + (ax128 * 64)) + (ax222 * 8)) + ax322))] = ((int8_t*)T_reshape)[(((((ax021 * 512) + (ax222 * 64)) + (ax128 * 8)) + ax322))];
        }
      }
    }
  }
  for (int32_t ax022 = 0; ax022 < 32; ++ax022) {
    for (int32_t ax223 = 0; ax223 < 8; ++ax223) {
      for (int32_t ax323 = 0; ax323 < 8; ++ax323) {
        for (int32_t ax41 = 0; ax41 < 8; ++ax41) {
          ((int8_t*)T_reshape)[(((((ax022 * 512) + (ax223 * 64)) + (ax323 * 8)) + ax41))] = ((int8_t*)T_reshape1)[(((((ax022 * 512) + (ax223 * 64)) + (ax323 * 8)) + ax41))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 2048, 0);
  for (int32_t i6 = 0; i6 < 392; ++i6) {
    for (int32_t x2 = 0; x2 < 32; ++x2) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i6 * 32)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 64, 0);
      (void)move(((((int64_t)(x2 * 32)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 64, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 8, (int64_t)1, (int64_t)0);
      (void)store(Y, (int64_t)537264128, 32, ((i6 * 8192) + (x2 * 256)));
    }
  }
  for (int32_t ax023 = 0; ax023 < 392; ++ax023) {
    for (int32_t ax129 = 0; ax129 < 8; ++ax129) {
      for (int32_t ax224 = 0; ax224 < 32; ++ax224) {
        for (int32_t ax324 = 0; ax324 < 8; ++ax324) {
          ((int32_t*)out)[(((((ax023 * 2048) + (ax129 * 256)) + (ax224 * 8)) + ax324))] = ((int32_t*)Y)[(((((ax023 * 2048) + (ax224 * 64)) + (ax129 * 8)) + ax324))];
        }
      }
    }
  }
  for (int32_t ax130 = 0; ax130 < 56; ++ax130) {
    for (int32_t ax225 = 0; ax225 < 56; ++ax225) {
      for (int32_t ax325 = 0; ax325 < 256; ++ax325) {
        ((int32_t*)Y)[((((ax130 * 14336) + (ax225 * 256)) + ax325))] = ((int32_t*)out)[((((ax130 * 14336) + (ax225 * 256)) + ax325))];
      }
    }
  }
  for (int32_t h23 = 0; h23 < 56; ++h23) {
    for (int32_t w15 = 0; w15 < 56; ++w15) {
      for (int32_t c19 = 0; c19 < 256; ++c19) {
        ((int32_t*)out)[((((h23 * 14336) + (w15 * 256)) + c19))] = 8;
      }
    }
  }
  for (int32_t h24 = 0; h24 < 56; ++h24) {
    (void)load(Y, (int64_t)537264128, 7168, (h24 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h24 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h24 * 57344));
  }
  for (int32_t h25 = 0; h25 < 56; ++h25) {
    for (int32_t w16 = 0; w16 < 56; ++w16) {
      for (int32_t c20 = 0; c20 < 256; ++c20) {
        ((int32_t*)out)[((((h25 * 14336) + (w16 * 256)) + c20))] = ((int32_t*)tensor_29)[(c20)];
      }
    }
  }
  for (int32_t h26 = 0; h26 < 56; ++h26) {
    (void)load(out1, (int64_t)537264128, 7168, (h26 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h26 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 7168, (h26 * 57344));
  }
  for (int32_t h27 = 0; h27 < 56; ++h27) {
    for (int32_t w17 = 0; w17 < 56; ++w17) {
      for (int32_t c21 = 0; c21 < 256; ++c21) {
        ((int32_t*)out1)[((((h27 * 14336) + (w17 * 256)) + c21))] = 32768;
      }
    }
  }
  for (int32_t h28 = 0; h28 < 56; ++h28) {
    (void)load(Y, (int64_t)537264128, 7168, (h28 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h28 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h28 * 57344));
  }
  for (int32_t h29 = 0; h29 < 56; ++h29) {
    for (int32_t w18 = 0; w18 < 56; ++w18) {
      for (int32_t c22 = 0; c22 < 256; ++c22) {
        ((int32_t*)out1)[((((h29 * 14336) + (w18 * 256)) + c22))] = 16;
      }
    }
  }
  for (int32_t h30 = 0; h30 < 56; ++h30) {
    (void)load(out, (int64_t)537264128, 7168, (h30 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h30 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 7168, (h30 * 57344));
  }
  for (int32_t i112 = 0; i112 < 56; ++i112) {
    for (int32_t i210 = 0; i210 < 56; ++i210) {
      for (int32_t i310 = 0; i310 < 256; ++i310) {
        int32_t _12 = ((int32_t*)Y)[((((i112 * 14336) + (i210 * 256)) + i310))];
        int32_t _13 = (_12) < (127) ? (_12) : (127);
        ((int32_t*)out)[((((i112 * 14336) + (i210 * 256)) + i310))] = ((_13) > (-127) ? (_13) : (-127));
      }
    }
  }
  for (int32_t i113 = 0; i113 < 56; ++i113) {
    for (int32_t i211 = 0; i211 < 56; ++i211) {
      for (int32_t i311 = 0; i311 < 256; ++i311) {
        ((int8_t*)compute)[((((i113 * 14336) + (i211 * 256)) + i311))] = ((int8_t)((int32_t*)out)[((((i113 * 14336) + (i211 * 256)) + i311))]);
      }
    }
  }
  for (int32_t i114 = 0; i114 < 56; ++i114) {
    for (int32_t i212 = 0; i212 < 56; ++i212) {
      for (int32_t i312 = 0; i312 < 256; ++i312) {
        ((int32_t*)out1)[((((i114 * 14336) + (i212 * 256)) + i312))] = ((int32_t)((int8_t*)compute)[((((i114 * 14336) + (i212 * 256)) + i312))]);
      }
    }
  }
  for (int32_t h31 = 0; h31 < 56; ++h31) {
    for (int32_t w19 = 0; w19 < 56; ++w19) {
      for (int32_t c23 = 0; c23 < 256; ++c23) {
        ((int32_t*)out)[((((h31 * 14336) + (w19 * 256)) + c23))] = ((int32_t*)tensor_36)[(c23)];
      }
    }
  }
  for (int32_t h32 = 0; h32 < 56; ++h32) {
    (void)load(out1, (int64_t)537264128, 7168, (h32 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h32 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 7168, (h32 * 57344));
  }
  for (int32_t h33 = 0; h33 < 56; ++h33) {
    for (int32_t w20 = 0; w20 < 56; ++w20) {
      for (int32_t c24 = 0; c24 < 256; ++c24) {
        ((int32_t*)out1)[((((h33 * 14336) + (w20 * 256)) + c24))] = ((int32_t*)tensor_37)[(c24)];
      }
    }
  }
  for (int32_t h34 = 0; h34 < 56; ++h34) {
    (void)load(Y, (int64_t)537264128, 7168, (h34 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h34 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h34 * 57344));
  }
  for (int32_t h35 = 0; h35 < 56; ++h35) {
    for (int32_t w21 = 0; w21 < 56; ++w21) {
      for (int32_t c25 = 0; c25 < 256; ++c25) {
        ((int32_t*)out1)[((((h35 * 14336) + (w21 * 256)) + c25))] = 8;
      }
    }
  }
  for (int32_t h36 = 0; h36 < 56; ++h36) {
    (void)load(out, (int64_t)537264128, 7168, (h36 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h36 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 7168, (h36 * 57344));
  }
  for (int32_t h37 = 0; h37 < 56; ++h37) {
    for (int32_t w22 = 0; w22 < 56; ++w22) {
      for (int32_t c26 = 0; c26 < 256; ++c26) {
        ((int32_t*)out)[((((h37 * 14336) + (w22 * 256)) + c26))] = 4;
      }
    }
  }
  for (int32_t h38 = 0; h38 < 56; ++h38) {
    (void)load(Y, (int64_t)537264128, 7168, (h38 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h38 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h38 * 57344));
  }
  for (int32_t i115 = 0; i115 < 56; ++i115) {
    for (int32_t i213 = 0; i213 < 56; ++i213) {
      for (int32_t i313 = 0; i313 < 256; ++i313) {
        int32_t _14 = ((int32_t*)out1)[((((i115 * 14336) + (i213 * 256)) + i313))];
        int32_t _15 = (_14) < (127) ? (_14) : (127);
        ((int32_t*)out1)[((((i115 * 14336) + (i213 * 256)) + i313))] = ((_15) > (-127) ? (_15) : (-127));
      }
    }
  }
  for (int32_t i116 = 0; i116 < 56; ++i116) {
    for (int32_t i214 = 0; i214 < 56; ++i214) {
      for (int32_t i314 = 0; i314 < 256; ++i314) {
        ((int8_t*)compute)[((((i116 * 14336) + (i214 * 256)) + i314))] = ((int8_t)((int32_t*)out1)[((((i116 * 14336) + (i214 * 256)) + i314))]);
      }
    }
  }
  for (int32_t i117 = 0; i117 < 56; ++i117) {
    for (int32_t i215 = 0; i215 < 56; ++i215) {
      for (int32_t i315 = 0; i315 < 256; ++i315) {
        ((int32_t*)out)[((((i117 * 14336) + (i215 * 256)) + i315))] = ((int32_t)((int8_t*)compute)[((((i117 * 14336) + (i215 * 256)) + i315))]);
      }
    }
  }
  for (int32_t ax131 = 0; ax131 < 64; ++ax131) {
    for (int32_t ax226 = 0; ax226 < 56; ++ax226) {
      for (int32_t ax326 = 0; ax326 < 56; ++ax326) {
        ((float*)compute)[((((ax131 * 3136) + (ax226 * 56)) + ax326))] = (((float*)pad_data)[((((ax131 * 3136) + (ax226 * 56)) + ax326))] * 1.600000e+01f);
      }
    }
  }
  for (int32_t i118 = 0; i118 < 64; ++i118) {
    for (int32_t i216 = 0; i216 < 56; ++i216) {
      for (int32_t i316 = 0; i316 < 56; ++i316) {
        ((float*)compute)[((((i118 * 3136) + (i216 * 56)) + i316))] = roundf(((float*)compute)[((((i118 * 3136) + (i216 * 56)) + i316))]);
      }
    }
  }
  for (int32_t i119 = 0; i119 < 64; ++i119) {
    for (int32_t i217 = 0; i217 < 56; ++i217) {
      for (int32_t i317 = 0; i317 < 56; ++i317) {
        float _16 = ((float*)compute)[((((i119 * 3136) + (i217 * 56)) + i317))];
        float _17 = (_16) < (1.270000e+02f) ? (_16) : (1.270000e+02f);
        ((float*)compute)[((((i119 * 3136) + (i217 * 56)) + i317))] = ((_17) > (-1.270000e+02f) ? (_17) : (-1.270000e+02f));
      }
    }
  }
  for (int32_t i120 = 0; i120 < 64; ++i120) {
    for (int32_t i218 = 0; i218 < 56; ++i218) {
      for (int32_t i318 = 0; i318 < 56; ++i318) {
        ((int8_t*)compute1)[((((i120 * 3136) + (i218 * 56)) + i318))] = ((int8_t)((float*)compute)[((((i120 * 3136) + (i218 * 56)) + i318))]);
      }
    }
  }
  for (int32_t ax132 = 0; ax132 < 56; ++ax132) {
    for (int32_t ax227 = 0; ax227 < 56; ++ax227) {
      for (int32_t ax327 = 0; ax327 < 64; ++ax327) {
        ((int8_t*)compute)[((((ax132 * 3584) + (ax227 * 64)) + ax327))] = ((int8_t*)compute1)[((((ax327 * 3136) + (ax132 * 56)) + ax227))];
      }
    }
  }
  for (int32_t o13 = 0; o13 < 56; ++o13) {
    for (int32_t o23 = 0; o23 < 56; ++o23) {
      for (int32_t c27 = 0; c27 < 64; ++c27) {
        ((int8_t*)compute1)[((((o13 * 3584) + (o23 * 64)) + c27))] = ((int8_t*)compute)[((((o13 * 3584) + (o23 * 64)) + c27))];
      }
    }
  }
  for (int32_t ax024 = 0; ax024 < 3136; ++ax024) {
    for (int32_t ax133 = 0; ax133 < 64; ++ax133) {
      ((int8_t*)compute)[(((ax024 * 64) + ax133))] = ((int8_t*)compute1)[(((ax024 * 64) + ax133))];
    }
  }
  for (int32_t i02 = 0; i02 < 3136; ++i02) {
    for (int32_t i121 = 0; i121 < 64; ++i121) {
      ((int8_t*)compute1)[(((i02 * 64) + i121))] = ((int8_t*)compute)[(((i02 * 64) + i121))];
    }
  }
  for (int32_t ax025 = 0; ax025 < 392; ++ax025) {
    for (int32_t ax134 = 0; ax134 < 8; ++ax134) {
      for (int32_t ax228 = 0; ax228 < 8; ++ax228) {
        for (int32_t ax328 = 0; ax328 < 8; ++ax328) {
          ((int8_t*)compute)[(((((ax025 * 512) + (ax134 * 64)) + (ax228 * 8)) + ax328))] = ((int8_t*)compute1)[(((((ax025 * 512) + (ax134 * 64)) + (ax228 * 8)) + ax328))];
        }
      }
    }
  }
  for (int32_t ax026 = 0; ax026 < 392; ++ax026) {
    for (int32_t ax135 = 0; ax135 < 8; ++ax135) {
      for (int32_t ax229 = 0; ax229 < 8; ++ax229) {
        for (int32_t ax329 = 0; ax329 < 8; ++ax329) {
          ((int8_t*)compute1)[(((((ax026 * 512) + (ax135 * 64)) + (ax229 * 8)) + ax329))] = ((int8_t*)compute)[(((((ax026 * 512) + (ax229 * 64)) + (ax135 * 8)) + ax329))];
        }
      }
    }
  }
  for (int32_t ax027 = 0; ax027 < 392; ++ax027) {
    for (int32_t ax230 = 0; ax230 < 8; ++ax230) {
      for (int32_t ax330 = 0; ax330 < 8; ++ax330) {
        for (int32_t ax42 = 0; ax42 < 8; ++ax42) {
          ((int8_t*)compute)[(((((ax027 * 512) + (ax230 * 64)) + (ax330 * 8)) + ax42))] = ((int8_t*)compute1)[(((((ax027 * 512) + (ax230 * 64)) + (ax330 * 8)) + ax42))];
        }
      }
    }
  }
  (void)load(compute, (int64_t)536870912, 25088, 0);
  for (int32_t ax028 = 0; ax028 < 256; ++ax028) {
    for (int32_t ax136 = 0; ax136 < 64; ++ax136) {
      ((int8_t*)T_reshape1)[(((ax028 * 64) + ax136))] = ((int8_t*)kernel_48)[(((ax028 * 64) + ax136))];
    }
  }
  for (int32_t ax029 = 0; ax029 < 32; ++ax029) {
    for (int32_t ax137 = 0; ax137 < 8; ++ax137) {
      for (int32_t ax231 = 0; ax231 < 8; ++ax231) {
        for (int32_t ax331 = 0; ax331 < 8; ++ax331) {
          ((int8_t*)T_reshape)[(((((ax029 * 512) + (ax137 * 64)) + (ax231 * 8)) + ax331))] = ((int8_t*)T_reshape1)[(((((ax029 * 512) + (ax137 * 64)) + (ax231 * 8)) + ax331))];
        }
      }
    }
  }
  for (int32_t ax030 = 0; ax030 < 32; ++ax030) {
    for (int32_t ax138 = 0; ax138 < 8; ++ax138) {
      for (int32_t ax232 = 0; ax232 < 8; ++ax232) {
        for (int32_t ax332 = 0; ax332 < 8; ++ax332) {
          ((int8_t*)T_reshape1)[(((((ax030 * 512) + (ax138 * 64)) + (ax232 * 8)) + ax332))] = ((int8_t*)T_reshape)[(((((ax030 * 512) + (ax232 * 64)) + (ax138 * 8)) + ax332))];
        }
      }
    }
  }
  for (int32_t ax031 = 0; ax031 < 32; ++ax031) {
    for (int32_t ax233 = 0; ax233 < 8; ++ax233) {
      for (int32_t ax333 = 0; ax333 < 8; ++ax333) {
        for (int32_t ax43 = 0; ax43 < 8; ++ax43) {
          ((int8_t*)T_reshape)[(((((ax031 * 512) + (ax233 * 64)) + (ax333 * 8)) + ax43))] = ((int8_t*)T_reshape1)[(((((ax031 * 512) + (ax233 * 64)) + (ax333 * 8)) + ax43))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 2048, 0);
  for (int32_t i7 = 0; i7 < 392; ++i7) {
    for (int32_t x3 = 0; x3 < 32; ++x3) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i7 * 32)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 64, 0);
      (void)move(((((int64_t)(x3 * 32)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 64, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 8, (int64_t)1, (int64_t)0);
      (void)store(out1, (int64_t)537264128, 32, ((i7 * 8192) + (x3 * 256)));
    }
  }
  for (int32_t ax032 = 0; ax032 < 392; ++ax032) {
    for (int32_t ax139 = 0; ax139 < 8; ++ax139) {
      for (int32_t ax234 = 0; ax234 < 32; ++ax234) {
        for (int32_t ax334 = 0; ax334 < 8; ++ax334) {
          ((int32_t*)pad_data)[(((((ax032 * 2048) + (ax139 * 256)) + (ax234 * 8)) + ax334))] = ((int32_t*)out1)[(((((ax032 * 2048) + (ax234 * 64)) + (ax139 * 8)) + ax334))];
        }
      }
    }
  }
  for (int32_t ax033 = 0; ax033 < 3136; ++ax033) {
    for (int32_t ax140 = 0; ax140 < 256; ++ax140) {
      ((int32_t*)out1)[(((ax033 * 256) + ax140))] = ((int32_t*)pad_data)[(((ax033 * 256) + ax140))];
    }
  }
  for (int32_t ax141 = 0; ax141 < 56; ++ax141) {
    for (int32_t ax235 = 0; ax235 < 56; ++ax235) {
      for (int32_t ax335 = 0; ax335 < 256; ++ax335) {
        ((int32_t*)pad_data)[((((ax141 * 14336) + (ax235 * 256)) + ax335))] = ((int32_t*)out1)[((((ax141 * 14336) + (ax235 * 256)) + ax335))];
      }
    }
  }
  for (int32_t h39 = 0; h39 < 56; ++h39) {
    for (int32_t w23 = 0; w23 < 56; ++w23) {
      for (int32_t c28 = 0; c28 < 256; ++c28) {
        ((int32_t*)out1)[((((h39 * 14336) + (w23 * 256)) + c28))] = ((int32_t*)tensor_49)[(c28)];
      }
    }
  }
  for (int32_t h40 = 0; h40 < 56; ++h40) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h40 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h40 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 7168, (h40 * 57344));
  }
  for (int32_t h41 = 0; h41 < 56; ++h41) {
    for (int32_t w24 = 0; w24 < 56; ++w24) {
      for (int32_t c29 = 0; c29 < 256; ++c29) {
        ((int32_t*)pad_data)[((((h41 * 14336) + (w24 * 256)) + c29))] = 32;
      }
    }
  }
  for (int32_t h42 = 0; h42 < 56; ++h42) {
    (void)load(Y, (int64_t)537264128, 7168, (h42 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h42 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h42 * 57344));
  }
  for (int32_t h43 = 0; h43 < 56; ++h43) {
    for (int32_t w25 = 0; w25 < 56; ++w25) {
      for (int32_t c30 = 0; c30 < 256; ++c30) {
        ((int32_t*)pad_data)[((((h43 * 14336) + (w25 * 256)) + c30))] = 6;
      }
    }
  }
  for (int32_t h44 = 0; h44 < 56; ++h44) {
    (void)load(out1, (int64_t)537264128, 7168, (h44 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h44 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(Y, (int64_t)537395200, 7168, (h44 * 57344));
  }
  for (int32_t i122 = 0; i122 < 56; ++i122) {
    for (int32_t i219 = 0; i219 < 56; ++i219) {
      for (int32_t i319 = 0; i319 < 256; ++i319) {
        int32_t _18 = ((int32_t*)Y)[((((i122 * 14336) + (i219 * 256)) + i319))];
        int32_t _19 = (_18) < (127) ? (_18) : (127);
        ((int32_t*)out1)[((((i122 * 14336) + (i219 * 256)) + i319))] = ((_19) > (-127) ? (_19) : (-127));
      }
    }
  }
  for (int32_t i123 = 0; i123 < 56; ++i123) {
    for (int32_t i220 = 0; i220 < 56; ++i220) {
      for (int32_t i320 = 0; i320 < 256; ++i320) {
        ((int8_t*)compute)[((((i123 * 14336) + (i220 * 256)) + i320))] = ((int8_t)((int32_t*)out1)[((((i123 * 14336) + (i220 * 256)) + i320))]);
      }
    }
  }
  for (int32_t i124 = 0; i124 < 56; ++i124) {
    for (int32_t i221 = 0; i221 < 56; ++i221) {
      for (int32_t i321 = 0; i321 < 256; ++i321) {
        ((int32_t*)pad_data)[((((i124 * 14336) + (i221 * 256)) + i321))] = ((int32_t)((int8_t*)compute)[((((i124 * 14336) + (i221 * 256)) + i321))]);
      }
    }
  }
  for (int32_t h45 = 0; h45 < 56; ++h45) {
    (void)load(out, (int64_t)537264128, 7168, (h45 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h45 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h45 * 57344));
  }
  for (int32_t h46 = 0; h46 < 56; ++h46) {
    for (int32_t w26 = 0; w26 < 56; ++w26) {
      for (int32_t c31 = 0; c31 < 256; ++c31) {
        ((int32_t*)out)[((((h46 * 14336) + (w26 * 256)) + c31))] = 0;
      }
    }
  }
  for (int32_t h47 = 0; h47 < 56; ++h47) {
    (void)load(out1, (int64_t)537264128, 7168, (h47 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h47 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h47 * 57344));
  }
  for (int32_t i125 = 0; i125 < 56; ++i125) {
    for (int32_t i222 = 0; i222 < 56; ++i222) {
      for (int32_t i322 = 0; i322 < 256; ++i322) {
        int32_t _20 = ((int32_t*)pad_data)[((((i125 * 14336) + (i222 * 256)) + i322))];
        int32_t _21 = (_20) < (127) ? (_20) : (127);
        ((int32_t*)out1)[((((i125 * 14336) + (i222 * 256)) + i322))] = ((_21) > (-127) ? (_21) : (-127));
      }
    }
  }
  for (int32_t i126 = 0; i126 < 56; ++i126) {
    for (int32_t i223 = 0; i223 < 56; ++i223) {
      for (int32_t i323 = 0; i323 < 256; ++i323) {
        ((int8_t*)compute)[((((i126 * 14336) + (i223 * 256)) + i323))] = ((int8_t)((int32_t*)out1)[((((i126 * 14336) + (i223 * 256)) + i323))]);
      }
    }
  }
  for (int32_t o14 = 0; o14 < 56; ++o14) {
    for (int32_t o24 = 0; o24 < 56; ++o24) {
      for (int32_t c32 = 0; c32 < 256; ++c32) {
        ((int8_t*)compute1)[((((o14 * 14336) + (o24 * 256)) + c32))] = ((int8_t*)compute)[((((o14 * 14336) + (o24 * 256)) + c32))];
      }
    }
  }
  for (int32_t ax034 = 0; ax034 < 3136; ++ax034) {
    for (int32_t ax142 = 0; ax142 < 256; ++ax142) {
      ((int8_t*)out)[(((ax034 * 256) + ax142))] = ((int8_t*)compute1)[(((ax034 * 256) + ax142))];
    }
  }
  for (int32_t i03 = 0; i03 < 3136; ++i03) {
    for (int32_t i127 = 0; i127 < 256; ++i127) {
      ((int8_t*)compute1)[(((i03 * 256) + i127))] = ((int8_t*)out)[(((i03 * 256) + i127))];
    }
  }
  for (int32_t ax035 = 0; ax035 < 392; ++ax035) {
    for (int32_t ax143 = 0; ax143 < 8; ++ax143) {
      for (int32_t ax236 = 0; ax236 < 32; ++ax236) {
        for (int32_t ax336 = 0; ax336 < 8; ++ax336) {
          ((int8_t*)pad_data)[(((((ax035 * 2048) + (ax143 * 256)) + (ax236 * 8)) + ax336))] = ((int8_t*)compute1)[(((((ax035 * 2048) + (ax143 * 256)) + (ax236 * 8)) + ax336))];
        }
      }
    }
  }
  for (int32_t ax036 = 0; ax036 < 392; ++ax036) {
    for (int32_t ax144 = 0; ax144 < 32; ++ax144) {
      for (int32_t ax237 = 0; ax237 < 8; ++ax237) {
        for (int32_t ax337 = 0; ax337 < 8; ++ax337) {
          ((int8_t*)compute1)[(((((ax036 * 2048) + (ax144 * 64)) + (ax237 * 8)) + ax337))] = ((int8_t*)pad_data)[(((((ax036 * 2048) + (ax237 * 256)) + (ax144 * 8)) + ax337))];
        }
      }
    }
  }
  for (int32_t ax037 = 0; ax037 < 392; ++ax037) {
    for (int32_t ax238 = 0; ax238 < 32; ++ax238) {
      for (int32_t ax338 = 0; ax338 < 8; ++ax338) {
        for (int32_t ax44 = 0; ax44 < 8; ++ax44) {
          ((int8_t*)out1)[(((((ax037 * 2048) + (ax238 * 64)) + (ax338 * 8)) + ax44))] = ((int8_t*)compute1)[(((((ax037 * 2048) + (ax238 * 64)) + (ax338 * 8)) + ax44))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536870912, 100352, 0);
  for (int32_t ax038 = 0; ax038 < 64; ++ax038) {
    for (int32_t ax145 = 0; ax145 < 256; ++ax145) {
      ((int8_t*)T_reshape1)[(((ax038 * 256) + ax145))] = ((int8_t*)kernel_62)[(((ax038 * 256) + ax145))];
    }
  }
  for (int32_t ax039 = 0; ax039 < 8; ++ax039) {
    for (int32_t ax146 = 0; ax146 < 8; ++ax146) {
      for (int32_t ax239 = 0; ax239 < 32; ++ax239) {
        for (int32_t ax339 = 0; ax339 < 8; ++ax339) {
          ((int8_t*)T_reshape)[(((((ax039 * 2048) + (ax146 * 256)) + (ax239 * 8)) + ax339))] = ((int8_t*)T_reshape1)[(((((ax039 * 2048) + (ax146 * 256)) + (ax239 * 8)) + ax339))];
        }
      }
    }
  }
  for (int32_t ax040 = 0; ax040 < 8; ++ax040) {
    for (int32_t ax147 = 0; ax147 < 32; ++ax147) {
      for (int32_t ax240 = 0; ax240 < 8; ++ax240) {
        for (int32_t ax340 = 0; ax340 < 8; ++ax340) {
          ((int8_t*)T_reshape1)[(((((ax040 * 2048) + (ax147 * 64)) + (ax240 * 8)) + ax340))] = ((int8_t*)T_reshape)[(((((ax040 * 2048) + (ax240 * 256)) + (ax147 * 8)) + ax340))];
        }
      }
    }
  }
  for (int32_t ax041 = 0; ax041 < 8; ++ax041) {
    for (int32_t ax241 = 0; ax241 < 32; ++ax241) {
      for (int32_t ax341 = 0; ax341 < 8; ++ax341) {
        for (int32_t ax45 = 0; ax45 < 8; ++ax45) {
          ((int8_t*)T_reshape)[(((((ax041 * 2048) + (ax241 * 64)) + (ax341 * 8)) + ax45))] = ((int8_t*)T_reshape1)[(((((ax041 * 2048) + (ax241 * 64)) + (ax341 * 8)) + ax45))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 2048, 0);
  for (int32_t i8 = 0; i8 < 392; ++i8) {
    for (int32_t x4 = 0; x4 < 8; ++x4) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i8 * 128)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x4 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i8 * 2048) + (x4 * 256)));
    }
  }
  for (int32_t ax042 = 0; ax042 < 392; ++ax042) {
    for (int32_t ax148 = 0; ax148 < 8; ++ax148) {
      for (int32_t ax242 = 0; ax242 < 8; ++ax242) {
        for (int32_t ax342 = 0; ax342 < 8; ++ax342) {
          ((int32_t*)out)[(((((ax042 * 512) + (ax148 * 64)) + (ax242 * 8)) + ax342))] = ((int32_t*)compute1)[(((((ax042 * 512) + (ax242 * 64)) + (ax148 * 8)) + ax342))];
        }
      }
    }
  }
  for (int32_t ax043 = 0; ax043 < 3136; ++ax043) {
    for (int32_t ax149 = 0; ax149 < 64; ++ax149) {
      ((int32_t*)compute1)[(((ax043 * 64) + ax149))] = ((int32_t*)out)[(((ax043 * 64) + ax149))];
    }
  }
  for (int32_t i04 = 0; i04 < 3136; ++i04) {
    for (int32_t i128 = 0; i128 < 64; ++i128) {
      ((int32_t*)pad_data)[(((i04 * 64) + i128))] = ((int32_t*)compute1)[(((i04 * 64) + i128))];
    }
  }
  for (int32_t ax150 = 0; ax150 < 56; ++ax150) {
    for (int32_t ax243 = 0; ax243 < 56; ++ax243) {
      for (int32_t ax343 = 0; ax343 < 64; ++ax343) {
        ((int32_t*)compute1)[((((ax150 * 3584) + (ax243 * 64)) + ax343))] = ((int32_t*)pad_data)[((((ax150 * 3584) + (ax243 * 64)) + ax343))];
      }
    }
  }
  for (int32_t h48 = 0; h48 < 56; ++h48) {
    for (int32_t w27 = 0; w27 < 56; ++w27) {
      for (int32_t c33 = 0; c33 < 64; ++c33) {
        ((int32_t*)out1)[((((h48 * 3584) + (w27 * 64)) + c33))] = 9;
      }
    }
  }
  for (int32_t h49 = 0; h49 < 56; ++h49) {
    (void)load(compute1, (int64_t)537264128, 1792, (h49 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h49 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h49 * 14336));
  }
  for (int32_t h50 = 0; h50 < 56; ++h50) {
    for (int32_t w28 = 0; w28 < 56; ++w28) {
      for (int32_t c34 = 0; c34 < 64; ++c34) {
        ((int32_t*)compute1)[((((h50 * 3584) + (w28 * 64)) + c34))] = ((int32_t*)tensor_64)[(c34)];
      }
    }
  }
  for (int32_t h51 = 0; h51 < 56; ++h51) {
    (void)load(out, (int64_t)537264128, 1792, (h51 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h51 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h51 * 14336));
  }
  for (int32_t h52 = 0; h52 < 56; ++h52) {
    for (int32_t w29 = 0; w29 < 56; ++w29) {
      for (int32_t c35 = 0; c35 < 64; ++c35) {
        ((int32_t*)compute1)[((((h52 * 3584) + (w29 * 64)) + c35))] = ((int32_t*)tensor_65)[(c35)];
      }
    }
  }
  for (int32_t h53 = 0; h53 < 56; ++h53) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h53 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h53 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h53 * 14336));
  }
  for (int32_t h54 = 0; h54 < 56; ++h54) {
    for (int32_t w30 = 0; w30 < 56; ++w30) {
      for (int32_t c36 = 0; c36 < 64; ++c36) {
        ((int32_t*)compute1)[((((h54 * 3584) + (w30 * 64)) + c36))] = 0;
      }
    }
  }
  for (int32_t h55 = 0; h55 < 56; ++h55) {
    (void)load(out1, (int64_t)537264128, 1792, (h55 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h55 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h55 * 14336));
  }
  for (int32_t h56 = 0; h56 < 56; ++h56) {
    for (int32_t w31 = 0; w31 < 56; ++w31) {
      for (int32_t c37 = 0; c37 < 64; ++c37) {
        ((int32_t*)compute1)[((((h56 * 3584) + (w31 * 64)) + c37))] = 65536;
      }
    }
  }
  for (int32_t h57 = 0; h57 < 56; ++h57) {
    (void)load(out, (int64_t)537264128, 1792, (h57 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h57 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h57 * 14336));
  }
  for (int32_t h58 = 0; h58 < 56; ++h58) {
    for (int32_t w32 = 0; w32 < 56; ++w32) {
      for (int32_t c38 = 0; c38 < 64; ++c38) {
        ((int32_t*)compute1)[((((h58 * 3584) + (w32 * 64)) + c38))] = 17;
      }
    }
  }
  for (int32_t h59 = 0; h59 < 56; ++h59) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h59 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h59 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h59 * 14336));
  }
  for (int32_t i129 = 0; i129 < 56; ++i129) {
    for (int32_t i224 = 0; i224 < 56; ++i224) {
      for (int32_t i324 = 0; i324 < 64; ++i324) {
        int32_t _22 = ((int32_t*)out1)[((((i129 * 3584) + (i224 * 64)) + i324))];
        int32_t _23 = (_22) < (127) ? (_22) : (127);
        ((int32_t*)compute1)[((((i129 * 3584) + (i224 * 64)) + i324))] = ((_23) > (-127) ? (_23) : (-127));
      }
    }
  }
  for (int32_t i130 = 0; i130 < 56; ++i130) {
    for (int32_t i225 = 0; i225 < 56; ++i225) {
      for (int32_t i325 = 0; i325 < 64; ++i325) {
        ((int8_t*)out)[((((i130 * 3584) + (i225 * 64)) + i325))] = ((int8_t)((int32_t*)compute1)[((((i130 * 3584) + (i225 * 64)) + i325))]);
      }
    }
  }
  for (int32_t i131 = 0; i131 < 58; ++i131) {
    for (int32_t i226 = 0; i226 < 58; ++i226) {
      for (int32_t i326 = 0; i326 < 64; ++i326) {
        ((int8_t*)compute1)[((((i131 * 3712) + (i226 * 64)) + i326))] = (((((1 <= i131) && (i131 < 57)) && (1 <= i226)) && (i226 < 57)) ? ((int8_t*)out)[(((((i131 * 3584) + (i226 * 64)) + i326) - 3648))] : (int8_t)0);
      }
    }
  }
  for (int32_t o15 = 0; o15 < 56; ++o15) {
    for (int32_t o25 = 0; o25 < 56; ++o25) {
      for (int32_t k11 = 0; k11 < 3; ++k11) {
        for (int32_t k21 = 0; k21 < 3; ++k21) {
          for (int32_t c39 = 0; c39 < 64; ++c39) {
            ((int8_t*)pad_data)[((((((o15 * 32256) + (o25 * 576)) + (k11 * 192)) + (k21 * 64)) + c39))] = ((int8_t*)compute1)[((((((k11 * 3712) + (o15 * 3712)) + (k21 * 64)) + (o25 * 64)) + c39))];
          }
        }
      }
    }
  }
  for (int32_t ax044 = 0; ax044 < 3136; ++ax044) {
    for (int32_t ax151 = 0; ax151 < 576; ++ax151) {
      ((int8_t*)compute1)[(((ax044 * 576) + ax151))] = ((int8_t*)pad_data)[(((ax044 * 576) + ax151))];
    }
  }
  for (int32_t ax045 = 0; ax045 < 392; ++ax045) {
    for (int32_t ax152 = 0; ax152 < 8; ++ax152) {
      for (int32_t ax244 = 0; ax244 < 72; ++ax244) {
        for (int32_t ax344 = 0; ax344 < 8; ++ax344) {
          ((int8_t*)out1)[(((((ax045 * 4608) + (ax152 * 576)) + (ax244 * 8)) + ax344))] = ((int8_t*)compute1)[(((((ax045 * 4608) + (ax152 * 576)) + (ax244 * 8)) + ax344))];
        }
      }
    }
  }
  for (int32_t ax046 = 0; ax046 < 392; ++ax046) {
    for (int32_t ax153 = 0; ax153 < 72; ++ax153) {
      for (int32_t ax245 = 0; ax245 < 8; ++ax245) {
        for (int32_t ax345 = 0; ax345 < 8; ++ax345) {
          ((int8_t*)compute1)[(((((ax046 * 4608) + (ax153 * 64)) + (ax245 * 8)) + ax345))] = ((int8_t*)out1)[(((((ax046 * 4608) + (ax245 * 576)) + (ax153 * 8)) + ax345))];
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 225792, 0);
  for (int32_t ax047 = 0; ax047 < 64; ++ax047) {
    for (int32_t ax154 = 0; ax154 < 576; ++ax154) {
      ((int8_t*)T_reshape1)[(((ax047 * 576) + ax154))] = ((int8_t*)kernel_72)[(((ax047 * 576) + ax154))];
    }
  }
  for (int32_t ax048 = 0; ax048 < 8; ++ax048) {
    for (int32_t ax155 = 0; ax155 < 8; ++ax155) {
      for (int32_t ax246 = 0; ax246 < 72; ++ax246) {
        for (int32_t ax346 = 0; ax346 < 8; ++ax346) {
          ((int8_t*)T_reshape)[(((((ax048 * 4608) + (ax155 * 576)) + (ax246 * 8)) + ax346))] = ((int8_t*)T_reshape1)[(((((ax048 * 4608) + (ax155 * 576)) + (ax246 * 8)) + ax346))];
        }
      }
    }
  }
  for (int32_t ax049 = 0; ax049 < 8; ++ax049) {
    for (int32_t ax156 = 0; ax156 < 72; ++ax156) {
      for (int32_t ax247 = 0; ax247 < 8; ++ax247) {
        for (int32_t ax347 = 0; ax347 < 8; ++ax347) {
          ((int8_t*)T_reshape1)[(((((ax049 * 4608) + (ax156 * 64)) + (ax247 * 8)) + ax347))] = ((int8_t*)T_reshape)[(((((ax049 * 4608) + (ax247 * 576)) + (ax156 * 8)) + ax347))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536936448, 4608, 0);
  for (int32_t i9 = 0; i9 < 392; ++i9) {
    for (int32_t x5 = 0; x5 < 8; ++x5) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i9 * 288)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
      (void)move(((((int64_t)(x5 * 288)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i9 * 2048) + (x5 * 256)));
    }
  }
  for (int32_t ax050 = 0; ax050 < 392; ++ax050) {
    for (int32_t ax157 = 0; ax157 < 8; ++ax157) {
      for (int32_t ax248 = 0; ax248 < 8; ++ax248) {
        for (int32_t ax348 = 0; ax348 < 8; ++ax348) {
          ((int32_t*)out)[(((((ax050 * 512) + (ax157 * 64)) + (ax248 * 8)) + ax348))] = ((int32_t*)compute1)[(((((ax050 * 512) + (ax248 * 64)) + (ax157 * 8)) + ax348))];
        }
      }
    }
  }
  for (int32_t ax051 = 0; ax051 < 3136; ++ax051) {
    for (int32_t ax158 = 0; ax158 < 64; ++ax158) {
      ((int32_t*)compute1)[(((ax051 * 64) + ax158))] = ((int32_t*)out)[(((ax051 * 64) + ax158))];
    }
  }
  for (int32_t i05 = 0; i05 < 3136; ++i05) {
    for (int32_t i132 = 0; i132 < 64; ++i132) {
      ((int32_t*)pad_data)[(((i05 * 64) + i132))] = ((int32_t*)compute1)[(((i05 * 64) + i132))];
    }
  }
  for (int32_t ax159 = 0; ax159 < 56; ++ax159) {
    for (int32_t ax249 = 0; ax249 < 56; ++ax249) {
      for (int32_t ax349 = 0; ax349 < 64; ++ax349) {
        ((int32_t*)compute1)[((((ax159 * 3584) + (ax249 * 64)) + ax349))] = ((int32_t*)pad_data)[((((ax159 * 3584) + (ax249 * 64)) + ax349))];
      }
    }
  }
  for (int32_t h60 = 0; h60 < 56; ++h60) {
    for (int32_t w33 = 0; w33 < 56; ++w33) {
      for (int32_t c40 = 0; c40 < 64; ++c40) {
        ((int32_t*)out1)[((((h60 * 3584) + (w33 * 64)) + c40))] = ((int32_t*)tensor_73)[(c40)];
      }
    }
  }
  for (int32_t h61 = 0; h61 < 56; ++h61) {
    (void)load(compute1, (int64_t)537264128, 1792, (h61 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h61 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h61 * 14336));
  }
  for (int32_t h62 = 0; h62 < 56; ++h62) {
    for (int32_t w34 = 0; w34 < 56; ++w34) {
      for (int32_t c41 = 0; c41 < 64; ++c41) {
        ((int32_t*)compute1)[((((h62 * 3584) + (w34 * 64)) + c41))] = 0;
      }
    }
  }
  for (int32_t h63 = 0; h63 < 56; ++h63) {
    (void)load(out, (int64_t)537264128, 1792, (h63 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h63 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h63 * 14336));
  }
  for (int32_t h64 = 0; h64 < 56; ++h64) {
    for (int32_t w35 = 0; w35 < 56; ++w35) {
      for (int32_t c42 = 0; c42 < 64; ++c42) {
        ((int32_t*)compute1)[((((h64 * 3584) + (w35 * 64)) + c42))] = 128;
      }
    }
  }
  for (int32_t h65 = 0; h65 < 56; ++h65) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h65 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h65 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h65 * 14336));
  }
  for (int32_t h66 = 0; h66 < 56; ++h66) {
    for (int32_t w36 = 0; w36 < 56; ++w36) {
      for (int32_t c43 = 0; c43 < 64; ++c43) {
        ((int32_t*)compute1)[((((h66 * 3584) + (w36 * 64)) + c43))] = 8;
      }
    }
  }
  for (int32_t h67 = 0; h67 < 56; ++h67) {
    (void)load(out1, (int64_t)537264128, 1792, (h67 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h67 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h67 * 14336));
  }
  for (int32_t i133 = 0; i133 < 56; ++i133) {
    for (int32_t i227 = 0; i227 < 56; ++i227) {
      for (int32_t i327 = 0; i327 < 64; ++i327) {
        int32_t _24 = ((int32_t*)out)[((((i133 * 3584) + (i227 * 64)) + i327))];
        int32_t _25 = (_24) < (127) ? (_24) : (127);
        ((int32_t*)compute1)[((((i133 * 3584) + (i227 * 64)) + i327))] = ((_25) > (-127) ? (_25) : (-127));
      }
    }
  }
  for (int32_t i134 = 0; i134 < 56; ++i134) {
    for (int32_t i228 = 0; i228 < 56; ++i228) {
      for (int32_t i328 = 0; i328 < 64; ++i328) {
        ((int8_t*)pad_data)[((((i134 * 3584) + (i228 * 64)) + i328))] = ((int8_t)((int32_t*)compute1)[((((i134 * 3584) + (i228 * 64)) + i328))]);
      }
    }
  }
  for (int32_t o16 = 0; o16 < 56; ++o16) {
    for (int32_t o26 = 0; o26 < 56; ++o26) {
      for (int32_t c44 = 0; c44 < 64; ++c44) {
        ((int8_t*)compute1)[((((o16 * 3584) + (o26 * 64)) + c44))] = ((int8_t*)pad_data)[((((o16 * 3584) + (o26 * 64)) + c44))];
      }
    }
  }
  for (int32_t ax052 = 0; ax052 < 3136; ++ax052) {
    for (int32_t ax160 = 0; ax160 < 64; ++ax160) {
      ((int8_t*)out1)[(((ax052 * 64) + ax160))] = ((int8_t*)compute1)[(((ax052 * 64) + ax160))];
    }
  }
  for (int32_t i06 = 0; i06 < 3136; ++i06) {
    for (int32_t i135 = 0; i135 < 64; ++i135) {
      ((int8_t*)compute1)[(((i06 * 64) + i135))] = ((int8_t*)out1)[(((i06 * 64) + i135))];
    }
  }
  for (int32_t ax053 = 0; ax053 < 392; ++ax053) {
    for (int32_t ax161 = 0; ax161 < 8; ++ax161) {
      for (int32_t ax250 = 0; ax250 < 8; ++ax250) {
        for (int32_t ax350 = 0; ax350 < 8; ++ax350) {
          ((int8_t*)out)[(((((ax053 * 512) + (ax161 * 64)) + (ax250 * 8)) + ax350))] = ((int8_t*)compute1)[(((((ax053 * 512) + (ax161 * 64)) + (ax250 * 8)) + ax350))];
        }
      }
    }
  }
  for (int32_t ax054 = 0; ax054 < 392; ++ax054) {
    for (int32_t ax162 = 0; ax162 < 8; ++ax162) {
      for (int32_t ax251 = 0; ax251 < 8; ++ax251) {
        for (int32_t ax351 = 0; ax351 < 8; ++ax351) {
          ((int8_t*)compute1)[(((((ax054 * 512) + (ax162 * 64)) + (ax251 * 8)) + ax351))] = ((int8_t*)out)[(((((ax054 * 512) + (ax251 * 64)) + (ax162 * 8)) + ax351))];
        }
      }
    }
  }
  for (int32_t ax055 = 0; ax055 < 392; ++ax055) {
    for (int32_t ax252 = 0; ax252 < 8; ++ax252) {
      for (int32_t ax352 = 0; ax352 < 8; ++ax352) {
        for (int32_t ax46 = 0; ax46 < 8; ++ax46) {
          ((int8_t*)pad_data)[(((((ax055 * 512) + (ax252 * 64)) + (ax352 * 8)) + ax46))] = ((int8_t*)compute1)[(((((ax055 * 512) + (ax252 * 64)) + (ax352 * 8)) + ax46))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25088, 0);
  for (int32_t ax056 = 0; ax056 < 256; ++ax056) {
    for (int32_t ax163 = 0; ax163 < 64; ++ax163) {
      ((int8_t*)T_reshape)[(((ax056 * 64) + ax163))] = ((int8_t*)kernel_80)[(((ax056 * 64) + ax163))];
    }
  }
  for (int32_t ax057 = 0; ax057 < 32; ++ax057) {
    for (int32_t ax164 = 0; ax164 < 8; ++ax164) {
      for (int32_t ax253 = 0; ax253 < 8; ++ax253) {
        for (int32_t ax353 = 0; ax353 < 8; ++ax353) {
          ((int8_t*)T_reshape1)[(((((ax057 * 512) + (ax164 * 64)) + (ax253 * 8)) + ax353))] = ((int8_t*)T_reshape)[(((((ax057 * 512) + (ax164 * 64)) + (ax253 * 8)) + ax353))];
        }
      }
    }
  }
  for (int32_t ax058 = 0; ax058 < 32; ++ax058) {
    for (int32_t ax165 = 0; ax165 < 8; ++ax165) {
      for (int32_t ax254 = 0; ax254 < 8; ++ax254) {
        for (int32_t ax354 = 0; ax354 < 8; ++ax354) {
          ((int8_t*)T_reshape)[(((((ax058 * 512) + (ax165 * 64)) + (ax254 * 8)) + ax354))] = ((int8_t*)T_reshape1)[(((((ax058 * 512) + (ax254 * 64)) + (ax165 * 8)) + ax354))];
        }
      }
    }
  }
  for (int32_t ax059 = 0; ax059 < 32; ++ax059) {
    for (int32_t ax255 = 0; ax255 < 8; ++ax255) {
      for (int32_t ax355 = 0; ax355 < 8; ++ax355) {
        for (int32_t ax47 = 0; ax47 < 8; ++ax47) {
          ((int8_t*)T_reshape1)[(((((ax059 * 512) + (ax255 * 64)) + (ax355 * 8)) + ax47))] = ((int8_t*)T_reshape)[(((((ax059 * 512) + (ax255 * 64)) + (ax355 * 8)) + ax47))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536936448, 2048, 0);
  for (int32_t i10 = 0; i10 < 392; ++i10) {
    for (int32_t x6 = 0; x6 < 32; ++x6) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i10 * 32)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 64, 0);
      (void)move(((((int64_t)(x6 * 32)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 64, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 8, (int64_t)1, (int64_t)0);
      (void)store(out1, (int64_t)537264128, 32, ((i10 * 8192) + (x6 * 256)));
    }
  }
  for (int32_t ax060 = 0; ax060 < 392; ++ax060) {
    for (int32_t ax166 = 0; ax166 < 8; ++ax166) {
      for (int32_t ax256 = 0; ax256 < 32; ++ax256) {
        for (int32_t ax356 = 0; ax356 < 8; ++ax356) {
          ((int32_t*)out)[(((((ax060 * 2048) + (ax166 * 256)) + (ax256 * 8)) + ax356))] = ((int32_t*)out1)[(((((ax060 * 2048) + (ax256 * 64)) + (ax166 * 8)) + ax356))];
        }
      }
    }
  }
  for (int32_t ax167 = 0; ax167 < 56; ++ax167) {
    for (int32_t ax257 = 0; ax257 < 56; ++ax257) {
      for (int32_t ax357 = 0; ax357 < 256; ++ax357) {
        ((int32_t*)pad_data)[((((ax167 * 14336) + (ax257 * 256)) + ax357))] = ((int32_t*)out)[((((ax167 * 14336) + (ax257 * 256)) + ax357))];
      }
    }
  }
  for (int32_t h68 = 0; h68 < 56; ++h68) {
    for (int32_t w37 = 0; w37 < 56; ++w37) {
      for (int32_t c45 = 0; c45 < 256; ++c45) {
        ((int32_t*)out1)[((((h68 * 14336) + (w37 * 256)) + c45))] = 8;
      }
    }
  }
  for (int32_t h69 = 0; h69 < 56; ++h69) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h69 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h69 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h69 * 57344));
  }
  for (int32_t h70 = 0; h70 < 56; ++h70) {
    for (int32_t w38 = 0; w38 < 56; ++w38) {
      for (int32_t c46 = 0; c46 < 256; ++c46) {
        ((int32_t*)pad_data)[((((h70 * 14336) + (w38 * 256)) + c46))] = ((int32_t*)tensor_82)[(c46)];
      }
    }
  }
  for (int32_t h71 = 0; h71 < 56; ++h71) {
    (void)load(out, (int64_t)537264128, 7168, (h71 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h71 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h71 * 57344));
  }
  for (int32_t h72 = 0; h72 < 56; ++h72) {
    for (int32_t w39 = 0; w39 < 56; ++w39) {
      for (int32_t c47 = 0; c47 < 256; ++c47) {
        ((int32_t*)out)[((((h72 * 14336) + (w39 * 256)) + c47))] = 32768;
      }
    }
  }
  for (int32_t h73 = 0; h73 < 56; ++h73) {
    (void)load(out1, (int64_t)537264128, 7168, (h73 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h73 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h73 * 57344));
  }
  for (int32_t h74 = 0; h74 < 56; ++h74) {
    for (int32_t w40 = 0; w40 < 56; ++w40) {
      for (int32_t c48 = 0; c48 < 256; ++c48) {
        ((int32_t*)out1)[((((h74 * 14336) + (w40 * 256)) + c48))] = 16;
      }
    }
  }
  for (int32_t h75 = 0; h75 < 56; ++h75) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h75 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h75 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h75 * 57344));
  }
  for (int32_t i136 = 0; i136 < 56; ++i136) {
    for (int32_t i229 = 0; i229 < 56; ++i229) {
      for (int32_t i329 = 0; i329 < 256; ++i329) {
        int32_t _26 = ((int32_t*)out)[((((i136 * 14336) + (i229 * 256)) + i329))];
        int32_t _27 = (_26) < (127) ? (_26) : (127);
        ((int32_t*)out)[((((i136 * 14336) + (i229 * 256)) + i329))] = ((_27) > (-127) ? (_27) : (-127));
      }
    }
  }
  for (int32_t i137 = 0; i137 < 56; ++i137) {
    for (int32_t i230 = 0; i230 < 56; ++i230) {
      for (int32_t i330 = 0; i330 < 256; ++i330) {
        ((int8_t*)compute1)[((((i137 * 14336) + (i230 * 256)) + i330))] = ((int8_t)((int32_t*)out)[((((i137 * 14336) + (i230 * 256)) + i330))]);
      }
    }
  }
  for (int32_t i138 = 0; i138 < 56; ++i138) {
    for (int32_t i231 = 0; i231 < 56; ++i231) {
      for (int32_t i331 = 0; i331 < 256; ++i331) {
        ((int32_t*)pad_data)[((((i138 * 14336) + (i231 * 256)) + i331))] = ((int32_t)((int8_t*)compute1)[((((i138 * 14336) + (i231 * 256)) + i331))]);
      }
    }
  }
  for (int32_t h76 = 0; h76 < 56; ++h76) {
    for (int32_t w41 = 0; w41 < 56; ++w41) {
      for (int32_t c49 = 0; c49 < 256; ++c49) {
        ((int32_t*)out1)[((((h76 * 14336) + (w41 * 256)) + c49))] = ((int32_t*)tensor_89)[(c49)];
      }
    }
  }
  for (int32_t h77 = 0; h77 < 56; ++h77) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h77 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h77 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h77 * 57344));
  }
  for (int32_t h78 = 0; h78 < 56; ++h78) {
    for (int32_t w42 = 0; w42 < 56; ++w42) {
      for (int32_t c50 = 0; c50 < 256; ++c50) {
        ((int32_t*)pad_data)[((((h78 * 14336) + (w42 * 256)) + c50))] = ((int32_t*)tensor_90)[(c50)];
      }
    }
  }
  for (int32_t h79 = 0; h79 < 56; ++h79) {
    (void)load(out, (int64_t)537264128, 7168, (h79 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h79 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h79 * 57344));
  }
  for (int32_t h80 = 0; h80 < 56; ++h80) {
    for (int32_t w43 = 0; w43 < 56; ++w43) {
      for (int32_t c51 = 0; c51 < 256; ++c51) {
        ((int32_t*)out)[((((h80 * 14336) + (w43 * 256)) + c51))] = 8;
      }
    }
  }
  for (int32_t h81 = 0; h81 < 56; ++h81) {
    (void)load(out1, (int64_t)537264128, 7168, (h81 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h81 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h81 * 57344));
  }
  for (int32_t h82 = 0; h82 < 56; ++h82) {
    for (int32_t w44 = 0; w44 < 56; ++w44) {
      for (int32_t c52 = 0; c52 < 256; ++c52) {
        ((int32_t*)out1)[((((h82 * 14336) + (w44 * 256)) + c52))] = 4;
      }
    }
  }
  for (int32_t h83 = 0; h83 < 56; ++h83) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h83 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h83 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h83 * 57344));
  }
  for (int32_t i139 = 0; i139 < 56; ++i139) {
    for (int32_t i232 = 0; i232 < 56; ++i232) {
      for (int32_t i332 = 0; i332 < 256; ++i332) {
        int32_t _28 = ((int32_t*)out)[((((i139 * 14336) + (i232 * 256)) + i332))];
        int32_t _29 = (_28) < (127) ? (_28) : (127);
        ((int32_t*)out)[((((i139 * 14336) + (i232 * 256)) + i332))] = ((_29) > (-127) ? (_29) : (-127));
      }
    }
  }
  for (int32_t i140 = 0; i140 < 56; ++i140) {
    for (int32_t i233 = 0; i233 < 56; ++i233) {
      for (int32_t i333 = 0; i333 < 256; ++i333) {
        ((int8_t*)compute1)[((((i140 * 14336) + (i233 * 256)) + i333))] = ((int8_t)((int32_t*)out)[((((i140 * 14336) + (i233 * 256)) + i333))]);
      }
    }
  }
  for (int32_t i141 = 0; i141 < 56; ++i141) {
    for (int32_t i234 = 0; i234 < 56; ++i234) {
      for (int32_t i334 = 0; i334 < 256; ++i334) {
        ((int32_t*)pad_data)[((((i141 * 14336) + (i234 * 256)) + i334))] = ((int32_t)((int8_t*)compute1)[((((i141 * 14336) + (i234 * 256)) + i334))]);
      }
    }
  }
  for (int32_t i142 = 0; i142 < 56; ++i142) {
    for (int32_t i235 = 0; i235 < 56; ++i235) {
      for (int32_t i335 = 0; i335 < 256; ++i335) {
        ((int32_t*)out1)[((((i142 * 14336) + (i235 * 256)) + i335))] = ((int32_t)((int8_t*)compute)[((((i142 * 14336) + (i235 * 256)) + i335))]);
      }
    }
  }
  for (int32_t h84 = 0; h84 < 56; ++h84) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h84 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h84 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h84 * 57344));
  }
  for (int32_t h85 = 0; h85 < 56; ++h85) {
    for (int32_t w45 = 0; w45 < 56; ++w45) {
      for (int32_t c53 = 0; c53 < 256; ++c53) {
        ((int32_t*)pad_data)[((((h85 * 14336) + (w45 * 256)) + c53))] = 0;
      }
    }
  }
  for (int32_t h86 = 0; h86 < 56; ++h86) {
    (void)load(out, (int64_t)537264128, 7168, (h86 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h86 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h86 * 57344));
  }
  for (int32_t i143 = 0; i143 < 56; ++i143) {
    for (int32_t i236 = 0; i236 < 56; ++i236) {
      for (int32_t i336 = 0; i336 < 256; ++i336) {
        int32_t _30 = ((int32_t*)out1)[((((i143 * 14336) + (i236 * 256)) + i336))];
        int32_t _31 = (_30) < (127) ? (_30) : (127);
        ((int32_t*)out1)[((((i143 * 14336) + (i236 * 256)) + i336))] = ((_31) > (-127) ? (_31) : (-127));
      }
    }
  }
  for (int32_t i144 = 0; i144 < 56; ++i144) {
    for (int32_t i237 = 0; i237 < 56; ++i237) {
      for (int32_t i337 = 0; i337 < 256; ++i337) {
        ((int8_t*)compute)[((((i144 * 14336) + (i237 * 256)) + i337))] = ((int8_t)((int32_t*)out1)[((((i144 * 14336) + (i237 * 256)) + i337))]);
      }
    }
  }
  for (int32_t o17 = 0; o17 < 56; ++o17) {
    for (int32_t o27 = 0; o27 < 56; ++o27) {
      for (int32_t c54 = 0; c54 < 256; ++c54) {
        ((int8_t*)compute1)[((((o17 * 14336) + (o27 * 256)) + c54))] = ((int8_t*)compute)[((((o17 * 14336) + (o27 * 256)) + c54))];
      }
    }
  }
  for (int32_t ax061 = 0; ax061 < 3136; ++ax061) {
    for (int32_t ax168 = 0; ax168 < 256; ++ax168) {
      ((int8_t*)out)[(((ax061 * 256) + ax168))] = ((int8_t*)compute1)[(((ax061 * 256) + ax168))];
    }
  }
  for (int32_t i07 = 0; i07 < 3136; ++i07) {
    for (int32_t i145 = 0; i145 < 256; ++i145) {
      ((int8_t*)compute1)[(((i07 * 256) + i145))] = ((int8_t*)out)[(((i07 * 256) + i145))];
    }
  }
  for (int32_t ax062 = 0; ax062 < 392; ++ax062) {
    for (int32_t ax169 = 0; ax169 < 8; ++ax169) {
      for (int32_t ax258 = 0; ax258 < 32; ++ax258) {
        for (int32_t ax358 = 0; ax358 < 8; ++ax358) {
          ((int8_t*)pad_data)[(((((ax062 * 2048) + (ax169 * 256)) + (ax258 * 8)) + ax358))] = ((int8_t*)compute1)[(((((ax062 * 2048) + (ax169 * 256)) + (ax258 * 8)) + ax358))];
        }
      }
    }
  }
  for (int32_t ax063 = 0; ax063 < 392; ++ax063) {
    for (int32_t ax170 = 0; ax170 < 32; ++ax170) {
      for (int32_t ax259 = 0; ax259 < 8; ++ax259) {
        for (int32_t ax359 = 0; ax359 < 8; ++ax359) {
          ((int8_t*)compute1)[(((((ax063 * 2048) + (ax170 * 64)) + (ax259 * 8)) + ax359))] = ((int8_t*)pad_data)[(((((ax063 * 2048) + (ax259 * 256)) + (ax170 * 8)) + ax359))];
        }
      }
    }
  }
  for (int32_t ax064 = 0; ax064 < 392; ++ax064) {
    for (int32_t ax260 = 0; ax260 < 32; ++ax260) {
      for (int32_t ax360 = 0; ax360 < 8; ++ax360) {
        for (int32_t ax48 = 0; ax48 < 8; ++ax48) {
          ((int8_t*)out1)[(((((ax064 * 2048) + (ax260 * 64)) + (ax360 * 8)) + ax48))] = ((int8_t*)compute1)[(((((ax064 * 2048) + (ax260 * 64)) + (ax360 * 8)) + ax48))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536870912, 100352, 0);
  for (int32_t ax065 = 0; ax065 < 64; ++ax065) {
    for (int32_t ax171 = 0; ax171 < 256; ++ax171) {
      ((int8_t*)T_reshape)[(((ax065 * 256) + ax171))] = ((int8_t*)kernel_105)[(((ax065 * 256) + ax171))];
    }
  }
  for (int32_t ax066 = 0; ax066 < 8; ++ax066) {
    for (int32_t ax172 = 0; ax172 < 8; ++ax172) {
      for (int32_t ax261 = 0; ax261 < 32; ++ax261) {
        for (int32_t ax361 = 0; ax361 < 8; ++ax361) {
          ((int8_t*)T_reshape1)[(((((ax066 * 2048) + (ax172 * 256)) + (ax261 * 8)) + ax361))] = ((int8_t*)T_reshape)[(((((ax066 * 2048) + (ax172 * 256)) + (ax261 * 8)) + ax361))];
        }
      }
    }
  }
  for (int32_t ax067 = 0; ax067 < 8; ++ax067) {
    for (int32_t ax173 = 0; ax173 < 32; ++ax173) {
      for (int32_t ax262 = 0; ax262 < 8; ++ax262) {
        for (int32_t ax362 = 0; ax362 < 8; ++ax362) {
          ((int8_t*)T_reshape)[(((((ax067 * 2048) + (ax173 * 64)) + (ax262 * 8)) + ax362))] = ((int8_t*)T_reshape1)[(((((ax067 * 2048) + (ax262 * 256)) + (ax173 * 8)) + ax362))];
        }
      }
    }
  }
  for (int32_t ax068 = 0; ax068 < 8; ++ax068) {
    for (int32_t ax263 = 0; ax263 < 32; ++ax263) {
      for (int32_t ax363 = 0; ax363 < 8; ++ax363) {
        for (int32_t ax49 = 0; ax49 < 8; ++ax49) {
          ((int8_t*)T_reshape1)[(((((ax068 * 2048) + (ax263 * 64)) + (ax363 * 8)) + ax49))] = ((int8_t*)T_reshape)[(((((ax068 * 2048) + (ax263 * 64)) + (ax363 * 8)) + ax49))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536936448, 2048, 0);
  for (int32_t i20 = 0; i20 < 392; ++i20) {
    for (int32_t x7 = 0; x7 < 8; ++x7) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i20 * 128)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x7 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i20 * 2048) + (x7 * 256)));
    }
  }
  for (int32_t ax069 = 0; ax069 < 392; ++ax069) {
    for (int32_t ax174 = 0; ax174 < 8; ++ax174) {
      for (int32_t ax264 = 0; ax264 < 8; ++ax264) {
        for (int32_t ax364 = 0; ax364 < 8; ++ax364) {
          ((int32_t*)out)[(((((ax069 * 512) + (ax174 * 64)) + (ax264 * 8)) + ax364))] = ((int32_t*)compute1)[(((((ax069 * 512) + (ax264 * 64)) + (ax174 * 8)) + ax364))];
        }
      }
    }
  }
  for (int32_t ax070 = 0; ax070 < 3136; ++ax070) {
    for (int32_t ax175 = 0; ax175 < 64; ++ax175) {
      ((int32_t*)compute1)[(((ax070 * 64) + ax175))] = ((int32_t*)out)[(((ax070 * 64) + ax175))];
    }
  }
  for (int32_t i08 = 0; i08 < 3136; ++i08) {
    for (int32_t i146 = 0; i146 < 64; ++i146) {
      ((int32_t*)pad_data)[(((i08 * 64) + i146))] = ((int32_t*)compute1)[(((i08 * 64) + i146))];
    }
  }
  for (int32_t ax176 = 0; ax176 < 56; ++ax176) {
    for (int32_t ax265 = 0; ax265 < 56; ++ax265) {
      for (int32_t ax365 = 0; ax365 < 64; ++ax365) {
        ((int32_t*)compute1)[((((ax176 * 3584) + (ax265 * 64)) + ax365))] = ((int32_t*)pad_data)[((((ax176 * 3584) + (ax265 * 64)) + ax365))];
      }
    }
  }
  for (int32_t h87 = 0; h87 < 56; ++h87) {
    for (int32_t w46 = 0; w46 < 56; ++w46) {
      for (int32_t c55 = 0; c55 < 64; ++c55) {
        ((int32_t*)out1)[((((h87 * 3584) + (w46 * 64)) + c55))] = 8;
      }
    }
  }
  for (int32_t h88 = 0; h88 < 56; ++h88) {
    (void)load(compute1, (int64_t)537264128, 1792, (h88 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h88 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h88 * 14336));
  }
  for (int32_t h89 = 0; h89 < 56; ++h89) {
    for (int32_t w47 = 0; w47 < 56; ++w47) {
      for (int32_t c56 = 0; c56 < 64; ++c56) {
        ((int32_t*)compute1)[((((h89 * 3584) + (w47 * 64)) + c56))] = ((int32_t*)tensor_107)[(c56)];
      }
    }
  }
  for (int32_t h90 = 0; h90 < 56; ++h90) {
    (void)load(out, (int64_t)537264128, 1792, (h90 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h90 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h90 * 14336));
  }
  for (int32_t h91 = 0; h91 < 56; ++h91) {
    for (int32_t w48 = 0; w48 < 56; ++w48) {
      for (int32_t c57 = 0; c57 < 64; ++c57) {
        ((int32_t*)compute1)[((((h91 * 3584) + (w48 * 64)) + c57))] = ((int32_t*)tensor_108)[(c57)];
      }
    }
  }
  for (int32_t h92 = 0; h92 < 56; ++h92) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h92 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h92 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h92 * 14336));
  }
  for (int32_t h93 = 0; h93 < 56; ++h93) {
    for (int32_t w49 = 0; w49 < 56; ++w49) {
      for (int32_t c58 = 0; c58 < 64; ++c58) {
        ((int32_t*)compute1)[((((h93 * 3584) + (w49 * 64)) + c58))] = 0;
      }
    }
  }
  for (int32_t h94 = 0; h94 < 56; ++h94) {
    (void)load(out1, (int64_t)537264128, 1792, (h94 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h94 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h94 * 14336));
  }
  for (int32_t h95 = 0; h95 < 56; ++h95) {
    for (int32_t w50 = 0; w50 < 56; ++w50) {
      for (int32_t c59 = 0; c59 < 64; ++c59) {
        ((int32_t*)compute1)[((((h95 * 3584) + (w50 * 64)) + c59))] = 65536;
      }
    }
  }
  for (int32_t h96 = 0; h96 < 56; ++h96) {
    (void)load(out, (int64_t)537264128, 1792, (h96 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h96 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h96 * 14336));
  }
  for (int32_t h97 = 0; h97 < 56; ++h97) {
    for (int32_t w51 = 0; w51 < 56; ++w51) {
      for (int32_t c60 = 0; c60 < 64; ++c60) {
        ((int32_t*)compute1)[((((h97 * 3584) + (w51 * 64)) + c60))] = 17;
      }
    }
  }
  for (int32_t h98 = 0; h98 < 56; ++h98) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h98 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h98 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h98 * 14336));
  }
  for (int32_t i147 = 0; i147 < 56; ++i147) {
    for (int32_t i238 = 0; i238 < 56; ++i238) {
      for (int32_t i338 = 0; i338 < 64; ++i338) {
        int32_t _32 = ((int32_t*)out1)[((((i147 * 3584) + (i238 * 64)) + i338))];
        int32_t _33 = (_32) < (127) ? (_32) : (127);
        ((int32_t*)compute1)[((((i147 * 3584) + (i238 * 64)) + i338))] = ((_33) > (-127) ? (_33) : (-127));
      }
    }
  }
  for (int32_t i148 = 0; i148 < 56; ++i148) {
    for (int32_t i239 = 0; i239 < 56; ++i239) {
      for (int32_t i339 = 0; i339 < 64; ++i339) {
        ((int8_t*)out)[((((i148 * 3584) + (i239 * 64)) + i339))] = ((int8_t)((int32_t*)compute1)[((((i148 * 3584) + (i239 * 64)) + i339))]);
      }
    }
  }
  for (int32_t i149 = 0; i149 < 57; ++i149) {
    for (int32_t i240 = 0; i240 < 58; ++i240) {
      for (int32_t i340 = 0; i340 < 64; ++i340) {
        ((int8_t*)compute1)[((((i149 * 3712) + (i240 * 64)) + i340))] = ((((1 <= i149) && (1 <= i240)) && (i240 < 57)) ? ((int8_t*)out)[(((((i149 * 3584) + (i240 * 64)) + i340) - 3648))] : (int8_t)0);
      }
    }
  }
  for (int32_t o18 = 0; o18 < 55; ++o18) {
    for (int32_t o28 = 0; o28 < 56; ++o28) {
      for (int32_t k12 = 0; k12 < 3; ++k12) {
        for (int32_t k22 = 0; k22 < 3; ++k22) {
          for (int32_t c61 = 0; c61 < 64; ++c61) {
            ((int8_t*)pad_data)[((((((o18 * 32256) + (o28 * 576)) + (k12 * 192)) + (k22 * 64)) + c61))] = ((int8_t*)compute1)[((((((k12 * 3712) + (o18 * 3712)) + (k22 * 64)) + (o28 * 64)) + c61))];
          }
        }
      }
    }
  }
  for (int32_t ax071 = 0; ax071 < 3080; ++ax071) {
    for (int32_t ax177 = 0; ax177 < 576; ++ax177) {
      ((int8_t*)compute1)[(((ax071 * 576) + ax177))] = ((int8_t*)pad_data)[(((ax071 * 576) + ax177))];
    }
  }
  for (int32_t i09 = 0; i09 < 3080; ++i09) {
    for (int32_t i150 = 0; i150 < 576; ++i150) {
      ((int8_t*)out1)[(((i09 * 576) + i150))] = ((int8_t*)compute1)[(((i09 * 576) + i150))];
    }
  }
  for (int32_t ax072 = 0; ax072 < 385; ++ax072) {
    for (int32_t ax178 = 0; ax178 < 8; ++ax178) {
      for (int32_t ax266 = 0; ax266 < 72; ++ax266) {
        for (int32_t ax366 = 0; ax366 < 8; ++ax366) {
          ((int8_t*)compute1)[(((((ax072 * 4608) + (ax178 * 576)) + (ax266 * 8)) + ax366))] = ((int8_t*)out1)[(((((ax072 * 4608) + (ax178 * 576)) + (ax266 * 8)) + ax366))];
        }
      }
    }
  }
  for (int32_t ax073 = 0; ax073 < 385; ++ax073) {
    for (int32_t ax179 = 0; ax179 < 72; ++ax179) {
      for (int32_t ax267 = 0; ax267 < 8; ++ax267) {
        for (int32_t ax367 = 0; ax367 < 8; ++ax367) {
          ((int8_t*)out)[(((((ax073 * 4608) + (ax179 * 64)) + (ax267 * 8)) + ax367))] = ((int8_t*)compute1)[(((((ax073 * 4608) + (ax267 * 576)) + (ax179 * 8)) + ax367))];
        }
      }
    }
  }
  for (int32_t ax074 = 0; ax074 < 385; ++ax074) {
    for (int32_t ax268 = 0; ax268 < 72; ++ax268) {
      for (int32_t ax368 = 0; ax368 < 8; ++ax368) {
        for (int32_t ax410 = 0; ax410 < 8; ++ax410) {
          ((int8_t*)compute1)[(((((ax074 * 4608) + (ax268 * 64)) + (ax368 * 8)) + ax410))] = ((int8_t*)out)[(((((ax074 * 4608) + (ax268 * 64)) + (ax368 * 8)) + ax410))];
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 221760, 0);
  for (int32_t ax075 = 0; ax075 < 64; ++ax075) {
    for (int32_t ax180 = 0; ax180 < 576; ++ax180) {
      ((int8_t*)T_reshape)[(((ax075 * 576) + ax180))] = ((int8_t*)kernel_115)[(((ax075 * 576) + ax180))];
    }
  }
  for (int32_t ax076 = 0; ax076 < 8; ++ax076) {
    for (int32_t ax181 = 0; ax181 < 8; ++ax181) {
      for (int32_t ax269 = 0; ax269 < 72; ++ax269) {
        for (int32_t ax369 = 0; ax369 < 8; ++ax369) {
          ((int8_t*)T_reshape1)[(((((ax076 * 4608) + (ax181 * 576)) + (ax269 * 8)) + ax369))] = ((int8_t*)T_reshape)[(((((ax076 * 4608) + (ax181 * 576)) + (ax269 * 8)) + ax369))];
        }
      }
    }
  }
  for (int32_t ax077 = 0; ax077 < 8; ++ax077) {
    for (int32_t ax182 = 0; ax182 < 72; ++ax182) {
      for (int32_t ax270 = 0; ax270 < 8; ++ax270) {
        for (int32_t ax370 = 0; ax370 < 8; ++ax370) {
          ((int8_t*)T_reshape)[(((((ax077 * 4608) + (ax182 * 64)) + (ax270 * 8)) + ax370))] = ((int8_t*)T_reshape1)[(((((ax077 * 4608) + (ax270 * 576)) + (ax182 * 8)) + ax370))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 4608, 0);
  for (int32_t i30 = 0; i30 < 385; ++i30) {
    for (int32_t x8 = 0; x8 < 8; ++x8) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i30 * 288)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
      (void)move(((((int64_t)(x8 * 288)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i30 * 2048) + (x8 * 256)));
    }
  }
  for (int32_t ax078 = 0; ax078 < 385; ++ax078) {
    for (int32_t ax183 = 0; ax183 < 8; ++ax183) {
      for (int32_t ax271 = 0; ax271 < 8; ++ax271) {
        for (int32_t ax371 = 0; ax371 < 8; ++ax371) {
          ((int32_t*)pad_data)[(((((ax078 * 512) + (ax183 * 64)) + (ax271 * 8)) + ax371))] = ((int32_t*)compute1)[(((((ax078 * 512) + (ax271 * 64)) + (ax183 * 8)) + ax371))];
        }
      }
    }
  }
  for (int32_t ax079 = 0; ax079 < 3080; ++ax079) {
    for (int32_t ax184 = 0; ax184 < 64; ++ax184) {
      ((int32_t*)compute1)[(((ax079 * 64) + ax184))] = ((int32_t*)pad_data)[(((ax079 * 64) + ax184))];
    }
  }
  for (int32_t i010 = 0; i010 < 3080; ++i010) {
    for (int32_t i151 = 0; i151 < 64; ++i151) {
      ((int32_t*)out1)[(((i010 * 64) + i151))] = ((int32_t*)compute1)[(((i010 * 64) + i151))];
    }
  }
  for (int32_t ax185 = 0; ax185 < 55; ++ax185) {
    for (int32_t ax272 = 0; ax272 < 56; ++ax272) {
      for (int32_t ax372 = 0; ax372 < 64; ++ax372) {
        ((int32_t*)compute1)[((((ax185 * 3584) + (ax272 * 64)) + ax372))] = ((int32_t*)out1)[((((ax185 * 3584) + (ax272 * 64)) + ax372))];
      }
    }
  }
  for (int32_t h99 = 0; h99 < 55; ++h99) {
    for (int32_t w52 = 0; w52 < 56; ++w52) {
      for (int32_t c62 = 0; c62 < 64; ++c62) {
        ((int32_t*)out)[((((h99 * 3584) + (w52 * 64)) + c62))] = ((int32_t*)tensor_116)[(c62)];
      }
    }
  }
  for (int32_t h100 = 0; h100 < 55; ++h100) {
    (void)load(compute1, (int64_t)537264128, 1792, (h100 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h100 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h100 * 14336));
  }
  for (int32_t h101 = 0; h101 < 55; ++h101) {
    for (int32_t w53 = 0; w53 < 56; ++w53) {
      for (int32_t c63 = 0; c63 < 64; ++c63) {
        ((int32_t*)compute1)[((((h101 * 3584) + (w53 * 64)) + c63))] = 0;
      }
    }
  }
  for (int32_t h102 = 0; h102 < 55; ++h102) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h102 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h102 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h102 * 14336));
  }
  for (int32_t h103 = 0; h103 < 55; ++h103) {
    for (int32_t w54 = 0; w54 < 56; ++w54) {
      for (int32_t c64 = 0; c64 < 64; ++c64) {
        ((int32_t*)compute1)[((((h103 * 3584) + (w54 * 64)) + c64))] = 64;
      }
    }
  }
  for (int32_t h104 = 0; h104 < 55; ++h104) {
    (void)load(out1, (int64_t)537264128, 1792, (h104 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h104 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h104 * 14336));
  }
  for (int32_t h105 = 0; h105 < 55; ++h105) {
    for (int32_t w55 = 0; w55 < 56; ++w55) {
      for (int32_t c65 = 0; c65 < 64; ++c65) {
        ((int32_t*)compute1)[((((h105 * 3584) + (w55 * 64)) + c65))] = 7;
      }
    }
  }
  for (int32_t h106 = 0; h106 < 55; ++h106) {
    (void)load(out, (int64_t)537264128, 1792, (h106 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h106 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h106 * 14336));
  }
  for (int32_t i152 = 0; i152 < 55; ++i152) {
    for (int32_t i241 = 0; i241 < 56; ++i241) {
      for (int32_t i341 = 0; i341 < 64; ++i341) {
        int32_t _34 = ((int32_t*)pad_data)[((((i152 * 3584) + (i241 * 64)) + i341))];
        int32_t _35 = (_34) < (127) ? (_34) : (127);
        ((int32_t*)compute1)[((((i152 * 3584) + (i241 * 64)) + i341))] = ((_35) > (-127) ? (_35) : (-127));
      }
    }
  }
  for (int32_t i153 = 0; i153 < 55; ++i153) {
    for (int32_t i242 = 0; i242 < 56; ++i242) {
      for (int32_t i342 = 0; i342 < 64; ++i342) {
        ((int8_t*)T_reshape)[((((i153 * 3584) + (i242 * 64)) + i342))] = ((int8_t)((int32_t*)compute1)[((((i153 * 3584) + (i242 * 64)) + i342))]);
      }
    }
  }
  for (int32_t ax080 = 0; ax080 < 385; ++ax080) {
    for (int32_t ax186 = 0; ax186 < 8; ++ax186) {
      for (int32_t ax273 = 0; ax273 < 8; ++ax273) {
        for (int32_t ax373 = 0; ax373 < 8; ++ax373) {
          ((int8_t*)compute1)[(((((ax080 * 512) + (ax186 * 64)) + (ax273 * 8)) + ax373))] = ((int8_t*)T_reshape)[(((((ax080 * 512) + (ax186 * 64)) + (ax273 * 8)) + ax373))];
        }
      }
    }
  }
  for (int32_t ax081 = 0; ax081 < 385; ++ax081) {
    for (int32_t ax187 = 0; ax187 < 8; ++ax187) {
      for (int32_t ax274 = 0; ax274 < 8; ++ax274) {
        for (int32_t ax374 = 0; ax374 < 8; ++ax374) {
          ((int8_t*)T_reshape)[(((((ax081 * 512) + (ax187 * 64)) + (ax274 * 8)) + ax374))] = ((int8_t*)compute1)[(((((ax081 * 512) + (ax274 * 64)) + (ax187 * 8)) + ax374))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536870912, 24640, 0);
  for (int32_t ax082 = 0; ax082 < 256; ++ax082) {
    for (int32_t ax188 = 0; ax188 < 64; ++ax188) {
      ((int8_t*)T_reshape1)[(((ax082 * 64) + ax188))] = ((int8_t*)kernel_123)[(((ax082 * 64) + ax188))];
    }
  }
  for (int32_t ax083 = 0; ax083 < 32; ++ax083) {
    for (int32_t ax189 = 0; ax189 < 8; ++ax189) {
      for (int32_t ax275 = 0; ax275 < 8; ++ax275) {
        for (int32_t ax375 = 0; ax375 < 8; ++ax375) {
          ((int8_t*)T_reshape)[(((((ax083 * 512) + (ax189 * 64)) + (ax275 * 8)) + ax375))] = ((int8_t*)T_reshape1)[(((((ax083 * 512) + (ax189 * 64)) + (ax275 * 8)) + ax375))];
        }
      }
    }
  }
  for (int32_t ax084 = 0; ax084 < 32; ++ax084) {
    for (int32_t ax190 = 0; ax190 < 8; ++ax190) {
      for (int32_t ax276 = 0; ax276 < 8; ++ax276) {
        for (int32_t ax376 = 0; ax376 < 8; ++ax376) {
          ((int8_t*)T_reshape1)[(((((ax084 * 512) + (ax190 * 64)) + (ax276 * 8)) + ax376))] = ((int8_t*)T_reshape)[(((((ax084 * 512) + (ax276 * 64)) + (ax190 * 8)) + ax376))];
        }
      }
    }
  }
  for (int32_t ax085 = 0; ax085 < 32; ++ax085) {
    for (int32_t ax277 = 0; ax277 < 8; ++ax277) {
      for (int32_t ax377 = 0; ax377 < 8; ++ax377) {
        for (int32_t ax411 = 0; ax411 < 8; ++ax411) {
          ((int8_t*)T_reshape)[(((((ax085 * 512) + (ax277 * 64)) + (ax377 * 8)) + ax411))] = ((int8_t*)T_reshape1)[(((((ax085 * 512) + (ax277 * 64)) + (ax377 * 8)) + ax411))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 2048, 0);
  for (int32_t i40 = 0; i40 < 385; ++i40) {
    for (int32_t x9 = 0; x9 < 32; ++x9) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i40 * 32)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 64, 0);
      (void)move(((((int64_t)(x9 * 32)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 64, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 8, (int64_t)1, (int64_t)0);
      (void)store(out1, (int64_t)537264128, 32, ((i40 * 8192) + (x9 * 256)));
    }
  }
  for (int32_t ax086 = 0; ax086 < 385; ++ax086) {
    for (int32_t ax191 = 0; ax191 < 8; ++ax191) {
      for (int32_t ax278 = 0; ax278 < 32; ++ax278) {
        for (int32_t ax378 = 0; ax378 < 8; ++ax378) {
          ((int32_t*)out)[(((((ax086 * 2048) + (ax191 * 256)) + (ax278 * 8)) + ax378))] = ((int32_t*)out1)[(((((ax086 * 2048) + (ax278 * 64)) + (ax191 * 8)) + ax378))];
        }
      }
    }
  }
  for (int32_t ax087 = 0; ax087 < 3079; ++ax087) {
    for (int32_t ax192 = 0; ax192 < 256; ++ax192) {
      ((int32_t*)pad_data)[(((ax087 * 256) + ax192))] = ((int32_t*)out)[(((ax087 * 256) + ax192))];
    }
  }
  for (int32_t i011 = 0; i011 < 3079; ++i011) {
    for (int32_t i154 = 0; i154 < 256; ++i154) {
      ((int32_t*)out1)[(((i011 * 256) + i154))] = ((int32_t*)pad_data)[(((i011 * 256) + i154))];
    }
  }
  for (int32_t ax193 = 0; ax193 < 55; ++ax193) {
    for (int32_t ax279 = 0; ax279 < 55; ++ax279) {
      for (int32_t ax379 = 0; ax379 < 256; ++ax379) {
        ((int32_t*)out)[((((ax193 * 14080) + (ax279 * 256)) + ax379))] = ((int32_t*)out1)[((((ax193 * 14336) + (ax279 * 256)) + ax379))];
      }
    }
  }
  for (int32_t h107 = 0; h107 < 55; ++h107) {
    for (int32_t w56 = 0; w56 < 55; ++w56) {
      for (int32_t c66 = 0; c66 < 256; ++c66) {
        ((int32_t*)pad_data)[((((h107 * 14080) + (w56 * 256)) + c66))] = 8;
      }
    }
  }
  for (int32_t h108 = 0; h108 < 55; ++h108) {
    (void)load(out, (int64_t)537264128, 7040, (h108 * 14080));
    (void)load(pad_data, (int64_t)537329664, 7040, (h108 * 14080));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7040, (h108 * 56320));
  }
  for (int32_t h109 = 0; h109 < 55; ++h109) {
    for (int32_t w57 = 0; w57 < 55; ++w57) {
      for (int32_t c67 = 0; c67 < 256; ++c67) {
        ((int32_t*)out)[((((h109 * 14080) + (w57 * 256)) + c67))] = ((int32_t*)tensor_125)[(c67)];
      }
    }
  }
  for (int32_t h110 = 0; h110 < 55; ++h110) {
    (void)load(out1, (int64_t)537264128, 7040, (h110 * 14080));
    (void)load(out, (int64_t)537329664, 7040, (h110 * 14080));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7040, (h110 * 56320));
  }
  for (int32_t h111 = 0; h111 < 55; ++h111) {
    for (int32_t w58 = 0; w58 < 55; ++w58) {
      for (int32_t c68 = 0; c68 < 256; ++c68) {
        ((int32_t*)out1)[((((h111 * 14080) + (w58 * 256)) + c68))] = 32768;
      }
    }
  }
  for (int32_t h112 = 0; h112 < 55; ++h112) {
    (void)load(pad_data, (int64_t)537264128, 7040, (h112 * 14080));
    (void)load(out1, (int64_t)537329664, 7040, (h112 * 14080));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7040, (h112 * 56320));
  }
  for (int32_t h113 = 0; h113 < 55; ++h113) {
    for (int32_t w59 = 0; w59 < 55; ++w59) {
      for (int32_t c69 = 0; c69 < 256; ++c69) {
        ((int32_t*)pad_data)[((((h113 * 14080) + (w59 * 256)) + c69))] = 16;
      }
    }
  }
  for (int32_t h114 = 0; h114 < 55; ++h114) {
    (void)load(out, (int64_t)537264128, 7040, (h114 * 14080));
    (void)load(pad_data, (int64_t)537329664, 7040, (h114 * 14080));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7040, (h114 * 56320));
  }
  for (int32_t i155 = 0; i155 < 55; ++i155) {
    for (int32_t i243 = 0; i243 < 55; ++i243) {
      for (int32_t i343 = 0; i343 < 256; ++i343) {
        int32_t _36 = ((int32_t*)out1)[((((i155 * 14080) + (i243 * 256)) + i343))];
        int32_t _37 = (_36) < (127) ? (_36) : (127);
        ((int32_t*)out)[((((i155 * 14080) + (i243 * 256)) + i343))] = ((_37) > (-127) ? (_37) : (-127));
      }
    }
  }
  for (int32_t i156 = 0; i156 < 55; ++i156) {
    for (int32_t i244 = 0; i244 < 55; ++i244) {
      for (int32_t i344 = 0; i344 < 256; ++i344) {
        ((int8_t*)compute1)[((((i156 * 14080) + (i244 * 256)) + i344))] = ((int8_t)((int32_t*)out)[((((i156 * 14080) + (i244 * 256)) + i344))]);
      }
    }
  }
  for (int32_t i157 = 0; i157 < 55; ++i157) {
    for (int32_t i245 = 0; i245 < 55; ++i245) {
      for (int32_t i345 = 0; i345 < 256; ++i345) {
        ((int32_t*)pad_data)[((((i157 * 14080) + (i245 * 256)) + i345))] = ((int32_t)((int8_t*)compute1)[((((i157 * 14080) + (i245 * 256)) + i345))]);
      }
    }
  }
  for (int32_t h115 = 0; h115 < 55; ++h115) {
    for (int32_t w60 = 0; w60 < 55; ++w60) {
      for (int32_t c70 = 0; c70 < 256; ++c70) {
        ((int32_t*)out1)[((((h115 * 14080) + (w60 * 256)) + c70))] = ((int32_t*)tensor_132)[(c70)];
      }
    }
  }
  for (int32_t h116 = 0; h116 < 55; ++h116) {
    (void)load(pad_data, (int64_t)537264128, 7040, (h116 * 14080));
    (void)load(out1, (int64_t)537329664, 7040, (h116 * 14080));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7040, (h116 * 56320));
  }
  for (int32_t h117 = 0; h117 < 55; ++h117) {
    for (int32_t w61 = 0; w61 < 55; ++w61) {
      for (int32_t c71 = 0; c71 < 256; ++c71) {
        ((int32_t*)pad_data)[((((h117 * 14080) + (w61 * 256)) + c71))] = ((int32_t*)tensor_133)[(c71)];
      }
    }
  }
  for (int32_t h118 = 0; h118 < 55; ++h118) {
    (void)load(out, (int64_t)537264128, 7040, (h118 * 14080));
    (void)load(pad_data, (int64_t)537329664, 7040, (h118 * 14080));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7040, (h118 * 56320));
  }
  for (int32_t h119 = 0; h119 < 55; ++h119) {
    for (int32_t w62 = 0; w62 < 55; ++w62) {
      for (int32_t c72 = 0; c72 < 256; ++c72) {
        ((int32_t*)out)[((((h119 * 14080) + (w62 * 256)) + c72))] = 8;
      }
    }
  }
  for (int32_t h120 = 0; h120 < 55; ++h120) {
    (void)load(out1, (int64_t)537264128, 7040, (h120 * 14080));
    (void)load(out, (int64_t)537329664, 7040, (h120 * 14080));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7040, (h120 * 56320));
  }
  for (int32_t h121 = 0; h121 < 55; ++h121) {
    for (int32_t w63 = 0; w63 < 55; ++w63) {
      for (int32_t c73 = 0; c73 < 256; ++c73) {
        ((int32_t*)out1)[((((h121 * 14080) + (w63 * 256)) + c73))] = 4;
      }
    }
  }
  for (int32_t h122 = 0; h122 < 55; ++h122) {
    (void)load(pad_data, (int64_t)537264128, 7040, (h122 * 14080));
    (void)load(out1, (int64_t)537329664, 7040, (h122 * 14080));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7040, (h122 * 56320));
  }
  for (int32_t i158 = 0; i158 < 55; ++i158) {
    for (int32_t i246 = 0; i246 < 55; ++i246) {
      for (int32_t i346 = 0; i346 < 256; ++i346) {
        int32_t _38 = ((int32_t*)out)[((((i158 * 14080) + (i246 * 256)) + i346))];
        int32_t _39 = (_38) < (127) ? (_38) : (127);
        ((int32_t*)pad_data)[((((i158 * 14080) + (i246 * 256)) + i346))] = ((_39) > (-127) ? (_39) : (-127));
      }
    }
  }
  for (int32_t i159 = 0; i159 < 55; ++i159) {
    for (int32_t i247 = 0; i247 < 55; ++i247) {
      for (int32_t i347 = 0; i347 < 256; ++i347) {
        ((int8_t*)compute1)[((((i159 * 14080) + (i247 * 256)) + i347))] = ((int8_t)((int32_t*)pad_data)[((((i159 * 14080) + (i247 * 256)) + i347))]);
      }
    }
  }
  for (int32_t i160 = 0; i160 < 55; ++i160) {
    for (int32_t i248 = 0; i248 < 55; ++i248) {
      for (int32_t i348 = 0; i348 < 256; ++i348) {
        ((int32_t*)out1)[((((i160 * 14080) + (i248 * 256)) + i348))] = ((int32_t)((int8_t*)compute1)[((((i160 * 14080) + (i248 * 256)) + i348))]);
      }
    }
  }
  for (int32_t i161 = 0; i161 < 55; ++i161) {
    for (int32_t i249 = 0; i249 < 55; ++i249) {
      for (int32_t i349 = 0; i349 < 256; ++i349) {
        ((int32_t*)out)[((((i161 * 14080) + (i249 * 256)) + i349))] = ((int32_t)((int8_t*)compute)[((((i161 * 14336) + (i249 * 256)) + i349))]);
      }
    }
  }
  for (int32_t h123 = 0; h123 < 55; ++h123) {
    (void)load(out1, (int64_t)537264128, 7040, (h123 * 14080));
    (void)load(out, (int64_t)537329664, 7040, (h123 * 14080));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7040, (h123 * 56320));
  }
  for (int32_t h124 = 0; h124 < 55; ++h124) {
    for (int32_t w64 = 0; w64 < 55; ++w64) {
      for (int32_t c74 = 0; c74 < 256; ++c74) {
        ((int32_t*)out1)[((((h124 * 14080) + (w64 * 256)) + c74))] = 0;
      }
    }
  }
  for (int32_t h125 = 0; h125 < 55; ++h125) {
    (void)load(pad_data, (int64_t)537264128, 7040, (h125 * 14080));
    (void)load(out1, (int64_t)537329664, 7040, (h125 * 14080));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 440, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7040, (h125 * 56320));
  }
  for (int32_t i162 = 0; i162 < 55; ++i162) {
    for (int32_t i250 = 0; i250 < 55; ++i250) {
      for (int32_t i350 = 0; i350 < 256; ++i350) {
        int32_t _40 = ((int32_t*)out)[((((i162 * 14080) + (i250 * 256)) + i350))];
        int32_t _41 = (_40) < (127) ? (_40) : (127);
        ((int32_t*)pad_data)[((((i162 * 14080) + (i250 * 256)) + i350))] = ((_41) > (-127) ? (_41) : (-127));
      }
    }
  }
  for (int32_t i163 = 0; i163 < 55; ++i163) {
    for (int32_t i251 = 0; i251 < 55; ++i251) {
      for (int32_t i351 = 0; i351 < 256; ++i351) {
        ((int8_t*)compute)[((((i163 * 14080) + (i251 * 256)) + i351))] = ((int8_t)((int32_t*)pad_data)[((((i163 * 14080) + (i251 * 256)) + i351))]);
      }
    }
  }
  for (int32_t o19 = 0; o19 < 28; ++o19) {
    for (int32_t o29 = 0; o29 < 28; ++o29) {
      for (int32_t c75 = 0; c75 < 256; ++c75) {
        ((int8_t*)compute1)[((((o19 * 7168) + (o29 * 256)) + c75))] = ((int8_t*)compute)[((((o19 * 28160) + (o29 * 512)) + c75))];
      }
    }
  }
  for (int32_t ax088 = 0; ax088 < 784; ++ax088) {
    for (int32_t ax194 = 0; ax194 < 256; ++ax194) {
      ((int8_t*)out1)[(((ax088 * 256) + ax194))] = ((int8_t*)compute1)[(((ax088 * 256) + ax194))];
    }
  }
  for (int32_t i012 = 0; i012 < 784; ++i012) {
    for (int32_t i164 = 0; i164 < 256; ++i164) {
      ((int8_t*)compute1)[(((i012 * 256) + i164))] = ((int8_t*)out1)[(((i012 * 256) + i164))];
    }
  }
  for (int32_t ax089 = 0; ax089 < 98; ++ax089) {
    for (int32_t ax195 = 0; ax195 < 8; ++ax195) {
      for (int32_t ax280 = 0; ax280 < 32; ++ax280) {
        for (int32_t ax380 = 0; ax380 < 8; ++ax380) {
          ((int8_t*)out)[(((((ax089 * 2048) + (ax195 * 256)) + (ax280 * 8)) + ax380))] = ((int8_t*)compute1)[(((((ax089 * 2048) + (ax195 * 256)) + (ax280 * 8)) + ax380))];
        }
      }
    }
  }
  for (int32_t ax090 = 0; ax090 < 98; ++ax090) {
    for (int32_t ax196 = 0; ax196 < 32; ++ax196) {
      for (int32_t ax281 = 0; ax281 < 8; ++ax281) {
        for (int32_t ax381 = 0; ax381 < 8; ++ax381) {
          ((int8_t*)compute1)[(((((ax090 * 2048) + (ax196 * 64)) + (ax281 * 8)) + ax381))] = ((int8_t*)out)[(((((ax090 * 2048) + (ax281 * 256)) + (ax196 * 8)) + ax381))];
        }
      }
    }
  }
  for (int32_t ax091 = 0; ax091 < 98; ++ax091) {
    for (int32_t ax282 = 0; ax282 < 32; ++ax282) {
      for (int32_t ax382 = 0; ax382 < 8; ++ax382) {
        for (int32_t ax412 = 0; ax412 < 8; ++ax412) {
          ((int8_t*)pad_data)[(((((ax091 * 2048) + (ax282 * 64)) + (ax382 * 8)) + ax412))] = ((int8_t*)compute1)[(((((ax091 * 2048) + (ax282 * 64)) + (ax382 * 8)) + ax412))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25088, 0);
  for (int32_t ax092 = 0; ax092 < 128; ++ax092) {
    for (int32_t ax197 = 0; ax197 < 256; ++ax197) {
      ((int8_t*)T_reshape1)[(((ax092 * 256) + ax197))] = ((int8_t*)kernel_148)[(((ax092 * 256) + ax197))];
    }
  }
  for (int32_t ax093 = 0; ax093 < 16; ++ax093) {
    for (int32_t ax198 = 0; ax198 < 8; ++ax198) {
      for (int32_t ax283 = 0; ax283 < 32; ++ax283) {
        for (int32_t ax383 = 0; ax383 < 8; ++ax383) {
          ((int8_t*)T_reshape)[(((((ax093 * 2048) + (ax198 * 256)) + (ax283 * 8)) + ax383))] = ((int8_t*)T_reshape1)[(((((ax093 * 2048) + (ax198 * 256)) + (ax283 * 8)) + ax383))];
        }
      }
    }
  }
  for (int32_t ax094 = 0; ax094 < 16; ++ax094) {
    for (int32_t ax199 = 0; ax199 < 32; ++ax199) {
      for (int32_t ax284 = 0; ax284 < 8; ++ax284) {
        for (int32_t ax384 = 0; ax384 < 8; ++ax384) {
          ((int8_t*)T_reshape1)[(((((ax094 * 2048) + (ax199 * 64)) + (ax284 * 8)) + ax384))] = ((int8_t*)T_reshape)[(((((ax094 * 2048) + (ax284 * 256)) + (ax199 * 8)) + ax384))];
        }
      }
    }
  }
  for (int32_t ax095 = 0; ax095 < 16; ++ax095) {
    for (int32_t ax285 = 0; ax285 < 32; ++ax285) {
      for (int32_t ax385 = 0; ax385 < 8; ++ax385) {
        for (int32_t ax413 = 0; ax413 < 8; ++ax413) {
          ((int8_t*)T_reshape)[(((((ax095 * 2048) + (ax285 * 64)) + (ax385 * 8)) + ax413))] = ((int8_t*)T_reshape1)[(((((ax095 * 2048) + (ax285 * 64)) + (ax385 * 8)) + ax413))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 4096, 0);
  for (int32_t i41 = 0; i41 < 98; ++i41) {
    for (int32_t x10 = 0; x10 < 16; ++x10) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i41 * 128)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x10 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i41 * 4096) + (x10 * 256)));
    }
  }
  for (int32_t ax096 = 0; ax096 < 98; ++ax096) {
    for (int32_t ax1100 = 0; ax1100 < 8; ++ax1100) {
      for (int32_t ax286 = 0; ax286 < 16; ++ax286) {
        for (int32_t ax386 = 0; ax386 < 8; ++ax386) {
          ((int32_t*)out1)[(((((ax096 * 1024) + (ax1100 * 128)) + (ax286 * 8)) + ax386))] = ((int32_t*)compute1)[(((((ax096 * 1024) + (ax286 * 64)) + (ax1100 * 8)) + ax386))];
        }
      }
    }
  }
  for (int32_t ax097 = 0; ax097 < 784; ++ax097) {
    for (int32_t ax1101 = 0; ax1101 < 128; ++ax1101) {
      ((int32_t*)compute1)[(((ax097 * 128) + ax1101))] = ((int32_t*)out1)[(((ax097 * 128) + ax1101))];
    }
  }
  for (int32_t i013 = 0; i013 < 784; ++i013) {
    for (int32_t i165 = 0; i165 < 128; ++i165) {
      ((int32_t*)out)[(((i013 * 128) + i165))] = ((int32_t*)compute1)[(((i013 * 128) + i165))];
    }
  }
  for (int32_t ax1102 = 0; ax1102 < 28; ++ax1102) {
    for (int32_t ax287 = 0; ax287 < 28; ++ax287) {
      for (int32_t ax387 = 0; ax387 < 128; ++ax387) {
        ((int32_t*)compute1)[((((ax1102 * 3584) + (ax287 * 128)) + ax387))] = ((int32_t*)out)[((((ax1102 * 3584) + (ax287 * 128)) + ax387))];
      }
    }
  }
  for (int32_t h126 = 0; h126 < 28; ++h126) {
    for (int32_t w65 = 0; w65 < 28; ++w65) {
      for (int32_t c76 = 0; c76 < 128; ++c76) {
        ((int32_t*)pad_data)[((((h126 * 3584) + (w65 * 128)) + c76))] = 12;
      }
    }
  }
  for (int32_t h127 = 0; h127 < 28; ++h127) {
    (void)load(compute1, (int64_t)537264128, 1792, (h127 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h127 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h127 * 14336));
  }
  for (int32_t h128 = 0; h128 < 28; ++h128) {
    for (int32_t w66 = 0; w66 < 28; ++w66) {
      for (int32_t c77 = 0; c77 < 128; ++c77) {
        ((int32_t*)compute1)[((((h128 * 3584) + (w66 * 128)) + c77))] = ((int32_t*)tensor_150)[(c77)];
      }
    }
  }
  for (int32_t h129 = 0; h129 < 28; ++h129) {
    (void)load(out1, (int64_t)537264128, 1792, (h129 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h129 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h129 * 14336));
  }
  for (int32_t h130 = 0; h130 < 28; ++h130) {
    for (int32_t w67 = 0; w67 < 28; ++w67) {
      for (int32_t c78 = 0; c78 < 128; ++c78) {
        ((int32_t*)compute1)[((((h130 * 3584) + (w67 * 128)) + c78))] = ((int32_t*)tensor_151)[(c78)];
      }
    }
  }
  for (int32_t h131 = 0; h131 < 28; ++h131) {
    (void)load(out, (int64_t)537264128, 1792, (h131 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h131 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h131 * 14336));
  }
  for (int32_t h132 = 0; h132 < 28; ++h132) {
    for (int32_t w68 = 0; w68 < 28; ++w68) {
      for (int32_t c79 = 0; c79 < 128; ++c79) {
        ((int32_t*)compute1)[((((h132 * 3584) + (w68 * 128)) + c79))] = 0;
      }
    }
  }
  for (int32_t h133 = 0; h133 < 28; ++h133) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h133 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h133 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h133 * 14336));
  }
  for (int32_t h134 = 0; h134 < 28; ++h134) {
    for (int32_t w69 = 0; w69 < 28; ++w69) {
      for (int32_t c80 = 0; c80 < 128; ++c80) {
        ((int32_t*)compute1)[((((h134 * 3584) + (w69 * 128)) + c80))] = 262144;
      }
    }
  }
  for (int32_t h135 = 0; h135 < 28; ++h135) {
    (void)load(out1, (int64_t)537264128, 1792, (h135 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h135 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h135 * 14336));
  }
  for (int32_t h136 = 0; h136 < 28; ++h136) {
    for (int32_t w70 = 0; w70 < 28; ++w70) {
      for (int32_t c81 = 0; c81 < 128; ++c81) {
        ((int32_t*)compute1)[((((h136 * 3584) + (w70 * 128)) + c81))] = 19;
      }
    }
  }
  for (int32_t h137 = 0; h137 < 28; ++h137) {
    (void)load(out, (int64_t)537264128, 1792, (h137 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h137 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h137 * 14336));
  }
  for (int32_t i166 = 0; i166 < 28; ++i166) {
    for (int32_t i252 = 0; i252 < 28; ++i252) {
      for (int32_t i352 = 0; i352 < 128; ++i352) {
        int32_t _42 = ((int32_t*)pad_data)[((((i166 * 3584) + (i252 * 128)) + i352))];
        int32_t _43 = (_42) < (127) ? (_42) : (127);
        ((int32_t*)compute1)[((((i166 * 3584) + (i252 * 128)) + i352))] = ((_43) > (-127) ? (_43) : (-127));
      }
    }
  }
  for (int32_t i167 = 0; i167 < 28; ++i167) {
    for (int32_t i253 = 0; i253 < 28; ++i253) {
      for (int32_t i353 = 0; i353 < 128; ++i353) {
        ((int8_t*)T_reshape)[((((i167 * 3584) + (i253 * 128)) + i353))] = ((int8_t)((int32_t*)compute1)[((((i167 * 3584) + (i253 * 128)) + i353))]);
      }
    }
  }
  for (int32_t i168 = 0; i168 < 30; ++i168) {
    for (int32_t i254 = 0; i254 < 30; ++i254) {
      for (int32_t i354 = 0; i354 < 128; ++i354) {
        ((int8_t*)compute1)[((((i168 * 3840) + (i254 * 128)) + i354))] = (((((1 <= i168) && (i168 < 29)) && (1 <= i254)) && (i254 < 29)) ? ((int8_t*)T_reshape)[(((((i168 * 3584) + (i254 * 128)) + i354) - 3712))] : (int8_t)0);
      }
    }
  }
  for (int32_t o110 = 0; o110 < 28; ++o110) {
    for (int32_t o210 = 0; o210 < 28; ++o210) {
      for (int32_t k13 = 0; k13 < 3; ++k13) {
        for (int32_t k23 = 0; k23 < 3; ++k23) {
          for (int32_t c82 = 0; c82 < 128; ++c82) {
            ((int8_t*)out1)[((((((o110 * 32256) + (o210 * 1152)) + (k13 * 384)) + (k23 * 128)) + c82))] = ((int8_t*)compute1)[((((((k13 * 3840) + (o110 * 3840)) + (k23 * 128)) + (o210 * 128)) + c82))];
          }
        }
      }
    }
  }
  for (int32_t ax098 = 0; ax098 < 784; ++ax098) {
    for (int32_t ax1103 = 0; ax1103 < 1152; ++ax1103) {
      ((int8_t*)compute1)[(((ax098 * 1152) + ax1103))] = ((int8_t*)out1)[(((ax098 * 1152) + ax1103))];
    }
  }
  for (int32_t i014 = 0; i014 < 784; ++i014) {
    for (int32_t i169 = 0; i169 < 1152; ++i169) {
      ((int8_t*)out)[(((i014 * 1152) + i169))] = ((int8_t*)compute1)[(((i014 * 1152) + i169))];
    }
  }
  for (int32_t ax099 = 0; ax099 < 98; ++ax099) {
    for (int32_t ax1104 = 0; ax1104 < 8; ++ax1104) {
      for (int32_t ax288 = 0; ax288 < 144; ++ax288) {
        for (int32_t ax388 = 0; ax388 < 8; ++ax388) {
          ((int8_t*)compute1)[(((((ax099 * 9216) + (ax1104 * 1152)) + (ax288 * 8)) + ax388))] = ((int8_t*)out)[(((((ax099 * 9216) + (ax1104 * 1152)) + (ax288 * 8)) + ax388))];
        }
      }
    }
  }
  for (int32_t ax0100 = 0; ax0100 < 98; ++ax0100) {
    for (int32_t ax1105 = 0; ax1105 < 144; ++ax1105) {
      for (int32_t ax289 = 0; ax289 < 8; ++ax289) {
        for (int32_t ax389 = 0; ax389 < 8; ++ax389) {
          ((int8_t*)pad_data)[(((((ax0100 * 9216) + (ax1105 * 64)) + (ax289 * 8)) + ax389))] = ((int8_t*)compute1)[(((((ax0100 * 9216) + (ax289 * 1152)) + (ax1105 * 8)) + ax389))];
        }
      }
    }
  }
  for (int32_t ax0101 = 0; ax0101 < 98; ++ax0101) {
    for (int32_t ax1106 = 0; ax1106 < 2; ++ax1106) {
      for (int32_t ax290 = 0; ax290 < 72; ++ax290) {
        for (int32_t ax390 = 0; ax390 < 8; ++ax390) {
          for (int32_t ax414 = 0; ax414 < 8; ++ax414) {
            ((int8_t*)compute1)[((((((ax0101 * 9216) + (ax1106 * 4608)) + (ax290 * 64)) + (ax390 * 8)) + ax414))] = ((int8_t*)pad_data)[((((((ax0101 * 9216) + (ax1106 * 4608)) + (ax290 * 64)) + (ax390 * 8)) + ax414))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 112896, 0);
  for (int32_t ax0102 = 0; ax0102 < 128; ++ax0102) {
    for (int32_t ax1107 = 0; ax1107 < 1152; ++ax1107) {
      ((int8_t*)T_reshape)[(((ax0102 * 1152) + ax1107))] = ((int8_t*)kernel_158)[(((ax0102 * 1152) + ax1107))];
    }
  }
  for (int32_t ax0103 = 0; ax0103 < 16; ++ax0103) {
    for (int32_t ax1108 = 0; ax1108 < 8; ++ax1108) {
      for (int32_t ax291 = 0; ax291 < 144; ++ax291) {
        for (int32_t ax391 = 0; ax391 < 8; ++ax391) {
          ((int8_t*)compute1)[(((((ax0103 * 9216) + (ax1108 * 1152)) + (ax291 * 8)) + ax391))] = ((int8_t*)T_reshape)[(((((ax0103 * 9216) + (ax1108 * 1152)) + (ax291 * 8)) + ax391))];
        }
      }
    }
  }
  for (int32_t ax0104 = 0; ax0104 < 16; ++ax0104) {
    for (int32_t ax1109 = 0; ax1109 < 144; ++ax1109) {
      for (int32_t ax292 = 0; ax292 < 8; ++ax292) {
        for (int32_t ax392 = 0; ax392 < 8; ++ax392) {
          ((int8_t*)T_reshape)[(((((ax0104 * 9216) + (ax1109 * 64)) + (ax292 * 8)) + ax392))] = ((int8_t*)compute1)[(((((ax0104 * 9216) + (ax292 * 1152)) + (ax1109 * 8)) + ax392))];
        }
      }
    }
  }
  for (int32_t ax0105 = 0; ax0105 < 16; ++ax0105) {
    for (int32_t ax1110 = 0; ax1110 < 2; ++ax1110) {
      for (int32_t ax293 = 0; ax293 < 72; ++ax293) {
        for (int32_t ax393 = 0; ax393 < 8; ++ax393) {
          for (int32_t ax415 = 0; ax415 < 8; ++ax415) {
            ((int8_t*)compute1)[((((((ax0105 * 9216) + (ax1110 * 4608)) + (ax293 * 64)) + (ax393 * 8)) + ax415))] = ((int8_t*)T_reshape)[((((((ax0105 * 9216) + (ax1110 * 4608)) + (ax293 * 64)) + (ax393 * 8)) + ax415))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536936448, 18432, 0);
  for (int32_t i42 = 0; i42 < 98; ++i42) {
    for (int32_t x11 = 0; x11 < 16; ++x11) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k0 = 0; k0 < 2; ++k0) {
        (void)move(((((int64_t)((i42 * 576) + (k0 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x11 * 576) + (k0 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute1, (int64_t)537264128, 32, ((i42 * 4096) + (x11 * 256)));
    }
  }
  for (int32_t ax0106 = 0; ax0106 < 98; ++ax0106) {
    for (int32_t ax1111 = 0; ax1111 < 8; ++ax1111) {
      for (int32_t ax294 = 0; ax294 < 16; ++ax294) {
        for (int32_t ax394 = 0; ax394 < 8; ++ax394) {
          ((int32_t*)out1)[(((((ax0106 * 1024) + (ax1111 * 128)) + (ax294 * 8)) + ax394))] = ((int32_t*)compute1)[(((((ax0106 * 1024) + (ax294 * 64)) + (ax1111 * 8)) + ax394))];
        }
      }
    }
  }
  for (int32_t ax0107 = 0; ax0107 < 784; ++ax0107) {
    for (int32_t ax1112 = 0; ax1112 < 128; ++ax1112) {
      ((int32_t*)compute1)[(((ax0107 * 128) + ax1112))] = ((int32_t*)out1)[(((ax0107 * 128) + ax1112))];
    }
  }
  for (int32_t i015 = 0; i015 < 784; ++i015) {
    for (int32_t i170 = 0; i170 < 128; ++i170) {
      ((int32_t*)out)[(((i015 * 128) + i170))] = ((int32_t*)compute1)[(((i015 * 128) + i170))];
    }
  }
  for (int32_t ax1113 = 0; ax1113 < 28; ++ax1113) {
    for (int32_t ax295 = 0; ax295 < 28; ++ax295) {
      for (int32_t ax395 = 0; ax395 < 128; ++ax395) {
        ((int32_t*)compute1)[((((ax1113 * 3584) + (ax295 * 128)) + ax395))] = ((int32_t*)out)[((((ax1113 * 3584) + (ax295 * 128)) + ax395))];
      }
    }
  }
  for (int32_t h138 = 0; h138 < 28; ++h138) {
    for (int32_t w71 = 0; w71 < 28; ++w71) {
      for (int32_t c83 = 0; c83 < 128; ++c83) {
        ((int32_t*)pad_data)[((((h138 * 3584) + (w71 * 128)) + c83))] = ((int32_t*)tensor_159)[(c83)];
      }
    }
  }
  for (int32_t h139 = 0; h139 < 28; ++h139) {
    (void)load(compute1, (int64_t)537264128, 1792, (h139 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h139 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h139 * 14336));
  }
  for (int32_t h140 = 0; h140 < 28; ++h140) {
    for (int32_t w72 = 0; w72 < 28; ++w72) {
      for (int32_t c84 = 0; c84 < 128; ++c84) {
        ((int32_t*)compute1)[((((h140 * 3584) + (w72 * 128)) + c84))] = 0;
      }
    }
  }
  for (int32_t h141 = 0; h141 < 28; ++h141) {
    (void)load(out1, (int64_t)537264128, 1792, (h141 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h141 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h141 * 14336));
  }
  for (int32_t h142 = 0; h142 < 28; ++h142) {
    for (int32_t w73 = 0; w73 < 28; ++w73) {
      for (int32_t c85 = 0; c85 < 128; ++c85) {
        ((int32_t*)compute1)[((((h142 * 3584) + (w73 * 128)) + c85))] = 64;
      }
    }
  }
  for (int32_t h143 = 0; h143 < 28; ++h143) {
    (void)load(out, (int64_t)537264128, 1792, (h143 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h143 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h143 * 14336));
  }
  for (int32_t h144 = 0; h144 < 28; ++h144) {
    for (int32_t w74 = 0; w74 < 28; ++w74) {
      for (int32_t c86 = 0; c86 < 128; ++c86) {
        ((int32_t*)compute1)[((((h144 * 3584) + (w74 * 128)) + c86))] = 7;
      }
    }
  }
  for (int32_t h145 = 0; h145 < 28; ++h145) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h145 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h145 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h145 * 14336));
  }
  for (int32_t i171 = 0; i171 < 28; ++i171) {
    for (int32_t i255 = 0; i255 < 28; ++i255) {
      for (int32_t i355 = 0; i355 < 128; ++i355) {
        int32_t _44 = ((int32_t*)out1)[((((i171 * 3584) + (i255 * 128)) + i355))];
        int32_t _45 = (_44) < (127) ? (_44) : (127);
        ((int32_t*)compute1)[((((i171 * 3584) + (i255 * 128)) + i355))] = ((_45) > (-127) ? (_45) : (-127));
      }
    }
  }
  for (int32_t i172 = 0; i172 < 28; ++i172) {
    for (int32_t i256 = 0; i256 < 28; ++i256) {
      for (int32_t i356 = 0; i356 < 128; ++i356) {
        ((int8_t*)T_reshape)[((((i172 * 3584) + (i256 * 128)) + i356))] = ((int8_t)((int32_t*)compute1)[((((i172 * 3584) + (i256 * 128)) + i356))]);
      }
    }
  }
  for (int32_t o111 = 0; o111 < 28; ++o111) {
    for (int32_t o211 = 0; o211 < 28; ++o211) {
      for (int32_t c87 = 0; c87 < 128; ++c87) {
        ((int8_t*)T_reshape1)[((((o111 * 3584) + (o211 * 128)) + c87))] = ((int8_t*)T_reshape)[((((o111 * 3584) + (o211 * 128)) + c87))];
      }
    }
  }
  for (int32_t ax0108 = 0; ax0108 < 98; ++ax0108) {
    for (int32_t ax1114 = 0; ax1114 < 8; ++ax1114) {
      for (int32_t ax296 = 0; ax296 < 16; ++ax296) {
        for (int32_t ax396 = 0; ax396 < 8; ++ax396) {
          ((int8_t*)T_reshape)[(((((ax0108 * 1024) + (ax1114 * 128)) + (ax296 * 8)) + ax396))] = ((int8_t*)T_reshape1)[(((((ax0108 * 1024) + (ax1114 * 128)) + (ax296 * 8)) + ax396))];
        }
      }
    }
  }
  for (int32_t ax0109 = 0; ax0109 < 98; ++ax0109) {
    for (int32_t ax1115 = 0; ax1115 < 16; ++ax1115) {
      for (int32_t ax297 = 0; ax297 < 8; ++ax297) {
        for (int32_t ax397 = 0; ax397 < 8; ++ax397) {
          ((int8_t*)T_reshape1)[(((((ax0109 * 1024) + (ax1115 * 64)) + (ax297 * 8)) + ax397))] = ((int8_t*)T_reshape)[(((((ax0109 * 1024) + (ax297 * 128)) + (ax1115 * 8)) + ax397))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 12544, 0);
  for (int32_t ax0110 = 0; ax0110 < 512; ++ax0110) {
    for (int32_t ax1116 = 0; ax1116 < 128; ++ax1116) {
      ((int8_t*)T_reshape1)[(((ax0110 * 128) + ax1116))] = ((int8_t*)kernel_166)[(((ax0110 * 128) + ax1116))];
    }
  }
  for (int32_t ax0111 = 0; ax0111 < 64; ++ax0111) {
    for (int32_t ax1117 = 0; ax1117 < 8; ++ax1117) {
      for (int32_t ax298 = 0; ax298 < 16; ++ax298) {
        for (int32_t ax398 = 0; ax398 < 8; ++ax398) {
          ((int8_t*)T_reshape)[(((((ax0111 * 1024) + (ax1117 * 128)) + (ax298 * 8)) + ax398))] = ((int8_t*)T_reshape1)[(((((ax0111 * 1024) + (ax1117 * 128)) + (ax298 * 8)) + ax398))];
        }
      }
    }
  }
  for (int32_t ax0112 = 0; ax0112 < 64; ++ax0112) {
    for (int32_t ax1118 = 0; ax1118 < 16; ++ax1118) {
      for (int32_t ax299 = 0; ax299 < 8; ++ax299) {
        for (int32_t ax399 = 0; ax399 < 8; ++ax399) {
          ((int8_t*)T_reshape1)[(((((ax0112 * 1024) + (ax1118 * 64)) + (ax299 * 8)) + ax399))] = ((int8_t*)T_reshape)[(((((ax0112 * 1024) + (ax299 * 128)) + (ax1118 * 8)) + ax399))];
        }
      }
    }
  }
  for (int32_t ax0113 = 0; ax0113 < 64; ++ax0113) {
    for (int32_t ax2100 = 0; ax2100 < 16; ++ax2100) {
      for (int32_t ax3100 = 0; ax3100 < 8; ++ax3100) {
        for (int32_t ax416 = 0; ax416 < 8; ++ax416) {
          ((int8_t*)T_reshape)[(((((ax0113 * 1024) + (ax2100 * 64)) + (ax3100 * 8)) + ax416))] = ((int8_t*)T_reshape1)[(((((ax0113 * 1024) + (ax2100 * 64)) + (ax3100 * 8)) + ax416))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i43 = 0; i43 < 98; ++i43) {
    for (int32_t x12 = 0; x12 < 64; ++x12) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i43 * 64) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 128, 0);
      (void)move(((((int64_t)(x12 * 64)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 128, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 16, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i43 * 16384) + (x12 * 256)));
    }
  }
  for (int32_t ax0114 = 0; ax0114 < 98; ++ax0114) {
    for (int32_t ax1119 = 0; ax1119 < 8; ++ax1119) {
      for (int32_t ax2101 = 0; ax2101 < 64; ++ax2101) {
        for (int32_t ax3101 = 0; ax3101 < 8; ++ax3101) {
          ((int32_t*)out)[(((((ax0114 * 4096) + (ax1119 * 512)) + (ax2101 * 8)) + ax3101))] = ((int32_t*)compute1)[(((((ax0114 * 4096) + (ax2101 * 64)) + (ax1119 * 8)) + ax3101))];
        }
      }
    }
  }
  for (int32_t ax0115 = 0; ax0115 < 784; ++ax0115) {
    for (int32_t ax1120 = 0; ax1120 < 512; ++ax1120) {
      ((int32_t*)compute1)[(((ax0115 * 512) + ax1120))] = ((int32_t*)out)[(((ax0115 * 512) + ax1120))];
    }
  }
  for (int32_t i016 = 0; i016 < 784; ++i016) {
    for (int32_t i173 = 0; i173 < 512; ++i173) {
      ((int32_t*)pad_data)[(((i016 * 512) + i173))] = ((int32_t*)compute1)[(((i016 * 512) + i173))];
    }
  }
  for (int32_t ax1121 = 0; ax1121 < 28; ++ax1121) {
    for (int32_t ax2102 = 0; ax2102 < 28; ++ax2102) {
      for (int32_t ax3102 = 0; ax3102 < 512; ++ax3102) {
        ((int32_t*)compute1)[((((ax1121 * 14336) + (ax2102 * 512)) + ax3102))] = ((int32_t*)pad_data)[((((ax1121 * 14336) + (ax2102 * 512)) + ax3102))];
      }
    }
  }
  for (int32_t h146 = 0; h146 < 28; ++h146) {
    for (int32_t w75 = 0; w75 < 28; ++w75) {
      for (int32_t c88 = 0; c88 < 512; ++c88) {
        ((int32_t*)out1)[((((h146 * 14336) + (w75 * 512)) + c88))] = 10;
      }
    }
  }
  for (int32_t h147 = 0; h147 < 28; ++h147) {
    (void)load(compute1, (int64_t)537264128, 7168, (h147 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h147 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h147 * 57344));
  }
  for (int32_t h148 = 0; h148 < 28; ++h148) {
    for (int32_t w76 = 0; w76 < 28; ++w76) {
      for (int32_t c89 = 0; c89 < 512; ++c89) {
        ((int32_t*)compute1)[((((h148 * 14336) + (w76 * 512)) + c89))] = ((int32_t*)tensor_168)[(c89)];
      }
    }
  }
  for (int32_t h149 = 0; h149 < 28; ++h149) {
    (void)load(out, (int64_t)537264128, 7168, (h149 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h149 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h149 * 57344));
  }
  for (int32_t h150 = 0; h150 < 28; ++h150) {
    for (int32_t w77 = 0; w77 < 28; ++w77) {
      for (int32_t c90 = 0; c90 < 512; ++c90) {
        ((int32_t*)compute1)[((((h150 * 14336) + (w77 * 512)) + c90))] = 131072;
      }
    }
  }
  for (int32_t h151 = 0; h151 < 28; ++h151) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h151 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h151 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h151 * 57344));
  }
  for (int32_t h152 = 0; h152 < 28; ++h152) {
    for (int32_t w78 = 0; w78 < 28; ++w78) {
      for (int32_t c91 = 0; c91 < 512; ++c91) {
        ((int32_t*)compute1)[((((h152 * 14336) + (w78 * 512)) + c91))] = 18;
      }
    }
  }
  for (int32_t h153 = 0; h153 < 28; ++h153) {
    (void)load(out1, (int64_t)537264128, 7168, (h153 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h153 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h153 * 57344));
  }
  for (int32_t i174 = 0; i174 < 28; ++i174) {
    for (int32_t i257 = 0; i257 < 28; ++i257) {
      for (int32_t i357 = 0; i357 < 512; ++i357) {
        int32_t _46 = ((int32_t*)out)[((((i174 * 14336) + (i257 * 512)) + i357))];
        int32_t _47 = (_46) < (127) ? (_46) : (127);
        ((int32_t*)compute1)[((((i174 * 14336) + (i257 * 512)) + i357))] = ((_47) > (-127) ? (_47) : (-127));
      }
    }
  }
  for (int32_t i175 = 0; i175 < 28; ++i175) {
    for (int32_t i258 = 0; i258 < 28; ++i258) {
      for (int32_t i358 = 0; i358 < 512; ++i358) {
        ((int8_t*)pad_data)[((((i175 * 14336) + (i258 * 512)) + i358))] = ((int8_t)((int32_t*)compute1)[((((i175 * 14336) + (i258 * 512)) + i358))]);
      }
    }
  }
  for (int32_t i176 = 0; i176 < 28; ++i176) {
    for (int32_t i259 = 0; i259 < 28; ++i259) {
      for (int32_t i359 = 0; i359 < 512; ++i359) {
        ((int32_t*)compute1)[((((i176 * 14336) + (i259 * 512)) + i359))] = ((int32_t)((int8_t*)pad_data)[((((i176 * 14336) + (i259 * 512)) + i359))]);
      }
    }
  }
  for (int32_t h154 = 0; h154 < 28; ++h154) {
    for (int32_t w79 = 0; w79 < 28; ++w79) {
      for (int32_t c92 = 0; c92 < 512; ++c92) {
        ((int32_t*)out1)[((((h154 * 14336) + (w79 * 512)) + c92))] = ((int32_t*)tensor_175)[(c92)];
      }
    }
  }
  for (int32_t h155 = 0; h155 < 28; ++h155) {
    (void)load(compute1, (int64_t)537264128, 7168, (h155 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h155 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h155 * 57344));
  }
  for (int32_t h156 = 0; h156 < 28; ++h156) {
    for (int32_t w80 = 0; w80 < 28; ++w80) {
      for (int32_t c93 = 0; c93 < 512; ++c93) {
        ((int32_t*)compute1)[((((h156 * 14336) + (w80 * 512)) + c93))] = ((int32_t*)tensor_176)[(c93)];
      }
    }
  }
  for (int32_t h157 = 0; h157 < 28; ++h157) {
    (void)load(out, (int64_t)537264128, 7168, (h157 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h157 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h157 * 57344));
  }
  for (int32_t h158 = 0; h158 < 28; ++h158) {
    for (int32_t w81 = 0; w81 < 28; ++w81) {
      for (int32_t c94 = 0; c94 < 512; ++c94) {
        ((int32_t*)compute1)[((((h158 * 14336) + (w81 * 512)) + c94))] = 8;
      }
    }
  }
  for (int32_t h159 = 0; h159 < 28; ++h159) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h159 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h159 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h159 * 57344));
  }
  for (int32_t h160 = 0; h160 < 28; ++h160) {
    for (int32_t w82 = 0; w82 < 28; ++w82) {
      for (int32_t c95 = 0; c95 < 512; ++c95) {
        ((int32_t*)compute1)[((((h160 * 14336) + (w82 * 512)) + c95))] = 4;
      }
    }
  }
  for (int32_t h161 = 0; h161 < 28; ++h161) {
    (void)load(out1, (int64_t)537264128, 7168, (h161 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h161 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h161 * 57344));
  }
  for (int32_t i177 = 0; i177 < 28; ++i177) {
    for (int32_t i260 = 0; i260 < 28; ++i260) {
      for (int32_t i360 = 0; i360 < 512; ++i360) {
        int32_t _48 = ((int32_t*)out)[((((i177 * 14336) + (i260 * 512)) + i360))];
        int32_t _49 = (_48) < (127) ? (_48) : (127);
        ((int32_t*)compute1)[((((i177 * 14336) + (i260 * 512)) + i360))] = ((_49) > (-127) ? (_49) : (-127));
      }
    }
  }
  for (int32_t i178 = 0; i178 < 28; ++i178) {
    for (int32_t i261 = 0; i261 < 28; ++i261) {
      for (int32_t i361 = 0; i361 < 512; ++i361) {
        ((int8_t*)pad_data)[((((i178 * 14336) + (i261 * 512)) + i361))] = ((int8_t)((int32_t*)compute1)[((((i178 * 14336) + (i261 * 512)) + i361))]);
      }
    }
  }
  for (int32_t i179 = 0; i179 < 28; ++i179) {
    for (int32_t i262 = 0; i262 < 28; ++i262) {
      for (int32_t i362 = 0; i362 < 512; ++i362) {
        ((int32_t*)compute1)[((((i179 * 14336) + (i262 * 512)) + i362))] = ((int32_t)((int8_t*)pad_data)[((((i179 * 14336) + (i262 * 512)) + i362))]);
      }
    }
  }
  for (int32_t o112 = 0; o112 < 28; ++o112) {
    for (int32_t o212 = 0; o212 < 28; ++o212) {
      for (int32_t c96 = 0; c96 < 256; ++c96) {
        ((int8_t*)out1)[((((o112 * 7168) + (o212 * 256)) + c96))] = ((int8_t*)compute)[((((o112 * 28160) + (o212 * 512)) + c96))];
      }
    }
  }
  for (int32_t ax0116 = 0; ax0116 < 784; ++ax0116) {
    for (int32_t ax1122 = 0; ax1122 < 256; ++ax1122) {
      ((int8_t*)compute)[(((ax0116 * 256) + ax1122))] = ((int8_t*)out1)[(((ax0116 * 256) + ax1122))];
    }
  }
  for (int32_t i017 = 0; i017 < 784; ++i017) {
    for (int32_t i180 = 0; i180 < 256; ++i180) {
      ((int8_t*)out)[(((i017 * 256) + i180))] = ((int8_t*)compute)[(((i017 * 256) + i180))];
    }
  }
  for (int32_t ax0117 = 0; ax0117 < 98; ++ax0117) {
    for (int32_t ax1123 = 0; ax1123 < 8; ++ax1123) {
      for (int32_t ax2103 = 0; ax2103 < 32; ++ax2103) {
        for (int32_t ax3103 = 0; ax3103 < 8; ++ax3103) {
          ((int8_t*)compute)[(((((ax0117 * 2048) + (ax1123 * 256)) + (ax2103 * 8)) + ax3103))] = ((int8_t*)out)[(((((ax0117 * 2048) + (ax1123 * 256)) + (ax2103 * 8)) + ax3103))];
        }
      }
    }
  }
  for (int32_t ax0118 = 0; ax0118 < 98; ++ax0118) {
    for (int32_t ax1124 = 0; ax1124 < 32; ++ax1124) {
      for (int32_t ax2104 = 0; ax2104 < 8; ++ax2104) {
        for (int32_t ax3104 = 0; ax3104 < 8; ++ax3104) {
          ((int8_t*)pad_data)[(((((ax0118 * 2048) + (ax1124 * 64)) + (ax2104 * 8)) + ax3104))] = ((int8_t*)compute)[(((((ax0118 * 2048) + (ax2104 * 256)) + (ax1124 * 8)) + ax3104))];
        }
      }
    }
  }
  for (int32_t ax0119 = 0; ax0119 < 98; ++ax0119) {
    for (int32_t ax2105 = 0; ax2105 < 32; ++ax2105) {
      for (int32_t ax3105 = 0; ax3105 < 8; ++ax3105) {
        for (int32_t ax417 = 0; ax417 < 8; ++ax417) {
          ((int8_t*)compute)[(((((ax0119 * 2048) + (ax2105 * 64)) + (ax3105 * 8)) + ax417))] = ((int8_t*)pad_data)[(((((ax0119 * 2048) + (ax2105 * 64)) + (ax3105 * 8)) + ax417))];
        }
      }
    }
  }
  (void)load(compute, (int64_t)536870912, 25088, 0);
  for (int32_t ax0120 = 0; ax0120 < 512; ++ax0120) {
    for (int32_t ax1125 = 0; ax1125 < 256; ++ax1125) {
      ((int8_t*)T_reshape)[(((ax0120 * 256) + ax1125))] = ((int8_t*)kernel_184)[(((ax0120 * 256) + ax1125))];
    }
  }
  for (int32_t ax0121 = 0; ax0121 < 64; ++ax0121) {
    for (int32_t ax1126 = 0; ax1126 < 8; ++ax1126) {
      for (int32_t ax2106 = 0; ax2106 < 32; ++ax2106) {
        for (int32_t ax3106 = 0; ax3106 < 8; ++ax3106) {
          ((int8_t*)compute)[(((((ax0121 * 2048) + (ax1126 * 256)) + (ax2106 * 8)) + ax3106))] = ((int8_t*)T_reshape)[(((((ax0121 * 2048) + (ax1126 * 256)) + (ax2106 * 8)) + ax3106))];
        }
      }
    }
  }
  for (int32_t ax0122 = 0; ax0122 < 64; ++ax0122) {
    for (int32_t ax1127 = 0; ax1127 < 32; ++ax1127) {
      for (int32_t ax2107 = 0; ax2107 < 8; ++ax2107) {
        for (int32_t ax3107 = 0; ax3107 < 8; ++ax3107) {
          ((int8_t*)T_reshape)[(((((ax0122 * 2048) + (ax1127 * 64)) + (ax2107 * 8)) + ax3107))] = ((int8_t*)compute)[(((((ax0122 * 2048) + (ax2107 * 256)) + (ax1127 * 8)) + ax3107))];
        }
      }
    }
  }
  for (int32_t ax0123 = 0; ax0123 < 64; ++ax0123) {
    for (int32_t ax2108 = 0; ax2108 < 32; ++ax2108) {
      for (int32_t ax3108 = 0; ax3108 < 8; ++ax3108) {
        for (int32_t ax418 = 0; ax418 < 8; ++ax418) {
          ((int8_t*)compute)[(((((ax0123 * 2048) + (ax2108 * 64)) + (ax3108 * 8)) + ax418))] = ((int8_t*)T_reshape)[(((((ax0123 * 2048) + (ax2108 * 64)) + (ax3108 * 8)) + ax418))];
        }
      }
    }
  }
  (void)load(compute, (int64_t)536936448, 16384, 0);
  for (int32_t i44 = 0; i44 < 98; ++i44) {
    for (int32_t x13 = 0; x13 < 64; ++x13) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i44 * 128)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x13 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(out1, (int64_t)537264128, 32, ((i44 * 16384) + (x13 * 256)));
    }
  }
  for (int32_t ax0124 = 0; ax0124 < 98; ++ax0124) {
    for (int32_t ax1128 = 0; ax1128 < 8; ++ax1128) {
      for (int32_t ax2109 = 0; ax2109 < 64; ++ax2109) {
        for (int32_t ax3109 = 0; ax3109 < 8; ++ax3109) {
          ((int32_t*)out)[(((((ax0124 * 4096) + (ax1128 * 512)) + (ax2109 * 8)) + ax3109))] = ((int32_t*)out1)[(((((ax0124 * 4096) + (ax2109 * 64)) + (ax1128 * 8)) + ax3109))];
        }
      }
    }
  }
  for (int32_t ax0125 = 0; ax0125 < 784; ++ax0125) {
    for (int32_t ax1129 = 0; ax1129 < 512; ++ax1129) {
      ((int32_t*)pad_data)[(((ax0125 * 512) + ax1129))] = ((int32_t*)out)[(((ax0125 * 512) + ax1129))];
    }
  }
  for (int32_t i018 = 0; i018 < 784; ++i018) {
    for (int32_t i181 = 0; i181 < 512; ++i181) {
      ((int32_t*)out1)[(((i018 * 512) + i181))] = ((int32_t*)pad_data)[(((i018 * 512) + i181))];
    }
  }
  for (int32_t ax1130 = 0; ax1130 < 28; ++ax1130) {
    for (int32_t ax2110 = 0; ax2110 < 28; ++ax2110) {
      for (int32_t ax3110 = 0; ax3110 < 512; ++ax3110) {
        ((int32_t*)out)[((((ax1130 * 14336) + (ax2110 * 512)) + ax3110))] = ((int32_t*)out1)[((((ax1130 * 14336) + (ax2110 * 512)) + ax3110))];
      }
    }
  }
  for (int32_t h162 = 0; h162 < 28; ++h162) {
    for (int32_t w83 = 0; w83 < 28; ++w83) {
      for (int32_t c97 = 0; c97 < 512; ++c97) {
        ((int32_t*)pad_data)[((((h162 * 14336) + (w83 * 512)) + c97))] = ((int32_t*)tensor_185)[(c97)];
      }
    }
  }
  for (int32_t h163 = 0; h163 < 28; ++h163) {
    (void)load(out, (int64_t)537264128, 7168, (h163 * 14336));
    (void)load(pad_data, (int64_t)537329664, 7168, (h163 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h163 * 57344));
  }
  for (int32_t h164 = 0; h164 < 28; ++h164) {
    for (int32_t w84 = 0; w84 < 28; ++w84) {
      for (int32_t c98 = 0; c98 < 512; ++c98) {
        ((int32_t*)out)[((((h164 * 14336) + (w84 * 512)) + c98))] = 64;
      }
    }
  }
  for (int32_t h165 = 0; h165 < 28; ++h165) {
    (void)load(out1, (int64_t)537264128, 7168, (h165 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h165 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h165 * 57344));
  }
  for (int32_t h166 = 0; h166 < 28; ++h166) {
    for (int32_t w85 = 0; w85 < 28; ++w85) {
      for (int32_t c99 = 0; c99 < 512; ++c99) {
        ((int32_t*)out1)[((((h166 * 14336) + (w85 * 512)) + c99))] = 7;
      }
    }
  }
  for (int32_t h167 = 0; h167 < 28; ++h167) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h167 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h167 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h167 * 57344));
  }
  for (int32_t i182 = 0; i182 < 28; ++i182) {
    for (int32_t i263 = 0; i263 < 28; ++i263) {
      for (int32_t i363 = 0; i363 < 512; ++i363) {
        int32_t _50 = ((int32_t*)out)[((((i182 * 14336) + (i263 * 512)) + i363))];
        int32_t _51 = (_50) < (127) ? (_50) : (127);
        ((int32_t*)pad_data)[((((i182 * 14336) + (i263 * 512)) + i363))] = ((_51) > (-127) ? (_51) : (-127));
      }
    }
  }
  for (int32_t i183 = 0; i183 < 28; ++i183) {
    for (int32_t i264 = 0; i264 < 28; ++i264) {
      for (int32_t i364 = 0; i364 < 512; ++i364) {
        ((int8_t*)compute)[((((i183 * 14336) + (i264 * 512)) + i364))] = ((int8_t)((int32_t*)pad_data)[((((i183 * 14336) + (i264 * 512)) + i364))]);
      }
    }
  }
  for (int32_t i184 = 0; i184 < 28; ++i184) {
    for (int32_t i265 = 0; i265 < 28; ++i265) {
      for (int32_t i365 = 0; i365 < 512; ++i365) {
        ((int32_t*)out1)[((((i184 * 14336) + (i265 * 512)) + i365))] = ((int32_t)((int8_t*)compute)[((((i184 * 14336) + (i265 * 512)) + i365))]);
      }
    }
  }
  for (int32_t h168 = 0; h168 < 28; ++h168) {
    (void)load(compute1, (int64_t)537264128, 7168, (h168 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h168 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h168 * 57344));
  }
  for (int32_t h169 = 0; h169 < 28; ++h169) {
    for (int32_t w86 = 0; w86 < 28; ++w86) {
      for (int32_t c100 = 0; c100 < 512; ++c100) {
        ((int32_t*)compute1)[((((h169 * 14336) + (w86 * 512)) + c100))] = 0;
      }
    }
  }
  for (int32_t h170 = 0; h170 < 28; ++h170) {
    (void)load(out, (int64_t)537264128, 7168, (h170 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h170 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h170 * 57344));
  }
  for (int32_t i185 = 0; i185 < 28; ++i185) {
    for (int32_t i266 = 0; i266 < 28; ++i266) {
      for (int32_t i366 = 0; i366 < 512; ++i366) {
        int32_t _52 = ((int32_t*)pad_data)[((((i185 * 14336) + (i266 * 512)) + i366))];
        int32_t _53 = (_52) < (127) ? (_52) : (127);
        ((int32_t*)compute1)[((((i185 * 14336) + (i266 * 512)) + i366))] = ((_53) > (-127) ? (_53) : (-127));
      }
    }
  }
  for (int32_t i186 = 0; i186 < 28; ++i186) {
    for (int32_t i267 = 0; i267 < 28; ++i267) {
      for (int32_t i367 = 0; i367 < 512; ++i367) {
        ((int8_t*)compute)[((((i186 * 14336) + (i267 * 512)) + i367))] = ((int8_t)((int32_t*)compute1)[((((i186 * 14336) + (i267 * 512)) + i367))]);
      }
    }
  }
  for (int32_t o113 = 0; o113 < 28; ++o113) {
    for (int32_t o213 = 0; o213 < 28; ++o213) {
      for (int32_t c101 = 0; c101 < 512; ++c101) {
        ((int8_t*)compute1)[((((o113 * 14336) + (o213 * 512)) + c101))] = ((int8_t*)compute)[((((o113 * 14336) + (o213 * 512)) + c101))];
      }
    }
  }
  for (int32_t ax0126 = 0; ax0126 < 784; ++ax0126) {
    for (int32_t ax1131 = 0; ax1131 < 512; ++ax1131) {
      ((int8_t*)out1)[(((ax0126 * 512) + ax1131))] = ((int8_t*)compute1)[(((ax0126 * 512) + ax1131))];
    }
  }
  for (int32_t i019 = 0; i019 < 784; ++i019) {
    for (int32_t i187 = 0; i187 < 512; ++i187) {
      ((int8_t*)compute1)[(((i019 * 512) + i187))] = ((int8_t*)out1)[(((i019 * 512) + i187))];
    }
  }
  for (int32_t ax0127 = 0; ax0127 < 98; ++ax0127) {
    for (int32_t ax1132 = 0; ax1132 < 8; ++ax1132) {
      for (int32_t ax2111 = 0; ax2111 < 64; ++ax2111) {
        for (int32_t ax3111 = 0; ax3111 < 8; ++ax3111) {
          ((int8_t*)out)[(((((ax0127 * 4096) + (ax1132 * 512)) + (ax2111 * 8)) + ax3111))] = ((int8_t*)compute1)[(((((ax0127 * 4096) + (ax1132 * 512)) + (ax2111 * 8)) + ax3111))];
        }
      }
    }
  }
  for (int32_t ax0128 = 0; ax0128 < 98; ++ax0128) {
    for (int32_t ax1133 = 0; ax1133 < 64; ++ax1133) {
      for (int32_t ax2112 = 0; ax2112 < 8; ++ax2112) {
        for (int32_t ax3112 = 0; ax3112 < 8; ++ax3112) {
          ((int8_t*)compute1)[(((((ax0128 * 4096) + (ax1133 * 64)) + (ax2112 * 8)) + ax3112))] = ((int8_t*)out)[(((((ax0128 * 4096) + (ax2112 * 512)) + (ax1133 * 8)) + ax3112))];
        }
      }
    }
  }
  for (int32_t ax0129 = 0; ax0129 < 98; ++ax0129) {
    for (int32_t ax2113 = 0; ax2113 < 64; ++ax2113) {
      for (int32_t ax3113 = 0; ax3113 < 8; ++ax3113) {
        for (int32_t ax419 = 0; ax419 < 8; ++ax419) {
          ((int8_t*)pad_data)[(((((ax0129 * 4096) + (ax2113 * 64)) + (ax3113 * 8)) + ax419))] = ((int8_t*)compute1)[(((((ax0129 * 4096) + (ax2113 * 64)) + (ax3113 * 8)) + ax419))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 50176, 0);
  for (int32_t ax0130 = 0; ax0130 < 128; ++ax0130) {
    for (int32_t ax1134 = 0; ax1134 < 512; ++ax1134) {
      ((int8_t*)T_reshape1)[(((ax0130 * 512) + ax1134))] = ((int8_t*)kernel_198)[(((ax0130 * 512) + ax1134))];
    }
  }
  for (int32_t ax0131 = 0; ax0131 < 16; ++ax0131) {
    for (int32_t ax1135 = 0; ax1135 < 8; ++ax1135) {
      for (int32_t ax2114 = 0; ax2114 < 64; ++ax2114) {
        for (int32_t ax3114 = 0; ax3114 < 8; ++ax3114) {
          ((int8_t*)T_reshape)[(((((ax0131 * 4096) + (ax1135 * 512)) + (ax2114 * 8)) + ax3114))] = ((int8_t*)T_reshape1)[(((((ax0131 * 4096) + (ax1135 * 512)) + (ax2114 * 8)) + ax3114))];
        }
      }
    }
  }
  for (int32_t ax0132 = 0; ax0132 < 16; ++ax0132) {
    for (int32_t ax1136 = 0; ax1136 < 64; ++ax1136) {
      for (int32_t ax2115 = 0; ax2115 < 8; ++ax2115) {
        for (int32_t ax3115 = 0; ax3115 < 8; ++ax3115) {
          ((int8_t*)T_reshape1)[(((((ax0132 * 4096) + (ax1136 * 64)) + (ax2115 * 8)) + ax3115))] = ((int8_t*)T_reshape)[(((((ax0132 * 4096) + (ax2115 * 512)) + (ax1136 * 8)) + ax3115))];
        }
      }
    }
  }
  for (int32_t ax0133 = 0; ax0133 < 16; ++ax0133) {
    for (int32_t ax2116 = 0; ax2116 < 64; ++ax2116) {
      for (int32_t ax3116 = 0; ax3116 < 8; ++ax3116) {
        for (int32_t ax420 = 0; ax420 < 8; ++ax420) {
          ((int8_t*)T_reshape)[(((((ax0133 * 4096) + (ax2116 * 64)) + (ax3116 * 8)) + ax420))] = ((int8_t*)T_reshape1)[(((((ax0133 * 4096) + (ax2116 * 64)) + (ax3116 * 8)) + ax420))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i45 = 0; i45 < 98; ++i45) {
    for (int32_t x14 = 0; x14 < 16; ++x14) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i45 * 256)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x14 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i45 * 4096) + (x14 * 256)));
    }
  }
  for (int32_t ax0134 = 0; ax0134 < 98; ++ax0134) {
    for (int32_t ax1137 = 0; ax1137 < 8; ++ax1137) {
      for (int32_t ax2117 = 0; ax2117 < 16; ++ax2117) {
        for (int32_t ax3117 = 0; ax3117 < 8; ++ax3117) {
          ((int32_t*)out1)[(((((ax0134 * 1024) + (ax1137 * 128)) + (ax2117 * 8)) + ax3117))] = ((int32_t*)compute1)[(((((ax0134 * 1024) + (ax2117 * 64)) + (ax1137 * 8)) + ax3117))];
        }
      }
    }
  }
  for (int32_t ax0135 = 0; ax0135 < 784; ++ax0135) {
    for (int32_t ax1138 = 0; ax1138 < 128; ++ax1138) {
      ((int32_t*)compute1)[(((ax0135 * 128) + ax1138))] = ((int32_t*)out1)[(((ax0135 * 128) + ax1138))];
    }
  }
  for (int32_t i020 = 0; i020 < 784; ++i020) {
    for (int32_t i188 = 0; i188 < 128; ++i188) {
      ((int32_t*)out)[(((i020 * 128) + i188))] = ((int32_t*)compute1)[(((i020 * 128) + i188))];
    }
  }
  for (int32_t ax1139 = 0; ax1139 < 28; ++ax1139) {
    for (int32_t ax2118 = 0; ax2118 < 28; ++ax2118) {
      for (int32_t ax3118 = 0; ax3118 < 128; ++ax3118) {
        ((int32_t*)compute1)[((((ax1139 * 3584) + (ax2118 * 128)) + ax3118))] = ((int32_t*)out)[((((ax1139 * 3584) + (ax2118 * 128)) + ax3118))];
      }
    }
  }
  for (int32_t h171 = 0; h171 < 28; ++h171) {
    for (int32_t w87 = 0; w87 < 28; ++w87) {
      for (int32_t c102 = 0; c102 < 128; ++c102) {
        ((int32_t*)pad_data)[((((h171 * 3584) + (w87 * 128)) + c102))] = 11;
      }
    }
  }
  for (int32_t h172 = 0; h172 < 28; ++h172) {
    (void)load(compute1, (int64_t)537264128, 1792, (h172 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h172 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h172 * 14336));
  }
  for (int32_t h173 = 0; h173 < 28; ++h173) {
    for (int32_t w88 = 0; w88 < 28; ++w88) {
      for (int32_t c103 = 0; c103 < 128; ++c103) {
        ((int32_t*)compute1)[((((h173 * 3584) + (w88 * 128)) + c103))] = ((int32_t*)tensor_200)[(c103)];
      }
    }
  }
  for (int32_t h174 = 0; h174 < 28; ++h174) {
    (void)load(out1, (int64_t)537264128, 1792, (h174 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h174 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h174 * 14336));
  }
  for (int32_t h175 = 0; h175 < 28; ++h175) {
    for (int32_t w89 = 0; w89 < 28; ++w89) {
      for (int32_t c104 = 0; c104 < 128; ++c104) {
        ((int32_t*)compute1)[((((h175 * 3584) + (w89 * 128)) + c104))] = ((int32_t*)tensor_201)[(c104)];
      }
    }
  }
  for (int32_t h176 = 0; h176 < 28; ++h176) {
    (void)load(out, (int64_t)537264128, 1792, (h176 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h176 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h176 * 14336));
  }
  for (int32_t h177 = 0; h177 < 28; ++h177) {
    for (int32_t w90 = 0; w90 < 28; ++w90) {
      for (int32_t c105 = 0; c105 < 128; ++c105) {
        ((int32_t*)compute1)[((((h177 * 3584) + (w90 * 128)) + c105))] = 0;
      }
    }
  }
  for (int32_t h178 = 0; h178 < 28; ++h178) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h178 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h178 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h178 * 14336));
  }
  for (int32_t h179 = 0; h179 < 28; ++h179) {
    for (int32_t w91 = 0; w91 < 28; ++w91) {
      for (int32_t c106 = 0; c106 < 128; ++c106) {
        ((int32_t*)compute1)[((((h179 * 3584) + (w91 * 128)) + c106))] = 262144;
      }
    }
  }
  for (int32_t h180 = 0; h180 < 28; ++h180) {
    (void)load(out1, (int64_t)537264128, 1792, (h180 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h180 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h180 * 14336));
  }
  for (int32_t h181 = 0; h181 < 28; ++h181) {
    for (int32_t w92 = 0; w92 < 28; ++w92) {
      for (int32_t c107 = 0; c107 < 128; ++c107) {
        ((int32_t*)compute1)[((((h181 * 3584) + (w92 * 128)) + c107))] = 19;
      }
    }
  }
  for (int32_t h182 = 0; h182 < 28; ++h182) {
    (void)load(out, (int64_t)537264128, 1792, (h182 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h182 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h182 * 14336));
  }
  for (int32_t i189 = 0; i189 < 28; ++i189) {
    for (int32_t i268 = 0; i268 < 28; ++i268) {
      for (int32_t i368 = 0; i368 < 128; ++i368) {
        int32_t _54 = ((int32_t*)pad_data)[((((i189 * 3584) + (i268 * 128)) + i368))];
        int32_t _55 = (_54) < (127) ? (_54) : (127);
        ((int32_t*)compute1)[((((i189 * 3584) + (i268 * 128)) + i368))] = ((_55) > (-127) ? (_55) : (-127));
      }
    }
  }
  for (int32_t i190 = 0; i190 < 28; ++i190) {
    for (int32_t i269 = 0; i269 < 28; ++i269) {
      for (int32_t i369 = 0; i369 < 128; ++i369) {
        ((int8_t*)T_reshape1)[((((i190 * 3584) + (i269 * 128)) + i369))] = ((int8_t)((int32_t*)compute1)[((((i190 * 3584) + (i269 * 128)) + i369))]);
      }
    }
  }
  for (int32_t i191 = 0; i191 < 30; ++i191) {
    for (int32_t i270 = 0; i270 < 30; ++i270) {
      for (int32_t i370 = 0; i370 < 128; ++i370) {
        ((int8_t*)T_reshape)[((((i191 * 3840) + (i270 * 128)) + i370))] = (((((1 <= i191) && (i191 < 29)) && (1 <= i270)) && (i270 < 29)) ? ((int8_t*)T_reshape1)[(((((i191 * 3584) + (i270 * 128)) + i370) - 3712))] : (int8_t)0);
      }
    }
  }
  for (int32_t o114 = 0; o114 < 28; ++o114) {
    for (int32_t o214 = 0; o214 < 28; ++o214) {
      for (int32_t k14 = 0; k14 < 3; ++k14) {
        for (int32_t k24 = 0; k24 < 3; ++k24) {
          for (int32_t c108 = 0; c108 < 128; ++c108) {
            ((int8_t*)compute1)[((((((o114 * 32256) + (o214 * 1152)) + (k14 * 384)) + (k24 * 128)) + c108))] = ((int8_t*)T_reshape)[((((((k14 * 3840) + (o114 * 3840)) + (k24 * 128)) + (o214 * 128)) + c108))];
          }
        }
      }
    }
  }
  for (int32_t ax0136 = 0; ax0136 < 784; ++ax0136) {
    for (int32_t ax1140 = 0; ax1140 < 1152; ++ax1140) {
      ((int8_t*)out1)[(((ax0136 * 1152) + ax1140))] = ((int8_t*)compute1)[(((ax0136 * 1152) + ax1140))];
    }
  }
  for (int32_t i021 = 0; i021 < 784; ++i021) {
    for (int32_t i192 = 0; i192 < 1152; ++i192) {
      ((int8_t*)compute1)[(((i021 * 1152) + i192))] = ((int8_t*)out1)[(((i021 * 1152) + i192))];
    }
  }
  for (int32_t ax0137 = 0; ax0137 < 98; ++ax0137) {
    for (int32_t ax1141 = 0; ax1141 < 8; ++ax1141) {
      for (int32_t ax2119 = 0; ax2119 < 144; ++ax2119) {
        for (int32_t ax3119 = 0; ax3119 < 8; ++ax3119) {
          ((int8_t*)out)[(((((ax0137 * 9216) + (ax1141 * 1152)) + (ax2119 * 8)) + ax3119))] = ((int8_t*)compute1)[(((((ax0137 * 9216) + (ax1141 * 1152)) + (ax2119 * 8)) + ax3119))];
        }
      }
    }
  }
  for (int32_t ax0138 = 0; ax0138 < 98; ++ax0138) {
    for (int32_t ax1142 = 0; ax1142 < 144; ++ax1142) {
      for (int32_t ax2120 = 0; ax2120 < 8; ++ax2120) {
        for (int32_t ax3120 = 0; ax3120 < 8; ++ax3120) {
          ((int8_t*)compute1)[(((((ax0138 * 9216) + (ax1142 * 64)) + (ax2120 * 8)) + ax3120))] = ((int8_t*)out)[(((((ax0138 * 9216) + (ax2120 * 1152)) + (ax1142 * 8)) + ax3120))];
        }
      }
    }
  }
  for (int32_t ax0139 = 0; ax0139 < 98; ++ax0139) {
    for (int32_t ax1143 = 0; ax1143 < 2; ++ax1143) {
      for (int32_t ax2121 = 0; ax2121 < 72; ++ax2121) {
        for (int32_t ax3121 = 0; ax3121 < 8; ++ax3121) {
          for (int32_t ax421 = 0; ax421 < 8; ++ax421) {
            ((int8_t*)pad_data)[((((((ax0139 * 9216) + (ax1143 * 4608)) + (ax2121 * 64)) + (ax3121 * 8)) + ax421))] = ((int8_t*)compute1)[((((((ax0139 * 9216) + (ax1143 * 4608)) + (ax2121 * 64)) + (ax3121 * 8)) + ax421))];
          }
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 112896, 0);
  for (int32_t ax0140 = 0; ax0140 < 128; ++ax0140) {
    for (int32_t ax1144 = 0; ax1144 < 1152; ++ax1144) {
      ((int8_t*)T_reshape)[(((ax0140 * 1152) + ax1144))] = ((int8_t*)kernel_208)[(((ax0140 * 1152) + ax1144))];
    }
  }
  for (int32_t ax0141 = 0; ax0141 < 16; ++ax0141) {
    for (int32_t ax1145 = 0; ax1145 < 8; ++ax1145) {
      for (int32_t ax2122 = 0; ax2122 < 144; ++ax2122) {
        for (int32_t ax3122 = 0; ax3122 < 8; ++ax3122) {
          ((int8_t*)compute1)[(((((ax0141 * 9216) + (ax1145 * 1152)) + (ax2122 * 8)) + ax3122))] = ((int8_t*)T_reshape)[(((((ax0141 * 9216) + (ax1145 * 1152)) + (ax2122 * 8)) + ax3122))];
        }
      }
    }
  }
  for (int32_t ax0142 = 0; ax0142 < 16; ++ax0142) {
    for (int32_t ax1146 = 0; ax1146 < 144; ++ax1146) {
      for (int32_t ax2123 = 0; ax2123 < 8; ++ax2123) {
        for (int32_t ax3123 = 0; ax3123 < 8; ++ax3123) {
          ((int8_t*)T_reshape)[(((((ax0142 * 9216) + (ax1146 * 64)) + (ax2123 * 8)) + ax3123))] = ((int8_t*)compute1)[(((((ax0142 * 9216) + (ax2123 * 1152)) + (ax1146 * 8)) + ax3123))];
        }
      }
    }
  }
  for (int32_t ax0143 = 0; ax0143 < 16; ++ax0143) {
    for (int32_t ax1147 = 0; ax1147 < 2; ++ax1147) {
      for (int32_t ax2124 = 0; ax2124 < 72; ++ax2124) {
        for (int32_t ax3124 = 0; ax3124 < 8; ++ax3124) {
          for (int32_t ax422 = 0; ax422 < 8; ++ax422) {
            ((int8_t*)compute1)[((((((ax0143 * 9216) + (ax1147 * 4608)) + (ax2124 * 64)) + (ax3124 * 8)) + ax422))] = ((int8_t*)T_reshape)[((((((ax0143 * 9216) + (ax1147 * 4608)) + (ax2124 * 64)) + (ax3124 * 8)) + ax422))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536936448, 18432, 0);
  for (int32_t i46 = 0; i46 < 98; ++i46) {
    for (int32_t x15 = 0; x15 < 16; ++x15) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k01 = 0; k01 < 2; ++k01) {
        (void)move(((((int64_t)((i46 * 576) + (k01 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x15 * 576) + (k01 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute1, (int64_t)537264128, 32, ((i46 * 4096) + (x15 * 256)));
    }
  }
  for (int32_t ax0144 = 0; ax0144 < 98; ++ax0144) {
    for (int32_t ax1148 = 0; ax1148 < 8; ++ax1148) {
      for (int32_t ax2125 = 0; ax2125 < 16; ++ax2125) {
        for (int32_t ax3125 = 0; ax3125 < 8; ++ax3125) {
          ((int32_t*)out1)[(((((ax0144 * 1024) + (ax1148 * 128)) + (ax2125 * 8)) + ax3125))] = ((int32_t*)compute1)[(((((ax0144 * 1024) + (ax2125 * 64)) + (ax1148 * 8)) + ax3125))];
        }
      }
    }
  }
  for (int32_t ax0145 = 0; ax0145 < 784; ++ax0145) {
    for (int32_t ax1149 = 0; ax1149 < 128; ++ax1149) {
      ((int32_t*)compute1)[(((ax0145 * 128) + ax1149))] = ((int32_t*)out1)[(((ax0145 * 128) + ax1149))];
    }
  }
  for (int32_t i022 = 0; i022 < 784; ++i022) {
    for (int32_t i193 = 0; i193 < 128; ++i193) {
      ((int32_t*)out)[(((i022 * 128) + i193))] = ((int32_t*)compute1)[(((i022 * 128) + i193))];
    }
  }
  for (int32_t ax1150 = 0; ax1150 < 28; ++ax1150) {
    for (int32_t ax2126 = 0; ax2126 < 28; ++ax2126) {
      for (int32_t ax3126 = 0; ax3126 < 128; ++ax3126) {
        ((int32_t*)compute1)[((((ax1150 * 3584) + (ax2126 * 128)) + ax3126))] = ((int32_t*)out)[((((ax1150 * 3584) + (ax2126 * 128)) + ax3126))];
      }
    }
  }
  for (int32_t h183 = 0; h183 < 28; ++h183) {
    for (int32_t w93 = 0; w93 < 28; ++w93) {
      for (int32_t c109 = 0; c109 < 128; ++c109) {
        ((int32_t*)pad_data)[((((h183 * 3584) + (w93 * 128)) + c109))] = ((int32_t*)tensor_209)[(c109)];
      }
    }
  }
  for (int32_t h184 = 0; h184 < 28; ++h184) {
    (void)load(compute1, (int64_t)537264128, 1792, (h184 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h184 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h184 * 14336));
  }
  for (int32_t h185 = 0; h185 < 28; ++h185) {
    for (int32_t w94 = 0; w94 < 28; ++w94) {
      for (int32_t c110 = 0; c110 < 128; ++c110) {
        ((int32_t*)compute1)[((((h185 * 3584) + (w94 * 128)) + c110))] = 0;
      }
    }
  }
  for (int32_t h186 = 0; h186 < 28; ++h186) {
    (void)load(out1, (int64_t)537264128, 1792, (h186 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h186 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h186 * 14336));
  }
  for (int32_t h187 = 0; h187 < 28; ++h187) {
    for (int32_t w95 = 0; w95 < 28; ++w95) {
      for (int32_t c111 = 0; c111 < 128; ++c111) {
        ((int32_t*)compute1)[((((h187 * 3584) + (w95 * 128)) + c111))] = 64;
      }
    }
  }
  for (int32_t h188 = 0; h188 < 28; ++h188) {
    (void)load(out, (int64_t)537264128, 1792, (h188 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h188 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h188 * 14336));
  }
  for (int32_t h189 = 0; h189 < 28; ++h189) {
    for (int32_t w96 = 0; w96 < 28; ++w96) {
      for (int32_t c112 = 0; c112 < 128; ++c112) {
        ((int32_t*)compute1)[((((h189 * 3584) + (w96 * 128)) + c112))] = 7;
      }
    }
  }
  for (int32_t h190 = 0; h190 < 28; ++h190) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h190 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h190 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h190 * 14336));
  }
  for (int32_t i194 = 0; i194 < 28; ++i194) {
    for (int32_t i271 = 0; i271 < 28; ++i271) {
      for (int32_t i371 = 0; i371 < 128; ++i371) {
        int32_t _56 = ((int32_t*)out1)[((((i194 * 3584) + (i271 * 128)) + i371))];
        int32_t _57 = (_56) < (127) ? (_56) : (127);
        ((int32_t*)compute1)[((((i194 * 3584) + (i271 * 128)) + i371))] = ((_57) > (-127) ? (_57) : (-127));
      }
    }
  }
  for (int32_t i195 = 0; i195 < 28; ++i195) {
    for (int32_t i272 = 0; i272 < 28; ++i272) {
      for (int32_t i372 = 0; i372 < 128; ++i372) {
        ((int8_t*)T_reshape1)[((((i195 * 3584) + (i272 * 128)) + i372))] = ((int8_t)((int32_t*)compute1)[((((i195 * 3584) + (i272 * 128)) + i372))]);
      }
    }
  }
  for (int32_t ax0146 = 0; ax0146 < 98; ++ax0146) {
    for (int32_t ax1151 = 0; ax1151 < 8; ++ax1151) {
      for (int32_t ax2127 = 0; ax2127 < 16; ++ax2127) {
        for (int32_t ax3127 = 0; ax3127 < 8; ++ax3127) {
          ((int8_t*)T_reshape)[(((((ax0146 * 1024) + (ax1151 * 128)) + (ax2127 * 8)) + ax3127))] = ((int8_t*)T_reshape1)[(((((ax0146 * 1024) + (ax1151 * 128)) + (ax2127 * 8)) + ax3127))];
        }
      }
    }
  }
  for (int32_t ax0147 = 0; ax0147 < 98; ++ax0147) {
    for (int32_t ax1152 = 0; ax1152 < 16; ++ax1152) {
      for (int32_t ax2128 = 0; ax2128 < 8; ++ax2128) {
        for (int32_t ax3128 = 0; ax3128 < 8; ++ax3128) {
          ((int8_t*)T_reshape1)[(((((ax0147 * 1024) + (ax1152 * 64)) + (ax2128 * 8)) + ax3128))] = ((int8_t*)T_reshape)[(((((ax0147 * 1024) + (ax2128 * 128)) + (ax1152 * 8)) + ax3128))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 12544, 0);
  for (int32_t ax0148 = 0; ax0148 < 512; ++ax0148) {
    for (int32_t ax1153 = 0; ax1153 < 128; ++ax1153) {
      ((int8_t*)T_reshape1)[(((ax0148 * 128) + ax1153))] = ((int8_t*)kernel_216)[(((ax0148 * 128) + ax1153))];
    }
  }
  for (int32_t ax0149 = 0; ax0149 < 64; ++ax0149) {
    for (int32_t ax1154 = 0; ax1154 < 8; ++ax1154) {
      for (int32_t ax2129 = 0; ax2129 < 16; ++ax2129) {
        for (int32_t ax3129 = 0; ax3129 < 8; ++ax3129) {
          ((int8_t*)T_reshape)[(((((ax0149 * 1024) + (ax1154 * 128)) + (ax2129 * 8)) + ax3129))] = ((int8_t*)T_reshape1)[(((((ax0149 * 1024) + (ax1154 * 128)) + (ax2129 * 8)) + ax3129))];
        }
      }
    }
  }
  for (int32_t ax0150 = 0; ax0150 < 64; ++ax0150) {
    for (int32_t ax1155 = 0; ax1155 < 16; ++ax1155) {
      for (int32_t ax2130 = 0; ax2130 < 8; ++ax2130) {
        for (int32_t ax3130 = 0; ax3130 < 8; ++ax3130) {
          ((int8_t*)T_reshape1)[(((((ax0150 * 1024) + (ax1155 * 64)) + (ax2130 * 8)) + ax3130))] = ((int8_t*)T_reshape)[(((((ax0150 * 1024) + (ax2130 * 128)) + (ax1155 * 8)) + ax3130))];
        }
      }
    }
  }
  for (int32_t ax0151 = 0; ax0151 < 64; ++ax0151) {
    for (int32_t ax2131 = 0; ax2131 < 16; ++ax2131) {
      for (int32_t ax3131 = 0; ax3131 < 8; ++ax3131) {
        for (int32_t ax423 = 0; ax423 < 8; ++ax423) {
          ((int8_t*)T_reshape)[(((((ax0151 * 1024) + (ax2131 * 64)) + (ax3131 * 8)) + ax423))] = ((int8_t*)T_reshape1)[(((((ax0151 * 1024) + (ax2131 * 64)) + (ax3131 * 8)) + ax423))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i47 = 0; i47 < 98; ++i47) {
    for (int32_t x16 = 0; x16 < 64; ++x16) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i47 * 64) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 128, 0);
      (void)move(((((int64_t)(x16 * 64)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 128, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 16, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i47 * 16384) + (x16 * 256)));
    }
  }
  for (int32_t ax0152 = 0; ax0152 < 98; ++ax0152) {
    for (int32_t ax1156 = 0; ax1156 < 8; ++ax1156) {
      for (int32_t ax2132 = 0; ax2132 < 64; ++ax2132) {
        for (int32_t ax3132 = 0; ax3132 < 8; ++ax3132) {
          ((int32_t*)out)[(((((ax0152 * 4096) + (ax1156 * 512)) + (ax2132 * 8)) + ax3132))] = ((int32_t*)compute1)[(((((ax0152 * 4096) + (ax2132 * 64)) + (ax1156 * 8)) + ax3132))];
        }
      }
    }
  }
  for (int32_t ax0153 = 0; ax0153 < 784; ++ax0153) {
    for (int32_t ax1157 = 0; ax1157 < 512; ++ax1157) {
      ((int32_t*)compute1)[(((ax0153 * 512) + ax1157))] = ((int32_t*)out)[(((ax0153 * 512) + ax1157))];
    }
  }
  for (int32_t i023 = 0; i023 < 784; ++i023) {
    for (int32_t i196 = 0; i196 < 512; ++i196) {
      ((int32_t*)pad_data)[(((i023 * 512) + i196))] = ((int32_t*)compute1)[(((i023 * 512) + i196))];
    }
  }
  for (int32_t ax1158 = 0; ax1158 < 28; ++ax1158) {
    for (int32_t ax2133 = 0; ax2133 < 28; ++ax2133) {
      for (int32_t ax3133 = 0; ax3133 < 512; ++ax3133) {
        ((int32_t*)compute1)[((((ax1158 * 14336) + (ax2133 * 512)) + ax3133))] = ((int32_t*)pad_data)[((((ax1158 * 14336) + (ax2133 * 512)) + ax3133))];
      }
    }
  }
  for (int32_t h191 = 0; h191 < 28; ++h191) {
    for (int32_t w97 = 0; w97 < 28; ++w97) {
      for (int32_t c113 = 0; c113 < 512; ++c113) {
        ((int32_t*)out1)[((((h191 * 14336) + (w97 * 512)) + c113))] = 10;
      }
    }
  }
  for (int32_t h192 = 0; h192 < 28; ++h192) {
    (void)load(compute1, (int64_t)537264128, 7168, (h192 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h192 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h192 * 57344));
  }
  for (int32_t h193 = 0; h193 < 28; ++h193) {
    for (int32_t w98 = 0; w98 < 28; ++w98) {
      for (int32_t c114 = 0; c114 < 512; ++c114) {
        ((int32_t*)compute1)[((((h193 * 14336) + (w98 * 512)) + c114))] = ((int32_t*)tensor_218)[(c114)];
      }
    }
  }
  for (int32_t h194 = 0; h194 < 28; ++h194) {
    (void)load(out, (int64_t)537264128, 7168, (h194 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h194 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h194 * 57344));
  }
  for (int32_t h195 = 0; h195 < 28; ++h195) {
    for (int32_t w99 = 0; w99 < 28; ++w99) {
      for (int32_t c115 = 0; c115 < 512; ++c115) {
        ((int32_t*)compute1)[((((h195 * 14336) + (w99 * 512)) + c115))] = 131072;
      }
    }
  }
  for (int32_t h196 = 0; h196 < 28; ++h196) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h196 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h196 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h196 * 57344));
  }
  for (int32_t h197 = 0; h197 < 28; ++h197) {
    for (int32_t w100 = 0; w100 < 28; ++w100) {
      for (int32_t c116 = 0; c116 < 512; ++c116) {
        ((int32_t*)compute1)[((((h197 * 14336) + (w100 * 512)) + c116))] = 18;
      }
    }
  }
  for (int32_t h198 = 0; h198 < 28; ++h198) {
    (void)load(out1, (int64_t)537264128, 7168, (h198 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h198 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h198 * 57344));
  }
  for (int32_t i197 = 0; i197 < 28; ++i197) {
    for (int32_t i273 = 0; i273 < 28; ++i273) {
      for (int32_t i373 = 0; i373 < 512; ++i373) {
        int32_t _58 = ((int32_t*)out)[((((i197 * 14336) + (i273 * 512)) + i373))];
        int32_t _59 = (_58) < (127) ? (_58) : (127);
        ((int32_t*)compute1)[((((i197 * 14336) + (i273 * 512)) + i373))] = ((_59) > (-127) ? (_59) : (-127));
      }
    }
  }
  for (int32_t i198 = 0; i198 < 28; ++i198) {
    for (int32_t i274 = 0; i274 < 28; ++i274) {
      for (int32_t i374 = 0; i374 < 512; ++i374) {
        ((int8_t*)pad_data)[((((i198 * 14336) + (i274 * 512)) + i374))] = ((int8_t)((int32_t*)compute1)[((((i198 * 14336) + (i274 * 512)) + i374))]);
      }
    }
  }
  for (int32_t i199 = 0; i199 < 28; ++i199) {
    for (int32_t i275 = 0; i275 < 28; ++i275) {
      for (int32_t i375 = 0; i375 < 512; ++i375) {
        ((int32_t*)compute1)[((((i199 * 14336) + (i275 * 512)) + i375))] = ((int32_t)((int8_t*)pad_data)[((((i199 * 14336) + (i275 * 512)) + i375))]);
      }
    }
  }
  for (int32_t h199 = 0; h199 < 28; ++h199) {
    for (int32_t w101 = 0; w101 < 28; ++w101) {
      for (int32_t c117 = 0; c117 < 512; ++c117) {
        ((int32_t*)out1)[((((h199 * 14336) + (w101 * 512)) + c117))] = ((int32_t*)tensor_225)[(c117)];
      }
    }
  }
  for (int32_t h200 = 0; h200 < 28; ++h200) {
    (void)load(compute1, (int64_t)537264128, 7168, (h200 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h200 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h200 * 57344));
  }
  for (int32_t h201 = 0; h201 < 28; ++h201) {
    for (int32_t w102 = 0; w102 < 28; ++w102) {
      for (int32_t c118 = 0; c118 < 512; ++c118) {
        ((int32_t*)compute1)[((((h201 * 14336) + (w102 * 512)) + c118))] = ((int32_t*)tensor_226)[(c118)];
      }
    }
  }
  for (int32_t h202 = 0; h202 < 28; ++h202) {
    (void)load(out, (int64_t)537264128, 7168, (h202 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h202 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h202 * 57344));
  }
  for (int32_t h203 = 0; h203 < 28; ++h203) {
    for (int32_t w103 = 0; w103 < 28; ++w103) {
      for (int32_t c119 = 0; c119 < 512; ++c119) {
        ((int32_t*)compute1)[((((h203 * 14336) + (w103 * 512)) + c119))] = 8;
      }
    }
  }
  for (int32_t h204 = 0; h204 < 28; ++h204) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h204 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h204 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h204 * 57344));
  }
  for (int32_t h205 = 0; h205 < 28; ++h205) {
    for (int32_t w104 = 0; w104 < 28; ++w104) {
      for (int32_t c120 = 0; c120 < 512; ++c120) {
        ((int32_t*)compute1)[((((h205 * 14336) + (w104 * 512)) + c120))] = 4;
      }
    }
  }
  for (int32_t h206 = 0; h206 < 28; ++h206) {
    (void)load(out1, (int64_t)537264128, 7168, (h206 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h206 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h206 * 57344));
  }
  for (int32_t i1100 = 0; i1100 < 28; ++i1100) {
    for (int32_t i276 = 0; i276 < 28; ++i276) {
      for (int32_t i376 = 0; i376 < 512; ++i376) {
        int32_t _60 = ((int32_t*)out)[((((i1100 * 14336) + (i276 * 512)) + i376))];
        int32_t _61 = (_60) < (127) ? (_60) : (127);
        ((int32_t*)compute1)[((((i1100 * 14336) + (i276 * 512)) + i376))] = ((_61) > (-127) ? (_61) : (-127));
      }
    }
  }
  for (int32_t i1101 = 0; i1101 < 28; ++i1101) {
    for (int32_t i277 = 0; i277 < 28; ++i277) {
      for (int32_t i377 = 0; i377 < 512; ++i377) {
        ((int8_t*)pad_data)[((((i1101 * 14336) + (i277 * 512)) + i377))] = ((int8_t)((int32_t*)compute1)[((((i1101 * 14336) + (i277 * 512)) + i377))]);
      }
    }
  }
  for (int32_t i1102 = 0; i1102 < 28; ++i1102) {
    for (int32_t i278 = 0; i278 < 28; ++i278) {
      for (int32_t i378 = 0; i378 < 512; ++i378) {
        ((int32_t*)compute1)[((((i1102 * 14336) + (i278 * 512)) + i378))] = ((int32_t)((int8_t*)pad_data)[((((i1102 * 14336) + (i278 * 512)) + i378))]);
      }
    }
  }
  for (int32_t i1103 = 0; i1103 < 28; ++i1103) {
    for (int32_t i279 = 0; i279 < 28; ++i279) {
      for (int32_t i379 = 0; i379 < 512; ++i379) {
        ((int32_t*)out1)[((((i1103 * 14336) + (i279 * 512)) + i379))] = ((int32_t)((int8_t*)compute)[((((i1103 * 14336) + (i279 * 512)) + i379))]);
      }
    }
  }
  for (int32_t h207 = 0; h207 < 28; ++h207) {
    (void)load(compute1, (int64_t)537264128, 7168, (h207 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h207 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h207 * 57344));
  }
  for (int32_t h208 = 0; h208 < 28; ++h208) {
    for (int32_t w105 = 0; w105 < 28; ++w105) {
      for (int32_t c121 = 0; c121 < 512; ++c121) {
        ((int32_t*)compute1)[((((h208 * 14336) + (w105 * 512)) + c121))] = 0;
      }
    }
  }
  for (int32_t h209 = 0; h209 < 28; ++h209) {
    (void)load(out, (int64_t)537264128, 7168, (h209 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h209 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h209 * 57344));
  }
  for (int32_t i1104 = 0; i1104 < 28; ++i1104) {
    for (int32_t i280 = 0; i280 < 28; ++i280) {
      for (int32_t i380 = 0; i380 < 512; ++i380) {
        int32_t _62 = ((int32_t*)pad_data)[((((i1104 * 14336) + (i280 * 512)) + i380))];
        int32_t _63 = (_62) < (127) ? (_62) : (127);
        ((int32_t*)compute1)[((((i1104 * 14336) + (i280 * 512)) + i380))] = ((_63) > (-127) ? (_63) : (-127));
      }
    }
  }
  for (int32_t i1105 = 0; i1105 < 28; ++i1105) {
    for (int32_t i281 = 0; i281 < 28; ++i281) {
      for (int32_t i381 = 0; i381 < 512; ++i381) {
        ((int8_t*)compute)[((((i1105 * 14336) + (i281 * 512)) + i381))] = ((int8_t)((int32_t*)compute1)[((((i1105 * 14336) + (i281 * 512)) + i381))]);
      }
    }
  }
  for (int32_t o115 = 0; o115 < 28; ++o115) {
    for (int32_t o215 = 0; o215 < 28; ++o215) {
      for (int32_t c122 = 0; c122 < 512; ++c122) {
        ((int8_t*)compute1)[((((o115 * 14336) + (o215 * 512)) + c122))] = ((int8_t*)compute)[((((o115 * 14336) + (o215 * 512)) + c122))];
      }
    }
  }
  for (int32_t ax0154 = 0; ax0154 < 784; ++ax0154) {
    for (int32_t ax1159 = 0; ax1159 < 512; ++ax1159) {
      ((int8_t*)out1)[(((ax0154 * 512) + ax1159))] = ((int8_t*)compute1)[(((ax0154 * 512) + ax1159))];
    }
  }
  for (int32_t i024 = 0; i024 < 784; ++i024) {
    for (int32_t i1106 = 0; i1106 < 512; ++i1106) {
      ((int8_t*)compute1)[(((i024 * 512) + i1106))] = ((int8_t*)out1)[(((i024 * 512) + i1106))];
    }
  }
  for (int32_t ax0155 = 0; ax0155 < 98; ++ax0155) {
    for (int32_t ax1160 = 0; ax1160 < 8; ++ax1160) {
      for (int32_t ax2134 = 0; ax2134 < 64; ++ax2134) {
        for (int32_t ax3134 = 0; ax3134 < 8; ++ax3134) {
          ((int8_t*)out)[(((((ax0155 * 4096) + (ax1160 * 512)) + (ax2134 * 8)) + ax3134))] = ((int8_t*)compute1)[(((((ax0155 * 4096) + (ax1160 * 512)) + (ax2134 * 8)) + ax3134))];
        }
      }
    }
  }
  for (int32_t ax0156 = 0; ax0156 < 98; ++ax0156) {
    for (int32_t ax1161 = 0; ax1161 < 64; ++ax1161) {
      for (int32_t ax2135 = 0; ax2135 < 8; ++ax2135) {
        for (int32_t ax3135 = 0; ax3135 < 8; ++ax3135) {
          ((int8_t*)compute1)[(((((ax0156 * 4096) + (ax1161 * 64)) + (ax2135 * 8)) + ax3135))] = ((int8_t*)out)[(((((ax0156 * 4096) + (ax2135 * 512)) + (ax1161 * 8)) + ax3135))];
        }
      }
    }
  }
  for (int32_t ax0157 = 0; ax0157 < 98; ++ax0157) {
    for (int32_t ax2136 = 0; ax2136 < 64; ++ax2136) {
      for (int32_t ax3136 = 0; ax3136 < 8; ++ax3136) {
        for (int32_t ax424 = 0; ax424 < 8; ++ax424) {
          ((int8_t*)pad_data)[(((((ax0157 * 4096) + (ax2136 * 64)) + (ax3136 * 8)) + ax424))] = ((int8_t*)compute1)[(((((ax0157 * 4096) + (ax2136 * 64)) + (ax3136 * 8)) + ax424))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 50176, 0);
  for (int32_t ax0158 = 0; ax0158 < 128; ++ax0158) {
    for (int32_t ax1162 = 0; ax1162 < 512; ++ax1162) {
      ((int8_t*)T_reshape1)[(((ax0158 * 512) + ax1162))] = ((int8_t*)kernel_241)[(((ax0158 * 512) + ax1162))];
    }
  }
  for (int32_t ax0159 = 0; ax0159 < 16; ++ax0159) {
    for (int32_t ax1163 = 0; ax1163 < 8; ++ax1163) {
      for (int32_t ax2137 = 0; ax2137 < 64; ++ax2137) {
        for (int32_t ax3137 = 0; ax3137 < 8; ++ax3137) {
          ((int8_t*)T_reshape)[(((((ax0159 * 4096) + (ax1163 * 512)) + (ax2137 * 8)) + ax3137))] = ((int8_t*)T_reshape1)[(((((ax0159 * 4096) + (ax1163 * 512)) + (ax2137 * 8)) + ax3137))];
        }
      }
    }
  }
  for (int32_t ax0160 = 0; ax0160 < 16; ++ax0160) {
    for (int32_t ax1164 = 0; ax1164 < 64; ++ax1164) {
      for (int32_t ax2138 = 0; ax2138 < 8; ++ax2138) {
        for (int32_t ax3138 = 0; ax3138 < 8; ++ax3138) {
          ((int8_t*)T_reshape1)[(((((ax0160 * 4096) + (ax1164 * 64)) + (ax2138 * 8)) + ax3138))] = ((int8_t*)T_reshape)[(((((ax0160 * 4096) + (ax2138 * 512)) + (ax1164 * 8)) + ax3138))];
        }
      }
    }
  }
  for (int32_t ax0161 = 0; ax0161 < 16; ++ax0161) {
    for (int32_t ax2139 = 0; ax2139 < 64; ++ax2139) {
      for (int32_t ax3139 = 0; ax3139 < 8; ++ax3139) {
        for (int32_t ax425 = 0; ax425 < 8; ++ax425) {
          ((int8_t*)T_reshape)[(((((ax0161 * 4096) + (ax2139 * 64)) + (ax3139 * 8)) + ax425))] = ((int8_t*)T_reshape1)[(((((ax0161 * 4096) + (ax2139 * 64)) + (ax3139 * 8)) + ax425))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i48 = 0; i48 < 98; ++i48) {
    for (int32_t x17 = 0; x17 < 16; ++x17) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i48 * 256)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x17 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i48 * 4096) + (x17 * 256)));
    }
  }
  for (int32_t ax0162 = 0; ax0162 < 98; ++ax0162) {
    for (int32_t ax1165 = 0; ax1165 < 8; ++ax1165) {
      for (int32_t ax2140 = 0; ax2140 < 16; ++ax2140) {
        for (int32_t ax3140 = 0; ax3140 < 8; ++ax3140) {
          ((int32_t*)out1)[(((((ax0162 * 1024) + (ax1165 * 128)) + (ax2140 * 8)) + ax3140))] = ((int32_t*)compute1)[(((((ax0162 * 1024) + (ax2140 * 64)) + (ax1165 * 8)) + ax3140))];
        }
      }
    }
  }
  for (int32_t ax0163 = 0; ax0163 < 784; ++ax0163) {
    for (int32_t ax1166 = 0; ax1166 < 128; ++ax1166) {
      ((int32_t*)compute1)[(((ax0163 * 128) + ax1166))] = ((int32_t*)out1)[(((ax0163 * 128) + ax1166))];
    }
  }
  for (int32_t i025 = 0; i025 < 784; ++i025) {
    for (int32_t i1107 = 0; i1107 < 128; ++i1107) {
      ((int32_t*)out)[(((i025 * 128) + i1107))] = ((int32_t*)compute1)[(((i025 * 128) + i1107))];
    }
  }
  for (int32_t ax1167 = 0; ax1167 < 28; ++ax1167) {
    for (int32_t ax2141 = 0; ax2141 < 28; ++ax2141) {
      for (int32_t ax3141 = 0; ax3141 < 128; ++ax3141) {
        ((int32_t*)compute1)[((((ax1167 * 3584) + (ax2141 * 128)) + ax3141))] = ((int32_t*)out)[((((ax1167 * 3584) + (ax2141 * 128)) + ax3141))];
      }
    }
  }
  for (int32_t h210 = 0; h210 < 28; ++h210) {
    for (int32_t w106 = 0; w106 < 28; ++w106) {
      for (int32_t c123 = 0; c123 < 128; ++c123) {
        ((int32_t*)pad_data)[((((h210 * 3584) + (w106 * 128)) + c123))] = 11;
      }
    }
  }
  for (int32_t h211 = 0; h211 < 28; ++h211) {
    (void)load(compute1, (int64_t)537264128, 1792, (h211 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h211 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h211 * 14336));
  }
  for (int32_t h212 = 0; h212 < 28; ++h212) {
    for (int32_t w107 = 0; w107 < 28; ++w107) {
      for (int32_t c124 = 0; c124 < 128; ++c124) {
        ((int32_t*)compute1)[((((h212 * 3584) + (w107 * 128)) + c124))] = ((int32_t*)tensor_243)[(c124)];
      }
    }
  }
  for (int32_t h213 = 0; h213 < 28; ++h213) {
    (void)load(out1, (int64_t)537264128, 1792, (h213 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h213 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h213 * 14336));
  }
  for (int32_t h214 = 0; h214 < 28; ++h214) {
    for (int32_t w108 = 0; w108 < 28; ++w108) {
      for (int32_t c125 = 0; c125 < 128; ++c125) {
        ((int32_t*)compute1)[((((h214 * 3584) + (w108 * 128)) + c125))] = ((int32_t*)tensor_244)[(c125)];
      }
    }
  }
  for (int32_t h215 = 0; h215 < 28; ++h215) {
    (void)load(out, (int64_t)537264128, 1792, (h215 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h215 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h215 * 14336));
  }
  for (int32_t h216 = 0; h216 < 28; ++h216) {
    for (int32_t w109 = 0; w109 < 28; ++w109) {
      for (int32_t c126 = 0; c126 < 128; ++c126) {
        ((int32_t*)compute1)[((((h216 * 3584) + (w109 * 128)) + c126))] = 0;
      }
    }
  }
  for (int32_t h217 = 0; h217 < 28; ++h217) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h217 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h217 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h217 * 14336));
  }
  for (int32_t h218 = 0; h218 < 28; ++h218) {
    for (int32_t w110 = 0; w110 < 28; ++w110) {
      for (int32_t c127 = 0; c127 < 128; ++c127) {
        ((int32_t*)compute1)[((((h218 * 3584) + (w110 * 128)) + c127))] = 262144;
      }
    }
  }
  for (int32_t h219 = 0; h219 < 28; ++h219) {
    (void)load(out1, (int64_t)537264128, 1792, (h219 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h219 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h219 * 14336));
  }
  for (int32_t h220 = 0; h220 < 28; ++h220) {
    for (int32_t w111 = 0; w111 < 28; ++w111) {
      for (int32_t c128 = 0; c128 < 128; ++c128) {
        ((int32_t*)compute1)[((((h220 * 3584) + (w111 * 128)) + c128))] = 19;
      }
    }
  }
  for (int32_t h221 = 0; h221 < 28; ++h221) {
    (void)load(out, (int64_t)537264128, 1792, (h221 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h221 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h221 * 14336));
  }
  for (int32_t i1108 = 0; i1108 < 28; ++i1108) {
    for (int32_t i282 = 0; i282 < 28; ++i282) {
      for (int32_t i382 = 0; i382 < 128; ++i382) {
        int32_t _64 = ((int32_t*)pad_data)[((((i1108 * 3584) + (i282 * 128)) + i382))];
        int32_t _65 = (_64) < (127) ? (_64) : (127);
        ((int32_t*)compute1)[((((i1108 * 3584) + (i282 * 128)) + i382))] = ((_65) > (-127) ? (_65) : (-127));
      }
    }
  }
  for (int32_t i1109 = 0; i1109 < 28; ++i1109) {
    for (int32_t i283 = 0; i283 < 28; ++i283) {
      for (int32_t i383 = 0; i383 < 128; ++i383) {
        ((int8_t*)T_reshape1)[((((i1109 * 3584) + (i283 * 128)) + i383))] = ((int8_t)((int32_t*)compute1)[((((i1109 * 3584) + (i283 * 128)) + i383))]);
      }
    }
  }
  for (int32_t i1110 = 0; i1110 < 30; ++i1110) {
    for (int32_t i284 = 0; i284 < 30; ++i284) {
      for (int32_t i384 = 0; i384 < 128; ++i384) {
        ((int8_t*)T_reshape)[((((i1110 * 3840) + (i284 * 128)) + i384))] = (((((1 <= i1110) && (i1110 < 29)) && (1 <= i284)) && (i284 < 29)) ? ((int8_t*)T_reshape1)[(((((i1110 * 3584) + (i284 * 128)) + i384) - 3712))] : (int8_t)0);
      }
    }
  }
  for (int32_t o116 = 0; o116 < 28; ++o116) {
    for (int32_t o216 = 0; o216 < 28; ++o216) {
      for (int32_t k15 = 0; k15 < 3; ++k15) {
        for (int32_t k25 = 0; k25 < 3; ++k25) {
          for (int32_t c129 = 0; c129 < 128; ++c129) {
            ((int8_t*)compute1)[((((((o116 * 32256) + (o216 * 1152)) + (k15 * 384)) + (k25 * 128)) + c129))] = ((int8_t*)T_reshape)[((((((k15 * 3840) + (o116 * 3840)) + (k25 * 128)) + (o216 * 128)) + c129))];
          }
        }
      }
    }
  }
  for (int32_t ax0164 = 0; ax0164 < 784; ++ax0164) {
    for (int32_t ax1168 = 0; ax1168 < 1152; ++ax1168) {
      ((int8_t*)out1)[(((ax0164 * 1152) + ax1168))] = ((int8_t*)compute1)[(((ax0164 * 1152) + ax1168))];
    }
  }
  for (int32_t i026 = 0; i026 < 784; ++i026) {
    for (int32_t i1111 = 0; i1111 < 1152; ++i1111) {
      ((int8_t*)compute1)[(((i026 * 1152) + i1111))] = ((int8_t*)out1)[(((i026 * 1152) + i1111))];
    }
  }
  for (int32_t ax0165 = 0; ax0165 < 98; ++ax0165) {
    for (int32_t ax1169 = 0; ax1169 < 8; ++ax1169) {
      for (int32_t ax2142 = 0; ax2142 < 144; ++ax2142) {
        for (int32_t ax3142 = 0; ax3142 < 8; ++ax3142) {
          ((int8_t*)out)[(((((ax0165 * 9216) + (ax1169 * 1152)) + (ax2142 * 8)) + ax3142))] = ((int8_t*)compute1)[(((((ax0165 * 9216) + (ax1169 * 1152)) + (ax2142 * 8)) + ax3142))];
        }
      }
    }
  }
  for (int32_t ax0166 = 0; ax0166 < 98; ++ax0166) {
    for (int32_t ax1170 = 0; ax1170 < 144; ++ax1170) {
      for (int32_t ax2143 = 0; ax2143 < 8; ++ax2143) {
        for (int32_t ax3143 = 0; ax3143 < 8; ++ax3143) {
          ((int8_t*)compute1)[(((((ax0166 * 9216) + (ax1170 * 64)) + (ax2143 * 8)) + ax3143))] = ((int8_t*)out)[(((((ax0166 * 9216) + (ax2143 * 1152)) + (ax1170 * 8)) + ax3143))];
        }
      }
    }
  }
  for (int32_t ax0167 = 0; ax0167 < 98; ++ax0167) {
    for (int32_t ax1171 = 0; ax1171 < 2; ++ax1171) {
      for (int32_t ax2144 = 0; ax2144 < 72; ++ax2144) {
        for (int32_t ax3144 = 0; ax3144 < 8; ++ax3144) {
          for (int32_t ax426 = 0; ax426 < 8; ++ax426) {
            ((int8_t*)pad_data)[((((((ax0167 * 9216) + (ax1171 * 4608)) + (ax2144 * 64)) + (ax3144 * 8)) + ax426))] = ((int8_t*)compute1)[((((((ax0167 * 9216) + (ax1171 * 4608)) + (ax2144 * 64)) + (ax3144 * 8)) + ax426))];
          }
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 112896, 0);
  for (int32_t ax0168 = 0; ax0168 < 128; ++ax0168) {
    for (int32_t ax1172 = 0; ax1172 < 1152; ++ax1172) {
      ((int8_t*)T_reshape)[(((ax0168 * 1152) + ax1172))] = ((int8_t*)kernel_251)[(((ax0168 * 1152) + ax1172))];
    }
  }
  for (int32_t ax0169 = 0; ax0169 < 16; ++ax0169) {
    for (int32_t ax1173 = 0; ax1173 < 8; ++ax1173) {
      for (int32_t ax2145 = 0; ax2145 < 144; ++ax2145) {
        for (int32_t ax3145 = 0; ax3145 < 8; ++ax3145) {
          ((int8_t*)compute1)[(((((ax0169 * 9216) + (ax1173 * 1152)) + (ax2145 * 8)) + ax3145))] = ((int8_t*)T_reshape)[(((((ax0169 * 9216) + (ax1173 * 1152)) + (ax2145 * 8)) + ax3145))];
        }
      }
    }
  }
  for (int32_t ax0170 = 0; ax0170 < 16; ++ax0170) {
    for (int32_t ax1174 = 0; ax1174 < 144; ++ax1174) {
      for (int32_t ax2146 = 0; ax2146 < 8; ++ax2146) {
        for (int32_t ax3146 = 0; ax3146 < 8; ++ax3146) {
          ((int8_t*)T_reshape)[(((((ax0170 * 9216) + (ax1174 * 64)) + (ax2146 * 8)) + ax3146))] = ((int8_t*)compute1)[(((((ax0170 * 9216) + (ax2146 * 1152)) + (ax1174 * 8)) + ax3146))];
        }
      }
    }
  }
  for (int32_t ax0171 = 0; ax0171 < 16; ++ax0171) {
    for (int32_t ax1175 = 0; ax1175 < 2; ++ax1175) {
      for (int32_t ax2147 = 0; ax2147 < 72; ++ax2147) {
        for (int32_t ax3147 = 0; ax3147 < 8; ++ax3147) {
          for (int32_t ax427 = 0; ax427 < 8; ++ax427) {
            ((int8_t*)compute1)[((((((ax0171 * 9216) + (ax1175 * 4608)) + (ax2147 * 64)) + (ax3147 * 8)) + ax427))] = ((int8_t*)T_reshape)[((((((ax0171 * 9216) + (ax1175 * 4608)) + (ax2147 * 64)) + (ax3147 * 8)) + ax427))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536936448, 18432, 0);
  for (int32_t i49 = 0; i49 < 98; ++i49) {
    for (int32_t x18 = 0; x18 < 16; ++x18) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k02 = 0; k02 < 2; ++k02) {
        (void)move(((((int64_t)((i49 * 576) + (k02 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x18 * 576) + (k02 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute1, (int64_t)537264128, 32, ((i49 * 4096) + (x18 * 256)));
    }
  }
  for (int32_t ax0172 = 0; ax0172 < 98; ++ax0172) {
    for (int32_t ax1176 = 0; ax1176 < 8; ++ax1176) {
      for (int32_t ax2148 = 0; ax2148 < 16; ++ax2148) {
        for (int32_t ax3148 = 0; ax3148 < 8; ++ax3148) {
          ((int32_t*)out1)[(((((ax0172 * 1024) + (ax1176 * 128)) + (ax2148 * 8)) + ax3148))] = ((int32_t*)compute1)[(((((ax0172 * 1024) + (ax2148 * 64)) + (ax1176 * 8)) + ax3148))];
        }
      }
    }
  }
  for (int32_t ax0173 = 0; ax0173 < 784; ++ax0173) {
    for (int32_t ax1177 = 0; ax1177 < 128; ++ax1177) {
      ((int32_t*)compute1)[(((ax0173 * 128) + ax1177))] = ((int32_t*)out1)[(((ax0173 * 128) + ax1177))];
    }
  }
  for (int32_t i027 = 0; i027 < 784; ++i027) {
    for (int32_t i1112 = 0; i1112 < 128; ++i1112) {
      ((int32_t*)out)[(((i027 * 128) + i1112))] = ((int32_t*)compute1)[(((i027 * 128) + i1112))];
    }
  }
  for (int32_t ax1178 = 0; ax1178 < 28; ++ax1178) {
    for (int32_t ax2149 = 0; ax2149 < 28; ++ax2149) {
      for (int32_t ax3149 = 0; ax3149 < 128; ++ax3149) {
        ((int32_t*)compute1)[((((ax1178 * 3584) + (ax2149 * 128)) + ax3149))] = ((int32_t*)out)[((((ax1178 * 3584) + (ax2149 * 128)) + ax3149))];
      }
    }
  }
  for (int32_t h222 = 0; h222 < 28; ++h222) {
    for (int32_t w112 = 0; w112 < 28; ++w112) {
      for (int32_t c130 = 0; c130 < 128; ++c130) {
        ((int32_t*)pad_data)[((((h222 * 3584) + (w112 * 128)) + c130))] = ((int32_t*)tensor_252)[(c130)];
      }
    }
  }
  for (int32_t h223 = 0; h223 < 28; ++h223) {
    (void)load(compute1, (int64_t)537264128, 1792, (h223 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h223 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h223 * 14336));
  }
  for (int32_t h224 = 0; h224 < 28; ++h224) {
    for (int32_t w113 = 0; w113 < 28; ++w113) {
      for (int32_t c131 = 0; c131 < 128; ++c131) {
        ((int32_t*)compute1)[((((h224 * 3584) + (w113 * 128)) + c131))] = 0;
      }
    }
  }
  for (int32_t h225 = 0; h225 < 28; ++h225) {
    (void)load(out1, (int64_t)537264128, 1792, (h225 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h225 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h225 * 14336));
  }
  for (int32_t h226 = 0; h226 < 28; ++h226) {
    for (int32_t w114 = 0; w114 < 28; ++w114) {
      for (int32_t c132 = 0; c132 < 128; ++c132) {
        ((int32_t*)compute1)[((((h226 * 3584) + (w114 * 128)) + c132))] = 32;
      }
    }
  }
  for (int32_t h227 = 0; h227 < 28; ++h227) {
    (void)load(out, (int64_t)537264128, 1792, (h227 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h227 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h227 * 14336));
  }
  for (int32_t h228 = 0; h228 < 28; ++h228) {
    for (int32_t w115 = 0; w115 < 28; ++w115) {
      for (int32_t c133 = 0; c133 < 128; ++c133) {
        ((int32_t*)compute1)[((((h228 * 3584) + (w115 * 128)) + c133))] = 6;
      }
    }
  }
  for (int32_t h229 = 0; h229 < 28; ++h229) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h229 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h229 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h229 * 14336));
  }
  for (int32_t i1113 = 0; i1113 < 28; ++i1113) {
    for (int32_t i285 = 0; i285 < 28; ++i285) {
      for (int32_t i385 = 0; i385 < 128; ++i385) {
        int32_t _66 = ((int32_t*)out1)[((((i1113 * 3584) + (i285 * 128)) + i385))];
        int32_t _67 = (_66) < (127) ? (_66) : (127);
        ((int32_t*)compute1)[((((i1113 * 3584) + (i285 * 128)) + i385))] = ((_67) > (-127) ? (_67) : (-127));
      }
    }
  }
  for (int32_t i1114 = 0; i1114 < 28; ++i1114) {
    for (int32_t i286 = 0; i286 < 28; ++i286) {
      for (int32_t i386 = 0; i386 < 128; ++i386) {
        ((int8_t*)T_reshape1)[((((i1114 * 3584) + (i286 * 128)) + i386))] = ((int8_t)((int32_t*)compute1)[((((i1114 * 3584) + (i286 * 128)) + i386))]);
      }
    }
  }
  for (int32_t ax0174 = 0; ax0174 < 98; ++ax0174) {
    for (int32_t ax1179 = 0; ax1179 < 8; ++ax1179) {
      for (int32_t ax2150 = 0; ax2150 < 16; ++ax2150) {
        for (int32_t ax3150 = 0; ax3150 < 8; ++ax3150) {
          ((int8_t*)T_reshape)[(((((ax0174 * 1024) + (ax1179 * 128)) + (ax2150 * 8)) + ax3150))] = ((int8_t*)T_reshape1)[(((((ax0174 * 1024) + (ax1179 * 128)) + (ax2150 * 8)) + ax3150))];
        }
      }
    }
  }
  for (int32_t ax0175 = 0; ax0175 < 98; ++ax0175) {
    for (int32_t ax1180 = 0; ax1180 < 16; ++ax1180) {
      for (int32_t ax2151 = 0; ax2151 < 8; ++ax2151) {
        for (int32_t ax3151 = 0; ax3151 < 8; ++ax3151) {
          ((int8_t*)T_reshape1)[(((((ax0175 * 1024) + (ax1180 * 64)) + (ax2151 * 8)) + ax3151))] = ((int8_t*)T_reshape)[(((((ax0175 * 1024) + (ax2151 * 128)) + (ax1180 * 8)) + ax3151))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 12544, 0);
  for (int32_t ax0176 = 0; ax0176 < 512; ++ax0176) {
    for (int32_t ax1181 = 0; ax1181 < 128; ++ax1181) {
      ((int8_t*)T_reshape1)[(((ax0176 * 128) + ax1181))] = ((int8_t*)kernel_259)[(((ax0176 * 128) + ax1181))];
    }
  }
  for (int32_t ax0177 = 0; ax0177 < 64; ++ax0177) {
    for (int32_t ax1182 = 0; ax1182 < 8; ++ax1182) {
      for (int32_t ax2152 = 0; ax2152 < 16; ++ax2152) {
        for (int32_t ax3152 = 0; ax3152 < 8; ++ax3152) {
          ((int8_t*)T_reshape)[(((((ax0177 * 1024) + (ax1182 * 128)) + (ax2152 * 8)) + ax3152))] = ((int8_t*)T_reshape1)[(((((ax0177 * 1024) + (ax1182 * 128)) + (ax2152 * 8)) + ax3152))];
        }
      }
    }
  }
  for (int32_t ax0178 = 0; ax0178 < 64; ++ax0178) {
    for (int32_t ax1183 = 0; ax1183 < 16; ++ax1183) {
      for (int32_t ax2153 = 0; ax2153 < 8; ++ax2153) {
        for (int32_t ax3153 = 0; ax3153 < 8; ++ax3153) {
          ((int8_t*)T_reshape1)[(((((ax0178 * 1024) + (ax1183 * 64)) + (ax2153 * 8)) + ax3153))] = ((int8_t*)T_reshape)[(((((ax0178 * 1024) + (ax2153 * 128)) + (ax1183 * 8)) + ax3153))];
        }
      }
    }
  }
  for (int32_t ax0179 = 0; ax0179 < 64; ++ax0179) {
    for (int32_t ax2154 = 0; ax2154 < 16; ++ax2154) {
      for (int32_t ax3154 = 0; ax3154 < 8; ++ax3154) {
        for (int32_t ax428 = 0; ax428 < 8; ++ax428) {
          ((int8_t*)T_reshape)[(((((ax0179 * 1024) + (ax2154 * 64)) + (ax3154 * 8)) + ax428))] = ((int8_t*)T_reshape1)[(((((ax0179 * 1024) + (ax2154 * 64)) + (ax3154 * 8)) + ax428))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i50 = 0; i50 < 98; ++i50) {
    for (int32_t x19 = 0; x19 < 64; ++x19) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i50 * 64) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 128, 0);
      (void)move(((((int64_t)(x19 * 64)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 128, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 16, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i50 * 16384) + (x19 * 256)));
    }
  }
  for (int32_t ax0180 = 0; ax0180 < 98; ++ax0180) {
    for (int32_t ax1184 = 0; ax1184 < 8; ++ax1184) {
      for (int32_t ax2155 = 0; ax2155 < 64; ++ax2155) {
        for (int32_t ax3155 = 0; ax3155 < 8; ++ax3155) {
          ((int32_t*)out)[(((((ax0180 * 4096) + (ax1184 * 512)) + (ax2155 * 8)) + ax3155))] = ((int32_t*)compute1)[(((((ax0180 * 4096) + (ax2155 * 64)) + (ax1184 * 8)) + ax3155))];
        }
      }
    }
  }
  for (int32_t ax0181 = 0; ax0181 < 784; ++ax0181) {
    for (int32_t ax1185 = 0; ax1185 < 512; ++ax1185) {
      ((int32_t*)compute1)[(((ax0181 * 512) + ax1185))] = ((int32_t*)out)[(((ax0181 * 512) + ax1185))];
    }
  }
  for (int32_t i028 = 0; i028 < 784; ++i028) {
    for (int32_t i1115 = 0; i1115 < 512; ++i1115) {
      ((int32_t*)pad_data)[(((i028 * 512) + i1115))] = ((int32_t*)compute1)[(((i028 * 512) + i1115))];
    }
  }
  for (int32_t ax1186 = 0; ax1186 < 28; ++ax1186) {
    for (int32_t ax2156 = 0; ax2156 < 28; ++ax2156) {
      for (int32_t ax3156 = 0; ax3156 < 512; ++ax3156) {
        ((int32_t*)compute1)[((((ax1186 * 14336) + (ax2156 * 512)) + ax3156))] = ((int32_t*)pad_data)[((((ax1186 * 14336) + (ax2156 * 512)) + ax3156))];
      }
    }
  }
  for (int32_t h230 = 0; h230 < 28; ++h230) {
    for (int32_t w116 = 0; w116 < 28; ++w116) {
      for (int32_t c134 = 0; c134 < 512; ++c134) {
        ((int32_t*)out1)[((((h230 * 14336) + (w116 * 512)) + c134))] = 10;
      }
    }
  }
  for (int32_t h231 = 0; h231 < 28; ++h231) {
    (void)load(compute1, (int64_t)537264128, 7168, (h231 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h231 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h231 * 57344));
  }
  for (int32_t h232 = 0; h232 < 28; ++h232) {
    for (int32_t w117 = 0; w117 < 28; ++w117) {
      for (int32_t c135 = 0; c135 < 512; ++c135) {
        ((int32_t*)compute1)[((((h232 * 14336) + (w117 * 512)) + c135))] = ((int32_t*)tensor_261)[(c135)];
      }
    }
  }
  for (int32_t h233 = 0; h233 < 28; ++h233) {
    (void)load(out, (int64_t)537264128, 7168, (h233 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h233 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h233 * 57344));
  }
  for (int32_t h234 = 0; h234 < 28; ++h234) {
    for (int32_t w118 = 0; w118 < 28; ++w118) {
      for (int32_t c136 = 0; c136 < 512; ++c136) {
        ((int32_t*)compute1)[((((h234 * 14336) + (w118 * 512)) + c136))] = 131072;
      }
    }
  }
  for (int32_t h235 = 0; h235 < 28; ++h235) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h235 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h235 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h235 * 57344));
  }
  for (int32_t h236 = 0; h236 < 28; ++h236) {
    for (int32_t w119 = 0; w119 < 28; ++w119) {
      for (int32_t c137 = 0; c137 < 512; ++c137) {
        ((int32_t*)compute1)[((((h236 * 14336) + (w119 * 512)) + c137))] = 18;
      }
    }
  }
  for (int32_t h237 = 0; h237 < 28; ++h237) {
    (void)load(out1, (int64_t)537264128, 7168, (h237 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h237 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h237 * 57344));
  }
  for (int32_t i1116 = 0; i1116 < 28; ++i1116) {
    for (int32_t i287 = 0; i287 < 28; ++i287) {
      for (int32_t i387 = 0; i387 < 512; ++i387) {
        int32_t _68 = ((int32_t*)out)[((((i1116 * 14336) + (i287 * 512)) + i387))];
        int32_t _69 = (_68) < (127) ? (_68) : (127);
        ((int32_t*)compute1)[((((i1116 * 14336) + (i287 * 512)) + i387))] = ((_69) > (-127) ? (_69) : (-127));
      }
    }
  }
  for (int32_t i1117 = 0; i1117 < 28; ++i1117) {
    for (int32_t i288 = 0; i288 < 28; ++i288) {
      for (int32_t i388 = 0; i388 < 512; ++i388) {
        ((int8_t*)pad_data)[((((i1117 * 14336) + (i288 * 512)) + i388))] = ((int8_t)((int32_t*)compute1)[((((i1117 * 14336) + (i288 * 512)) + i388))]);
      }
    }
  }
  for (int32_t i1118 = 0; i1118 < 28; ++i1118) {
    for (int32_t i289 = 0; i289 < 28; ++i289) {
      for (int32_t i389 = 0; i389 < 512; ++i389) {
        ((int32_t*)compute1)[((((i1118 * 14336) + (i289 * 512)) + i389))] = ((int32_t)((int8_t*)pad_data)[((((i1118 * 14336) + (i289 * 512)) + i389))]);
      }
    }
  }
  for (int32_t h238 = 0; h238 < 28; ++h238) {
    for (int32_t w120 = 0; w120 < 28; ++w120) {
      for (int32_t c138 = 0; c138 < 512; ++c138) {
        ((int32_t*)out1)[((((h238 * 14336) + (w120 * 512)) + c138))] = ((int32_t*)tensor_268)[(c138)];
      }
    }
  }
  for (int32_t h239 = 0; h239 < 28; ++h239) {
    (void)load(compute1, (int64_t)537264128, 7168, (h239 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h239 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h239 * 57344));
  }
  for (int32_t h240 = 0; h240 < 28; ++h240) {
    for (int32_t w121 = 0; w121 < 28; ++w121) {
      for (int32_t c139 = 0; c139 < 512; ++c139) {
        ((int32_t*)compute1)[((((h240 * 14336) + (w121 * 512)) + c139))] = ((int32_t*)tensor_269)[(c139)];
      }
    }
  }
  for (int32_t h241 = 0; h241 < 28; ++h241) {
    (void)load(out, (int64_t)537264128, 7168, (h241 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h241 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h241 * 57344));
  }
  for (int32_t h242 = 0; h242 < 28; ++h242) {
    for (int32_t w122 = 0; w122 < 28; ++w122) {
      for (int32_t c140 = 0; c140 < 512; ++c140) {
        ((int32_t*)compute1)[((((h242 * 14336) + (w122 * 512)) + c140))] = 8;
      }
    }
  }
  for (int32_t h243 = 0; h243 < 28; ++h243) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h243 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h243 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h243 * 57344));
  }
  for (int32_t h244 = 0; h244 < 28; ++h244) {
    for (int32_t w123 = 0; w123 < 28; ++w123) {
      for (int32_t c141 = 0; c141 < 512; ++c141) {
        ((int32_t*)compute1)[((((h244 * 14336) + (w123 * 512)) + c141))] = 4;
      }
    }
  }
  for (int32_t h245 = 0; h245 < 28; ++h245) {
    (void)load(out1, (int64_t)537264128, 7168, (h245 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h245 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h245 * 57344));
  }
  for (int32_t i1119 = 0; i1119 < 28; ++i1119) {
    for (int32_t i290 = 0; i290 < 28; ++i290) {
      for (int32_t i390 = 0; i390 < 512; ++i390) {
        int32_t _70 = ((int32_t*)out)[((((i1119 * 14336) + (i290 * 512)) + i390))];
        int32_t _71 = (_70) < (127) ? (_70) : (127);
        ((int32_t*)compute1)[((((i1119 * 14336) + (i290 * 512)) + i390))] = ((_71) > (-127) ? (_71) : (-127));
      }
    }
  }
  for (int32_t i1120 = 0; i1120 < 28; ++i1120) {
    for (int32_t i291 = 0; i291 < 28; ++i291) {
      for (int32_t i391 = 0; i391 < 512; ++i391) {
        ((int8_t*)pad_data)[((((i1120 * 14336) + (i291 * 512)) + i391))] = ((int8_t)((int32_t*)compute1)[((((i1120 * 14336) + (i291 * 512)) + i391))]);
      }
    }
  }
  for (int32_t i1121 = 0; i1121 < 28; ++i1121) {
    for (int32_t i292 = 0; i292 < 28; ++i292) {
      for (int32_t i392 = 0; i392 < 512; ++i392) {
        ((int32_t*)compute1)[((((i1121 * 14336) + (i292 * 512)) + i392))] = ((int32_t)((int8_t*)pad_data)[((((i1121 * 14336) + (i292 * 512)) + i392))]);
      }
    }
  }
  for (int32_t i1122 = 0; i1122 < 28; ++i1122) {
    for (int32_t i293 = 0; i293 < 28; ++i293) {
      for (int32_t i393 = 0; i393 < 512; ++i393) {
        ((int32_t*)out1)[((((i1122 * 14336) + (i293 * 512)) + i393))] = ((int32_t)((int8_t*)compute)[((((i1122 * 14336) + (i293 * 512)) + i393))]);
      }
    }
  }
  for (int32_t h246 = 0; h246 < 28; ++h246) {
    (void)load(compute1, (int64_t)537264128, 7168, (h246 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h246 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h246 * 57344));
  }
  for (int32_t h247 = 0; h247 < 28; ++h247) {
    for (int32_t w124 = 0; w124 < 28; ++w124) {
      for (int32_t c142 = 0; c142 < 512; ++c142) {
        ((int32_t*)compute1)[((((h247 * 14336) + (w124 * 512)) + c142))] = 0;
      }
    }
  }
  for (int32_t h248 = 0; h248 < 28; ++h248) {
    (void)load(out, (int64_t)537264128, 7168, (h248 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h248 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h248 * 57344));
  }
  for (int32_t i1123 = 0; i1123 < 28; ++i1123) {
    for (int32_t i294 = 0; i294 < 28; ++i294) {
      for (int32_t i394 = 0; i394 < 512; ++i394) {
        int32_t _72 = ((int32_t*)pad_data)[((((i1123 * 14336) + (i294 * 512)) + i394))];
        int32_t _73 = (_72) < (127) ? (_72) : (127);
        ((int32_t*)compute1)[((((i1123 * 14336) + (i294 * 512)) + i394))] = ((_73) > (-127) ? (_73) : (-127));
      }
    }
  }
  for (int32_t i1124 = 0; i1124 < 28; ++i1124) {
    for (int32_t i295 = 0; i295 < 28; ++i295) {
      for (int32_t i395 = 0; i395 < 512; ++i395) {
        ((int8_t*)compute)[((((i1124 * 14336) + (i295 * 512)) + i395))] = ((int8_t)((int32_t*)compute1)[((((i1124 * 14336) + (i295 * 512)) + i395))]);
      }
    }
  }
  for (int32_t o117 = 0; o117 < 28; ++o117) {
    for (int32_t o217 = 0; o217 < 28; ++o217) {
      for (int32_t c143 = 0; c143 < 512; ++c143) {
        ((int8_t*)compute1)[((((o117 * 14336) + (o217 * 512)) + c143))] = ((int8_t*)compute)[((((o117 * 14336) + (o217 * 512)) + c143))];
      }
    }
  }
  for (int32_t ax0182 = 0; ax0182 < 784; ++ax0182) {
    for (int32_t ax1187 = 0; ax1187 < 512; ++ax1187) {
      ((int8_t*)out1)[(((ax0182 * 512) + ax1187))] = ((int8_t*)compute1)[(((ax0182 * 512) + ax1187))];
    }
  }
  for (int32_t i029 = 0; i029 < 784; ++i029) {
    for (int32_t i1125 = 0; i1125 < 512; ++i1125) {
      ((int8_t*)compute1)[(((i029 * 512) + i1125))] = ((int8_t*)out1)[(((i029 * 512) + i1125))];
    }
  }
  for (int32_t ax0183 = 0; ax0183 < 98; ++ax0183) {
    for (int32_t ax1188 = 0; ax1188 < 8; ++ax1188) {
      for (int32_t ax2157 = 0; ax2157 < 64; ++ax2157) {
        for (int32_t ax3157 = 0; ax3157 < 8; ++ax3157) {
          ((int8_t*)out)[(((((ax0183 * 4096) + (ax1188 * 512)) + (ax2157 * 8)) + ax3157))] = ((int8_t*)compute1)[(((((ax0183 * 4096) + (ax1188 * 512)) + (ax2157 * 8)) + ax3157))];
        }
      }
    }
  }
  for (int32_t ax0184 = 0; ax0184 < 98; ++ax0184) {
    for (int32_t ax1189 = 0; ax1189 < 64; ++ax1189) {
      for (int32_t ax2158 = 0; ax2158 < 8; ++ax2158) {
        for (int32_t ax3158 = 0; ax3158 < 8; ++ax3158) {
          ((int8_t*)compute1)[(((((ax0184 * 4096) + (ax1189 * 64)) + (ax2158 * 8)) + ax3158))] = ((int8_t*)out)[(((((ax0184 * 4096) + (ax2158 * 512)) + (ax1189 * 8)) + ax3158))];
        }
      }
    }
  }
  for (int32_t ax0185 = 0; ax0185 < 98; ++ax0185) {
    for (int32_t ax2159 = 0; ax2159 < 64; ++ax2159) {
      for (int32_t ax3159 = 0; ax3159 < 8; ++ax3159) {
        for (int32_t ax429 = 0; ax429 < 8; ++ax429) {
          ((int8_t*)pad_data)[(((((ax0185 * 4096) + (ax2159 * 64)) + (ax3159 * 8)) + ax429))] = ((int8_t*)compute1)[(((((ax0185 * 4096) + (ax2159 * 64)) + (ax3159 * 8)) + ax429))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 50176, 0);
  for (int32_t ax0186 = 0; ax0186 < 128; ++ax0186) {
    for (int32_t ax1190 = 0; ax1190 < 512; ++ax1190) {
      ((int8_t*)T_reshape1)[(((ax0186 * 512) + ax1190))] = ((int8_t*)kernel_284)[(((ax0186 * 512) + ax1190))];
    }
  }
  for (int32_t ax0187 = 0; ax0187 < 16; ++ax0187) {
    for (int32_t ax1191 = 0; ax1191 < 8; ++ax1191) {
      for (int32_t ax2160 = 0; ax2160 < 64; ++ax2160) {
        for (int32_t ax3160 = 0; ax3160 < 8; ++ax3160) {
          ((int8_t*)T_reshape)[(((((ax0187 * 4096) + (ax1191 * 512)) + (ax2160 * 8)) + ax3160))] = ((int8_t*)T_reshape1)[(((((ax0187 * 4096) + (ax1191 * 512)) + (ax2160 * 8)) + ax3160))];
        }
      }
    }
  }
  for (int32_t ax0188 = 0; ax0188 < 16; ++ax0188) {
    for (int32_t ax1192 = 0; ax1192 < 64; ++ax1192) {
      for (int32_t ax2161 = 0; ax2161 < 8; ++ax2161) {
        for (int32_t ax3161 = 0; ax3161 < 8; ++ax3161) {
          ((int8_t*)T_reshape1)[(((((ax0188 * 4096) + (ax1192 * 64)) + (ax2161 * 8)) + ax3161))] = ((int8_t*)T_reshape)[(((((ax0188 * 4096) + (ax2161 * 512)) + (ax1192 * 8)) + ax3161))];
        }
      }
    }
  }
  for (int32_t ax0189 = 0; ax0189 < 16; ++ax0189) {
    for (int32_t ax2162 = 0; ax2162 < 64; ++ax2162) {
      for (int32_t ax3162 = 0; ax3162 < 8; ++ax3162) {
        for (int32_t ax430 = 0; ax430 < 8; ++ax430) {
          ((int8_t*)T_reshape)[(((((ax0189 * 4096) + (ax2162 * 64)) + (ax3162 * 8)) + ax430))] = ((int8_t*)T_reshape1)[(((((ax0189 * 4096) + (ax2162 * 64)) + (ax3162 * 8)) + ax430))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i51 = 0; i51 < 98; ++i51) {
    for (int32_t x20 = 0; x20 < 16; ++x20) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i51 * 256)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x20 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i51 * 4096) + (x20 * 256)));
    }
  }
  for (int32_t ax0190 = 0; ax0190 < 98; ++ax0190) {
    for (int32_t ax1193 = 0; ax1193 < 8; ++ax1193) {
      for (int32_t ax2163 = 0; ax2163 < 16; ++ax2163) {
        for (int32_t ax3163 = 0; ax3163 < 8; ++ax3163) {
          ((int32_t*)out1)[(((((ax0190 * 1024) + (ax1193 * 128)) + (ax2163 * 8)) + ax3163))] = ((int32_t*)compute1)[(((((ax0190 * 1024) + (ax2163 * 64)) + (ax1193 * 8)) + ax3163))];
        }
      }
    }
  }
  for (int32_t ax0191 = 0; ax0191 < 784; ++ax0191) {
    for (int32_t ax1194 = 0; ax1194 < 128; ++ax1194) {
      ((int32_t*)compute1)[(((ax0191 * 128) + ax1194))] = ((int32_t*)out1)[(((ax0191 * 128) + ax1194))];
    }
  }
  for (int32_t i030 = 0; i030 < 784; ++i030) {
    for (int32_t i1126 = 0; i1126 < 128; ++i1126) {
      ((int32_t*)out)[(((i030 * 128) + i1126))] = ((int32_t*)compute1)[(((i030 * 128) + i1126))];
    }
  }
  for (int32_t ax1195 = 0; ax1195 < 28; ++ax1195) {
    for (int32_t ax2164 = 0; ax2164 < 28; ++ax2164) {
      for (int32_t ax3164 = 0; ax3164 < 128; ++ax3164) {
        ((int32_t*)compute1)[((((ax1195 * 3584) + (ax2164 * 128)) + ax3164))] = ((int32_t*)out)[((((ax1195 * 3584) + (ax2164 * 128)) + ax3164))];
      }
    }
  }
  for (int32_t h249 = 0; h249 < 28; ++h249) {
    for (int32_t w125 = 0; w125 < 28; ++w125) {
      for (int32_t c144 = 0; c144 < 128; ++c144) {
        ((int32_t*)pad_data)[((((h249 * 3584) + (w125 * 128)) + c144))] = 11;
      }
    }
  }
  for (int32_t h250 = 0; h250 < 28; ++h250) {
    (void)load(compute1, (int64_t)537264128, 1792, (h250 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h250 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h250 * 14336));
  }
  for (int32_t h251 = 0; h251 < 28; ++h251) {
    for (int32_t w126 = 0; w126 < 28; ++w126) {
      for (int32_t c145 = 0; c145 < 128; ++c145) {
        ((int32_t*)compute1)[((((h251 * 3584) + (w126 * 128)) + c145))] = ((int32_t*)tensor_286)[(c145)];
      }
    }
  }
  for (int32_t h252 = 0; h252 < 28; ++h252) {
    (void)load(out1, (int64_t)537264128, 1792, (h252 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h252 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h252 * 14336));
  }
  for (int32_t h253 = 0; h253 < 28; ++h253) {
    for (int32_t w127 = 0; w127 < 28; ++w127) {
      for (int32_t c146 = 0; c146 < 128; ++c146) {
        ((int32_t*)compute1)[((((h253 * 3584) + (w127 * 128)) + c146))] = ((int32_t*)tensor_287)[(c146)];
      }
    }
  }
  for (int32_t h254 = 0; h254 < 28; ++h254) {
    (void)load(out, (int64_t)537264128, 1792, (h254 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h254 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h254 * 14336));
  }
  for (int32_t h255 = 0; h255 < 28; ++h255) {
    for (int32_t w128 = 0; w128 < 28; ++w128) {
      for (int32_t c147 = 0; c147 < 128; ++c147) {
        ((int32_t*)compute1)[((((h255 * 3584) + (w128 * 128)) + c147))] = 0;
      }
    }
  }
  for (int32_t h256 = 0; h256 < 28; ++h256) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h256 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h256 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h256 * 14336));
  }
  for (int32_t h257 = 0; h257 < 28; ++h257) {
    for (int32_t w129 = 0; w129 < 28; ++w129) {
      for (int32_t c148 = 0; c148 < 128; ++c148) {
        ((int32_t*)compute1)[((((h257 * 3584) + (w129 * 128)) + c148))] = 262144;
      }
    }
  }
  for (int32_t h258 = 0; h258 < 28; ++h258) {
    (void)load(out1, (int64_t)537264128, 1792, (h258 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h258 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h258 * 14336));
  }
  for (int32_t h259 = 0; h259 < 28; ++h259) {
    for (int32_t w130 = 0; w130 < 28; ++w130) {
      for (int32_t c149 = 0; c149 < 128; ++c149) {
        ((int32_t*)compute1)[((((h259 * 3584) + (w130 * 128)) + c149))] = 19;
      }
    }
  }
  for (int32_t h260 = 0; h260 < 28; ++h260) {
    (void)load(out, (int64_t)537264128, 1792, (h260 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h260 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h260 * 14336));
  }
  for (int32_t i1127 = 0; i1127 < 28; ++i1127) {
    for (int32_t i296 = 0; i296 < 28; ++i296) {
      for (int32_t i396 = 0; i396 < 128; ++i396) {
        int32_t _74 = ((int32_t*)pad_data)[((((i1127 * 3584) + (i296 * 128)) + i396))];
        int32_t _75 = (_74) < (127) ? (_74) : (127);
        ((int32_t*)compute1)[((((i1127 * 3584) + (i296 * 128)) + i396))] = ((_75) > (-127) ? (_75) : (-127));
      }
    }
  }
  for (int32_t i1128 = 0; i1128 < 28; ++i1128) {
    for (int32_t i297 = 0; i297 < 28; ++i297) {
      for (int32_t i397 = 0; i397 < 128; ++i397) {
        ((int8_t*)T_reshape1)[((((i1128 * 3584) + (i297 * 128)) + i397))] = ((int8_t)((int32_t*)compute1)[((((i1128 * 3584) + (i297 * 128)) + i397))]);
      }
    }
  }
  for (int32_t i1129 = 0; i1129 < 30; ++i1129) {
    for (int32_t i298 = 0; i298 < 30; ++i298) {
      for (int32_t i398 = 0; i398 < 128; ++i398) {
        ((int8_t*)T_reshape)[((((i1129 * 3840) + (i298 * 128)) + i398))] = (((((1 <= i1129) && (i1129 < 29)) && (1 <= i298)) && (i298 < 29)) ? ((int8_t*)T_reshape1)[(((((i1129 * 3584) + (i298 * 128)) + i398) - 3712))] : (int8_t)0);
      }
    }
  }
  for (int32_t o118 = 0; o118 < 28; ++o118) {
    for (int32_t o218 = 0; o218 < 28; ++o218) {
      for (int32_t k16 = 0; k16 < 3; ++k16) {
        for (int32_t k26 = 0; k26 < 3; ++k26) {
          for (int32_t c150 = 0; c150 < 128; ++c150) {
            ((int8_t*)compute1)[((((((o118 * 32256) + (o218 * 1152)) + (k16 * 384)) + (k26 * 128)) + c150))] = ((int8_t*)T_reshape)[((((((k16 * 3840) + (o118 * 3840)) + (k26 * 128)) + (o218 * 128)) + c150))];
          }
        }
      }
    }
  }
  for (int32_t ax0192 = 0; ax0192 < 784; ++ax0192) {
    for (int32_t ax1196 = 0; ax1196 < 1152; ++ax1196) {
      ((int8_t*)out1)[(((ax0192 * 1152) + ax1196))] = ((int8_t*)compute1)[(((ax0192 * 1152) + ax1196))];
    }
  }
  for (int32_t i031 = 0; i031 < 784; ++i031) {
    for (int32_t i1130 = 0; i1130 < 1152; ++i1130) {
      ((int8_t*)compute1)[(((i031 * 1152) + i1130))] = ((int8_t*)out1)[(((i031 * 1152) + i1130))];
    }
  }
  for (int32_t ax0193 = 0; ax0193 < 98; ++ax0193) {
    for (int32_t ax1197 = 0; ax1197 < 8; ++ax1197) {
      for (int32_t ax2165 = 0; ax2165 < 144; ++ax2165) {
        for (int32_t ax3165 = 0; ax3165 < 8; ++ax3165) {
          ((int8_t*)out)[(((((ax0193 * 9216) + (ax1197 * 1152)) + (ax2165 * 8)) + ax3165))] = ((int8_t*)compute1)[(((((ax0193 * 9216) + (ax1197 * 1152)) + (ax2165 * 8)) + ax3165))];
        }
      }
    }
  }
  for (int32_t ax0194 = 0; ax0194 < 98; ++ax0194) {
    for (int32_t ax1198 = 0; ax1198 < 144; ++ax1198) {
      for (int32_t ax2166 = 0; ax2166 < 8; ++ax2166) {
        for (int32_t ax3166 = 0; ax3166 < 8; ++ax3166) {
          ((int8_t*)compute1)[(((((ax0194 * 9216) + (ax1198 * 64)) + (ax2166 * 8)) + ax3166))] = ((int8_t*)out)[(((((ax0194 * 9216) + (ax2166 * 1152)) + (ax1198 * 8)) + ax3166))];
        }
      }
    }
  }
  for (int32_t ax0195 = 0; ax0195 < 98; ++ax0195) {
    for (int32_t ax1199 = 0; ax1199 < 2; ++ax1199) {
      for (int32_t ax2167 = 0; ax2167 < 72; ++ax2167) {
        for (int32_t ax3167 = 0; ax3167 < 8; ++ax3167) {
          for (int32_t ax431 = 0; ax431 < 8; ++ax431) {
            ((int8_t*)pad_data)[((((((ax0195 * 9216) + (ax1199 * 4608)) + (ax2167 * 64)) + (ax3167 * 8)) + ax431))] = ((int8_t*)compute1)[((((((ax0195 * 9216) + (ax1199 * 4608)) + (ax2167 * 64)) + (ax3167 * 8)) + ax431))];
          }
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 112896, 0);
  for (int32_t ax0196 = 0; ax0196 < 128; ++ax0196) {
    for (int32_t ax1200 = 0; ax1200 < 1152; ++ax1200) {
      ((int8_t*)T_reshape)[(((ax0196 * 1152) + ax1200))] = ((int8_t*)kernel_294)[(((ax0196 * 1152) + ax1200))];
    }
  }
  for (int32_t ax0197 = 0; ax0197 < 16; ++ax0197) {
    for (int32_t ax1201 = 0; ax1201 < 8; ++ax1201) {
      for (int32_t ax2168 = 0; ax2168 < 144; ++ax2168) {
        for (int32_t ax3168 = 0; ax3168 < 8; ++ax3168) {
          ((int8_t*)compute1)[(((((ax0197 * 9216) + (ax1201 * 1152)) + (ax2168 * 8)) + ax3168))] = ((int8_t*)T_reshape)[(((((ax0197 * 9216) + (ax1201 * 1152)) + (ax2168 * 8)) + ax3168))];
        }
      }
    }
  }
  for (int32_t ax0198 = 0; ax0198 < 16; ++ax0198) {
    for (int32_t ax1202 = 0; ax1202 < 144; ++ax1202) {
      for (int32_t ax2169 = 0; ax2169 < 8; ++ax2169) {
        for (int32_t ax3169 = 0; ax3169 < 8; ++ax3169) {
          ((int8_t*)T_reshape)[(((((ax0198 * 9216) + (ax1202 * 64)) + (ax2169 * 8)) + ax3169))] = ((int8_t*)compute1)[(((((ax0198 * 9216) + (ax2169 * 1152)) + (ax1202 * 8)) + ax3169))];
        }
      }
    }
  }
  for (int32_t ax0199 = 0; ax0199 < 16; ++ax0199) {
    for (int32_t ax1203 = 0; ax1203 < 2; ++ax1203) {
      for (int32_t ax2170 = 0; ax2170 < 72; ++ax2170) {
        for (int32_t ax3170 = 0; ax3170 < 8; ++ax3170) {
          for (int32_t ax432 = 0; ax432 < 8; ++ax432) {
            ((int8_t*)compute1)[((((((ax0199 * 9216) + (ax1203 * 4608)) + (ax2170 * 64)) + (ax3170 * 8)) + ax432))] = ((int8_t*)T_reshape)[((((((ax0199 * 9216) + (ax1203 * 4608)) + (ax2170 * 64)) + (ax3170 * 8)) + ax432))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536936448, 18432, 0);
  for (int32_t i52 = 0; i52 < 98; ++i52) {
    for (int32_t x21 = 0; x21 < 16; ++x21) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k03 = 0; k03 < 2; ++k03) {
        (void)move(((((int64_t)((i52 * 576) + (k03 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x21 * 576) + (k03 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute1, (int64_t)537264128, 32, ((i52 * 4096) + (x21 * 256)));
    }
  }
  for (int32_t ax0200 = 0; ax0200 < 98; ++ax0200) {
    for (int32_t ax1204 = 0; ax1204 < 8; ++ax1204) {
      for (int32_t ax2171 = 0; ax2171 < 16; ++ax2171) {
        for (int32_t ax3171 = 0; ax3171 < 8; ++ax3171) {
          ((int32_t*)out1)[(((((ax0200 * 1024) + (ax1204 * 128)) + (ax2171 * 8)) + ax3171))] = ((int32_t*)compute1)[(((((ax0200 * 1024) + (ax2171 * 64)) + (ax1204 * 8)) + ax3171))];
        }
      }
    }
  }
  for (int32_t ax0201 = 0; ax0201 < 784; ++ax0201) {
    for (int32_t ax1205 = 0; ax1205 < 128; ++ax1205) {
      ((int32_t*)compute1)[(((ax0201 * 128) + ax1205))] = ((int32_t*)out1)[(((ax0201 * 128) + ax1205))];
    }
  }
  for (int32_t i032 = 0; i032 < 784; ++i032) {
    for (int32_t i1131 = 0; i1131 < 128; ++i1131) {
      ((int32_t*)out)[(((i032 * 128) + i1131))] = ((int32_t*)compute1)[(((i032 * 128) + i1131))];
    }
  }
  for (int32_t ax1206 = 0; ax1206 < 28; ++ax1206) {
    for (int32_t ax2172 = 0; ax2172 < 28; ++ax2172) {
      for (int32_t ax3172 = 0; ax3172 < 128; ++ax3172) {
        ((int32_t*)compute1)[((((ax1206 * 3584) + (ax2172 * 128)) + ax3172))] = ((int32_t*)out)[((((ax1206 * 3584) + (ax2172 * 128)) + ax3172))];
      }
    }
  }
  for (int32_t h261 = 0; h261 < 28; ++h261) {
    for (int32_t w131 = 0; w131 < 28; ++w131) {
      for (int32_t c151 = 0; c151 < 128; ++c151) {
        ((int32_t*)pad_data)[((((h261 * 3584) + (w131 * 128)) + c151))] = ((int32_t*)tensor_295)[(c151)];
      }
    }
  }
  for (int32_t h262 = 0; h262 < 28; ++h262) {
    (void)load(compute1, (int64_t)537264128, 1792, (h262 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h262 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h262 * 14336));
  }
  for (int32_t h263 = 0; h263 < 28; ++h263) {
    for (int32_t w132 = 0; w132 < 28; ++w132) {
      for (int32_t c152 = 0; c152 < 128; ++c152) {
        ((int32_t*)compute1)[((((h263 * 3584) + (w132 * 128)) + c152))] = 0;
      }
    }
  }
  for (int32_t h264 = 0; h264 < 28; ++h264) {
    (void)load(out1, (int64_t)537264128, 1792, (h264 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h264 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h264 * 14336));
  }
  for (int32_t h265 = 0; h265 < 28; ++h265) {
    for (int32_t w133 = 0; w133 < 28; ++w133) {
      for (int32_t c153 = 0; c153 < 128; ++c153) {
        ((int32_t*)compute1)[((((h265 * 3584) + (w133 * 128)) + c153))] = 128;
      }
    }
  }
  for (int32_t h266 = 0; h266 < 28; ++h266) {
    (void)load(out, (int64_t)537264128, 1792, (h266 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h266 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h266 * 14336));
  }
  for (int32_t h267 = 0; h267 < 28; ++h267) {
    for (int32_t w134 = 0; w134 < 28; ++w134) {
      for (int32_t c154 = 0; c154 < 128; ++c154) {
        ((int32_t*)compute1)[((((h267 * 3584) + (w134 * 128)) + c154))] = 8;
      }
    }
  }
  for (int32_t h268 = 0; h268 < 28; ++h268) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h268 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h268 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h268 * 14336));
  }
  for (int32_t i1132 = 0; i1132 < 28; ++i1132) {
    for (int32_t i299 = 0; i299 < 28; ++i299) {
      for (int32_t i399 = 0; i399 < 128; ++i399) {
        int32_t _76 = ((int32_t*)out1)[((((i1132 * 3584) + (i299 * 128)) + i399))];
        int32_t _77 = (_76) < (127) ? (_76) : (127);
        ((int32_t*)compute1)[((((i1132 * 3584) + (i299 * 128)) + i399))] = ((_77) > (-127) ? (_77) : (-127));
      }
    }
  }
  for (int32_t i1133 = 0; i1133 < 28; ++i1133) {
    for (int32_t i2100 = 0; i2100 < 28; ++i2100) {
      for (int32_t i3100 = 0; i3100 < 128; ++i3100) {
        ((int8_t*)T_reshape1)[((((i1133 * 3584) + (i2100 * 128)) + i3100))] = ((int8_t)((int32_t*)compute1)[((((i1133 * 3584) + (i2100 * 128)) + i3100))]);
      }
    }
  }
  for (int32_t ax0202 = 0; ax0202 < 760; ++ax0202) {
    for (int32_t ax1207 = 0; ax1207 < 128; ++ax1207) {
      ((int8_t*)T_reshape)[(((ax0202 * 128) + ax1207))] = ((int8_t*)T_reshape1)[(((ax0202 * 128) + ax1207))];
    }
  }
  for (int32_t i033 = 0; i033 < 760; ++i033) {
    for (int32_t i1134 = 0; i1134 < 128; ++i1134) {
      ((int8_t*)T_reshape1)[(((i033 * 128) + i1134))] = ((int8_t*)T_reshape)[(((i033 * 128) + i1134))];
    }
  }
  for (int32_t ax0203 = 0; ax0203 < 95; ++ax0203) {
    for (int32_t ax1208 = 0; ax1208 < 8; ++ax1208) {
      for (int32_t ax2173 = 0; ax2173 < 16; ++ax2173) {
        for (int32_t ax3173 = 0; ax3173 < 8; ++ax3173) {
          ((int8_t*)T_reshape)[(((((ax0203 * 1024) + (ax1208 * 128)) + (ax2173 * 8)) + ax3173))] = ((int8_t*)T_reshape1)[(((((ax0203 * 1024) + (ax1208 * 128)) + (ax2173 * 8)) + ax3173))];
        }
      }
    }
  }
  for (int32_t ax0204 = 0; ax0204 < 95; ++ax0204) {
    for (int32_t ax1209 = 0; ax1209 < 16; ++ax1209) {
      for (int32_t ax2174 = 0; ax2174 < 8; ++ax2174) {
        for (int32_t ax3174 = 0; ax3174 < 8; ++ax3174) {
          ((int8_t*)T_reshape1)[(((((ax0204 * 1024) + (ax1209 * 64)) + (ax2174 * 8)) + ax3174))] = ((int8_t*)T_reshape)[(((((ax0204 * 1024) + (ax2174 * 128)) + (ax1209 * 8)) + ax3174))];
        }
      }
    }
  }
  for (int32_t ax0205 = 0; ax0205 < 95; ++ax0205) {
    for (int32_t ax2175 = 0; ax2175 < 16; ++ax2175) {
      for (int32_t ax3175 = 0; ax3175 < 8; ++ax3175) {
        for (int32_t ax433 = 0; ax433 < 8; ++ax433) {
          ((int8_t*)T_reshape)[(((((ax0205 * 1024) + (ax2175 * 64)) + (ax3175 * 8)) + ax433))] = ((int8_t*)T_reshape1)[(((((ax0205 * 1024) + (ax2175 * 64)) + (ax3175 * 8)) + ax433))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536870912, 12160, 0);
  for (int32_t ax0206 = 0; ax0206 < 512; ++ax0206) {
    for (int32_t ax1210 = 0; ax1210 < 128; ++ax1210) {
      ((int8_t*)T_reshape1)[(((ax0206 * 128) + ax1210))] = ((int8_t*)kernel_302)[(((ax0206 * 128) + ax1210))];
    }
  }
  for (int32_t ax0207 = 0; ax0207 < 64; ++ax0207) {
    for (int32_t ax1211 = 0; ax1211 < 8; ++ax1211) {
      for (int32_t ax2176 = 0; ax2176 < 16; ++ax2176) {
        for (int32_t ax3176 = 0; ax3176 < 8; ++ax3176) {
          ((int8_t*)T_reshape)[(((((ax0207 * 1024) + (ax1211 * 128)) + (ax2176 * 8)) + ax3176))] = ((int8_t*)T_reshape1)[(((((ax0207 * 1024) + (ax1211 * 128)) + (ax2176 * 8)) + ax3176))];
        }
      }
    }
  }
  for (int32_t ax0208 = 0; ax0208 < 64; ++ax0208) {
    for (int32_t ax1212 = 0; ax1212 < 16; ++ax1212) {
      for (int32_t ax2177 = 0; ax2177 < 8; ++ax2177) {
        for (int32_t ax3177 = 0; ax3177 < 8; ++ax3177) {
          ((int8_t*)T_reshape1)[(((((ax0208 * 1024) + (ax1212 * 64)) + (ax2177 * 8)) + ax3177))] = ((int8_t*)T_reshape)[(((((ax0208 * 1024) + (ax2177 * 128)) + (ax1212 * 8)) + ax3177))];
        }
      }
    }
  }
  for (int32_t ax0209 = 0; ax0209 < 64; ++ax0209) {
    for (int32_t ax2178 = 0; ax2178 < 16; ++ax2178) {
      for (int32_t ax3178 = 0; ax3178 < 8; ++ax3178) {
        for (int32_t ax434 = 0; ax434 < 8; ++ax434) {
          ((int8_t*)T_reshape)[(((((ax0209 * 1024) + (ax2178 * 64)) + (ax3178 * 8)) + ax434))] = ((int8_t*)T_reshape1)[(((((ax0209 * 1024) + (ax2178 * 64)) + (ax3178 * 8)) + ax434))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536936448, 8192, 0);
  for (int32_t i53 = 0; i53 < 95; ++i53) {
    for (int32_t x22 = 0; x22 < 64; ++x22) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i53 * 64) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 128, 0);
      (void)move(((((int64_t)(x22 * 64)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 128, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 16, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i53 * 16384) + (x22 * 256)));
    }
  }
  for (int32_t ax0210 = 0; ax0210 < 95; ++ax0210) {
    for (int32_t ax1213 = 0; ax1213 < 8; ++ax1213) {
      for (int32_t ax2179 = 0; ax2179 < 64; ++ax2179) {
        for (int32_t ax3179 = 0; ax3179 < 8; ++ax3179) {
          ((int32_t*)out)[(((((ax0210 * 4096) + (ax1213 * 512)) + (ax2179 * 8)) + ax3179))] = ((int32_t*)compute1)[(((((ax0210 * 4096) + (ax2179 * 64)) + (ax1213 * 8)) + ax3179))];
        }
      }
    }
  }
  for (int32_t ax0211 = 0; ax0211 < 755; ++ax0211) {
    for (int32_t ax1214 = 0; ax1214 < 512; ++ax1214) {
      ((int32_t*)compute1)[(((ax0211 * 512) + ax1214))] = ((int32_t*)out)[(((ax0211 * 512) + ax1214))];
    }
  }
  for (int32_t i034 = 0; i034 < 755; ++i034) {
    for (int32_t i1135 = 0; i1135 < 512; ++i1135) {
      ((int32_t*)pad_data)[(((i034 * 512) + i1135))] = ((int32_t*)compute1)[(((i034 * 512) + i1135))];
    }
  }
  for (int32_t ax1215 = 0; ax1215 < 27; ++ax1215) {
    for (int32_t ax2180 = 0; ax2180 < 27; ++ax2180) {
      for (int32_t ax3180 = 0; ax3180 < 512; ++ax3180) {
        ((int32_t*)compute1)[((((ax1215 * 13824) + (ax2180 * 512)) + ax3180))] = ((int32_t*)pad_data)[((((ax1215 * 14336) + (ax2180 * 512)) + ax3180))];
      }
    }
  }
  for (int32_t h269 = 0; h269 < 27; ++h269) {
    for (int32_t w135 = 0; w135 < 27; ++w135) {
      for (int32_t c155 = 0; c155 < 512; ++c155) {
        ((int32_t*)out1)[((((h269 * 13824) + (w135 * 512)) + c155))] = 10;
      }
    }
  }
  for (int32_t h270 = 0; h270 < 27; ++h270) {
    (void)load(compute1, (int64_t)537264128, 6912, (h270 * 13824));
    (void)load(out1, (int64_t)537329664, 6912, (h270 * 13824));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6912, (h270 * 55296));
  }
  for (int32_t h271 = 0; h271 < 27; ++h271) {
    for (int32_t w136 = 0; w136 < 27; ++w136) {
      for (int32_t c156 = 0; c156 < 512; ++c156) {
        ((int32_t*)compute1)[((((h271 * 13824) + (w136 * 512)) + c156))] = ((int32_t*)tensor_304)[(c156)];
      }
    }
  }
  for (int32_t h272 = 0; h272 < 27; ++h272) {
    (void)load(out, (int64_t)537264128, 6912, (h272 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h272 * 13824));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 6912, (h272 * 55296));
  }
  for (int32_t h273 = 0; h273 < 27; ++h273) {
    for (int32_t w137 = 0; w137 < 27; ++w137) {
      for (int32_t c157 = 0; c157 < 512; ++c157) {
        ((int32_t*)compute1)[((((h273 * 13824) + (w137 * 512)) + c157))] = 131072;
      }
    }
  }
  for (int32_t h274 = 0; h274 < 27; ++h274) {
    (void)load(pad_data, (int64_t)537264128, 6912, (h274 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h274 * 13824));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 6912, (h274 * 55296));
  }
  for (int32_t h275 = 0; h275 < 27; ++h275) {
    for (int32_t w138 = 0; w138 < 27; ++w138) {
      for (int32_t c158 = 0; c158 < 512; ++c158) {
        ((int32_t*)compute1)[((((h275 * 13824) + (w138 * 512)) + c158))] = 18;
      }
    }
  }
  for (int32_t h276 = 0; h276 < 27; ++h276) {
    (void)load(out1, (int64_t)537264128, 6912, (h276 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h276 * 13824));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6912, (h276 * 55296));
  }
  for (int32_t i1136 = 0; i1136 < 27; ++i1136) {
    for (int32_t i2101 = 0; i2101 < 27; ++i2101) {
      for (int32_t i3101 = 0; i3101 < 512; ++i3101) {
        int32_t _78 = ((int32_t*)out)[((((i1136 * 13824) + (i2101 * 512)) + i3101))];
        int32_t _79 = (_78) < (127) ? (_78) : (127);
        ((int32_t*)compute1)[((((i1136 * 13824) + (i2101 * 512)) + i3101))] = ((_79) > (-127) ? (_79) : (-127));
      }
    }
  }
  for (int32_t i1137 = 0; i1137 < 27; ++i1137) {
    for (int32_t i2102 = 0; i2102 < 27; ++i2102) {
      for (int32_t i3102 = 0; i3102 < 512; ++i3102) {
        ((int8_t*)pad_data)[((((i1137 * 13824) + (i2102 * 512)) + i3102))] = ((int8_t)((int32_t*)compute1)[((((i1137 * 13824) + (i2102 * 512)) + i3102))]);
      }
    }
  }
  for (int32_t i1138 = 0; i1138 < 27; ++i1138) {
    for (int32_t i2103 = 0; i2103 < 27; ++i2103) {
      for (int32_t i3103 = 0; i3103 < 512; ++i3103) {
        ((int32_t*)compute1)[((((i1138 * 13824) + (i2103 * 512)) + i3103))] = ((int32_t)((int8_t*)pad_data)[((((i1138 * 13824) + (i2103 * 512)) + i3103))]);
      }
    }
  }
  for (int32_t h277 = 0; h277 < 27; ++h277) {
    for (int32_t w139 = 0; w139 < 27; ++w139) {
      for (int32_t c159 = 0; c159 < 512; ++c159) {
        ((int32_t*)out1)[((((h277 * 13824) + (w139 * 512)) + c159))] = ((int32_t*)tensor_311)[(c159)];
      }
    }
  }
  for (int32_t h278 = 0; h278 < 27; ++h278) {
    (void)load(compute1, (int64_t)537264128, 6912, (h278 * 13824));
    (void)load(out1, (int64_t)537329664, 6912, (h278 * 13824));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6912, (h278 * 55296));
  }
  for (int32_t h279 = 0; h279 < 27; ++h279) {
    for (int32_t w140 = 0; w140 < 27; ++w140) {
      for (int32_t c160 = 0; c160 < 512; ++c160) {
        ((int32_t*)compute1)[((((h279 * 13824) + (w140 * 512)) + c160))] = ((int32_t*)tensor_312)[(c160)];
      }
    }
  }
  for (int32_t h280 = 0; h280 < 27; ++h280) {
    (void)load(out, (int64_t)537264128, 6912, (h280 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h280 * 13824));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 6912, (h280 * 55296));
  }
  for (int32_t h281 = 0; h281 < 27; ++h281) {
    for (int32_t w141 = 0; w141 < 27; ++w141) {
      for (int32_t c161 = 0; c161 < 512; ++c161) {
        ((int32_t*)compute1)[((((h281 * 13824) + (w141 * 512)) + c161))] = 8;
      }
    }
  }
  for (int32_t h282 = 0; h282 < 27; ++h282) {
    (void)load(pad_data, (int64_t)537264128, 6912, (h282 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h282 * 13824));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 6912, (h282 * 55296));
  }
  for (int32_t h283 = 0; h283 < 27; ++h283) {
    for (int32_t w142 = 0; w142 < 27; ++w142) {
      for (int32_t c162 = 0; c162 < 512; ++c162) {
        ((int32_t*)compute1)[((((h283 * 13824) + (w142 * 512)) + c162))] = 4;
      }
    }
  }
  for (int32_t h284 = 0; h284 < 27; ++h284) {
    (void)load(out1, (int64_t)537264128, 6912, (h284 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h284 * 13824));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6912, (h284 * 55296));
  }
  for (int32_t i1139 = 0; i1139 < 27; ++i1139) {
    for (int32_t i2104 = 0; i2104 < 27; ++i2104) {
      for (int32_t i3104 = 0; i3104 < 512; ++i3104) {
        int32_t _80 = ((int32_t*)out)[((((i1139 * 13824) + (i2104 * 512)) + i3104))];
        int32_t _81 = (_80) < (127) ? (_80) : (127);
        ((int32_t*)compute1)[((((i1139 * 13824) + (i2104 * 512)) + i3104))] = ((_81) > (-127) ? (_81) : (-127));
      }
    }
  }
  for (int32_t i1140 = 0; i1140 < 27; ++i1140) {
    for (int32_t i2105 = 0; i2105 < 27; ++i2105) {
      for (int32_t i3105 = 0; i3105 < 512; ++i3105) {
        ((int8_t*)pad_data)[((((i1140 * 13824) + (i2105 * 512)) + i3105))] = ((int8_t)((int32_t*)compute1)[((((i1140 * 13824) + (i2105 * 512)) + i3105))]);
      }
    }
  }
  for (int32_t i1141 = 0; i1141 < 27; ++i1141) {
    for (int32_t i2106 = 0; i2106 < 27; ++i2106) {
      for (int32_t i3106 = 0; i3106 < 512; ++i3106) {
        ((int32_t*)compute1)[((((i1141 * 13824) + (i2106 * 512)) + i3106))] = ((int32_t)((int8_t*)pad_data)[((((i1141 * 13824) + (i2106 * 512)) + i3106))]);
      }
    }
  }
  for (int32_t i1142 = 0; i1142 < 27; ++i1142) {
    for (int32_t i2107 = 0; i2107 < 27; ++i2107) {
      for (int32_t i3107 = 0; i3107 < 512; ++i3107) {
        ((int32_t*)out1)[((((i1142 * 13824) + (i2107 * 512)) + i3107))] = ((int32_t)((int8_t*)compute)[((((i1142 * 14336) + (i2107 * 512)) + i3107))]);
      }
    }
  }
  for (int32_t h285 = 0; h285 < 27; ++h285) {
    (void)load(compute1, (int64_t)537264128, 6912, (h285 * 13824));
    (void)load(out1, (int64_t)537329664, 6912, (h285 * 13824));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6912, (h285 * 55296));
  }
  for (int32_t h286 = 0; h286 < 27; ++h286) {
    for (int32_t w143 = 0; w143 < 27; ++w143) {
      for (int32_t c163 = 0; c163 < 512; ++c163) {
        ((int32_t*)compute1)[((((h286 * 13824) + (w143 * 512)) + c163))] = 0;
      }
    }
  }
  for (int32_t h287 = 0; h287 < 27; ++h287) {
    (void)load(out, (int64_t)537264128, 6912, (h287 * 13824));
    (void)load(compute1, (int64_t)537329664, 6912, (h287 * 13824));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 432, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 6912, (h287 * 55296));
  }
  for (int32_t i1143 = 0; i1143 < 27; ++i1143) {
    for (int32_t i2108 = 0; i2108 < 27; ++i2108) {
      for (int32_t i3108 = 0; i3108 < 512; ++i3108) {
        int32_t _82 = ((int32_t*)pad_data)[((((i1143 * 13824) + (i2108 * 512)) + i3108))];
        int32_t _83 = (_82) < (127) ? (_82) : (127);
        ((int32_t*)compute1)[((((i1143 * 13824) + (i2108 * 512)) + i3108))] = ((_83) > (-127) ? (_83) : (-127));
      }
    }
  }
  for (int32_t i1144 = 0; i1144 < 27; ++i1144) {
    for (int32_t i2109 = 0; i2109 < 27; ++i2109) {
      for (int32_t i3109 = 0; i3109 < 512; ++i3109) {
        ((int8_t*)compute)[((((i1144 * 13824) + (i2109 * 512)) + i3109))] = ((int8_t)((int32_t*)compute1)[((((i1144 * 13824) + (i2109 * 512)) + i3109))]);
      }
    }
  }
  for (int32_t o119 = 0; o119 < 14; ++o119) {
    for (int32_t o219 = 0; o219 < 14; ++o219) {
      for (int32_t c164 = 0; c164 < 512; ++c164) {
        ((int8_t*)T_reshape1)[((((o119 * 7168) + (o219 * 512)) + c164))] = ((int8_t*)compute)[((((o119 * 27648) + (o219 * 1024)) + c164))];
      }
    }
  }
  for (int32_t i035 = 0; i035 < 200; ++i035) {
    for (int32_t i1145 = 0; i1145 < 512; ++i1145) {
      ((int8_t*)T_reshape)[(((i035 * 512) + i1145))] = ((i035 < 196) ? ((int8_t*)T_reshape1)[(((i035 * 512) + i1145))] : (int8_t)0);
    }
  }
  for (int32_t ax0212 = 0; ax0212 < 25; ++ax0212) {
    for (int32_t ax1216 = 0; ax1216 < 8; ++ax1216) {
      for (int32_t ax2181 = 0; ax2181 < 64; ++ax2181) {
        for (int32_t ax3181 = 0; ax3181 < 8; ++ax3181) {
          ((int8_t*)T_reshape1)[(((((ax0212 * 4096) + (ax1216 * 512)) + (ax2181 * 8)) + ax3181))] = ((int8_t*)T_reshape)[(((((ax0212 * 4096) + (ax1216 * 512)) + (ax2181 * 8)) + ax3181))];
        }
      }
    }
  }
  for (int32_t ax0213 = 0; ax0213 < 25; ++ax0213) {
    for (int32_t ax1217 = 0; ax1217 < 64; ++ax1217) {
      for (int32_t ax2182 = 0; ax2182 < 8; ++ax2182) {
        for (int32_t ax3182 = 0; ax3182 < 8; ++ax3182) {
          ((int8_t*)T_reshape)[(((((ax0213 * 4096) + (ax1217 * 64)) + (ax2182 * 8)) + ax3182))] = ((int8_t*)T_reshape1)[(((((ax0213 * 4096) + (ax2182 * 512)) + (ax1217 * 8)) + ax3182))];
        }
      }
    }
  }
  for (int32_t ax0214 = 0; ax0214 < 25; ++ax0214) {
    for (int32_t ax2183 = 0; ax2183 < 64; ++ax2183) {
      for (int32_t ax3183 = 0; ax3183 < 8; ++ax3183) {
        for (int32_t ax435 = 0; ax435 < 8; ++ax435) {
          ((int8_t*)T_reshape1)[(((((ax0214 * 4096) + (ax2183 * 64)) + (ax3183 * 8)) + ax435))] = ((int8_t*)T_reshape)[(((((ax0214 * 4096) + (ax2183 * 64)) + (ax3183 * 8)) + ax435))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 12800, 0);
  for (int32_t ax0215 = 0; ax0215 < 256; ++ax0215) {
    for (int32_t ax1218 = 0; ax1218 < 512; ++ax1218) {
      ((int8_t*)T_reshape)[(((ax0215 * 512) + ax1218))] = ((int8_t*)kernel_327)[(((ax0215 * 512) + ax1218))];
    }
  }
  for (int32_t ax0216 = 0; ax0216 < 32; ++ax0216) {
    for (int32_t ax1219 = 0; ax1219 < 8; ++ax1219) {
      for (int32_t ax2184 = 0; ax2184 < 64; ++ax2184) {
        for (int32_t ax3184 = 0; ax3184 < 8; ++ax3184) {
          ((int8_t*)compute1)[(((((ax0216 * 4096) + (ax1219 * 512)) + (ax2184 * 8)) + ax3184))] = ((int8_t*)T_reshape)[(((((ax0216 * 4096) + (ax1219 * 512)) + (ax2184 * 8)) + ax3184))];
        }
      }
    }
  }
  for (int32_t ax0217 = 0; ax0217 < 32; ++ax0217) {
    for (int32_t ax1220 = 0; ax1220 < 64; ++ax1220) {
      for (int32_t ax2185 = 0; ax2185 < 8; ++ax2185) {
        for (int32_t ax3185 = 0; ax3185 < 8; ++ax3185) {
          ((int8_t*)T_reshape)[(((((ax0217 * 4096) + (ax1220 * 64)) + (ax2185 * 8)) + ax3185))] = ((int8_t*)compute1)[(((((ax0217 * 4096) + (ax2185 * 512)) + (ax1220 * 8)) + ax3185))];
        }
      }
    }
  }
  for (int32_t ax0218 = 0; ax0218 < 32; ++ax0218) {
    for (int32_t ax2186 = 0; ax2186 < 64; ++ax2186) {
      for (int32_t ax3186 = 0; ax3186 < 8; ++ax3186) {
        for (int32_t ax436 = 0; ax436 < 8; ++ax436) {
          ((int8_t*)compute1)[(((((ax0218 * 4096) + (ax2186 * 64)) + (ax3186 * 8)) + ax436))] = ((int8_t*)T_reshape)[(((((ax0218 * 4096) + (ax2186 * 64)) + (ax3186 * 8)) + ax436))];
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536936448, 16384, 0);
  for (int32_t i54 = 0; i54 < 25; ++i54) {
    for (int32_t x23 = 0; x23 < 32; ++x23) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i54 * 256) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x23 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i54 * 8192) + (x23 * 256)));
    }
  }
  for (int32_t ax0219 = 0; ax0219 < 25; ++ax0219) {
    for (int32_t ax1221 = 0; ax1221 < 8; ++ax1221) {
      for (int32_t ax2187 = 0; ax2187 < 32; ++ax2187) {
        for (int32_t ax3187 = 0; ax3187 < 8; ++ax3187) {
          ((int32_t*)out1)[(((((ax0219 * 2048) + (ax1221 * 256)) + (ax2187 * 8)) + ax3187))] = ((int32_t*)compute1)[(((((ax0219 * 2048) + (ax2187 * 64)) + (ax1221 * 8)) + ax3187))];
        }
      }
    }
  }
  for (int32_t ax0220 = 0; ax0220 < 196; ++ax0220) {
    for (int32_t ax1222 = 0; ax1222 < 256; ++ax1222) {
      ((int32_t*)compute1)[(((ax0220 * 256) + ax1222))] = ((int32_t*)out1)[(((ax0220 * 256) + ax1222))];
    }
  }
  for (int32_t i036 = 0; i036 < 196; ++i036) {
    for (int32_t i1146 = 0; i1146 < 256; ++i1146) {
      ((int32_t*)out)[(((i036 * 256) + i1146))] = ((int32_t*)compute1)[(((i036 * 256) + i1146))];
    }
  }
  for (int32_t ax1223 = 0; ax1223 < 14; ++ax1223) {
    for (int32_t ax2188 = 0; ax2188 < 14; ++ax2188) {
      for (int32_t ax3188 = 0; ax3188 < 256; ++ax3188) {
        ((int32_t*)compute1)[((((ax1223 * 3584) + (ax2188 * 256)) + ax3188))] = ((int32_t*)out)[((((ax1223 * 3584) + (ax2188 * 256)) + ax3188))];
      }
    }
  }
  for (int32_t h288 = 0; h288 < 14; ++h288) {
    for (int32_t w144 = 0; w144 < 14; ++w144) {
      for (int32_t c165 = 0; c165 < 256; ++c165) {
        ((int32_t*)pad_data)[((((h288 * 3584) + (w144 * 256)) + c165))] = 12;
      }
    }
  }
  for (int32_t h289 = 0; h289 < 14; ++h289) {
    (void)load(compute1, (int64_t)537264128, 1792, (h289 * 3584));
    (void)load(pad_data, (int64_t)537329664, 1792, (h289 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h289 * 14336));
  }
  for (int32_t h290 = 0; h290 < 14; ++h290) {
    for (int32_t w145 = 0; w145 < 14; ++w145) {
      for (int32_t c166 = 0; c166 < 256; ++c166) {
        ((int32_t*)compute1)[((((h290 * 3584) + (w145 * 256)) + c166))] = ((int32_t*)tensor_329)[(c166)];
      }
    }
  }
  for (int32_t h291 = 0; h291 < 14; ++h291) {
    (void)load(out1, (int64_t)537264128, 1792, (h291 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h291 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h291 * 14336));
  }
  for (int32_t h292 = 0; h292 < 14; ++h292) {
    for (int32_t w146 = 0; w146 < 14; ++w146) {
      for (int32_t c167 = 0; c167 < 256; ++c167) {
        ((int32_t*)compute1)[((((h292 * 3584) + (w146 * 256)) + c167))] = ((int32_t*)tensor_330)[(c167)];
      }
    }
  }
  for (int32_t h293 = 0; h293 < 14; ++h293) {
    (void)load(out, (int64_t)537264128, 1792, (h293 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h293 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h293 * 14336));
  }
  for (int32_t h294 = 0; h294 < 14; ++h294) {
    for (int32_t w147 = 0; w147 < 14; ++w147) {
      for (int32_t c168 = 0; c168 < 256; ++c168) {
        ((int32_t*)compute1)[((((h294 * 3584) + (w147 * 256)) + c168))] = 0;
      }
    }
  }
  for (int32_t h295 = 0; h295 < 14; ++h295) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h295 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h295 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h295 * 14336));
  }
  for (int32_t h296 = 0; h296 < 14; ++h296) {
    for (int32_t w148 = 0; w148 < 14; ++w148) {
      for (int32_t c169 = 0; c169 < 256; ++c169) {
        ((int32_t*)compute1)[((((h296 * 3584) + (w148 * 256)) + c169))] = 524288;
      }
    }
  }
  for (int32_t h297 = 0; h297 < 14; ++h297) {
    (void)load(out1, (int64_t)537264128, 1792, (h297 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h297 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h297 * 14336));
  }
  for (int32_t h298 = 0; h298 < 14; ++h298) {
    for (int32_t w149 = 0; w149 < 14; ++w149) {
      for (int32_t c170 = 0; c170 < 256; ++c170) {
        ((int32_t*)compute1)[((((h298 * 3584) + (w149 * 256)) + c170))] = 20;
      }
    }
  }
  for (int32_t h299 = 0; h299 < 14; ++h299) {
    (void)load(out, (int64_t)537264128, 1792, (h299 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h299 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h299 * 14336));
  }
  for (int32_t i1147 = 0; i1147 < 14; ++i1147) {
    for (int32_t i2110 = 0; i2110 < 14; ++i2110) {
      for (int32_t i3110 = 0; i3110 < 256; ++i3110) {
        int32_t _84 = ((int32_t*)pad_data)[((((i1147 * 3584) + (i2110 * 256)) + i3110))];
        int32_t _85 = (_84) < (127) ? (_84) : (127);
        ((int32_t*)compute1)[((((i1147 * 3584) + (i2110 * 256)) + i3110))] = ((_85) > (-127) ? (_85) : (-127));
      }
    }
  }
  for (int32_t i1148 = 0; i1148 < 14; ++i1148) {
    for (int32_t i2111 = 0; i2111 < 14; ++i2111) {
      for (int32_t i3111 = 0; i3111 < 256; ++i3111) {
        ((int8_t*)T_reshape1)[((((i1148 * 3584) + (i2111 * 256)) + i3111))] = ((int8_t)((int32_t*)compute1)[((((i1148 * 3584) + (i2111 * 256)) + i3111))]);
      }
    }
  }
  for (int32_t i1149 = 0; i1149 < 16; ++i1149) {
    for (int32_t i2112 = 0; i2112 < 16; ++i2112) {
      for (int32_t i3112 = 0; i3112 < 256; ++i3112) {
        ((int8_t*)T_reshape)[((((i1149 * 4096) + (i2112 * 256)) + i3112))] = (((((1 <= i1149) && (i1149 < 15)) && (1 <= i2112)) && (i2112 < 15)) ? ((int8_t*)T_reshape1)[(((((i1149 * 3584) + (i2112 * 256)) + i3112) - 3840))] : (int8_t)0);
      }
    }
  }
  for (int32_t o120 = 0; o120 < 14; ++o120) {
    for (int32_t o220 = 0; o220 < 14; ++o220) {
      for (int32_t k17 = 0; k17 < 3; ++k17) {
        for (int32_t k27 = 0; k27 < 3; ++k27) {
          for (int32_t c171 = 0; c171 < 256; ++c171) {
            ((int8_t*)compute1)[((((((o120 * 32256) + (o220 * 2304)) + (k17 * 768)) + (k27 * 256)) + c171))] = ((int8_t*)T_reshape)[((((((k17 * 4096) + (o120 * 4096)) + (k27 * 256)) + (o220 * 256)) + c171))];
          }
        }
      }
    }
  }
  for (int32_t ax0221 = 0; ax0221 < 196; ++ax0221) {
    for (int32_t ax1224 = 0; ax1224 < 2304; ++ax1224) {
      ((int8_t*)out1)[(((ax0221 * 2304) + ax1224))] = ((int8_t*)compute1)[(((ax0221 * 2304) + ax1224))];
    }
  }
  for (int32_t i037 = 0; i037 < 200; ++i037) {
    for (int32_t i1150 = 0; i1150 < 2304; ++i1150) {
      ((int8_t*)compute1)[(((i037 * 2304) + i1150))] = ((i037 < 196) ? ((int8_t*)out1)[(((i037 * 2304) + i1150))] : (int8_t)0);
    }
  }
  for (int32_t ax0222 = 0; ax0222 < 25; ++ax0222) {
    for (int32_t ax1225 = 0; ax1225 < 8; ++ax1225) {
      for (int32_t ax2189 = 0; ax2189 < 288; ++ax2189) {
        for (int32_t ax3189 = 0; ax3189 < 8; ++ax3189) {
          ((int8_t*)out)[(((((ax0222 * 18432) + (ax1225 * 2304)) + (ax2189 * 8)) + ax3189))] = ((int8_t*)compute1)[(((((ax0222 * 18432) + (ax1225 * 2304)) + (ax2189 * 8)) + ax3189))];
        }
      }
    }
  }
  for (int32_t ax0223 = 0; ax0223 < 25; ++ax0223) {
    for (int32_t ax1226 = 0; ax1226 < 288; ++ax1226) {
      for (int32_t ax2190 = 0; ax2190 < 8; ++ax2190) {
        for (int32_t ax3190 = 0; ax3190 < 8; ++ax3190) {
          ((int8_t*)compute1)[(((((ax0223 * 18432) + (ax1226 * 64)) + (ax2190 * 8)) + ax3190))] = ((int8_t*)out)[(((((ax0223 * 18432) + (ax2190 * 2304)) + (ax1226 * 8)) + ax3190))];
        }
      }
    }
  }
  for (int32_t ax0224 = 0; ax0224 < 25; ++ax0224) {
    for (int32_t ax1227 = 0; ax1227 < 4; ++ax1227) {
      for (int32_t ax2191 = 0; ax2191 < 72; ++ax2191) {
        for (int32_t ax3191 = 0; ax3191 < 8; ++ax3191) {
          for (int32_t ax437 = 0; ax437 < 8; ++ax437) {
            ((int8_t*)pad_data)[((((((ax0224 * 18432) + (ax1227 * 4608)) + (ax2191 * 64)) + (ax3191 * 8)) + ax437))] = ((int8_t*)compute1)[((((((ax0224 * 18432) + (ax1227 * 4608)) + (ax2191 * 64)) + (ax3191 * 8)) + ax437))];
          }
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 57600, 0);
  for (int32_t ax0225 = 0; ax0225 < 256; ++ax0225) {
    for (int32_t ax1228 = 0; ax1228 < 2304; ++ax1228) {
      ((int8_t*)compute1)[(((ax0225 * 2304) + ax1228))] = ((int8_t*)kernel_337)[(((ax0225 * 2304) + ax1228))];
    }
  }
  for (int32_t ax0226 = 0; ax0226 < 32; ++ax0226) {
    for (int32_t ax1229 = 0; ax1229 < 8; ++ax1229) {
      for (int32_t ax2192 = 0; ax2192 < 288; ++ax2192) {
        for (int32_t ax3192 = 0; ax3192 < 8; ++ax3192) {
          ((int8_t*)out1)[(((((ax0226 * 18432) + (ax1229 * 2304)) + (ax2192 * 8)) + ax3192))] = ((int8_t*)compute1)[(((((ax0226 * 18432) + (ax1229 * 2304)) + (ax2192 * 8)) + ax3192))];
        }
      }
    }
  }
  for (int32_t ax0227 = 0; ax0227 < 32; ++ax0227) {
    for (int32_t ax1230 = 0; ax1230 < 288; ++ax1230) {
      for (int32_t ax2193 = 0; ax2193 < 8; ++ax2193) {
        for (int32_t ax3193 = 0; ax3193 < 8; ++ax3193) {
          ((int8_t*)compute1)[(((((ax0227 * 18432) + (ax1230 * 64)) + (ax2193 * 8)) + ax3193))] = ((int8_t*)out1)[(((((ax0227 * 18432) + (ax2193 * 2304)) + (ax1230 * 8)) + ax3193))];
        }
      }
    }
  }
  for (int32_t ax0228 = 0; ax0228 < 32; ++ax0228) {
    for (int32_t ax1231 = 0; ax1231 < 4; ++ax1231) {
      for (int32_t ax2194 = 0; ax2194 < 72; ++ax2194) {
        for (int32_t ax3194 = 0; ax3194 < 8; ++ax3194) {
          for (int32_t ax438 = 0; ax438 < 8; ++ax438) {
            ((int8_t*)out)[((((((ax0228 * 18432) + (ax1231 * 4608)) + (ax2194 * 64)) + (ax3194 * 8)) + ax438))] = ((int8_t*)compute1)[((((((ax0228 * 18432) + (ax1231 * 4608)) + (ax2194 * 64)) + (ax3194 * 8)) + ax438))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 73728, 0);
  for (int32_t i55 = 0; i55 < 25; ++i55) {
    for (int32_t x24 = 0; x24 < 32; ++x24) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k04 = 0; k04 < 4; ++k04) {
        (void)move(((((int64_t)((i55 * 1152) + (k04 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x24 * 1152) + (k04 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute1, (int64_t)537264128, 32, ((i55 * 8192) + (x24 * 256)));
    }
  }
  for (int32_t ax0229 = 0; ax0229 < 25; ++ax0229) {
    for (int32_t ax1232 = 0; ax1232 < 8; ++ax1232) {
      for (int32_t ax2195 = 0; ax2195 < 32; ++ax2195) {
        for (int32_t ax3195 = 0; ax3195 < 8; ++ax3195) {
          ((int32_t*)pad_data)[(((((ax0229 * 2048) + (ax1232 * 256)) + (ax2195 * 8)) + ax3195))] = ((int32_t*)compute1)[(((((ax0229 * 2048) + (ax2195 * 64)) + (ax1232 * 8)) + ax3195))];
        }
      }
    }
  }
  for (int32_t ax0230 = 0; ax0230 < 196; ++ax0230) {
    for (int32_t ax1233 = 0; ax1233 < 256; ++ax1233) {
      ((int32_t*)compute1)[(((ax0230 * 256) + ax1233))] = ((int32_t*)pad_data)[(((ax0230 * 256) + ax1233))];
    }
  }
  for (int32_t i038 = 0; i038 < 196; ++i038) {
    for (int32_t i1151 = 0; i1151 < 256; ++i1151) {
      ((int32_t*)out1)[(((i038 * 256) + i1151))] = ((int32_t*)compute1)[(((i038 * 256) + i1151))];
    }
  }
  for (int32_t ax1234 = 0; ax1234 < 14; ++ax1234) {
    for (int32_t ax2196 = 0; ax2196 < 14; ++ax2196) {
      for (int32_t ax3196 = 0; ax3196 < 256; ++ax3196) {
        ((int32_t*)compute1)[((((ax1234 * 3584) + (ax2196 * 256)) + ax3196))] = ((int32_t*)out1)[((((ax1234 * 3584) + (ax2196 * 256)) + ax3196))];
      }
    }
  }
  for (int32_t h300 = 0; h300 < 14; ++h300) {
    for (int32_t w150 = 0; w150 < 14; ++w150) {
      for (int32_t c172 = 0; c172 < 256; ++c172) {
        ((int32_t*)out)[((((h300 * 3584) + (w150 * 256)) + c172))] = ((int32_t*)tensor_338)[(c172)];
      }
    }
  }
  for (int32_t h301 = 0; h301 < 14; ++h301) {
    (void)load(compute1, (int64_t)537264128, 1792, (h301 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h301 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h301 * 14336));
  }
  for (int32_t h302 = 0; h302 < 14; ++h302) {
    for (int32_t w151 = 0; w151 < 14; ++w151) {
      for (int32_t c173 = 0; c173 < 256; ++c173) {
        ((int32_t*)compute1)[((((h302 * 3584) + (w151 * 256)) + c173))] = 0;
      }
    }
  }
  for (int32_t h303 = 0; h303 < 14; ++h303) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h303 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h303 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h303 * 14336));
  }
  for (int32_t h304 = 0; h304 < 14; ++h304) {
    for (int32_t w152 = 0; w152 < 14; ++w152) {
      for (int32_t c174 = 0; c174 < 256; ++c174) {
        ((int32_t*)compute1)[((((h304 * 3584) + (w152 * 256)) + c174))] = 128;
      }
    }
  }
  for (int32_t h305 = 0; h305 < 14; ++h305) {
    (void)load(out1, (int64_t)537264128, 1792, (h305 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h305 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h305 * 14336));
  }
  for (int32_t h306 = 0; h306 < 14; ++h306) {
    for (int32_t w153 = 0; w153 < 14; ++w153) {
      for (int32_t c175 = 0; c175 < 256; ++c175) {
        ((int32_t*)compute1)[((((h306 * 3584) + (w153 * 256)) + c175))] = 8;
      }
    }
  }
  for (int32_t h307 = 0; h307 < 14; ++h307) {
    (void)load(out, (int64_t)537264128, 1792, (h307 * 3584));
    (void)load(compute1, (int64_t)537329664, 1792, (h307 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h307 * 14336));
  }
  for (int32_t i1152 = 0; i1152 < 14; ++i1152) {
    for (int32_t i2113 = 0; i2113 < 14; ++i2113) {
      for (int32_t i3113 = 0; i3113 < 256; ++i3113) {
        int32_t _86 = ((int32_t*)pad_data)[((((i1152 * 3584) + (i2113 * 256)) + i3113))];
        int32_t _87 = (_86) < (127) ? (_86) : (127);
        ((int32_t*)compute1)[((((i1152 * 3584) + (i2113 * 256)) + i3113))] = ((_87) > (-127) ? (_87) : (-127));
      }
    }
  }
  for (int32_t i1153 = 0; i1153 < 14; ++i1153) {
    for (int32_t i2114 = 0; i2114 < 14; ++i2114) {
      for (int32_t i3114 = 0; i3114 < 256; ++i3114) {
        ((int8_t*)T_reshape1)[((((i1153 * 3584) + (i2114 * 256)) + i3114))] = ((int8_t)((int32_t*)compute1)[((((i1153 * 3584) + (i2114 * 256)) + i3114))]);
      }
    }
  }
  for (int32_t o121 = 0; o121 < 14; ++o121) {
    for (int32_t o221 = 0; o221 < 14; ++o221) {
      for (int32_t c176 = 0; c176 < 256; ++c176) {
        ((int8_t*)T_reshape)[((((o121 * 3584) + (o221 * 256)) + c176))] = ((int8_t*)T_reshape1)[((((o121 * 3584) + (o221 * 256)) + c176))];
      }
    }
  }
  for (int32_t ax0231 = 0; ax0231 < 196; ++ax0231) {
    for (int32_t ax1235 = 0; ax1235 < 256; ++ax1235) {
      ((int8_t*)T_reshape1)[(((ax0231 * 256) + ax1235))] = ((int8_t*)T_reshape)[(((ax0231 * 256) + ax1235))];
    }
  }
  for (int32_t i039 = 0; i039 < 200; ++i039) {
    for (int32_t i1154 = 0; i1154 < 256; ++i1154) {
      ((int8_t*)T_reshape)[(((i039 * 256) + i1154))] = ((i039 < 196) ? ((int8_t*)T_reshape1)[(((i039 * 256) + i1154))] : (int8_t)0);
    }
  }
  for (int32_t ax0232 = 0; ax0232 < 25; ++ax0232) {
    for (int32_t ax1236 = 0; ax1236 < 8; ++ax1236) {
      for (int32_t ax2197 = 0; ax2197 < 32; ++ax2197) {
        for (int32_t ax3197 = 0; ax3197 < 8; ++ax3197) {
          ((int8_t*)T_reshape1)[(((((ax0232 * 2048) + (ax1236 * 256)) + (ax2197 * 8)) + ax3197))] = ((int8_t*)T_reshape)[(((((ax0232 * 2048) + (ax1236 * 256)) + (ax2197 * 8)) + ax3197))];
        }
      }
    }
  }
  for (int32_t ax0233 = 0; ax0233 < 25; ++ax0233) {
    for (int32_t ax1237 = 0; ax1237 < 32; ++ax1237) {
      for (int32_t ax2198 = 0; ax2198 < 8; ++ax2198) {
        for (int32_t ax3198 = 0; ax3198 < 8; ++ax3198) {
          ((int8_t*)T_reshape)[(((((ax0233 * 2048) + (ax1237 * 64)) + (ax2198 * 8)) + ax3198))] = ((int8_t*)T_reshape1)[(((((ax0233 * 2048) + (ax2198 * 256)) + (ax1237 * 8)) + ax3198))];
        }
      }
    }
  }
  for (int32_t ax0234 = 0; ax0234 < 25; ++ax0234) {
    for (int32_t ax2199 = 0; ax2199 < 32; ++ax2199) {
      for (int32_t ax3199 = 0; ax3199 < 8; ++ax3199) {
        for (int32_t ax439 = 0; ax439 < 8; ++ax439) {
          ((int8_t*)T_reshape1)[(((((ax0234 * 2048) + (ax2199 * 64)) + (ax3199 * 8)) + ax439))] = ((int8_t*)T_reshape)[(((((ax0234 * 2048) + (ax2199 * 64)) + (ax3199 * 8)) + ax439))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 6400, 0);
  for (int32_t ax0235 = 0; ax0235 < 1024; ++ax0235) {
    for (int32_t ax1238 = 0; ax1238 < 256; ++ax1238) {
      ((int8_t*)compute1)[(((ax0235 * 256) + ax1238))] = ((int8_t*)kernel_345)[(((ax0235 * 256) + ax1238))];
    }
  }
  for (int32_t ax0236 = 0; ax0236 < 128; ++ax0236) {
    for (int32_t ax1239 = 0; ax1239 < 8; ++ax1239) {
      for (int32_t ax2200 = 0; ax2200 < 32; ++ax2200) {
        for (int32_t ax3200 = 0; ax3200 < 8; ++ax3200) {
          ((int8_t*)out1)[(((((ax0236 * 2048) + (ax1239 * 256)) + (ax2200 * 8)) + ax3200))] = ((int8_t*)compute1)[(((((ax0236 * 2048) + (ax1239 * 256)) + (ax2200 * 8)) + ax3200))];
        }
      }
    }
  }
  for (int32_t ax0237 = 0; ax0237 < 128; ++ax0237) {
    for (int32_t ax1240 = 0; ax1240 < 32; ++ax1240) {
      for (int32_t ax2201 = 0; ax2201 < 8; ++ax2201) {
        for (int32_t ax3201 = 0; ax3201 < 8; ++ax3201) {
          ((int8_t*)compute1)[(((((ax0237 * 2048) + (ax1240 * 64)) + (ax2201 * 8)) + ax3201))] = ((int8_t*)out1)[(((((ax0237 * 2048) + (ax2201 * 256)) + (ax1240 * 8)) + ax3201))];
        }
      }
    }
  }
  for (int32_t ax0238 = 0; ax0238 < 128; ++ax0238) {
    for (int32_t ax2202 = 0; ax2202 < 32; ++ax2202) {
      for (int32_t ax3202 = 0; ax3202 < 8; ++ax3202) {
        for (int32_t ax440 = 0; ax440 < 8; ++ax440) {
          ((int8_t*)out)[(((((ax0238 * 2048) + (ax2202 * 64)) + (ax3202 * 8)) + ax440))] = ((int8_t*)compute1)[(((((ax0238 * 2048) + (ax2202 * 64)) + (ax3202 * 8)) + ax440))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 32768, 0);
  for (int32_t i56 = 0; i56 < 25; ++i56) {
    for (int32_t x25 = 0; x25 < 128; ++x25) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i56 * 128) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x25 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i56 * 32768) + (x25 * 256)));
    }
  }
  for (int32_t ax0239 = 0; ax0239 < 25; ++ax0239) {
    for (int32_t ax1241 = 0; ax1241 < 8; ++ax1241) {
      for (int32_t ax2203 = 0; ax2203 < 128; ++ax2203) {
        for (int32_t ax3203 = 0; ax3203 < 8; ++ax3203) {
          ((int32_t*)pad_data)[(((((ax0239 * 8192) + (ax1241 * 1024)) + (ax2203 * 8)) + ax3203))] = ((int32_t*)compute1)[(((((ax0239 * 8192) + (ax2203 * 64)) + (ax1241 * 8)) + ax3203))];
        }
      }
    }
  }
  for (int32_t ax0240 = 0; ax0240 < 196; ++ax0240) {
    for (int32_t ax1242 = 0; ax1242 < 1024; ++ax1242) {
      ((int32_t*)compute1)[(((ax0240 * 1024) + ax1242))] = ((int32_t*)pad_data)[(((ax0240 * 1024) + ax1242))];
    }
  }
  for (int32_t i040 = 0; i040 < 196; ++i040) {
    for (int32_t i1155 = 0; i1155 < 1024; ++i1155) {
      ((int32_t*)out1)[(((i040 * 1024) + i1155))] = ((int32_t*)compute1)[(((i040 * 1024) + i1155))];
    }
  }
  for (int32_t ax1243 = 0; ax1243 < 14; ++ax1243) {
    for (int32_t ax2204 = 0; ax2204 < 14; ++ax2204) {
      for (int32_t ax3204 = 0; ax3204 < 1024; ++ax3204) {
        ((int32_t*)compute1)[((((ax1243 * 14336) + (ax2204 * 1024)) + ax3204))] = ((int32_t*)out1)[((((ax1243 * 14336) + (ax2204 * 1024)) + ax3204))];
      }
    }
  }
  for (int32_t h308 = 0; h308 < 14; ++h308) {
    for (int32_t w154 = 0; w154 < 14; ++w154) {
      for (int32_t c177 = 0; c177 < 1024; ++c177) {
        ((int32_t*)out)[((((h308 * 14336) + (w154 * 1024)) + c177))] = 12;
      }
    }
  }
  for (int32_t h309 = 0; h309 < 14; ++h309) {
    (void)load(compute1, (int64_t)537264128, 7168, (h309 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h309 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h309 * 57344));
  }
  for (int32_t h310 = 0; h310 < 14; ++h310) {
    for (int32_t w155 = 0; w155 < 14; ++w155) {
      for (int32_t c178 = 0; c178 < 1024; ++c178) {
        ((int32_t*)compute1)[((((h310 * 14336) + (w155 * 1024)) + c178))] = ((int32_t*)tensor_347)[(c178)];
      }
    }
  }
  for (int32_t h311 = 0; h311 < 14; ++h311) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h311 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h311 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h311 * 57344));
  }
  for (int32_t h312 = 0; h312 < 14; ++h312) {
    for (int32_t w156 = 0; w156 < 14; ++w156) {
      for (int32_t c179 = 0; c179 < 1024; ++c179) {
        ((int32_t*)compute1)[((((h312 * 14336) + (w156 * 1024)) + c179))] = 262144;
      }
    }
  }
  for (int32_t h313 = 0; h313 < 14; ++h313) {
    (void)load(out1, (int64_t)537264128, 7168, (h313 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h313 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h313 * 57344));
  }
  for (int32_t h314 = 0; h314 < 14; ++h314) {
    for (int32_t w157 = 0; w157 < 14; ++w157) {
      for (int32_t c180 = 0; c180 < 1024; ++c180) {
        ((int32_t*)compute1)[((((h314 * 14336) + (w157 * 1024)) + c180))] = 19;
      }
    }
  }
  for (int32_t h315 = 0; h315 < 14; ++h315) {
    (void)load(out, (int64_t)537264128, 7168, (h315 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h315 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h315 * 57344));
  }
  for (int32_t i1156 = 0; i1156 < 14; ++i1156) {
    for (int32_t i2115 = 0; i2115 < 14; ++i2115) {
      for (int32_t i3115 = 0; i3115 < 1024; ++i3115) {
        int32_t _88 = ((int32_t*)pad_data)[((((i1156 * 14336) + (i2115 * 1024)) + i3115))];
        int32_t _89 = (_88) < (127) ? (_88) : (127);
        ((int32_t*)compute1)[((((i1156 * 14336) + (i2115 * 1024)) + i3115))] = ((_89) > (-127) ? (_89) : (-127));
      }
    }
  }
  for (int32_t i1157 = 0; i1157 < 14; ++i1157) {
    for (int32_t i2116 = 0; i2116 < 14; ++i2116) {
      for (int32_t i3116 = 0; i3116 < 1024; ++i3116) {
        ((int8_t*)out1)[((((i1157 * 14336) + (i2116 * 1024)) + i3116))] = ((int8_t)((int32_t*)compute1)[((((i1157 * 14336) + (i2116 * 1024)) + i3116))]);
      }
    }
  }
  for (int32_t i1158 = 0; i1158 < 14; ++i1158) {
    for (int32_t i2117 = 0; i2117 < 14; ++i2117) {
      for (int32_t i3117 = 0; i3117 < 1024; ++i3117) {
        ((int32_t*)compute1)[((((i1158 * 14336) + (i2117 * 1024)) + i3117))] = ((int32_t)((int8_t*)out1)[((((i1158 * 14336) + (i2117 * 1024)) + i3117))]);
      }
    }
  }
  for (int32_t h316 = 0; h316 < 14; ++h316) {
    for (int32_t w158 = 0; w158 < 14; ++w158) {
      for (int32_t c181 = 0; c181 < 1024; ++c181) {
        ((int32_t*)out)[((((h316 * 14336) + (w158 * 1024)) + c181))] = ((int32_t*)tensor_354)[(c181)];
      }
    }
  }
  for (int32_t h317 = 0; h317 < 14; ++h317) {
    (void)load(compute1, (int64_t)537264128, 7168, (h317 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h317 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h317 * 57344));
  }
  for (int32_t h318 = 0; h318 < 14; ++h318) {
    for (int32_t w159 = 0; w159 < 14; ++w159) {
      for (int32_t c182 = 0; c182 < 1024; ++c182) {
        ((int32_t*)compute1)[((((h318 * 14336) + (w159 * 1024)) + c182))] = ((int32_t*)tensor_355)[(c182)];
      }
    }
  }
  for (int32_t h319 = 0; h319 < 14; ++h319) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h319 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h319 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h319 * 57344));
  }
  for (int32_t h320 = 0; h320 < 14; ++h320) {
    for (int32_t w160 = 0; w160 < 14; ++w160) {
      for (int32_t c183 = 0; c183 < 1024; ++c183) {
        ((int32_t*)compute1)[((((h320 * 14336) + (w160 * 1024)) + c183))] = 8;
      }
    }
  }
  for (int32_t h321 = 0; h321 < 14; ++h321) {
    (void)load(out1, (int64_t)537264128, 7168, (h321 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h321 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h321 * 57344));
  }
  for (int32_t h322 = 0; h322 < 14; ++h322) {
    for (int32_t w161 = 0; w161 < 14; ++w161) {
      for (int32_t c184 = 0; c184 < 1024; ++c184) {
        ((int32_t*)compute1)[((((h322 * 14336) + (w161 * 1024)) + c184))] = 4;
      }
    }
  }
  for (int32_t h323 = 0; h323 < 14; ++h323) {
    (void)load(out, (int64_t)537264128, 7168, (h323 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h323 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h323 * 57344));
  }
  for (int32_t i1159 = 0; i1159 < 14; ++i1159) {
    for (int32_t i2118 = 0; i2118 < 14; ++i2118) {
      for (int32_t i3118 = 0; i3118 < 1024; ++i3118) {
        int32_t _90 = ((int32_t*)pad_data)[((((i1159 * 14336) + (i2118 * 1024)) + i3118))];
        int32_t _91 = (_90) < (127) ? (_90) : (127);
        ((int32_t*)compute1)[((((i1159 * 14336) + (i2118 * 1024)) + i3118))] = ((_91) > (-127) ? (_91) : (-127));
      }
    }
  }
  for (int32_t i1160 = 0; i1160 < 14; ++i1160) {
    for (int32_t i2119 = 0; i2119 < 14; ++i2119) {
      for (int32_t i3119 = 0; i3119 < 1024; ++i3119) {
        ((int8_t*)out1)[((((i1160 * 14336) + (i2119 * 1024)) + i3119))] = ((int8_t)((int32_t*)compute1)[((((i1160 * 14336) + (i2119 * 1024)) + i3119))]);
      }
    }
  }
  for (int32_t i1161 = 0; i1161 < 14; ++i1161) {
    for (int32_t i2120 = 0; i2120 < 14; ++i2120) {
      for (int32_t i3120 = 0; i3120 < 1024; ++i3120) {
        ((int32_t*)compute1)[((((i1161 * 14336) + (i2120 * 1024)) + i3120))] = ((int32_t)((int8_t*)out1)[((((i1161 * 14336) + (i2120 * 1024)) + i3120))]);
      }
    }
  }
  for (int32_t o122 = 0; o122 < 14; ++o122) {
    for (int32_t o222 = 0; o222 < 14; ++o222) {
      for (int32_t c185 = 0; c185 < 512; ++c185) {
        ((int8_t*)T_reshape1)[((((o122 * 7168) + (o222 * 512)) + c185))] = ((int8_t*)compute)[((((o122 * 27648) + (o222 * 1024)) + c185))];
      }
    }
  }
  for (int32_t ax0241 = 0; ax0241 < 196; ++ax0241) {
    for (int32_t ax1244 = 0; ax1244 < 512; ++ax1244) {
      ((int8_t*)T_reshape)[(((ax0241 * 512) + ax1244))] = ((int8_t*)T_reshape1)[(((ax0241 * 512) + ax1244))];
    }
  }
  for (int32_t i041 = 0; i041 < 200; ++i041) {
    for (int32_t i1162 = 0; i1162 < 512; ++i1162) {
      ((int8_t*)T_reshape1)[(((i041 * 512) + i1162))] = ((i041 < 196) ? ((int8_t*)T_reshape)[(((i041 * 512) + i1162))] : (int8_t)0);
    }
  }
  for (int32_t ax0242 = 0; ax0242 < 25; ++ax0242) {
    for (int32_t ax1245 = 0; ax1245 < 8; ++ax1245) {
      for (int32_t ax2205 = 0; ax2205 < 64; ++ax2205) {
        for (int32_t ax3205 = 0; ax3205 < 8; ++ax3205) {
          ((int8_t*)T_reshape)[(((((ax0242 * 4096) + (ax1245 * 512)) + (ax2205 * 8)) + ax3205))] = ((int8_t*)T_reshape1)[(((((ax0242 * 4096) + (ax1245 * 512)) + (ax2205 * 8)) + ax3205))];
        }
      }
    }
  }
  for (int32_t ax0243 = 0; ax0243 < 25; ++ax0243) {
    for (int32_t ax1246 = 0; ax1246 < 64; ++ax1246) {
      for (int32_t ax2206 = 0; ax2206 < 8; ++ax2206) {
        for (int32_t ax3206 = 0; ax3206 < 8; ++ax3206) {
          ((int8_t*)T_reshape1)[(((((ax0243 * 4096) + (ax1246 * 64)) + (ax2206 * 8)) + ax3206))] = ((int8_t*)T_reshape)[(((((ax0243 * 4096) + (ax2206 * 512)) + (ax1246 * 8)) + ax3206))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 12800, 0);
  for (int32_t ax0244 = 0; ax0244 < 1024; ++ax0244) {
    for (int32_t ax1247 = 0; ax1247 < 512; ++ax1247) {
      ((int8_t*)compute)[(((ax0244 * 512) + ax1247))] = ((int8_t*)kernel_363)[(((ax0244 * 512) + ax1247))];
    }
  }
  for (int32_t ax0245 = 0; ax0245 < 128; ++ax0245) {
    for (int32_t ax1248 = 0; ax1248 < 8; ++ax1248) {
      for (int32_t ax2207 = 0; ax2207 < 64; ++ax2207) {
        for (int32_t ax3207 = 0; ax3207 < 8; ++ax3207) {
          ((int8_t*)out)[(((((ax0245 * 4096) + (ax1248 * 512)) + (ax2207 * 8)) + ax3207))] = ((int8_t*)compute)[(((((ax0245 * 4096) + (ax1248 * 512)) + (ax2207 * 8)) + ax3207))];
        }
      }
    }
  }
  for (int32_t ax0246 = 0; ax0246 < 128; ++ax0246) {
    for (int32_t ax1249 = 0; ax1249 < 64; ++ax1249) {
      for (int32_t ax2208 = 0; ax2208 < 8; ++ax2208) {
        for (int32_t ax3208 = 0; ax3208 < 8; ++ax3208) {
          ((int8_t*)compute)[(((((ax0246 * 4096) + (ax1249 * 64)) + (ax2208 * 8)) + ax3208))] = ((int8_t*)out)[(((((ax0246 * 4096) + (ax2208 * 512)) + (ax1249 * 8)) + ax3208))];
        }
      }
    }
  }
  for (int32_t ax0247 = 0; ax0247 < 128; ++ax0247) {
    for (int32_t ax2209 = 0; ax2209 < 64; ++ax2209) {
      for (int32_t ax3209 = 0; ax3209 < 8; ++ax3209) {
        for (int32_t ax441 = 0; ax441 < 8; ++ax441) {
          ((int8_t*)pad_data)[(((((ax0247 * 4096) + (ax2209 * 64)) + (ax3209 * 8)) + ax441))] = ((int8_t*)compute)[(((((ax0247 * 4096) + (ax2209 * 64)) + (ax3209 * 8)) + ax441))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536936448, 65536, 0);
  for (int32_t i57 = 0; i57 < 25; ++i57) {
    for (int32_t x26 = 0; x26 < 128; ++x26) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i57 * 256) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x26 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(out1, (int64_t)537264128, 32, ((i57 * 32768) + (x26 * 256)));
    }
  }
  for (int32_t ax0248 = 0; ax0248 < 25; ++ax0248) {
    for (int32_t ax1250 = 0; ax1250 < 8; ++ax1250) {
      for (int32_t ax2210 = 0; ax2210 < 128; ++ax2210) {
        for (int32_t ax3210 = 0; ax3210 < 8; ++ax3210) {
          ((int32_t*)out)[(((((ax0248 * 8192) + (ax1250 * 1024)) + (ax2210 * 8)) + ax3210))] = ((int32_t*)out1)[(((((ax0248 * 8192) + (ax2210 * 64)) + (ax1250 * 8)) + ax3210))];
        }
      }
    }
  }
  for (int32_t ax0249 = 0; ax0249 < 196; ++ax0249) {
    for (int32_t ax1251 = 0; ax1251 < 1024; ++ax1251) {
      ((int32_t*)compute)[(((ax0249 * 1024) + ax1251))] = ((int32_t*)out)[(((ax0249 * 1024) + ax1251))];
    }
  }
  for (int32_t i042 = 0; i042 < 196; ++i042) {
    for (int32_t i1163 = 0; i1163 < 1024; ++i1163) {
      ((int32_t*)pad_data)[(((i042 * 1024) + i1163))] = ((int32_t*)compute)[(((i042 * 1024) + i1163))];
    }
  }
  for (int32_t ax1252 = 0; ax1252 < 14; ++ax1252) {
    for (int32_t ax2211 = 0; ax2211 < 14; ++ax2211) {
      for (int32_t ax3211 = 0; ax3211 < 1024; ++ax3211) {
        ((int32_t*)compute)[((((ax1252 * 14336) + (ax2211 * 1024)) + ax3211))] = ((int32_t*)pad_data)[((((ax1252 * 14336) + (ax2211 * 1024)) + ax3211))];
      }
    }
  }
  for (int32_t h324 = 0; h324 < 14; ++h324) {
    for (int32_t w162 = 0; w162 < 14; ++w162) {
      for (int32_t c186 = 0; c186 < 1024; ++c186) {
        ((int32_t*)out1)[((((h324 * 14336) + (w162 * 1024)) + c186))] = ((int32_t*)tensor_364)[(c186)];
      }
    }
  }
  for (int32_t h325 = 0; h325 < 14; ++h325) {
    (void)load(compute, (int64_t)537264128, 7168, (h325 * 14336));
    (void)load(out1, (int64_t)537329664, 7168, (h325 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h325 * 57344));
  }
  for (int32_t h326 = 0; h326 < 14; ++h326) {
    for (int32_t w163 = 0; w163 < 14; ++w163) {
      for (int32_t c187 = 0; c187 < 1024; ++c187) {
        ((int32_t*)compute)[((((h326 * 14336) + (w163 * 1024)) + c187))] = 64;
      }
    }
  }
  for (int32_t h327 = 0; h327 < 14; ++h327) {
    (void)load(out, (int64_t)537264128, 7168, (h327 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h327 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h327 * 57344));
  }
  for (int32_t h328 = 0; h328 < 14; ++h328) {
    for (int32_t w164 = 0; w164 < 14; ++w164) {
      for (int32_t c188 = 0; c188 < 1024; ++c188) {
        ((int32_t*)compute)[((((h328 * 14336) + (w164 * 1024)) + c188))] = 7;
      }
    }
  }
  for (int32_t h329 = 0; h329 < 14; ++h329) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h329 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h329 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h329 * 57344));
  }
  for (int32_t i1164 = 0; i1164 < 14; ++i1164) {
    for (int32_t i2121 = 0; i2121 < 14; ++i2121) {
      for (int32_t i3121 = 0; i3121 < 1024; ++i3121) {
        int32_t _92 = ((int32_t*)out1)[((((i1164 * 14336) + (i2121 * 1024)) + i3121))];
        int32_t _93 = (_92) < (127) ? (_92) : (127);
        ((int32_t*)compute)[((((i1164 * 14336) + (i2121 * 1024)) + i3121))] = ((_93) > (-127) ? (_93) : (-127));
      }
    }
  }
  for (int32_t i1165 = 0; i1165 < 14; ++i1165) {
    for (int32_t i2122 = 0; i2122 < 14; ++i2122) {
      for (int32_t i3122 = 0; i3122 < 1024; ++i3122) {
        ((int8_t*)out)[((((i1165 * 14336) + (i2122 * 1024)) + i3122))] = ((int8_t)((int32_t*)compute)[((((i1165 * 14336) + (i2122 * 1024)) + i3122))]);
      }
    }
  }
  for (int32_t i1166 = 0; i1166 < 14; ++i1166) {
    for (int32_t i2123 = 0; i2123 < 14; ++i2123) {
      for (int32_t i3123 = 0; i3123 < 1024; ++i3123) {
        ((int32_t*)compute)[((((i1166 * 14336) + (i2123 * 1024)) + i3123))] = ((int32_t)((int8_t*)out)[((((i1166 * 14336) + (i2123 * 1024)) + i3123))]);
      }
    }
  }
  for (int32_t h330 = 0; h330 < 14; ++h330) {
    (void)load(compute1, (int64_t)537264128, 7168, (h330 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h330 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h330 * 57344));
  }
  for (int32_t h331 = 0; h331 < 14; ++h331) {
    for (int32_t w165 = 0; w165 < 14; ++w165) {
      for (int32_t c189 = 0; c189 < 1024; ++c189) {
        ((int32_t*)compute)[((((h331 * 14336) + (w165 * 1024)) + c189))] = 0;
      }
    }
  }
  for (int32_t h332 = 0; h332 < 14; ++h332) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h332 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h332 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h332 * 57344));
  }
  for (int32_t i1167 = 0; i1167 < 14; ++i1167) {
    for (int32_t i2124 = 0; i2124 < 14; ++i2124) {
      for (int32_t i3124 = 0; i3124 < 1024; ++i3124) {
        int32_t _94 = ((int32_t*)compute1)[((((i1167 * 14336) + (i2124 * 1024)) + i3124))];
        int32_t _95 = (_94) < (127) ? (_94) : (127);
        ((int32_t*)compute)[((((i1167 * 14336) + (i2124 * 1024)) + i3124))] = ((_95) > (-127) ? (_95) : (-127));
      }
    }
  }
  for (int32_t i1168 = 0; i1168 < 14; ++i1168) {
    for (int32_t i2125 = 0; i2125 < 14; ++i2125) {
      for (int32_t i3125 = 0; i3125 < 1024; ++i3125) {
        ((int8_t*)compute1)[((((i1168 * 14336) + (i2125 * 1024)) + i3125))] = ((int8_t)((int32_t*)compute)[((((i1168 * 14336) + (i2125 * 1024)) + i3125))]);
      }
    }
  }
  for (int32_t o123 = 0; o123 < 14; ++o123) {
    for (int32_t o223 = 0; o223 < 14; ++o223) {
      for (int32_t c190 = 0; c190 < 1024; ++c190) {
        ((int8_t*)compute)[((((o123 * 14336) + (o223 * 1024)) + c190))] = ((int8_t*)compute1)[((((o123 * 14336) + (o223 * 1024)) + c190))];
      }
    }
  }
  for (int32_t ax0250 = 0; ax0250 < 196; ++ax0250) {
    for (int32_t ax1253 = 0; ax1253 < 1024; ++ax1253) {
      ((int8_t*)out1)[(((ax0250 * 1024) + ax1253))] = ((int8_t*)compute)[(((ax0250 * 1024) + ax1253))];
    }
  }
  for (int32_t i043 = 0; i043 < 200; ++i043) {
    for (int32_t i1169 = 0; i1169 < 1024; ++i1169) {
      ((int8_t*)compute)[(((i043 * 1024) + i1169))] = ((i043 < 196) ? ((int8_t*)out1)[(((i043 * 1024) + i1169))] : (int8_t)0);
    }
  }
  for (int32_t ax0251 = 0; ax0251 < 25; ++ax0251) {
    for (int32_t ax1254 = 0; ax1254 < 8; ++ax1254) {
      for (int32_t ax2212 = 0; ax2212 < 128; ++ax2212) {
        for (int32_t ax3212 = 0; ax3212 < 8; ++ax3212) {
          ((int8_t*)out)[(((((ax0251 * 8192) + (ax1254 * 1024)) + (ax2212 * 8)) + ax3212))] = ((int8_t*)compute)[(((((ax0251 * 8192) + (ax1254 * 1024)) + (ax2212 * 8)) + ax3212))];
        }
      }
    }
  }
  for (int32_t ax0252 = 0; ax0252 < 25; ++ax0252) {
    for (int32_t ax1255 = 0; ax1255 < 128; ++ax1255) {
      for (int32_t ax2213 = 0; ax2213 < 8; ++ax2213) {
        for (int32_t ax3213 = 0; ax3213 < 8; ++ax3213) {
          ((int8_t*)compute)[(((((ax0252 * 8192) + (ax1255 * 64)) + (ax2213 * 8)) + ax3213))] = ((int8_t*)out)[(((((ax0252 * 8192) + (ax2213 * 1024)) + (ax1255 * 8)) + ax3213))];
        }
      }
    }
  }
  for (int32_t ax0253 = 0; ax0253 < 25; ++ax0253) {
    for (int32_t ax2214 = 0; ax2214 < 128; ++ax2214) {
      for (int32_t ax3214 = 0; ax3214 < 8; ++ax3214) {
        for (int32_t ax442 = 0; ax442 < 8; ++ax442) {
          ((int8_t*)pad_data)[(((((ax0253 * 8192) + (ax2214 * 64)) + (ax3214 * 8)) + ax442))] = ((int8_t*)compute)[(((((ax0253 * 8192) + (ax2214 * 64)) + (ax3214 * 8)) + ax442))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25600, 0);
  for (int32_t ax0254 = 0; ax0254 < 256; ++ax0254) {
    for (int32_t ax1256 = 0; ax1256 < 1024; ++ax1256) {
      ((int8_t*)compute)[(((ax0254 * 1024) + ax1256))] = ((int8_t*)kernel_377)[(((ax0254 * 1024) + ax1256))];
    }
  }
  for (int32_t ax0255 = 0; ax0255 < 32; ++ax0255) {
    for (int32_t ax1257 = 0; ax1257 < 8; ++ax1257) {
      for (int32_t ax2215 = 0; ax2215 < 128; ++ax2215) {
        for (int32_t ax3215 = 0; ax3215 < 8; ++ax3215) {
          ((int8_t*)out1)[(((((ax0255 * 8192) + (ax1257 * 1024)) + (ax2215 * 8)) + ax3215))] = ((int8_t*)compute)[(((((ax0255 * 8192) + (ax1257 * 1024)) + (ax2215 * 8)) + ax3215))];
        }
      }
    }
  }
  for (int32_t ax0256 = 0; ax0256 < 32; ++ax0256) {
    for (int32_t ax1258 = 0; ax1258 < 128; ++ax1258) {
      for (int32_t ax2216 = 0; ax2216 < 8; ++ax2216) {
        for (int32_t ax3216 = 0; ax3216 < 8; ++ax3216) {
          ((int8_t*)compute)[(((((ax0256 * 8192) + (ax1258 * 64)) + (ax2216 * 8)) + ax3216))] = ((int8_t*)out1)[(((((ax0256 * 8192) + (ax2216 * 1024)) + (ax1258 * 8)) + ax3216))];
        }
      }
    }
  }
  for (int32_t ax0257 = 0; ax0257 < 32; ++ax0257) {
    for (int32_t ax2217 = 0; ax2217 < 128; ++ax2217) {
      for (int32_t ax3217 = 0; ax3217 < 8; ++ax3217) {
        for (int32_t ax443 = 0; ax443 < 8; ++ax443) {
          ((int8_t*)out)[(((((ax0257 * 8192) + (ax2217 * 64)) + (ax3217 * 8)) + ax443))] = ((int8_t*)compute)[(((((ax0257 * 8192) + (ax2217 * 64)) + (ax3217 * 8)) + ax443))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 32768, 0);
  for (int32_t i58 = 0; i58 < 25; ++i58) {
    for (int32_t x27 = 0; x27 < 32; ++x27) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i58 * 512)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x27 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i58 * 8192) + (x27 * 256)));
    }
  }
  for (int32_t ax0258 = 0; ax0258 < 25; ++ax0258) {
    for (int32_t ax1259 = 0; ax1259 < 8; ++ax1259) {
      for (int32_t ax2218 = 0; ax2218 < 32; ++ax2218) {
        for (int32_t ax3218 = 0; ax3218 < 8; ++ax3218) {
          ((int32_t*)pad_data)[(((((ax0258 * 2048) + (ax1259 * 256)) + (ax2218 * 8)) + ax3218))] = ((int32_t*)compute)[(((((ax0258 * 2048) + (ax2218 * 64)) + (ax1259 * 8)) + ax3218))];
        }
      }
    }
  }
  for (int32_t ax0259 = 0; ax0259 < 196; ++ax0259) {
    for (int32_t ax1260 = 0; ax1260 < 256; ++ax1260) {
      ((int32_t*)compute)[(((ax0259 * 256) + ax1260))] = ((int32_t*)pad_data)[(((ax0259 * 256) + ax1260))];
    }
  }
  for (int32_t i044 = 0; i044 < 196; ++i044) {
    for (int32_t i1170 = 0; i1170 < 256; ++i1170) {
      ((int32_t*)out1)[(((i044 * 256) + i1170))] = ((int32_t*)compute)[(((i044 * 256) + i1170))];
    }
  }
  for (int32_t ax1261 = 0; ax1261 < 14; ++ax1261) {
    for (int32_t ax2219 = 0; ax2219 < 14; ++ax2219) {
      for (int32_t ax3219 = 0; ax3219 < 256; ++ax3219) {
        ((int32_t*)compute)[((((ax1261 * 3584) + (ax2219 * 256)) + ax3219))] = ((int32_t*)out1)[((((ax1261 * 3584) + (ax2219 * 256)) + ax3219))];
      }
    }
  }
  for (int32_t h333 = 0; h333 < 14; ++h333) {
    for (int32_t w166 = 0; w166 < 14; ++w166) {
      for (int32_t c191 = 0; c191 < 256; ++c191) {
        ((int32_t*)out)[((((h333 * 3584) + (w166 * 256)) + c191))] = 12;
      }
    }
  }
  for (int32_t h334 = 0; h334 < 14; ++h334) {
    (void)load(compute, (int64_t)537264128, 1792, (h334 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h334 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h334 * 14336));
  }
  for (int32_t h335 = 0; h335 < 14; ++h335) {
    for (int32_t w167 = 0; w167 < 14; ++w167) {
      for (int32_t c192 = 0; c192 < 256; ++c192) {
        ((int32_t*)compute)[((((h335 * 3584) + (w167 * 256)) + c192))] = ((int32_t*)tensor_379)[(c192)];
      }
    }
  }
  for (int32_t h336 = 0; h336 < 14; ++h336) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h336 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h336 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h336 * 14336));
  }
  for (int32_t h337 = 0; h337 < 14; ++h337) {
    for (int32_t w168 = 0; w168 < 14; ++w168) {
      for (int32_t c193 = 0; c193 < 256; ++c193) {
        ((int32_t*)compute)[((((h337 * 3584) + (w168 * 256)) + c193))] = ((int32_t*)tensor_380)[(c193)];
      }
    }
  }
  for (int32_t h338 = 0; h338 < 14; ++h338) {
    (void)load(out1, (int64_t)537264128, 1792, (h338 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h338 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h338 * 14336));
  }
  for (int32_t h339 = 0; h339 < 14; ++h339) {
    for (int32_t w169 = 0; w169 < 14; ++w169) {
      for (int32_t c194 = 0; c194 < 256; ++c194) {
        ((int32_t*)compute)[((((h339 * 3584) + (w169 * 256)) + c194))] = 0;
      }
    }
  }
  for (int32_t h340 = 0; h340 < 14; ++h340) {
    (void)load(out, (int64_t)537264128, 1792, (h340 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h340 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h340 * 14336));
  }
  for (int32_t h341 = 0; h341 < 14; ++h341) {
    for (int32_t w170 = 0; w170 < 14; ++w170) {
      for (int32_t c195 = 0; c195 < 256; ++c195) {
        ((int32_t*)compute)[((((h341 * 3584) + (w170 * 256)) + c195))] = 524288;
      }
    }
  }
  for (int32_t h342 = 0; h342 < 14; ++h342) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h342 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h342 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h342 * 14336));
  }
  for (int32_t h343 = 0; h343 < 14; ++h343) {
    for (int32_t w171 = 0; w171 < 14; ++w171) {
      for (int32_t c196 = 0; c196 < 256; ++c196) {
        ((int32_t*)compute)[((((h343 * 3584) + (w171 * 256)) + c196))] = 20;
      }
    }
  }
  for (int32_t h344 = 0; h344 < 14; ++h344) {
    (void)load(out1, (int64_t)537264128, 1792, (h344 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h344 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h344 * 14336));
  }
  for (int32_t i1171 = 0; i1171 < 14; ++i1171) {
    for (int32_t i2126 = 0; i2126 < 14; ++i2126) {
      for (int32_t i3126 = 0; i3126 < 256; ++i3126) {
        int32_t _96 = ((int32_t*)out)[((((i1171 * 3584) + (i2126 * 256)) + i3126))];
        int32_t _97 = (_96) < (127) ? (_96) : (127);
        ((int32_t*)compute)[((((i1171 * 3584) + (i2126 * 256)) + i3126))] = ((_97) > (-127) ? (_97) : (-127));
      }
    }
  }
  for (int32_t i1172 = 0; i1172 < 14; ++i1172) {
    for (int32_t i2127 = 0; i2127 < 14; ++i2127) {
      for (int32_t i3127 = 0; i3127 < 256; ++i3127) {
        ((int8_t*)T_reshape1)[((((i1172 * 3584) + (i2127 * 256)) + i3127))] = ((int8_t)((int32_t*)compute)[((((i1172 * 3584) + (i2127 * 256)) + i3127))]);
      }
    }
  }
  for (int32_t i1173 = 0; i1173 < 16; ++i1173) {
    for (int32_t i2128 = 0; i2128 < 16; ++i2128) {
      for (int32_t i3128 = 0; i3128 < 256; ++i3128) {
        ((int8_t*)T_reshape)[((((i1173 * 4096) + (i2128 * 256)) + i3128))] = (((((1 <= i1173) && (i1173 < 15)) && (1 <= i2128)) && (i2128 < 15)) ? ((int8_t*)T_reshape1)[(((((i1173 * 3584) + (i2128 * 256)) + i3128) - 3840))] : (int8_t)0);
      }
    }
  }
  for (int32_t o124 = 0; o124 < 14; ++o124) {
    for (int32_t o224 = 0; o224 < 14; ++o224) {
      for (int32_t k18 = 0; k18 < 3; ++k18) {
        for (int32_t k28 = 0; k28 < 3; ++k28) {
          for (int32_t c197 = 0; c197 < 256; ++c197) {
            ((int8_t*)compute)[((((((o124 * 32256) + (o224 * 2304)) + (k18 * 768)) + (k28 * 256)) + c197))] = ((int8_t*)T_reshape)[((((((k18 * 4096) + (o124 * 4096)) + (k28 * 256)) + (o224 * 256)) + c197))];
          }
        }
      }
    }
  }
  for (int32_t ax0260 = 0; ax0260 < 196; ++ax0260) {
    for (int32_t ax1262 = 0; ax1262 < 2304; ++ax1262) {
      ((int8_t*)pad_data)[(((ax0260 * 2304) + ax1262))] = ((int8_t*)compute)[(((ax0260 * 2304) + ax1262))];
    }
  }
  for (int32_t i045 = 0; i045 < 200; ++i045) {
    for (int32_t i1174 = 0; i1174 < 2304; ++i1174) {
      ((int8_t*)compute)[(((i045 * 2304) + i1174))] = ((i045 < 196) ? ((int8_t*)pad_data)[(((i045 * 2304) + i1174))] : (int8_t)0);
    }
  }
  for (int32_t ax0261 = 0; ax0261 < 25; ++ax0261) {
    for (int32_t ax1263 = 0; ax1263 < 8; ++ax1263) {
      for (int32_t ax2220 = 0; ax2220 < 288; ++ax2220) {
        for (int32_t ax3220 = 0; ax3220 < 8; ++ax3220) {
          ((int8_t*)out1)[(((((ax0261 * 18432) + (ax1263 * 2304)) + (ax2220 * 8)) + ax3220))] = ((int8_t*)compute)[(((((ax0261 * 18432) + (ax1263 * 2304)) + (ax2220 * 8)) + ax3220))];
        }
      }
    }
  }
  for (int32_t ax0262 = 0; ax0262 < 25; ++ax0262) {
    for (int32_t ax1264 = 0; ax1264 < 288; ++ax1264) {
      for (int32_t ax2221 = 0; ax2221 < 8; ++ax2221) {
        for (int32_t ax3221 = 0; ax3221 < 8; ++ax3221) {
          ((int8_t*)compute)[(((((ax0262 * 18432) + (ax1264 * 64)) + (ax2221 * 8)) + ax3221))] = ((int8_t*)out1)[(((((ax0262 * 18432) + (ax2221 * 2304)) + (ax1264 * 8)) + ax3221))];
        }
      }
    }
  }
  for (int32_t ax0263 = 0; ax0263 < 25; ++ax0263) {
    for (int32_t ax1265 = 0; ax1265 < 4; ++ax1265) {
      for (int32_t ax2222 = 0; ax2222 < 72; ++ax2222) {
        for (int32_t ax3222 = 0; ax3222 < 8; ++ax3222) {
          for (int32_t ax444 = 0; ax444 < 8; ++ax444) {
            ((int8_t*)out)[((((((ax0263 * 18432) + (ax1265 * 4608)) + (ax2222 * 64)) + (ax3222 * 8)) + ax444))] = ((int8_t*)compute)[((((((ax0263 * 18432) + (ax1265 * 4608)) + (ax2222 * 64)) + (ax3222 * 8)) + ax444))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536870912, 57600, 0);
  for (int32_t ax0264 = 0; ax0264 < 256; ++ax0264) {
    for (int32_t ax1266 = 0; ax1266 < 2304; ++ax1266) {
      ((int8_t*)compute)[(((ax0264 * 2304) + ax1266))] = ((int8_t*)kernel_387)[(((ax0264 * 2304) + ax1266))];
    }
  }
  for (int32_t ax0265 = 0; ax0265 < 32; ++ax0265) {
    for (int32_t ax1267 = 0; ax1267 < 8; ++ax1267) {
      for (int32_t ax2223 = 0; ax2223 < 288; ++ax2223) {
        for (int32_t ax3223 = 0; ax3223 < 8; ++ax3223) {
          ((int8_t*)pad_data)[(((((ax0265 * 18432) + (ax1267 * 2304)) + (ax2223 * 8)) + ax3223))] = ((int8_t*)compute)[(((((ax0265 * 18432) + (ax1267 * 2304)) + (ax2223 * 8)) + ax3223))];
        }
      }
    }
  }
  for (int32_t ax0266 = 0; ax0266 < 32; ++ax0266) {
    for (int32_t ax1268 = 0; ax1268 < 288; ++ax1268) {
      for (int32_t ax2224 = 0; ax2224 < 8; ++ax2224) {
        for (int32_t ax3224 = 0; ax3224 < 8; ++ax3224) {
          ((int8_t*)compute)[(((((ax0266 * 18432) + (ax1268 * 64)) + (ax2224 * 8)) + ax3224))] = ((int8_t*)pad_data)[(((((ax0266 * 18432) + (ax2224 * 2304)) + (ax1268 * 8)) + ax3224))];
        }
      }
    }
  }
  for (int32_t ax0267 = 0; ax0267 < 32; ++ax0267) {
    for (int32_t ax1269 = 0; ax1269 < 4; ++ax1269) {
      for (int32_t ax2225 = 0; ax2225 < 72; ++ax2225) {
        for (int32_t ax3225 = 0; ax3225 < 8; ++ax3225) {
          for (int32_t ax445 = 0; ax445 < 8; ++ax445) {
            ((int8_t*)out1)[((((((ax0267 * 18432) + (ax1269 * 4608)) + (ax2225 * 64)) + (ax3225 * 8)) + ax445))] = ((int8_t*)compute)[((((((ax0267 * 18432) + (ax1269 * 4608)) + (ax2225 * 64)) + (ax3225 * 8)) + ax445))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 73728, 0);
  for (int32_t i59 = 0; i59 < 25; ++i59) {
    for (int32_t x28 = 0; x28 < 32; ++x28) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k05 = 0; k05 < 4; ++k05) {
        (void)move(((((int64_t)((i59 * 1152) + (k05 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x28 * 1152) + (k05 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute, (int64_t)537264128, 32, ((i59 * 8192) + (x28 * 256)));
    }
  }
  for (int32_t ax0268 = 0; ax0268 < 25; ++ax0268) {
    for (int32_t ax1270 = 0; ax1270 < 8; ++ax1270) {
      for (int32_t ax2226 = 0; ax2226 < 32; ++ax2226) {
        for (int32_t ax3226 = 0; ax3226 < 8; ++ax3226) {
          ((int32_t*)out)[(((((ax0268 * 2048) + (ax1270 * 256)) + (ax2226 * 8)) + ax3226))] = ((int32_t*)compute)[(((((ax0268 * 2048) + (ax2226 * 64)) + (ax1270 * 8)) + ax3226))];
        }
      }
    }
  }
  for (int32_t ax0269 = 0; ax0269 < 196; ++ax0269) {
    for (int32_t ax1271 = 0; ax1271 < 256; ++ax1271) {
      ((int32_t*)compute)[(((ax0269 * 256) + ax1271))] = ((int32_t*)out)[(((ax0269 * 256) + ax1271))];
    }
  }
  for (int32_t i046 = 0; i046 < 196; ++i046) {
    for (int32_t i1175 = 0; i1175 < 256; ++i1175) {
      ((int32_t*)pad_data)[(((i046 * 256) + i1175))] = ((int32_t*)compute)[(((i046 * 256) + i1175))];
    }
  }
  for (int32_t ax1272 = 0; ax1272 < 14; ++ax1272) {
    for (int32_t ax2227 = 0; ax2227 < 14; ++ax2227) {
      for (int32_t ax3227 = 0; ax3227 < 256; ++ax3227) {
        ((int32_t*)compute)[((((ax1272 * 3584) + (ax2227 * 256)) + ax3227))] = ((int32_t*)pad_data)[((((ax1272 * 3584) + (ax2227 * 256)) + ax3227))];
      }
    }
  }
  for (int32_t h345 = 0; h345 < 14; ++h345) {
    for (int32_t w172 = 0; w172 < 14; ++w172) {
      for (int32_t c198 = 0; c198 < 256; ++c198) {
        ((int32_t*)out1)[((((h345 * 3584) + (w172 * 256)) + c198))] = ((int32_t*)tensor_388)[(c198)];
      }
    }
  }
  for (int32_t h346 = 0; h346 < 14; ++h346) {
    (void)load(compute, (int64_t)537264128, 1792, (h346 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h346 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h346 * 14336));
  }
  for (int32_t h347 = 0; h347 < 14; ++h347) {
    for (int32_t w173 = 0; w173 < 14; ++w173) {
      for (int32_t c199 = 0; c199 < 256; ++c199) {
        ((int32_t*)compute)[((((h347 * 3584) + (w173 * 256)) + c199))] = 0;
      }
    }
  }
  for (int32_t h348 = 0; h348 < 14; ++h348) {
    (void)load(out, (int64_t)537264128, 1792, (h348 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h348 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h348 * 14336));
  }
  for (int32_t h349 = 0; h349 < 14; ++h349) {
    for (int32_t w174 = 0; w174 < 14; ++w174) {
      for (int32_t c200 = 0; c200 < 256; ++c200) {
        ((int32_t*)compute)[((((h349 * 3584) + (w174 * 256)) + c200))] = 128;
      }
    }
  }
  for (int32_t h350 = 0; h350 < 14; ++h350) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h350 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h350 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h350 * 14336));
  }
  for (int32_t h351 = 0; h351 < 14; ++h351) {
    for (int32_t w175 = 0; w175 < 14; ++w175) {
      for (int32_t c201 = 0; c201 < 256; ++c201) {
        ((int32_t*)compute)[((((h351 * 3584) + (w175 * 256)) + c201))] = 8;
      }
    }
  }
  for (int32_t h352 = 0; h352 < 14; ++h352) {
    (void)load(out1, (int64_t)537264128, 1792, (h352 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h352 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h352 * 14336));
  }
  for (int32_t i1176 = 0; i1176 < 14; ++i1176) {
    for (int32_t i2129 = 0; i2129 < 14; ++i2129) {
      for (int32_t i3129 = 0; i3129 < 256; ++i3129) {
        int32_t _98 = ((int32_t*)out)[((((i1176 * 3584) + (i2129 * 256)) + i3129))];
        int32_t _99 = (_98) < (127) ? (_98) : (127);
        ((int32_t*)compute)[((((i1176 * 3584) + (i2129 * 256)) + i3129))] = ((_99) > (-127) ? (_99) : (-127));
      }
    }
  }
  for (int32_t i1177 = 0; i1177 < 14; ++i1177) {
    for (int32_t i2130 = 0; i2130 < 14; ++i2130) {
      for (int32_t i3130 = 0; i3130 < 256; ++i3130) {
        ((int8_t*)T_reshape1)[((((i1177 * 3584) + (i2130 * 256)) + i3130))] = ((int8_t)((int32_t*)compute)[((((i1177 * 3584) + (i2130 * 256)) + i3130))]);
      }
    }
  }
  for (int32_t o125 = 0; o125 < 14; ++o125) {
    for (int32_t o225 = 0; o225 < 14; ++o225) {
      for (int32_t c202 = 0; c202 < 256; ++c202) {
        ((int8_t*)T_reshape)[((((o125 * 3584) + (o225 * 256)) + c202))] = ((int8_t*)T_reshape1)[((((o125 * 3584) + (o225 * 256)) + c202))];
      }
    }
  }
  for (int32_t ax0270 = 0; ax0270 < 196; ++ax0270) {
    for (int32_t ax1273 = 0; ax1273 < 256; ++ax1273) {
      ((int8_t*)T_reshape1)[(((ax0270 * 256) + ax1273))] = ((int8_t*)T_reshape)[(((ax0270 * 256) + ax1273))];
    }
  }
  for (int32_t i047 = 0; i047 < 200; ++i047) {
    for (int32_t i1178 = 0; i1178 < 256; ++i1178) {
      ((int8_t*)T_reshape)[(((i047 * 256) + i1178))] = ((i047 < 196) ? ((int8_t*)T_reshape1)[(((i047 * 256) + i1178))] : (int8_t)0);
    }
  }
  for (int32_t ax0271 = 0; ax0271 < 25; ++ax0271) {
    for (int32_t ax1274 = 0; ax1274 < 8; ++ax1274) {
      for (int32_t ax2228 = 0; ax2228 < 32; ++ax2228) {
        for (int32_t ax3228 = 0; ax3228 < 8; ++ax3228) {
          ((int8_t*)T_reshape1)[(((((ax0271 * 2048) + (ax1274 * 256)) + (ax2228 * 8)) + ax3228))] = ((int8_t*)T_reshape)[(((((ax0271 * 2048) + (ax1274 * 256)) + (ax2228 * 8)) + ax3228))];
        }
      }
    }
  }
  for (int32_t ax0272 = 0; ax0272 < 25; ++ax0272) {
    for (int32_t ax1275 = 0; ax1275 < 32; ++ax1275) {
      for (int32_t ax2229 = 0; ax2229 < 8; ++ax2229) {
        for (int32_t ax3229 = 0; ax3229 < 8; ++ax3229) {
          ((int8_t*)T_reshape)[(((((ax0272 * 2048) + (ax1275 * 64)) + (ax2229 * 8)) + ax3229))] = ((int8_t*)T_reshape1)[(((((ax0272 * 2048) + (ax2229 * 256)) + (ax1275 * 8)) + ax3229))];
        }
      }
    }
  }
  for (int32_t ax0273 = 0; ax0273 < 25; ++ax0273) {
    for (int32_t ax2230 = 0; ax2230 < 32; ++ax2230) {
      for (int32_t ax3230 = 0; ax3230 < 8; ++ax3230) {
        for (int32_t ax446 = 0; ax446 < 8; ++ax446) {
          ((int8_t*)T_reshape1)[(((((ax0273 * 2048) + (ax2230 * 64)) + (ax3230 * 8)) + ax446))] = ((int8_t*)T_reshape)[(((((ax0273 * 2048) + (ax2230 * 64)) + (ax3230 * 8)) + ax446))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 6400, 0);
  for (int32_t ax0274 = 0; ax0274 < 1024; ++ax0274) {
    for (int32_t ax1276 = 0; ax1276 < 256; ++ax1276) {
      ((int8_t*)compute)[(((ax0274 * 256) + ax1276))] = ((int8_t*)kernel_395)[(((ax0274 * 256) + ax1276))];
    }
  }
  for (int32_t ax0275 = 0; ax0275 < 128; ++ax0275) {
    for (int32_t ax1277 = 0; ax1277 < 8; ++ax1277) {
      for (int32_t ax2231 = 0; ax2231 < 32; ++ax2231) {
        for (int32_t ax3231 = 0; ax3231 < 8; ++ax3231) {
          ((int8_t*)pad_data)[(((((ax0275 * 2048) + (ax1277 * 256)) + (ax2231 * 8)) + ax3231))] = ((int8_t*)compute)[(((((ax0275 * 2048) + (ax1277 * 256)) + (ax2231 * 8)) + ax3231))];
        }
      }
    }
  }
  for (int32_t ax0276 = 0; ax0276 < 128; ++ax0276) {
    for (int32_t ax1278 = 0; ax1278 < 32; ++ax1278) {
      for (int32_t ax2232 = 0; ax2232 < 8; ++ax2232) {
        for (int32_t ax3232 = 0; ax3232 < 8; ++ax3232) {
          ((int8_t*)compute)[(((((ax0276 * 2048) + (ax1278 * 64)) + (ax2232 * 8)) + ax3232))] = ((int8_t*)pad_data)[(((((ax0276 * 2048) + (ax2232 * 256)) + (ax1278 * 8)) + ax3232))];
        }
      }
    }
  }
  for (int32_t ax0277 = 0; ax0277 < 128; ++ax0277) {
    for (int32_t ax2233 = 0; ax2233 < 32; ++ax2233) {
      for (int32_t ax3233 = 0; ax3233 < 8; ++ax3233) {
        for (int32_t ax447 = 0; ax447 < 8; ++ax447) {
          ((int8_t*)out1)[(((((ax0277 * 2048) + (ax2233 * 64)) + (ax3233 * 8)) + ax447))] = ((int8_t*)compute)[(((((ax0277 * 2048) + (ax2233 * 64)) + (ax3233 * 8)) + ax447))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 32768, 0);
  for (int32_t i60 = 0; i60 < 25; ++i60) {
    for (int32_t x29 = 0; x29 < 128; ++x29) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i60 * 128) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x29 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(out, (int64_t)537264128, 32, ((i60 * 32768) + (x29 * 256)));
    }
  }
  for (int32_t ax0278 = 0; ax0278 < 25; ++ax0278) {
    for (int32_t ax1279 = 0; ax1279 < 8; ++ax1279) {
      for (int32_t ax2234 = 0; ax2234 < 128; ++ax2234) {
        for (int32_t ax3234 = 0; ax3234 < 8; ++ax3234) {
          ((int32_t*)pad_data)[(((((ax0278 * 8192) + (ax1279 * 1024)) + (ax2234 * 8)) + ax3234))] = ((int32_t*)out)[(((((ax0278 * 8192) + (ax2234 * 64)) + (ax1279 * 8)) + ax3234))];
        }
      }
    }
  }
  for (int32_t ax0279 = 0; ax0279 < 196; ++ax0279) {
    for (int32_t ax1280 = 0; ax1280 < 1024; ++ax1280) {
      ((int32_t*)compute)[(((ax0279 * 1024) + ax1280))] = ((int32_t*)pad_data)[(((ax0279 * 1024) + ax1280))];
    }
  }
  for (int32_t i048 = 0; i048 < 196; ++i048) {
    for (int32_t i1179 = 0; i1179 < 1024; ++i1179) {
      ((int32_t*)out1)[(((i048 * 1024) + i1179))] = ((int32_t*)compute)[(((i048 * 1024) + i1179))];
    }
  }
  for (int32_t ax1281 = 0; ax1281 < 14; ++ax1281) {
    for (int32_t ax2235 = 0; ax2235 < 14; ++ax2235) {
      for (int32_t ax3235 = 0; ax3235 < 1024; ++ax3235) {
        ((int32_t*)compute)[((((ax1281 * 14336) + (ax2235 * 1024)) + ax3235))] = ((int32_t*)out1)[((((ax1281 * 14336) + (ax2235 * 1024)) + ax3235))];
      }
    }
  }
  for (int32_t h353 = 0; h353 < 14; ++h353) {
    for (int32_t w176 = 0; w176 < 14; ++w176) {
      for (int32_t c203 = 0; c203 < 1024; ++c203) {
        ((int32_t*)out)[((((h353 * 14336) + (w176 * 1024)) + c203))] = 10;
      }
    }
  }
  for (int32_t h354 = 0; h354 < 14; ++h354) {
    (void)load(compute, (int64_t)537264128, 7168, (h354 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h354 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h354 * 57344));
  }
  for (int32_t h355 = 0; h355 < 14; ++h355) {
    for (int32_t w177 = 0; w177 < 14; ++w177) {
      for (int32_t c204 = 0; c204 < 1024; ++c204) {
        ((int32_t*)compute)[((((h355 * 14336) + (w177 * 1024)) + c204))] = ((int32_t*)tensor_397)[(c204)];
      }
    }
  }
  for (int32_t h356 = 0; h356 < 14; ++h356) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h356 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h356 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h356 * 57344));
  }
  for (int32_t h357 = 0; h357 < 14; ++h357) {
    for (int32_t w178 = 0; w178 < 14; ++w178) {
      for (int32_t c205 = 0; c205 < 1024; ++c205) {
        ((int32_t*)compute)[((((h357 * 14336) + (w178 * 1024)) + c205))] = 131072;
      }
    }
  }
  for (int32_t h358 = 0; h358 < 14; ++h358) {
    (void)load(out1, (int64_t)537264128, 7168, (h358 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h358 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h358 * 57344));
  }
  for (int32_t h359 = 0; h359 < 14; ++h359) {
    for (int32_t w179 = 0; w179 < 14; ++w179) {
      for (int32_t c206 = 0; c206 < 1024; ++c206) {
        ((int32_t*)compute)[((((h359 * 14336) + (w179 * 1024)) + c206))] = 18;
      }
    }
  }
  for (int32_t h360 = 0; h360 < 14; ++h360) {
    (void)load(out, (int64_t)537264128, 7168, (h360 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h360 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h360 * 57344));
  }
  for (int32_t i1180 = 0; i1180 < 14; ++i1180) {
    for (int32_t i2131 = 0; i2131 < 14; ++i2131) {
      for (int32_t i3131 = 0; i3131 < 1024; ++i3131) {
        int32_t _100 = ((int32_t*)pad_data)[((((i1180 * 14336) + (i2131 * 1024)) + i3131))];
        int32_t _101 = (_100) < (127) ? (_100) : (127);
        ((int32_t*)compute)[((((i1180 * 14336) + (i2131 * 1024)) + i3131))] = ((_101) > (-127) ? (_101) : (-127));
      }
    }
  }
  for (int32_t i1181 = 0; i1181 < 14; ++i1181) {
    for (int32_t i2132 = 0; i2132 < 14; ++i2132) {
      for (int32_t i3132 = 0; i3132 < 1024; ++i3132) {
        ((int8_t*)out1)[((((i1181 * 14336) + (i2132 * 1024)) + i3132))] = ((int8_t)((int32_t*)compute)[((((i1181 * 14336) + (i2132 * 1024)) + i3132))]);
      }
    }
  }
  for (int32_t i1182 = 0; i1182 < 14; ++i1182) {
    for (int32_t i2133 = 0; i2133 < 14; ++i2133) {
      for (int32_t i3133 = 0; i3133 < 1024; ++i3133) {
        ((int32_t*)compute)[((((i1182 * 14336) + (i2133 * 1024)) + i3133))] = ((int32_t)((int8_t*)out1)[((((i1182 * 14336) + (i2133 * 1024)) + i3133))]);
      }
    }
  }
  for (int32_t h361 = 0; h361 < 14; ++h361) {
    for (int32_t w180 = 0; w180 < 14; ++w180) {
      for (int32_t c207 = 0; c207 < 1024; ++c207) {
        ((int32_t*)out)[((((h361 * 14336) + (w180 * 1024)) + c207))] = ((int32_t*)tensor_404)[(c207)];
      }
    }
  }
  for (int32_t h362 = 0; h362 < 14; ++h362) {
    (void)load(compute, (int64_t)537264128, 7168, (h362 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h362 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h362 * 57344));
  }
  for (int32_t h363 = 0; h363 < 14; ++h363) {
    for (int32_t w181 = 0; w181 < 14; ++w181) {
      for (int32_t c208 = 0; c208 < 1024; ++c208) {
        ((int32_t*)compute)[((((h363 * 14336) + (w181 * 1024)) + c208))] = ((int32_t*)tensor_405)[(c208)];
      }
    }
  }
  for (int32_t h364 = 0; h364 < 14; ++h364) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h364 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h364 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h364 * 57344));
  }
  for (int32_t h365 = 0; h365 < 14; ++h365) {
    for (int32_t w182 = 0; w182 < 14; ++w182) {
      for (int32_t c209 = 0; c209 < 1024; ++c209) {
        ((int32_t*)compute)[((((h365 * 14336) + (w182 * 1024)) + c209))] = 8;
      }
    }
  }
  for (int32_t h366 = 0; h366 < 14; ++h366) {
    (void)load(out1, (int64_t)537264128, 7168, (h366 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h366 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h366 * 57344));
  }
  for (int32_t h367 = 0; h367 < 14; ++h367) {
    for (int32_t w183 = 0; w183 < 14; ++w183) {
      for (int32_t c210 = 0; c210 < 1024; ++c210) {
        ((int32_t*)compute)[((((h367 * 14336) + (w183 * 1024)) + c210))] = 4;
      }
    }
  }
  for (int32_t h368 = 0; h368 < 14; ++h368) {
    (void)load(out, (int64_t)537264128, 7168, (h368 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h368 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h368 * 57344));
  }
  for (int32_t i1183 = 0; i1183 < 14; ++i1183) {
    for (int32_t i2134 = 0; i2134 < 14; ++i2134) {
      for (int32_t i3134 = 0; i3134 < 1024; ++i3134) {
        int32_t _102 = ((int32_t*)pad_data)[((((i1183 * 14336) + (i2134 * 1024)) + i3134))];
        int32_t _103 = (_102) < (127) ? (_102) : (127);
        ((int32_t*)compute)[((((i1183 * 14336) + (i2134 * 1024)) + i3134))] = ((_103) > (-127) ? (_103) : (-127));
      }
    }
  }
  for (int32_t i1184 = 0; i1184 < 14; ++i1184) {
    for (int32_t i2135 = 0; i2135 < 14; ++i2135) {
      for (int32_t i3135 = 0; i3135 < 1024; ++i3135) {
        ((int8_t*)out1)[((((i1184 * 14336) + (i2135 * 1024)) + i3135))] = ((int8_t)((int32_t*)compute)[((((i1184 * 14336) + (i2135 * 1024)) + i3135))]);
      }
    }
  }
  for (int32_t i1185 = 0; i1185 < 14; ++i1185) {
    for (int32_t i2136 = 0; i2136 < 14; ++i2136) {
      for (int32_t i3136 = 0; i3136 < 1024; ++i3136) {
        ((int32_t*)compute)[((((i1185 * 14336) + (i2136 * 1024)) + i3136))] = ((int32_t)((int8_t*)out1)[((((i1185 * 14336) + (i2136 * 1024)) + i3136))]);
      }
    }
  }
  for (int32_t i1186 = 0; i1186 < 14; ++i1186) {
    for (int32_t i2137 = 0; i2137 < 14; ++i2137) {
      for (int32_t i3137 = 0; i3137 < 1024; ++i3137) {
        ((int32_t*)out)[((((i1186 * 14336) + (i2137 * 1024)) + i3137))] = ((int32_t)((int8_t*)compute1)[((((i1186 * 14336) + (i2137 * 1024)) + i3137))]);
      }
    }
  }
  for (int32_t h369 = 0; h369 < 14; ++h369) {
    (void)load(compute, (int64_t)537264128, 7168, (h369 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h369 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h369 * 57344));
  }
  for (int32_t h370 = 0; h370 < 14; ++h370) {
    for (int32_t w184 = 0; w184 < 14; ++w184) {
      for (int32_t c211 = 0; c211 < 1024; ++c211) {
        ((int32_t*)compute)[((((h370 * 14336) + (w184 * 1024)) + c211))] = 0;
      }
    }
  }
  for (int32_t h371 = 0; h371 < 14; ++h371) {
    (void)load(compute1, (int64_t)537264128, 7168, (h371 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h371 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h371 * 57344));
  }
  for (int32_t i1187 = 0; i1187 < 14; ++i1187) {
    for (int32_t i2138 = 0; i2138 < 14; ++i2138) {
      for (int32_t i3138 = 0; i3138 < 1024; ++i3138) {
        int32_t _104 = ((int32_t*)pad_data)[((((i1187 * 14336) + (i2138 * 1024)) + i3138))];
        int32_t _105 = (_104) < (127) ? (_104) : (127);
        ((int32_t*)compute)[((((i1187 * 14336) + (i2138 * 1024)) + i3138))] = ((_105) > (-127) ? (_105) : (-127));
      }
    }
  }
  for (int32_t i1188 = 0; i1188 < 14; ++i1188) {
    for (int32_t i2139 = 0; i2139 < 14; ++i2139) {
      for (int32_t i3139 = 0; i3139 < 1024; ++i3139) {
        ((int8_t*)compute1)[((((i1188 * 14336) + (i2139 * 1024)) + i3139))] = ((int8_t)((int32_t*)compute)[((((i1188 * 14336) + (i2139 * 1024)) + i3139))]);
      }
    }
  }
  for (int32_t o126 = 0; o126 < 14; ++o126) {
    for (int32_t o226 = 0; o226 < 14; ++o226) {
      for (int32_t c212 = 0; c212 < 1024; ++c212) {
        ((int8_t*)compute)[((((o126 * 14336) + (o226 * 1024)) + c212))] = ((int8_t*)compute1)[((((o126 * 14336) + (o226 * 1024)) + c212))];
      }
    }
  }
  for (int32_t ax0280 = 0; ax0280 < 196; ++ax0280) {
    for (int32_t ax1282 = 0; ax1282 < 1024; ++ax1282) {
      ((int8_t*)out1)[(((ax0280 * 1024) + ax1282))] = ((int8_t*)compute)[(((ax0280 * 1024) + ax1282))];
    }
  }
  for (int32_t i049 = 0; i049 < 200; ++i049) {
    for (int32_t i1189 = 0; i1189 < 1024; ++i1189) {
      ((int8_t*)compute)[(((i049 * 1024) + i1189))] = ((i049 < 196) ? ((int8_t*)out1)[(((i049 * 1024) + i1189))] : (int8_t)0);
    }
  }
  for (int32_t ax0281 = 0; ax0281 < 25; ++ax0281) {
    for (int32_t ax1283 = 0; ax1283 < 8; ++ax1283) {
      for (int32_t ax2236 = 0; ax2236 < 128; ++ax2236) {
        for (int32_t ax3236 = 0; ax3236 < 8; ++ax3236) {
          ((int8_t*)out)[(((((ax0281 * 8192) + (ax1283 * 1024)) + (ax2236 * 8)) + ax3236))] = ((int8_t*)compute)[(((((ax0281 * 8192) + (ax1283 * 1024)) + (ax2236 * 8)) + ax3236))];
        }
      }
    }
  }
  for (int32_t ax0282 = 0; ax0282 < 25; ++ax0282) {
    for (int32_t ax1284 = 0; ax1284 < 128; ++ax1284) {
      for (int32_t ax2237 = 0; ax2237 < 8; ++ax2237) {
        for (int32_t ax3237 = 0; ax3237 < 8; ++ax3237) {
          ((int8_t*)compute)[(((((ax0282 * 8192) + (ax1284 * 64)) + (ax2237 * 8)) + ax3237))] = ((int8_t*)out)[(((((ax0282 * 8192) + (ax2237 * 1024)) + (ax1284 * 8)) + ax3237))];
        }
      }
    }
  }
  for (int32_t ax0283 = 0; ax0283 < 25; ++ax0283) {
    for (int32_t ax2238 = 0; ax2238 < 128; ++ax2238) {
      for (int32_t ax3238 = 0; ax3238 < 8; ++ax3238) {
        for (int32_t ax448 = 0; ax448 < 8; ++ax448) {
          ((int8_t*)pad_data)[(((((ax0283 * 8192) + (ax2238 * 64)) + (ax3238 * 8)) + ax448))] = ((int8_t*)compute)[(((((ax0283 * 8192) + (ax2238 * 64)) + (ax3238 * 8)) + ax448))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25600, 0);
  for (int32_t ax0284 = 0; ax0284 < 256; ++ax0284) {
    for (int32_t ax1285 = 0; ax1285 < 1024; ++ax1285) {
      ((int8_t*)compute)[(((ax0284 * 1024) + ax1285))] = ((int8_t*)kernel_420)[(((ax0284 * 1024) + ax1285))];
    }
  }
  for (int32_t ax0285 = 0; ax0285 < 32; ++ax0285) {
    for (int32_t ax1286 = 0; ax1286 < 8; ++ax1286) {
      for (int32_t ax2239 = 0; ax2239 < 128; ++ax2239) {
        for (int32_t ax3239 = 0; ax3239 < 8; ++ax3239) {
          ((int8_t*)out1)[(((((ax0285 * 8192) + (ax1286 * 1024)) + (ax2239 * 8)) + ax3239))] = ((int8_t*)compute)[(((((ax0285 * 8192) + (ax1286 * 1024)) + (ax2239 * 8)) + ax3239))];
        }
      }
    }
  }
  for (int32_t ax0286 = 0; ax0286 < 32; ++ax0286) {
    for (int32_t ax1287 = 0; ax1287 < 128; ++ax1287) {
      for (int32_t ax2240 = 0; ax2240 < 8; ++ax2240) {
        for (int32_t ax3240 = 0; ax3240 < 8; ++ax3240) {
          ((int8_t*)compute)[(((((ax0286 * 8192) + (ax1287 * 64)) + (ax2240 * 8)) + ax3240))] = ((int8_t*)out1)[(((((ax0286 * 8192) + (ax2240 * 1024)) + (ax1287 * 8)) + ax3240))];
        }
      }
    }
  }
  for (int32_t ax0287 = 0; ax0287 < 32; ++ax0287) {
    for (int32_t ax2241 = 0; ax2241 < 128; ++ax2241) {
      for (int32_t ax3241 = 0; ax3241 < 8; ++ax3241) {
        for (int32_t ax449 = 0; ax449 < 8; ++ax449) {
          ((int8_t*)out)[(((((ax0287 * 8192) + (ax2241 * 64)) + (ax3241 * 8)) + ax449))] = ((int8_t*)compute)[(((((ax0287 * 8192) + (ax2241 * 64)) + (ax3241 * 8)) + ax449))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 32768, 0);
  for (int32_t i61 = 0; i61 < 25; ++i61) {
    for (int32_t x30 = 0; x30 < 32; ++x30) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i61 * 512)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x30 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i61 * 8192) + (x30 * 256)));
    }
  }
  for (int32_t ax0288 = 0; ax0288 < 25; ++ax0288) {
    for (int32_t ax1288 = 0; ax1288 < 8; ++ax1288) {
      for (int32_t ax2242 = 0; ax2242 < 32; ++ax2242) {
        for (int32_t ax3242 = 0; ax3242 < 8; ++ax3242) {
          ((int32_t*)pad_data)[(((((ax0288 * 2048) + (ax1288 * 256)) + (ax2242 * 8)) + ax3242))] = ((int32_t*)compute)[(((((ax0288 * 2048) + (ax2242 * 64)) + (ax1288 * 8)) + ax3242))];
        }
      }
    }
  }
  for (int32_t ax0289 = 0; ax0289 < 196; ++ax0289) {
    for (int32_t ax1289 = 0; ax1289 < 256; ++ax1289) {
      ((int32_t*)compute)[(((ax0289 * 256) + ax1289))] = ((int32_t*)pad_data)[(((ax0289 * 256) + ax1289))];
    }
  }
  for (int32_t i050 = 0; i050 < 196; ++i050) {
    for (int32_t i1190 = 0; i1190 < 256; ++i1190) {
      ((int32_t*)out1)[(((i050 * 256) + i1190))] = ((int32_t*)compute)[(((i050 * 256) + i1190))];
    }
  }
  for (int32_t ax1290 = 0; ax1290 < 14; ++ax1290) {
    for (int32_t ax2243 = 0; ax2243 < 14; ++ax2243) {
      for (int32_t ax3243 = 0; ax3243 < 256; ++ax3243) {
        ((int32_t*)compute)[((((ax1290 * 3584) + (ax2243 * 256)) + ax3243))] = ((int32_t*)out1)[((((ax1290 * 3584) + (ax2243 * 256)) + ax3243))];
      }
    }
  }
  for (int32_t h372 = 0; h372 < 14; ++h372) {
    for (int32_t w185 = 0; w185 < 14; ++w185) {
      for (int32_t c213 = 0; c213 < 256; ++c213) {
        ((int32_t*)out)[((((h372 * 3584) + (w185 * 256)) + c213))] = 12;
      }
    }
  }
  for (int32_t h373 = 0; h373 < 14; ++h373) {
    (void)load(compute, (int64_t)537264128, 1792, (h373 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h373 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h373 * 14336));
  }
  for (int32_t h374 = 0; h374 < 14; ++h374) {
    for (int32_t w186 = 0; w186 < 14; ++w186) {
      for (int32_t c214 = 0; c214 < 256; ++c214) {
        ((int32_t*)compute)[((((h374 * 3584) + (w186 * 256)) + c214))] = ((int32_t*)tensor_422)[(c214)];
      }
    }
  }
  for (int32_t h375 = 0; h375 < 14; ++h375) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h375 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h375 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h375 * 14336));
  }
  for (int32_t h376 = 0; h376 < 14; ++h376) {
    for (int32_t w187 = 0; w187 < 14; ++w187) {
      for (int32_t c215 = 0; c215 < 256; ++c215) {
        ((int32_t*)compute)[((((h376 * 3584) + (w187 * 256)) + c215))] = ((int32_t*)tensor_423)[(c215)];
      }
    }
  }
  for (int32_t h377 = 0; h377 < 14; ++h377) {
    (void)load(out1, (int64_t)537264128, 1792, (h377 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h377 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h377 * 14336));
  }
  for (int32_t h378 = 0; h378 < 14; ++h378) {
    for (int32_t w188 = 0; w188 < 14; ++w188) {
      for (int32_t c216 = 0; c216 < 256; ++c216) {
        ((int32_t*)compute)[((((h378 * 3584) + (w188 * 256)) + c216))] = 0;
      }
    }
  }
  for (int32_t h379 = 0; h379 < 14; ++h379) {
    (void)load(out, (int64_t)537264128, 1792, (h379 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h379 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h379 * 14336));
  }
  for (int32_t h380 = 0; h380 < 14; ++h380) {
    for (int32_t w189 = 0; w189 < 14; ++w189) {
      for (int32_t c217 = 0; c217 < 256; ++c217) {
        ((int32_t*)compute)[((((h380 * 3584) + (w189 * 256)) + c217))] = 524288;
      }
    }
  }
  for (int32_t h381 = 0; h381 < 14; ++h381) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h381 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h381 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h381 * 14336));
  }
  for (int32_t h382 = 0; h382 < 14; ++h382) {
    for (int32_t w190 = 0; w190 < 14; ++w190) {
      for (int32_t c218 = 0; c218 < 256; ++c218) {
        ((int32_t*)compute)[((((h382 * 3584) + (w190 * 256)) + c218))] = 20;
      }
    }
  }
  for (int32_t h383 = 0; h383 < 14; ++h383) {
    (void)load(out1, (int64_t)537264128, 1792, (h383 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h383 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h383 * 14336));
  }
  for (int32_t i1191 = 0; i1191 < 14; ++i1191) {
    for (int32_t i2140 = 0; i2140 < 14; ++i2140) {
      for (int32_t i3140 = 0; i3140 < 256; ++i3140) {
        int32_t _106 = ((int32_t*)out)[((((i1191 * 3584) + (i2140 * 256)) + i3140))];
        int32_t _107 = (_106) < (127) ? (_106) : (127);
        ((int32_t*)compute)[((((i1191 * 3584) + (i2140 * 256)) + i3140))] = ((_107) > (-127) ? (_107) : (-127));
      }
    }
  }
  for (int32_t i1192 = 0; i1192 < 14; ++i1192) {
    for (int32_t i2141 = 0; i2141 < 14; ++i2141) {
      for (int32_t i3141 = 0; i3141 < 256; ++i3141) {
        ((int8_t*)T_reshape1)[((((i1192 * 3584) + (i2141 * 256)) + i3141))] = ((int8_t)((int32_t*)compute)[((((i1192 * 3584) + (i2141 * 256)) + i3141))]);
      }
    }
  }
  for (int32_t i1193 = 0; i1193 < 16; ++i1193) {
    for (int32_t i2142 = 0; i2142 < 16; ++i2142) {
      for (int32_t i3142 = 0; i3142 < 256; ++i3142) {
        ((int8_t*)T_reshape)[((((i1193 * 4096) + (i2142 * 256)) + i3142))] = (((((1 <= i1193) && (i1193 < 15)) && (1 <= i2142)) && (i2142 < 15)) ? ((int8_t*)T_reshape1)[(((((i1193 * 3584) + (i2142 * 256)) + i3142) - 3840))] : (int8_t)0);
      }
    }
  }
  for (int32_t o127 = 0; o127 < 14; ++o127) {
    for (int32_t o227 = 0; o227 < 14; ++o227) {
      for (int32_t k19 = 0; k19 < 3; ++k19) {
        for (int32_t k29 = 0; k29 < 3; ++k29) {
          for (int32_t c219 = 0; c219 < 256; ++c219) {
            ((int8_t*)compute)[((((((o127 * 32256) + (o227 * 2304)) + (k19 * 768)) + (k29 * 256)) + c219))] = ((int8_t*)T_reshape)[((((((k19 * 4096) + (o127 * 4096)) + (k29 * 256)) + (o227 * 256)) + c219))];
          }
        }
      }
    }
  }
  for (int32_t ax0290 = 0; ax0290 < 196; ++ax0290) {
    for (int32_t ax1291 = 0; ax1291 < 2304; ++ax1291) {
      ((int8_t*)pad_data)[(((ax0290 * 2304) + ax1291))] = ((int8_t*)compute)[(((ax0290 * 2304) + ax1291))];
    }
  }
  for (int32_t i051 = 0; i051 < 200; ++i051) {
    for (int32_t i1194 = 0; i1194 < 2304; ++i1194) {
      ((int8_t*)compute)[(((i051 * 2304) + i1194))] = ((i051 < 196) ? ((int8_t*)pad_data)[(((i051 * 2304) + i1194))] : (int8_t)0);
    }
  }
  for (int32_t ax0291 = 0; ax0291 < 25; ++ax0291) {
    for (int32_t ax1292 = 0; ax1292 < 8; ++ax1292) {
      for (int32_t ax2244 = 0; ax2244 < 288; ++ax2244) {
        for (int32_t ax3244 = 0; ax3244 < 8; ++ax3244) {
          ((int8_t*)out1)[(((((ax0291 * 18432) + (ax1292 * 2304)) + (ax2244 * 8)) + ax3244))] = ((int8_t*)compute)[(((((ax0291 * 18432) + (ax1292 * 2304)) + (ax2244 * 8)) + ax3244))];
        }
      }
    }
  }
  for (int32_t ax0292 = 0; ax0292 < 25; ++ax0292) {
    for (int32_t ax1293 = 0; ax1293 < 288; ++ax1293) {
      for (int32_t ax2245 = 0; ax2245 < 8; ++ax2245) {
        for (int32_t ax3245 = 0; ax3245 < 8; ++ax3245) {
          ((int8_t*)compute)[(((((ax0292 * 18432) + (ax1293 * 64)) + (ax2245 * 8)) + ax3245))] = ((int8_t*)out1)[(((((ax0292 * 18432) + (ax2245 * 2304)) + (ax1293 * 8)) + ax3245))];
        }
      }
    }
  }
  for (int32_t ax0293 = 0; ax0293 < 25; ++ax0293) {
    for (int32_t ax1294 = 0; ax1294 < 4; ++ax1294) {
      for (int32_t ax2246 = 0; ax2246 < 72; ++ax2246) {
        for (int32_t ax3246 = 0; ax3246 < 8; ++ax3246) {
          for (int32_t ax450 = 0; ax450 < 8; ++ax450) {
            ((int8_t*)out)[((((((ax0293 * 18432) + (ax1294 * 4608)) + (ax2246 * 64)) + (ax3246 * 8)) + ax450))] = ((int8_t*)compute)[((((((ax0293 * 18432) + (ax1294 * 4608)) + (ax2246 * 64)) + (ax3246 * 8)) + ax450))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536870912, 57600, 0);
  for (int32_t ax0294 = 0; ax0294 < 256; ++ax0294) {
    for (int32_t ax1295 = 0; ax1295 < 2304; ++ax1295) {
      ((int8_t*)compute)[(((ax0294 * 2304) + ax1295))] = ((int8_t*)kernel_430)[(((ax0294 * 2304) + ax1295))];
    }
  }
  for (int32_t ax0295 = 0; ax0295 < 32; ++ax0295) {
    for (int32_t ax1296 = 0; ax1296 < 8; ++ax1296) {
      for (int32_t ax2247 = 0; ax2247 < 288; ++ax2247) {
        for (int32_t ax3247 = 0; ax3247 < 8; ++ax3247) {
          ((int8_t*)pad_data)[(((((ax0295 * 18432) + (ax1296 * 2304)) + (ax2247 * 8)) + ax3247))] = ((int8_t*)compute)[(((((ax0295 * 18432) + (ax1296 * 2304)) + (ax2247 * 8)) + ax3247))];
        }
      }
    }
  }
  for (int32_t ax0296 = 0; ax0296 < 32; ++ax0296) {
    for (int32_t ax1297 = 0; ax1297 < 288; ++ax1297) {
      for (int32_t ax2248 = 0; ax2248 < 8; ++ax2248) {
        for (int32_t ax3248 = 0; ax3248 < 8; ++ax3248) {
          ((int8_t*)compute)[(((((ax0296 * 18432) + (ax1297 * 64)) + (ax2248 * 8)) + ax3248))] = ((int8_t*)pad_data)[(((((ax0296 * 18432) + (ax2248 * 2304)) + (ax1297 * 8)) + ax3248))];
        }
      }
    }
  }
  for (int32_t ax0297 = 0; ax0297 < 32; ++ax0297) {
    for (int32_t ax1298 = 0; ax1298 < 4; ++ax1298) {
      for (int32_t ax2249 = 0; ax2249 < 72; ++ax2249) {
        for (int32_t ax3249 = 0; ax3249 < 8; ++ax3249) {
          for (int32_t ax451 = 0; ax451 < 8; ++ax451) {
            ((int8_t*)out1)[((((((ax0297 * 18432) + (ax1298 * 4608)) + (ax2249 * 64)) + (ax3249 * 8)) + ax451))] = ((int8_t*)compute)[((((((ax0297 * 18432) + (ax1298 * 4608)) + (ax2249 * 64)) + (ax3249 * 8)) + ax451))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 73728, 0);
  for (int32_t i62 = 0; i62 < 25; ++i62) {
    for (int32_t x31 = 0; x31 < 32; ++x31) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k06 = 0; k06 < 4; ++k06) {
        (void)move(((((int64_t)((i62 * 1152) + (k06 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x31 * 1152) + (k06 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute, (int64_t)537264128, 32, ((i62 * 8192) + (x31 * 256)));
    }
  }
  for (int32_t ax0298 = 0; ax0298 < 25; ++ax0298) {
    for (int32_t ax1299 = 0; ax1299 < 8; ++ax1299) {
      for (int32_t ax2250 = 0; ax2250 < 32; ++ax2250) {
        for (int32_t ax3250 = 0; ax3250 < 8; ++ax3250) {
          ((int32_t*)out)[(((((ax0298 * 2048) + (ax1299 * 256)) + (ax2250 * 8)) + ax3250))] = ((int32_t*)compute)[(((((ax0298 * 2048) + (ax2250 * 64)) + (ax1299 * 8)) + ax3250))];
        }
      }
    }
  }
  for (int32_t ax0299 = 0; ax0299 < 196; ++ax0299) {
    for (int32_t ax1300 = 0; ax1300 < 256; ++ax1300) {
      ((int32_t*)compute)[(((ax0299 * 256) + ax1300))] = ((int32_t*)out)[(((ax0299 * 256) + ax1300))];
    }
  }
  for (int32_t i052 = 0; i052 < 196; ++i052) {
    for (int32_t i1195 = 0; i1195 < 256; ++i1195) {
      ((int32_t*)pad_data)[(((i052 * 256) + i1195))] = ((int32_t*)compute)[(((i052 * 256) + i1195))];
    }
  }
  for (int32_t ax1301 = 0; ax1301 < 14; ++ax1301) {
    for (int32_t ax2251 = 0; ax2251 < 14; ++ax2251) {
      for (int32_t ax3251 = 0; ax3251 < 256; ++ax3251) {
        ((int32_t*)compute)[((((ax1301 * 3584) + (ax2251 * 256)) + ax3251))] = ((int32_t*)pad_data)[((((ax1301 * 3584) + (ax2251 * 256)) + ax3251))];
      }
    }
  }
  for (int32_t h384 = 0; h384 < 14; ++h384) {
    for (int32_t w191 = 0; w191 < 14; ++w191) {
      for (int32_t c220 = 0; c220 < 256; ++c220) {
        ((int32_t*)out1)[((((h384 * 3584) + (w191 * 256)) + c220))] = ((int32_t*)tensor_431)[(c220)];
      }
    }
  }
  for (int32_t h385 = 0; h385 < 14; ++h385) {
    (void)load(compute, (int64_t)537264128, 1792, (h385 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h385 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h385 * 14336));
  }
  for (int32_t h386 = 0; h386 < 14; ++h386) {
    for (int32_t w192 = 0; w192 < 14; ++w192) {
      for (int32_t c221 = 0; c221 < 256; ++c221) {
        ((int32_t*)compute)[((((h386 * 3584) + (w192 * 256)) + c221))] = 0;
      }
    }
  }
  for (int32_t h387 = 0; h387 < 14; ++h387) {
    (void)load(out, (int64_t)537264128, 1792, (h387 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h387 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h387 * 14336));
  }
  for (int32_t h388 = 0; h388 < 14; ++h388) {
    for (int32_t w193 = 0; w193 < 14; ++w193) {
      for (int32_t c222 = 0; c222 < 256; ++c222) {
        ((int32_t*)compute)[((((h388 * 3584) + (w193 * 256)) + c222))] = 64;
      }
    }
  }
  for (int32_t h389 = 0; h389 < 14; ++h389) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h389 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h389 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h389 * 14336));
  }
  for (int32_t h390 = 0; h390 < 14; ++h390) {
    for (int32_t w194 = 0; w194 < 14; ++w194) {
      for (int32_t c223 = 0; c223 < 256; ++c223) {
        ((int32_t*)compute)[((((h390 * 3584) + (w194 * 256)) + c223))] = 7;
      }
    }
  }
  for (int32_t h391 = 0; h391 < 14; ++h391) {
    (void)load(out1, (int64_t)537264128, 1792, (h391 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h391 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h391 * 14336));
  }
  for (int32_t i1196 = 0; i1196 < 14; ++i1196) {
    for (int32_t i2143 = 0; i2143 < 14; ++i2143) {
      for (int32_t i3143 = 0; i3143 < 256; ++i3143) {
        int32_t _108 = ((int32_t*)out)[((((i1196 * 3584) + (i2143 * 256)) + i3143))];
        int32_t _109 = (_108) < (127) ? (_108) : (127);
        ((int32_t*)compute)[((((i1196 * 3584) + (i2143 * 256)) + i3143))] = ((_109) > (-127) ? (_109) : (-127));
      }
    }
  }
  for (int32_t i1197 = 0; i1197 < 14; ++i1197) {
    for (int32_t i2144 = 0; i2144 < 14; ++i2144) {
      for (int32_t i3144 = 0; i3144 < 256; ++i3144) {
        ((int8_t*)T_reshape1)[((((i1197 * 3584) + (i2144 * 256)) + i3144))] = ((int8_t)((int32_t*)compute)[((((i1197 * 3584) + (i2144 * 256)) + i3144))]);
      }
    }
  }
  for (int32_t o128 = 0; o128 < 14; ++o128) {
    for (int32_t o228 = 0; o228 < 14; ++o228) {
      for (int32_t c224 = 0; c224 < 256; ++c224) {
        ((int8_t*)T_reshape)[((((o128 * 3584) + (o228 * 256)) + c224))] = ((int8_t*)T_reshape1)[((((o128 * 3584) + (o228 * 256)) + c224))];
      }
    }
  }
  for (int32_t ax0300 = 0; ax0300 < 196; ++ax0300) {
    for (int32_t ax1302 = 0; ax1302 < 256; ++ax1302) {
      ((int8_t*)T_reshape1)[(((ax0300 * 256) + ax1302))] = ((int8_t*)T_reshape)[(((ax0300 * 256) + ax1302))];
    }
  }
  for (int32_t i053 = 0; i053 < 200; ++i053) {
    for (int32_t i1198 = 0; i1198 < 256; ++i1198) {
      ((int8_t*)T_reshape)[(((i053 * 256) + i1198))] = ((i053 < 196) ? ((int8_t*)T_reshape1)[(((i053 * 256) + i1198))] : (int8_t)0);
    }
  }
  for (int32_t ax0301 = 0; ax0301 < 25; ++ax0301) {
    for (int32_t ax1303 = 0; ax1303 < 8; ++ax1303) {
      for (int32_t ax2252 = 0; ax2252 < 32; ++ax2252) {
        for (int32_t ax3252 = 0; ax3252 < 8; ++ax3252) {
          ((int8_t*)T_reshape1)[(((((ax0301 * 2048) + (ax1303 * 256)) + (ax2252 * 8)) + ax3252))] = ((int8_t*)T_reshape)[(((((ax0301 * 2048) + (ax1303 * 256)) + (ax2252 * 8)) + ax3252))];
        }
      }
    }
  }
  for (int32_t ax0302 = 0; ax0302 < 25; ++ax0302) {
    for (int32_t ax1304 = 0; ax1304 < 32; ++ax1304) {
      for (int32_t ax2253 = 0; ax2253 < 8; ++ax2253) {
        for (int32_t ax3253 = 0; ax3253 < 8; ++ax3253) {
          ((int8_t*)T_reshape)[(((((ax0302 * 2048) + (ax1304 * 64)) + (ax2253 * 8)) + ax3253))] = ((int8_t*)T_reshape1)[(((((ax0302 * 2048) + (ax2253 * 256)) + (ax1304 * 8)) + ax3253))];
        }
      }
    }
  }
  for (int32_t ax0303 = 0; ax0303 < 25; ++ax0303) {
    for (int32_t ax2254 = 0; ax2254 < 32; ++ax2254) {
      for (int32_t ax3254 = 0; ax3254 < 8; ++ax3254) {
        for (int32_t ax452 = 0; ax452 < 8; ++ax452) {
          ((int8_t*)T_reshape1)[(((((ax0303 * 2048) + (ax2254 * 64)) + (ax3254 * 8)) + ax452))] = ((int8_t*)T_reshape)[(((((ax0303 * 2048) + (ax2254 * 64)) + (ax3254 * 8)) + ax452))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 6400, 0);
  for (int32_t ax0304 = 0; ax0304 < 1024; ++ax0304) {
    for (int32_t ax1305 = 0; ax1305 < 256; ++ax1305) {
      ((int8_t*)compute)[(((ax0304 * 256) + ax1305))] = ((int8_t*)kernel_438)[(((ax0304 * 256) + ax1305))];
    }
  }
  for (int32_t ax0305 = 0; ax0305 < 128; ++ax0305) {
    for (int32_t ax1306 = 0; ax1306 < 8; ++ax1306) {
      for (int32_t ax2255 = 0; ax2255 < 32; ++ax2255) {
        for (int32_t ax3255 = 0; ax3255 < 8; ++ax3255) {
          ((int8_t*)pad_data)[(((((ax0305 * 2048) + (ax1306 * 256)) + (ax2255 * 8)) + ax3255))] = ((int8_t*)compute)[(((((ax0305 * 2048) + (ax1306 * 256)) + (ax2255 * 8)) + ax3255))];
        }
      }
    }
  }
  for (int32_t ax0306 = 0; ax0306 < 128; ++ax0306) {
    for (int32_t ax1307 = 0; ax1307 < 32; ++ax1307) {
      for (int32_t ax2256 = 0; ax2256 < 8; ++ax2256) {
        for (int32_t ax3256 = 0; ax3256 < 8; ++ax3256) {
          ((int8_t*)compute)[(((((ax0306 * 2048) + (ax1307 * 64)) + (ax2256 * 8)) + ax3256))] = ((int8_t*)pad_data)[(((((ax0306 * 2048) + (ax2256 * 256)) + (ax1307 * 8)) + ax3256))];
        }
      }
    }
  }
  for (int32_t ax0307 = 0; ax0307 < 128; ++ax0307) {
    for (int32_t ax2257 = 0; ax2257 < 32; ++ax2257) {
      for (int32_t ax3257 = 0; ax3257 < 8; ++ax3257) {
        for (int32_t ax453 = 0; ax453 < 8; ++ax453) {
          ((int8_t*)out1)[(((((ax0307 * 2048) + (ax2257 * 64)) + (ax3257 * 8)) + ax453))] = ((int8_t*)compute)[(((((ax0307 * 2048) + (ax2257 * 64)) + (ax3257 * 8)) + ax453))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 32768, 0);
  for (int32_t i63 = 0; i63 < 25; ++i63) {
    for (int32_t x32 = 0; x32 < 128; ++x32) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i63 * 128) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x32 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(out, (int64_t)537264128, 32, ((i63 * 32768) + (x32 * 256)));
    }
  }
  for (int32_t ax0308 = 0; ax0308 < 25; ++ax0308) {
    for (int32_t ax1308 = 0; ax1308 < 8; ++ax1308) {
      for (int32_t ax2258 = 0; ax2258 < 128; ++ax2258) {
        for (int32_t ax3258 = 0; ax3258 < 8; ++ax3258) {
          ((int32_t*)pad_data)[(((((ax0308 * 8192) + (ax1308 * 1024)) + (ax2258 * 8)) + ax3258))] = ((int32_t*)out)[(((((ax0308 * 8192) + (ax2258 * 64)) + (ax1308 * 8)) + ax3258))];
        }
      }
    }
  }
  for (int32_t ax0309 = 0; ax0309 < 196; ++ax0309) {
    for (int32_t ax1309 = 0; ax1309 < 1024; ++ax1309) {
      ((int32_t*)compute)[(((ax0309 * 1024) + ax1309))] = ((int32_t*)pad_data)[(((ax0309 * 1024) + ax1309))];
    }
  }
  for (int32_t i054 = 0; i054 < 196; ++i054) {
    for (int32_t i1199 = 0; i1199 < 1024; ++i1199) {
      ((int32_t*)out1)[(((i054 * 1024) + i1199))] = ((int32_t*)compute)[(((i054 * 1024) + i1199))];
    }
  }
  for (int32_t ax1310 = 0; ax1310 < 14; ++ax1310) {
    for (int32_t ax2259 = 0; ax2259 < 14; ++ax2259) {
      for (int32_t ax3259 = 0; ax3259 < 1024; ++ax3259) {
        ((int32_t*)compute)[((((ax1310 * 14336) + (ax2259 * 1024)) + ax3259))] = ((int32_t*)out1)[((((ax1310 * 14336) + (ax2259 * 1024)) + ax3259))];
      }
    }
  }
  for (int32_t h392 = 0; h392 < 14; ++h392) {
    for (int32_t w195 = 0; w195 < 14; ++w195) {
      for (int32_t c225 = 0; c225 < 1024; ++c225) {
        ((int32_t*)out)[((((h392 * 14336) + (w195 * 1024)) + c225))] = 10;
      }
    }
  }
  for (int32_t h393 = 0; h393 < 14; ++h393) {
    (void)load(compute, (int64_t)537264128, 7168, (h393 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h393 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h393 * 57344));
  }
  for (int32_t h394 = 0; h394 < 14; ++h394) {
    for (int32_t w196 = 0; w196 < 14; ++w196) {
      for (int32_t c226 = 0; c226 < 1024; ++c226) {
        ((int32_t*)compute)[((((h394 * 14336) + (w196 * 1024)) + c226))] = ((int32_t*)tensor_440)[(c226)];
      }
    }
  }
  for (int32_t h395 = 0; h395 < 14; ++h395) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h395 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h395 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h395 * 57344));
  }
  for (int32_t h396 = 0; h396 < 14; ++h396) {
    for (int32_t w197 = 0; w197 < 14; ++w197) {
      for (int32_t c227 = 0; c227 < 1024; ++c227) {
        ((int32_t*)compute)[((((h396 * 14336) + (w197 * 1024)) + c227))] = 131072;
      }
    }
  }
  for (int32_t h397 = 0; h397 < 14; ++h397) {
    (void)load(out1, (int64_t)537264128, 7168, (h397 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h397 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h397 * 57344));
  }
  for (int32_t h398 = 0; h398 < 14; ++h398) {
    for (int32_t w198 = 0; w198 < 14; ++w198) {
      for (int32_t c228 = 0; c228 < 1024; ++c228) {
        ((int32_t*)compute)[((((h398 * 14336) + (w198 * 1024)) + c228))] = 18;
      }
    }
  }
  for (int32_t h399 = 0; h399 < 14; ++h399) {
    (void)load(out, (int64_t)537264128, 7168, (h399 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h399 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h399 * 57344));
  }
  for (int32_t i1200 = 0; i1200 < 14; ++i1200) {
    for (int32_t i2145 = 0; i2145 < 14; ++i2145) {
      for (int32_t i3145 = 0; i3145 < 1024; ++i3145) {
        int32_t _110 = ((int32_t*)pad_data)[((((i1200 * 14336) + (i2145 * 1024)) + i3145))];
        int32_t _111 = (_110) < (127) ? (_110) : (127);
        ((int32_t*)compute)[((((i1200 * 14336) + (i2145 * 1024)) + i3145))] = ((_111) > (-127) ? (_111) : (-127));
      }
    }
  }
  for (int32_t i1201 = 0; i1201 < 14; ++i1201) {
    for (int32_t i2146 = 0; i2146 < 14; ++i2146) {
      for (int32_t i3146 = 0; i3146 < 1024; ++i3146) {
        ((int8_t*)out1)[((((i1201 * 14336) + (i2146 * 1024)) + i3146))] = ((int8_t)((int32_t*)compute)[((((i1201 * 14336) + (i2146 * 1024)) + i3146))]);
      }
    }
  }
  for (int32_t i1202 = 0; i1202 < 14; ++i1202) {
    for (int32_t i2147 = 0; i2147 < 14; ++i2147) {
      for (int32_t i3147 = 0; i3147 < 1024; ++i3147) {
        ((int32_t*)compute)[((((i1202 * 14336) + (i2147 * 1024)) + i3147))] = ((int32_t)((int8_t*)out1)[((((i1202 * 14336) + (i2147 * 1024)) + i3147))]);
      }
    }
  }
  for (int32_t h400 = 0; h400 < 14; ++h400) {
    for (int32_t w199 = 0; w199 < 14; ++w199) {
      for (int32_t c229 = 0; c229 < 1024; ++c229) {
        ((int32_t*)out)[((((h400 * 14336) + (w199 * 1024)) + c229))] = ((int32_t*)tensor_447)[(c229)];
      }
    }
  }
  for (int32_t h401 = 0; h401 < 14; ++h401) {
    (void)load(compute, (int64_t)537264128, 7168, (h401 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h401 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h401 * 57344));
  }
  for (int32_t h402 = 0; h402 < 14; ++h402) {
    for (int32_t w200 = 0; w200 < 14; ++w200) {
      for (int32_t c230 = 0; c230 < 1024; ++c230) {
        ((int32_t*)compute)[((((h402 * 14336) + (w200 * 1024)) + c230))] = ((int32_t*)tensor_448)[(c230)];
      }
    }
  }
  for (int32_t h403 = 0; h403 < 14; ++h403) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h403 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h403 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h403 * 57344));
  }
  for (int32_t h404 = 0; h404 < 14; ++h404) {
    for (int32_t w201 = 0; w201 < 14; ++w201) {
      for (int32_t c231 = 0; c231 < 1024; ++c231) {
        ((int32_t*)compute)[((((h404 * 14336) + (w201 * 1024)) + c231))] = 8;
      }
    }
  }
  for (int32_t h405 = 0; h405 < 14; ++h405) {
    (void)load(out1, (int64_t)537264128, 7168, (h405 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h405 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h405 * 57344));
  }
  for (int32_t h406 = 0; h406 < 14; ++h406) {
    for (int32_t w202 = 0; w202 < 14; ++w202) {
      for (int32_t c232 = 0; c232 < 1024; ++c232) {
        ((int32_t*)compute)[((((h406 * 14336) + (w202 * 1024)) + c232))] = 4;
      }
    }
  }
  for (int32_t h407 = 0; h407 < 14; ++h407) {
    (void)load(out, (int64_t)537264128, 7168, (h407 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h407 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h407 * 57344));
  }
  for (int32_t i1203 = 0; i1203 < 14; ++i1203) {
    for (int32_t i2148 = 0; i2148 < 14; ++i2148) {
      for (int32_t i3148 = 0; i3148 < 1024; ++i3148) {
        int32_t _112 = ((int32_t*)pad_data)[((((i1203 * 14336) + (i2148 * 1024)) + i3148))];
        int32_t _113 = (_112) < (127) ? (_112) : (127);
        ((int32_t*)compute)[((((i1203 * 14336) + (i2148 * 1024)) + i3148))] = ((_113) > (-127) ? (_113) : (-127));
      }
    }
  }
  for (int32_t i1204 = 0; i1204 < 14; ++i1204) {
    for (int32_t i2149 = 0; i2149 < 14; ++i2149) {
      for (int32_t i3149 = 0; i3149 < 1024; ++i3149) {
        ((int8_t*)out1)[((((i1204 * 14336) + (i2149 * 1024)) + i3149))] = ((int8_t)((int32_t*)compute)[((((i1204 * 14336) + (i2149 * 1024)) + i3149))]);
      }
    }
  }
  for (int32_t i1205 = 0; i1205 < 14; ++i1205) {
    for (int32_t i2150 = 0; i2150 < 14; ++i2150) {
      for (int32_t i3150 = 0; i3150 < 1024; ++i3150) {
        ((int32_t*)compute)[((((i1205 * 14336) + (i2150 * 1024)) + i3150))] = ((int32_t)((int8_t*)out1)[((((i1205 * 14336) + (i2150 * 1024)) + i3150))]);
      }
    }
  }
  for (int32_t i1206 = 0; i1206 < 14; ++i1206) {
    for (int32_t i2151 = 0; i2151 < 14; ++i2151) {
      for (int32_t i3151 = 0; i3151 < 1024; ++i3151) {
        ((int32_t*)out)[((((i1206 * 14336) + (i2151 * 1024)) + i3151))] = ((int32_t)((int8_t*)compute1)[((((i1206 * 14336) + (i2151 * 1024)) + i3151))]);
      }
    }
  }
  for (int32_t h408 = 0; h408 < 14; ++h408) {
    (void)load(compute, (int64_t)537264128, 7168, (h408 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h408 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h408 * 57344));
  }
  for (int32_t h409 = 0; h409 < 14; ++h409) {
    for (int32_t w203 = 0; w203 < 14; ++w203) {
      for (int32_t c233 = 0; c233 < 1024; ++c233) {
        ((int32_t*)compute)[((((h409 * 14336) + (w203 * 1024)) + c233))] = 0;
      }
    }
  }
  for (int32_t h410 = 0; h410 < 14; ++h410) {
    (void)load(compute1, (int64_t)537264128, 7168, (h410 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h410 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h410 * 57344));
  }
  for (int32_t i1207 = 0; i1207 < 14; ++i1207) {
    for (int32_t i2152 = 0; i2152 < 14; ++i2152) {
      for (int32_t i3152 = 0; i3152 < 1024; ++i3152) {
        int32_t _114 = ((int32_t*)pad_data)[((((i1207 * 14336) + (i2152 * 1024)) + i3152))];
        int32_t _115 = (_114) < (127) ? (_114) : (127);
        ((int32_t*)compute)[((((i1207 * 14336) + (i2152 * 1024)) + i3152))] = ((_115) > (-127) ? (_115) : (-127));
      }
    }
  }
  for (int32_t i1208 = 0; i1208 < 14; ++i1208) {
    for (int32_t i2153 = 0; i2153 < 14; ++i2153) {
      for (int32_t i3153 = 0; i3153 < 1024; ++i3153) {
        ((int8_t*)compute1)[((((i1208 * 14336) + (i2153 * 1024)) + i3153))] = ((int8_t)((int32_t*)compute)[((((i1208 * 14336) + (i2153 * 1024)) + i3153))]);
      }
    }
  }
  for (int32_t o129 = 0; o129 < 14; ++o129) {
    for (int32_t o229 = 0; o229 < 14; ++o229) {
      for (int32_t c234 = 0; c234 < 1024; ++c234) {
        ((int8_t*)compute)[((((o129 * 14336) + (o229 * 1024)) + c234))] = ((int8_t*)compute1)[((((o129 * 14336) + (o229 * 1024)) + c234))];
      }
    }
  }
  for (int32_t ax0310 = 0; ax0310 < 196; ++ax0310) {
    for (int32_t ax1311 = 0; ax1311 < 1024; ++ax1311) {
      ((int8_t*)out1)[(((ax0310 * 1024) + ax1311))] = ((int8_t*)compute)[(((ax0310 * 1024) + ax1311))];
    }
  }
  for (int32_t i055 = 0; i055 < 200; ++i055) {
    for (int32_t i1209 = 0; i1209 < 1024; ++i1209) {
      ((int8_t*)compute)[(((i055 * 1024) + i1209))] = ((i055 < 196) ? ((int8_t*)out1)[(((i055 * 1024) + i1209))] : (int8_t)0);
    }
  }
  for (int32_t ax0311 = 0; ax0311 < 25; ++ax0311) {
    for (int32_t ax1312 = 0; ax1312 < 8; ++ax1312) {
      for (int32_t ax2260 = 0; ax2260 < 128; ++ax2260) {
        for (int32_t ax3260 = 0; ax3260 < 8; ++ax3260) {
          ((int8_t*)out)[(((((ax0311 * 8192) + (ax1312 * 1024)) + (ax2260 * 8)) + ax3260))] = ((int8_t*)compute)[(((((ax0311 * 8192) + (ax1312 * 1024)) + (ax2260 * 8)) + ax3260))];
        }
      }
    }
  }
  for (int32_t ax0312 = 0; ax0312 < 25; ++ax0312) {
    for (int32_t ax1313 = 0; ax1313 < 128; ++ax1313) {
      for (int32_t ax2261 = 0; ax2261 < 8; ++ax2261) {
        for (int32_t ax3261 = 0; ax3261 < 8; ++ax3261) {
          ((int8_t*)compute)[(((((ax0312 * 8192) + (ax1313 * 64)) + (ax2261 * 8)) + ax3261))] = ((int8_t*)out)[(((((ax0312 * 8192) + (ax2261 * 1024)) + (ax1313 * 8)) + ax3261))];
        }
      }
    }
  }
  for (int32_t ax0313 = 0; ax0313 < 25; ++ax0313) {
    for (int32_t ax2262 = 0; ax2262 < 128; ++ax2262) {
      for (int32_t ax3262 = 0; ax3262 < 8; ++ax3262) {
        for (int32_t ax454 = 0; ax454 < 8; ++ax454) {
          ((int8_t*)pad_data)[(((((ax0313 * 8192) + (ax2262 * 64)) + (ax3262 * 8)) + ax454))] = ((int8_t*)compute)[(((((ax0313 * 8192) + (ax2262 * 64)) + (ax3262 * 8)) + ax454))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25600, 0);
  for (int32_t ax0314 = 0; ax0314 < 256; ++ax0314) {
    for (int32_t ax1314 = 0; ax1314 < 1024; ++ax1314) {
      ((int8_t*)compute)[(((ax0314 * 1024) + ax1314))] = ((int8_t*)kernel_463)[(((ax0314 * 1024) + ax1314))];
    }
  }
  for (int32_t ax0315 = 0; ax0315 < 32; ++ax0315) {
    for (int32_t ax1315 = 0; ax1315 < 8; ++ax1315) {
      for (int32_t ax2263 = 0; ax2263 < 128; ++ax2263) {
        for (int32_t ax3263 = 0; ax3263 < 8; ++ax3263) {
          ((int8_t*)out1)[(((((ax0315 * 8192) + (ax1315 * 1024)) + (ax2263 * 8)) + ax3263))] = ((int8_t*)compute)[(((((ax0315 * 8192) + (ax1315 * 1024)) + (ax2263 * 8)) + ax3263))];
        }
      }
    }
  }
  for (int32_t ax0316 = 0; ax0316 < 32; ++ax0316) {
    for (int32_t ax1316 = 0; ax1316 < 128; ++ax1316) {
      for (int32_t ax2264 = 0; ax2264 < 8; ++ax2264) {
        for (int32_t ax3264 = 0; ax3264 < 8; ++ax3264) {
          ((int8_t*)compute)[(((((ax0316 * 8192) + (ax1316 * 64)) + (ax2264 * 8)) + ax3264))] = ((int8_t*)out1)[(((((ax0316 * 8192) + (ax2264 * 1024)) + (ax1316 * 8)) + ax3264))];
        }
      }
    }
  }
  for (int32_t ax0317 = 0; ax0317 < 32; ++ax0317) {
    for (int32_t ax2265 = 0; ax2265 < 128; ++ax2265) {
      for (int32_t ax3265 = 0; ax3265 < 8; ++ax3265) {
        for (int32_t ax455 = 0; ax455 < 8; ++ax455) {
          ((int8_t*)out)[(((((ax0317 * 8192) + (ax2265 * 64)) + (ax3265 * 8)) + ax455))] = ((int8_t*)compute)[(((((ax0317 * 8192) + (ax2265 * 64)) + (ax3265 * 8)) + ax455))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 32768, 0);
  for (int32_t i64 = 0; i64 < 25; ++i64) {
    for (int32_t x33 = 0; x33 < 32; ++x33) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i64 * 512)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x33 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i64 * 8192) + (x33 * 256)));
    }
  }
  for (int32_t ax0318 = 0; ax0318 < 25; ++ax0318) {
    for (int32_t ax1317 = 0; ax1317 < 8; ++ax1317) {
      for (int32_t ax2266 = 0; ax2266 < 32; ++ax2266) {
        for (int32_t ax3266 = 0; ax3266 < 8; ++ax3266) {
          ((int32_t*)pad_data)[(((((ax0318 * 2048) + (ax1317 * 256)) + (ax2266 * 8)) + ax3266))] = ((int32_t*)compute)[(((((ax0318 * 2048) + (ax2266 * 64)) + (ax1317 * 8)) + ax3266))];
        }
      }
    }
  }
  for (int32_t ax0319 = 0; ax0319 < 196; ++ax0319) {
    for (int32_t ax1318 = 0; ax1318 < 256; ++ax1318) {
      ((int32_t*)compute)[(((ax0319 * 256) + ax1318))] = ((int32_t*)pad_data)[(((ax0319 * 256) + ax1318))];
    }
  }
  for (int32_t i056 = 0; i056 < 196; ++i056) {
    for (int32_t i1210 = 0; i1210 < 256; ++i1210) {
      ((int32_t*)out1)[(((i056 * 256) + i1210))] = ((int32_t*)compute)[(((i056 * 256) + i1210))];
    }
  }
  for (int32_t ax1319 = 0; ax1319 < 14; ++ax1319) {
    for (int32_t ax2267 = 0; ax2267 < 14; ++ax2267) {
      for (int32_t ax3267 = 0; ax3267 < 256; ++ax3267) {
        ((int32_t*)compute)[((((ax1319 * 3584) + (ax2267 * 256)) + ax3267))] = ((int32_t*)out1)[((((ax1319 * 3584) + (ax2267 * 256)) + ax3267))];
      }
    }
  }
  for (int32_t h411 = 0; h411 < 14; ++h411) {
    for (int32_t w204 = 0; w204 < 14; ++w204) {
      for (int32_t c235 = 0; c235 < 256; ++c235) {
        ((int32_t*)out)[((((h411 * 3584) + (w204 * 256)) + c235))] = 12;
      }
    }
  }
  for (int32_t h412 = 0; h412 < 14; ++h412) {
    (void)load(compute, (int64_t)537264128, 1792, (h412 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h412 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h412 * 14336));
  }
  for (int32_t h413 = 0; h413 < 14; ++h413) {
    for (int32_t w205 = 0; w205 < 14; ++w205) {
      for (int32_t c236 = 0; c236 < 256; ++c236) {
        ((int32_t*)compute)[((((h413 * 3584) + (w205 * 256)) + c236))] = ((int32_t*)tensor_465)[(c236)];
      }
    }
  }
  for (int32_t h414 = 0; h414 < 14; ++h414) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h414 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h414 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h414 * 14336));
  }
  for (int32_t h415 = 0; h415 < 14; ++h415) {
    for (int32_t w206 = 0; w206 < 14; ++w206) {
      for (int32_t c237 = 0; c237 < 256; ++c237) {
        ((int32_t*)compute)[((((h415 * 3584) + (w206 * 256)) + c237))] = ((int32_t*)tensor_466)[(c237)];
      }
    }
  }
  for (int32_t h416 = 0; h416 < 14; ++h416) {
    (void)load(out1, (int64_t)537264128, 1792, (h416 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h416 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h416 * 14336));
  }
  for (int32_t h417 = 0; h417 < 14; ++h417) {
    for (int32_t w207 = 0; w207 < 14; ++w207) {
      for (int32_t c238 = 0; c238 < 256; ++c238) {
        ((int32_t*)compute)[((((h417 * 3584) + (w207 * 256)) + c238))] = 0;
      }
    }
  }
  for (int32_t h418 = 0; h418 < 14; ++h418) {
    (void)load(out, (int64_t)537264128, 1792, (h418 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h418 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h418 * 14336));
  }
  for (int32_t h419 = 0; h419 < 14; ++h419) {
    for (int32_t w208 = 0; w208 < 14; ++w208) {
      for (int32_t c239 = 0; c239 < 256; ++c239) {
        ((int32_t*)compute)[((((h419 * 3584) + (w208 * 256)) + c239))] = 524288;
      }
    }
  }
  for (int32_t h420 = 0; h420 < 14; ++h420) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h420 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h420 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h420 * 14336));
  }
  for (int32_t h421 = 0; h421 < 14; ++h421) {
    for (int32_t w209 = 0; w209 < 14; ++w209) {
      for (int32_t c240 = 0; c240 < 256; ++c240) {
        ((int32_t*)compute)[((((h421 * 3584) + (w209 * 256)) + c240))] = 20;
      }
    }
  }
  for (int32_t h422 = 0; h422 < 14; ++h422) {
    (void)load(out1, (int64_t)537264128, 1792, (h422 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h422 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h422 * 14336));
  }
  for (int32_t i1211 = 0; i1211 < 14; ++i1211) {
    for (int32_t i2154 = 0; i2154 < 14; ++i2154) {
      for (int32_t i3154 = 0; i3154 < 256; ++i3154) {
        int32_t _116 = ((int32_t*)out)[((((i1211 * 3584) + (i2154 * 256)) + i3154))];
        int32_t _117 = (_116) < (127) ? (_116) : (127);
        ((int32_t*)compute)[((((i1211 * 3584) + (i2154 * 256)) + i3154))] = ((_117) > (-127) ? (_117) : (-127));
      }
    }
  }
  for (int32_t i1212 = 0; i1212 < 14; ++i1212) {
    for (int32_t i2155 = 0; i2155 < 14; ++i2155) {
      for (int32_t i3155 = 0; i3155 < 256; ++i3155) {
        ((int8_t*)T_reshape1)[((((i1212 * 3584) + (i2155 * 256)) + i3155))] = ((int8_t)((int32_t*)compute)[((((i1212 * 3584) + (i2155 * 256)) + i3155))]);
      }
    }
  }
  for (int32_t i1213 = 0; i1213 < 16; ++i1213) {
    for (int32_t i2156 = 0; i2156 < 16; ++i2156) {
      for (int32_t i3156 = 0; i3156 < 256; ++i3156) {
        ((int8_t*)T_reshape)[((((i1213 * 4096) + (i2156 * 256)) + i3156))] = (((((1 <= i1213) && (i1213 < 15)) && (1 <= i2156)) && (i2156 < 15)) ? ((int8_t*)T_reshape1)[(((((i1213 * 3584) + (i2156 * 256)) + i3156) - 3840))] : (int8_t)0);
      }
    }
  }
  for (int32_t o130 = 0; o130 < 14; ++o130) {
    for (int32_t o230 = 0; o230 < 14; ++o230) {
      for (int32_t k110 = 0; k110 < 3; ++k110) {
        for (int32_t k210 = 0; k210 < 3; ++k210) {
          for (int32_t c241 = 0; c241 < 256; ++c241) {
            ((int8_t*)compute)[((((((o130 * 32256) + (o230 * 2304)) + (k110 * 768)) + (k210 * 256)) + c241))] = ((int8_t*)T_reshape)[((((((k110 * 4096) + (o130 * 4096)) + (k210 * 256)) + (o230 * 256)) + c241))];
          }
        }
      }
    }
  }
  for (int32_t ax0320 = 0; ax0320 < 196; ++ax0320) {
    for (int32_t ax1320 = 0; ax1320 < 2304; ++ax1320) {
      ((int8_t*)pad_data)[(((ax0320 * 2304) + ax1320))] = ((int8_t*)compute)[(((ax0320 * 2304) + ax1320))];
    }
  }
  for (int32_t i057 = 0; i057 < 200; ++i057) {
    for (int32_t i1214 = 0; i1214 < 2304; ++i1214) {
      ((int8_t*)compute)[(((i057 * 2304) + i1214))] = ((i057 < 196) ? ((int8_t*)pad_data)[(((i057 * 2304) + i1214))] : (int8_t)0);
    }
  }
  for (int32_t ax0321 = 0; ax0321 < 25; ++ax0321) {
    for (int32_t ax1321 = 0; ax1321 < 8; ++ax1321) {
      for (int32_t ax2268 = 0; ax2268 < 288; ++ax2268) {
        for (int32_t ax3268 = 0; ax3268 < 8; ++ax3268) {
          ((int8_t*)out1)[(((((ax0321 * 18432) + (ax1321 * 2304)) + (ax2268 * 8)) + ax3268))] = ((int8_t*)compute)[(((((ax0321 * 18432) + (ax1321 * 2304)) + (ax2268 * 8)) + ax3268))];
        }
      }
    }
  }
  for (int32_t ax0322 = 0; ax0322 < 25; ++ax0322) {
    for (int32_t ax1322 = 0; ax1322 < 288; ++ax1322) {
      for (int32_t ax2269 = 0; ax2269 < 8; ++ax2269) {
        for (int32_t ax3269 = 0; ax3269 < 8; ++ax3269) {
          ((int8_t*)compute)[(((((ax0322 * 18432) + (ax1322 * 64)) + (ax2269 * 8)) + ax3269))] = ((int8_t*)out1)[(((((ax0322 * 18432) + (ax2269 * 2304)) + (ax1322 * 8)) + ax3269))];
        }
      }
    }
  }
  for (int32_t ax0323 = 0; ax0323 < 25; ++ax0323) {
    for (int32_t ax1323 = 0; ax1323 < 4; ++ax1323) {
      for (int32_t ax2270 = 0; ax2270 < 72; ++ax2270) {
        for (int32_t ax3270 = 0; ax3270 < 8; ++ax3270) {
          for (int32_t ax456 = 0; ax456 < 8; ++ax456) {
            ((int8_t*)out)[((((((ax0323 * 18432) + (ax1323 * 4608)) + (ax2270 * 64)) + (ax3270 * 8)) + ax456))] = ((int8_t*)compute)[((((((ax0323 * 18432) + (ax1323 * 4608)) + (ax2270 * 64)) + (ax3270 * 8)) + ax456))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536870912, 57600, 0);
  for (int32_t ax0324 = 0; ax0324 < 256; ++ax0324) {
    for (int32_t ax1324 = 0; ax1324 < 2304; ++ax1324) {
      ((int8_t*)compute)[(((ax0324 * 2304) + ax1324))] = ((int8_t*)kernel_473)[(((ax0324 * 2304) + ax1324))];
    }
  }
  for (int32_t ax0325 = 0; ax0325 < 32; ++ax0325) {
    for (int32_t ax1325 = 0; ax1325 < 8; ++ax1325) {
      for (int32_t ax2271 = 0; ax2271 < 288; ++ax2271) {
        for (int32_t ax3271 = 0; ax3271 < 8; ++ax3271) {
          ((int8_t*)pad_data)[(((((ax0325 * 18432) + (ax1325 * 2304)) + (ax2271 * 8)) + ax3271))] = ((int8_t*)compute)[(((((ax0325 * 18432) + (ax1325 * 2304)) + (ax2271 * 8)) + ax3271))];
        }
      }
    }
  }
  for (int32_t ax0326 = 0; ax0326 < 32; ++ax0326) {
    for (int32_t ax1326 = 0; ax1326 < 288; ++ax1326) {
      for (int32_t ax2272 = 0; ax2272 < 8; ++ax2272) {
        for (int32_t ax3272 = 0; ax3272 < 8; ++ax3272) {
          ((int8_t*)compute)[(((((ax0326 * 18432) + (ax1326 * 64)) + (ax2272 * 8)) + ax3272))] = ((int8_t*)pad_data)[(((((ax0326 * 18432) + (ax2272 * 2304)) + (ax1326 * 8)) + ax3272))];
        }
      }
    }
  }
  for (int32_t ax0327 = 0; ax0327 < 32; ++ax0327) {
    for (int32_t ax1327 = 0; ax1327 < 4; ++ax1327) {
      for (int32_t ax2273 = 0; ax2273 < 72; ++ax2273) {
        for (int32_t ax3273 = 0; ax3273 < 8; ++ax3273) {
          for (int32_t ax457 = 0; ax457 < 8; ++ax457) {
            ((int8_t*)out1)[((((((ax0327 * 18432) + (ax1327 * 4608)) + (ax2273 * 64)) + (ax3273 * 8)) + ax457))] = ((int8_t*)compute)[((((((ax0327 * 18432) + (ax1327 * 4608)) + (ax2273 * 64)) + (ax3273 * 8)) + ax457))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 73728, 0);
  for (int32_t i65 = 0; i65 < 25; ++i65) {
    for (int32_t x34 = 0; x34 < 32; ++x34) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k07 = 0; k07 < 4; ++k07) {
        (void)move(((((int64_t)((i65 * 1152) + (k07 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x34 * 1152) + (k07 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute, (int64_t)537264128, 32, ((i65 * 8192) + (x34 * 256)));
    }
  }
  for (int32_t ax0328 = 0; ax0328 < 25; ++ax0328) {
    for (int32_t ax1328 = 0; ax1328 < 8; ++ax1328) {
      for (int32_t ax2274 = 0; ax2274 < 32; ++ax2274) {
        for (int32_t ax3274 = 0; ax3274 < 8; ++ax3274) {
          ((int32_t*)out)[(((((ax0328 * 2048) + (ax1328 * 256)) + (ax2274 * 8)) + ax3274))] = ((int32_t*)compute)[(((((ax0328 * 2048) + (ax2274 * 64)) + (ax1328 * 8)) + ax3274))];
        }
      }
    }
  }
  for (int32_t ax0329 = 0; ax0329 < 196; ++ax0329) {
    for (int32_t ax1329 = 0; ax1329 < 256; ++ax1329) {
      ((int32_t*)compute)[(((ax0329 * 256) + ax1329))] = ((int32_t*)out)[(((ax0329 * 256) + ax1329))];
    }
  }
  for (int32_t i058 = 0; i058 < 196; ++i058) {
    for (int32_t i1215 = 0; i1215 < 256; ++i1215) {
      ((int32_t*)pad_data)[(((i058 * 256) + i1215))] = ((int32_t*)compute)[(((i058 * 256) + i1215))];
    }
  }
  for (int32_t ax1330 = 0; ax1330 < 14; ++ax1330) {
    for (int32_t ax2275 = 0; ax2275 < 14; ++ax2275) {
      for (int32_t ax3275 = 0; ax3275 < 256; ++ax3275) {
        ((int32_t*)compute)[((((ax1330 * 3584) + (ax2275 * 256)) + ax3275))] = ((int32_t*)pad_data)[((((ax1330 * 3584) + (ax2275 * 256)) + ax3275))];
      }
    }
  }
  for (int32_t h423 = 0; h423 < 14; ++h423) {
    for (int32_t w210 = 0; w210 < 14; ++w210) {
      for (int32_t c242 = 0; c242 < 256; ++c242) {
        ((int32_t*)out1)[((((h423 * 3584) + (w210 * 256)) + c242))] = ((int32_t*)tensor_474)[(c242)];
      }
    }
  }
  for (int32_t h424 = 0; h424 < 14; ++h424) {
    (void)load(compute, (int64_t)537264128, 1792, (h424 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h424 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h424 * 14336));
  }
  for (int32_t h425 = 0; h425 < 14; ++h425) {
    for (int32_t w211 = 0; w211 < 14; ++w211) {
      for (int32_t c243 = 0; c243 < 256; ++c243) {
        ((int32_t*)compute)[((((h425 * 3584) + (w211 * 256)) + c243))] = 0;
      }
    }
  }
  for (int32_t h426 = 0; h426 < 14; ++h426) {
    (void)load(out, (int64_t)537264128, 1792, (h426 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h426 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h426 * 14336));
  }
  for (int32_t h427 = 0; h427 < 14; ++h427) {
    for (int32_t w212 = 0; w212 < 14; ++w212) {
      for (int32_t c244 = 0; c244 < 256; ++c244) {
        ((int32_t*)compute)[((((h427 * 3584) + (w212 * 256)) + c244))] = 64;
      }
    }
  }
  for (int32_t h428 = 0; h428 < 14; ++h428) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h428 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h428 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h428 * 14336));
  }
  for (int32_t h429 = 0; h429 < 14; ++h429) {
    for (int32_t w213 = 0; w213 < 14; ++w213) {
      for (int32_t c245 = 0; c245 < 256; ++c245) {
        ((int32_t*)compute)[((((h429 * 3584) + (w213 * 256)) + c245))] = 7;
      }
    }
  }
  for (int32_t h430 = 0; h430 < 14; ++h430) {
    (void)load(out1, (int64_t)537264128, 1792, (h430 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h430 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h430 * 14336));
  }
  for (int32_t i1216 = 0; i1216 < 14; ++i1216) {
    for (int32_t i2157 = 0; i2157 < 14; ++i2157) {
      for (int32_t i3157 = 0; i3157 < 256; ++i3157) {
        int32_t _118 = ((int32_t*)out)[((((i1216 * 3584) + (i2157 * 256)) + i3157))];
        int32_t _119 = (_118) < (127) ? (_118) : (127);
        ((int32_t*)compute)[((((i1216 * 3584) + (i2157 * 256)) + i3157))] = ((_119) > (-127) ? (_119) : (-127));
      }
    }
  }
  for (int32_t i1217 = 0; i1217 < 14; ++i1217) {
    for (int32_t i2158 = 0; i2158 < 14; ++i2158) {
      for (int32_t i3158 = 0; i3158 < 256; ++i3158) {
        ((int8_t*)T_reshape1)[((((i1217 * 3584) + (i2158 * 256)) + i3158))] = ((int8_t)((int32_t*)compute)[((((i1217 * 3584) + (i2158 * 256)) + i3158))]);
      }
    }
  }
  for (int32_t o131 = 0; o131 < 14; ++o131) {
    for (int32_t o231 = 0; o231 < 14; ++o231) {
      for (int32_t c246 = 0; c246 < 256; ++c246) {
        ((int8_t*)T_reshape)[((((o131 * 3584) + (o231 * 256)) + c246))] = ((int8_t*)T_reshape1)[((((o131 * 3584) + (o231 * 256)) + c246))];
      }
    }
  }
  for (int32_t ax0330 = 0; ax0330 < 196; ++ax0330) {
    for (int32_t ax1331 = 0; ax1331 < 256; ++ax1331) {
      ((int8_t*)T_reshape1)[(((ax0330 * 256) + ax1331))] = ((int8_t*)T_reshape)[(((ax0330 * 256) + ax1331))];
    }
  }
  for (int32_t i059 = 0; i059 < 200; ++i059) {
    for (int32_t i1218 = 0; i1218 < 256; ++i1218) {
      ((int8_t*)T_reshape)[(((i059 * 256) + i1218))] = ((i059 < 196) ? ((int8_t*)T_reshape1)[(((i059 * 256) + i1218))] : (int8_t)0);
    }
  }
  for (int32_t ax0331 = 0; ax0331 < 25; ++ax0331) {
    for (int32_t ax1332 = 0; ax1332 < 8; ++ax1332) {
      for (int32_t ax2276 = 0; ax2276 < 32; ++ax2276) {
        for (int32_t ax3276 = 0; ax3276 < 8; ++ax3276) {
          ((int8_t*)T_reshape1)[(((((ax0331 * 2048) + (ax1332 * 256)) + (ax2276 * 8)) + ax3276))] = ((int8_t*)T_reshape)[(((((ax0331 * 2048) + (ax1332 * 256)) + (ax2276 * 8)) + ax3276))];
        }
      }
    }
  }
  for (int32_t ax0332 = 0; ax0332 < 25; ++ax0332) {
    for (int32_t ax1333 = 0; ax1333 < 32; ++ax1333) {
      for (int32_t ax2277 = 0; ax2277 < 8; ++ax2277) {
        for (int32_t ax3277 = 0; ax3277 < 8; ++ax3277) {
          ((int8_t*)T_reshape)[(((((ax0332 * 2048) + (ax1333 * 64)) + (ax2277 * 8)) + ax3277))] = ((int8_t*)T_reshape1)[(((((ax0332 * 2048) + (ax2277 * 256)) + (ax1333 * 8)) + ax3277))];
        }
      }
    }
  }
  for (int32_t ax0333 = 0; ax0333 < 25; ++ax0333) {
    for (int32_t ax2278 = 0; ax2278 < 32; ++ax2278) {
      for (int32_t ax3278 = 0; ax3278 < 8; ++ax3278) {
        for (int32_t ax458 = 0; ax458 < 8; ++ax458) {
          ((int8_t*)T_reshape1)[(((((ax0333 * 2048) + (ax2278 * 64)) + (ax3278 * 8)) + ax458))] = ((int8_t*)T_reshape)[(((((ax0333 * 2048) + (ax2278 * 64)) + (ax3278 * 8)) + ax458))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 6400, 0);
  for (int32_t ax0334 = 0; ax0334 < 1024; ++ax0334) {
    for (int32_t ax1334 = 0; ax1334 < 256; ++ax1334) {
      ((int8_t*)compute)[(((ax0334 * 256) + ax1334))] = ((int8_t*)kernel_481)[(((ax0334 * 256) + ax1334))];
    }
  }
  for (int32_t ax0335 = 0; ax0335 < 128; ++ax0335) {
    for (int32_t ax1335 = 0; ax1335 < 8; ++ax1335) {
      for (int32_t ax2279 = 0; ax2279 < 32; ++ax2279) {
        for (int32_t ax3279 = 0; ax3279 < 8; ++ax3279) {
          ((int8_t*)pad_data)[(((((ax0335 * 2048) + (ax1335 * 256)) + (ax2279 * 8)) + ax3279))] = ((int8_t*)compute)[(((((ax0335 * 2048) + (ax1335 * 256)) + (ax2279 * 8)) + ax3279))];
        }
      }
    }
  }
  for (int32_t ax0336 = 0; ax0336 < 128; ++ax0336) {
    for (int32_t ax1336 = 0; ax1336 < 32; ++ax1336) {
      for (int32_t ax2280 = 0; ax2280 < 8; ++ax2280) {
        for (int32_t ax3280 = 0; ax3280 < 8; ++ax3280) {
          ((int8_t*)compute)[(((((ax0336 * 2048) + (ax1336 * 64)) + (ax2280 * 8)) + ax3280))] = ((int8_t*)pad_data)[(((((ax0336 * 2048) + (ax2280 * 256)) + (ax1336 * 8)) + ax3280))];
        }
      }
    }
  }
  for (int32_t ax0337 = 0; ax0337 < 128; ++ax0337) {
    for (int32_t ax2281 = 0; ax2281 < 32; ++ax2281) {
      for (int32_t ax3281 = 0; ax3281 < 8; ++ax3281) {
        for (int32_t ax459 = 0; ax459 < 8; ++ax459) {
          ((int8_t*)out1)[(((((ax0337 * 2048) + (ax2281 * 64)) + (ax3281 * 8)) + ax459))] = ((int8_t*)compute)[(((((ax0337 * 2048) + (ax2281 * 64)) + (ax3281 * 8)) + ax459))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 32768, 0);
  for (int32_t i66 = 0; i66 < 25; ++i66) {
    for (int32_t x35 = 0; x35 < 128; ++x35) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i66 * 128) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x35 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(out, (int64_t)537264128, 32, ((i66 * 32768) + (x35 * 256)));
    }
  }
  for (int32_t ax0338 = 0; ax0338 < 25; ++ax0338) {
    for (int32_t ax1337 = 0; ax1337 < 8; ++ax1337) {
      for (int32_t ax2282 = 0; ax2282 < 128; ++ax2282) {
        for (int32_t ax3282 = 0; ax3282 < 8; ++ax3282) {
          ((int32_t*)pad_data)[(((((ax0338 * 8192) + (ax1337 * 1024)) + (ax2282 * 8)) + ax3282))] = ((int32_t*)out)[(((((ax0338 * 8192) + (ax2282 * 64)) + (ax1337 * 8)) + ax3282))];
        }
      }
    }
  }
  for (int32_t ax0339 = 0; ax0339 < 196; ++ax0339) {
    for (int32_t ax1338 = 0; ax1338 < 1024; ++ax1338) {
      ((int32_t*)compute)[(((ax0339 * 1024) + ax1338))] = ((int32_t*)pad_data)[(((ax0339 * 1024) + ax1338))];
    }
  }
  for (int32_t i060 = 0; i060 < 196; ++i060) {
    for (int32_t i1219 = 0; i1219 < 1024; ++i1219) {
      ((int32_t*)out1)[(((i060 * 1024) + i1219))] = ((int32_t*)compute)[(((i060 * 1024) + i1219))];
    }
  }
  for (int32_t ax1339 = 0; ax1339 < 14; ++ax1339) {
    for (int32_t ax2283 = 0; ax2283 < 14; ++ax2283) {
      for (int32_t ax3283 = 0; ax3283 < 1024; ++ax3283) {
        ((int32_t*)compute)[((((ax1339 * 14336) + (ax2283 * 1024)) + ax3283))] = ((int32_t*)out1)[((((ax1339 * 14336) + (ax2283 * 1024)) + ax3283))];
      }
    }
  }
  for (int32_t h431 = 0; h431 < 14; ++h431) {
    for (int32_t w214 = 0; w214 < 14; ++w214) {
      for (int32_t c247 = 0; c247 < 1024; ++c247) {
        ((int32_t*)out)[((((h431 * 14336) + (w214 * 1024)) + c247))] = 10;
      }
    }
  }
  for (int32_t h432 = 0; h432 < 14; ++h432) {
    (void)load(compute, (int64_t)537264128, 7168, (h432 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h432 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h432 * 57344));
  }
  for (int32_t h433 = 0; h433 < 14; ++h433) {
    for (int32_t w215 = 0; w215 < 14; ++w215) {
      for (int32_t c248 = 0; c248 < 1024; ++c248) {
        ((int32_t*)compute)[((((h433 * 14336) + (w215 * 1024)) + c248))] = ((int32_t*)tensor_483)[(c248)];
      }
    }
  }
  for (int32_t h434 = 0; h434 < 14; ++h434) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h434 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h434 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h434 * 57344));
  }
  for (int32_t h435 = 0; h435 < 14; ++h435) {
    for (int32_t w216 = 0; w216 < 14; ++w216) {
      for (int32_t c249 = 0; c249 < 1024; ++c249) {
        ((int32_t*)compute)[((((h435 * 14336) + (w216 * 1024)) + c249))] = 131072;
      }
    }
  }
  for (int32_t h436 = 0; h436 < 14; ++h436) {
    (void)load(out1, (int64_t)537264128, 7168, (h436 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h436 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h436 * 57344));
  }
  for (int32_t h437 = 0; h437 < 14; ++h437) {
    for (int32_t w217 = 0; w217 < 14; ++w217) {
      for (int32_t c250 = 0; c250 < 1024; ++c250) {
        ((int32_t*)compute)[((((h437 * 14336) + (w217 * 1024)) + c250))] = 18;
      }
    }
  }
  for (int32_t h438 = 0; h438 < 14; ++h438) {
    (void)load(out, (int64_t)537264128, 7168, (h438 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h438 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h438 * 57344));
  }
  for (int32_t i1220 = 0; i1220 < 14; ++i1220) {
    for (int32_t i2159 = 0; i2159 < 14; ++i2159) {
      for (int32_t i3159 = 0; i3159 < 1024; ++i3159) {
        int32_t _120 = ((int32_t*)pad_data)[((((i1220 * 14336) + (i2159 * 1024)) + i3159))];
        int32_t _121 = (_120) < (127) ? (_120) : (127);
        ((int32_t*)compute)[((((i1220 * 14336) + (i2159 * 1024)) + i3159))] = ((_121) > (-127) ? (_121) : (-127));
      }
    }
  }
  for (int32_t i1221 = 0; i1221 < 14; ++i1221) {
    for (int32_t i2160 = 0; i2160 < 14; ++i2160) {
      for (int32_t i3160 = 0; i3160 < 1024; ++i3160) {
        ((int8_t*)out1)[((((i1221 * 14336) + (i2160 * 1024)) + i3160))] = ((int8_t)((int32_t*)compute)[((((i1221 * 14336) + (i2160 * 1024)) + i3160))]);
      }
    }
  }
  for (int32_t i1222 = 0; i1222 < 14; ++i1222) {
    for (int32_t i2161 = 0; i2161 < 14; ++i2161) {
      for (int32_t i3161 = 0; i3161 < 1024; ++i3161) {
        ((int32_t*)compute)[((((i1222 * 14336) + (i2161 * 1024)) + i3161))] = ((int32_t)((int8_t*)out1)[((((i1222 * 14336) + (i2161 * 1024)) + i3161))]);
      }
    }
  }
  for (int32_t h439 = 0; h439 < 14; ++h439) {
    for (int32_t w218 = 0; w218 < 14; ++w218) {
      for (int32_t c251 = 0; c251 < 1024; ++c251) {
        ((int32_t*)out)[((((h439 * 14336) + (w218 * 1024)) + c251))] = ((int32_t*)tensor_490)[(c251)];
      }
    }
  }
  for (int32_t h440 = 0; h440 < 14; ++h440) {
    (void)load(compute, (int64_t)537264128, 7168, (h440 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h440 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h440 * 57344));
  }
  for (int32_t h441 = 0; h441 < 14; ++h441) {
    for (int32_t w219 = 0; w219 < 14; ++w219) {
      for (int32_t c252 = 0; c252 < 1024; ++c252) {
        ((int32_t*)compute)[((((h441 * 14336) + (w219 * 1024)) + c252))] = ((int32_t*)tensor_491)[(c252)];
      }
    }
  }
  for (int32_t h442 = 0; h442 < 14; ++h442) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h442 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h442 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h442 * 57344));
  }
  for (int32_t h443 = 0; h443 < 14; ++h443) {
    for (int32_t w220 = 0; w220 < 14; ++w220) {
      for (int32_t c253 = 0; c253 < 1024; ++c253) {
        ((int32_t*)compute)[((((h443 * 14336) + (w220 * 1024)) + c253))] = 8;
      }
    }
  }
  for (int32_t h444 = 0; h444 < 14; ++h444) {
    (void)load(out1, (int64_t)537264128, 7168, (h444 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h444 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h444 * 57344));
  }
  for (int32_t h445 = 0; h445 < 14; ++h445) {
    for (int32_t w221 = 0; w221 < 14; ++w221) {
      for (int32_t c254 = 0; c254 < 1024; ++c254) {
        ((int32_t*)compute)[((((h445 * 14336) + (w221 * 1024)) + c254))] = 4;
      }
    }
  }
  for (int32_t h446 = 0; h446 < 14; ++h446) {
    (void)load(out, (int64_t)537264128, 7168, (h446 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h446 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h446 * 57344));
  }
  for (int32_t i1223 = 0; i1223 < 14; ++i1223) {
    for (int32_t i2162 = 0; i2162 < 14; ++i2162) {
      for (int32_t i3162 = 0; i3162 < 1024; ++i3162) {
        int32_t _122 = ((int32_t*)pad_data)[((((i1223 * 14336) + (i2162 * 1024)) + i3162))];
        int32_t _123 = (_122) < (127) ? (_122) : (127);
        ((int32_t*)compute)[((((i1223 * 14336) + (i2162 * 1024)) + i3162))] = ((_123) > (-127) ? (_123) : (-127));
      }
    }
  }
  for (int32_t i1224 = 0; i1224 < 14; ++i1224) {
    for (int32_t i2163 = 0; i2163 < 14; ++i2163) {
      for (int32_t i3163 = 0; i3163 < 1024; ++i3163) {
        ((int8_t*)out1)[((((i1224 * 14336) + (i2163 * 1024)) + i3163))] = ((int8_t)((int32_t*)compute)[((((i1224 * 14336) + (i2163 * 1024)) + i3163))]);
      }
    }
  }
  for (int32_t i1225 = 0; i1225 < 14; ++i1225) {
    for (int32_t i2164 = 0; i2164 < 14; ++i2164) {
      for (int32_t i3164 = 0; i3164 < 1024; ++i3164) {
        ((int32_t*)compute)[((((i1225 * 14336) + (i2164 * 1024)) + i3164))] = ((int32_t)((int8_t*)out1)[((((i1225 * 14336) + (i2164 * 1024)) + i3164))]);
      }
    }
  }
  for (int32_t i1226 = 0; i1226 < 14; ++i1226) {
    for (int32_t i2165 = 0; i2165 < 14; ++i2165) {
      for (int32_t i3165 = 0; i3165 < 1024; ++i3165) {
        ((int32_t*)out)[((((i1226 * 14336) + (i2165 * 1024)) + i3165))] = ((int32_t)((int8_t*)compute1)[((((i1226 * 14336) + (i2165 * 1024)) + i3165))]);
      }
    }
  }
  for (int32_t h447 = 0; h447 < 14; ++h447) {
    (void)load(compute, (int64_t)537264128, 7168, (h447 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h447 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h447 * 57344));
  }
  for (int32_t h448 = 0; h448 < 14; ++h448) {
    for (int32_t w222 = 0; w222 < 14; ++w222) {
      for (int32_t c255 = 0; c255 < 1024; ++c255) {
        ((int32_t*)compute)[((((h448 * 14336) + (w222 * 1024)) + c255))] = 0;
      }
    }
  }
  for (int32_t h449 = 0; h449 < 14; ++h449) {
    (void)load(compute1, (int64_t)537264128, 7168, (h449 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h449 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h449 * 57344));
  }
  for (int32_t i1227 = 0; i1227 < 14; ++i1227) {
    for (int32_t i2166 = 0; i2166 < 14; ++i2166) {
      for (int32_t i3166 = 0; i3166 < 1024; ++i3166) {
        int32_t _124 = ((int32_t*)pad_data)[((((i1227 * 14336) + (i2166 * 1024)) + i3166))];
        int32_t _125 = (_124) < (127) ? (_124) : (127);
        ((int32_t*)compute)[((((i1227 * 14336) + (i2166 * 1024)) + i3166))] = ((_125) > (-127) ? (_125) : (-127));
      }
    }
  }
  for (int32_t i1228 = 0; i1228 < 14; ++i1228) {
    for (int32_t i2167 = 0; i2167 < 14; ++i2167) {
      for (int32_t i3167 = 0; i3167 < 1024; ++i3167) {
        ((int8_t*)compute1)[((((i1228 * 14336) + (i2167 * 1024)) + i3167))] = ((int8_t)((int32_t*)compute)[((((i1228 * 14336) + (i2167 * 1024)) + i3167))]);
      }
    }
  }
  for (int32_t o132 = 0; o132 < 14; ++o132) {
    for (int32_t o232 = 0; o232 < 14; ++o232) {
      for (int32_t c256 = 0; c256 < 1024; ++c256) {
        ((int8_t*)compute)[((((o132 * 14336) + (o232 * 1024)) + c256))] = ((int8_t*)compute1)[((((o132 * 14336) + (o232 * 1024)) + c256))];
      }
    }
  }
  for (int32_t ax0340 = 0; ax0340 < 196; ++ax0340) {
    for (int32_t ax1340 = 0; ax1340 < 1024; ++ax1340) {
      ((int8_t*)out1)[(((ax0340 * 1024) + ax1340))] = ((int8_t*)compute)[(((ax0340 * 1024) + ax1340))];
    }
  }
  for (int32_t i061 = 0; i061 < 200; ++i061) {
    for (int32_t i1229 = 0; i1229 < 1024; ++i1229) {
      ((int8_t*)compute)[(((i061 * 1024) + i1229))] = ((i061 < 196) ? ((int8_t*)out1)[(((i061 * 1024) + i1229))] : (int8_t)0);
    }
  }
  for (int32_t ax0341 = 0; ax0341 < 25; ++ax0341) {
    for (int32_t ax1341 = 0; ax1341 < 8; ++ax1341) {
      for (int32_t ax2284 = 0; ax2284 < 128; ++ax2284) {
        for (int32_t ax3284 = 0; ax3284 < 8; ++ax3284) {
          ((int8_t*)out)[(((((ax0341 * 8192) + (ax1341 * 1024)) + (ax2284 * 8)) + ax3284))] = ((int8_t*)compute)[(((((ax0341 * 8192) + (ax1341 * 1024)) + (ax2284 * 8)) + ax3284))];
        }
      }
    }
  }
  for (int32_t ax0342 = 0; ax0342 < 25; ++ax0342) {
    for (int32_t ax1342 = 0; ax1342 < 128; ++ax1342) {
      for (int32_t ax2285 = 0; ax2285 < 8; ++ax2285) {
        for (int32_t ax3285 = 0; ax3285 < 8; ++ax3285) {
          ((int8_t*)compute)[(((((ax0342 * 8192) + (ax1342 * 64)) + (ax2285 * 8)) + ax3285))] = ((int8_t*)out)[(((((ax0342 * 8192) + (ax2285 * 1024)) + (ax1342 * 8)) + ax3285))];
        }
      }
    }
  }
  for (int32_t ax0343 = 0; ax0343 < 25; ++ax0343) {
    for (int32_t ax2286 = 0; ax2286 < 128; ++ax2286) {
      for (int32_t ax3286 = 0; ax3286 < 8; ++ax3286) {
        for (int32_t ax460 = 0; ax460 < 8; ++ax460) {
          ((int8_t*)pad_data)[(((((ax0343 * 8192) + (ax2286 * 64)) + (ax3286 * 8)) + ax460))] = ((int8_t*)compute)[(((((ax0343 * 8192) + (ax2286 * 64)) + (ax3286 * 8)) + ax460))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25600, 0);
  for (int32_t ax0344 = 0; ax0344 < 256; ++ax0344) {
    for (int32_t ax1343 = 0; ax1343 < 1024; ++ax1343) {
      ((int8_t*)compute)[(((ax0344 * 1024) + ax1343))] = ((int8_t*)kernel_506)[(((ax0344 * 1024) + ax1343))];
    }
  }
  for (int32_t ax0345 = 0; ax0345 < 32; ++ax0345) {
    for (int32_t ax1344 = 0; ax1344 < 8; ++ax1344) {
      for (int32_t ax2287 = 0; ax2287 < 128; ++ax2287) {
        for (int32_t ax3287 = 0; ax3287 < 8; ++ax3287) {
          ((int8_t*)out1)[(((((ax0345 * 8192) + (ax1344 * 1024)) + (ax2287 * 8)) + ax3287))] = ((int8_t*)compute)[(((((ax0345 * 8192) + (ax1344 * 1024)) + (ax2287 * 8)) + ax3287))];
        }
      }
    }
  }
  for (int32_t ax0346 = 0; ax0346 < 32; ++ax0346) {
    for (int32_t ax1345 = 0; ax1345 < 128; ++ax1345) {
      for (int32_t ax2288 = 0; ax2288 < 8; ++ax2288) {
        for (int32_t ax3288 = 0; ax3288 < 8; ++ax3288) {
          ((int8_t*)compute)[(((((ax0346 * 8192) + (ax1345 * 64)) + (ax2288 * 8)) + ax3288))] = ((int8_t*)out1)[(((((ax0346 * 8192) + (ax2288 * 1024)) + (ax1345 * 8)) + ax3288))];
        }
      }
    }
  }
  for (int32_t ax0347 = 0; ax0347 < 32; ++ax0347) {
    for (int32_t ax2289 = 0; ax2289 < 128; ++ax2289) {
      for (int32_t ax3289 = 0; ax3289 < 8; ++ax3289) {
        for (int32_t ax461 = 0; ax461 < 8; ++ax461) {
          ((int8_t*)out)[(((((ax0347 * 8192) + (ax2289 * 64)) + (ax3289 * 8)) + ax461))] = ((int8_t*)compute)[(((((ax0347 * 8192) + (ax2289 * 64)) + (ax3289 * 8)) + ax461))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 32768, 0);
  for (int32_t i67 = 0; i67 < 25; ++i67) {
    for (int32_t x36 = 0; x36 < 32; ++x36) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i67 * 512)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x36 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i67 * 8192) + (x36 * 256)));
    }
  }
  for (int32_t ax0348 = 0; ax0348 < 25; ++ax0348) {
    for (int32_t ax1346 = 0; ax1346 < 8; ++ax1346) {
      for (int32_t ax2290 = 0; ax2290 < 32; ++ax2290) {
        for (int32_t ax3290 = 0; ax3290 < 8; ++ax3290) {
          ((int32_t*)pad_data)[(((((ax0348 * 2048) + (ax1346 * 256)) + (ax2290 * 8)) + ax3290))] = ((int32_t*)compute)[(((((ax0348 * 2048) + (ax2290 * 64)) + (ax1346 * 8)) + ax3290))];
        }
      }
    }
  }
  for (int32_t ax0349 = 0; ax0349 < 196; ++ax0349) {
    for (int32_t ax1347 = 0; ax1347 < 256; ++ax1347) {
      ((int32_t*)compute)[(((ax0349 * 256) + ax1347))] = ((int32_t*)pad_data)[(((ax0349 * 256) + ax1347))];
    }
  }
  for (int32_t i062 = 0; i062 < 196; ++i062) {
    for (int32_t i1230 = 0; i1230 < 256; ++i1230) {
      ((int32_t*)out1)[(((i062 * 256) + i1230))] = ((int32_t*)compute)[(((i062 * 256) + i1230))];
    }
  }
  for (int32_t ax1348 = 0; ax1348 < 14; ++ax1348) {
    for (int32_t ax2291 = 0; ax2291 < 14; ++ax2291) {
      for (int32_t ax3291 = 0; ax3291 < 256; ++ax3291) {
        ((int32_t*)compute)[((((ax1348 * 3584) + (ax2291 * 256)) + ax3291))] = ((int32_t*)out1)[((((ax1348 * 3584) + (ax2291 * 256)) + ax3291))];
      }
    }
  }
  for (int32_t h450 = 0; h450 < 14; ++h450) {
    for (int32_t w223 = 0; w223 < 14; ++w223) {
      for (int32_t c257 = 0; c257 < 256; ++c257) {
        ((int32_t*)out)[((((h450 * 3584) + (w223 * 256)) + c257))] = 12;
      }
    }
  }
  for (int32_t h451 = 0; h451 < 14; ++h451) {
    (void)load(compute, (int64_t)537264128, 1792, (h451 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h451 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h451 * 14336));
  }
  for (int32_t h452 = 0; h452 < 14; ++h452) {
    for (int32_t w224 = 0; w224 < 14; ++w224) {
      for (int32_t c258 = 0; c258 < 256; ++c258) {
        ((int32_t*)compute)[((((h452 * 3584) + (w224 * 256)) + c258))] = ((int32_t*)tensor_508)[(c258)];
      }
    }
  }
  for (int32_t h453 = 0; h453 < 14; ++h453) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h453 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h453 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h453 * 14336));
  }
  for (int32_t h454 = 0; h454 < 14; ++h454) {
    for (int32_t w225 = 0; w225 < 14; ++w225) {
      for (int32_t c259 = 0; c259 < 256; ++c259) {
        ((int32_t*)compute)[((((h454 * 3584) + (w225 * 256)) + c259))] = ((int32_t*)tensor_509)[(c259)];
      }
    }
  }
  for (int32_t h455 = 0; h455 < 14; ++h455) {
    (void)load(out1, (int64_t)537264128, 1792, (h455 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h455 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h455 * 14336));
  }
  for (int32_t h456 = 0; h456 < 14; ++h456) {
    for (int32_t w226 = 0; w226 < 14; ++w226) {
      for (int32_t c260 = 0; c260 < 256; ++c260) {
        ((int32_t*)compute)[((((h456 * 3584) + (w226 * 256)) + c260))] = 0;
      }
    }
  }
  for (int32_t h457 = 0; h457 < 14; ++h457) {
    (void)load(out, (int64_t)537264128, 1792, (h457 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h457 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h457 * 14336));
  }
  for (int32_t h458 = 0; h458 < 14; ++h458) {
    for (int32_t w227 = 0; w227 < 14; ++w227) {
      for (int32_t c261 = 0; c261 < 256; ++c261) {
        ((int32_t*)compute)[((((h458 * 3584) + (w227 * 256)) + c261))] = 524288;
      }
    }
  }
  for (int32_t h459 = 0; h459 < 14; ++h459) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h459 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h459 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h459 * 14336));
  }
  for (int32_t h460 = 0; h460 < 14; ++h460) {
    for (int32_t w228 = 0; w228 < 14; ++w228) {
      for (int32_t c262 = 0; c262 < 256; ++c262) {
        ((int32_t*)compute)[((((h460 * 3584) + (w228 * 256)) + c262))] = 20;
      }
    }
  }
  for (int32_t h461 = 0; h461 < 14; ++h461) {
    (void)load(out1, (int64_t)537264128, 1792, (h461 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h461 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h461 * 14336));
  }
  for (int32_t i1231 = 0; i1231 < 14; ++i1231) {
    for (int32_t i2168 = 0; i2168 < 14; ++i2168) {
      for (int32_t i3168 = 0; i3168 < 256; ++i3168) {
        int32_t _126 = ((int32_t*)out)[((((i1231 * 3584) + (i2168 * 256)) + i3168))];
        int32_t _127 = (_126) < (127) ? (_126) : (127);
        ((int32_t*)compute)[((((i1231 * 3584) + (i2168 * 256)) + i3168))] = ((_127) > (-127) ? (_127) : (-127));
      }
    }
  }
  for (int32_t i1232 = 0; i1232 < 14; ++i1232) {
    for (int32_t i2169 = 0; i2169 < 14; ++i2169) {
      for (int32_t i3169 = 0; i3169 < 256; ++i3169) {
        ((int8_t*)T_reshape1)[((((i1232 * 3584) + (i2169 * 256)) + i3169))] = ((int8_t)((int32_t*)compute)[((((i1232 * 3584) + (i2169 * 256)) + i3169))]);
      }
    }
  }
  for (int32_t i1233 = 0; i1233 < 16; ++i1233) {
    for (int32_t i2170 = 0; i2170 < 16; ++i2170) {
      for (int32_t i3170 = 0; i3170 < 256; ++i3170) {
        ((int8_t*)T_reshape)[((((i1233 * 4096) + (i2170 * 256)) + i3170))] = (((((1 <= i1233) && (i1233 < 15)) && (1 <= i2170)) && (i2170 < 15)) ? ((int8_t*)T_reshape1)[(((((i1233 * 3584) + (i2170 * 256)) + i3170) - 3840))] : (int8_t)0);
      }
    }
  }
  for (int32_t o133 = 0; o133 < 14; ++o133) {
    for (int32_t o233 = 0; o233 < 14; ++o233) {
      for (int32_t k111 = 0; k111 < 3; ++k111) {
        for (int32_t k211 = 0; k211 < 3; ++k211) {
          for (int32_t c263 = 0; c263 < 256; ++c263) {
            ((int8_t*)compute)[((((((o133 * 32256) + (o233 * 2304)) + (k111 * 768)) + (k211 * 256)) + c263))] = ((int8_t*)T_reshape)[((((((k111 * 4096) + (o133 * 4096)) + (k211 * 256)) + (o233 * 256)) + c263))];
          }
        }
      }
    }
  }
  for (int32_t ax0350 = 0; ax0350 < 196; ++ax0350) {
    for (int32_t ax1349 = 0; ax1349 < 2304; ++ax1349) {
      ((int8_t*)pad_data)[(((ax0350 * 2304) + ax1349))] = ((int8_t*)compute)[(((ax0350 * 2304) + ax1349))];
    }
  }
  for (int32_t i063 = 0; i063 < 200; ++i063) {
    for (int32_t i1234 = 0; i1234 < 2304; ++i1234) {
      ((int8_t*)compute)[(((i063 * 2304) + i1234))] = ((i063 < 196) ? ((int8_t*)pad_data)[(((i063 * 2304) + i1234))] : (int8_t)0);
    }
  }
  for (int32_t ax0351 = 0; ax0351 < 25; ++ax0351) {
    for (int32_t ax1350 = 0; ax1350 < 8; ++ax1350) {
      for (int32_t ax2292 = 0; ax2292 < 288; ++ax2292) {
        for (int32_t ax3292 = 0; ax3292 < 8; ++ax3292) {
          ((int8_t*)out1)[(((((ax0351 * 18432) + (ax1350 * 2304)) + (ax2292 * 8)) + ax3292))] = ((int8_t*)compute)[(((((ax0351 * 18432) + (ax1350 * 2304)) + (ax2292 * 8)) + ax3292))];
        }
      }
    }
  }
  for (int32_t ax0352 = 0; ax0352 < 25; ++ax0352) {
    for (int32_t ax1351 = 0; ax1351 < 288; ++ax1351) {
      for (int32_t ax2293 = 0; ax2293 < 8; ++ax2293) {
        for (int32_t ax3293 = 0; ax3293 < 8; ++ax3293) {
          ((int8_t*)compute)[(((((ax0352 * 18432) + (ax1351 * 64)) + (ax2293 * 8)) + ax3293))] = ((int8_t*)out1)[(((((ax0352 * 18432) + (ax2293 * 2304)) + (ax1351 * 8)) + ax3293))];
        }
      }
    }
  }
  for (int32_t ax0353 = 0; ax0353 < 25; ++ax0353) {
    for (int32_t ax1352 = 0; ax1352 < 4; ++ax1352) {
      for (int32_t ax2294 = 0; ax2294 < 72; ++ax2294) {
        for (int32_t ax3294 = 0; ax3294 < 8; ++ax3294) {
          for (int32_t ax462 = 0; ax462 < 8; ++ax462) {
            ((int8_t*)out)[((((((ax0353 * 18432) + (ax1352 * 4608)) + (ax2294 * 64)) + (ax3294 * 8)) + ax462))] = ((int8_t*)compute)[((((((ax0353 * 18432) + (ax1352 * 4608)) + (ax2294 * 64)) + (ax3294 * 8)) + ax462))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536870912, 57600, 0);
  for (int32_t ax0354 = 0; ax0354 < 256; ++ax0354) {
    for (int32_t ax1353 = 0; ax1353 < 2304; ++ax1353) {
      ((int8_t*)compute)[(((ax0354 * 2304) + ax1353))] = ((int8_t*)kernel_516)[(((ax0354 * 2304) + ax1353))];
    }
  }
  for (int32_t ax0355 = 0; ax0355 < 32; ++ax0355) {
    for (int32_t ax1354 = 0; ax1354 < 8; ++ax1354) {
      for (int32_t ax2295 = 0; ax2295 < 288; ++ax2295) {
        for (int32_t ax3295 = 0; ax3295 < 8; ++ax3295) {
          ((int8_t*)pad_data)[(((((ax0355 * 18432) + (ax1354 * 2304)) + (ax2295 * 8)) + ax3295))] = ((int8_t*)compute)[(((((ax0355 * 18432) + (ax1354 * 2304)) + (ax2295 * 8)) + ax3295))];
        }
      }
    }
  }
  for (int32_t ax0356 = 0; ax0356 < 32; ++ax0356) {
    for (int32_t ax1355 = 0; ax1355 < 288; ++ax1355) {
      for (int32_t ax2296 = 0; ax2296 < 8; ++ax2296) {
        for (int32_t ax3296 = 0; ax3296 < 8; ++ax3296) {
          ((int8_t*)compute)[(((((ax0356 * 18432) + (ax1355 * 64)) + (ax2296 * 8)) + ax3296))] = ((int8_t*)pad_data)[(((((ax0356 * 18432) + (ax2296 * 2304)) + (ax1355 * 8)) + ax3296))];
        }
      }
    }
  }
  for (int32_t ax0357 = 0; ax0357 < 32; ++ax0357) {
    for (int32_t ax1356 = 0; ax1356 < 4; ++ax1356) {
      for (int32_t ax2297 = 0; ax2297 < 72; ++ax2297) {
        for (int32_t ax3297 = 0; ax3297 < 8; ++ax3297) {
          for (int32_t ax463 = 0; ax463 < 8; ++ax463) {
            ((int8_t*)out1)[((((((ax0357 * 18432) + (ax1356 * 4608)) + (ax2297 * 64)) + (ax3297 * 8)) + ax463))] = ((int8_t*)compute)[((((((ax0357 * 18432) + (ax1356 * 4608)) + (ax2297 * 64)) + (ax3297 * 8)) + ax463))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 73728, 0);
  for (int32_t i68 = 0; i68 < 25; ++i68) {
    for (int32_t x37 = 0; x37 < 32; ++x37) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k08 = 0; k08 < 4; ++k08) {
        (void)move(((((int64_t)((i68 * 1152) + (k08 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x37 * 1152) + (k08 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute, (int64_t)537264128, 32, ((i68 * 8192) + (x37 * 256)));
    }
  }
  for (int32_t ax0358 = 0; ax0358 < 25; ++ax0358) {
    for (int32_t ax1357 = 0; ax1357 < 8; ++ax1357) {
      for (int32_t ax2298 = 0; ax2298 < 32; ++ax2298) {
        for (int32_t ax3298 = 0; ax3298 < 8; ++ax3298) {
          ((int32_t*)out)[(((((ax0358 * 2048) + (ax1357 * 256)) + (ax2298 * 8)) + ax3298))] = ((int32_t*)compute)[(((((ax0358 * 2048) + (ax2298 * 64)) + (ax1357 * 8)) + ax3298))];
        }
      }
    }
  }
  for (int32_t ax0359 = 0; ax0359 < 196; ++ax0359) {
    for (int32_t ax1358 = 0; ax1358 < 256; ++ax1358) {
      ((int32_t*)compute)[(((ax0359 * 256) + ax1358))] = ((int32_t*)out)[(((ax0359 * 256) + ax1358))];
    }
  }
  for (int32_t i064 = 0; i064 < 196; ++i064) {
    for (int32_t i1235 = 0; i1235 < 256; ++i1235) {
      ((int32_t*)pad_data)[(((i064 * 256) + i1235))] = ((int32_t*)compute)[(((i064 * 256) + i1235))];
    }
  }
  for (int32_t ax1359 = 0; ax1359 < 14; ++ax1359) {
    for (int32_t ax2299 = 0; ax2299 < 14; ++ax2299) {
      for (int32_t ax3299 = 0; ax3299 < 256; ++ax3299) {
        ((int32_t*)compute)[((((ax1359 * 3584) + (ax2299 * 256)) + ax3299))] = ((int32_t*)pad_data)[((((ax1359 * 3584) + (ax2299 * 256)) + ax3299))];
      }
    }
  }
  for (int32_t h462 = 0; h462 < 14; ++h462) {
    for (int32_t w229 = 0; w229 < 14; ++w229) {
      for (int32_t c264 = 0; c264 < 256; ++c264) {
        ((int32_t*)out1)[((((h462 * 3584) + (w229 * 256)) + c264))] = ((int32_t*)tensor_517)[(c264)];
      }
    }
  }
  for (int32_t h463 = 0; h463 < 14; ++h463) {
    (void)load(compute, (int64_t)537264128, 1792, (h463 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h463 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h463 * 14336));
  }
  for (int32_t h464 = 0; h464 < 14; ++h464) {
    for (int32_t w230 = 0; w230 < 14; ++w230) {
      for (int32_t c265 = 0; c265 < 256; ++c265) {
        ((int32_t*)compute)[((((h464 * 3584) + (w230 * 256)) + c265))] = 0;
      }
    }
  }
  for (int32_t h465 = 0; h465 < 14; ++h465) {
    (void)load(out, (int64_t)537264128, 1792, (h465 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h465 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h465 * 14336));
  }
  for (int32_t h466 = 0; h466 < 14; ++h466) {
    for (int32_t w231 = 0; w231 < 14; ++w231) {
      for (int32_t c266 = 0; c266 < 256; ++c266) {
        ((int32_t*)compute)[((((h466 * 3584) + (w231 * 256)) + c266))] = 16;
      }
    }
  }
  for (int32_t h467 = 0; h467 < 14; ++h467) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h467 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h467 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h467 * 14336));
  }
  for (int32_t h468 = 0; h468 < 14; ++h468) {
    for (int32_t w232 = 0; w232 < 14; ++w232) {
      for (int32_t c267 = 0; c267 < 256; ++c267) {
        ((int32_t*)compute)[((((h468 * 3584) + (w232 * 256)) + c267))] = 5;
      }
    }
  }
  for (int32_t h469 = 0; h469 < 14; ++h469) {
    (void)load(out1, (int64_t)537264128, 1792, (h469 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h469 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h469 * 14336));
  }
  for (int32_t i1236 = 0; i1236 < 14; ++i1236) {
    for (int32_t i2171 = 0; i2171 < 14; ++i2171) {
      for (int32_t i3171 = 0; i3171 < 256; ++i3171) {
        int32_t _128 = ((int32_t*)out)[((((i1236 * 3584) + (i2171 * 256)) + i3171))];
        int32_t _129 = (_128) < (127) ? (_128) : (127);
        ((int32_t*)compute)[((((i1236 * 3584) + (i2171 * 256)) + i3171))] = ((_129) > (-127) ? (_129) : (-127));
      }
    }
  }
  for (int32_t i1237 = 0; i1237 < 14; ++i1237) {
    for (int32_t i2172 = 0; i2172 < 14; ++i2172) {
      for (int32_t i3172 = 0; i3172 < 256; ++i3172) {
        ((int8_t*)T_reshape1)[((((i1237 * 3584) + (i2172 * 256)) + i3172))] = ((int8_t)((int32_t*)compute)[((((i1237 * 3584) + (i2172 * 256)) + i3172))]);
      }
    }
  }
  for (int32_t o134 = 0; o134 < 14; ++o134) {
    for (int32_t o234 = 0; o234 < 14; ++o234) {
      for (int32_t c268 = 0; c268 < 256; ++c268) {
        ((int8_t*)T_reshape)[((((o134 * 3584) + (o234 * 256)) + c268))] = ((int8_t*)T_reshape1)[((((o134 * 3584) + (o234 * 256)) + c268))];
      }
    }
  }
  for (int32_t ax0360 = 0; ax0360 < 196; ++ax0360) {
    for (int32_t ax1360 = 0; ax1360 < 256; ++ax1360) {
      ((int8_t*)T_reshape1)[(((ax0360 * 256) + ax1360))] = ((int8_t*)T_reshape)[(((ax0360 * 256) + ax1360))];
    }
  }
  for (int32_t i065 = 0; i065 < 200; ++i065) {
    for (int32_t i1238 = 0; i1238 < 256; ++i1238) {
      ((int8_t*)T_reshape)[(((i065 * 256) + i1238))] = ((i065 < 196) ? ((int8_t*)T_reshape1)[(((i065 * 256) + i1238))] : (int8_t)0);
    }
  }
  for (int32_t ax0361 = 0; ax0361 < 25; ++ax0361) {
    for (int32_t ax1361 = 0; ax1361 < 8; ++ax1361) {
      for (int32_t ax2300 = 0; ax2300 < 32; ++ax2300) {
        for (int32_t ax3300 = 0; ax3300 < 8; ++ax3300) {
          ((int8_t*)T_reshape1)[(((((ax0361 * 2048) + (ax1361 * 256)) + (ax2300 * 8)) + ax3300))] = ((int8_t*)T_reshape)[(((((ax0361 * 2048) + (ax1361 * 256)) + (ax2300 * 8)) + ax3300))];
        }
      }
    }
  }
  for (int32_t ax0362 = 0; ax0362 < 25; ++ax0362) {
    for (int32_t ax1362 = 0; ax1362 < 32; ++ax1362) {
      for (int32_t ax2301 = 0; ax2301 < 8; ++ax2301) {
        for (int32_t ax3301 = 0; ax3301 < 8; ++ax3301) {
          ((int8_t*)T_reshape)[(((((ax0362 * 2048) + (ax1362 * 64)) + (ax2301 * 8)) + ax3301))] = ((int8_t*)T_reshape1)[(((((ax0362 * 2048) + (ax2301 * 256)) + (ax1362 * 8)) + ax3301))];
        }
      }
    }
  }
  for (int32_t ax0363 = 0; ax0363 < 25; ++ax0363) {
    for (int32_t ax2302 = 0; ax2302 < 32; ++ax2302) {
      for (int32_t ax3302 = 0; ax3302 < 8; ++ax3302) {
        for (int32_t ax464 = 0; ax464 < 8; ++ax464) {
          ((int8_t*)T_reshape1)[(((((ax0363 * 2048) + (ax2302 * 64)) + (ax3302 * 8)) + ax464))] = ((int8_t*)T_reshape)[(((((ax0363 * 2048) + (ax2302 * 64)) + (ax3302 * 8)) + ax464))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 6400, 0);
  for (int32_t ax0364 = 0; ax0364 < 1024; ++ax0364) {
    for (int32_t ax1363 = 0; ax1363 < 256; ++ax1363) {
      ((int8_t*)compute)[(((ax0364 * 256) + ax1363))] = ((int8_t*)kernel_524)[(((ax0364 * 256) + ax1363))];
    }
  }
  for (int32_t ax0365 = 0; ax0365 < 128; ++ax0365) {
    for (int32_t ax1364 = 0; ax1364 < 8; ++ax1364) {
      for (int32_t ax2303 = 0; ax2303 < 32; ++ax2303) {
        for (int32_t ax3303 = 0; ax3303 < 8; ++ax3303) {
          ((int8_t*)pad_data)[(((((ax0365 * 2048) + (ax1364 * 256)) + (ax2303 * 8)) + ax3303))] = ((int8_t*)compute)[(((((ax0365 * 2048) + (ax1364 * 256)) + (ax2303 * 8)) + ax3303))];
        }
      }
    }
  }
  for (int32_t ax0366 = 0; ax0366 < 128; ++ax0366) {
    for (int32_t ax1365 = 0; ax1365 < 32; ++ax1365) {
      for (int32_t ax2304 = 0; ax2304 < 8; ++ax2304) {
        for (int32_t ax3304 = 0; ax3304 < 8; ++ax3304) {
          ((int8_t*)compute)[(((((ax0366 * 2048) + (ax1365 * 64)) + (ax2304 * 8)) + ax3304))] = ((int8_t*)pad_data)[(((((ax0366 * 2048) + (ax2304 * 256)) + (ax1365 * 8)) + ax3304))];
        }
      }
    }
  }
  for (int32_t ax0367 = 0; ax0367 < 128; ++ax0367) {
    for (int32_t ax2305 = 0; ax2305 < 32; ++ax2305) {
      for (int32_t ax3305 = 0; ax3305 < 8; ++ax3305) {
        for (int32_t ax465 = 0; ax465 < 8; ++ax465) {
          ((int8_t*)out1)[(((((ax0367 * 2048) + (ax2305 * 64)) + (ax3305 * 8)) + ax465))] = ((int8_t*)compute)[(((((ax0367 * 2048) + (ax2305 * 64)) + (ax3305 * 8)) + ax465))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 32768, 0);
  for (int32_t i69 = 0; i69 < 25; ++i69) {
    for (int32_t x38 = 0; x38 < 128; ++x38) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i69 * 128) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x38 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(out, (int64_t)537264128, 32, ((i69 * 32768) + (x38 * 256)));
    }
  }
  for (int32_t ax0368 = 0; ax0368 < 25; ++ax0368) {
    for (int32_t ax1366 = 0; ax1366 < 8; ++ax1366) {
      for (int32_t ax2306 = 0; ax2306 < 128; ++ax2306) {
        for (int32_t ax3306 = 0; ax3306 < 8; ++ax3306) {
          ((int32_t*)pad_data)[(((((ax0368 * 8192) + (ax1366 * 1024)) + (ax2306 * 8)) + ax3306))] = ((int32_t*)out)[(((((ax0368 * 8192) + (ax2306 * 64)) + (ax1366 * 8)) + ax3306))];
        }
      }
    }
  }
  for (int32_t ax0369 = 0; ax0369 < 196; ++ax0369) {
    for (int32_t ax1367 = 0; ax1367 < 1024; ++ax1367) {
      ((int32_t*)compute)[(((ax0369 * 1024) + ax1367))] = ((int32_t*)pad_data)[(((ax0369 * 1024) + ax1367))];
    }
  }
  for (int32_t i066 = 0; i066 < 196; ++i066) {
    for (int32_t i1239 = 0; i1239 < 1024; ++i1239) {
      ((int32_t*)out1)[(((i066 * 1024) + i1239))] = ((int32_t*)compute)[(((i066 * 1024) + i1239))];
    }
  }
  for (int32_t ax1368 = 0; ax1368 < 14; ++ax1368) {
    for (int32_t ax2307 = 0; ax2307 < 14; ++ax2307) {
      for (int32_t ax3307 = 0; ax3307 < 1024; ++ax3307) {
        ((int32_t*)compute)[((((ax1368 * 14336) + (ax2307 * 1024)) + ax3307))] = ((int32_t*)out1)[((((ax1368 * 14336) + (ax2307 * 1024)) + ax3307))];
      }
    }
  }
  for (int32_t h470 = 0; h470 < 14; ++h470) {
    for (int32_t w233 = 0; w233 < 14; ++w233) {
      for (int32_t c269 = 0; c269 < 1024; ++c269) {
        ((int32_t*)out)[((((h470 * 14336) + (w233 * 1024)) + c269))] = 11;
      }
    }
  }
  for (int32_t h471 = 0; h471 < 14; ++h471) {
    (void)load(compute, (int64_t)537264128, 7168, (h471 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h471 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h471 * 57344));
  }
  for (int32_t h472 = 0; h472 < 14; ++h472) {
    for (int32_t w234 = 0; w234 < 14; ++w234) {
      for (int32_t c270 = 0; c270 < 1024; ++c270) {
        ((int32_t*)compute)[((((h472 * 14336) + (w234 * 1024)) + c270))] = ((int32_t*)tensor_526)[(c270)];
      }
    }
  }
  for (int32_t h473 = 0; h473 < 14; ++h473) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h473 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h473 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h473 * 57344));
  }
  for (int32_t h474 = 0; h474 < 14; ++h474) {
    for (int32_t w235 = 0; w235 < 14; ++w235) {
      for (int32_t c271 = 0; c271 < 1024; ++c271) {
        ((int32_t*)compute)[((((h474 * 14336) + (w235 * 1024)) + c271))] = 262144;
      }
    }
  }
  for (int32_t h475 = 0; h475 < 14; ++h475) {
    (void)load(out1, (int64_t)537264128, 7168, (h475 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h475 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h475 * 57344));
  }
  for (int32_t h476 = 0; h476 < 14; ++h476) {
    for (int32_t w236 = 0; w236 < 14; ++w236) {
      for (int32_t c272 = 0; c272 < 1024; ++c272) {
        ((int32_t*)compute)[((((h476 * 14336) + (w236 * 1024)) + c272))] = 19;
      }
    }
  }
  for (int32_t h477 = 0; h477 < 14; ++h477) {
    (void)load(out, (int64_t)537264128, 7168, (h477 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h477 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h477 * 57344));
  }
  for (int32_t i1240 = 0; i1240 < 14; ++i1240) {
    for (int32_t i2173 = 0; i2173 < 14; ++i2173) {
      for (int32_t i3173 = 0; i3173 < 1024; ++i3173) {
        int32_t _130 = ((int32_t*)pad_data)[((((i1240 * 14336) + (i2173 * 1024)) + i3173))];
        int32_t _131 = (_130) < (127) ? (_130) : (127);
        ((int32_t*)compute)[((((i1240 * 14336) + (i2173 * 1024)) + i3173))] = ((_131) > (-127) ? (_131) : (-127));
      }
    }
  }
  for (int32_t i1241 = 0; i1241 < 14; ++i1241) {
    for (int32_t i2174 = 0; i2174 < 14; ++i2174) {
      for (int32_t i3174 = 0; i3174 < 1024; ++i3174) {
        ((int8_t*)out1)[((((i1241 * 14336) + (i2174 * 1024)) + i3174))] = ((int8_t)((int32_t*)compute)[((((i1241 * 14336) + (i2174 * 1024)) + i3174))]);
      }
    }
  }
  for (int32_t i1242 = 0; i1242 < 14; ++i1242) {
    for (int32_t i2175 = 0; i2175 < 14; ++i2175) {
      for (int32_t i3175 = 0; i3175 < 1024; ++i3175) {
        ((int32_t*)compute)[((((i1242 * 14336) + (i2175 * 1024)) + i3175))] = ((int32_t)((int8_t*)out1)[((((i1242 * 14336) + (i2175 * 1024)) + i3175))]);
      }
    }
  }
  for (int32_t h478 = 0; h478 < 14; ++h478) {
    for (int32_t w237 = 0; w237 < 14; ++w237) {
      for (int32_t c273 = 0; c273 < 1024; ++c273) {
        ((int32_t*)out)[((((h478 * 14336) + (w237 * 1024)) + c273))] = ((int32_t*)tensor_533)[(c273)];
      }
    }
  }
  for (int32_t h479 = 0; h479 < 14; ++h479) {
    (void)load(compute, (int64_t)537264128, 7168, (h479 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h479 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h479 * 57344));
  }
  for (int32_t h480 = 0; h480 < 14; ++h480) {
    for (int32_t w238 = 0; w238 < 14; ++w238) {
      for (int32_t c274 = 0; c274 < 1024; ++c274) {
        ((int32_t*)compute)[((((h480 * 14336) + (w238 * 1024)) + c274))] = ((int32_t*)tensor_534)[(c274)];
      }
    }
  }
  for (int32_t h481 = 0; h481 < 14; ++h481) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h481 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h481 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h481 * 57344));
  }
  for (int32_t h482 = 0; h482 < 14; ++h482) {
    for (int32_t w239 = 0; w239 < 14; ++w239) {
      for (int32_t c275 = 0; c275 < 1024; ++c275) {
        ((int32_t*)compute)[((((h482 * 14336) + (w239 * 1024)) + c275))] = 8;
      }
    }
  }
  for (int32_t h483 = 0; h483 < 14; ++h483) {
    (void)load(out1, (int64_t)537264128, 7168, (h483 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h483 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h483 * 57344));
  }
  for (int32_t h484 = 0; h484 < 14; ++h484) {
    for (int32_t w240 = 0; w240 < 14; ++w240) {
      for (int32_t c276 = 0; c276 < 1024; ++c276) {
        ((int32_t*)compute)[((((h484 * 14336) + (w240 * 1024)) + c276))] = 4;
      }
    }
  }
  for (int32_t h485 = 0; h485 < 14; ++h485) {
    (void)load(out, (int64_t)537264128, 7168, (h485 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h485 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h485 * 57344));
  }
  for (int32_t i1243 = 0; i1243 < 14; ++i1243) {
    for (int32_t i2176 = 0; i2176 < 14; ++i2176) {
      for (int32_t i3176 = 0; i3176 < 1024; ++i3176) {
        int32_t _132 = ((int32_t*)pad_data)[((((i1243 * 14336) + (i2176 * 1024)) + i3176))];
        int32_t _133 = (_132) < (127) ? (_132) : (127);
        ((int32_t*)compute)[((((i1243 * 14336) + (i2176 * 1024)) + i3176))] = ((_133) > (-127) ? (_133) : (-127));
      }
    }
  }
  for (int32_t i1244 = 0; i1244 < 14; ++i1244) {
    for (int32_t i2177 = 0; i2177 < 14; ++i2177) {
      for (int32_t i3177 = 0; i3177 < 1024; ++i3177) {
        ((int8_t*)out1)[((((i1244 * 14336) + (i2177 * 1024)) + i3177))] = ((int8_t)((int32_t*)compute)[((((i1244 * 14336) + (i2177 * 1024)) + i3177))]);
      }
    }
  }
  for (int32_t i1245 = 0; i1245 < 14; ++i1245) {
    for (int32_t i2178 = 0; i2178 < 14; ++i2178) {
      for (int32_t i3178 = 0; i3178 < 1024; ++i3178) {
        ((int32_t*)compute)[((((i1245 * 14336) + (i2178 * 1024)) + i3178))] = ((int32_t)((int8_t*)out1)[((((i1245 * 14336) + (i2178 * 1024)) + i3178))]);
      }
    }
  }
  for (int32_t i1246 = 0; i1246 < 14; ++i1246) {
    for (int32_t i2179 = 0; i2179 < 14; ++i2179) {
      for (int32_t i3179 = 0; i3179 < 1024; ++i3179) {
        ((int32_t*)out)[((((i1246 * 14336) + (i2179 * 1024)) + i3179))] = ((int32_t)((int8_t*)compute1)[((((i1246 * 14336) + (i2179 * 1024)) + i3179))]);
      }
    }
  }
  for (int32_t h486 = 0; h486 < 14; ++h486) {
    (void)load(compute, (int64_t)537264128, 7168, (h486 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h486 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h486 * 57344));
  }
  for (int32_t h487 = 0; h487 < 14; ++h487) {
    for (int32_t w241 = 0; w241 < 14; ++w241) {
      for (int32_t c277 = 0; c277 < 1024; ++c277) {
        ((int32_t*)compute)[((((h487 * 14336) + (w241 * 1024)) + c277))] = 0;
      }
    }
  }
  for (int32_t h488 = 0; h488 < 14; ++h488) {
    (void)load(compute1, (int64_t)537264128, 7168, (h488 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h488 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h488 * 57344));
  }
  for (int32_t i1247 = 0; i1247 < 14; ++i1247) {
    for (int32_t i2180 = 0; i2180 < 14; ++i2180) {
      for (int32_t i3180 = 0; i3180 < 1024; ++i3180) {
        int32_t _134 = ((int32_t*)pad_data)[((((i1247 * 14336) + (i2180 * 1024)) + i3180))];
        int32_t _135 = (_134) < (127) ? (_134) : (127);
        ((int32_t*)compute)[((((i1247 * 14336) + (i2180 * 1024)) + i3180))] = ((_135) > (-127) ? (_135) : (-127));
      }
    }
  }
  for (int32_t i1248 = 0; i1248 < 14; ++i1248) {
    for (int32_t i2181 = 0; i2181 < 14; ++i2181) {
      for (int32_t i3181 = 0; i3181 < 1024; ++i3181) {
        ((int8_t*)compute1)[((((i1248 * 14336) + (i2181 * 1024)) + i3181))] = ((int8_t)((int32_t*)compute)[((((i1248 * 14336) + (i2181 * 1024)) + i3181))]);
      }
    }
  }
  for (int32_t o135 = 0; o135 < 14; ++o135) {
    for (int32_t o235 = 0; o235 < 14; ++o235) {
      for (int32_t c278 = 0; c278 < 1024; ++c278) {
        ((int8_t*)compute)[((((o135 * 14336) + (o235 * 1024)) + c278))] = ((int8_t*)compute1)[((((o135 * 14336) + (o235 * 1024)) + c278))];
      }
    }
  }
  for (int32_t ax0370 = 0; ax0370 < 196; ++ax0370) {
    for (int32_t ax1369 = 0; ax1369 < 1024; ++ax1369) {
      ((int8_t*)out1)[(((ax0370 * 1024) + ax1369))] = ((int8_t*)compute)[(((ax0370 * 1024) + ax1369))];
    }
  }
  for (int32_t i067 = 0; i067 < 200; ++i067) {
    for (int32_t i1249 = 0; i1249 < 1024; ++i1249) {
      ((int8_t*)compute)[(((i067 * 1024) + i1249))] = ((i067 < 196) ? ((int8_t*)out1)[(((i067 * 1024) + i1249))] : (int8_t)0);
    }
  }
  for (int32_t ax0371 = 0; ax0371 < 25; ++ax0371) {
    for (int32_t ax1370 = 0; ax1370 < 8; ++ax1370) {
      for (int32_t ax2308 = 0; ax2308 < 128; ++ax2308) {
        for (int32_t ax3308 = 0; ax3308 < 8; ++ax3308) {
          ((int8_t*)out)[(((((ax0371 * 8192) + (ax1370 * 1024)) + (ax2308 * 8)) + ax3308))] = ((int8_t*)compute)[(((((ax0371 * 8192) + (ax1370 * 1024)) + (ax2308 * 8)) + ax3308))];
        }
      }
    }
  }
  for (int32_t ax0372 = 0; ax0372 < 25; ++ax0372) {
    for (int32_t ax1371 = 0; ax1371 < 128; ++ax1371) {
      for (int32_t ax2309 = 0; ax2309 < 8; ++ax2309) {
        for (int32_t ax3309 = 0; ax3309 < 8; ++ax3309) {
          ((int8_t*)compute)[(((((ax0372 * 8192) + (ax1371 * 64)) + (ax2309 * 8)) + ax3309))] = ((int8_t*)out)[(((((ax0372 * 8192) + (ax2309 * 1024)) + (ax1371 * 8)) + ax3309))];
        }
      }
    }
  }
  for (int32_t ax0373 = 0; ax0373 < 25; ++ax0373) {
    for (int32_t ax2310 = 0; ax2310 < 128; ++ax2310) {
      for (int32_t ax3310 = 0; ax3310 < 8; ++ax3310) {
        for (int32_t ax466 = 0; ax466 < 8; ++ax466) {
          ((int8_t*)pad_data)[(((((ax0373 * 8192) + (ax2310 * 64)) + (ax3310 * 8)) + ax466))] = ((int8_t*)compute)[(((((ax0373 * 8192) + (ax2310 * 64)) + (ax3310 * 8)) + ax466))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536870912, 25600, 0);
  for (int32_t ax0374 = 0; ax0374 < 256; ++ax0374) {
    for (int32_t ax1372 = 0; ax1372 < 1024; ++ax1372) {
      ((int8_t*)compute)[(((ax0374 * 1024) + ax1372))] = ((int8_t*)kernel_549)[(((ax0374 * 1024) + ax1372))];
    }
  }
  for (int32_t ax0375 = 0; ax0375 < 32; ++ax0375) {
    for (int32_t ax1373 = 0; ax1373 < 8; ++ax1373) {
      for (int32_t ax2311 = 0; ax2311 < 128; ++ax2311) {
        for (int32_t ax3311 = 0; ax3311 < 8; ++ax3311) {
          ((int8_t*)out1)[(((((ax0375 * 8192) + (ax1373 * 1024)) + (ax2311 * 8)) + ax3311))] = ((int8_t*)compute)[(((((ax0375 * 8192) + (ax1373 * 1024)) + (ax2311 * 8)) + ax3311))];
        }
      }
    }
  }
  for (int32_t ax0376 = 0; ax0376 < 32; ++ax0376) {
    for (int32_t ax1374 = 0; ax1374 < 128; ++ax1374) {
      for (int32_t ax2312 = 0; ax2312 < 8; ++ax2312) {
        for (int32_t ax3312 = 0; ax3312 < 8; ++ax3312) {
          ((int8_t*)compute)[(((((ax0376 * 8192) + (ax1374 * 64)) + (ax2312 * 8)) + ax3312))] = ((int8_t*)out1)[(((((ax0376 * 8192) + (ax2312 * 1024)) + (ax1374 * 8)) + ax3312))];
        }
      }
    }
  }
  for (int32_t ax0377 = 0; ax0377 < 32; ++ax0377) {
    for (int32_t ax2313 = 0; ax2313 < 128; ++ax2313) {
      for (int32_t ax3313 = 0; ax3313 < 8; ++ax3313) {
        for (int32_t ax467 = 0; ax467 < 8; ++ax467) {
          ((int8_t*)out)[(((((ax0377 * 8192) + (ax2313 * 64)) + (ax3313 * 8)) + ax467))] = ((int8_t*)compute)[(((((ax0377 * 8192) + (ax2313 * 64)) + (ax3313 * 8)) + ax467))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 32768, 0);
  for (int32_t i70 = 0; i70 < 25; ++i70) {
    for (int32_t x39 = 0; x39 < 32; ++x39) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)(i70 * 512)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x39 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i70 * 8192) + (x39 * 256)));
    }
  }
  for (int32_t ax0378 = 0; ax0378 < 25; ++ax0378) {
    for (int32_t ax1375 = 0; ax1375 < 8; ++ax1375) {
      for (int32_t ax2314 = 0; ax2314 < 32; ++ax2314) {
        for (int32_t ax3314 = 0; ax3314 < 8; ++ax3314) {
          ((int32_t*)pad_data)[(((((ax0378 * 2048) + (ax1375 * 256)) + (ax2314 * 8)) + ax3314))] = ((int32_t*)compute)[(((((ax0378 * 2048) + (ax2314 * 64)) + (ax1375 * 8)) + ax3314))];
        }
      }
    }
  }
  for (int32_t ax0379 = 0; ax0379 < 196; ++ax0379) {
    for (int32_t ax1376 = 0; ax1376 < 256; ++ax1376) {
      ((int32_t*)compute)[(((ax0379 * 256) + ax1376))] = ((int32_t*)pad_data)[(((ax0379 * 256) + ax1376))];
    }
  }
  for (int32_t i068 = 0; i068 < 196; ++i068) {
    for (int32_t i1250 = 0; i1250 < 256; ++i1250) {
      ((int32_t*)out1)[(((i068 * 256) + i1250))] = ((int32_t*)compute)[(((i068 * 256) + i1250))];
    }
  }
  for (int32_t ax1377 = 0; ax1377 < 14; ++ax1377) {
    for (int32_t ax2315 = 0; ax2315 < 14; ++ax2315) {
      for (int32_t ax3315 = 0; ax3315 < 256; ++ax3315) {
        ((int32_t*)compute)[((((ax1377 * 3584) + (ax2315 * 256)) + ax3315))] = ((int32_t*)out1)[((((ax1377 * 3584) + (ax2315 * 256)) + ax3315))];
      }
    }
  }
  for (int32_t h489 = 0; h489 < 14; ++h489) {
    for (int32_t w242 = 0; w242 < 14; ++w242) {
      for (int32_t c279 = 0; c279 < 256; ++c279) {
        ((int32_t*)out)[((((h489 * 3584) + (w242 * 256)) + c279))] = 12;
      }
    }
  }
  for (int32_t h490 = 0; h490 < 14; ++h490) {
    (void)load(compute, (int64_t)537264128, 1792, (h490 * 3584));
    (void)load(out, (int64_t)537329664, 1792, (h490 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h490 * 14336));
  }
  for (int32_t h491 = 0; h491 < 14; ++h491) {
    for (int32_t w243 = 0; w243 < 14; ++w243) {
      for (int32_t c280 = 0; c280 < 256; ++c280) {
        ((int32_t*)compute)[((((h491 * 3584) + (w243 * 256)) + c280))] = ((int32_t*)tensor_551)[(c280)];
      }
    }
  }
  for (int32_t h492 = 0; h492 < 14; ++h492) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h492 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h492 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h492 * 14336));
  }
  for (int32_t h493 = 0; h493 < 14; ++h493) {
    for (int32_t w244 = 0; w244 < 14; ++w244) {
      for (int32_t c281 = 0; c281 < 256; ++c281) {
        ((int32_t*)compute)[((((h493 * 3584) + (w244 * 256)) + c281))] = ((int32_t*)tensor_552)[(c281)];
      }
    }
  }
  for (int32_t h494 = 0; h494 < 14; ++h494) {
    (void)load(out1, (int64_t)537264128, 1792, (h494 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h494 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h494 * 14336));
  }
  for (int32_t h495 = 0; h495 < 14; ++h495) {
    for (int32_t w245 = 0; w245 < 14; ++w245) {
      for (int32_t c282 = 0; c282 < 256; ++c282) {
        ((int32_t*)compute)[((((h495 * 3584) + (w245 * 256)) + c282))] = 0;
      }
    }
  }
  for (int32_t h496 = 0; h496 < 14; ++h496) {
    (void)load(out, (int64_t)537264128, 1792, (h496 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h496 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h496 * 14336));
  }
  for (int32_t h497 = 0; h497 < 14; ++h497) {
    for (int32_t w246 = 0; w246 < 14; ++w246) {
      for (int32_t c283 = 0; c283 < 256; ++c283) {
        ((int32_t*)compute)[((((h497 * 3584) + (w246 * 256)) + c283))] = 524288;
      }
    }
  }
  for (int32_t h498 = 0; h498 < 14; ++h498) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h498 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h498 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h498 * 14336));
  }
  for (int32_t h499 = 0; h499 < 14; ++h499) {
    for (int32_t w247 = 0; w247 < 14; ++w247) {
      for (int32_t c284 = 0; c284 < 256; ++c284) {
        ((int32_t*)compute)[((((h499 * 3584) + (w247 * 256)) + c284))] = 20;
      }
    }
  }
  for (int32_t h500 = 0; h500 < 14; ++h500) {
    (void)load(out1, (int64_t)537264128, 1792, (h500 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h500 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h500 * 14336));
  }
  for (int32_t i1251 = 0; i1251 < 14; ++i1251) {
    for (int32_t i2182 = 0; i2182 < 14; ++i2182) {
      for (int32_t i3182 = 0; i3182 < 256; ++i3182) {
        int32_t _136 = ((int32_t*)out)[((((i1251 * 3584) + (i2182 * 256)) + i3182))];
        int32_t _137 = (_136) < (127) ? (_136) : (127);
        ((int32_t*)compute)[((((i1251 * 3584) + (i2182 * 256)) + i3182))] = ((_137) > (-127) ? (_137) : (-127));
      }
    }
  }
  for (int32_t i1252 = 0; i1252 < 14; ++i1252) {
    for (int32_t i2183 = 0; i2183 < 14; ++i2183) {
      for (int32_t i3183 = 0; i3183 < 256; ++i3183) {
        ((int8_t*)T_reshape1)[((((i1252 * 3584) + (i2183 * 256)) + i3183))] = ((int8_t)((int32_t*)compute)[((((i1252 * 3584) + (i2183 * 256)) + i3183))]);
      }
    }
  }
  for (int32_t i1253 = 0; i1253 < 16; ++i1253) {
    for (int32_t i2184 = 0; i2184 < 16; ++i2184) {
      for (int32_t i3184 = 0; i3184 < 256; ++i3184) {
        ((int8_t*)T_reshape)[((((i1253 * 4096) + (i2184 * 256)) + i3184))] = (((((1 <= i1253) && (i1253 < 15)) && (1 <= i2184)) && (i2184 < 15)) ? ((int8_t*)T_reshape1)[(((((i1253 * 3584) + (i2184 * 256)) + i3184) - 3840))] : (int8_t)0);
      }
    }
  }
  for (int32_t o136 = 0; o136 < 14; ++o136) {
    for (int32_t o236 = 0; o236 < 14; ++o236) {
      for (int32_t k112 = 0; k112 < 3; ++k112) {
        for (int32_t k212 = 0; k212 < 3; ++k212) {
          for (int32_t c285 = 0; c285 < 256; ++c285) {
            ((int8_t*)compute)[((((((o136 * 32256) + (o236 * 2304)) + (k112 * 768)) + (k212 * 256)) + c285))] = ((int8_t*)T_reshape)[((((((k112 * 4096) + (o136 * 4096)) + (k212 * 256)) + (o236 * 256)) + c285))];
          }
        }
      }
    }
  }
  for (int32_t ax0380 = 0; ax0380 < 196; ++ax0380) {
    for (int32_t ax1378 = 0; ax1378 < 2304; ++ax1378) {
      ((int8_t*)pad_data)[(((ax0380 * 2304) + ax1378))] = ((int8_t*)compute)[(((ax0380 * 2304) + ax1378))];
    }
  }
  for (int32_t i069 = 0; i069 < 200; ++i069) {
    for (int32_t i1254 = 0; i1254 < 2304; ++i1254) {
      ((int8_t*)compute)[(((i069 * 2304) + i1254))] = ((i069 < 196) ? ((int8_t*)pad_data)[(((i069 * 2304) + i1254))] : (int8_t)0);
    }
  }
  for (int32_t ax0381 = 0; ax0381 < 25; ++ax0381) {
    for (int32_t ax1379 = 0; ax1379 < 8; ++ax1379) {
      for (int32_t ax2316 = 0; ax2316 < 288; ++ax2316) {
        for (int32_t ax3316 = 0; ax3316 < 8; ++ax3316) {
          ((int8_t*)out1)[(((((ax0381 * 18432) + (ax1379 * 2304)) + (ax2316 * 8)) + ax3316))] = ((int8_t*)compute)[(((((ax0381 * 18432) + (ax1379 * 2304)) + (ax2316 * 8)) + ax3316))];
        }
      }
    }
  }
  for (int32_t ax0382 = 0; ax0382 < 25; ++ax0382) {
    for (int32_t ax1380 = 0; ax1380 < 288; ++ax1380) {
      for (int32_t ax2317 = 0; ax2317 < 8; ++ax2317) {
        for (int32_t ax3317 = 0; ax3317 < 8; ++ax3317) {
          ((int8_t*)compute)[(((((ax0382 * 18432) + (ax1380 * 64)) + (ax2317 * 8)) + ax3317))] = ((int8_t*)out1)[(((((ax0382 * 18432) + (ax2317 * 2304)) + (ax1380 * 8)) + ax3317))];
        }
      }
    }
  }
  for (int32_t ax0383 = 0; ax0383 < 25; ++ax0383) {
    for (int32_t ax1381 = 0; ax1381 < 4; ++ax1381) {
      for (int32_t ax2318 = 0; ax2318 < 72; ++ax2318) {
        for (int32_t ax3318 = 0; ax3318 < 8; ++ax3318) {
          for (int32_t ax468 = 0; ax468 < 8; ++ax468) {
            ((int8_t*)out)[((((((ax0383 * 18432) + (ax1381 * 4608)) + (ax2318 * 64)) + (ax3318 * 8)) + ax468))] = ((int8_t*)compute)[((((((ax0383 * 18432) + (ax1381 * 4608)) + (ax2318 * 64)) + (ax3318 * 8)) + ax468))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536870912, 57600, 0);
  for (int32_t ax0384 = 0; ax0384 < 256; ++ax0384) {
    for (int32_t ax1382 = 0; ax1382 < 2304; ++ax1382) {
      ((int8_t*)compute)[(((ax0384 * 2304) + ax1382))] = ((int8_t*)kernel_559)[(((ax0384 * 2304) + ax1382))];
    }
  }
  for (int32_t ax0385 = 0; ax0385 < 32; ++ax0385) {
    for (int32_t ax1383 = 0; ax1383 < 8; ++ax1383) {
      for (int32_t ax2319 = 0; ax2319 < 288; ++ax2319) {
        for (int32_t ax3319 = 0; ax3319 < 8; ++ax3319) {
          ((int8_t*)pad_data)[(((((ax0385 * 18432) + (ax1383 * 2304)) + (ax2319 * 8)) + ax3319))] = ((int8_t*)compute)[(((((ax0385 * 18432) + (ax1383 * 2304)) + (ax2319 * 8)) + ax3319))];
        }
      }
    }
  }
  for (int32_t ax0386 = 0; ax0386 < 32; ++ax0386) {
    for (int32_t ax1384 = 0; ax1384 < 288; ++ax1384) {
      for (int32_t ax2320 = 0; ax2320 < 8; ++ax2320) {
        for (int32_t ax3320 = 0; ax3320 < 8; ++ax3320) {
          ((int8_t*)compute)[(((((ax0386 * 18432) + (ax1384 * 64)) + (ax2320 * 8)) + ax3320))] = ((int8_t*)pad_data)[(((((ax0386 * 18432) + (ax2320 * 2304)) + (ax1384 * 8)) + ax3320))];
        }
      }
    }
  }
  for (int32_t ax0387 = 0; ax0387 < 32; ++ax0387) {
    for (int32_t ax1385 = 0; ax1385 < 4; ++ax1385) {
      for (int32_t ax2321 = 0; ax2321 < 72; ++ax2321) {
        for (int32_t ax3321 = 0; ax3321 < 8; ++ax3321) {
          for (int32_t ax469 = 0; ax469 < 8; ++ax469) {
            ((int8_t*)out1)[((((((ax0387 * 18432) + (ax1385 * 4608)) + (ax2321 * 64)) + (ax3321 * 8)) + ax469))] = ((int8_t*)compute)[((((((ax0387 * 18432) + (ax1385 * 4608)) + (ax2321 * 64)) + (ax3321 * 8)) + ax469))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 73728, 0);
  for (int32_t i71 = 0; i71 < 25; ++i71) {
    for (int32_t x40 = 0; x40 < 32; ++x40) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k09 = 0; k09 < 4; ++k09) {
        (void)move(((((int64_t)((i71 * 1152) + (k09 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x40 * 1152) + (k09 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute, (int64_t)537264128, 32, ((i71 * 8192) + (x40 * 256)));
    }
  }
  for (int32_t ax0388 = 0; ax0388 < 25; ++ax0388) {
    for (int32_t ax1386 = 0; ax1386 < 8; ++ax1386) {
      for (int32_t ax2322 = 0; ax2322 < 32; ++ax2322) {
        for (int32_t ax3322 = 0; ax3322 < 8; ++ax3322) {
          ((int32_t*)out)[(((((ax0388 * 2048) + (ax1386 * 256)) + (ax2322 * 8)) + ax3322))] = ((int32_t*)compute)[(((((ax0388 * 2048) + (ax2322 * 64)) + (ax1386 * 8)) + ax3322))];
        }
      }
    }
  }
  for (int32_t ax0389 = 0; ax0389 < 196; ++ax0389) {
    for (int32_t ax1387 = 0; ax1387 < 256; ++ax1387) {
      ((int32_t*)compute)[(((ax0389 * 256) + ax1387))] = ((int32_t*)out)[(((ax0389 * 256) + ax1387))];
    }
  }
  for (int32_t i070 = 0; i070 < 196; ++i070) {
    for (int32_t i1255 = 0; i1255 < 256; ++i1255) {
      ((int32_t*)pad_data)[(((i070 * 256) + i1255))] = ((int32_t*)compute)[(((i070 * 256) + i1255))];
    }
  }
  for (int32_t ax1388 = 0; ax1388 < 14; ++ax1388) {
    for (int32_t ax2323 = 0; ax2323 < 14; ++ax2323) {
      for (int32_t ax3323 = 0; ax3323 < 256; ++ax3323) {
        ((int32_t*)compute)[((((ax1388 * 3584) + (ax2323 * 256)) + ax3323))] = ((int32_t*)pad_data)[((((ax1388 * 3584) + (ax2323 * 256)) + ax3323))];
      }
    }
  }
  for (int32_t h501 = 0; h501 < 14; ++h501) {
    for (int32_t w248 = 0; w248 < 14; ++w248) {
      for (int32_t c286 = 0; c286 < 256; ++c286) {
        ((int32_t*)out1)[((((h501 * 3584) + (w248 * 256)) + c286))] = ((int32_t*)tensor_560)[(c286)];
      }
    }
  }
  for (int32_t h502 = 0; h502 < 14; ++h502) {
    (void)load(compute, (int64_t)537264128, 1792, (h502 * 3584));
    (void)load(out1, (int64_t)537329664, 1792, (h502 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h502 * 14336));
  }
  for (int32_t h503 = 0; h503 < 14; ++h503) {
    for (int32_t w249 = 0; w249 < 14; ++w249) {
      for (int32_t c287 = 0; c287 < 256; ++c287) {
        ((int32_t*)compute)[((((h503 * 3584) + (w249 * 256)) + c287))] = 0;
      }
    }
  }
  for (int32_t h504 = 0; h504 < 14; ++h504) {
    (void)load(out, (int64_t)537264128, 1792, (h504 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h504 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 1792, (h504 * 14336));
  }
  for (int32_t h505 = 0; h505 < 14; ++h505) {
    for (int32_t w250 = 0; w250 < 14; ++w250) {
      for (int32_t c288 = 0; c288 < 256; ++c288) {
        ((int32_t*)compute)[((((h505 * 3584) + (w250 * 256)) + c288))] = 64;
      }
    }
  }
  for (int32_t h506 = 0; h506 < 14; ++h506) {
    (void)load(pad_data, (int64_t)537264128, 1792, (h506 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h506 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 1792, (h506 * 14336));
  }
  for (int32_t h507 = 0; h507 < 14; ++h507) {
    for (int32_t w251 = 0; w251 < 14; ++w251) {
      for (int32_t c289 = 0; c289 < 256; ++c289) {
        ((int32_t*)compute)[((((h507 * 3584) + (w251 * 256)) + c289))] = 7;
      }
    }
  }
  for (int32_t h508 = 0; h508 < 14; ++h508) {
    (void)load(out1, (int64_t)537264128, 1792, (h508 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h508 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out, (int64_t)537395200, 1792, (h508 * 14336));
  }
  for (int32_t i1256 = 0; i1256 < 14; ++i1256) {
    for (int32_t i2185 = 0; i2185 < 14; ++i2185) {
      for (int32_t i3185 = 0; i3185 < 256; ++i3185) {
        int32_t _138 = ((int32_t*)out)[((((i1256 * 3584) + (i2185 * 256)) + i3185))];
        int32_t _139 = (_138) < (127) ? (_138) : (127);
        ((int32_t*)compute)[((((i1256 * 3584) + (i2185 * 256)) + i3185))] = ((_139) > (-127) ? (_139) : (-127));
      }
    }
  }
  for (int32_t i1257 = 0; i1257 < 14; ++i1257) {
    for (int32_t i2186 = 0; i2186 < 14; ++i2186) {
      for (int32_t i3186 = 0; i3186 < 256; ++i3186) {
        ((int8_t*)T_reshape1)[((((i1257 * 3584) + (i2186 * 256)) + i3186))] = ((int8_t)((int32_t*)compute)[((((i1257 * 3584) + (i2186 * 256)) + i3186))]);
      }
    }
  }
  for (int32_t o137 = 0; o137 < 14; ++o137) {
    for (int32_t o237 = 0; o237 < 14; ++o237) {
      for (int32_t c290 = 0; c290 < 256; ++c290) {
        ((int8_t*)T_reshape)[((((o137 * 3584) + (o237 * 256)) + c290))] = ((int8_t*)T_reshape1)[((((o137 * 3584) + (o237 * 256)) + c290))];
      }
    }
  }
  for (int32_t ax0390 = 0; ax0390 < 184; ++ax0390) {
    for (int32_t ax1389 = 0; ax1389 < 256; ++ax1389) {
      ((int8_t*)T_reshape1)[(((ax0390 * 256) + ax1389))] = ((int8_t*)T_reshape)[(((ax0390 * 256) + ax1389))];
    }
  }
  for (int32_t i071 = 0; i071 < 184; ++i071) {
    for (int32_t i1258 = 0; i1258 < 256; ++i1258) {
      ((int8_t*)T_reshape)[(((i071 * 256) + i1258))] = ((int8_t*)T_reshape1)[(((i071 * 256) + i1258))];
    }
  }
  for (int32_t ax0391 = 0; ax0391 < 23; ++ax0391) {
    for (int32_t ax1390 = 0; ax1390 < 8; ++ax1390) {
      for (int32_t ax2324 = 0; ax2324 < 32; ++ax2324) {
        for (int32_t ax3324 = 0; ax3324 < 8; ++ax3324) {
          ((int8_t*)T_reshape1)[(((((ax0391 * 2048) + (ax1390 * 256)) + (ax2324 * 8)) + ax3324))] = ((int8_t*)T_reshape)[(((((ax0391 * 2048) + (ax1390 * 256)) + (ax2324 * 8)) + ax3324))];
        }
      }
    }
  }
  for (int32_t ax0392 = 0; ax0392 < 23; ++ax0392) {
    for (int32_t ax1391 = 0; ax1391 < 32; ++ax1391) {
      for (int32_t ax2325 = 0; ax2325 < 8; ++ax2325) {
        for (int32_t ax3325 = 0; ax3325 < 8; ++ax3325) {
          ((int8_t*)T_reshape)[(((((ax0392 * 2048) + (ax1391 * 64)) + (ax2325 * 8)) + ax3325))] = ((int8_t*)T_reshape1)[(((((ax0392 * 2048) + (ax2325 * 256)) + (ax1391 * 8)) + ax3325))];
        }
      }
    }
  }
  for (int32_t ax0393 = 0; ax0393 < 23; ++ax0393) {
    for (int32_t ax2326 = 0; ax2326 < 32; ++ax2326) {
      for (int32_t ax3326 = 0; ax3326 < 8; ++ax3326) {
        for (int32_t ax470 = 0; ax470 < 8; ++ax470) {
          ((int8_t*)T_reshape1)[(((((ax0393 * 2048) + (ax2326 * 64)) + (ax3326 * 8)) + ax470))] = ((int8_t*)T_reshape)[(((((ax0393 * 2048) + (ax2326 * 64)) + (ax3326 * 8)) + ax470))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 5888, 0);
  for (int32_t ax0394 = 0; ax0394 < 1024; ++ax0394) {
    for (int32_t ax1392 = 0; ax1392 < 256; ++ax1392) {
      ((int8_t*)compute)[(((ax0394 * 256) + ax1392))] = ((int8_t*)kernel_567)[(((ax0394 * 256) + ax1392))];
    }
  }
  for (int32_t ax0395 = 0; ax0395 < 128; ++ax0395) {
    for (int32_t ax1393 = 0; ax1393 < 8; ++ax1393) {
      for (int32_t ax2327 = 0; ax2327 < 32; ++ax2327) {
        for (int32_t ax3327 = 0; ax3327 < 8; ++ax3327) {
          ((int8_t*)pad_data)[(((((ax0395 * 2048) + (ax1393 * 256)) + (ax2327 * 8)) + ax3327))] = ((int8_t*)compute)[(((((ax0395 * 2048) + (ax1393 * 256)) + (ax2327 * 8)) + ax3327))];
        }
      }
    }
  }
  for (int32_t ax0396 = 0; ax0396 < 128; ++ax0396) {
    for (int32_t ax1394 = 0; ax1394 < 32; ++ax1394) {
      for (int32_t ax2328 = 0; ax2328 < 8; ++ax2328) {
        for (int32_t ax3328 = 0; ax3328 < 8; ++ax3328) {
          ((int8_t*)compute)[(((((ax0396 * 2048) + (ax1394 * 64)) + (ax2328 * 8)) + ax3328))] = ((int8_t*)pad_data)[(((((ax0396 * 2048) + (ax2328 * 256)) + (ax1394 * 8)) + ax3328))];
        }
      }
    }
  }
  for (int32_t ax0397 = 0; ax0397 < 128; ++ax0397) {
    for (int32_t ax2329 = 0; ax2329 < 32; ++ax2329) {
      for (int32_t ax3329 = 0; ax3329 < 8; ++ax3329) {
        for (int32_t ax471 = 0; ax471 < 8; ++ax471) {
          ((int8_t*)out1)[(((((ax0397 * 2048) + (ax2329 * 64)) + (ax3329 * 8)) + ax471))] = ((int8_t*)compute)[(((((ax0397 * 2048) + (ax2329 * 64)) + (ax3329 * 8)) + ax471))];
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 32768, 0);
  for (int32_t i72 = 0; i72 < 23; ++i72) {
    for (int32_t x41 = 0; x41 < 128; ++x41) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i72 * 128) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 256, 0);
      (void)move(((((int64_t)(x41 * 128)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 256, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 32, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i72 * 32768) + (x41 * 256)));
    }
  }
  for (int32_t ax0398 = 0; ax0398 < 23; ++ax0398) {
    for (int32_t ax1395 = 0; ax1395 < 8; ++ax1395) {
      for (int32_t ax2330 = 0; ax2330 < 128; ++ax2330) {
        for (int32_t ax3330 = 0; ax3330 < 8; ++ax3330) {
          ((int32_t*)out)[(((((ax0398 * 8192) + (ax1395 * 1024)) + (ax2330 * 8)) + ax3330))] = ((int32_t*)compute)[(((((ax0398 * 8192) + (ax2330 * 64)) + (ax1395 * 8)) + ax3330))];
        }
      }
    }
  }
  for (int32_t ax0399 = 0; ax0399 < 181; ++ax0399) {
    for (int32_t ax1396 = 0; ax1396 < 1024; ++ax1396) {
      ((int32_t*)compute)[(((ax0399 * 1024) + ax1396))] = ((int32_t*)out)[(((ax0399 * 1024) + ax1396))];
    }
  }
  for (int32_t i072 = 0; i072 < 181; ++i072) {
    for (int32_t i1259 = 0; i1259 < 1024; ++i1259) {
      ((int32_t*)pad_data)[(((i072 * 1024) + i1259))] = ((int32_t*)compute)[(((i072 * 1024) + i1259))];
    }
  }
  for (int32_t ax1397 = 0; ax1397 < 13; ++ax1397) {
    for (int32_t ax2331 = 0; ax2331 < 13; ++ax2331) {
      for (int32_t ax3331 = 0; ax3331 < 1024; ++ax3331) {
        ((int32_t*)compute)[((((ax1397 * 13312) + (ax2331 * 1024)) + ax3331))] = ((int32_t*)pad_data)[((((ax1397 * 14336) + (ax2331 * 1024)) + ax3331))];
      }
    }
  }
  for (int32_t h509 = 0; h509 < 13; ++h509) {
    for (int32_t w252 = 0; w252 < 13; ++w252) {
      for (int32_t c291 = 0; c291 < 1024; ++c291) {
        ((int32_t*)out1)[((((h509 * 13312) + (w252 * 1024)) + c291))] = 9;
      }
    }
  }
  for (int32_t h510 = 0; h510 < 13; ++h510) {
    (void)load(compute, (int64_t)537264128, 6656, (h510 * 13312));
    (void)load(out1, (int64_t)537329664, 6656, (h510 * 13312));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6656, (h510 * 53248));
  }
  for (int32_t h511 = 0; h511 < 13; ++h511) {
    for (int32_t w253 = 0; w253 < 13; ++w253) {
      for (int32_t c292 = 0; c292 < 1024; ++c292) {
        ((int32_t*)compute)[((((h511 * 13312) + (w253 * 1024)) + c292))] = ((int32_t*)tensor_569)[(c292)];
      }
    }
  }
  for (int32_t h512 = 0; h512 < 13; ++h512) {
    (void)load(out, (int64_t)537264128, 6656, (h512 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h512 * 13312));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 6656, (h512 * 53248));
  }
  for (int32_t h513 = 0; h513 < 13; ++h513) {
    for (int32_t w254 = 0; w254 < 13; ++w254) {
      for (int32_t c293 = 0; c293 < 1024; ++c293) {
        ((int32_t*)compute)[((((h513 * 13312) + (w254 * 1024)) + c293))] = 131072;
      }
    }
  }
  for (int32_t h514 = 0; h514 < 13; ++h514) {
    (void)load(pad_data, (int64_t)537264128, 6656, (h514 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h514 * 13312));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 6656, (h514 * 53248));
  }
  for (int32_t h515 = 0; h515 < 13; ++h515) {
    for (int32_t w255 = 0; w255 < 13; ++w255) {
      for (int32_t c294 = 0; c294 < 1024; ++c294) {
        ((int32_t*)compute)[((((h515 * 13312) + (w255 * 1024)) + c294))] = 18;
      }
    }
  }
  for (int32_t h516 = 0; h516 < 13; ++h516) {
    (void)load(out1, (int64_t)537264128, 6656, (h516 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h516 * 13312));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6656, (h516 * 53248));
  }
  for (int32_t i1260 = 0; i1260 < 13; ++i1260) {
    for (int32_t i2187 = 0; i2187 < 13; ++i2187) {
      for (int32_t i3187 = 0; i3187 < 1024; ++i3187) {
        int32_t _140 = ((int32_t*)out)[((((i1260 * 13312) + (i2187 * 1024)) + i3187))];
        int32_t _141 = (_140) < (127) ? (_140) : (127);
        ((int32_t*)compute)[((((i1260 * 13312) + (i2187 * 1024)) + i3187))] = ((_141) > (-127) ? (_141) : (-127));
      }
    }
  }
  for (int32_t i1261 = 0; i1261 < 13; ++i1261) {
    for (int32_t i2188 = 0; i2188 < 13; ++i2188) {
      for (int32_t i3188 = 0; i3188 < 1024; ++i3188) {
        ((int8_t*)T_reshape)[((((i1261 * 13312) + (i2188 * 1024)) + i3188))] = ((int8_t)((int32_t*)compute)[((((i1261 * 13312) + (i2188 * 1024)) + i3188))]);
      }
    }
  }
  for (int32_t i1262 = 0; i1262 < 13; ++i1262) {
    for (int32_t i2189 = 0; i2189 < 13; ++i2189) {
      for (int32_t i3189 = 0; i3189 < 1024; ++i3189) {
        ((int32_t*)compute)[((((i1262 * 13312) + (i2189 * 1024)) + i3189))] = ((int32_t)((int8_t*)T_reshape)[((((i1262 * 13312) + (i2189 * 1024)) + i3189))]);
      }
    }
  }
  for (int32_t h517 = 0; h517 < 13; ++h517) {
    for (int32_t w256 = 0; w256 < 13; ++w256) {
      for (int32_t c295 = 0; c295 < 1024; ++c295) {
        ((int32_t*)pad_data)[((((h517 * 13312) + (w256 * 1024)) + c295))] = ((int32_t*)tensor_576)[(c295)];
      }
    }
  }
  for (int32_t h518 = 0; h518 < 13; ++h518) {
    (void)load(compute, (int64_t)537264128, 6656, (h518 * 13312));
    (void)load(pad_data, (int64_t)537329664, 6656, (h518 * 13312));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 6656, (h518 * 53248));
  }
  for (int32_t h519 = 0; h519 < 13; ++h519) {
    for (int32_t w257 = 0; w257 < 13; ++w257) {
      for (int32_t c296 = 0; c296 < 1024; ++c296) {
        ((int32_t*)compute)[((((h519 * 13312) + (w257 * 1024)) + c296))] = ((int32_t*)tensor_577)[(c296)];
      }
    }
  }
  for (int32_t h520 = 0; h520 < 13; ++h520) {
    (void)load(out1, (int64_t)537264128, 6656, (h520 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h520 * 13312));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(out, (int64_t)537395200, 6656, (h520 * 53248));
  }
  for (int32_t h521 = 0; h521 < 13; ++h521) {
    for (int32_t w258 = 0; w258 < 13; ++w258) {
      for (int32_t c297 = 0; c297 < 1024; ++c297) {
        ((int32_t*)compute)[((((h521 * 13312) + (w258 * 1024)) + c297))] = 8;
      }
    }
  }
  for (int32_t h522 = 0; h522 < 13; ++h522) {
    (void)load(out, (int64_t)537264128, 6656, (h522 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h522 * 13312));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 6656, (h522 * 53248));
  }
  for (int32_t h523 = 0; h523 < 13; ++h523) {
    for (int32_t w259 = 0; w259 < 13; ++w259) {
      for (int32_t c298 = 0; c298 < 1024; ++c298) {
        ((int32_t*)compute)[((((h523 * 13312) + (w259 * 1024)) + c298))] = 4;
      }
    }
  }
  for (int32_t h524 = 0; h524 < 13; ++h524) {
    (void)load(pad_data, (int64_t)537264128, 6656, (h524 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h524 * 13312));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 6656, (h524 * 53248));
  }
  for (int32_t i1263 = 0; i1263 < 13; ++i1263) {
    for (int32_t i2190 = 0; i2190 < 13; ++i2190) {
      for (int32_t i3190 = 0; i3190 < 1024; ++i3190) {
        int32_t _142 = ((int32_t*)out1)[((((i1263 * 13312) + (i2190 * 1024)) + i3190))];
        int32_t _143 = (_142) < (127) ? (_142) : (127);
        ((int32_t*)compute)[((((i1263 * 13312) + (i2190 * 1024)) + i3190))] = ((_143) > (-127) ? (_143) : (-127));
      }
    }
  }
  for (int32_t i1264 = 0; i1264 < 13; ++i1264) {
    for (int32_t i2191 = 0; i2191 < 13; ++i2191) {
      for (int32_t i3191 = 0; i3191 < 1024; ++i3191) {
        ((int8_t*)T_reshape)[((((i1264 * 13312) + (i2191 * 1024)) + i3191))] = ((int8_t)((int32_t*)compute)[((((i1264 * 13312) + (i2191 * 1024)) + i3191))]);
      }
    }
  }
  for (int32_t i1265 = 0; i1265 < 13; ++i1265) {
    for (int32_t i2192 = 0; i2192 < 13; ++i2192) {
      for (int32_t i3192 = 0; i3192 < 1024; ++i3192) {
        ((int32_t*)compute)[((((i1265 * 13312) + (i2192 * 1024)) + i3192))] = ((int32_t)((int8_t*)T_reshape)[((((i1265 * 13312) + (i2192 * 1024)) + i3192))]);
      }
    }
  }
  for (int32_t i1266 = 0; i1266 < 13; ++i1266) {
    for (int32_t i2193 = 0; i2193 < 13; ++i2193) {
      for (int32_t i3193 = 0; i3193 < 1024; ++i3193) {
        ((int32_t*)out)[((((i1266 * 13312) + (i2193 * 1024)) + i3193))] = ((int32_t)((int8_t*)compute1)[((((i1266 * 14336) + (i2193 * 1024)) + i3193))]);
      }
    }
  }
  for (int32_t h525 = 0; h525 < 13; ++h525) {
    (void)load(compute, (int64_t)537264128, 6656, (h525 * 13312));
    (void)load(out, (int64_t)537329664, 6656, (h525 * 13312));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 6656, (h525 * 53248));
  }
  for (int32_t h526 = 0; h526 < 13; ++h526) {
    for (int32_t w260 = 0; w260 < 13; ++w260) {
      for (int32_t c299 = 0; c299 < 1024; ++c299) {
        ((int32_t*)compute)[((((h526 * 13312) + (w260 * 1024)) + c299))] = 0;
      }
    }
  }
  for (int32_t h527 = 0; h527 < 13; ++h527) {
    (void)load(compute1, (int64_t)537264128, 6656, (h527 * 13312));
    (void)load(compute, (int64_t)537329664, 6656, (h527 * 13312));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 416, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 6656, (h527 * 53248));
  }
  for (int32_t i1267 = 0; i1267 < 13; ++i1267) {
    for (int32_t i2194 = 0; i2194 < 13; ++i2194) {
      for (int32_t i3194 = 0; i3194 < 1024; ++i3194) {
        int32_t _144 = ((int32_t*)pad_data)[((((i1267 * 13312) + (i2194 * 1024)) + i3194))];
        int32_t _145 = (_144) < (127) ? (_144) : (127);
        ((int32_t*)compute)[((((i1267 * 13312) + (i2194 * 1024)) + i3194))] = ((_145) > (-127) ? (_145) : (-127));
      }
    }
  }
  for (int32_t i1268 = 0; i1268 < 13; ++i1268) {
    for (int32_t i2195 = 0; i2195 < 13; ++i2195) {
      for (int32_t i3195 = 0; i3195 < 1024; ++i3195) {
        ((int8_t*)T_reshape)[((((i1268 * 13312) + (i2195 * 1024)) + i3195))] = ((int8_t)((int32_t*)compute)[((((i1268 * 13312) + (i2195 * 1024)) + i3195))]);
      }
    }
  }
  for (int32_t o138 = 0; o138 < 7; ++o138) {
    for (int32_t o238 = 0; o238 < 7; ++o238) {
      for (int32_t c300 = 0; c300 < 1024; ++c300) {
        ((int8_t*)T_reshape1)[((((o138 * 7168) + (o238 * 1024)) + c300))] = ((int8_t*)T_reshape)[((((o138 * 26624) + (o238 * 2048)) + c300))];
      }
    }
  }
  for (int32_t ax0400 = 0; ax0400 < 49; ++ax0400) {
    for (int32_t ax1398 = 0; ax1398 < 1024; ++ax1398) {
      ((int8_t*)compute)[(((ax0400 * 1024) + ax1398))] = ((int8_t*)T_reshape1)[(((ax0400 * 1024) + ax1398))];
    }
  }
  for (int32_t i073 = 0; i073 < 56; ++i073) {
    for (int32_t i1269 = 0; i1269 < 1024; ++i1269) {
      ((int8_t*)T_reshape1)[(((i073 * 1024) + i1269))] = ((i073 < 49) ? ((int8_t*)compute)[(((i073 * 1024) + i1269))] : (int8_t)0);
    }
  }
  for (int32_t ax0401 = 0; ax0401 < 7; ++ax0401) {
    for (int32_t ax1399 = 0; ax1399 < 8; ++ax1399) {
      for (int32_t ax2332 = 0; ax2332 < 128; ++ax2332) {
        for (int32_t ax3332 = 0; ax3332 < 8; ++ax3332) {
          ((int8_t*)compute)[(((((ax0401 * 8192) + (ax1399 * 1024)) + (ax2332 * 8)) + ax3332))] = ((int8_t*)T_reshape1)[(((((ax0401 * 8192) + (ax1399 * 1024)) + (ax2332 * 8)) + ax3332))];
        }
      }
    }
  }
  for (int32_t ax0402 = 0; ax0402 < 7; ++ax0402) {
    for (int32_t ax1400 = 0; ax1400 < 128; ++ax1400) {
      for (int32_t ax2333 = 0; ax2333 < 8; ++ax2333) {
        for (int32_t ax3333 = 0; ax3333 < 8; ++ax3333) {
          ((int8_t*)T_reshape1)[(((((ax0402 * 8192) + (ax1400 * 64)) + (ax2333 * 8)) + ax3333))] = ((int8_t*)compute)[(((((ax0402 * 8192) + (ax2333 * 1024)) + (ax1400 * 8)) + ax3333))];
        }
      }
    }
  }
  for (int32_t ax0403 = 0; ax0403 < 7; ++ax0403) {
    for (int32_t ax2334 = 0; ax2334 < 128; ++ax2334) {
      for (int32_t ax3334 = 0; ax3334 < 8; ++ax3334) {
        for (int32_t ax472 = 0; ax472 < 8; ++ax472) {
          ((int8_t*)compute)[(((((ax0403 * 8192) + (ax2334 * 64)) + (ax3334 * 8)) + ax472))] = ((int8_t*)T_reshape1)[(((((ax0403 * 8192) + (ax2334 * 64)) + (ax3334 * 8)) + ax472))];
        }
      }
    }
  }
  (void)load(compute, (int64_t)536870912, 7168, 0);
  for (int32_t ax0404 = 0; ax0404 < 512; ++ax0404) {
    for (int32_t ax1401 = 0; ax1401 < 1024; ++ax1401) {
      ((int8_t*)compute)[(((ax0404 * 1024) + ax1401))] = ((int8_t*)kernel_592)[(((ax0404 * 1024) + ax1401))];
    }
  }
  for (int32_t ax0405 = 0; ax0405 < 64; ++ax0405) {
    for (int32_t ax1402 = 0; ax1402 < 8; ++ax1402) {
      for (int32_t ax2335 = 0; ax2335 < 128; ++ax2335) {
        for (int32_t ax3335 = 0; ax3335 < 8; ++ax3335) {
          ((int8_t*)compute1)[(((((ax0405 * 8192) + (ax1402 * 1024)) + (ax2335 * 8)) + ax3335))] = ((int8_t*)compute)[(((((ax0405 * 8192) + (ax1402 * 1024)) + (ax2335 * 8)) + ax3335))];
        }
      }
    }
  }
  for (int32_t ax0406 = 0; ax0406 < 64; ++ax0406) {
    for (int32_t ax1403 = 0; ax1403 < 128; ++ax1403) {
      for (int32_t ax2336 = 0; ax2336 < 8; ++ax2336) {
        for (int32_t ax3336 = 0; ax3336 < 8; ++ax3336) {
          ((int8_t*)compute)[(((((ax0406 * 8192) + (ax1403 * 64)) + (ax2336 * 8)) + ax3336))] = ((int8_t*)compute1)[(((((ax0406 * 8192) + (ax2336 * 1024)) + (ax1403 * 8)) + ax3336))];
        }
      }
    }
  }
  for (int32_t ax0407 = 0; ax0407 < 64; ++ax0407) {
    for (int32_t ax2337 = 0; ax2337 < 128; ++ax2337) {
      for (int32_t ax3337 = 0; ax3337 < 8; ++ax3337) {
        for (int32_t ax473 = 0; ax473 < 8; ++ax473) {
          ((int8_t*)compute1)[(((((ax0407 * 8192) + (ax2337 * 64)) + (ax3337 * 8)) + ax473))] = ((int8_t*)compute)[(((((ax0407 * 8192) + (ax2337 * 64)) + (ax3337 * 8)) + ax473))];
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536936448, 65536, 0);
  for (int32_t i73 = 0; i73 < 7; ++i73) {
    for (int32_t x42 = 0; x42 < 64; ++x42) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i73 * 512) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x42 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i73 * 16384) + (x42 * 256)));
    }
  }
  for (int32_t ax0408 = 0; ax0408 < 7; ++ax0408) {
    for (int32_t ax1404 = 0; ax1404 < 8; ++ax1404) {
      for (int32_t ax2338 = 0; ax2338 < 64; ++ax2338) {
        for (int32_t ax3338 = 0; ax3338 < 8; ++ax3338) {
          ((int32_t*)compute1)[(((((ax0408 * 4096) + (ax1404 * 512)) + (ax2338 * 8)) + ax3338))] = ((int32_t*)compute)[(((((ax0408 * 4096) + (ax2338 * 64)) + (ax1404 * 8)) + ax3338))];
        }
      }
    }
  }
  for (int32_t ax0409 = 0; ax0409 < 49; ++ax0409) {
    for (int32_t ax1405 = 0; ax1405 < 512; ++ax1405) {
      ((int32_t*)T_reshape1)[(((ax0409 * 512) + ax1405))] = ((int32_t*)compute1)[(((ax0409 * 512) + ax1405))];
    }
  }
  for (int32_t i074 = 0; i074 < 49; ++i074) {
    for (int32_t i1270 = 0; i1270 < 512; ++i1270) {
      ((int32_t*)compute)[(((i074 * 512) + i1270))] = ((int32_t*)T_reshape1)[(((i074 * 512) + i1270))];
    }
  }
  for (int32_t ax1406 = 0; ax1406 < 7; ++ax1406) {
    for (int32_t ax2339 = 0; ax2339 < 7; ++ax2339) {
      for (int32_t ax3339 = 0; ax3339 < 512; ++ax3339) {
        ((int32_t*)T_reshape1)[((((ax1406 * 3584) + (ax2339 * 512)) + ax3339))] = ((int32_t*)compute)[((((ax1406 * 3584) + (ax2339 * 512)) + ax3339))];
      }
    }
  }
  for (int32_t h528 = 0; h528 < 7; ++h528) {
    for (int32_t w261 = 0; w261 < 7; ++w261) {
      for (int32_t c301 = 0; c301 < 512; ++c301) {
        ((int32_t*)compute)[((((h528 * 3584) + (w261 * 512)) + c301))] = 18;
      }
    }
  }
  for (int32_t h529 = 0; h529 < 7; ++h529) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h529 * 3584));
    (void)load(compute, (int64_t)537329664, 1792, (h529 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(out2, (int64_t)537395200, 1792, (h529 * 14336));
  }
  for (int32_t h530 = 0; h530 < 7; ++h530) {
    for (int32_t w262 = 0; w262 < 7; ++w262) {
      for (int32_t c302 = 0; c302 < 512; ++c302) {
        ((int32_t*)T_reshape1)[((((h530 * 3584) + (w262 * 512)) + c302))] = ((int32_t*)tensor_594)[(c302)];
      }
    }
  }
  for (int32_t h531 = 0; h531 < 7; ++h531) {
    (void)load(out2, (int64_t)537264128, 1792, (h531 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h531 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h531 * 14336));
  }
  for (int32_t h532 = 0; h532 < 7; ++h532) {
    for (int32_t w263 = 0; w263 < 7; ++w263) {
      for (int32_t c303 = 0; c303 < 512; ++c303) {
        ((int32_t*)out2)[((((h532 * 3584) + (w263 * 512)) + c303))] = ((int32_t*)tensor_595)[(c303)];
      }
    }
  }
  for (int32_t h533 = 0; h533 < 7; ++h533) {
    (void)load(compute, (int64_t)537264128, 1792, (h533 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h533 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape1, (int64_t)537395200, 1792, (h533 * 14336));
  }
  for (int32_t h534 = 0; h534 < 7; ++h534) {
    for (int32_t w264 = 0; w264 < 7; ++w264) {
      for (int32_t c304 = 0; c304 < 512; ++c304) {
        ((int32_t*)out2)[((((h534 * 3584) + (w264 * 512)) + c304))] = 0;
      }
    }
  }
  for (int32_t h535 = 0; h535 < 7; ++h535) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h535 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h535 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h535 * 14336));
  }
  for (int32_t h536 = 0; h536 < 7; ++h536) {
    for (int32_t w265 = 0; w265 < 7; ++w265) {
      for (int32_t c305 = 0; c305 < 512; ++c305) {
        ((int32_t*)out2)[((((h536 * 3584) + (w265 * 512)) + c305))] = 33554432;
      }
    }
  }
  for (int32_t h537 = 0; h537 < 7; ++h537) {
    (void)load(compute, (int64_t)537264128, 1792, (h537 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h537 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape1, (int64_t)537395200, 1792, (h537 * 14336));
  }
  for (int32_t h538 = 0; h538 < 7; ++h538) {
    for (int32_t w266 = 0; w266 < 7; ++w266) {
      for (int32_t c306 = 0; c306 < 512; ++c306) {
        ((int32_t*)out2)[((((h538 * 3584) + (w266 * 512)) + c306))] = 26;
      }
    }
  }
  for (int32_t h539 = 0; h539 < 7; ++h539) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h539 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h539 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h539 * 14336));
  }
  for (int32_t i1271 = 0; i1271 < 7; ++i1271) {
    for (int32_t i2196 = 0; i2196 < 7; ++i2196) {
      for (int32_t i3196 = 0; i3196 < 512; ++i3196) {
        int32_t _146 = ((int32_t*)compute)[((((i1271 * 3584) + (i2196 * 512)) + i3196))];
        int32_t _147 = (_146) < (127) ? (_146) : (127);
        ((int32_t*)out2)[((((i1271 * 3584) + (i2196 * 512)) + i3196))] = ((_147) > (-127) ? (_147) : (-127));
      }
    }
  }
  for (int32_t i1272 = 0; i1272 < 7; ++i1272) {
    for (int32_t i2197 = 0; i2197 < 7; ++i2197) {
      for (int32_t i3197 = 0; i3197 < 512; ++i3197) {
        ((int8_t*)T_reshape1)[((((i1272 * 3584) + (i2197 * 512)) + i3197))] = ((int8_t)((int32_t*)out2)[((((i1272 * 3584) + (i2197 * 512)) + i3197))]);
      }
    }
  }
  for (int32_t i1273 = 0; i1273 < 9; ++i1273) {
    for (int32_t i2198 = 0; i2198 < 9; ++i2198) {
      for (int32_t i3198 = 0; i3198 < 512; ++i3198) {
        ((int8_t*)out2)[((((i1273 * 4608) + (i2198 * 512)) + i3198))] = (((((1 <= i1273) && (i1273 < 8)) && (1 <= i2198)) && (i2198 < 8)) ? ((int8_t*)T_reshape1)[(((((i1273 * 3584) + (i2198 * 512)) + i3198) - 4096))] : (int8_t)0);
      }
    }
  }
  for (int32_t o139 = 0; o139 < 7; ++o139) {
    for (int32_t o239 = 0; o239 < 7; ++o239) {
      for (int32_t k113 = 0; k113 < 3; ++k113) {
        for (int32_t k213 = 0; k213 < 3; ++k213) {
          for (int32_t c307 = 0; c307 < 512; ++c307) {
            ((int8_t*)compute)[((((((o139 * 32256) + (o239 * 4608)) + (k113 * 1536)) + (k213 * 512)) + c307))] = ((int8_t*)out2)[((((((k113 * 4608) + (o139 * 4608)) + (k213 * 512)) + (o239 * 512)) + c307))];
          }
        }
      }
    }
  }
  for (int32_t ax0410 = 0; ax0410 < 49; ++ax0410) {
    for (int32_t ax1407 = 0; ax1407 < 4608; ++ax1407) {
      ((int8_t*)compute1)[(((ax0410 * 4608) + ax1407))] = ((int8_t*)compute)[(((ax0410 * 4608) + ax1407))];
    }
  }
  for (int32_t i075 = 0; i075 < 56; ++i075) {
    for (int32_t i1274 = 0; i1274 < 4608; ++i1274) {
      ((int8_t*)compute)[(((i075 * 4608) + i1274))] = ((i075 < 49) ? ((int8_t*)compute1)[(((i075 * 4608) + i1274))] : (int8_t)0);
    }
  }
  for (int32_t ax0411 = 0; ax0411 < 7; ++ax0411) {
    for (int32_t ax1408 = 0; ax1408 < 8; ++ax1408) {
      for (int32_t ax2340 = 0; ax2340 < 576; ++ax2340) {
        for (int32_t ax3340 = 0; ax3340 < 8; ++ax3340) {
          ((int8_t*)compute1)[(((((ax0411 * 36864) + (ax1408 * 4608)) + (ax2340 * 8)) + ax3340))] = ((int8_t*)compute)[(((((ax0411 * 36864) + (ax1408 * 4608)) + (ax2340 * 8)) + ax3340))];
        }
      }
    }
  }
  for (int32_t ax0412 = 0; ax0412 < 7; ++ax0412) {
    for (int32_t ax1409 = 0; ax1409 < 576; ++ax1409) {
      for (int32_t ax2341 = 0; ax2341 < 8; ++ax2341) {
        for (int32_t ax3341 = 0; ax3341 < 8; ++ax3341) {
          ((int8_t*)compute)[(((((ax0412 * 36864) + (ax1409 * 64)) + (ax2341 * 8)) + ax3341))] = ((int8_t*)compute1)[(((((ax0412 * 36864) + (ax2341 * 4608)) + (ax1409 * 8)) + ax3341))];
        }
      }
    }
  }
  for (int32_t ax0413 = 0; ax0413 < 7; ++ax0413) {
    for (int32_t ax1410 = 0; ax1410 < 8; ++ax1410) {
      for (int32_t ax2342 = 0; ax2342 < 72; ++ax2342) {
        for (int32_t ax3342 = 0; ax3342 < 8; ++ax3342) {
          for (int32_t ax474 = 0; ax474 < 8; ++ax474) {
            ((int8_t*)compute1)[((((((ax0413 * 36864) + (ax1410 * 4608)) + (ax2342 * 64)) + (ax3342 * 8)) + ax474))] = ((int8_t*)compute)[((((((ax0413 * 36864) + (ax1410 * 4608)) + (ax2342 * 64)) + (ax3342 * 8)) + ax474))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 32256, 0);
  for (int32_t ax0414 = 0; ax0414 < 512; ++ax0414) {
    for (int32_t ax1411 = 0; ax1411 < 4608; ++ax1411) {
      ((int8_t*)out1)[(((ax0414 * 4608) + ax1411))] = ((int8_t*)kernel_602)[(((ax0414 * 4608) + ax1411))];
    }
  }
  for (int32_t ax0415 = 0; ax0415 < 64; ++ax0415) {
    for (int32_t ax1412 = 0; ax1412 < 8; ++ax1412) {
      for (int32_t ax2343 = 0; ax2343 < 576; ++ax2343) {
        for (int32_t ax3343 = 0; ax3343 < 8; ++ax3343) {
          ((int8_t*)out)[(((((ax0415 * 36864) + (ax1412 * 4608)) + (ax2343 * 8)) + ax3343))] = ((int8_t*)out1)[(((((ax0415 * 36864) + (ax1412 * 4608)) + (ax2343 * 8)) + ax3343))];
        }
      }
    }
  }
  for (int32_t ax0416 = 0; ax0416 < 64; ++ax0416) {
    for (int32_t ax1413 = 0; ax1413 < 576; ++ax1413) {
      for (int32_t ax2344 = 0; ax2344 < 8; ++ax2344) {
        for (int32_t ax3344 = 0; ax3344 < 8; ++ax3344) {
          ((int8_t*)pad_data)[(((((ax0416 * 36864) + (ax1413 * 64)) + (ax2344 * 8)) + ax3344))] = ((int8_t*)out)[(((((ax0416 * 36864) + (ax2344 * 4608)) + (ax1413 * 8)) + ax3344))];
        }
      }
    }
  }
  for (int32_t ax0417 = 0; ax0417 < 64; ++ax0417) {
    for (int32_t ax1414 = 0; ax1414 < 8; ++ax1414) {
      for (int32_t ax2345 = 0; ax2345 < 72; ++ax2345) {
        for (int32_t ax3345 = 0; ax3345 < 8; ++ax3345) {
          for (int32_t ax475 = 0; ax475 < 8; ++ax475) {
            ((int8_t*)out1)[((((((ax0417 * 36864) + (ax1414 * 4608)) + (ax2345 * 64)) + (ax3345 * 8)) + ax475))] = ((int8_t*)pad_data)[((((((ax0417 * 36864) + (ax1414 * 4608)) + (ax2345 * 64)) + (ax3345 * 8)) + ax475))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 294912, 0);
  for (int32_t i74 = 0; i74 < 7; ++i74) {
    for (int32_t x43 = 0; x43 < 64; ++x43) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k010 = 0; k010 < 8; ++k010) {
        (void)move(((((int64_t)((i74 * 2304) + (k010 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x43 * 2304) + (k010 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(compute, (int64_t)537264128, 32, ((i74 * 16384) + (x43 * 256)));
    }
  }
  for (int32_t ax0418 = 0; ax0418 < 7; ++ax0418) {
    for (int32_t ax1415 = 0; ax1415 < 8; ++ax1415) {
      for (int32_t ax2346 = 0; ax2346 < 64; ++ax2346) {
        for (int32_t ax3346 = 0; ax3346 < 8; ++ax3346) {
          ((int32_t*)compute1)[(((((ax0418 * 4096) + (ax1415 * 512)) + (ax2346 * 8)) + ax3346))] = ((int32_t*)compute)[(((((ax0418 * 4096) + (ax2346 * 64)) + (ax1415 * 8)) + ax3346))];
        }
      }
    }
  }
  for (int32_t ax0419 = 0; ax0419 < 49; ++ax0419) {
    for (int32_t ax1416 = 0; ax1416 < 512; ++ax1416) {
      ((int32_t*)out2)[(((ax0419 * 512) + ax1416))] = ((int32_t*)compute1)[(((ax0419 * 512) + ax1416))];
    }
  }
  for (int32_t ax1417 = 0; ax1417 < 7; ++ax1417) {
    for (int32_t ax2347 = 0; ax2347 < 7; ++ax2347) {
      for (int32_t ax3347 = 0; ax3347 < 512; ++ax3347) {
        ((int32_t*)T_reshape1)[((((ax1417 * 3584) + (ax2347 * 512)) + ax3347))] = ((int32_t*)out2)[((((ax1417 * 3584) + (ax2347 * 512)) + ax3347))];
      }
    }
  }
  for (int32_t h540 = 0; h540 < 7; ++h540) {
    for (int32_t w267 = 0; w267 < 7; ++w267) {
      for (int32_t c308 = 0; c308 < 512; ++c308) {
        ((int32_t*)out2)[((((h540 * 3584) + (w267 * 512)) + c308))] = ((int32_t*)tensor_603)[(c308)];
      }
    }
  }
  for (int32_t h541 = 0; h541 < 7; ++h541) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h541 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h541 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h541 * 14336));
  }
  for (int32_t h542 = 0; h542 < 7; ++h542) {
    for (int32_t w268 = 0; w268 < 7; ++w268) {
      for (int32_t c309 = 0; c309 < 512; ++c309) {
        ((int32_t*)out2)[((((h542 * 3584) + (w268 * 512)) + c309))] = 0;
      }
    }
  }
  for (int32_t h543 = 0; h543 < 7; ++h543) {
    (void)load(compute, (int64_t)537264128, 1792, (h543 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h543 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape1, (int64_t)537395200, 1792, (h543 * 14336));
  }
  for (int32_t h544 = 0; h544 < 7; ++h544) {
    for (int32_t w269 = 0; w269 < 7; ++w269) {
      for (int32_t c310 = 0; c310 < 512; ++c310) {
        ((int32_t*)out2)[((((h544 * 3584) + (w269 * 512)) + c310))] = 64;
      }
    }
  }
  for (int32_t h545 = 0; h545 < 7; ++h545) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h545 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h545 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h545 * 14336));
  }
  for (int32_t h546 = 0; h546 < 7; ++h546) {
    for (int32_t w270 = 0; w270 < 7; ++w270) {
      for (int32_t c311 = 0; c311 < 512; ++c311) {
        ((int32_t*)out2)[((((h546 * 3584) + (w270 * 512)) + c311))] = 7;
      }
    }
  }
  for (int32_t h547 = 0; h547 < 7; ++h547) {
    (void)load(compute, (int64_t)537264128, 1792, (h547 * 3584));
    (void)load(out2, (int64_t)537329664, 1792, (h547 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape1, (int64_t)537395200, 1792, (h547 * 14336));
  }
  for (int32_t i1275 = 0; i1275 < 7; ++i1275) {
    for (int32_t i2199 = 0; i2199 < 7; ++i2199) {
      for (int32_t i3199 = 0; i3199 < 512; ++i3199) {
        int32_t _148 = ((int32_t*)T_reshape1)[((((i1275 * 3584) + (i2199 * 512)) + i3199))];
        int32_t _149 = (_148) < (127) ? (_148) : (127);
        ((int32_t*)out2)[((((i1275 * 3584) + (i2199 * 512)) + i3199))] = ((_149) > (-127) ? (_149) : (-127));
      }
    }
  }
  for (int32_t i1276 = 0; i1276 < 7; ++i1276) {
    for (int32_t i2200 = 0; i2200 < 7; ++i2200) {
      for (int32_t i3200 = 0; i3200 < 512; ++i3200) {
        ((int8_t*)T_reshape1)[((((i1276 * 3584) + (i2200 * 512)) + i3200))] = ((int8_t)((int32_t*)out2)[((((i1276 * 3584) + (i2200 * 512)) + i3200))]);
      }
    }
  }
  for (int32_t o140 = 0; o140 < 7; ++o140) {
    for (int32_t o240 = 0; o240 < 7; ++o240) {
      for (int32_t c312 = 0; c312 < 512; ++c312) {
        ((int8_t*)out2)[((((o140 * 3584) + (o240 * 512)) + c312))] = ((int8_t*)T_reshape1)[((((o140 * 3584) + (o240 * 512)) + c312))];
      }
    }
  }
  for (int32_t ax0420 = 0; ax0420 < 49; ++ax0420) {
    for (int32_t ax1418 = 0; ax1418 < 512; ++ax1418) {
      ((int8_t*)T_reshape1)[(((ax0420 * 512) + ax1418))] = ((int8_t*)out2)[(((ax0420 * 512) + ax1418))];
    }
  }
  for (int32_t i076 = 0; i076 < 56; ++i076) {
    for (int32_t i1277 = 0; i1277 < 512; ++i1277) {
      ((int8_t*)out2)[(((i076 * 512) + i1277))] = ((i076 < 49) ? ((int8_t*)T_reshape1)[(((i076 * 512) + i1277))] : (int8_t)0);
    }
  }
  for (int32_t ax0421 = 0; ax0421 < 7; ++ax0421) {
    for (int32_t ax1419 = 0; ax1419 < 8; ++ax1419) {
      for (int32_t ax2348 = 0; ax2348 < 64; ++ax2348) {
        for (int32_t ax3348 = 0; ax3348 < 8; ++ax3348) {
          ((int8_t*)T_reshape1)[(((((ax0421 * 4096) + (ax1419 * 512)) + (ax2348 * 8)) + ax3348))] = ((int8_t*)out2)[(((((ax0421 * 4096) + (ax1419 * 512)) + (ax2348 * 8)) + ax3348))];
        }
      }
    }
  }
  for (int32_t ax0422 = 0; ax0422 < 7; ++ax0422) {
    for (int32_t ax1420 = 0; ax1420 < 64; ++ax1420) {
      for (int32_t ax2349 = 0; ax2349 < 8; ++ax2349) {
        for (int32_t ax3349 = 0; ax3349 < 8; ++ax3349) {
          ((int8_t*)out2)[(((((ax0422 * 4096) + (ax1420 * 64)) + (ax2349 * 8)) + ax3349))] = ((int8_t*)T_reshape1)[(((((ax0422 * 4096) + (ax2349 * 512)) + (ax1420 * 8)) + ax3349))];
        }
      }
    }
  }
  for (int32_t ax0423 = 0; ax0423 < 7; ++ax0423) {
    for (int32_t ax2350 = 0; ax2350 < 64; ++ax2350) {
      for (int32_t ax3350 = 0; ax3350 < 8; ++ax3350) {
        for (int32_t ax476 = 0; ax476 < 8; ++ax476) {
          ((int8_t*)T_reshape1)[(((((ax0423 * 4096) + (ax2350 * 64)) + (ax3350 * 8)) + ax476))] = ((int8_t*)out2)[(((((ax0423 * 4096) + (ax2350 * 64)) + (ax3350 * 8)) + ax476))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 3584, 0);
  for (int32_t ax0424 = 0; ax0424 < 2048; ++ax0424) {
    for (int32_t ax1421 = 0; ax1421 < 512; ++ax1421) {
      ((int8_t*)compute1)[(((ax0424 * 512) + ax1421))] = ((int8_t*)kernel_610)[(((ax0424 * 512) + ax1421))];
    }
  }
  for (int32_t ax0425 = 0; ax0425 < 256; ++ax0425) {
    for (int32_t ax1422 = 0; ax1422 < 8; ++ax1422) {
      for (int32_t ax2351 = 0; ax2351 < 64; ++ax2351) {
        for (int32_t ax3351 = 0; ax3351 < 8; ++ax3351) {
          ((int8_t*)out)[(((((ax0425 * 4096) + (ax1422 * 512)) + (ax2351 * 8)) + ax3351))] = ((int8_t*)compute1)[(((((ax0425 * 4096) + (ax1422 * 512)) + (ax2351 * 8)) + ax3351))];
        }
      }
    }
  }
  for (int32_t ax0426 = 0; ax0426 < 256; ++ax0426) {
    for (int32_t ax1423 = 0; ax1423 < 64; ++ax1423) {
      for (int32_t ax2352 = 0; ax2352 < 8; ++ax2352) {
        for (int32_t ax3352 = 0; ax3352 < 8; ++ax3352) {
          ((int8_t*)compute1)[(((((ax0426 * 4096) + (ax1423 * 64)) + (ax2352 * 8)) + ax3352))] = ((int8_t*)out)[(((((ax0426 * 4096) + (ax2352 * 512)) + (ax1423 * 8)) + ax3352))];
        }
      }
    }
  }
  for (int32_t ax0427 = 0; ax0427 < 256; ++ax0427) {
    for (int32_t ax2353 = 0; ax2353 < 64; ++ax2353) {
      for (int32_t ax3353 = 0; ax3353 < 8; ++ax3353) {
        for (int32_t ax477 = 0; ax477 < 8; ++ax477) {
          ((int8_t*)pad_data)[(((((ax0427 * 4096) + (ax2353 * 64)) + (ax3353 * 8)) + ax477))] = ((int8_t*)compute1)[(((((ax0427 * 4096) + (ax2353 * 64)) + (ax3353 * 8)) + ax477))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536936448, 131072, 0);
  for (int32_t i75 = 0; i75 < 7; ++i75) {
    for (int32_t x44 = 0; x44 < 256; ++x44) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i75 * 256) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x44 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i75 * 65536) + (x44 * 256)));
    }
  }
  for (int32_t ax0428 = 0; ax0428 < 7; ++ax0428) {
    for (int32_t ax1424 = 0; ax1424 < 8; ++ax1424) {
      for (int32_t ax2354 = 0; ax2354 < 256; ++ax2354) {
        for (int32_t ax3354 = 0; ax3354 < 8; ++ax3354) {
          ((int32_t*)compute1)[(((((ax0428 * 16384) + (ax1424 * 2048)) + (ax2354 * 8)) + ax3354))] = ((int32_t*)compute)[(((((ax0428 * 16384) + (ax2354 * 64)) + (ax1424 * 8)) + ax3354))];
        }
      }
    }
  }
  for (int32_t ax0429 = 0; ax0429 < 49; ++ax0429) {
    for (int32_t ax1425 = 0; ax1425 < 2048; ++ax1425) {
      ((int32_t*)compute)[(((ax0429 * 2048) + ax1425))] = ((int32_t*)compute1)[(((ax0429 * 2048) + ax1425))];
    }
  }
  for (int32_t i077 = 0; i077 < 49; ++i077) {
    for (int32_t i1278 = 0; i1278 < 2048; ++i1278) {
      ((int32_t*)compute1)[(((i077 * 2048) + i1278))] = ((int32_t*)compute)[(((i077 * 2048) + i1278))];
    }
  }
  for (int32_t ax1426 = 0; ax1426 < 7; ++ax1426) {
    for (int32_t ax2355 = 0; ax2355 < 7; ++ax2355) {
      for (int32_t ax3355 = 0; ax3355 < 2048; ++ax3355) {
        ((int32_t*)compute)[((((ax1426 * 14336) + (ax2355 * 2048)) + ax3355))] = ((int32_t*)compute1)[((((ax1426 * 14336) + (ax2355 * 2048)) + ax3355))];
      }
    }
  }
  for (int32_t h548 = 0; h548 < 7; ++h548) {
    for (int32_t w271 = 0; w271 < 7; ++w271) {
      for (int32_t c313 = 0; c313 < 2048; ++c313) {
        ((int32_t*)compute1)[((((h548 * 14336) + (w271 * 2048)) + c313))] = 17;
      }
    }
  }
  for (int32_t h549 = 0; h549 < 7; ++h549) {
    (void)load(compute, (int64_t)537264128, 7168, (h549 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h549 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h549 * 57344));
  }
  for (int32_t h550 = 0; h550 < 7; ++h550) {
    for (int32_t w272 = 0; w272 < 7; ++w272) {
      for (int32_t c314 = 0; c314 < 2048; ++c314) {
        ((int32_t*)compute)[((((h550 * 14336) + (w272 * 2048)) + c314))] = ((int32_t*)tensor_612)[(c314)];
      }
    }
  }
  for (int32_t h551 = 0; h551 < 7; ++h551) {
    (void)load(out1, (int64_t)537264128, 7168, (h551 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h551 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h551 * 57344));
  }
  for (int32_t h552 = 0; h552 < 7; ++h552) {
    for (int32_t w273 = 0; w273 < 7; ++w273) {
      for (int32_t c315 = 0; c315 < 2048; ++c315) {
        ((int32_t*)compute)[((((h552 * 14336) + (w273 * 2048)) + c315))] = 16777216;
      }
    }
  }
  for (int32_t h553 = 0; h553 < 7; ++h553) {
    (void)load(compute1, (int64_t)537264128, 7168, (h553 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h553 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h553 * 57344));
  }
  for (int32_t h554 = 0; h554 < 7; ++h554) {
    for (int32_t w274 = 0; w274 < 7; ++w274) {
      for (int32_t c316 = 0; c316 < 2048; ++c316) {
        ((int32_t*)compute)[((((h554 * 14336) + (w274 * 2048)) + c316))] = 25;
      }
    }
  }
  for (int32_t h555 = 0; h555 < 7; ++h555) {
    (void)load(out, (int64_t)537264128, 7168, (h555 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h555 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h555 * 57344));
  }
  for (int32_t i1279 = 0; i1279 < 7; ++i1279) {
    for (int32_t i2201 = 0; i2201 < 7; ++i2201) {
      for (int32_t i3201 = 0; i3201 < 2048; ++i3201) {
        int32_t _150 = ((int32_t*)compute1)[((((i1279 * 14336) + (i2201 * 2048)) + i3201))];
        int32_t _151 = (_150) < (127) ? (_150) : (127);
        ((int32_t*)compute)[((((i1279 * 14336) + (i2201 * 2048)) + i3201))] = ((_151) > (-127) ? (_151) : (-127));
      }
    }
  }
  for (int32_t i1280 = 0; i1280 < 7; ++i1280) {
    for (int32_t i2202 = 0; i2202 < 7; ++i2202) {
      for (int32_t i3202 = 0; i3202 < 2048; ++i3202) {
        ((int8_t*)out2)[((((i1280 * 14336) + (i2202 * 2048)) + i3202))] = ((int8_t)((int32_t*)compute)[((((i1280 * 14336) + (i2202 * 2048)) + i3202))]);
      }
    }
  }
  for (int32_t i1281 = 0; i1281 < 7; ++i1281) {
    for (int32_t i2203 = 0; i2203 < 7; ++i2203) {
      for (int32_t i3203 = 0; i3203 < 2048; ++i3203) {
        ((int32_t*)compute)[((((i1281 * 14336) + (i2203 * 2048)) + i3203))] = ((int32_t)((int8_t*)out2)[((((i1281 * 14336) + (i2203 * 2048)) + i3203))]);
      }
    }
  }
  for (int32_t h556 = 0; h556 < 7; ++h556) {
    for (int32_t w275 = 0; w275 < 7; ++w275) {
      for (int32_t c317 = 0; c317 < 2048; ++c317) {
        ((int32_t*)compute1)[((((h556 * 14336) + (w275 * 2048)) + c317))] = ((int32_t*)tensor_619)[(c317)];
      }
    }
  }
  for (int32_t h557 = 0; h557 < 7; ++h557) {
    (void)load(compute, (int64_t)537264128, 7168, (h557 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h557 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h557 * 57344));
  }
  for (int32_t h558 = 0; h558 < 7; ++h558) {
    for (int32_t w276 = 0; w276 < 7; ++w276) {
      for (int32_t c318 = 0; c318 < 2048; ++c318) {
        ((int32_t*)compute)[((((h558 * 14336) + (w276 * 2048)) + c318))] = ((int32_t*)tensor_620)[(c318)];
      }
    }
  }
  for (int32_t h559 = 0; h559 < 7; ++h559) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h559 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h559 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h559 * 57344));
  }
  for (int32_t h560 = 0; h560 < 7; ++h560) {
    for (int32_t w277 = 0; w277 < 7; ++w277) {
      for (int32_t c319 = 0; c319 < 2048; ++c319) {
        ((int32_t*)compute)[((((h560 * 14336) + (w277 * 2048)) + c319))] = 8;
      }
    }
  }
  for (int32_t h561 = 0; h561 < 7; ++h561) {
    (void)load(compute1, (int64_t)537264128, 7168, (h561 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h561 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h561 * 57344));
  }
  for (int32_t h562 = 0; h562 < 7; ++h562) {
    for (int32_t w278 = 0; w278 < 7; ++w278) {
      for (int32_t c320 = 0; c320 < 2048; ++c320) {
        ((int32_t*)compute)[((((h562 * 14336) + (w278 * 2048)) + c320))] = 4;
      }
    }
  }
  for (int32_t h563 = 0; h563 < 7; ++h563) {
    (void)load(out1, (int64_t)537264128, 7168, (h563 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h563 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h563 * 57344));
  }
  for (int32_t i1282 = 0; i1282 < 7; ++i1282) {
    for (int32_t i2204 = 0; i2204 < 7; ++i2204) {
      for (int32_t i3204 = 0; i3204 < 2048; ++i3204) {
        int32_t _152 = ((int32_t*)compute1)[((((i1282 * 14336) + (i2204 * 2048)) + i3204))];
        int32_t _153 = (_152) < (127) ? (_152) : (127);
        ((int32_t*)compute)[((((i1282 * 14336) + (i2204 * 2048)) + i3204))] = ((_153) > (-127) ? (_153) : (-127));
      }
    }
  }
  for (int32_t i1283 = 0; i1283 < 7; ++i1283) {
    for (int32_t i2205 = 0; i2205 < 7; ++i2205) {
      for (int32_t i3205 = 0; i3205 < 2048; ++i3205) {
        ((int8_t*)out2)[((((i1283 * 14336) + (i2205 * 2048)) + i3205))] = ((int8_t)((int32_t*)compute)[((((i1283 * 14336) + (i2205 * 2048)) + i3205))]);
      }
    }
  }
  for (int32_t i1284 = 0; i1284 < 7; ++i1284) {
    for (int32_t i2206 = 0; i2206 < 7; ++i2206) {
      for (int32_t i3206 = 0; i3206 < 2048; ++i3206) {
        ((int32_t*)compute)[((((i1284 * 14336) + (i2206 * 2048)) + i3206))] = ((int32_t)((int8_t*)out2)[((((i1284 * 14336) + (i2206 * 2048)) + i3206))]);
      }
    }
  }
  for (int32_t o141 = 0; o141 < 7; ++o141) {
    for (int32_t o241 = 0; o241 < 7; ++o241) {
      for (int32_t c321 = 0; c321 < 1024; ++c321) {
        ((int8_t*)out2)[((((o141 * 7168) + (o241 * 1024)) + c321))] = ((int8_t*)T_reshape)[((((o141 * 26624) + (o241 * 2048)) + c321))];
      }
    }
  }
  for (int32_t ax0430 = 0; ax0430 < 49; ++ax0430) {
    for (int32_t ax1427 = 0; ax1427 < 1024; ++ax1427) {
      ((int8_t*)T_reshape1)[(((ax0430 * 1024) + ax1427))] = ((int8_t*)out2)[(((ax0430 * 1024) + ax1427))];
    }
  }
  for (int32_t i078 = 0; i078 < 56; ++i078) {
    for (int32_t i1285 = 0; i1285 < 1024; ++i1285) {
      ((int8_t*)out2)[(((i078 * 1024) + i1285))] = ((i078 < 49) ? ((int8_t*)T_reshape1)[(((i078 * 1024) + i1285))] : (int8_t)0);
    }
  }
  for (int32_t ax0431 = 0; ax0431 < 7; ++ax0431) {
    for (int32_t ax1428 = 0; ax1428 < 8; ++ax1428) {
      for (int32_t ax2356 = 0; ax2356 < 128; ++ax2356) {
        for (int32_t ax3356 = 0; ax3356 < 8; ++ax3356) {
          ((int8_t*)T_reshape1)[(((((ax0431 * 8192) + (ax1428 * 1024)) + (ax2356 * 8)) + ax3356))] = ((int8_t*)out2)[(((((ax0431 * 8192) + (ax1428 * 1024)) + (ax2356 * 8)) + ax3356))];
        }
      }
    }
  }
  for (int32_t ax0432 = 0; ax0432 < 7; ++ax0432) {
    for (int32_t ax1429 = 0; ax1429 < 128; ++ax1429) {
      for (int32_t ax2357 = 0; ax2357 < 8; ++ax2357) {
        for (int32_t ax3357 = 0; ax3357 < 8; ++ax3357) {
          ((int8_t*)out2)[(((((ax0432 * 8192) + (ax1429 * 64)) + (ax2357 * 8)) + ax3357))] = ((int8_t*)T_reshape1)[(((((ax0432 * 8192) + (ax2357 * 1024)) + (ax1429 * 8)) + ax3357))];
        }
      }
    }
  }
  for (int32_t ax0433 = 0; ax0433 < 7; ++ax0433) {
    for (int32_t ax2358 = 0; ax2358 < 128; ++ax2358) {
      for (int32_t ax3358 = 0; ax3358 < 8; ++ax3358) {
        for (int32_t ax478 = 0; ax478 < 8; ++ax478) {
          ((int8_t*)T_reshape1)[(((((ax0433 * 8192) + (ax2358 * 64)) + (ax3358 * 8)) + ax478))] = ((int8_t*)out2)[(((((ax0433 * 8192) + (ax2358 * 64)) + (ax3358 * 8)) + ax478))];
        }
      }
    }
  }
  (void)load(T_reshape1, (int64_t)536870912, 7168, 0);
  for (int32_t ax0434 = 0; ax0434 < 2048; ++ax0434) {
    for (int32_t ax1430 = 0; ax1430 < 1024; ++ax1430) {
      ((int8_t*)out)[(((ax0434 * 1024) + ax1430))] = ((int8_t*)kernel_628)[(((ax0434 * 1024) + ax1430))];
    }
  }
  for (int32_t ax0435 = 0; ax0435 < 256; ++ax0435) {
    for (int32_t ax1431 = 0; ax1431 < 8; ++ax1431) {
      for (int32_t ax2359 = 0; ax2359 < 128; ++ax2359) {
        for (int32_t ax3359 = 0; ax3359 < 8; ++ax3359) {
          ((int8_t*)pad_data)[(((((ax0435 * 8192) + (ax1431 * 1024)) + (ax2359 * 8)) + ax3359))] = ((int8_t*)out)[(((((ax0435 * 8192) + (ax1431 * 1024)) + (ax2359 * 8)) + ax3359))];
        }
      }
    }
  }
  for (int32_t ax0436 = 0; ax0436 < 256; ++ax0436) {
    for (int32_t ax1432 = 0; ax1432 < 128; ++ax1432) {
      for (int32_t ax2360 = 0; ax2360 < 8; ++ax2360) {
        for (int32_t ax3360 = 0; ax3360 < 8; ++ax3360) {
          ((int8_t*)out1)[(((((ax0436 * 8192) + (ax1432 * 64)) + (ax2360 * 8)) + ax3360))] = ((int8_t*)pad_data)[(((((ax0436 * 8192) + (ax2360 * 1024)) + (ax1432 * 8)) + ax3360))];
        }
      }
    }
  }
  for (int32_t ax0437 = 0; ax0437 < 256; ++ax0437) {
    for (int32_t ax2361 = 0; ax2361 < 128; ++ax2361) {
      for (int32_t ax3361 = 0; ax3361 < 8; ++ax3361) {
        for (int32_t ax479 = 0; ax479 < 8; ++ax479) {
          ((int8_t*)out)[(((((ax0437 * 8192) + (ax2361 * 64)) + (ax3361 * 8)) + ax479))] = ((int8_t*)out1)[(((((ax0437 * 8192) + (ax2361 * 64)) + (ax3361 * 8)) + ax479))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 262144, 0);
  for (int32_t i76 = 0; i76 < 7; ++i76) {
    for (int32_t x45 = 0; x45 < 256; ++x45) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i76 * 512) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
      (void)move(((((int64_t)(x45 * 512)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      (void)store(compute1, (int64_t)537264128, 32, ((i76 * 65536) + (x45 * 256)));
    }
  }
  for (int32_t ax0438 = 0; ax0438 < 7; ++ax0438) {
    for (int32_t ax1433 = 0; ax1433 < 8; ++ax1433) {
      for (int32_t ax2362 = 0; ax2362 < 256; ++ax2362) {
        for (int32_t ax3362 = 0; ax3362 < 8; ++ax3362) {
          ((int32_t*)pad_data)[(((((ax0438 * 16384) + (ax1433 * 2048)) + (ax2362 * 8)) + ax3362))] = ((int32_t*)compute1)[(((((ax0438 * 16384) + (ax2362 * 64)) + (ax1433 * 8)) + ax3362))];
        }
      }
    }
  }
  for (int32_t ax0439 = 0; ax0439 < 49; ++ax0439) {
    for (int32_t ax1434 = 0; ax1434 < 2048; ++ax1434) {
      ((int32_t*)compute1)[(((ax0439 * 2048) + ax1434))] = ((int32_t*)pad_data)[(((ax0439 * 2048) + ax1434))];
    }
  }
  for (int32_t i079 = 0; i079 < 49; ++i079) {
    for (int32_t i1286 = 0; i1286 < 2048; ++i1286) {
      ((int32_t*)out1)[(((i079 * 2048) + i1286))] = ((int32_t*)compute1)[(((i079 * 2048) + i1286))];
    }
  }
  for (int32_t ax1435 = 0; ax1435 < 7; ++ax1435) {
    for (int32_t ax2363 = 0; ax2363 < 7; ++ax2363) {
      for (int32_t ax3363 = 0; ax3363 < 2048; ++ax3363) {
        ((int32_t*)compute1)[((((ax1435 * 14336) + (ax2363 * 2048)) + ax3363))] = ((int32_t*)out1)[((((ax1435 * 14336) + (ax2363 * 2048)) + ax3363))];
      }
    }
  }
  for (int32_t h564 = 0; h564 < 7; ++h564) {
    for (int32_t w279 = 0; w279 < 7; ++w279) {
      for (int32_t c322 = 0; c322 < 2048; ++c322) {
        ((int32_t*)out)[((((h564 * 14336) + (w279 * 2048)) + c322))] = ((int32_t*)tensor_629)[(c322)];
      }
    }
  }
  for (int32_t h565 = 0; h565 < 7; ++h565) {
    (void)load(compute1, (int64_t)537264128, 7168, (h565 * 14336));
    (void)load(out, (int64_t)537329664, 7168, (h565 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h565 * 57344));
  }
  for (int32_t h566 = 0; h566 < 7; ++h566) {
    for (int32_t w280 = 0; w280 < 7; ++w280) {
      for (int32_t c323 = 0; c323 < 2048; ++c323) {
        ((int32_t*)compute1)[((((h566 * 14336) + (w280 * 2048)) + c323))] = 64;
      }
    }
  }
  for (int32_t h567 = 0; h567 < 7; ++h567) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h567 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h567 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h567 * 57344));
  }
  for (int32_t h568 = 0; h568 < 7; ++h568) {
    for (int32_t w281 = 0; w281 < 7; ++w281) {
      for (int32_t c324 = 0; c324 < 2048; ++c324) {
        ((int32_t*)compute1)[((((h568 * 14336) + (w281 * 2048)) + c324))] = 7;
      }
    }
  }
  for (int32_t h569 = 0; h569 < 7; ++h569) {
    (void)load(out1, (int64_t)537264128, 7168, (h569 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h569 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h569 * 57344));
  }
  for (int32_t i1287 = 0; i1287 < 7; ++i1287) {
    for (int32_t i2207 = 0; i2207 < 7; ++i2207) {
      for (int32_t i3207 = 0; i3207 < 2048; ++i3207) {
        int32_t _154 = ((int32_t*)out)[((((i1287 * 14336) + (i2207 * 2048)) + i3207))];
        int32_t _155 = (_154) < (127) ? (_154) : (127);
        ((int32_t*)compute1)[((((i1287 * 14336) + (i2207 * 2048)) + i3207))] = ((_155) > (-127) ? (_155) : (-127));
      }
    }
  }
  for (int32_t i1288 = 0; i1288 < 7; ++i1288) {
    for (int32_t i2208 = 0; i2208 < 7; ++i2208) {
      for (int32_t i3208 = 0; i3208 < 2048; ++i3208) {
        ((int8_t*)out2)[((((i1288 * 14336) + (i2208 * 2048)) + i3208))] = ((int8_t)((int32_t*)compute1)[((((i1288 * 14336) + (i2208 * 2048)) + i3208))]);
      }
    }
  }
  for (int32_t i1289 = 0; i1289 < 7; ++i1289) {
    for (int32_t i2209 = 0; i2209 < 7; ++i2209) {
      for (int32_t i3209 = 0; i3209 < 2048; ++i3209) {
        ((int32_t*)compute1)[((((i1289 * 14336) + (i2209 * 2048)) + i3209))] = ((int32_t)((int8_t*)out2)[((((i1289 * 14336) + (i2209 * 2048)) + i3209))]);
      }
    }
  }
  for (int32_t h570 = 0; h570 < 7; ++h570) {
    (void)load(compute, (int64_t)537264128, 7168, (h570 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h570 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h570 * 57344));
  }
  for (int32_t h571 = 0; h571 < 7; ++h571) {
    for (int32_t w282 = 0; w282 < 7; ++w282) {
      for (int32_t c325 = 0; c325 < 2048; ++c325) {
        ((int32_t*)compute)[((((h571 * 14336) + (w282 * 2048)) + c325))] = 0;
      }
    }
  }
  for (int32_t h572 = 0; h572 < 7; ++h572) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h572 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h572 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h572 * 57344));
  }
  for (int32_t i1290 = 0; i1290 < 7; ++i1290) {
    for (int32_t i2210 = 0; i2210 < 7; ++i2210) {
      for (int32_t i3210 = 0; i3210 < 2048; ++i3210) {
        int32_t _156 = ((int32_t*)compute1)[((((i1290 * 14336) + (i2210 * 2048)) + i3210))];
        int32_t _157 = (_156) < (127) ? (_156) : (127);
        ((int32_t*)compute)[((((i1290 * 14336) + (i2210 * 2048)) + i3210))] = ((_157) > (-127) ? (_157) : (-127));
      }
    }
  }
  for (int32_t i1291 = 0; i1291 < 7; ++i1291) {
    for (int32_t i2211 = 0; i2211 < 7; ++i2211) {
      for (int32_t i3211 = 0; i3211 < 2048; ++i3211) {
        ((int8_t*)out2)[((((i1291 * 14336) + (i2211 * 2048)) + i3211))] = ((int8_t)((int32_t*)compute)[((((i1291 * 14336) + (i2211 * 2048)) + i3211))]);
      }
    }
  }
  for (int32_t o142 = 0; o142 < 7; ++o142) {
    for (int32_t o242 = 0; o242 < 7; ++o242) {
      for (int32_t c326 = 0; c326 < 2048; ++c326) {
        ((int8_t*)T_reshape1)[((((o142 * 14336) + (o242 * 2048)) + c326))] = ((int8_t*)out2)[((((o142 * 14336) + (o242 * 2048)) + c326))];
      }
    }
  }
  for (int32_t ax0440 = 0; ax0440 < 49; ++ax0440) {
    for (int32_t ax1436 = 0; ax1436 < 2048; ++ax1436) {
      ((int8_t*)T_reshape)[(((ax0440 * 2048) + ax1436))] = ((int8_t*)T_reshape1)[(((ax0440 * 2048) + ax1436))];
    }
  }
  for (int32_t i080 = 0; i080 < 56; ++i080) {
    for (int32_t i1292 = 0; i1292 < 2048; ++i1292) {
      ((int8_t*)compute)[(((i080 * 2048) + i1292))] = ((i080 < 49) ? ((int8_t*)T_reshape)[(((i080 * 2048) + i1292))] : (int8_t)0);
    }
  }
  for (int32_t ax0441 = 0; ax0441 < 7; ++ax0441) {
    for (int32_t ax1437 = 0; ax1437 < 8; ++ax1437) {
      for (int32_t ax2364 = 0; ax2364 < 256; ++ax2364) {
        for (int32_t ax3364 = 0; ax3364 < 8; ++ax3364) {
          ((int8_t*)T_reshape)[(((((ax0441 * 16384) + (ax1437 * 2048)) + (ax2364 * 8)) + ax3364))] = ((int8_t*)compute)[(((((ax0441 * 16384) + (ax1437 * 2048)) + (ax2364 * 8)) + ax3364))];
        }
      }
    }
  }
  for (int32_t ax0442 = 0; ax0442 < 7; ++ax0442) {
    for (int32_t ax1438 = 0; ax1438 < 256; ++ax1438) {
      for (int32_t ax2365 = 0; ax2365 < 8; ++ax2365) {
        for (int32_t ax3365 = 0; ax3365 < 8; ++ax3365) {
          ((int8_t*)compute)[(((((ax0442 * 16384) + (ax1438 * 64)) + (ax2365 * 8)) + ax3365))] = ((int8_t*)T_reshape)[(((((ax0442 * 16384) + (ax2365 * 2048)) + (ax1438 * 8)) + ax3365))];
        }
      }
    }
  }
  for (int32_t ax0443 = 0; ax0443 < 7; ++ax0443) {
    for (int32_t ax1439 = 0; ax1439 < 2; ++ax1439) {
      for (int32_t ax2366 = 0; ax2366 < 128; ++ax2366) {
        for (int32_t ax3366 = 0; ax3366 < 8; ++ax3366) {
          for (int32_t ax480 = 0; ax480 < 8; ++ax480) {
            ((int8_t*)T_reshape)[((((((ax0443 * 16384) + (ax1439 * 8192)) + (ax2366 * 64)) + (ax3366 * 8)) + ax480))] = ((int8_t*)compute)[((((((ax0443 * 16384) + (ax1439 * 8192)) + (ax2366 * 64)) + (ax3366 * 8)) + ax480))];
          }
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536870912, 14336, 0);
  for (int32_t ax0444 = 0; ax0444 < 512; ++ax0444) {
    for (int32_t ax1440 = 0; ax1440 < 2048; ++ax1440) {
      ((int8_t*)compute1)[(((ax0444 * 2048) + ax1440))] = ((int8_t*)kernel_642)[(((ax0444 * 2048) + ax1440))];
    }
  }
  for (int32_t ax0445 = 0; ax0445 < 64; ++ax0445) {
    for (int32_t ax1441 = 0; ax1441 < 8; ++ax1441) {
      for (int32_t ax2367 = 0; ax2367 < 256; ++ax2367) {
        for (int32_t ax3367 = 0; ax3367 < 8; ++ax3367) {
          ((int8_t*)out1)[(((((ax0445 * 16384) + (ax1441 * 2048)) + (ax2367 * 8)) + ax3367))] = ((int8_t*)compute1)[(((((ax0445 * 16384) + (ax1441 * 2048)) + (ax2367 * 8)) + ax3367))];
        }
      }
    }
  }
  for (int32_t ax0446 = 0; ax0446 < 64; ++ax0446) {
    for (int32_t ax1442 = 0; ax1442 < 256; ++ax1442) {
      for (int32_t ax2368 = 0; ax2368 < 8; ++ax2368) {
        for (int32_t ax3368 = 0; ax3368 < 8; ++ax3368) {
          ((int8_t*)compute1)[(((((ax0446 * 16384) + (ax1442 * 64)) + (ax2368 * 8)) + ax3368))] = ((int8_t*)out1)[(((((ax0446 * 16384) + (ax2368 * 2048)) + (ax1442 * 8)) + ax3368))];
        }
      }
    }
  }
  for (int32_t ax0447 = 0; ax0447 < 64; ++ax0447) {
    for (int32_t ax1443 = 0; ax1443 < 2; ++ax1443) {
      for (int32_t ax2369 = 0; ax2369 < 128; ++ax2369) {
        for (int32_t ax3369 = 0; ax3369 < 8; ++ax3369) {
          for (int32_t ax481 = 0; ax481 < 8; ++ax481) {
            ((int8_t*)out)[((((((ax0447 * 16384) + (ax1443 * 8192)) + (ax2369 * 64)) + (ax3369 * 8)) + ax481))] = ((int8_t*)compute1)[((((((ax0447 * 16384) + (ax1443 * 8192)) + (ax2369 * 64)) + (ax3369 * 8)) + ax481))];
          }
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 131072, 0);
  for (int32_t i77 = 0; i77 < 7; ++i77) {
    for (int32_t x46 = 0; x46 < 64; ++x46) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k011 = 0; k011 < 2; ++k011) {
        (void)move(((((int64_t)((i77 * 1024) + (k011 * 512))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
        (void)move(((((int64_t)((x46 * 1024) + (k011 * 512))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      }
      (void)store(T_reshape, (int64_t)537264128, 32, ((i77 * 16384) + (x46 * 256)));
    }
  }
  for (int32_t ax0448 = 0; ax0448 < 7; ++ax0448) {
    for (int32_t ax1444 = 0; ax1444 < 8; ++ax1444) {
      for (int32_t ax2370 = 0; ax2370 < 64; ++ax2370) {
        for (int32_t ax3370 = 0; ax3370 < 8; ++ax3370) {
          ((int32_t*)compute)[(((((ax0448 * 4096) + (ax1444 * 512)) + (ax2370 * 8)) + ax3370))] = ((int32_t*)T_reshape)[(((((ax0448 * 4096) + (ax2370 * 64)) + (ax1444 * 8)) + ax3370))];
        }
      }
    }
  }
  for (int32_t ax0449 = 0; ax0449 < 49; ++ax0449) {
    for (int32_t ax1445 = 0; ax1445 < 512; ++ax1445) {
      ((int32_t*)T_reshape1)[(((ax0449 * 512) + ax1445))] = ((int32_t*)compute)[(((ax0449 * 512) + ax1445))];
    }
  }
  for (int32_t i081 = 0; i081 < 49; ++i081) {
    for (int32_t i1293 = 0; i1293 < 512; ++i1293) {
      ((int32_t*)T_reshape)[(((i081 * 512) + i1293))] = ((int32_t*)T_reshape1)[(((i081 * 512) + i1293))];
    }
  }
  for (int32_t ax1446 = 0; ax1446 < 7; ++ax1446) {
    for (int32_t ax2371 = 0; ax2371 < 7; ++ax2371) {
      for (int32_t ax3371 = 0; ax3371 < 512; ++ax3371) {
        ((int32_t*)T_reshape1)[((((ax1446 * 3584) + (ax2371 * 512)) + ax3371))] = ((int32_t*)T_reshape)[((((ax1446 * 3584) + (ax2371 * 512)) + ax3371))];
      }
    }
  }
  for (int32_t h573 = 0; h573 < 7; ++h573) {
    for (int32_t w283 = 0; w283 < 7; ++w283) {
      for (int32_t c327 = 0; c327 < 512; ++c327) {
        ((int32_t*)T_reshape)[((((h573 * 3584) + (w283 * 512)) + c327))] = 18;
      }
    }
  }
  for (int32_t h574 = 0; h574 < 7; ++h574) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h574 * 3584));
    (void)load(T_reshape, (int64_t)537329664, 1792, (h574 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h574 * 14336));
  }
  for (int32_t h575 = 0; h575 < 7; ++h575) {
    for (int32_t w284 = 0; w284 < 7; ++w284) {
      for (int32_t c328 = 0; c328 < 512; ++c328) {
        ((int32_t*)T_reshape1)[((((h575 * 3584) + (w284 * 512)) + c328))] = ((int32_t*)tensor_644)[(c328)];
      }
    }
  }
  for (int32_t h576 = 0; h576 < 7; ++h576) {
    (void)load(compute, (int64_t)537264128, 1792, (h576 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h576 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h576 * 14336));
  }
  for (int32_t h577 = 0; h577 < 7; ++h577) {
    for (int32_t w285 = 0; w285 < 7; ++w285) {
      for (int32_t c329 = 0; c329 < 512; ++c329) {
        ((int32_t*)T_reshape1)[((((h577 * 3584) + (w285 * 512)) + c329))] = ((int32_t*)tensor_645)[(c329)];
      }
    }
  }
  for (int32_t h578 = 0; h578 < 7; ++h578) {
    (void)load(T_reshape, (int64_t)537264128, 1792, (h578 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h578 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h578 * 14336));
  }
  for (int32_t h579 = 0; h579 < 7; ++h579) {
    for (int32_t w286 = 0; w286 < 7; ++w286) {
      for (int32_t c330 = 0; c330 < 512; ++c330) {
        ((int32_t*)T_reshape1)[((((h579 * 3584) + (w286 * 512)) + c330))] = 0;
      }
    }
  }
  for (int32_t h580 = 0; h580 < 7; ++h580) {
    (void)load(compute, (int64_t)537264128, 1792, (h580 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h580 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h580 * 14336));
  }
  for (int32_t h581 = 0; h581 < 7; ++h581) {
    for (int32_t w287 = 0; w287 < 7; ++w287) {
      for (int32_t c331 = 0; c331 < 512; ++c331) {
        ((int32_t*)T_reshape1)[((((h581 * 3584) + (w287 * 512)) + c331))] = 16777216;
      }
    }
  }
  for (int32_t h582 = 0; h582 < 7; ++h582) {
    (void)load(T_reshape, (int64_t)537264128, 1792, (h582 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h582 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h582 * 14336));
  }
  for (int32_t h583 = 0; h583 < 7; ++h583) {
    for (int32_t w288 = 0; w288 < 7; ++w288) {
      for (int32_t c332 = 0; c332 < 512; ++c332) {
        ((int32_t*)T_reshape1)[((((h583 * 3584) + (w288 * 512)) + c332))] = 25;
      }
    }
  }
  for (int32_t h584 = 0; h584 < 7; ++h584) {
    (void)load(compute, (int64_t)537264128, 1792, (h584 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h584 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h584 * 14336));
  }
  for (int32_t i1294 = 0; i1294 < 7; ++i1294) {
    for (int32_t i2212 = 0; i2212 < 7; ++i2212) {
      for (int32_t i3212 = 0; i3212 < 512; ++i3212) {
        int32_t _158 = ((int32_t*)T_reshape)[((((i1294 * 3584) + (i2212 * 512)) + i3212))];
        int32_t _159 = (_158) < (127) ? (_158) : (127);
        ((int32_t*)T_reshape1)[((((i1294 * 3584) + (i2212 * 512)) + i3212))] = ((_159) > (-127) ? (_159) : (-127));
      }
    }
  }
  for (int32_t i1295 = 0; i1295 < 7; ++i1295) {
    for (int32_t i2213 = 0; i2213 < 7; ++i2213) {
      for (int32_t i3213 = 0; i3213 < 512; ++i3213) {
        ((int8_t*)T_reshape)[((((i1295 * 3584) + (i2213 * 512)) + i3213))] = ((int8_t)((int32_t*)T_reshape1)[((((i1295 * 3584) + (i2213 * 512)) + i3213))]);
      }
    }
  }
  for (int32_t i1296 = 0; i1296 < 9; ++i1296) {
    for (int32_t i2214 = 0; i2214 < 9; ++i2214) {
      for (int32_t i3214 = 0; i3214 < 512; ++i3214) {
        ((int8_t*)T_reshape1)[((((i1296 * 4608) + (i2214 * 512)) + i3214))] = (((((1 <= i1296) && (i1296 < 8)) && (1 <= i2214)) && (i2214 < 8)) ? ((int8_t*)T_reshape)[(((((i1296 * 3584) + (i2214 * 512)) + i3214) - 4096))] : (int8_t)0);
      }
    }
  }
  for (int32_t o143 = 0; o143 < 7; ++o143) {
    for (int32_t o243 = 0; o243 < 7; ++o243) {
      for (int32_t k114 = 0; k114 < 3; ++k114) {
        for (int32_t k214 = 0; k214 < 3; ++k214) {
          for (int32_t c333 = 0; c333 < 512; ++c333) {
            ((int8_t*)compute)[((((((o143 * 32256) + (o243 * 4608)) + (k114 * 1536)) + (k214 * 512)) + c333))] = ((int8_t*)T_reshape1)[((((((k114 * 4608) + (o143 * 4608)) + (k214 * 512)) + (o243 * 512)) + c333))];
          }
        }
      }
    }
  }
  for (int32_t ax0450 = 0; ax0450 < 49; ++ax0450) {
    for (int32_t ax1447 = 0; ax1447 < 4608; ++ax1447) {
      ((int8_t*)compute1)[(((ax0450 * 4608) + ax1447))] = ((int8_t*)compute)[(((ax0450 * 4608) + ax1447))];
    }
  }
  for (int32_t i082 = 0; i082 < 56; ++i082) {
    for (int32_t i1297 = 0; i1297 < 4608; ++i1297) {
      ((int8_t*)compute)[(((i082 * 4608) + i1297))] = ((i082 < 49) ? ((int8_t*)compute1)[(((i082 * 4608) + i1297))] : (int8_t)0);
    }
  }
  for (int32_t ax0451 = 0; ax0451 < 7; ++ax0451) {
    for (int32_t ax1448 = 0; ax1448 < 8; ++ax1448) {
      for (int32_t ax2372 = 0; ax2372 < 576; ++ax2372) {
        for (int32_t ax3372 = 0; ax3372 < 8; ++ax3372) {
          ((int8_t*)compute1)[(((((ax0451 * 36864) + (ax1448 * 4608)) + (ax2372 * 8)) + ax3372))] = ((int8_t*)compute)[(((((ax0451 * 36864) + (ax1448 * 4608)) + (ax2372 * 8)) + ax3372))];
        }
      }
    }
  }
  for (int32_t ax0452 = 0; ax0452 < 7; ++ax0452) {
    for (int32_t ax1449 = 0; ax1449 < 576; ++ax1449) {
      for (int32_t ax2373 = 0; ax2373 < 8; ++ax2373) {
        for (int32_t ax3373 = 0; ax3373 < 8; ++ax3373) {
          ((int8_t*)compute)[(((((ax0452 * 36864) + (ax1449 * 64)) + (ax2373 * 8)) + ax3373))] = ((int8_t*)compute1)[(((((ax0452 * 36864) + (ax2373 * 4608)) + (ax1449 * 8)) + ax3373))];
        }
      }
    }
  }
  for (int32_t ax0453 = 0; ax0453 < 7; ++ax0453) {
    for (int32_t ax1450 = 0; ax1450 < 8; ++ax1450) {
      for (int32_t ax2374 = 0; ax2374 < 72; ++ax2374) {
        for (int32_t ax3374 = 0; ax3374 < 8; ++ax3374) {
          for (int32_t ax482 = 0; ax482 < 8; ++ax482) {
            ((int8_t*)compute1)[((((((ax0453 * 36864) + (ax1450 * 4608)) + (ax2374 * 64)) + (ax3374 * 8)) + ax482))] = ((int8_t*)compute)[((((((ax0453 * 36864) + (ax1450 * 4608)) + (ax2374 * 64)) + (ax3374 * 8)) + ax482))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 32256, 0);
  for (int32_t ax0454 = 0; ax0454 < 512; ++ax0454) {
    for (int32_t ax1451 = 0; ax1451 < 4608; ++ax1451) {
      ((int8_t*)pad_data)[(((ax0454 * 4608) + ax1451))] = ((int8_t*)kernel_652)[(((ax0454 * 4608) + ax1451))];
    }
  }
  for (int32_t ax0455 = 0; ax0455 < 64; ++ax0455) {
    for (int32_t ax1452 = 0; ax1452 < 8; ++ax1452) {
      for (int32_t ax2375 = 0; ax2375 < 576; ++ax2375) {
        for (int32_t ax3375 = 0; ax3375 < 8; ++ax3375) {
          ((int8_t*)out1)[(((((ax0455 * 36864) + (ax1452 * 4608)) + (ax2375 * 8)) + ax3375))] = ((int8_t*)pad_data)[(((((ax0455 * 36864) + (ax1452 * 4608)) + (ax2375 * 8)) + ax3375))];
        }
      }
    }
  }
  for (int32_t ax0456 = 0; ax0456 < 64; ++ax0456) {
    for (int32_t ax1453 = 0; ax1453 < 576; ++ax1453) {
      for (int32_t ax2376 = 0; ax2376 < 8; ++ax2376) {
        for (int32_t ax3376 = 0; ax3376 < 8; ++ax3376) {
          ((int8_t*)out)[(((((ax0456 * 36864) + (ax1453 * 64)) + (ax2376 * 8)) + ax3376))] = ((int8_t*)out1)[(((((ax0456 * 36864) + (ax2376 * 4608)) + (ax1453 * 8)) + ax3376))];
        }
      }
    }
  }
  for (int32_t ax0457 = 0; ax0457 < 64; ++ax0457) {
    for (int32_t ax1454 = 0; ax1454 < 8; ++ax1454) {
      for (int32_t ax2377 = 0; ax2377 < 72; ++ax2377) {
        for (int32_t ax3377 = 0; ax3377 < 8; ++ax3377) {
          for (int32_t ax483 = 0; ax483 < 8; ++ax483) {
            ((int8_t*)pad_data)[((((((ax0457 * 36864) + (ax1454 * 4608)) + (ax2377 * 64)) + (ax3377 * 8)) + ax483))] = ((int8_t*)out)[((((((ax0457 * 36864) + (ax1454 * 4608)) + (ax2377 * 64)) + (ax3377 * 8)) + ax483))];
          }
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536936448, 294912, 0);
  for (int32_t i78 = 0; i78 < 7; ++i78) {
    for (int32_t x47 = 0; x47 < 64; ++x47) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k012 = 0; k012 < 8; ++k012) {
        (void)move(((((int64_t)((i78 * 2304) + (k012 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x47 * 2304) + (k012 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(T_reshape, (int64_t)537264128, 32, ((i78 * 16384) + (x47 * 256)));
    }
  }
  for (int32_t ax0458 = 0; ax0458 < 7; ++ax0458) {
    for (int32_t ax1455 = 0; ax1455 < 8; ++ax1455) {
      for (int32_t ax2378 = 0; ax2378 < 64; ++ax2378) {
        for (int32_t ax3378 = 0; ax3378 < 8; ++ax3378) {
          ((int32_t*)compute)[(((((ax0458 * 4096) + (ax1455 * 512)) + (ax2378 * 8)) + ax3378))] = ((int32_t*)T_reshape)[(((((ax0458 * 4096) + (ax2378 * 64)) + (ax1455 * 8)) + ax3378))];
        }
      }
    }
  }
  for (int32_t ax0459 = 0; ax0459 < 49; ++ax0459) {
    for (int32_t ax1456 = 0; ax1456 < 512; ++ax1456) {
      ((int32_t*)T_reshape1)[(((ax0459 * 512) + ax1456))] = ((int32_t*)compute)[(((ax0459 * 512) + ax1456))];
    }
  }
  for (int32_t i083 = 0; i083 < 49; ++i083) {
    for (int32_t i1298 = 0; i1298 < 512; ++i1298) {
      ((int32_t*)T_reshape)[(((i083 * 512) + i1298))] = ((int32_t*)T_reshape1)[(((i083 * 512) + i1298))];
    }
  }
  for (int32_t ax1457 = 0; ax1457 < 7; ++ax1457) {
    for (int32_t ax2379 = 0; ax2379 < 7; ++ax2379) {
      for (int32_t ax3379 = 0; ax3379 < 512; ++ax3379) {
        ((int32_t*)T_reshape1)[((((ax1457 * 3584) + (ax2379 * 512)) + ax3379))] = ((int32_t*)T_reshape)[((((ax1457 * 3584) + (ax2379 * 512)) + ax3379))];
      }
    }
  }
  for (int32_t h585 = 0; h585 < 7; ++h585) {
    for (int32_t w289 = 0; w289 < 7; ++w289) {
      for (int32_t c334 = 0; c334 < 512; ++c334) {
        ((int32_t*)T_reshape)[((((h585 * 3584) + (w289 * 512)) + c334))] = ((int32_t*)tensor_653)[(c334)];
      }
    }
  }
  for (int32_t h586 = 0; h586 < 7; ++h586) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h586 * 3584));
    (void)load(T_reshape, (int64_t)537329664, 1792, (h586 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h586 * 14336));
  }
  for (int32_t h587 = 0; h587 < 7; ++h587) {
    for (int32_t w290 = 0; w290 < 7; ++w290) {
      for (int32_t c335 = 0; c335 < 512; ++c335) {
        ((int32_t*)T_reshape1)[((((h587 * 3584) + (w290 * 512)) + c335))] = 0;
      }
    }
  }
  for (int32_t h588 = 0; h588 < 7; ++h588) {
    (void)load(compute, (int64_t)537264128, 1792, (h588 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h588 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h588 * 14336));
  }
  for (int32_t h589 = 0; h589 < 7; ++h589) {
    for (int32_t w291 = 0; w291 < 7; ++w291) {
      for (int32_t c336 = 0; c336 < 512; ++c336) {
        ((int32_t*)T_reshape1)[((((h589 * 3584) + (w291 * 512)) + c336))] = 32;
      }
    }
  }
  for (int32_t h590 = 0; h590 < 7; ++h590) {
    (void)load(T_reshape, (int64_t)537264128, 1792, (h590 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h590 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h590 * 14336));
  }
  for (int32_t h591 = 0; h591 < 7; ++h591) {
    for (int32_t w292 = 0; w292 < 7; ++w292) {
      for (int32_t c337 = 0; c337 < 512; ++c337) {
        ((int32_t*)T_reshape1)[((((h591 * 3584) + (w292 * 512)) + c337))] = 6;
      }
    }
  }
  for (int32_t h592 = 0; h592 < 7; ++h592) {
    (void)load(compute, (int64_t)537264128, 1792, (h592 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h592 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h592 * 14336));
  }
  for (int32_t i1299 = 0; i1299 < 7; ++i1299) {
    for (int32_t i2215 = 0; i2215 < 7; ++i2215) {
      for (int32_t i3215 = 0; i3215 < 512; ++i3215) {
        int32_t _160 = ((int32_t*)T_reshape)[((((i1299 * 3584) + (i2215 * 512)) + i3215))];
        int32_t _161 = (_160) < (127) ? (_160) : (127);
        ((int32_t*)T_reshape1)[((((i1299 * 3584) + (i2215 * 512)) + i3215))] = ((_161) > (-127) ? (_161) : (-127));
      }
    }
  }
  for (int32_t i1300 = 0; i1300 < 7; ++i1300) {
    for (int32_t i2216 = 0; i2216 < 7; ++i2216) {
      for (int32_t i3216 = 0; i3216 < 512; ++i3216) {
        ((int8_t*)T_reshape)[((((i1300 * 3584) + (i2216 * 512)) + i3216))] = ((int8_t)((int32_t*)T_reshape1)[((((i1300 * 3584) + (i2216 * 512)) + i3216))]);
      }
    }
  }
  for (int32_t o144 = 0; o144 < 7; ++o144) {
    for (int32_t o244 = 0; o244 < 7; ++o244) {
      for (int32_t c338 = 0; c338 < 512; ++c338) {
        ((int8_t*)T_reshape1)[((((o144 * 3584) + (o244 * 512)) + c338))] = ((int8_t*)T_reshape)[((((o144 * 3584) + (o244 * 512)) + c338))];
      }
    }
  }
  for (int32_t ax0460 = 0; ax0460 < 49; ++ax0460) {
    for (int32_t ax1458 = 0; ax1458 < 512; ++ax1458) {
      ((int8_t*)T_reshape)[(((ax0460 * 512) + ax1458))] = ((int8_t*)T_reshape1)[(((ax0460 * 512) + ax1458))];
    }
  }
  for (int32_t i084 = 0; i084 < 56; ++i084) {
    for (int32_t i1301 = 0; i1301 < 512; ++i1301) {
      ((int8_t*)T_reshape1)[(((i084 * 512) + i1301))] = ((i084 < 49) ? ((int8_t*)T_reshape)[(((i084 * 512) + i1301))] : (int8_t)0);
    }
  }
  for (int32_t ax0461 = 0; ax0461 < 7; ++ax0461) {
    for (int32_t ax1459 = 0; ax1459 < 8; ++ax1459) {
      for (int32_t ax2380 = 0; ax2380 < 64; ++ax2380) {
        for (int32_t ax3380 = 0; ax3380 < 8; ++ax3380) {
          ((int8_t*)T_reshape)[(((((ax0461 * 4096) + (ax1459 * 512)) + (ax2380 * 8)) + ax3380))] = ((int8_t*)T_reshape1)[(((((ax0461 * 4096) + (ax1459 * 512)) + (ax2380 * 8)) + ax3380))];
        }
      }
    }
  }
  for (int32_t ax0462 = 0; ax0462 < 7; ++ax0462) {
    for (int32_t ax1460 = 0; ax1460 < 64; ++ax1460) {
      for (int32_t ax2381 = 0; ax2381 < 8; ++ax2381) {
        for (int32_t ax3381 = 0; ax3381 < 8; ++ax3381) {
          ((int8_t*)T_reshape1)[(((((ax0462 * 4096) + (ax1460 * 64)) + (ax2381 * 8)) + ax3381))] = ((int8_t*)T_reshape)[(((((ax0462 * 4096) + (ax2381 * 512)) + (ax1460 * 8)) + ax3381))];
        }
      }
    }
  }
  for (int32_t ax0463 = 0; ax0463 < 7; ++ax0463) {
    for (int32_t ax2382 = 0; ax2382 < 64; ++ax2382) {
      for (int32_t ax3382 = 0; ax3382 < 8; ++ax3382) {
        for (int32_t ax484 = 0; ax484 < 8; ++ax484) {
          ((int8_t*)T_reshape)[(((((ax0463 * 4096) + (ax2382 * 64)) + (ax3382 * 8)) + ax484))] = ((int8_t*)T_reshape1)[(((((ax0463 * 4096) + (ax2382 * 64)) + (ax3382 * 8)) + ax484))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536870912, 3584, 0);
  for (int32_t ax0464 = 0; ax0464 < 2048; ++ax0464) {
    for (int32_t ax1461 = 0; ax1461 < 512; ++ax1461) {
      ((int8_t*)compute1)[(((ax0464 * 512) + ax1461))] = ((int8_t*)kernel_660)[(((ax0464 * 512) + ax1461))];
    }
  }
  for (int32_t ax0465 = 0; ax0465 < 256; ++ax0465) {
    for (int32_t ax1462 = 0; ax1462 < 8; ++ax1462) {
      for (int32_t ax2383 = 0; ax2383 < 64; ++ax2383) {
        for (int32_t ax3383 = 0; ax3383 < 8; ++ax3383) {
          ((int8_t*)out1)[(((((ax0465 * 4096) + (ax1462 * 512)) + (ax2383 * 8)) + ax3383))] = ((int8_t*)compute1)[(((((ax0465 * 4096) + (ax1462 * 512)) + (ax2383 * 8)) + ax3383))];
        }
      }
    }
  }
  for (int32_t ax0466 = 0; ax0466 < 256; ++ax0466) {
    for (int32_t ax1463 = 0; ax1463 < 64; ++ax1463) {
      for (int32_t ax2384 = 0; ax2384 < 8; ++ax2384) {
        for (int32_t ax3384 = 0; ax3384 < 8; ++ax3384) {
          ((int8_t*)compute1)[(((((ax0466 * 4096) + (ax1463 * 64)) + (ax2384 * 8)) + ax3384))] = ((int8_t*)out1)[(((((ax0466 * 4096) + (ax2384 * 512)) + (ax1463 * 8)) + ax3384))];
        }
      }
    }
  }
  for (int32_t ax0467 = 0; ax0467 < 256; ++ax0467) {
    for (int32_t ax2385 = 0; ax2385 < 64; ++ax2385) {
      for (int32_t ax3385 = 0; ax3385 < 8; ++ax3385) {
        for (int32_t ax485 = 0; ax485 < 8; ++ax485) {
          ((int8_t*)out)[(((((ax0467 * 4096) + (ax2385 * 64)) + (ax3385 * 8)) + ax485))] = ((int8_t*)compute1)[(((((ax0467 * 4096) + (ax2385 * 64)) + (ax3385 * 8)) + ax485))];
        }
      }
    }
  }
  (void)load(out, (int64_t)536936448, 131072, 0);
  for (int32_t i79 = 0; i79 < 7; ++i79) {
    for (int32_t x48 = 0; x48 < 256; ++x48) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i79 * 256) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x48 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i79 * 65536) + (x48 * 256)));
    }
  }
  for (int32_t ax0468 = 0; ax0468 < 7; ++ax0468) {
    for (int32_t ax1464 = 0; ax1464 < 8; ++ax1464) {
      for (int32_t ax2386 = 0; ax2386 < 256; ++ax2386) {
        for (int32_t ax3386 = 0; ax3386 < 8; ++ax3386) {
          ((int32_t*)compute1)[(((((ax0468 * 16384) + (ax1464 * 2048)) + (ax2386 * 8)) + ax3386))] = ((int32_t*)compute)[(((((ax0468 * 16384) + (ax2386 * 64)) + (ax1464 * 8)) + ax3386))];
        }
      }
    }
  }
  for (int32_t ax0469 = 0; ax0469 < 49; ++ax0469) {
    for (int32_t ax1465 = 0; ax1465 < 2048; ++ax1465) {
      ((int32_t*)compute)[(((ax0469 * 2048) + ax1465))] = ((int32_t*)compute1)[(((ax0469 * 2048) + ax1465))];
    }
  }
  for (int32_t i085 = 0; i085 < 49; ++i085) {
    for (int32_t i1302 = 0; i1302 < 2048; ++i1302) {
      ((int32_t*)compute1)[(((i085 * 2048) + i1302))] = ((int32_t*)compute)[(((i085 * 2048) + i1302))];
    }
  }
  for (int32_t ax1466 = 0; ax1466 < 7; ++ax1466) {
    for (int32_t ax2387 = 0; ax2387 < 7; ++ax2387) {
      for (int32_t ax3387 = 0; ax3387 < 2048; ++ax3387) {
        ((int32_t*)compute)[((((ax1466 * 14336) + (ax2387 * 2048)) + ax3387))] = ((int32_t*)compute1)[((((ax1466 * 14336) + (ax2387 * 2048)) + ax3387))];
      }
    }
  }
  for (int32_t h593 = 0; h593 < 7; ++h593) {
    for (int32_t w293 = 0; w293 < 7; ++w293) {
      for (int32_t c339 = 0; c339 < 2048; ++c339) {
        ((int32_t*)compute1)[((((h593 * 14336) + (w293 * 2048)) + c339))] = 16;
      }
    }
  }
  for (int32_t h594 = 0; h594 < 7; ++h594) {
    (void)load(compute, (int64_t)537264128, 7168, (h594 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h594 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h594 * 57344));
  }
  for (int32_t h595 = 0; h595 < 7; ++h595) {
    for (int32_t w294 = 0; w294 < 7; ++w294) {
      for (int32_t c340 = 0; c340 < 2048; ++c340) {
        ((int32_t*)compute)[((((h595 * 14336) + (w294 * 2048)) + c340))] = ((int32_t*)tensor_662)[(c340)];
      }
    }
  }
  for (int32_t h596 = 0; h596 < 7; ++h596) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h596 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h596 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h596 * 57344));
  }
  for (int32_t h597 = 0; h597 < 7; ++h597) {
    for (int32_t w295 = 0; w295 < 7; ++w295) {
      for (int32_t c341 = 0; c341 < 2048; ++c341) {
        ((int32_t*)compute)[((((h597 * 14336) + (w295 * 2048)) + c341))] = 8388608;
      }
    }
  }
  for (int32_t h598 = 0; h598 < 7; ++h598) {
    (void)load(compute1, (int64_t)537264128, 7168, (h598 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h598 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h598 * 57344));
  }
  for (int32_t h599 = 0; h599 < 7; ++h599) {
    for (int32_t w296 = 0; w296 < 7; ++w296) {
      for (int32_t c342 = 0; c342 < 2048; ++c342) {
        ((int32_t*)compute)[((((h599 * 14336) + (w296 * 2048)) + c342))] = 24;
      }
    }
  }
  for (int32_t h600 = 0; h600 < 7; ++h600) {
    (void)load(out1, (int64_t)537264128, 7168, (h600 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h600 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h600 * 57344));
  }
  for (int32_t i1303 = 0; i1303 < 7; ++i1303) {
    for (int32_t i2217 = 0; i2217 < 7; ++i2217) {
      for (int32_t i3217 = 0; i3217 < 2048; ++i3217) {
        int32_t _162 = ((int32_t*)compute1)[((((i1303 * 14336) + (i2217 * 2048)) + i3217))];
        int32_t _163 = (_162) < (127) ? (_162) : (127);
        ((int32_t*)compute)[((((i1303 * 14336) + (i2217 * 2048)) + i3217))] = ((_163) > (-127) ? (_163) : (-127));
      }
    }
  }
  for (int32_t i1304 = 0; i1304 < 7; ++i1304) {
    for (int32_t i2218 = 0; i2218 < 7; ++i2218) {
      for (int32_t i3218 = 0; i3218 < 2048; ++i3218) {
        ((int8_t*)T_reshape1)[((((i1304 * 14336) + (i2218 * 2048)) + i3218))] = ((int8_t)((int32_t*)compute)[((((i1304 * 14336) + (i2218 * 2048)) + i3218))]);
      }
    }
  }
  for (int32_t i1305 = 0; i1305 < 7; ++i1305) {
    for (int32_t i2219 = 0; i2219 < 7; ++i2219) {
      for (int32_t i3219 = 0; i3219 < 2048; ++i3219) {
        ((int32_t*)compute)[((((i1305 * 14336) + (i2219 * 2048)) + i3219))] = ((int32_t)((int8_t*)T_reshape1)[((((i1305 * 14336) + (i2219 * 2048)) + i3219))]);
      }
    }
  }
  for (int32_t h601 = 0; h601 < 7; ++h601) {
    for (int32_t w297 = 0; w297 < 7; ++w297) {
      for (int32_t c343 = 0; c343 < 2048; ++c343) {
        ((int32_t*)compute1)[((((h601 * 14336) + (w297 * 2048)) + c343))] = ((int32_t*)tensor_669)[(c343)];
      }
    }
  }
  for (int32_t h602 = 0; h602 < 7; ++h602) {
    (void)load(compute, (int64_t)537264128, 7168, (h602 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h602 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h602 * 57344));
  }
  for (int32_t h603 = 0; h603 < 7; ++h603) {
    for (int32_t w298 = 0; w298 < 7; ++w298) {
      for (int32_t c344 = 0; c344 < 2048; ++c344) {
        ((int32_t*)compute)[((((h603 * 14336) + (w298 * 2048)) + c344))] = ((int32_t*)tensor_670)[(c344)];
      }
    }
  }
  for (int32_t h604 = 0; h604 < 7; ++h604) {
    (void)load(out, (int64_t)537264128, 7168, (h604 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h604 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h604 * 57344));
  }
  for (int32_t h605 = 0; h605 < 7; ++h605) {
    for (int32_t w299 = 0; w299 < 7; ++w299) {
      for (int32_t c345 = 0; c345 < 2048; ++c345) {
        ((int32_t*)compute)[((((h605 * 14336) + (w299 * 2048)) + c345))] = 8;
      }
    }
  }
  for (int32_t h606 = 0; h606 < 7; ++h606) {
    (void)load(compute1, (int64_t)537264128, 7168, (h606 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h606 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h606 * 57344));
  }
  for (int32_t h607 = 0; h607 < 7; ++h607) {
    for (int32_t w300 = 0; w300 < 7; ++w300) {
      for (int32_t c346 = 0; c346 < 2048; ++c346) {
        ((int32_t*)compute)[((((h607 * 14336) + (w300 * 2048)) + c346))] = 4;
      }
    }
  }
  for (int32_t h608 = 0; h608 < 7; ++h608) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h608 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h608 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h608 * 57344));
  }
  for (int32_t i1306 = 0; i1306 < 7; ++i1306) {
    for (int32_t i2220 = 0; i2220 < 7; ++i2220) {
      for (int32_t i3220 = 0; i3220 < 2048; ++i3220) {
        int32_t _164 = ((int32_t*)compute1)[((((i1306 * 14336) + (i2220 * 2048)) + i3220))];
        int32_t _165 = (_164) < (127) ? (_164) : (127);
        ((int32_t*)compute)[((((i1306 * 14336) + (i2220 * 2048)) + i3220))] = ((_165) > (-127) ? (_165) : (-127));
      }
    }
  }
  for (int32_t i1307 = 0; i1307 < 7; ++i1307) {
    for (int32_t i2221 = 0; i2221 < 7; ++i2221) {
      for (int32_t i3221 = 0; i3221 < 2048; ++i3221) {
        ((int8_t*)T_reshape1)[((((i1307 * 14336) + (i2221 * 2048)) + i3221))] = ((int8_t)((int32_t*)compute)[((((i1307 * 14336) + (i2221 * 2048)) + i3221))]);
      }
    }
  }
  for (int32_t i1308 = 0; i1308 < 7; ++i1308) {
    for (int32_t i2222 = 0; i2222 < 7; ++i2222) {
      for (int32_t i3222 = 0; i3222 < 2048; ++i3222) {
        ((int32_t*)compute)[((((i1308 * 14336) + (i2222 * 2048)) + i3222))] = ((int32_t)((int8_t*)T_reshape1)[((((i1308 * 14336) + (i2222 * 2048)) + i3222))]);
      }
    }
  }
  for (int32_t i1309 = 0; i1309 < 7; ++i1309) {
    for (int32_t i2223 = 0; i2223 < 7; ++i2223) {
      for (int32_t i3223 = 0; i3223 < 2048; ++i3223) {
        ((int32_t*)compute1)[((((i1309 * 14336) + (i2223 * 2048)) + i3223))] = ((int32_t)((int8_t*)out2)[((((i1309 * 14336) + (i2223 * 2048)) + i3223))]);
      }
    }
  }
  for (int32_t h609 = 0; h609 < 7; ++h609) {
    (void)load(compute, (int64_t)537264128, 7168, (h609 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h609 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h609 * 57344));
  }
  for (int32_t h610 = 0; h610 < 7; ++h610) {
    for (int32_t w301 = 0; w301 < 7; ++w301) {
      for (int32_t c347 = 0; c347 < 2048; ++c347) {
        ((int32_t*)compute)[((((h610 * 14336) + (w301 * 2048)) + c347))] = 0;
      }
    }
  }
  for (int32_t h611 = 0; h611 < 7; ++h611) {
    (void)load(out1, (int64_t)537264128, 7168, (h611 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h611 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h611 * 57344));
  }
  for (int32_t i1310 = 0; i1310 < 7; ++i1310) {
    for (int32_t i2224 = 0; i2224 < 7; ++i2224) {
      for (int32_t i3224 = 0; i3224 < 2048; ++i3224) {
        int32_t _166 = ((int32_t*)compute1)[((((i1310 * 14336) + (i2224 * 2048)) + i3224))];
        int32_t _167 = (_166) < (127) ? (_166) : (127);
        ((int32_t*)compute)[((((i1310 * 14336) + (i2224 * 2048)) + i3224))] = ((_167) > (-127) ? (_167) : (-127));
      }
    }
  }
  for (int32_t i1311 = 0; i1311 < 7; ++i1311) {
    for (int32_t i2225 = 0; i2225 < 7; ++i2225) {
      for (int32_t i3225 = 0; i3225 < 2048; ++i3225) {
        ((int8_t*)out2)[((((i1311 * 14336) + (i2225 * 2048)) + i3225))] = ((int8_t)((int32_t*)compute)[((((i1311 * 14336) + (i2225 * 2048)) + i3225))]);
      }
    }
  }
  for (int32_t o145 = 0; o145 < 7; ++o145) {
    for (int32_t o245 = 0; o245 < 7; ++o245) {
      for (int32_t c348 = 0; c348 < 2048; ++c348) {
        ((int8_t*)T_reshape1)[((((o145 * 14336) + (o245 * 2048)) + c348))] = ((int8_t*)out2)[((((o145 * 14336) + (o245 * 2048)) + c348))];
      }
    }
  }
  for (int32_t ax0470 = 0; ax0470 < 49; ++ax0470) {
    for (int32_t ax1467 = 0; ax1467 < 2048; ++ax1467) {
      ((int8_t*)T_reshape)[(((ax0470 * 2048) + ax1467))] = ((int8_t*)T_reshape1)[(((ax0470 * 2048) + ax1467))];
    }
  }
  for (int32_t i086 = 0; i086 < 56; ++i086) {
    for (int32_t i1312 = 0; i1312 < 2048; ++i1312) {
      ((int8_t*)compute)[(((i086 * 2048) + i1312))] = ((i086 < 49) ? ((int8_t*)T_reshape)[(((i086 * 2048) + i1312))] : (int8_t)0);
    }
  }
  for (int32_t ax0471 = 0; ax0471 < 7; ++ax0471) {
    for (int32_t ax1468 = 0; ax1468 < 8; ++ax1468) {
      for (int32_t ax2388 = 0; ax2388 < 256; ++ax2388) {
        for (int32_t ax3388 = 0; ax3388 < 8; ++ax3388) {
          ((int8_t*)T_reshape)[(((((ax0471 * 16384) + (ax1468 * 2048)) + (ax2388 * 8)) + ax3388))] = ((int8_t*)compute)[(((((ax0471 * 16384) + (ax1468 * 2048)) + (ax2388 * 8)) + ax3388))];
        }
      }
    }
  }
  for (int32_t ax0472 = 0; ax0472 < 7; ++ax0472) {
    for (int32_t ax1469 = 0; ax1469 < 256; ++ax1469) {
      for (int32_t ax2389 = 0; ax2389 < 8; ++ax2389) {
        for (int32_t ax3389 = 0; ax3389 < 8; ++ax3389) {
          ((int8_t*)compute)[(((((ax0472 * 16384) + (ax1469 * 64)) + (ax2389 * 8)) + ax3389))] = ((int8_t*)T_reshape)[(((((ax0472 * 16384) + (ax2389 * 2048)) + (ax1469 * 8)) + ax3389))];
        }
      }
    }
  }
  for (int32_t ax0473 = 0; ax0473 < 7; ++ax0473) {
    for (int32_t ax1470 = 0; ax1470 < 2; ++ax1470) {
      for (int32_t ax2390 = 0; ax2390 < 128; ++ax2390) {
        for (int32_t ax3390 = 0; ax3390 < 8; ++ax3390) {
          for (int32_t ax486 = 0; ax486 < 8; ++ax486) {
            ((int8_t*)T_reshape)[((((((ax0473 * 16384) + (ax1470 * 8192)) + (ax2390 * 64)) + (ax3390 * 8)) + ax486))] = ((int8_t*)compute)[((((((ax0473 * 16384) + (ax1470 * 8192)) + (ax2390 * 64)) + (ax3390 * 8)) + ax486))];
          }
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536870912, 14336, 0);
  for (int32_t ax0474 = 0; ax0474 < 512; ++ax0474) {
    for (int32_t ax1471 = 0; ax1471 < 2048; ++ax1471) {
      ((int8_t*)compute1)[(((ax0474 * 2048) + ax1471))] = ((int8_t*)kernel_685)[(((ax0474 * 2048) + ax1471))];
    }
  }
  for (int32_t ax0475 = 0; ax0475 < 64; ++ax0475) {
    for (int32_t ax1472 = 0; ax1472 < 8; ++ax1472) {
      for (int32_t ax2391 = 0; ax2391 < 256; ++ax2391) {
        for (int32_t ax3391 = 0; ax3391 < 8; ++ax3391) {
          ((int8_t*)out)[(((((ax0475 * 16384) + (ax1472 * 2048)) + (ax2391 * 8)) + ax3391))] = ((int8_t*)compute1)[(((((ax0475 * 16384) + (ax1472 * 2048)) + (ax2391 * 8)) + ax3391))];
        }
      }
    }
  }
  for (int32_t ax0476 = 0; ax0476 < 64; ++ax0476) {
    for (int32_t ax1473 = 0; ax1473 < 256; ++ax1473) {
      for (int32_t ax2392 = 0; ax2392 < 8; ++ax2392) {
        for (int32_t ax3392 = 0; ax3392 < 8; ++ax3392) {
          ((int8_t*)compute1)[(((((ax0476 * 16384) + (ax1473 * 64)) + (ax2392 * 8)) + ax3392))] = ((int8_t*)out)[(((((ax0476 * 16384) + (ax2392 * 2048)) + (ax1473 * 8)) + ax3392))];
        }
      }
    }
  }
  for (int32_t ax0477 = 0; ax0477 < 64; ++ax0477) {
    for (int32_t ax1474 = 0; ax1474 < 2; ++ax1474) {
      for (int32_t ax2393 = 0; ax2393 < 128; ++ax2393) {
        for (int32_t ax3393 = 0; ax3393 < 8; ++ax3393) {
          for (int32_t ax487 = 0; ax487 < 8; ++ax487) {
            ((int8_t*)pad_data)[((((((ax0477 * 16384) + (ax1474 * 8192)) + (ax2393 * 64)) + (ax3393 * 8)) + ax487))] = ((int8_t*)compute1)[((((((ax0477 * 16384) + (ax1474 * 8192)) + (ax2393 * 64)) + (ax3393 * 8)) + ax487))];
          }
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536936448, 131072, 0);
  for (int32_t i80 = 0; i80 < 7; ++i80) {
    for (int32_t x49 = 0; x49 < 64; ++x49) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k013 = 0; k013 < 2; ++k013) {
        (void)move(((((int64_t)((i80 * 1024) + (k013 * 512))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 1024, 0);
        (void)move(((((int64_t)((x49 * 1024) + (k013 * 512))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 1024, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 128, (int64_t)1, (int64_t)0);
      }
      (void)store(T_reshape, (int64_t)537264128, 32, ((i80 * 16384) + (x49 * 256)));
    }
  }
  for (int32_t ax0478 = 0; ax0478 < 7; ++ax0478) {
    for (int32_t ax1475 = 0; ax1475 < 8; ++ax1475) {
      for (int32_t ax2394 = 0; ax2394 < 64; ++ax2394) {
        for (int32_t ax3394 = 0; ax3394 < 8; ++ax3394) {
          ((int32_t*)compute)[(((((ax0478 * 4096) + (ax1475 * 512)) + (ax2394 * 8)) + ax3394))] = ((int32_t*)T_reshape)[(((((ax0478 * 4096) + (ax2394 * 64)) + (ax1475 * 8)) + ax3394))];
        }
      }
    }
  }
  for (int32_t ax0479 = 0; ax0479 < 49; ++ax0479) {
    for (int32_t ax1476 = 0; ax1476 < 512; ++ax1476) {
      ((int32_t*)T_reshape1)[(((ax0479 * 512) + ax1476))] = ((int32_t*)compute)[(((ax0479 * 512) + ax1476))];
    }
  }
  for (int32_t i087 = 0; i087 < 49; ++i087) {
    for (int32_t i1313 = 0; i1313 < 512; ++i1313) {
      ((int32_t*)T_reshape)[(((i087 * 512) + i1313))] = ((int32_t*)T_reshape1)[(((i087 * 512) + i1313))];
    }
  }
  for (int32_t ax1477 = 0; ax1477 < 7; ++ax1477) {
    for (int32_t ax2395 = 0; ax2395 < 7; ++ax2395) {
      for (int32_t ax3395 = 0; ax3395 < 512; ++ax3395) {
        ((int32_t*)T_reshape1)[((((ax1477 * 3584) + (ax2395 * 512)) + ax3395))] = ((int32_t*)T_reshape)[((((ax1477 * 3584) + (ax2395 * 512)) + ax3395))];
      }
    }
  }
  for (int32_t h612 = 0; h612 < 7; ++h612) {
    for (int32_t w302 = 0; w302 < 7; ++w302) {
      for (int32_t c349 = 0; c349 < 512; ++c349) {
        ((int32_t*)T_reshape)[((((h612 * 3584) + (w302 * 512)) + c349))] = 18;
      }
    }
  }
  for (int32_t h613 = 0; h613 < 7; ++h613) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h613 * 3584));
    (void)load(T_reshape, (int64_t)537329664, 1792, (h613 * 3584));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h613 * 14336));
  }
  for (int32_t h614 = 0; h614 < 7; ++h614) {
    for (int32_t w303 = 0; w303 < 7; ++w303) {
      for (int32_t c350 = 0; c350 < 512; ++c350) {
        ((int32_t*)T_reshape1)[((((h614 * 3584) + (w303 * 512)) + c350))] = ((int32_t*)tensor_687)[(c350)];
      }
    }
  }
  for (int32_t h615 = 0; h615 < 7; ++h615) {
    (void)load(compute, (int64_t)537264128, 1792, (h615 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h615 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h615 * 14336));
  }
  for (int32_t h616 = 0; h616 < 7; ++h616) {
    for (int32_t w304 = 0; w304 < 7; ++w304) {
      for (int32_t c351 = 0; c351 < 512; ++c351) {
        ((int32_t*)T_reshape1)[((((h616 * 3584) + (w304 * 512)) + c351))] = ((int32_t*)tensor_688)[(c351)];
      }
    }
  }
  for (int32_t h617 = 0; h617 < 7; ++h617) {
    (void)load(T_reshape, (int64_t)537264128, 1792, (h617 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h617 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h617 * 14336));
  }
  for (int32_t h618 = 0; h618 < 7; ++h618) {
    for (int32_t w305 = 0; w305 < 7; ++w305) {
      for (int32_t c352 = 0; c352 < 512; ++c352) {
        ((int32_t*)T_reshape1)[((((h618 * 3584) + (w305 * 512)) + c352))] = 0;
      }
    }
  }
  for (int32_t h619 = 0; h619 < 7; ++h619) {
    (void)load(compute, (int64_t)537264128, 1792, (h619 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h619 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h619 * 14336));
  }
  for (int32_t h620 = 0; h620 < 7; ++h620) {
    for (int32_t w306 = 0; w306 < 7; ++w306) {
      for (int32_t c353 = 0; c353 < 512; ++c353) {
        ((int32_t*)T_reshape1)[((((h620 * 3584) + (w306 * 512)) + c353))] = 16777216;
      }
    }
  }
  for (int32_t h621 = 0; h621 < 7; ++h621) {
    (void)load(T_reshape, (int64_t)537264128, 1792, (h621 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h621 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h621 * 14336));
  }
  for (int32_t h622 = 0; h622 < 7; ++h622) {
    for (int32_t w307 = 0; w307 < 7; ++w307) {
      for (int32_t c354 = 0; c354 < 512; ++c354) {
        ((int32_t*)T_reshape1)[((((h622 * 3584) + (w307 * 512)) + c354))] = 25;
      }
    }
  }
  for (int32_t h623 = 0; h623 < 7; ++h623) {
    (void)load(compute, (int64_t)537264128, 1792, (h623 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h623 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h623 * 14336));
  }
  for (int32_t i1314 = 0; i1314 < 7; ++i1314) {
    for (int32_t i2226 = 0; i2226 < 7; ++i2226) {
      for (int32_t i3226 = 0; i3226 < 512; ++i3226) {
        int32_t _168 = ((int32_t*)T_reshape)[((((i1314 * 3584) + (i2226 * 512)) + i3226))];
        int32_t _169 = (_168) < (127) ? (_168) : (127);
        ((int32_t*)T_reshape1)[((((i1314 * 3584) + (i2226 * 512)) + i3226))] = ((_169) > (-127) ? (_169) : (-127));
      }
    }
  }
  for (int32_t i1315 = 0; i1315 < 7; ++i1315) {
    for (int32_t i2227 = 0; i2227 < 7; ++i2227) {
      for (int32_t i3227 = 0; i3227 < 512; ++i3227) {
        ((int8_t*)T_reshape)[((((i1315 * 3584) + (i2227 * 512)) + i3227))] = ((int8_t)((int32_t*)T_reshape1)[((((i1315 * 3584) + (i2227 * 512)) + i3227))]);
      }
    }
  }
  for (int32_t i1316 = 0; i1316 < 9; ++i1316) {
    for (int32_t i2228 = 0; i2228 < 9; ++i2228) {
      for (int32_t i3228 = 0; i3228 < 512; ++i3228) {
        ((int8_t*)T_reshape1)[((((i1316 * 4608) + (i2228 * 512)) + i3228))] = (((((1 <= i1316) && (i1316 < 8)) && (1 <= i2228)) && (i2228 < 8)) ? ((int8_t*)T_reshape)[(((((i1316 * 3584) + (i2228 * 512)) + i3228) - 4096))] : (int8_t)0);
      }
    }
  }
  for (int32_t o146 = 0; o146 < 7; ++o146) {
    for (int32_t o246 = 0; o246 < 7; ++o246) {
      for (int32_t k115 = 0; k115 < 3; ++k115) {
        for (int32_t k215 = 0; k215 < 3; ++k215) {
          for (int32_t c355 = 0; c355 < 512; ++c355) {
            ((int8_t*)compute)[((((((o146 * 32256) + (o246 * 4608)) + (k115 * 1536)) + (k215 * 512)) + c355))] = ((int8_t*)T_reshape1)[((((((k115 * 4608) + (o146 * 4608)) + (k215 * 512)) + (o246 * 512)) + c355))];
          }
        }
      }
    }
  }
  for (int32_t ax0480 = 0; ax0480 < 49; ++ax0480) {
    for (int32_t ax1478 = 0; ax1478 < 4608; ++ax1478) {
      ((int8_t*)compute1)[(((ax0480 * 4608) + ax1478))] = ((int8_t*)compute)[(((ax0480 * 4608) + ax1478))];
    }
  }
  for (int32_t i088 = 0; i088 < 56; ++i088) {
    for (int32_t i1317 = 0; i1317 < 4608; ++i1317) {
      ((int8_t*)compute)[(((i088 * 4608) + i1317))] = ((i088 < 49) ? ((int8_t*)compute1)[(((i088 * 4608) + i1317))] : (int8_t)0);
    }
  }
  for (int32_t ax0481 = 0; ax0481 < 7; ++ax0481) {
    for (int32_t ax1479 = 0; ax1479 < 8; ++ax1479) {
      for (int32_t ax2396 = 0; ax2396 < 576; ++ax2396) {
        for (int32_t ax3396 = 0; ax3396 < 8; ++ax3396) {
          ((int8_t*)compute1)[(((((ax0481 * 36864) + (ax1479 * 4608)) + (ax2396 * 8)) + ax3396))] = ((int8_t*)compute)[(((((ax0481 * 36864) + (ax1479 * 4608)) + (ax2396 * 8)) + ax3396))];
        }
      }
    }
  }
  for (int32_t ax0482 = 0; ax0482 < 7; ++ax0482) {
    for (int32_t ax1480 = 0; ax1480 < 576; ++ax1480) {
      for (int32_t ax2397 = 0; ax2397 < 8; ++ax2397) {
        for (int32_t ax3397 = 0; ax3397 < 8; ++ax3397) {
          ((int8_t*)compute)[(((((ax0482 * 36864) + (ax1480 * 64)) + (ax2397 * 8)) + ax3397))] = ((int8_t*)compute1)[(((((ax0482 * 36864) + (ax2397 * 4608)) + (ax1480 * 8)) + ax3397))];
        }
      }
    }
  }
  for (int32_t ax0483 = 0; ax0483 < 7; ++ax0483) {
    for (int32_t ax1481 = 0; ax1481 < 8; ++ax1481) {
      for (int32_t ax2398 = 0; ax2398 < 72; ++ax2398) {
        for (int32_t ax3398 = 0; ax3398 < 8; ++ax3398) {
          for (int32_t ax488 = 0; ax488 < 8; ++ax488) {
            ((int8_t*)compute1)[((((((ax0483 * 36864) + (ax1481 * 4608)) + (ax2398 * 64)) + (ax3398 * 8)) + ax488))] = ((int8_t*)compute)[((((((ax0483 * 36864) + (ax1481 * 4608)) + (ax2398 * 64)) + (ax3398 * 8)) + ax488))];
          }
        }
      }
    }
  }
  (void)load(compute1, (int64_t)536870912, 32256, 0);
  for (int32_t ax0484 = 0; ax0484 < 512; ++ax0484) {
    for (int32_t ax1482 = 0; ax1482 < 4608; ++ax1482) {
      ((int8_t*)out1)[(((ax0484 * 4608) + ax1482))] = ((int8_t*)kernel_695)[(((ax0484 * 4608) + ax1482))];
    }
  }
  for (int32_t ax0485 = 0; ax0485 < 64; ++ax0485) {
    for (int32_t ax1483 = 0; ax1483 < 8; ++ax1483) {
      for (int32_t ax2399 = 0; ax2399 < 576; ++ax2399) {
        for (int32_t ax3399 = 0; ax3399 < 8; ++ax3399) {
          ((int8_t*)out)[(((((ax0485 * 36864) + (ax1483 * 4608)) + (ax2399 * 8)) + ax3399))] = ((int8_t*)out1)[(((((ax0485 * 36864) + (ax1483 * 4608)) + (ax2399 * 8)) + ax3399))];
        }
      }
    }
  }
  for (int32_t ax0486 = 0; ax0486 < 64; ++ax0486) {
    for (int32_t ax1484 = 0; ax1484 < 576; ++ax1484) {
      for (int32_t ax2400 = 0; ax2400 < 8; ++ax2400) {
        for (int32_t ax3400 = 0; ax3400 < 8; ++ax3400) {
          ((int8_t*)pad_data)[(((((ax0486 * 36864) + (ax1484 * 64)) + (ax2400 * 8)) + ax3400))] = ((int8_t*)out)[(((((ax0486 * 36864) + (ax2400 * 4608)) + (ax1484 * 8)) + ax3400))];
        }
      }
    }
  }
  for (int32_t ax0487 = 0; ax0487 < 64; ++ax0487) {
    for (int32_t ax1485 = 0; ax1485 < 8; ++ax1485) {
      for (int32_t ax2401 = 0; ax2401 < 72; ++ax2401) {
        for (int32_t ax3401 = 0; ax3401 < 8; ++ax3401) {
          for (int32_t ax489 = 0; ax489 < 8; ++ax489) {
            ((int8_t*)out1)[((((((ax0487 * 36864) + (ax1485 * 4608)) + (ax2401 * 64)) + (ax3401 * 8)) + ax489))] = ((int8_t*)pad_data)[((((((ax0487 * 36864) + (ax1485 * 4608)) + (ax2401 * 64)) + (ax3401 * 8)) + ax489))];
          }
        }
      }
    }
  }
  (void)load(out1, (int64_t)536936448, 294912, 0);
  for (int32_t i81 = 0; i81 < 7; ++i81) {
    for (int32_t x50 = 0; x50 < 64; ++x50) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      for (int32_t k014 = 0; k014 < 8; ++k014) {
        (void)move(((((int64_t)((i81 * 2304) + (k014 * 288))) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 576, 0);
        (void)move(((((int64_t)((x50 * 2304) + (k014 * 288))) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 576, 0);
        (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 72, (int64_t)1, (int64_t)0);
      }
      (void)store(T_reshape, (int64_t)537264128, 32, ((i81 * 16384) + (x50 * 256)));
    }
  }
  for (int32_t ax0488 = 0; ax0488 < 7; ++ax0488) {
    for (int32_t ax1486 = 0; ax1486 < 8; ++ax1486) {
      for (int32_t ax2402 = 0; ax2402 < 64; ++ax2402) {
        for (int32_t ax3402 = 0; ax3402 < 8; ++ax3402) {
          ((int32_t*)compute)[(((((ax0488 * 4096) + (ax1486 * 512)) + (ax2402 * 8)) + ax3402))] = ((int32_t*)T_reshape)[(((((ax0488 * 4096) + (ax2402 * 64)) + (ax1486 * 8)) + ax3402))];
        }
      }
    }
  }
  for (int32_t ax0489 = 0; ax0489 < 49; ++ax0489) {
    for (int32_t ax1487 = 0; ax1487 < 512; ++ax1487) {
      ((int32_t*)T_reshape1)[(((ax0489 * 512) + ax1487))] = ((int32_t*)compute)[(((ax0489 * 512) + ax1487))];
    }
  }
  for (int32_t i089 = 0; i089 < 49; ++i089) {
    for (int32_t i1318 = 0; i1318 < 512; ++i1318) {
      ((int32_t*)T_reshape)[(((i089 * 512) + i1318))] = ((int32_t*)T_reshape1)[(((i089 * 512) + i1318))];
    }
  }
  for (int32_t ax1488 = 0; ax1488 < 7; ++ax1488) {
    for (int32_t ax2403 = 0; ax2403 < 7; ++ax2403) {
      for (int32_t ax3403 = 0; ax3403 < 512; ++ax3403) {
        ((int32_t*)T_reshape1)[((((ax1488 * 3584) + (ax2403 * 512)) + ax3403))] = ((int32_t*)T_reshape)[((((ax1488 * 3584) + (ax2403 * 512)) + ax3403))];
      }
    }
  }
  for (int32_t h624 = 0; h624 < 7; ++h624) {
    for (int32_t w308 = 0; w308 < 7; ++w308) {
      for (int32_t c356 = 0; c356 < 512; ++c356) {
        ((int32_t*)T_reshape)[((((h624 * 3584) + (w308 * 512)) + c356))] = ((int32_t*)tensor_696)[(c356)];
      }
    }
  }
  for (int32_t h625 = 0; h625 < 7; ++h625) {
    (void)load(T_reshape1, (int64_t)537264128, 1792, (h625 * 3584));
    (void)load(T_reshape, (int64_t)537329664, 1792, (h625 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h625 * 14336));
  }
  for (int32_t h626 = 0; h626 < 7; ++h626) {
    for (int32_t w309 = 0; w309 < 7; ++w309) {
      for (int32_t c357 = 0; c357 < 512; ++c357) {
        ((int32_t*)T_reshape1)[((((h626 * 3584) + (w309 * 512)) + c357))] = 0;
      }
    }
  }
  for (int32_t h627 = 0; h627 < 7; ++h627) {
    (void)load(compute, (int64_t)537264128, 1792, (h627 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h627 * 3584));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h627 * 14336));
  }
  for (int32_t h628 = 0; h628 < 7; ++h628) {
    for (int32_t w310 = 0; w310 < 7; ++w310) {
      for (int32_t c358 = 0; c358 < 512; ++c358) {
        ((int32_t*)T_reshape1)[((((h628 * 3584) + (w310 * 512)) + c358))] = 64;
      }
    }
  }
  for (int32_t h629 = 0; h629 < 7; ++h629) {
    (void)load(T_reshape, (int64_t)537264128, 1792, (h629 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h629 * 3584));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(compute, (int64_t)537395200, 1792, (h629 * 14336));
  }
  for (int32_t h630 = 0; h630 < 7; ++h630) {
    for (int32_t w311 = 0; w311 < 7; ++w311) {
      for (int32_t c359 = 0; c359 < 512; ++c359) {
        ((int32_t*)T_reshape1)[((((h630 * 3584) + (w311 * 512)) + c359))] = 7;
      }
    }
  }
  for (int32_t h631 = 0; h631 < 7; ++h631) {
    (void)load(compute, (int64_t)537264128, 1792, (h631 * 3584));
    (void)load(T_reshape1, (int64_t)537329664, 1792, (h631 * 3584));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 112, (int64_t)0);
    (void)store(T_reshape, (int64_t)537395200, 1792, (h631 * 14336));
  }
  for (int32_t i1319 = 0; i1319 < 7; ++i1319) {
    for (int32_t i2229 = 0; i2229 < 7; ++i2229) {
      for (int32_t i3229 = 0; i3229 < 512; ++i3229) {
        int32_t _170 = ((int32_t*)T_reshape)[((((i1319 * 3584) + (i2229 * 512)) + i3229))];
        int32_t _171 = (_170) < (127) ? (_170) : (127);
        ((int32_t*)T_reshape1)[((((i1319 * 3584) + (i2229 * 512)) + i3229))] = ((_171) > (-127) ? (_171) : (-127));
      }
    }
  }
  for (int32_t i1320 = 0; i1320 < 7; ++i1320) {
    for (int32_t i2230 = 0; i2230 < 7; ++i2230) {
      for (int32_t i3230 = 0; i3230 < 512; ++i3230) {
        ((int8_t*)T_reshape)[((((i1320 * 3584) + (i2230 * 512)) + i3230))] = ((int8_t)((int32_t*)T_reshape1)[((((i1320 * 3584) + (i2230 * 512)) + i3230))]);
      }
    }
  }
  for (int32_t o147 = 0; o147 < 7; ++o147) {
    for (int32_t o247 = 0; o247 < 7; ++o247) {
      for (int32_t c360 = 0; c360 < 512; ++c360) {
        ((int8_t*)T_reshape1)[((((o147 * 3584) + (o247 * 512)) + c360))] = ((int8_t*)T_reshape)[((((o147 * 3584) + (o247 * 512)) + c360))];
      }
    }
  }
  for (int32_t ax0490 = 0; ax0490 < 49; ++ax0490) {
    for (int32_t ax1489 = 0; ax1489 < 512; ++ax1489) {
      ((int8_t*)T_reshape)[(((ax0490 * 512) + ax1489))] = ((int8_t*)T_reshape1)[(((ax0490 * 512) + ax1489))];
    }
  }
  for (int32_t i090 = 0; i090 < 56; ++i090) {
    for (int32_t i1321 = 0; i1321 < 512; ++i1321) {
      ((int8_t*)T_reshape1)[(((i090 * 512) + i1321))] = ((i090 < 49) ? ((int8_t*)T_reshape)[(((i090 * 512) + i1321))] : (int8_t)0);
    }
  }
  for (int32_t ax0491 = 0; ax0491 < 7; ++ax0491) {
    for (int32_t ax1490 = 0; ax1490 < 8; ++ax1490) {
      for (int32_t ax2404 = 0; ax2404 < 64; ++ax2404) {
        for (int32_t ax3404 = 0; ax3404 < 8; ++ax3404) {
          ((int8_t*)T_reshape)[(((((ax0491 * 4096) + (ax1490 * 512)) + (ax2404 * 8)) + ax3404))] = ((int8_t*)T_reshape1)[(((((ax0491 * 4096) + (ax1490 * 512)) + (ax2404 * 8)) + ax3404))];
        }
      }
    }
  }
  for (int32_t ax0492 = 0; ax0492 < 7; ++ax0492) {
    for (int32_t ax1491 = 0; ax1491 < 64; ++ax1491) {
      for (int32_t ax2405 = 0; ax2405 < 8; ++ax2405) {
        for (int32_t ax3405 = 0; ax3405 < 8; ++ax3405) {
          ((int8_t*)T_reshape1)[(((((ax0492 * 4096) + (ax1491 * 64)) + (ax2405 * 8)) + ax3405))] = ((int8_t*)T_reshape)[(((((ax0492 * 4096) + (ax2405 * 512)) + (ax1491 * 8)) + ax3405))];
        }
      }
    }
  }
  for (int32_t ax0493 = 0; ax0493 < 7; ++ax0493) {
    for (int32_t ax2406 = 0; ax2406 < 64; ++ax2406) {
      for (int32_t ax3406 = 0; ax3406 < 8; ++ax3406) {
        for (int32_t ax490 = 0; ax490 < 8; ++ax490) {
          ((int8_t*)T_reshape)[(((((ax0493 * 4096) + (ax2406 * 64)) + (ax3406 * 8)) + ax490))] = ((int8_t*)T_reshape1)[(((((ax0493 * 4096) + (ax2406 * 64)) + (ax3406 * 8)) + ax490))];
        }
      }
    }
  }
  (void)load(T_reshape, (int64_t)536870912, 3584, 0);
  for (int32_t ax0494 = 0; ax0494 < 2048; ++ax0494) {
    for (int32_t ax1492 = 0; ax1492 < 512; ++ax1492) {
      ((int8_t*)compute1)[(((ax0494 * 512) + ax1492))] = ((int8_t*)kernel_703)[(((ax0494 * 512) + ax1492))];
    }
  }
  for (int32_t ax0495 = 0; ax0495 < 256; ++ax0495) {
    for (int32_t ax1493 = 0; ax1493 < 8; ++ax1493) {
      for (int32_t ax2407 = 0; ax2407 < 64; ++ax2407) {
        for (int32_t ax3407 = 0; ax3407 < 8; ++ax3407) {
          ((int8_t*)out)[(((((ax0495 * 4096) + (ax1493 * 512)) + (ax2407 * 8)) + ax3407))] = ((int8_t*)compute1)[(((((ax0495 * 4096) + (ax1493 * 512)) + (ax2407 * 8)) + ax3407))];
        }
      }
    }
  }
  for (int32_t ax0496 = 0; ax0496 < 256; ++ax0496) {
    for (int32_t ax1494 = 0; ax1494 < 64; ++ax1494) {
      for (int32_t ax2408 = 0; ax2408 < 8; ++ax2408) {
        for (int32_t ax3408 = 0; ax3408 < 8; ++ax3408) {
          ((int8_t*)compute1)[(((((ax0496 * 4096) + (ax1494 * 64)) + (ax2408 * 8)) + ax3408))] = ((int8_t*)out)[(((((ax0496 * 4096) + (ax2408 * 512)) + (ax1494 * 8)) + ax3408))];
        }
      }
    }
  }
  for (int32_t ax0497 = 0; ax0497 < 256; ++ax0497) {
    for (int32_t ax2409 = 0; ax2409 < 64; ++ax2409) {
      for (int32_t ax3409 = 0; ax3409 < 8; ++ax3409) {
        for (int32_t ax491 = 0; ax491 < 8; ++ax491) {
          ((int8_t*)pad_data)[(((((ax0497 * 4096) + (ax2409 * 64)) + (ax3409 * 8)) + ax491))] = ((int8_t*)compute1)[(((((ax0497 * 4096) + (ax2409 * 64)) + (ax3409 * 8)) + ax491))];
        }
      }
    }
  }
  (void)load(pad_data, (int64_t)536936448, 131072, 0);
  for (int32_t i82 = 0; i82 < 7; ++i82) {
    for (int32_t x51 = 0; x51 < 256; ++x51) {
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, (int64_t)1, (int64_t)1, (int64_t)1);
      (void)move(((((int64_t)((i82 * 256) + 112896)) * (int64_t)4) + (int64_t)536870912), (((int64_t)0 * (int64_t)2) + (int64_t)537001984), 512, 0);
      (void)move(((((int64_t)(x51 * 256)) * (int64_t)4) + (int64_t)536936448), (((int64_t)0 * (int64_t)16) + (int64_t)537133056), 512, 0);
      (void)gemm((int64_t)537001984, (int64_t)537133056, (int64_t)537264128, (int64_t)1, 64, (int64_t)1, (int64_t)0);
      (void)store(compute, (int64_t)537264128, 32, ((i82 * 65536) + (x51 * 256)));
    }
  }
  for (int32_t ax0498 = 0; ax0498 < 7; ++ax0498) {
    for (int32_t ax1495 = 0; ax1495 < 8; ++ax1495) {
      for (int32_t ax2410 = 0; ax2410 < 256; ++ax2410) {
        for (int32_t ax3410 = 0; ax3410 < 8; ++ax3410) {
          ((int32_t*)compute1)[(((((ax0498 * 16384) + (ax1495 * 2048)) + (ax2410 * 8)) + ax3410))] = ((int32_t*)compute)[(((((ax0498 * 16384) + (ax2410 * 64)) + (ax1495 * 8)) + ax3410))];
        }
      }
    }
  }
  for (int32_t ax0499 = 0; ax0499 < 49; ++ax0499) {
    for (int32_t ax1496 = 0; ax1496 < 2048; ++ax1496) {
      ((int32_t*)compute)[(((ax0499 * 2048) + ax1496))] = ((int32_t*)compute1)[(((ax0499 * 2048) + ax1496))];
    }
  }
  for (int32_t i091 = 0; i091 < 49; ++i091) {
    for (int32_t i1322 = 0; i1322 < 2048; ++i1322) {
      ((int32_t*)compute1)[(((i091 * 2048) + i1322))] = ((int32_t*)compute)[(((i091 * 2048) + i1322))];
    }
  }
  for (int32_t ax1497 = 0; ax1497 < 7; ++ax1497) {
    for (int32_t ax2411 = 0; ax2411 < 7; ++ax2411) {
      for (int32_t ax3411 = 0; ax3411 < 2048; ++ax3411) {
        ((int32_t*)compute)[((((ax1497 * 14336) + (ax2411 * 2048)) + ax3411))] = ((int32_t*)compute1)[((((ax1497 * 14336) + (ax2411 * 2048)) + ax3411))];
      }
    }
  }
  for (int32_t h632 = 0; h632 < 7; ++h632) {
    for (int32_t w312 = 0; w312 < 7; ++w312) {
      for (int32_t c361 = 0; c361 < 2048; ++c361) {
        ((int32_t*)compute1)[((((h632 * 14336) + (w312 * 2048)) + c361))] = 17;
      }
    }
  }
  for (int32_t h633 = 0; h633 < 7; ++h633) {
    (void)load(compute, (int64_t)537264128, 7168, (h633 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h633 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h633 * 57344));
  }
  for (int32_t h634 = 0; h634 < 7; ++h634) {
    for (int32_t w313 = 0; w313 < 7; ++w313) {
      for (int32_t c362 = 0; c362 < 2048; ++c362) {
        ((int32_t*)compute)[((((h634 * 14336) + (w313 * 2048)) + c362))] = ((int32_t*)tensor_705)[(c362)];
      }
    }
  }
  for (int32_t h635 = 0; h635 < 7; ++h635) {
    (void)load(out1, (int64_t)537264128, 7168, (h635 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h635 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h635 * 57344));
  }
  for (int32_t h636 = 0; h636 < 7; ++h636) {
    for (int32_t w314 = 0; w314 < 7; ++w314) {
      for (int32_t c363 = 0; c363 < 2048; ++c363) {
        ((int32_t*)compute)[((((h636 * 14336) + (w314 * 2048)) + c363))] = 8388608;
      }
    }
  }
  for (int32_t h637 = 0; h637 < 7; ++h637) {
    (void)load(compute1, (int64_t)537264128, 7168, (h637 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h637 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h637 * 57344));
  }
  for (int32_t h638 = 0; h638 < 7; ++h638) {
    for (int32_t w315 = 0; w315 < 7; ++w315) {
      for (int32_t c364 = 0; c364 < 2048; ++c364) {
        ((int32_t*)compute)[((((h638 * 14336) + (w315 * 2048)) + c364))] = 24;
      }
    }
  }
  for (int32_t h639 = 0; h639 < 7; ++h639) {
    (void)load(out, (int64_t)537264128, 7168, (h639 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h639 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h639 * 57344));
  }
  for (int32_t i1323 = 0; i1323 < 7; ++i1323) {
    for (int32_t i2231 = 0; i2231 < 7; ++i2231) {
      for (int32_t i3231 = 0; i3231 < 2048; ++i3231) {
        int32_t _172 = ((int32_t*)compute1)[((((i1323 * 14336) + (i2231 * 2048)) + i3231))];
        int32_t _173 = (_172) < (127) ? (_172) : (127);
        ((int32_t*)compute)[((((i1323 * 14336) + (i2231 * 2048)) + i3231))] = ((_173) > (-127) ? (_173) : (-127));
      }
    }
  }
  for (int32_t i1324 = 0; i1324 < 7; ++i1324) {
    for (int32_t i2232 = 0; i2232 < 7; ++i2232) {
      for (int32_t i3232 = 0; i3232 < 2048; ++i3232) {
        ((int8_t*)T_reshape1)[((((i1324 * 14336) + (i2232 * 2048)) + i3232))] = ((int8_t)((int32_t*)compute)[((((i1324 * 14336) + (i2232 * 2048)) + i3232))]);
      }
    }
  }
  for (int32_t i1325 = 0; i1325 < 7; ++i1325) {
    for (int32_t i2233 = 0; i2233 < 7; ++i2233) {
      for (int32_t i3233 = 0; i3233 < 2048; ++i3233) {
        ((int32_t*)compute)[((((i1325 * 14336) + (i2233 * 2048)) + i3233))] = ((int32_t)((int8_t*)T_reshape1)[((((i1325 * 14336) + (i2233 * 2048)) + i3233))]);
      }
    }
  }
  for (int32_t h640 = 0; h640 < 7; ++h640) {
    for (int32_t w316 = 0; w316 < 7; ++w316) {
      for (int32_t c365 = 0; c365 < 2048; ++c365) {
        ((int32_t*)compute1)[((((h640 * 14336) + (w316 * 2048)) + c365))] = ((int32_t*)tensor_712)[(c365)];
      }
    }
  }
  for (int32_t h641 = 0; h641 < 7; ++h641) {
    (void)load(compute, (int64_t)537264128, 7168, (h641 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h641 * 14336));
    (void)ve(3, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h641 * 57344));
  }
  for (int32_t h642 = 0; h642 < 7; ++h642) {
    for (int32_t w317 = 0; w317 < 7; ++w317) {
      for (int32_t c366 = 0; c366 < 2048; ++c366) {
        ((int32_t*)compute)[((((h642 * 14336) + (w317 * 2048)) + c366))] = 1;
      }
    }
  }
  for (int32_t h643 = 0; h643 < 7; ++h643) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h643 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h643 * 14336));
    (void)ve(10, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h643 * 57344));
  }
  for (int32_t h644 = 0; h644 < 7; ++h644) {
    for (int32_t w318 = 0; w318 < 7; ++w318) {
      for (int32_t c367 = 0; c367 < 2048; ++c367) {
        ((int32_t*)compute)[((((h644 * 14336) + (w318 * 2048)) + c367))] = ((int32_t*)tensor_714)[(c367)];
      }
    }
  }
  for (int32_t h645 = 0; h645 < 7; ++h645) {
    (void)load(compute1, (int64_t)537264128, 7168, (h645 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h645 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out1, (int64_t)537395200, 7168, (h645 * 57344));
  }
  for (int32_t h646 = 0; h646 < 7; ++h646) {
    for (int32_t w319 = 0; w319 < 7; ++w319) {
      for (int32_t c368 = 0; c368 < 2048; ++c368) {
        ((int32_t*)compute)[((((h646 * 14336) + (w319 * 2048)) + c368))] = 4;
      }
    }
  }
  for (int32_t h647 = 0; h647 < 7; ++h647) {
    (void)load(out1, (int64_t)537264128, 7168, (h647 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h647 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h647 * 57344));
  }
  for (int32_t h648 = 0; h648 < 7; ++h648) {
    for (int32_t w320 = 0; w320 < 7; ++w320) {
      for (int32_t c369 = 0; c369 < 2048; ++c369) {
        ((int32_t*)compute)[((((h648 * 14336) + (w320 * 2048)) + c369))] = 3;
      }
    }
  }
  for (int32_t h649 = 0; h649 < 7; ++h649) {
    (void)load(compute1, (int64_t)537264128, 7168, (h649 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h649 * 14336));
    (void)ve(9, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(out, (int64_t)537395200, 7168, (h649 * 57344));
  }
  for (int32_t i1326 = 0; i1326 < 7; ++i1326) {
    for (int32_t i2234 = 0; i2234 < 7; ++i2234) {
      for (int32_t i3234 = 0; i3234 < 2048; ++i3234) {
        int32_t _174 = ((int32_t*)out)[((((i1326 * 14336) + (i2234 * 2048)) + i3234))];
        int32_t _175 = (_174) < (127) ? (_174) : (127);
        ((int32_t*)compute)[((((i1326 * 14336) + (i2234 * 2048)) + i3234))] = ((_175) > (-127) ? (_175) : (-127));
      }
    }
  }
  for (int32_t i1327 = 0; i1327 < 7; ++i1327) {
    for (int32_t i2235 = 0; i2235 < 7; ++i2235) {
      for (int32_t i3235 = 0; i3235 < 2048; ++i3235) {
        ((int8_t*)T_reshape1)[((((i1327 * 14336) + (i2235 * 2048)) + i3235))] = ((int8_t)((int32_t*)compute)[((((i1327 * 14336) + (i2235 * 2048)) + i3235))]);
      }
    }
  }
  for (int32_t i1328 = 0; i1328 < 7; ++i1328) {
    for (int32_t i2236 = 0; i2236 < 7; ++i2236) {
      for (int32_t i3236 = 0; i3236 < 2048; ++i3236) {
        ((int32_t*)compute)[((((i1328 * 14336) + (i2236 * 2048)) + i3236))] = ((int32_t)((int8_t*)T_reshape1)[((((i1328 * 14336) + (i2236 * 2048)) + i3236))]);
      }
    }
  }
  for (int32_t i1329 = 0; i1329 < 7; ++i1329) {
    for (int32_t i2237 = 0; i2237 < 7; ++i2237) {
      for (int32_t i3237 = 0; i3237 < 2048; ++i3237) {
        ((int32_t*)compute1)[((((i1329 * 14336) + (i2237 * 2048)) + i3237))] = ((int32_t)((int8_t*)out2)[((((i1329 * 14336) + (i2237 * 2048)) + i3237))]);
      }
    }
  }
  for (int32_t h650 = 0; h650 < 7; ++h650) {
    (void)load(compute, (int64_t)537264128, 7168, (h650 * 14336));
    (void)load(compute1, (int64_t)537329664, 7168, (h650 * 14336));
    (void)ve(1, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(pad_data, (int64_t)537395200, 7168, (h650 * 57344));
  }
  for (int32_t h651 = 0; h651 < 7; ++h651) {
    for (int32_t w321 = 0; w321 < 7; ++w321) {
      for (int32_t c370 = 0; c370 < 2048; ++c370) {
        ((int32_t*)compute)[((((h651 * 14336) + (w321 * 2048)) + c370))] = 0;
      }
    }
  }
  for (int32_t h652 = 0; h652 < 7; ++h652) {
    (void)load(pad_data, (int64_t)537264128, 7168, (h652 * 14336));
    (void)load(compute, (int64_t)537329664, 7168, (h652 * 14336));
    (void)ve(5, (int64_t)537264128, (int64_t)537329664, (int64_t)537395200, 448, (int64_t)0);
    (void)store(compute1, (int64_t)537395200, 7168, (h652 * 57344));
  }
  for (int32_t i1330 = 0; i1330 < 7; ++i1330) {
    for (int32_t i2238 = 0; i2238 < 7; ++i2238) {
      for (int32_t i3238 = 0; i3238 < 2048; ++i3238) {
        ((int8_t*)out2)[((((i1330 * 14336) + (i2238 * 2048)) + i3238))] = ((int8_t)((int32_t*)compute1)[((((i1330 * 14336) + (i2238 * 2048)) + i3238))]);
      }
    }
  }
  for (int32_t i1331 = 0; i1331 < 7; ++i1331) {
    for (int32_t i2239 = 0; i2239 < 7; ++i2239) {
      for (int32_t i3239 = 0; i3239 < 2048; ++i3239) {
        ((int32_t*)compute)[((((i1331 * 14336) + (i2239 * 2048)) + i3239))] = ((int32_t)((int8_t*)out2)[((((i1331 * 14336) + (i2239 * 2048)) + i3239))]);
      }
    }
  }
  for (int32_t ax1498 = 0; ax1498 < 2048; ++ax1498) {
    for (int32_t ax2412 = 0; ax2412 < 7; ++ax2412) {
      for (int32_t ax3412 = 0; ax3412 < 7; ++ax3412) {
        ((int32_t*)compute1)[((((ax1498 * 49) + (ax2412 * 7)) + ax3412))] = ((int32_t*)compute)[((((ax2412 * 14336) + (ax3412 * 2048)) + ax1498))];
      }
    }
  }
  for (int32_t ax1499 = 0; ax1499 < 2048; ++ax1499) {
    ((int32_t*)out2)[(ax1499)] = 0;
    for (int32_t rv01 = 0; rv01 < 7; ++rv01) {
      for (int32_t rv11 = 0; rv11 < 7; ++rv11) {
        ((int32_t*)out2)[(ax1499)] = (((int32_t*)out2)[(ax1499)] + ((int32_t*)compute1)[((((ax1499 * 49) + (rv01 * 7)) + rv11))]);
      }
    }
  }
  for (int32_t ax1500 = 0; ax1500 < 2048; ++ax1500) {
    ((int32_t*)T_reshape1)[(ax1500)] = (((int32_t*)out2)[(ax1500)] / 49);
  }
  for (int32_t j1 = 0; j1 < 2048; ++j1) {
    ((int32_t*)out2)[(j1)] = ((int32_t*)T_reshape1)[(j1)];
  }
  for (int32_t i1332 = 0; i1332 < 2048; ++i1332) {
    ((float*)T_reshape1)[(i1332)] = ((float)((int32_t*)out2)[(i1332)]);
  }
  for (int32_t ax1501 = 0; ax1501 < 2048; ++ax1501) {
    ((float*)out2)[(ax1501)] = (((float*)T_reshape1)[(ax1501)] * 6.250000e-02f);
  }
  for (int32_t j2 = 0; j2 < 1000; ++j2) {
    ((float*)T_matmul_NT)[(j2)] = 0.000000e+00f;
    for (int32_t k = 0; k < 2048; ++k) {
      ((float*)T_matmul_NT)[(j2)] = (((float*)T_matmul_NT)[(j2)] + (((float*)out2)[(k)] * ((float*)tensor_733)[(((j2 * 2048) + k))]));
    }
  }
  for (int32_t ax1502 = 0; ax1502 < 1000; ++ax1502) {
    ((float*)T_add)[(ax1502)] = (((float*)T_matmul_NT)[(ax1502)] + ((float*)tensor_734)[(ax1502)]);
  }
  if (TVMBackendFreeWorkspace(1, dev_id, T_matmul_NT) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, out2) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, out1) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, cout) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, data2_in) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, data1_in) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, out) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, weight) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, feature) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, weight_input) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, feature_input) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, T_reshape1) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, T_reshape) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, compute1) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, compute) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, Y) != 0) {
    return -1;
  }
  if (TVMBackendFreeWorkspace(1, dev_id, pad_data) != 0) {
    return -1;
  }
  return 0;
}

