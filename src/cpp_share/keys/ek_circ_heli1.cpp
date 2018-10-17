#include <fstream>
#include <iostream>

#include "ek_circ_heli.h"
#include "def_heli1.h"

using std::cout;

bool CircuitEvalKey_heli::load()
{
    throw "CircuitEvalKey_heli::load()";
}

std::string CircuitEvalKey_heli::decor(const std::string & s, bool add) const
{
    return prefix(s, add, "H");
}

std::string CircuitEvalKey_heli::filename() { return EvalKey::filename(); }
