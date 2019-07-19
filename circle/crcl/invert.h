#pragma once

#include <ostream>

#include "olc.h"
#include "crcl.h"

class Invertor
{
        Module & module;
    public:
        Invertor(Module & prog): module(prog) {}
        void invert(std::ostream &);
};

