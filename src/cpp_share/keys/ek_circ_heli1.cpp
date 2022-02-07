// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>

#include "ek_circ_heli.h"
#include "def_heli1.h"

using std::cout;

bool e3::CircuitEvalKey_heli::load()
{
    init_properties_heli(&properties, name.fil);
    key = new FHEPubKey(*properties->pcontext);

    if (e3heli::PRN)
        std::cout << "loading ek " <<  filename() << " : " << std::flush;

    FHEPubKey & k = *e3heli::toek(key);
    std::ifstream in(filename());

    if ( !in )
    {
        if (e3heli::PRN) std::cout << "failed\n";
        return false;
    }

    in >> k;
    if (e3heli::PRN) std::cout << "done\n";
    return true;
}

std::string e3::CircuitEvalKey_heli::filename() const { return EvalKey::filename(); }
