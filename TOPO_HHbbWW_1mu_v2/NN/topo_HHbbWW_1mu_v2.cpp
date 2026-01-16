#include <iostream>

#include "topo_HHbbWW_1mu_v2.h"
#include "parameters.h"


void topo_HHbbWW_1mu_v2(
    input_t dropout_input[21],
    result_t layer13_out[1]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=dropout_input complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer13_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=dropout_input,layer13_out 
    #pragma HLS PIPELINE

    // hls-fpga-machine-learning insert load weights
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        nnet::load_weights_from_txt<weight2_t, 1344>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 64>(b2, "b2.txt");
        nnet::load_weights_from_txt<weight5_t, 2048>(w5, "w5.txt");
        nnet::load_weights_from_txt<bias5_t, 32>(b5, "b5.txt");
        nnet::load_weights_from_txt<weight8_t, 1024>(w8, "w8.txt");
        nnet::load_weights_from_txt<bias8_t, 32>(b8, "b8.txt");
        nnet::load_weights_from_txt<weight11_t, 32>(w11, "w11.txt");
        nnet::load_weights_from_txt<bias11_t, 1>(b11, "b11.txt");
        loaded_weights = true;    }
#endif
    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    munet_fc1_result_t layer2_out[64];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0

    layer4_t layer4_out[64];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0

    munet_fc2_result_t layer5_out[32];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0

    layer7_t layer7_out[32];
    #pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0

    munet_fc3_result_t layer8_out[32];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0

    layer10_t layer10_out[32];
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0

    munet_output_result_t layer11_out[1];
    #pragma HLS ARRAY_PARTITION variable=layer11_out complete dim=0

    nnet::dense<input_t, munet_fc1_result_t, config2>(dropout_input, layer2_out, w2, b2); // munet_fc1

    nnet::relu<munet_fc1_result_t, layer4_t, relu_config4>(layer2_out, layer4_out); // munet_activation1

    nnet::dense<layer4_t, munet_fc2_result_t, config5>(layer4_out, layer5_out, w5, b5); // munet_fc2

    nnet::relu<munet_fc2_result_t, layer7_t, relu_config7>(layer5_out, layer7_out); // munet_activation2

    nnet::dense<layer7_t, munet_fc3_result_t, config8>(layer7_out, layer8_out, w8, b8); // munet_fc3

    nnet::relu<munet_fc3_result_t, layer10_t, relu_config10>(layer8_out, layer10_out); // munet_activation3

    nnet::dense<layer10_t, munet_output_result_t, config11>(layer10_out, layer11_out, w11, b11); // munet_output

    nnet::sigmoid<munet_output_result_t, result_t, sigmoid_config13>(layer11_out, layer13_out); // munet_sigmoid

    // layer13_out[0] = static_cast<result_t>(layer11_out[0]);
}

