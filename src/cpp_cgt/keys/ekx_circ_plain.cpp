// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "ekx_circ_plain.h"

void e3::CircuitEvalKey_plain_X::save()
{
    std::ofstream ofs(filename(), std::ios::binary);
    ofs << key << '\n';
}
