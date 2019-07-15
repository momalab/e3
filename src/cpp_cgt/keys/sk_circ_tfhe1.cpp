#include <fstream>
#include <iostream>

#include "sk_circ_tfhe.h"
#include "def_tfhe1.h"

using std::cout;

string e3::CircuitPrivKey_tfhe::filename() const { return PrivKey::filename(); }

e3::CircuitPrivKey_tfhe::CircuitPrivKey_tfhe
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
///    : CircuitPrivKey(name, seed, lam, &ek), ek(name)
    : CircuitPrivKey(name, seed, lam), ek(name)
{
    init_final(forceGen, forceLoad);
}

void e3::CircuitPrivKey_tfhe::gen()
{
    // first generate SK
    cout << "Generating private key (" << lambda << ") .. " << std::flush;
    TFheGateBootstrappingParameterSet * params =
        new_default_gate_bootstrapping_parameters(lambda);

    const int SZ = 20; // Some size to hold enough number of random bits
    uint32_t seed[SZ];
    for ( int i = 0; i < SZ; i++ ) seed[i] = (uint32_t)(*rnd)();
    tfhe_random_generator_setSeed(seed, SZ);
    auto priv_key = new_random_gate_bootstrapping_secret_keyset(params);
    key = priv_key; // using priv_key to save the type
    cout << "ok\n";

    // now generate EK and set it
    cout << "Generating evaluation key .. " << std::flush;
    std::stringstream cloud_stream;
    export_tfheGateBootstrappingCloudKeySet_toStream(cloud_stream, &priv_key->cloud);
    auto eval_key = new_tfheGateBootstrappingCloudKeySet_fromStream(cloud_stream);
    cout << "ok\n";

    ///ek.setKey(eval_key);
    ek.key = eval_key;
}

void e3::CircuitPrivKey_tfhe::save()
{
    cout << "Saving private key .. " << std::flush;
    {
        std::ofstream of(filename(), std::ios::binary);
        export_tfheGateBootstrappingSecretKeySet_toStream(of, e3tfhe::tosk(key));
    }
    cout << "ok\n";

    ek.save();
}

string CircuitPrivKey_tfhe_load(string s) { return s + ""; }
// (above) dummy function to force tfhe throw exception on error
bool e3::CircuitPrivKey_tfhe::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if (!in) return false;

    TFheGateBootstrappingSecretKeySet * k = nullptr;

    try
    {
        CircuitPrivKey_tfhe_load(filename());
        k = new_tfheGateBootstrappingSecretKeySet_fromStream(in);
    }
    catch (...)
    {
        throw "Loading " + filename() + " failed";
    }

    if (!in)
    {
        std::cout << "File " << filename() << " corrupted\n";
        return false;
    }

    key = k;

    return ek.load();
}

std::string e3::CircuitPrivKey_tfhe::encbitstr(bool b) const
{
    TfheNativeBt nb(ek.key);
    bootsSymEncrypt(&*nb.p, b, e3tfhe::tosk(key));
    return nb.str(ek.key);
}

bool e3::CircuitPrivKey_tfhe::decbitstr(const std::string & s, bool * ok) const
{
    TfheNativeBt nb(s, ek.key);
    bool r = ( bootsSymDecrypt(&*nb.p, e3tfhe::tosk(key) ) > 0 );
    return r;
}
