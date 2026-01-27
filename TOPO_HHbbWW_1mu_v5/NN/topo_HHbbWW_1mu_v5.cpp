#include <iostream>

#include "topo_HHbbWW_1mu_v5.h"
#include "parameters.h"

namespace hls4ml_topo_HHbbWW_1mu_v5 {

void topo_HHbbWW_1mu_v5(
    input_t dropout_input[21],
    result_t layer10_out[1]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=dropout_input complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=dropout_input,layer10_out 
    #pragma HLS PIPELINE

    // hls-fpga-machine-learning insert load weights

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    munet_fc1_result_t layer2_out[128];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0

    layer4_t layer4_out[128];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0

    munet_fc2_result_t layer5_out[64];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0

    layer7_t layer7_out[64];
    #pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0

    munet_output_result_t layer8_out[1];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0

    nnet::dense<input_t, munet_fc1_result_t, config2>(dropout_input, layer2_out, w2, b2); // munet_fc1

    nnet::relu<munet_fc1_result_t, layer4_t, relu_config4>(layer2_out, layer4_out); // munet_activation1

    nnet::dense<layer4_t, munet_fc2_result_t, config5>(layer4_out, layer5_out, w5, b5); // munet_fc2

    nnet::relu<munet_fc2_result_t, layer7_t, relu_config7>(layer5_out, layer7_out); // munet_activation2

    nnet::dense<layer7_t, munet_output_result_t, config8>(layer7_out, layer8_out, w8, b8); // munet_output

    nnet::sigmoid<munet_output_result_t, result_t, sigmoid_config10>(layer8_out, layer10_out); // munet_sigmoid
        
    if (layer8_out[0] > 31) layer10_out[0] = (result_t) 31;
    else if (layer8_out[0] < -32) layer10_out[0] = (result_t) -32;
    else layer10_out[0] = (result_t) layer8_out[0];
}

}
