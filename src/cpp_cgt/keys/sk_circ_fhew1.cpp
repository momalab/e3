// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>
#include <vector>

#include "sk_circ_fhew.h"
#include "def_fhew1.h"

using std::cout;
using std::vector;

namespace e3
{

CircuitPrivKey_fhew::CircuitPrivKey_fhew
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam), key(nullptr), ek(name)
{
    init_final(forceGen, forceLoad);
}

std::string CircuitPrivKey_fhew::encbitstr(vector<bool> v) const
{
    auto b = v[0];
    FhewNativeBt nb(ek.key);
    LWE::CipherText * p = &nb.p->b;
    LWE::Encrypt(p, *e3fhew::tosk(key), int(b));
    return nb.str(ek.key);
}

vector<bool> CircuitPrivKey_fhew::decbitstr(const std::string & s, bool * ok) const
{
    FhewNativeBt nb(s, ek.key);
    bool x = (bool)LWE::Decrypt(*e3fhew::tosk(key), nb.p->b);
    return vector<bool>(1, x);
}

string CircuitPrivKey_fhew::filename() const
{
    return PrivKey::filename();
}

void CircuitPrivKey_fhew::gen()
{
    init_properties_fhew();
    static LWE::SecretKey priv;
    key = &priv;

    static FHEW::EvalKey eval;
    ek.key = &eval;

    {
        cout << "Generating private key .. " << std::flush;
        LWE::KeyGen(priv);
        cout << "ok\n";
    }

    // Generate evaluation key (this is slow)
    {
        cout << "Generating evaluation key .. " << std::flush;
        FHEW::KeyGen(&eval, priv);
        cout << "ok\n";
    }
}

bool CircuitPrivKey_fhew::load()
{
    init_properties_fhew();

    cout << "loading PrivKey .. " << std::flush;
    static LWE::SecretKey k;
    key = &k;
    {
        std::ifstream in(filename());
        if ( !in ) { cout << "not present\n"; return false; }

        int x = -1;
        in >> x;
        const char * er = "Bad priv key file";
        if ( x != n )
        {
            cout << "Error: " << er << '\n';
            throw er;
        }

        for ( int i = 0; i < n; i++ ) in >> k[i];

        cout << "ok\n";
    }
    return ek.load();
}

void CircuitPrivKey_fhew::save()
{
    cout << "Saving private key .. " << std::flush;
    auto k = e3fhew::tosk(key);
    {
        std::ofstream of(filename());
        of << n << '\n';
        for ( int i = 0; i < n; i++ ) of << k[i] << ' ';
        of << '\n';
    }
    cout << "ok\n";
    ek.save();
}

} //e3
