#pragma once

#include <ostream>

#include "olc.h"
#include "crcl.h"

///Module invert(const Module & prog);

class Invertor
{
        Module & module;
    public:
        Invertor(Module & prog): module(prog) {}
        void invert(std::ostream &);
};

