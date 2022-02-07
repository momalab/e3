// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_fhew.h"

using std::cout;

void e3::CircuitEvalKey_fhew_X::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << "CircuitEvalKey_fhew_X impl:0\n";
}
