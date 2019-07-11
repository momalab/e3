#include <fstream>
#include <iostream>

#include "sk_circ_heli.h"
#include "def_heli1.h"

using std::cout;

string CircuitPrivKey_heli::filename() const { return PrivKey::filename(); }

CircuitPrivKey_heli::CircuitPrivKey_heli
(std::string name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam, &ek), ek(name)
{
    init_final(forceGen, forceLoad);
}

void CircuitPrivKey_heli::gen()
{
    init_properties_heli(&properties, name);
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

bool CircuitPrivKey_heli::load()
{
    init_properties_heli(&properties, name);
    ek.name = name;

    key = new FHESecKey(*properties->pcontext);

    FHESecKey & k = *e3heli::tosk(key);
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    in >> k;
    return ek.load();
}

std::string CircuitPrivKey_heli::encbitstr(bool b) const
{
    HeliNativeBt nb(ek.key);
    e3heli::toek(ek.key)->Encrypt(nb.ctxt->b, to_ZZX(b));
    return nb.str(ek.key);
}

bool CircuitPrivKey_heli::decbitstr(const std::string & s, bool * ok) const
{
    HeliNativeBt nb(s, ek.key);
    ZZX z;
    e3heli::tosk(key)->Decrypt(z, nb.ctxt->b);
    long a = 0;
    NTL::conv(a, z[0]);
    return bool(a);
}
