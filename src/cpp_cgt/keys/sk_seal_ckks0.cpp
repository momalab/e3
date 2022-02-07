// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>
#include <string>

#include "e3util.h"
#include "sk_seal_ckks.h"
#include "def_seal_ckks0.h"

using std::cout;
using std::string;

namespace e3
{

SealCkksBasePrivKey::SealCkksBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam,
 string polyModulusDegree, string primes, string scale)
    : PrivKey(name, seed, lam), ek(name)
{
    if ( !polyModulusDegree.empty() )
        this->polyModulusDegree = uint64_t(1) << uint64_t(std::stoull(polyModulusDegree));
    if ( !primes.empty() )
    {
        auto p = util::split(primes, ',');
        this->primes.clear();
        for ( auto & e : p ) this->primes.push_back( stoi( util::trim(e) ) );
    }
    if ( !scale.empty() ) this->scale = uint64_t( stoull(scale) );
    init_final(forceGen, forceLoad);
}

string SealCkksBasePrivKey::filename() const
{
    return PrivKey::filename();
}

void SealCkksBasePrivKey::gen()
{
    cout << "Generating keys .. " << std::flush;
    static e3seal_ckks::SealCkksEvalKey evalkey;
    evalkey.polyModulusDegree = polyModulusDegree;
    evalkey.scale = scale;
    ek.key = &evalkey;
    cout << "ok\n";
}

bool SealCkksBasePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

std::vector<string> SealCkksBasePrivKey::rawDecrypt(const string & c) const
{
    return e3::util::split(c, '_');
}

void SealCkksBasePrivKey::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "SealCkksPrivKey impl:0\n";
    ek.save();
}

} // e3
