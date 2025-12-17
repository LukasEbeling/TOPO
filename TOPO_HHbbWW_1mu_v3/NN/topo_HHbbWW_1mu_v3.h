//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

//from https://gitlab.cern.ch/lebeling/topo-deployed/-/tree/2025-06-24-v2/model/quantised/hls_model/firmware?ref_type=heads

#ifndef TOPO_v3_H_
#define TOPO_v3_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

#include "defines.h"

namespace hls4ml_topo_HHbbWW_1mu_v3 {

void topo_HHbbWW_1mu_v3(
    input_t munet_fc1_input[N_INPUT_1_1],
    result_t layer11_out[N_LAYER_11]
);

} // namespace hls4ml_topo_HHbbWW_1mu_v3

#endif
