#include <iostream>
#include <fstream>

#include "ek_arith_seal.h"

using std::cout;

bool e3::SealBaseEvalKey::load(string fname)
{
    std::ifstream in(fname, std::ios::binary);
    return !!in;
}
