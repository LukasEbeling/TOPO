#include "NN/topo_HHbbWW_1mu_v5.h"
#include "emulator.h"
#include "NN/nnet_utils/nnet_common.h"
#include <any>
#include "ap_fixed.h"
#include "ap_int.h"
#include "scales.h"

using namespace hls4ml_topo_HHbbWW_1mu_v5;

class topo_emulator_HHbbWW_1mu_v5 : public hls4mlEmulator::Model {

private:
    typedef ap_fixed<23,23> unscaled_t;
    static const int N_INPUT_SIZE  = 21;
    static const int N_OUTPUT_SIZE = 1;

    unscaled_t _unscaled_input[N_INPUT_SIZE];
    input_t  _scaled_input[N_INPUT_SIZE];
    result_t _result[N_OUTPUT_SIZE];

    virtual void _scaleNNInputs(unscaled_t unscaled[N_INPUT_SIZE],
                                input_t scaled[N_INPUT_SIZE])
    {
        for (int i = 0; i < N_INPUT_SIZE; i++) {
            ap_fixed<32,23> tmp0 = unscaled[i]; //more fractional bits for bit shifting, match uGT firmware hls wrapper
            tmp0 = tmp0 - topo_offsets[i]; 
            input_t tmp1 = tmp0 >> topo_shift[i];
            scaled[i] = tmp1;
        }
    }

public:
    virtual void prepare_input(std::any input) override {
        unscaled_t* unscaled_input_p = std::any_cast<unscaled_t*>(input);

        for (int i = 0; i < N_INPUT_SIZE; i++) {
            _unscaled_input[i] = unscaled_input_p[i];
        }

        _scaleNNInputs(_unscaled_input, _scaled_input);
    }

    virtual void predict() override {
        topo_HHbbWW_1mu_v5(_scaled_input, _result);
    }

    virtual void read_result(std::any result) override {
        result_t* result_p =
            std::any_cast<result_t*>(result);

        for (int i = 0; i < N_OUTPUT_SIZE; i++) {
            result_p[i] = _result[i];
        }
    }
};

extern "C" hls4mlEmulator::Model* create_model() {
    return new topo_emulator_HHbbWW_1mu_v5;
}

extern "C" void destroy_model(hls4mlEmulator::Model* m) {
    delete m;
}
