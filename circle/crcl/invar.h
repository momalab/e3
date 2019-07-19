#pragma once

#include "olc.h"
#include "crcl.h"

struct V3foot
{
    std::map<string, int> v3;
    std::map<string, ol::ull> c;
    ol::ull count = 0;
};

void writeProgTbl(string file, const Module & prog,
                  V3foot * vf = nullptr);

void findInvariants(string file_in, string file_ttb,
                    string file_out, const Module & prog, bool prgr);

