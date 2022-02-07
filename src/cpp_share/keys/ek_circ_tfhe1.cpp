// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>

#include "ek_circ_tfhe.h"
#include "def_tfhe1.h"

using std::cout;

bool e3::CircuitEvalKey_tfhe::load()
{
    if (!NOCOUT) cout << "Loading evaluation key .. " << std::flush;
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    try { key = new_tfheGateBootstrappingCloudKeySet_fromStream(in); }
    catch (...) { throw "Bad " + filename() + " eval key"; }
    if (!NOCOUT) cout << "ok\n";
    return true;
}

std::string e3::CircuitEvalKey_tfhe::filename() const { return EvalKey::filename(); }
