// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_tfhe.h"

using std::cout;

void e3::CircuitEvalKey_tfhe_X::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << "CircuitEvalKey_tfhe_X impl:0\n";
}
