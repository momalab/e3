// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>
#include <vector>

#include "sk_circ_heli.h"
#include "def_heli1.h"

using std::cout;
using std::vector;

namespace e3
{

CircuitPrivKey_heli::CircuitPrivKey_heli
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam), key(nullptr), ek(name)
{
    init_final(forceGen, forceLoad);
}

vector<bool> CircuitPrivKey_heli::decbitstr(const std::string & s, bool * ok) const
{
    HeliNativeBt nb(s, ek.key);
    ZZX z;
    e3heli::tosk(key)->Decrypt(z, nb.ctxt->b);
    long a = 0;
    NTL::conv(a, z[0]);
    return vector<bool>(1, bool(a));
}

std::string CircuitPrivKey_heli::encbitstr(vector<bool> b) const
{
    HeliNativeBt nb(ek.key);
    e3heli::toek(ek.key)->Encrypt(nb.ctxt->b, to_ZZX(b[0]));
    return nb.str(ek.key);
}

string CircuitPrivKey_heli::filename() const { return PrivKey::filename(); }

void CircuitPrivKey_heli::gen()
{
    init_properties_heli(&properties, name.fil);
    ek.name = name;

    key = new FHESecKey(*properties->pcontext);
    FHESecKey & skey = *e3heli::tosk(key);
    skey.GenSecKey(64);      // A Hamming-weight-64 secret key
    addSome1DMatrices(skey); // compute key-switching matrices that we need
    addFrbMatrices(skey);
    cout << "computing key-dependent tables..." << std::flush;
    skey.genRecryptData();
    cout << " done\n";

    ek.key = key;
}

bool CircuitPrivKey_heli::load()
{
    init_properties_heli(&properties, name.fil);
    ek.name = name;

    key = new FHESecKey(*properties->pcontext);

    FHESecKey & k = *e3heli::tosk(key);
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    in >> k;
    return ek.load();
}

void CircuitPrivKey_heli::save()
{
    FHESecKey & k = *e3heli::tosk(key);
    cout << "Saving private key .. " << std::flush;
    {
        std::ofstream of(filename(), std::ios::binary);
        of << k;
    }
    cout << "ok\n";

    ek.save();
}

} // e3
