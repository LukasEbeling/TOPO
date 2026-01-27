//Numpy array shape [1]
//Min -0.341796875000
//Max -0.341796875000
//Number of zeros 0

#ifndef B8_H_
#define B8_H_

#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
bias8_t b8[1];
#else
bias8_t b8[1] = {-0.341796875};

#endif

#endif
