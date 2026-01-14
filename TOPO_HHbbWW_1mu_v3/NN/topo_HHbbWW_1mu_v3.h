#ifndef TOPO_HHBBWW_1MU_V3_H_
#define TOPO_HHBBWW_1MU_V3_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"

#include "defines.h"

// Prototype of top level function for C-synthesis
void topo_HHbbWW_1mu_v3(
    input_t dropout_input[N_INPUT_1_1],
    result_t layer13_out[N_LAYER_11]
);

#endif
