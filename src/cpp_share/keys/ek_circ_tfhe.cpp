#ifndef TFHEIMP
#error "define TFHEIMP: 0 or 1"
#endif

#if TFHEIMP == 0
#include "ek_circ_tfhe0.cpp"
#else
#include "ek_circ_tfhe1.cpp"
#endif
