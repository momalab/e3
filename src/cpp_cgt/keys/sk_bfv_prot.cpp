// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#include "e3util.h"
#include "sk_bfv_prot.h"

using std::cout;
using std::string;

namespace e3
{

BfvProtPrivKey::BfvProtPrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam,
 string spolyModulusDegree, string splainModulus, string encoder)
    : PrivKey(name, seed, lam), ek(name)
{
    if ( !spolyModulusDegree.empty() )
        ek.polyModulusDegree = uint64_t(1) << uint64_t(std::stoull(spolyModulusDegree));

    if ( !splainModulus.empty() ) ek.plainModulus = uint64_t(std::stoull(splainModulus));
    std::transform( encoder.begin(), encoder.end(), encoder.begin(), [](char c) { return std::tolower(c); } );
    init_final(forceGen, forceLoad);
}

string BfvProtPrivKey::filename() const
{
    return PrivKey::filename();
}

void BfvProtPrivKey::gen()
{
    cout << "Generating keys .. " << std::flush;
    cout << " BfvProtPrivKey::gen()-NI ";
    cout << "ok\n";
}

bool BfvProtPrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

std::vector<string> BfvProtPrivKey::rawDecrypt(const string & c) const
{
    return e3::util::split(c, '_');
}

void BfvProtPrivKey::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "BfvProtPrivKey::save() - NI\n";
    ek.save();
}

} // e3
