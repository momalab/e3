// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>
#include <vector>

#include "ek_seal.h"
#include "def_seal1.h"

// using namespace seal;
using std::cout;
using std::stoull;
using std::string;
using std::vector;

namespace e3
{

bool SealBaseEvalKey::load(string fname)
{
    if (!NOCOUT) cout << "Loading evaluation key .. " << std::flush;

    auto fileParams = fname + ".params.key";
    auto filePublicKey = fname + ".publickey.key";
    auto fileRelin  = fname + ".relin.key";
    auto fileGalois = fname + ".galois.key";
    auto fileConfig = fname + ".config.key";
    std::ifstream inParams(fileParams, std::ios::binary);
    std::ifstream inPublicKey(filePublicKey, std::ios::binary);
    std::ifstream inRelin (fileRelin , std::ios::binary);
    std::ifstream inGalois(fileGalois, std::ios::binary);
    std::ifstream inConfig(fileConfig, std::ios::binary);
    if ( !inParams || !inPublicKey || !inRelin || !inConfig ) return false;

#if SEALVER == 332
    e3seal::SealEvalKey * ekey = new e3seal::SealEvalKey;
    e3seal::SealEvalKey & evalkey = *ekey;
    try
    {
        unsigned char be;
        inConfig.read(reinterpret_cast<char *>(&be), 1);
        evalkey.isBatchEncoder = be == 1;
        auto params = seal::EncryptionParameters::Load(inParams);
        evalkey.context = seal::SEALContext::Create(params);
        evalkey.publickey.load(evalkey.context, inPublicKey);
        evalkey.relinkeys.load(evalkey.context, inRelin);
        evalkey.galoiskeys.load(evalkey.context, inGalois);
        evalkey.evaluator = new seal::Evaluator(evalkey.context);
        evalkey.encryptor = new seal::Encryptor(evalkey.context, evalkey.publickey);
        if ( evalkey.isBatchEncoder ) evalkey.batchEncoder = new seal::BatchEncoder(evalkey.context);
        else evalkey.encoder = new seal::IntegerEncoder(evalkey.context);
        evalkey.params = &params;
    }
    catch (...) { throw "Bad " + fname + " eval key"; }
    key = ekey;
#else
    try
    {
        seal::EncryptionParameters params;
        params.load(inParams);
        e3seal::SealEvalKey * ekey = new e3seal::SealEvalKey(params);
        e3seal::SealEvalKey & evalkey = *ekey;
        unsigned char be;
        inConfig.read(reinterpret_cast<char *>(&be), 1);
        evalkey.isBatchEncoder = be == 1;
        evalkey.context = seal::SEALContext(params);
        evalkey.publickey.load(evalkey.context, inPublicKey);
        evalkey.relinkeys.load(evalkey.context, inRelin);
        evalkey.galoiskeys.load(evalkey.context, inGalois);
        evalkey.evaluator = new seal::Evaluator(evalkey.context);
        evalkey.encryptor = new seal::Encryptor(evalkey.context, evalkey.publickey);
        if ( evalkey.isBatchEncoder ) evalkey.batchEncoder = new seal::BatchEncoder(evalkey.context);
        else throw "no seal::IntegerEncoder - "+fname;
        evalkey.params = &params;
        key = ekey;
    }
    catch (...) { throw "Bad " + fname + " eval key"; }
#endif


    if (!NOCOUT) cout << "ok\n";
    return true;
}

string SealBaseEvalKey::rawEncrypt(const string & s, int) const
{
    SealNativeCiphertext nb;
    auto evalkey = e3seal::toek(key);
    auto & isBatchEncoder = evalkey->isBatchEncoder;
    auto & encryptor = evalkey->encryptor;
    seal::Plaintext p;
    if ( isBatchEncoder )
    {
        auto & encoder = evalkey->batchEncoder;
        // vector<uint64_t> v( encoder->slot_count(), 0LL );
        auto vs = e3::util::split(s, '_');
        vector<uint64_t> v;
        for ( auto e : vs ) v.push_back( stoull(e) );
        v.resize( encoder->slot_count(), v.back() );
        // string tmp = "";
        // size_t idx = 0;
        // for ( auto c : s )
        // {
        //     if ( c == '_' )
        //     {
        //         v[idx++] = stoull(tmp);
        //         tmp = "";
        //     }
        //     else tmp += c;
        // }
        // uint64_t value = stoull(tmp);
        // v[idx++] = value;
        // while ( idx < v.size() ) v[idx++] = value; // repeat the last value to the end
        encoder->encode(v, p);
    }
#if SEALVER == 332
    else p = evalkey->encoder->encode( (uint64_t) stoull(s) );
#else
    else throw "no seal::IntegerEncoder - "+s;
#endif
    encryptor->encrypt(p, nb.p->ct);
    return nb.str();
}

size_t SealBaseEvalKey::slots()
{
    const auto & k = e3seal::toek(key);
    bool isB = k->isBatchEncoder;
    return size_t(isB ? k->batchEncoder->slot_count() : 1);
}

uint64_t SealBaseEvalKey::getPlaintextModulus() const
{
    return e3seal::toek(key)->getPlaintextModulus();
}

} // e3
