#include <fstream>
#include <iostream>
#include "sk_circ_seal.h"
#include "def_seal1.h"

using namespace seal;
using std::cout;

string e3::CircuitPrivKey_seal::filename() const { return PrivKey::filename(); }

e3::CircuitPrivKey_seal::CircuitPrivKey_seal
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam), ek(name)
{
    init_final(forceGen, forceLoad);
}

void e3::CircuitPrivKey_seal::gen()
{
    // generate SK
    cout << "Generating private key (" << lambda << ") .. " << std::flush;
    static e3seal::SealPrivKey privkey;
    static e3seal::SealEvalKey evalkey;
    static auto params = EncryptionParameters(scheme_type::BFV);
    cout << " 1 " << std::flush;
    // evalkey.params = EncryptionParameters(scheme_type::BFV);
    size_t polyMod = 1 << 14; // it has to be a power of two
    params.set_poly_modulus_degree(polyMod);
    cout << " 2 " << std::flush;
    params.set_coeff_modulus(CoeffModulus::BFVDefault(polyMod));
    params.set_plain_modulus(1 << 1); // 2
    // static auto context = SEALContext::Create(params);
    evalkey.context = SEALContext::Create(params);
    // static auto keygen = KeyGenerator( context );
    KeyGenerator keygen(evalkey.context);
    static auto encoder = IntegerEncoder(evalkey.context);
    // static auto encoder = IntegerEncoder(context);
    // privkey.encoder = IntegerEncoder(context);
    privkey.secretkey = keygen.secret_key();
    privkey.publickey = keygen.public_key();
    auto static decryptor = Decryptor(evalkey.context, privkey.secretkey);
    auto static encryptor = Encryptor(evalkey.context, privkey.publickey);
    // privkey.decryptor = Decryptor(context, privkey.secretkey);
    // privkey.encryptor = Encryptor(context, privkey.publickey);
    privkey.encoder = &encoder;
    privkey.decryptor = &decryptor;
    privkey.encryptor = &encryptor;
    key = &privkey;
    cout << "ok\n";

    // generate EK and set it
    cout << "Generating evaluation key .. " << std::flush;
    // static e3seal::SealEvalKey evalkey;
    evalkey.params = &params;
    // evalkey.context = context;
    evalkey.relinkeys = keygen.relin_keys();
    ek.key = &evalkey;
    cout << "ok\n";
}

void e3::CircuitPrivKey_seal::save()
{
    cout << "Saving private key .. " << std::flush;
    {
        auto fileSecretKey = filename() + ".secretkey.key";
        auto filePublicKey = filename() + ".publickey.key";
        std::ofstream ofSecretKey(fileSecretKey, std::ios::binary);
        std::ofstream ofPublicKey(filePublicKey, std::ios::binary);
        e3seal::tosk(key)->secretkey.save(ofSecretKey);
        e3seal::tosk(key)->publickey.save(ofPublicKey);
    }
    cout << "ok\n";

    ek.save();
}

string CircuitPrivKey_seal_load(string s) { return s + ""; }
// (above) dummy function to force tfhe throw exception on error
bool e3::CircuitPrivKey_seal::load()
{
    auto fileSecretKey = filename() + ".secretkey.key";
    auto filePublicKey = filename() + ".publickey.key";
    std::ifstream inSecretKey(fileSecretKey, std::ios::binary);
    std::ifstream inPublicKey(filePublicKey, std::ios::binary);
    if (!inSecretKey || !inPublicKey) return false;

    auto r = ek.load();
    if ( !r ) return false;

    static e3seal::SealPrivKey privkey;
    try
    {
        CircuitPrivKey_seal_load(filename());
        static auto context = e3seal::toek(ek.key)->context;
        static auto encoder = IntegerEncoder( context );
        privkey.publickey.load(context, inPublicKey);
        privkey.secretkey.load(context, inSecretKey);
        static auto decryptor = Decryptor( context, privkey.secretkey );
        static auto encryptor = Encryptor( context, privkey.publickey );
        privkey.encoder = &encoder;
        privkey.decryptor = &decryptor;
        privkey.encryptor = &encryptor;
    }
    catch (...)
    {
        throw "Loading " + filename() + " failed";
    }

    key = &privkey;
    return r;
}

std::string e3::CircuitPrivKey_seal::encbitstr(bool b) const
{
    SealNativeBt nb(ek.key);
    auto context = e3seal::toek(ek.key)->context;
    auto encoder = e3seal::tosk(key)->encoder;
    auto publickey = e3seal::tosk(key)->publickey;
    auto encryptor = e3seal::tosk(key)->encryptor;
    Plaintext p = encoder->encode( int(b) );
    encryptor->encrypt(p, nb.p->b );
    return nb.str(ek.key);
}

bool e3::CircuitPrivKey_seal::decbitstr(const std::string & s, bool * ok) const
{
    SealNativeBt nb(s, ek.key);
    auto context = e3seal::toek(ek.key)->context;
    auto encoder = e3seal::tosk(key)->encoder;
    auto secretkey = e3seal::tosk(key)->secretkey;
    auto decryptor = e3seal::tosk(key)->decryptor;
    Plaintext p;
    decryptor->decrypt(nb.p->b, p);
    bool r = ( encoder->decode_int32(p) != 0 );
    return r;
}
