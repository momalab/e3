// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <string>
#include <vector>

#include "e3util.h"
#include "def_seal_ckks0.h"

using std::string;
using std::to_string;
using std::vector;

#include <iostream>
std::string e3::SealCkksNativeCiphertext::str() const
{
    if ( p->ct.empty() ) return "";
    string s = to_string(p->ct[0]);
    for ( size_t i = 1; i < p->ct.size(); i++ ) s += "_" + to_string(p->ct[i]);
    return s;
}

namespace e3
{

SealCkksNativeCiphertext::SealCkksNativeCiphertext()
    : p(new SealCkksCiphertext) {}

SealCkksNativeCiphertext::SealCkksNativeCiphertext(const SealCkksNativeCiphertext & a)
    : p(new SealCkksCiphertext)
{
    p->ct = a.p->ct;
}

SealCkksNativeCiphertext::SealCkksNativeCiphertext(const std::string & enc, cSealCkksNativeEvalKey ek)
    : SealCkksNativeCiphertext()
{
    size_t slots = size_t(e3seal_ckks::toek(ek)->polyModulusDegree);
    p->ct = vector<double>(slots, 0);
    auto items = e3::util::split(enc, '_');
    for ( size_t i = 0; i < items.size() && i < slots; i++ ) p->ct[i] = std::stod(items[i]);
}

}
