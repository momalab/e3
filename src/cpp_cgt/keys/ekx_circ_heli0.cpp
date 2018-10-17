#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_heli.h"

using std::cout;

void CircuitEvalKey_heli_X::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << "CircuitEvalKey_heli_X impl:0\n";
}
