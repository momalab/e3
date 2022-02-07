// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_INVAR_H_
#define _E3_INVAR_H_

#include "olc.h"
#include "crcl.h"

namespace e3
{
namespace cr
{

struct V3foot
{
    std::map<std::string, int> v3;
    std::map<std::string, ol::ull> c;
    ol::ull count = 0;
};

void writeProgTbl(std::string file, const Module & prog,
                  V3foot * vf = nullptr);

void findInvariants(std::string file_in, std::string file_ttb,
                    std::string file_out, const Module & prog, bool prgr);

}
} // e3::cr

#endif // _E3_INVAR_H_
