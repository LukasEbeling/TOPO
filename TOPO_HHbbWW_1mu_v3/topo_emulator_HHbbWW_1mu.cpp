#include "NN/topo_HHbbWW_1mu_v3.h" //include of the top level of HLS model
#include "emulator.h" //include of emulator modeling
#include <any>
#include "ap_fixed.h"
#include "scaling.h"

using namespace standardscaler;

class topo_emulator_HHbbWW_1mu : public hls4mlEmulator::Model {

private:
    static const int N_INPUT_1_1 = 21;
    static const int N_LAYER_11 = 1;
    unscaled_t _unscaled_input[N_INPUT_1_1];
    input_t _scaled_input[N_INPUT_1_1];
    result_t _result[N_LAYER_11];
    
    virtual void _scaleNNInputs(unscaled_t unscaled[N_INPUT_1_1], input_t scaled[N_INPUT_1_1])
    {
        for (int i = 0; i < N_INPUT_1_1; i++)
        {
        double tmp0 = unscaled[i] - standardscaler::bias[i];
        double tmp1 = tmp0 / standardscaler::norm[i];
        scaled[i] = static_cast<input_t>(tmp1);
        }
    }

public: 
    virtual void prepare_input(std::any input) {
        unscaled_t *unscaled_input_p = std::any_cast<unscaled_t*>(input);
        _scaleNNInputs(unscaled_input_p, _scaled_input);
    }

    virtual void predict() {
        topo_HHbbWW_1mu_v3(_scaled_input, _result);
    }
  
    virtual void read_result(std::any result) {
        result_t *result_p = std::any_cast<result_t*>(result);
        for (int i = 0; i < N_LAYER_11; ++i)
            result_p[i] = _result[i];
    }
};

extern "C" hls4mlEmulator::Model* create_model() {
    return new topo_emulator_HHbbWW_1mu;
}

extern "C" void destroy_model(hls4mlEmulator::Model* m) {
    delete m;
}
