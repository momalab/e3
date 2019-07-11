#include <fstream>

#include "ek_circ_fhew.h"

bool CircuitEvalKey_fhew::load()
{
    std::ifstream in(filename(), std::ios::binary);
    return !!in;
}

///std::string CircuitEvalKey_fhew::decor(const std::string & s, bool add) const
///{
///    return prefix(s, add, "F0");
///}

std::string CircuitEvalKey_fhew::filename() const
{
    return EvalKey::filenamex("_0");
}

