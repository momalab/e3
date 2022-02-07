// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>

#include "def_palisade_ckks0.h"
#include "ekx_palisade_ckks.h"

namespace e3
{

void PalisadeCkksEvalKeyExt::save()
{
    std::ofstream fout( filename(), std::ios::binary );
    fout << multDepth       << '\n';
    fout << scaleFactorBits << '\n';
    fout << batchSize       << '\n';
    fout << securityLevel   << '\n';
    fout << ringDimension   << '\n';
}

} // e3
