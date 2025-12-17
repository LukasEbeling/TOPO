#ifndef TOPO_HHBBWW_1MU_V3_H_
#define TOPO_HHBBWW_1MU_V3_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

#include "defines.h"

namespace hls4ml_topo_HHbbWW_1mu_v3 {

void topo_HHbbWW_1mu_v2(
    input_t dropout_input[N_INPUT_1_1],
    result_t layer11_out[N_LAYER_11]
);

} // namespace hls4ml_topo_HHbbWW_1mu_v3

#endif
