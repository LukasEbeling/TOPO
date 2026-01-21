CPP_STANDARD := c++17
CXXFLAGS := -O3 -fPIC -std=$(CPP_STANDARD)
PREFIX:=.
# EMULATOR_EXTRAS := /cvmfs/cms.cern.ch/el9_amd64_gcc13/external/hls4mlEmulatorExtras/1.1.4-303c71b78d29ea8c7700bea5268fd011/
EMULATOR_EXTRAS := ../../hls4mlEmulatorExtras
AP_TYPES := $(EMULATOR_EXTRAS)/include/ap_types
# HLS_ROOT := /cvmfs/cms.cern.ch/el9_amd64_gcc13/external/hls/2025.05-bf66465791178392d0ccc731a47dd76b
HLS_ROOT := ../../hls
HLS4ML_INCLUDE := $(EMULATOR_EXTRAS)/include/hls4ml
INCLUDES := -I$(HLS4ML_INCLUDE) -I$(AP_TYPES) -I$(HLS_ROOT)/include
LD_FLAGS := -L$(EMULATOR_EXTRAS)/lib64 -lemulator_interface
ALL_VERSIONS:=TOPO_HHbbWW_1mu_v2/topo_HHbbWW_1mu_v2.so TOPO_HHbbWW_1mu_v3/topo_HHbbWW_1mu_v3.so TOPO_HHbbWW_1mu_v4/topo_HHbbWW_1mu_v4.so

.DEFAULT_GOAL := all
.PHONY: all clean install

all: $(ALL_VERSIONS)
	@cp $(ALL_VERSIONS) ./
	@echo All OK

install: all
	@rm -rf $(PREFIX)/lib64
	@mkdir -p $(PREFIX)/lib64
	cp topo_*.so $(PREFIX)/lib64

%.so:
	$(MAKE) -C $(@D) INCLUDES="$(INCLUDES)" LD_FLAGS="$(LD_FLAGS)" CXXFLAGS="$(CXXFLAGS)"

clean:
	rm topo_*.so TOPO_HHbbWW_1mu_v*/*.o TOPO_HHbbWW_1mu_v*/*.so
