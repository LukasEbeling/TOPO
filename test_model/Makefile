.PHONY: clean

all: main.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LD_FLAGS) $< -o $@

clean:
	rm main.o
