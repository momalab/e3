// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN atop.cpp

#include <iostream>
#include <cstdlib>
#include <exception>
#include <vector>
#include <iomanip>
#include <fstream>

#include "secint.h"
#include "secint.inc"

void abortion()
{
    std::cout << "\nInternal error on E3 or underlying 3rd party library";
    std::cout << "\nTo catch exception recompile with E3NOABORT\n";
    std::exit(1);
}

namespace e3local
{
int set_abortion() { std::set_terminate(abortion); return 1; }
}

#ifndef E3NOABORT
int abortion_set_variable = e3local::set_abortion();
#endif


using std::vector;

bool e3::CarryAdd::use = false;
e3::CarryAdd::CarryAdd(): old(use) { use = true; }
e3::CarryAdd::~CarryAdd() { use = old; }

// === END atop.cpp
