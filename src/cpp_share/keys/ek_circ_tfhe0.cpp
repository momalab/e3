#include <fstream>

#include "ek_circ_tfhe.h"

bool CircuitEvalKey_tfhe::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

std::string CircuitEvalKey_tfhe::decor(const std::string & s, bool add) const
{
    return prefix(s, add, "T0");
}

std::string CircuitEvalKey_tfhe::filename()
{
    std::string old = name;
    name += "_0";
    std::string r = EvalKey::filename();
    name = old;
    return r;
}

