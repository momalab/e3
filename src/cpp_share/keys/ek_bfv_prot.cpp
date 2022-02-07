// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>

#include "ek_bfv_prot.h"

using std::stoi;
using std::stoull;
using std::string;

namespace e3
{

bool BfvProtEvalKey::load(string fname)
{
    std::cout << "ek_bfv_prot.cpp BfvProtEvalKey::load - NI\n";
    return false;
}

string BfvProtEvalKey::rawEncrypt(const string & s, int) const
{
    // FIXME refactor with SEAL
    string strout;
    if ( nslots > 1 )
    {
        auto v = e3::util::split(s, '_');
        auto & nnslots = polyModulusDegree;
        v.resize(size_t(nnslots), v.back());
        strout = e3::util::merge(v, "_");
    }
    else strout = s;
    return strout;

}

size_t BfvProtEvalKey::slots()
{
    return nslots;
}

} // e3
