#include <fstream>

#include "ek_circ_heli.h"

bool e3::CircuitEvalKey_heli::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

///std::string CircuitEvalKey_heli::decor(const std::string & s, bool add) const{    return prefix(s, add, "H0");}

std::string e3::CircuitEvalKey_heli::filename() const
{
    return EvalKey::filenamex("_0");
}

