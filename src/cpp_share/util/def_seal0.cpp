// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <string>
#include <vector>

#include "e3util.h"
#include "def_seal0.h"

using std::string;
using std::to_string;
using std::vector;

int e3::seal_impl() { return 0; }
std::string e3::SealNativeCiphertext::str() const
{
    if ( p->ct.empty() ) return "";
    string s = to_string(p->ct[0]);
    for ( size_t i = 1; i < p->ct.size(); i++ ) s += "_" + to_string(p->ct[i]);
    return s;
}

namespace e3
{

SealNativeCiphertext::~SealNativeCiphertext()
{
	std::ignore = std::ignore;
}

SealNativeCiphertext::SealNativeCiphertext()
    : p(new SealCiphertext) {}

SealNativeCiphertext::SealNativeCiphertext(const SealNativeCiphertext & a)
    : p(new SealCiphertext)
{
    p->ct = a.p->ct;
}

SealNativeCiphertext::SealNativeCiphertext(const std::string & enc, cSealNativeEvalKey ek)
    : SealNativeCiphertext()
{
    const auto & k = e3seal::toek(ek);
    size_t slots = size_t(k->isBatchEncoder ? k->polyModulusDegree : 1);
    p->ct = vector<uint64_t>(slots, 0);
    auto items = e3::util::split(enc, '_');
    for ( size_t i = 0; i < items.size() && i < slots; i++ ) p->ct[i] = uint64_t( std::stoull(items[i]) );
}

}
