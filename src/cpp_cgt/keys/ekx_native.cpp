// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "ekx_native.h"

void e3::NativeEvalKeyExt::save()
{
    std::ofstream ofs(filename(), std::ios::binary);
    ofs << key << '\n';
}
