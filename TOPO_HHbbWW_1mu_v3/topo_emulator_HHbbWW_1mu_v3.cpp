#include "NN/topo_HHbbWW_1mu_v3.h" //include of the top level of HLS model
#include "emulator.h" //include of emulator modeling
#include <any>
#include "ap_fixed.h"
#include "scaling.h"

using namespace hls4ml_topo_HHbbWW_1mu_v3;

class topo_emulator_HHbbWW_1mu_v3 : public hls4mlEmulator::Model {

private:
    unscaled_t _unscaled_input[N_INPUT_1_1];
    input_t _scaled_input[N_INPUT_1_1];
    result_t _result[N_LAYER_11];
    
    virtual void _scaleNNInputs(unscaled_t unscaled[N_INPUT_1_1], input_t scaled[N_INPUT_1_1])
    {
        for (int i = 0; i < N_INPUT_1_1; i++)
        {
        double tmp0 = unscaled[i] - hls4ml_topo_HHbbWW_1mu_v3::bias[i];
        double tmp1 = tmp0 / hls4ml_topo_HHbbWW_1mu_v3::norm[i];
        scaled[i] = static_cast<input_t>(tmp1);
        }
    }

public: 
    virtual void prepare_input(std::any input) {
        unscaled_t *unscaled_input_p = std::any_cast<unscaled_t*>(input);
        for (int i = 0; i < N_INPUT_1_1; i++)
            _unscaled_input[i] = std::any_cast<unscaled_t>(unscaled_input_p[i]);
        _scaleNNInputs(_unscaled_input, _scaled_input);
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
    return new topo_emulator_HHbbWW_1mu_v3;
}

extern "C" void destroy_model(hls4mlEmulator::Model* m) {
    delete m;
}
