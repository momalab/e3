#include <fstream>

#include "sk_circ_heli.h"

e3::CircuitPrivKey_heli::CircuitPrivKey_heli
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam), ek(name)
{
    init_final(forceGen, forceLoad);
}

///void e3::CircuitPrivKey_heli::init_properties() {}

void e3::CircuitPrivKey_heli::gen()
{
}

string e3::CircuitPrivKey_heli::filename() const
{
    return PrivKey::filenamex("_0");
}

void e3::CircuitPrivKey_heli::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "CircuitPrivKey_heli impl:0\n";
    ek.save();
}

bool e3::CircuitPrivKey_heli::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

std::string e3::CircuitPrivKey_heli::encbitstr(bool b) const
{
    return b ? "1" : "0";
}

bool e3::CircuitPrivKey_heli::decbitstr(const std::string & s, bool * ok) const
{
    if (ok) *ok = false;
    if ( s.size() != 1 ) return false;
    if (ok) *ok = true;
    if ( s == "0" ) return false;
    if ( s == "1" ) return true;
    if (ok) *ok = false;
    return false;
}

