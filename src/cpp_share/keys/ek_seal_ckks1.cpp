#include <iostream>
#include <fstream>
#include <vector>

#include "ek_seal_ckks.h"
#include "def_seal_ckks1.h"

using namespace seal;
using std::cout;
using std::stoull;
using std::string;
using std::vector;

namespace e3
{

bool SealCkksBaseEvalKey::load(string fname)
{
    if (!NOCOUT) cout << "Loading evaluation key .. " << std::flush;

    auto fileParams = fname + ".params.key";
    auto filePublicKey = fname + ".publickey.key";
    auto fileRelin  = fname + ".relin.key";
    // auto fileConfig = fname + ".config.key";
    std::ifstream inParams(fileParams, std::ios::binary);
    std::ifstream inPublicKey(filePublicKey, std::ios::binary);
    std::ifstream inRelin (fileRelin , std::ios::binary);
    // std::ifstream inConfig(fileConfig, std::ios::binary);
    // if ( !inParams || !inPublicKey || !inRelin || !inConfig ) return false;
    if ( !inParams || !inPublicKey || !inRelin ) return false;

    static e3seal_ckks::SealCkksEvalKey evalkey;
    try
    {
        // unsigned char be;
        // inConfig.read(reinterpret_cast<char *>(&be), 1);
        // evalkey.isBatchEncoder = be == 1;
        static auto params = EncryptionParameters::Load(inParams);
        evalkey.context = SEALContext::Create(params);
        evalkey.publickey.load(evalkey.context, inPublicKey);
        evalkey.relinkeys.load(evalkey.context, inRelin);
        static Evaluator evaluator(evalkey.context);
        static Encryptor encryptor(evalkey.context, evalkey.publickey);
        // static IntegerEncoder encoder(evalkey.context);
        static CKKSEncoder encoder(evalkey.context);
        evalkey.encoder = &encoder;
        evalkey.encryptor = &encryptor;
        evalkey.evaluator = &evaluator;
        evalkey.params = &params;
    }
    catch (...) { throw "Bad " + fname + " eval key"; }

    key = &evalkey;

    if (!NOCOUT) cout << "ok\n";
    return true;
}

string SealCkksBaseEvalKey::rawEncrypt(const string & s, int msz) const
{
    SealCkksNativeCiphertext nb;
    auto evalkey = e3seal_ckks::toek(key);
    // auto & isBatchEncoder = evalkey->isBatchEncoder;
    auto & encryptor = evalkey->encryptor;
    auto & encoder = evalkey->encoder;
    Plaintext p;
    vector<double> v( encoder->slot_count(), 0LL );
    string tmp = "";
    size_t idx = 0;
    for ( auto c : s )
    {
        if ( c == '_' )
        {
            v[idx++] = stod(tmp);
            tmp = "";
        }
        else if ( c == 'o' ) tmp += '.';
        else tmp += c;
    }
    auto value = stod(tmp);
    while ( idx < v.size() ) v[idx++] = value; // repeat the last value to the end
    double scale = pow(2.0, 40); // FIXME e add scale to config file
    encoder->encode(v, scale, p);
    encryptor->encrypt(p, nb.p->ct);
    return nb.str();
}

size_t SealCkksBaseEvalKey::slots()
{
    const auto & k = e3seal_ckks::toek(key);
    return k->encoder->slot_count();
}

} // e3
