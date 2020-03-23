#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "sk_seal.h"
#include "def_seal1.h"

using namespace seal;
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
    transform( encoder.begin(), encoder.end(), encoder.begin(), [](unsigned char const & c) { return ::tolower(c); } );
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
    static e3seal::SealPrivKey privkey;
    static e3seal::SealEvalKey evalkey;
    static auto params = EncryptionParameters(scheme_type::BFV);
    params.set_poly_modulus_degree(polyModulusDegree);
    params.set_coeff_modulus(CoeffModulus::BFVDefault(polyModulusDegree));
    params.set_plain_modulus(plainModulus);
    evalkey.context = SEALContext::Create(params);
    KeyGenerator keygen(evalkey.context);
    privkey.secretkey = keygen.secret_key();
    static Decryptor decryptor(evalkey.context, privkey.secretkey);
    privkey.decryptor = &decryptor;
    key = &privkey;
    cout << "ok\n";

    // generate EK and set it
    cout << "Generating evaluation key .. " << std::flush;
    evalkey.publickey = keygen.public_key();
    evalkey.relinkeys = keygen.relin_keys();
    static Evaluator evaluator(evalkey.context);
    static Encryptor encryptor(evalkey.context, evalkey.publickey);
    static IntegerEncoder encoder(evalkey.context);
    if ( this->isBatch )
    {
        static BatchEncoder batchEncoder(evalkey.context);
        evalkey.batchEncoder = &batchEncoder;
    }
    evalkey.isBatchEncoder = isBatch;
    evalkey.encoder = &encoder;
    evalkey.encryptor = &encryptor;
    evalkey.evaluator = &evaluator;
    evalkey.params = &params;
    ek.key = &evalkey;
    cout << "ok\n";
}

bool SealBasePrivKey::load()
{
    auto fileSecretKey = filename() + ".secretkey.key";
    std::ifstream inSecretKey(fileSecretKey, std::ios::binary);
    if (!inSecretKey) return false;

    auto r = ek.load();
    if ( !r ) return false;

    static e3seal::SealPrivKey privkey;
    try
    {
        auto & context = e3seal::toek(ek.key)->context;
        privkey.secretkey.load(context, inSecretKey);
        static Decryptor decryptor(context, privkey.secretkey);
        privkey.decryptor = &decryptor;
    }
    catch (...)
    {
        throw "Loading " + filename() + " failed";
    }

    key = &privkey;
    return r;
}

vector<string> SealBasePrivKey::rawDecrypt(const string & undecorated) const
{
    if (undecorated.empty()) return vector<string>(1, "");
    SealNativeCiphertext nb(undecorated, ek.key);
    auto evalkey = e3seal::toek(ek.key);
    auto & isBatchEncoder = evalkey->isBatchEncoder;
    auto & decryptor = e3seal::tosk(key)->decryptor;
    Plaintext p;
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
    else m.push_back( to_string( evalkey->encoder->decode_uint64(p) ) );
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
