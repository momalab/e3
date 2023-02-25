// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "sk_seal.h"
#include "def_seal1.h"

// using namespace seal;
using std::cout;
using std::stoull;
using std::string;
using std::to_string;
using std::tolower;
using std::transform;
using std::vector;


namespace e3
{

SealBasePrivKey::SealBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam,
 string polyModulusDegree, string plainModulus, string encoder)
    : PrivKey(name, seed, lam), ek(name)
{
    if ( !polyModulusDegree.empty() ) this->polyModulusDegree = uint64_t(1) << uint64_t(stoull(polyModulusDegree));
    if ( !plainModulus.empty() ) this->plainModulus = uint64_t(stoull(plainModulus));
    std::transform( encoder.begin(), encoder.end(), encoder.begin(), [](char c) { return std::tolower(c); } );
    this->isBatch = encoder == "batch";
    init_final(forceGen, forceLoad);
}

string SealBasePrivKey::filename() const
{
    return PrivKey::filename();
}

void SealBasePrivKey::gen()
{
    // generate SK
    cout << "Generating private key .. " << std::flush;
    e3seal::SealPrivKey * privkey_ptr = new e3seal::SealPrivKey;
    e3seal::SealPrivKey & privkey = *privkey_ptr;


#if SEALVER == 332
    e3seal::SealEvalKey * evalkey_ptr = new e3seal::SealEvalKey;
    e3seal::SealEvalKey & evalkey = *evalkey_ptr;
    evalkey.params = new seal::EncryptionParameters(seal::scheme_type::BFV);
#else
    auto evalkey_params = new seal::EncryptionParameters(seal::scheme_type::bfv);
    e3seal::SealEvalKey * evalkey_ptr = new e3seal::SealEvalKey(*evalkey_params);
    e3seal::SealEvalKey & evalkey = *evalkey_ptr;
    evalkey.params = evalkey_params;
#endif

    auto & params = *evalkey.params;
    params.set_poly_modulus_degree(polyModulusDegree);
    params.set_coeff_modulus(seal::CoeffModulus::BFVDefault(polyModulusDegree));
    params.set_plain_modulus(plainModulus);
#if SEALVER == 332
    evalkey.context = seal::SEALContext::Create(params);
#else
    evalkey.context = seal::SEALContext(params);
#endif

    seal::KeyGenerator keygen(evalkey.context);
    privkey.secretkey = keygen.secret_key();
    privkey.decryptor = new seal::Decryptor(evalkey.context, privkey.secretkey);
    key = privkey_ptr;
    cout << "ok\n";

    // generate EK and set it
    cout << "Generating evaluation key .. " << std::flush;

#if SEALVER == 332
    evalkey.publickey = keygen.public_key();
    evalkey.relinkeys = keygen.relin_keys();
    evalkey.galoiskeys = keygen.galois_keys();
#else
    keygen.create_public_key(evalkey.publickey);
    keygen.create_relin_keys(evalkey.relinkeys);
    keygen.create_galois_keys(evalkey.galoiskeys);
#endif

    evalkey.evaluator = new seal::Evaluator(evalkey.context);
    evalkey.encryptor = new seal::Encryptor(evalkey.context, evalkey.publickey);
    if ( this->isBatch ) evalkey.batchEncoder = new seal::BatchEncoder(evalkey.context);
#if SEALVER == 332
    else evalkey.encoder = new seal::IntegerEncoder(evalkey.context);
#else
    else nevers("No integer encoder supported for this SEAL version");
#endif
    evalkey.isBatchEncoder = isBatch;
    ek.key = evalkey_ptr;
    cout << "ok\n";
}

bool SealBasePrivKey::load()
{
    auto fileSecretKey = filename() + ".secretkey.key";
    std::ifstream inSecretKey(fileSecretKey, std::ios::binary);
    if (!inSecretKey) return false;

    auto r = ek.load();
    if ( !r ) return false;

    e3seal::SealPrivKey * privkey_ptr = new e3seal::SealPrivKey;
    e3seal::SealPrivKey & privkey = *privkey_ptr;

    try
    {
        auto & context = e3seal::toek(ek.key)->context;
        privkey.secretkey.load(context, inSecretKey);
        privkey.decryptor = new seal::Decryptor(context, privkey.secretkey);
    }
    catch (...)
    {
        throw "Loading " + filename() + " failed";
    }

    key = privkey_ptr;
    return r;
}

vector<string> SealBasePrivKey::rawDecrypt(const string & undecorated) const
{
    /// std::cout << __func__ << " INPUT: [" << ( undecorated.size() > 10 ? undecorated.substr(0,10) : undecorated ) << "]\n";
    if (undecorated.empty()) return vector<string>(1, "");
    SealNativeCiphertext nb(undecorated, ek.key);
    auto evalkey = e3seal::toek(ek.key);
    auto & isBatchEncoder = evalkey->isBatchEncoder;
    auto & decryptor = e3seal::tosk(key)->decryptor;
    seal::Plaintext p;
    vector<string> m;
    // std::cout << "DEBUG noise budget: " << decryptor->invariant_noise_budget(nb.p->ct) << "\n";
    decryptor->decrypt(nb.p->ct, p);
    if ( isBatchEncoder )
    {
        auto & encoder = evalkey->batchEncoder;
        vector<uint64_t> v;
        encoder->decode(p, v);
        for ( auto e : v ) m.push_back( to_string(e) );
    }
#if SEALVER == 332
    else m.push_back( to_string( evalkey->encoder->decode_uint64(p) ) );
#else
    else never;
#endif
    /// std::cout << __func__ << " OUTPUT SIZE: [" << m.size() << "]\n";
    return m;
}

void SealBasePrivKey::save()
{
    cout << "Saving private key .. " << std::flush;
    {
        auto fileSecretKey = filename() + ".secretkey.key";
        std::ofstream ofSecretKey(fileSecretKey, std::ios::binary);
        e3seal::tosk(key)->secretkey.save(ofSecretKey);
    }
    cout << "ok\n";

    ek.save();
}

} // e3
