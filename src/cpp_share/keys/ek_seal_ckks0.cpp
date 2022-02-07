// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <iostream>
#include <fstream>

#include "ek_seal_ckks.h"
#include "def_seal_ckks0.h"

using std::stoull;
using std::string;

namespace e3
{

bool SealCkksBaseEvalKey::load(string fname)
{
    std::ifstream in(fname, std::ios::binary);
    string s;
    static e3seal_ckks::SealCkksEvalKey evalkey;
    getline(in, s);
    evalkey.polyModulusDegree = uint64_t( stoull(s) );

    getline(in, s);
    evalkey.scale = uint64_t ( stoull(s) );

    key = &evalkey;
    return !!in;
}

string SealCkksBaseEvalKey::rawEncrypt(const string & s, int msz) const
{
    string tmp = s;
    std::replace(tmp.begin(), tmp.end(), 'o', '.');
    return tmp;
}

size_t SealCkksBaseEvalKey::slots()
{
    const auto & k = e3seal_ckks::toek(key);
    return (size_t)k->polyModulusDegree;
}

} // e3
