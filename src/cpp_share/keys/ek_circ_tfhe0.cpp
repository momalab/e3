// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>

#include "ek_circ_tfhe.h"

bool e3::CircuitEvalKey_tfhe::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

std::string e3::CircuitEvalKey_tfhe::filename() const
{
    return EvalKey::filenamex("_0");
}

