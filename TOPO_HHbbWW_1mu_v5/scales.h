#ifndef __ADT_SCALES_H
#define __ADT_SCALES_H

#include "NN/topo_HHbbWW_1mu_v5.h"

namespace hls4ml_topo_HHbbWW_1mu_v5 {

typedef ap_fixed<5,5> topo_shift_t;
typedef ap_fixed<23,23> topo_offset_t;

const topo_shift_t topo_shift[21] = {
    7, 5, 7, 8, 3, 2, 5, 6, 1, 6, 6, 6, 6, 6, 6, 5, 5, 6, 5, 5, 6
};

const topo_offset_t topo_offsets[21] = {
    43, 3, 0, 52, 2, 0, 0, 8, 0, 60, 1, 64, 37, 1, 51, 22, 1, 36, 12, 0, 23
};

} // namespace hls4ml_topo_HHbbWW_1mu_v5
#endif
