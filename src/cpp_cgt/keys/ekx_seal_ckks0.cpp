// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
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
    const auto & k = e3seal_ckks::toek(key);
    std::ofstream of(filename(), std::ios::binary);
    of << (k->polyModulusDegree) << "\n";
    of << (k->scale) << "\n";
    of << "SealCkksEvalKey_X impl:0\n";
    cout << "ok\n";
}
