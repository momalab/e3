#include <fstream>

#include "sk_circ_fhew.h"

CircuitPrivKey_fhew::CircuitPrivKey_fhew
(std::string name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam, &ek), ek(name)
{
    init_final(forceGen, forceLoad);
}

void CircuitPrivKey_fhew::gen()
{
}

string CircuitPrivKey_fhew::filename() const
{
    return PrivKey::filenamex("_0");
}

void CircuitPrivKey_fhew::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "CircuitPrivKey_fhew impl:0\n";
    ek.save();
}

bool CircuitPrivKey_fhew::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

std::string CircuitPrivKey_fhew::encbitstr(bool b) const
{
    return b ? "1" : "0";
}

bool CircuitPrivKey_fhew::decbitstr(const std::string & s, bool * ok) const
{
    if (ok) *ok = false;
    if ( s.size() != 1 ) return false;
    if (ok) *ok = true;
    if ( s == "0" ) return false;
    if ( s == "1" ) return true;
    if (ok) *ok = false;
    return false;
}

