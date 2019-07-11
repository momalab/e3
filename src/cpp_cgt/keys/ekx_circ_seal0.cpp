#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_seal.h"

using std::cout;

void e3::CircuitEvalKey_seal_X::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << "CircuitEvalKey_seal_X impl:0\n";
}
