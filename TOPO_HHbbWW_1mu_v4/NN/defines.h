#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <array>
#include <cstddef>
#include <cstdio>
#include <tuple>
#include <tuple>


// hls-fpga-machine-learning insert numbers

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<38,19> munet_fc1_result_t;
typedef ap_fixed<16,7> weight2_t;
typedef ap_fixed<16,7> bias2_t;
typedef ap_uint<1> layer2_index;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT,0> layer4_t;
typedef ap_fixed<18,8> munet_activation1_table_t;
typedef ap_fixed<32,15> munet_fc2_result_t;
typedef ap_fixed<16,7> weight5_t;
typedef ap_fixed<16,7> bias5_t;
typedef ap_uint<1> layer5_index;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT,0> layer7_t;
typedef ap_fixed<18,8> munet_activation2_table_t;
typedef ap_fixed<31,14> munet_output_result_t;
typedef ap_fixed<16,7> weight8_t;
typedef ap_fixed<16,7> bias8_t;
typedef ap_uint<1> layer8_index;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<18,8> munet_sigmoid_table_t;

// hls-fpga-machine-learning insert emulator-defines


#endif
