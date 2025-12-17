#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "nn_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

namespace hls4ml_topo_HHbbWW_1mu_v3 {

// hls-fpga-machine-learning insert numbers
static const int N_INPUT_1_1 = 21;
static const int N_LAYER_2 = 64;
static const int N_LAYER_5 = 32;
static const int N_LAYER_8 = 32;
static const int N_LAYER_11 = 1;

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<23,23> unscaled_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_fixed<16,7> weight2_t;
typedef ap_fixed<16,7> bias2_t;
typedef ap_uint<1> layer2_index;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT> layer4_t;
typedef ap_fixed<18,8> munet_activation1_table_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,7> weight5_t;
typedef ap_fixed<16,7> bias5_t;
typedef ap_uint<1> layer5_index;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT> layer7_t;
typedef ap_fixed<18,8> munet_activation2_table_t;
typedef ap_fixed<16,6> layer8_t;
typedef ap_fixed<16,7> weight8_t;
typedef ap_fixed<16,7> bias8_t;
typedef ap_uint<1> layer8_index;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT> layer10_t;
typedef ap_fixed<18,8> munet_activation3_table_t;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<16,7> weight11_t;
typedef ap_fixed<16,7> bias11_t;
typedef ap_uint<1> layer11_index;

extern weight2_t w2[1344];
extern weight5_t w5[2048];
extern weight8_t w8[1024];
extern weight11_t w11[32];
extern bias2_t b2[64];
extern bias5_t b5[32];
extern bias8_t b8[32];
extern bias11_t b11[1];

} // namespace hls4ml_topo_HHbbWW_1mu_v3
#endif