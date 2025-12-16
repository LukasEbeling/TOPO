CPP_STANDARD := c++17
CXXFLAGS := -O3 -fPIC -std=$(CPP_STANDARD)
PREFIX:=.
EMULATOR_EXTRAS := /cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hls4mlEmulatorExtras/1.1.1-6933fcc7cdb4cdd5a649bd6579151d1b/
AP_TYPES := $(EMULATOR_EXTRAS)/include/ap_types
HLS_ROOT := /cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hls/2019.08-fd724004387c2a6770dc3517446d30d9
HLS4ML_INCLUDE := $(EMULATOR_EXTRAS)/include/hls4ml
NN_INCLUDE := compile/NN
INCLUDES := -I$(HLS4ML_INCLUDE) -I$(AP_TYPES) -I$(HLS_ROOT)/include -I$(NN_INCLUDE)
LD_FLAGS := -L$(EMULATOR_EXTRAS)/lib64 -lemulator_interface

.PHONY: clean

INCLUDES += -I$(CURDIR)/NN

topo_HHbbWW_1mu_v3.so: topo_emulator_HHbbWW_1mu_v3.o topo_HHbbWW_1mu_v3.o
	$(CXX) $(CXXFLAGS) $(LD_FLAGS) -shared $^ -o $@

%.o: NN/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm topo_emulator_HHbbWW_1mu_v3.o topo_HHbbWW_1mu_v3.o topo_HHbbWW_1mu_v3.so