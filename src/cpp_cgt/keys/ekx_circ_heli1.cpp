// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_heli.h"
#include "def_heli1.h"

using std::cout;

void e3::CircuitEvalKey_heli_X::save()
{
    FHEPubKey & k = *e3heli::toek(key);

    cout << "Saving evaluation key .. " << std::flush;
    std::ofstream of(filename(), std::ios::binary);
    of << k;
    cout << "ok\n";
}
