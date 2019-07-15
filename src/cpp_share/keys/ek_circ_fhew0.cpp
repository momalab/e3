#include <fstream>

#include "ek_circ_fhew.h"

bool e3::CircuitEvalKey_fhew::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

///std::string CircuitEvalKey_fhew::decor(const std::string & s, bool add) const
///{
///    return prefix(s, add, "F0");
///}

std::string e3::CircuitEvalKey_fhew::filename() const
{
    return EvalKey::filenamex("_0");
}

