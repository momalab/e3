// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <vector>

#include "sk_circ_tfhe.h"

using std::vector;

namespace e3
{

CircuitPrivKey_tfhe::CircuitPrivKey_tfhe
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam), ek(name)
{
    init_final(forceGen, forceLoad);
}

vector<bool> CircuitPrivKey_tfhe::decbitstr(const std::string & s, bool * ok) const
{
    vector<bool> m(1, false);
    if (ok) *ok = false;
    if ( s.size() == 1 )
    {
        if (ok) *ok = true;
        m[0] = s == "1";
    }
    return m;
}

std::string CircuitPrivKey_tfhe::encbitstr(vector<bool> b) const
{
    return b[0] ? "1" : "0";
}

string CircuitPrivKey_tfhe::filename() const
{
    return PrivKey::filenamex("_0");
}

void CircuitPrivKey_tfhe::gen()
{
}

bool CircuitPrivKey_tfhe::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

void CircuitPrivKey_tfhe::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "CircuitPrivKey_tfhe impl:0\n";
    ek.save();
}

} // e3
