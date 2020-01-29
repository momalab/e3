// === BEGIN atop.cpp

#include <iostream>
#include <cstdlib>
#include <exception>
#include <vector>

#include "secint.h"
#include "secint.inc"


void abortion()
{
    // the program aborted for some reason (possibly unhandled exception)
    // it may come from anywhere in the program, not necessarily from E3
    std::cout << "\nAbnormal termination\n";
    std::exit(1);
}

namespace
{
int set_abortion() { std::set_terminate(abortion); return 1; }
}

// outside of namespace to suppress warning of not used variable
int abortion_set_variable = set_abortion();

using std::vector;

bool e3::CarryAdd::use = false;
e3::CarryAdd::CarryAdd(): old(use) { use = true; }
e3::CarryAdd::~CarryAdd() { use = old; }

// === END atop.cpp
