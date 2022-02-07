// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ekx_seal.h"
#include "def_seal0.h"

using std::cout;

void e3::SealBaseEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    std::ofstream of(filename(), std::ios::binary);
    of << (e3seal::toek(key)->polyModulusDegree) << "\n";
    of << (e3seal::toek(key)->plaintextModulus ) << "\n";
    of << int(e3seal::toek(key)->isBatchEncoder) << "\n";
    of << "SealEvalKey_X impl:0\n";
    cout << "ok\n";
}
