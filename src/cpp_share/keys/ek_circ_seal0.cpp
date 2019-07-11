#include <fstream>

#include "ek_circ_seal.h"

bool e3::CircuitEvalKey_seal::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

std::string e3::CircuitEvalKey_seal::filename() const
{
    return EvalKey::filenamex("_0");
}
