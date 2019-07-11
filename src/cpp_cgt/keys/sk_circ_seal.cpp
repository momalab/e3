THIS FILE SHOULD NOT BE USED
IT IS HERE ONLY FOR HISTORICAL REASONS

#ifndef SEALIMP
#error "define SEALIMP: 0 or 1"
#endif

#if SEALIMP == 0
#include "sk_circ_seal0.cpp"
#else
#include "sk_circ_seal1.cpp"
#endif
