#include <cstdlib>
#include <sstream>
#include <fstream>

#include "ekx_arith_seal.h"

void e3::SealBaseEvalKeyExt::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << "SealEvalKey_X impl:0\n";
}
