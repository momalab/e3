#include <fstream>
#include <iostream>
#include <string>

#include "sk_arith_seal.h"
#include "def_seal1.h"

using namespace seal;
using std::cout;
using std::stoul;
using std::string;
using std::to_string;

e3::SealBasePrivKey::SealBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam, string polyModulusDegree, string plainModulus)
    : PrivKey(name, seed, lam), ek(name)
{
    this->polyModulusDegree = 1 << stoul(polyModulusDegree);
    this->plainModulus = stoul(plainModulus);
    init_final(forceGen, forceLoad);
}

string e3::SealBasePrivKey::filename() const
{
    return PrivKey::filename();
}

void e3::SealBasePrivKey::gen()
{
    // generate SK
    cout << "Generating private key (" << lambda << ") .. " << std::flush;
    static e3seal::SealPrivKey privkey;
    static e3seal::SealEvalKey evalkey;
    static auto params = EncryptionParameters(scheme_type::BFV);
    params.set_poly_modulus_degree(polyModulusDegree);
    params.set_coeff_modulus(CoeffModulus::BFVDefault(polyModulusDegree));
    params.set_plain_modulus(plainModulus);
    evalkey.context = SEALContext::Create(params);
    KeyGenerator keygen(evalkey.context);
    ///static auto encoder = IntegerEncoder(evalkey.context);
    static IntegerEncoder encoder(evalkey.context);
    privkey.secretkey = keygen.secret_key();
    privkey.publickey = keygen.public_key();
    ///auto static decryptor = Decryptor(evalkey.context, privkey.secretkey);
    ///auto static encryptor = Encryptor(evalkey.context, privkey.publickey);
    static Decryptor decryptor(evalkey.context, privkey.secretkey);
    static Encryptor encryptor(evalkey.context, privkey.publickey);
    privkey.encoder = &encoder;
    privkey.decryptor = &decryptor;
    privkey.encryptor = &encryptor;
    key = &privkey;
    cout << "ok\n";

    // generate EK and set it
    cout << "Generating evaluation key .. " << std::flush;
    static Evaluator evaluator(evalkey.context);
    evalkey.relinkeys = keygen.relin_keys();
    evalkey.params = &params;
    evalkey.evaluator = &evaluator;
    ek.key = &evalkey;
    cout << "ok\n";
}

void e3::SealBasePrivKey::save()
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

bool e3::SealBasePrivKey::load()
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
        auto context = e3seal::toek(ek.key)->context;
        ///static auto encoder = IntegerEncoder( context );
    static IntegerEncoder encoder(context);
        privkey.publickey.load(context, inPublicKey);
        privkey.secretkey.load(context, inSecretKey);
        ///static auto decryptor = Decryptor( context, privkey.secretkey );
        ///static auto encryptor = Encryptor( context, privkey.publickey );
    static Decryptor decryptor(context, privkey.secretkey);
    static Encryptor encryptor(context, privkey.publickey);
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

string e3::SealBasePrivKey::decrypt(const string & c) const
{
    SealNativeCiphertext nb(ek.key);
    auto context = e3seal::toek(ek.key)->context;
    auto encoder = e3seal::tosk(key)->encoder;
    auto publickey = e3seal::tosk(key)->publickey;
    auto encryptor = e3seal::tosk(key)->encryptor;
    Plaintext p = encoder->encode( stoull(c) );
    encryptor->encrypt(p, nb.p->b );
    auto r = ek.decor(nb.str(ek.key), false);
    cout << "Dec(" << c << "): " << r << "\n";
    return r;
}

string e3::SealBasePrivKey::encrypt(const string & s, int msz) const
{
    SealNativeCiphertext nb(s, ek.key);
    auto context = e3seal::toek(ek.key)->context;
    auto encoder = e3seal::tosk(key)->encoder;
    auto secretkey = e3seal::tosk(key)->secretkey;
    auto decryptor = e3seal::tosk(key)->decryptor;
    Plaintext p;
    decryptor->decrypt(nb.p->b, p);
    auto r = ek.decor(to_string( encoder->decode_uint64(p) ), true);
    cout << "Enc(" << s << "): " << r << "\n";
    return r;
}
