#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ekx_seal_ckks.h"
#include "def_seal_ckks0.h"

using std::cout;

void e3::SealCkksBaseEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    std::ofstream of(filename(), std::ios::binary);
    of << (e3seal_ckks::toek(key)->polyModulusDegree) << "\n";
    of << "SealCkksEvalKey_X impl:0\n";
    cout << "ok\n";
}
