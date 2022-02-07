// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_tfhe.h"
#include "def_tfhe1.h"

using std::cout;

void e3::CircuitEvalKey_tfhe_X::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    std::ofstream of(filename(), std::ios::binary);
    export_tfheGateBootstrappingCloudKeySet_toStream(of, e3tfhe::toek(key));
    cout << "ok\n";
}
