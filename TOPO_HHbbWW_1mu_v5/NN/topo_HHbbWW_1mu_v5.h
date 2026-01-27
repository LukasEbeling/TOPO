#ifndef topo_HHbbWW_1mu_v5_H_
#define topo_HHbbWW_1mu_v5_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"

#include "defines.h"

namespace hls4ml_topo_HHbbWW_1mu_v5 {

// Prototype of top level function for C-synthesis
void topo_HHbbWW_1mu_v5(
    input_t dropout_input[21],
    result_t layer10_out[1]
);

// hls-fpga-machine-learning insert emulator-defines

}

#endif
