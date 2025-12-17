#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "ap_fixed.h"
#include "emulator.h"

// Constants
constexpr int N_EVENTS = 1000;
constexpr int N_INPUTS = 21;
constexpr int N_OUTPUT = 1;

// File reading function using fixed arrays
void read_csv(const std::string& filename, double data[N_EVENTS][N_INPUTS]) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        throw std::runtime_error("Error opening file: " + filename);
    }

    std::string line;
    int row = 0;

    while (std::getline(infile, line) && row < N_EVENTS) {
        std::istringstream iss(line);
        std::string value;
        int col = 0;

        while (std::getline(iss, value, ',') && col < N_INPUTS) {
            try {
                data[row][col] = std::stod(value);
            } catch (const std::exception&) {
                throw std::runtime_error("Conversion error at row " + std::to_string(row) +
                                         ", col " + std::to_string(col) + " (" + value + ")");
            }
            ++col;
        }

        if (col != N_INPUTS) {
            throw std::runtime_error("Incorrect number of columns at row " + std::to_string(row));
        }
        ++row;
    }

    if (row != N_EVENTS) {
        throw std::runtime_error("Incorrect number of rows. Expected " + std::to_string(N_EVENTS) +
                                 ", got " + std::to_string(row));
    }
}

int main() {
    const std::string filename = "features.txt";

    // Load model
    std::string TOPOmodelversion = "/data/dust/user/ebelingl/TOPO/TOPO_HHbbWW_1mu_v2/topo_HHbbWW_1mu_v2";
    hls4mlEmulator::ModelLoader loader(TOPOmodelversion);
    std::shared_ptr<hls4mlEmulator::Model> model = loader.load_model();

    // Read data into fixed-size array
    double data[N_EVENTS][N_INPUTS];
    try {
        read_csv(filename, data);
        std::cout << "File read successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    ap_fixed<23,23> modelInput[N_INPUTS];
    ap_fixed<16,6> modelResult[N_OUTPUT];

    for (int row = 0; row < N_EVENTS; ++row) {
        for (int i = 0; i < N_INPUTS; ++i) {
            modelInput[i] = data[row][i]; 
        }

        model->prepare_input(modelInput);
        model->predict();
        model->read_result(modelResult);
        std::cout << modelResult[0] << ", ";
    }

    std::cout << "\nProcessing complete.\n";
    return 0;
}
