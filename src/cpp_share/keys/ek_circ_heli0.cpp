// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>

#include "ek_circ_heli.h"

bool e3::CircuitEvalKey_heli::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

std::string e3::CircuitEvalKey_heli::filename() const
{
    return EvalKey::filenamex("_0");
}

