// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "e3util.h"
#include "sk_seal.h"
#include "def_seal0.h"

using std::cout;
using std::string;

namespace e3
{

SealBasePrivKey::SealBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam,
 string polyModulusDegree, string plainModulus, string encoder)
    : PrivKey(name, seed, lam), ek(name)
{
    if ( !polyModulusDegree.empty() )
        this->polyModulusDegree = uint64_t(1) << uint64_t(std::stoull(polyModulusDegree));

    if ( !plainModulus.empty() ) this->plainModulus = uint64_t(std::stoull(plainModulus));
    std::transform( encoder.begin(), encoder.end(), encoder.begin(), [](char c) { return std::tolower(c); } );
    this->isBatch = encoder == "batch";
    init_final(forceGen, forceLoad);
}

string SealBasePrivKey::filename() const
{
    return PrivKey::filename();
}

void SealBasePrivKey::gen()
{
    cout << "Generating keys .. " << std::flush;
    e3seal::SealEvalKey * evalkey_ptr = new e3seal::SealEvalKey;
    e3seal::SealEvalKey & evalkey = *evalkey_ptr;
    evalkey.polyModulusDegree = polyModulusDegree;
    evalkey.plaintextModulus = plainModulus;
    evalkey.isBatchEncoder = isBatch;
    ek.key = evalkey_ptr;
    cout << "ok\n";
}

bool SealBasePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

std::vector<string> SealBasePrivKey::rawDecrypt(const string & c) const
{
    return e3::util::split(c, '_');
}

void SealBasePrivKey::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "SealPrivKey impl:0\n";
    ek.save();
}

} // e3
