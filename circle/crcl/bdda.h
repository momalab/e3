// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_BDDA_H_
#define _E3_BDDA_H_

#include "olc.h"
#include "crcl.h"

namespace e3
{
namespace cr
{

void writeBDD(std::string file, const Module & prog, bool dot, bool reord);
int cudd_impl(); // returns 0 or 1

}
} // e3::cr

#endif // _E3_BDDA_H_
