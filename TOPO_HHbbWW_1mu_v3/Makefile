.PHONY: clean

topo_HHbbWW_1mu_v3.so: topo_emulator_HHbbWW_1mu_v3.o topo_HHbbWW_1mu_v3.o
	$(CXX) $(CXXFLAGS) $(LD_FLAGS) -shared $^ -o $@

%.o: NN/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm topo_emulator_HHbbWW_1mu_v3.o topo_HHbbWW_1mu_v3.o topo_HHbbWW_1mu_v3.so