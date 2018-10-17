THIS FILE SHOULD NOT BE USED
IT IS HERE ONLY FOR HISTORICAL REASONS

#ifndef TFHEIMP
#error "define TFHEIMP: 0 or 1"
#endif

#if TFHEIMP == 0
#include "sk_circ_tfhe0.cpp"
#else
#include "sk_circ_tfhe1.cpp"
#endif
