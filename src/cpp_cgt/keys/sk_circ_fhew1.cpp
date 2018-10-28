#include <fstream>
#include <iostream>

#include "sk_circ_fhew.h"
#include "def_fhew1.h"
#include "ol.h"

using std::cout;

string CircuitPrivKey_fhew::filename() { return PrivKey::filename(); }

CircuitPrivKey_fhew::CircuitPrivKey_fhew
(std::string name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam, &ek), ek(name)
{
    init_final(forceGen, forceLoad);
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
    ek.save();
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

std::string CircuitPrivKey_fhew::encbitstr(bool b) const
{
    ///never("FIXME");
    FhewNativeBit nb(ek.key);
    LWE::CipherText * p = &nb.p->b;
    LWE::Encrypt(p, *e3fhew::tosk(key), int(b));
    return nb.str(ek.key);
}

bool CircuitPrivKey_fhew::decbitstr(const std::string & s, bool * ok) const
{
    never("FIXME");
    //FhewNativeBit nb(s, ek.key);
    //bool r = ( LWE::Decrypt(e3fhew::tosk(sk), b.nb); );
    //return r;
}
