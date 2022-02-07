// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_INVERT_H_
#define _E3_INVERT_H_

#include <ostream>

#include "olc.h"
#include "crcl.h"

namespace e3
{
namespace cr
{

class Invertor
{
        Module & module;
    public:
        Invertor(Module & prog): module(prog) {}
        void invert(std::ostream &);
};

}
} // e3::cr

#endif // _E3_INVERT_H_
