// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "olc.h"

#include "ekx_bfv_prot.h"

using std::cout;

void e3::BfvProtEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    std::ofstream of(filename(), std::ios::binary);
//    of << (e3seal::toek(key)->polyModulusDegree) << "\n";
//    of << (e3seal::toek(key)->plaintextModulus ) << "\n";
//    of << int(e3seal::toek(key)->isBatchEncoder) << "\n";
//    of << "SealEvalKey_X impl:0\n";
    of << "e3::BfvProtEvalKeyExt::save() - NI\n";
    cout << "ok\n";
}
