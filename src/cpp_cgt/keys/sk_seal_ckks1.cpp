// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "sk_seal_ckks.h"
#include "def_seal_ckks1.h"

// using namespace seal;
using std::cout;
using std::stoul;
using std::string;
using std::to_string;
using std::tolower;
using std::transform;
using std::vector;


// static forms used here - no multiple Seal keys are possible

namespace e3
{

SealCkksBasePrivKey::SealCkksBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam,
 string polyModulusDegree, string primes, string scale)
    : PrivKey(name, seed, lam), ek(name)
{
    if ( !polyModulusDegree.empty() ) this->polyModulusDegree = uint64_t(1) << stoul(polyModulusDegree);
    if ( !primes.empty() )
    {
        auto p = util::split(primes, ',');
        this->primes.clear();
        for ( auto & e : p ) this->primes.push_back( stoi( util::trim(e) ) );
    }
    if ( !scale.empty() ) this->scale = uint64_t( stoull(scale) );
    init_final(forceGen, forceLoad);
}

string SealCkksBasePrivKey::filename() const
{
    return PrivKey::filename();
}

void SealCkksBasePrivKey::gen()
{
    // generate SK
    cout << "Generating private key (" << lambda << ") .. " << std::flush;
    static e3seal_ckks::SealCkksPrivKey privkey;
#if SEALVER == 332
    static auto params = seal::EncryptionParameters(seal::scheme_type::CKKS);
    static e3seal_ckks::SealCkksEvalKey evalkey;
#else
    static auto params = seal::EncryptionParameters(seal::scheme_type::ckks);
    static e3seal_ckks::SealCkksEvalKey evalkey(params);
#endif
    params.set_poly_modulus_degree(polyModulusDegree);
    params.set_coeff_modulus( seal::CoeffModulus::Create(polyModulusDegree, primes) );
#if SEALVER == 332
    evalkey.context = seal::SEALContext::Create(params);
#else
    evalkey.context = seal::SEALContext(params);
#endif
    seal::KeyGenerator keygen(evalkey.context);
    privkey.secretkey = keygen.secret_key();
    static seal::Decryptor decryptor(evalkey.context, privkey.secretkey);
    privkey.decryptor = &decryptor;
    key = &privkey;
    cout << "ok\n";

    // generate EK and set it
    cout << "Generating evaluation key .. " << std::flush;
#if SEALVER == 332
    evalkey.publickey = keygen.public_key();
    evalkey.relinkeys = keygen.relin_keys();
#else
    keygen.create_public_key(evalkey.publickey);
    keygen.create_relin_keys(evalkey.relinkeys);
#endif
    static seal::Evaluator evaluator(evalkey.context);
    static seal::Encryptor encryptor(evalkey.context, evalkey.publickey);
    static seal::CKKSEncoder encoder(evalkey.context);
    evalkey.encoder = &encoder;
    evalkey.encryptor = &encryptor;
    evalkey.evaluator = &evaluator;
    evalkey.params = &params;
    evalkey.scale = scale;
    ek.key = &evalkey;
    cout << "ok\n";
}

bool SealCkksBasePrivKey::load()
{
    auto fileSecretKey = filename() + ".secretkey.key";
    std::ifstream inSecretKey(fileSecretKey, std::ios::binary);
    if (!inSecretKey) return false;

    auto r = ek.load();
    if ( !r ) return false;

    static e3seal_ckks::SealCkksPrivKey privkey;
    try
    {
        auto & context = e3seal_ckks::toek(ek.key)->context;
        privkey.secretkey.load(context, inSecretKey);
        static seal::Decryptor decryptor(context, privkey.secretkey);
        privkey.decryptor = &decryptor;
    }
    catch (...)
    {
        throw "Loading " + filename() + " failed";
    }

    key = &privkey;
    return r;
}

vector<string> SealCkksBasePrivKey::rawDecrypt(const string & undecorated) const
{
    if (undecorated.empty()) return vector<string>(1, "");
    SealCkksNativeCiphertext nb(undecorated, ek.key);
    auto evalkey = e3seal_ckks::toek(ek.key);
    auto & decryptor = e3seal_ckks::tosk(key)->decryptor;
    auto & encoder = evalkey->encoder;
    seal::Plaintext p;
    vector<string> m;
    decryptor->decrypt(nb.p->ct, p);
    vector<double> v;
    encoder->decode(p, v);
    for ( auto e : v ) m.push_back( to_string(e) );
    return m;
}

void SealCkksBasePrivKey::save()
{
    cout << "Saving private key .. " << std::flush;
    {
        auto fileSecretKey = filename() + ".secretkey.key";
        std::ofstream ofSecretKey(fileSecretKey, std::ios::binary);
        e3seal_ckks::tosk(key)->secretkey.save(ofSecretKey);
    }
    cout << "ok\n";

    ek.save();
}

} // e3
