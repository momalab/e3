// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <vector>

#include "sk_circ_fhew.h"

using std::vector;

namespace e3
{

CircuitPrivKey_fhew::CircuitPrivKey_fhew
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam), key(nullptr), ek(name)
{
    init_final(forceGen, forceLoad);
}

vector<bool> CircuitPrivKey_fhew::decbitstr(const std::string & s, bool * ok) const
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

std::string CircuitPrivKey_fhew::encbitstr(vector<bool> b) const
{
    return b[0] ? "1" : "0";
}

string CircuitPrivKey_fhew::filename() const
{
    return PrivKey::filenamex("_0");
}

void CircuitPrivKey_fhew::gen()
{
}

bool CircuitPrivKey_fhew::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

void CircuitPrivKey_fhew::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "CircuitPrivKey_fhew impl:0\n";
    ek.save();
}

} // e3
