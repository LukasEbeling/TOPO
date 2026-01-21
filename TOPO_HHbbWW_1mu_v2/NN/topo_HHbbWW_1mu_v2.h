#ifndef TOPO_HHBBWW_1MU_V2_H_
#define TOPO_HHBBWW_1MU_V2_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"

#include "defines.h"


// Prototype of top level function for C-synthesis
void topo_HHbbWW_1mu_v2(
    input_t dropout_input[21],
    result_t layer13_out[1]
);

// hls-fpga-machine-learning insert emulator-defines


#endif
