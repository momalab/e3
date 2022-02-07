// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <complex>
#include <sstream>
#include <vector>
#include "palisade.h"

// Palisade serialization
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "pubkeylp-ser.h"
#include "scheme/ckks/ckks-ser.h"
#include "utils/serialize-binary.h"

#include "e3util.h"
#include "base64.h"
#include "def_palisade_ckks1.h"

using namespace std;

namespace e3
{

namespace palisade_ckks
{

using namespace lbcrypto;

// local variables

const string    CT_EXT = ".ct";      // ciphertext
const string   CTX_EXT = ".ctx.key"; // crypto context
const string   MUL_EXT = ".mul.key"; // multiplication keys
const string PARAM_EXT = ".par.key"; // parameters
const string   PUB_EXT = ".pub.key"; // public key
const string   ROT_EXT = ".rot.key"; // rotation keys

// local functions

RescalingTechnique getRescalingTechnique(const string & rescale)
{
    if ( rescale == "exact" ) return EXACTRESCALE;
    if ( rescale == "approx") return APPROXAUTO;
    throw "Rescaling technique not supported.";
}

SecurityLevel getSecurityLevel(int securityLevel)
{
    switch (securityLevel)
    {
        case   0: return HEStd_NotSet;
        case 128: return HEStd_128_classic;
        case 192: return HEStd_192_classic;
        case 256: return HEStd_256_classic;
    }
    throw "Invalid security level (" + std::to_string(securityLevel) + ")." +
    " It must have one of the following values: 0, 128, 192, 256.";
}

// header functions

string ciphertextToString(Ciphertext_t & ciphertext)
{
    ostringstream os;
    Serial::Serialize(ciphertext, os, SerType::BINARY);
    return os.str();
}

template <class T> T decrypt(Context & context, SecretKey & secretKey, Ciphertext_t & ciphertext, int size)
{
    throw string() + "Specialization for " + typeid(T).name() + " not implemented (def_palisade_ckks1.cpp::decrypt)";
}

template <> vector<std::complex<double>> decrypt(Context & context, SecretKey & secretKey, Ciphertext_t & ciphertext, int size)
{
    Plaintext_t plaintext = decrypt(context, secretKey, ciphertext);
    plaintext->SetLength(size);
    return plaintext->GetCKKSPackedValue();
}

template <> vector<double> decrypt(Context & context, SecretKey & secretKey, Ciphertext_t & ciphertext, int size)
{
    Plaintext_t plaintext = decrypt(context, secretKey, ciphertext);
    plaintext->SetLength(size);
    return plaintext->GetRealPackedValue();
}

Plaintext_t decrypt(Context & context, SecretKey & secretKey, Ciphertext_t & ciphertext)
{
    Plaintext_t plaintext;
    context->Decrypt(secretKey, ciphertext, &plaintext);
    return plaintext;
}

Ciphertext_t encrypt(Context & context, PublicKey & publicKey, const vector<double> & vectorPlaintext)
{
    Plaintext_t plaintext = context->MakeCKKSPackedPlaintext(vectorPlaintext);
    return context->Encrypt(publicKey, plaintext);
}

Ciphertext_t encrypt(Context & context, PublicKey & publicKey, const vector<complex<double>> & vectorPlaintext)
{
    Plaintext_t plaintext = context->MakeCKKSPackedPlaintext(vectorPlaintext);
    auto v = plaintext->GetCKKSPackedValue();
    return context->Encrypt(publicKey, plaintext);
}

Keys generateKeys(Context & context, const string & rotations)
{
    vector<int> vrot;
    if ( rotations == "none" ) {} // do nothing
    else if ( rotations == "all" )
    {
        auto size = int(context->GetRingDimension() >> 1);
        for ( int i = 0; i < size; i++ )
        {
            vrot.push_back(-i);
            vrot.push_back(i);
        }
    }
    else if ( rotations == "powers2" )
    {
        auto size = int(context->GetRingDimension() >> 1);
        for ( int i = 1; i < size; i <<= 1 ) vrot.push_back(i);
    }
    else
    {
        try
        {
            auto vs = e3::util::split(rotations, ',');
            for ( auto & s : vs ) vrot.push_back( std::stoi(s) );
        }
        catch (...) { throw "Invalid rotation keys. Check the configuration file."; }
    }
    auto keys = context->KeyGen();
    context->EvalMultKeyGen(keys.secretKey);
    context->EvalAtIndexKeyGen(keys.secretKey, vrot);
    return keys;
}

bool isLoadPublicKeyPossible(const string & filename)
{
    auto f1 = filename + PUB_EXT;
    auto f2 = filename + CTX_EXT;
    ifstream in1(f1), in2(f2);
    return !!in1 && !!in2;
}

Ciphertext_t loadCiphertext(const string & filename)
{
    auto file = filename + CT_EXT;
    Ciphertext_t ciphertext;
    if ( !Serial::DeserializeFromFile(file, ciphertext, SerType::BINARY) )
        throw "Error reading ciphertext from " + file;
    return ciphertext;
}

Context loadContext(const string & filename)
{
    auto file = filename + CTX_EXT;
    // CryptoContextFactory<DCRTPoly>::ReleaseAllContexts();
    Context context;
    if ( !Serial::DeserializeFromFile(file, context, SerType::BINARY) )
        throw "Could not read serialization from " + file;
    return context;
}

void loadEvaluationKey(Context & context, const string & filename)
{
    context->ClearEvalMultKeys();
    context->ClearEvalAutomorphismKeys();

    auto fileMul = filename + MUL_EXT;
    ifstream finMul(fileMul, std::ios::in | std::ios::binary);
    if ( !finMul.is_open() )
        throw "Failed when reading multiplication keys from " + fileMul;
    if ( !context->DeserializeEvalMultKey(finMul, SerType::BINARY) )
        throw "Deserialization of multiplication keys from " + fileMul + " failed";

    auto fileRot = filename + ROT_EXT;
    ifstream finRot(fileRot, std::ios::in | std::ios::binary);
    if ( !finRot.is_open() )
        throw "Failed when reading rotation keys from " + fileRot;
    if ( !context->DeserializeEvalAutomorphismKey(finRot, SerType::BINARY) )
        throw "Deserialization of rotation keys from " + fileRot + " failed";
}

void loadParams(const string & filename, uint32_t & multDepth, uint32_t & scaleFactorBits, uint32_t & batchSize,
                int & securityLevel, int & ringDimension, string & rescale, string & rotations)
{
    auto file = filename + PARAM_EXT;
    ifstream fin(file);
    fin >> multDepth >> scaleFactorBits >> batchSize >> securityLevel >> ringDimension >> rescale >> rotations;
    if ( !fin ) throw "Cannot open " + file;
}

PublicKey loadPublicKey(const string & filename)
{
    auto file = filename + PUB_EXT;
    PublicKey publicKey;
    if ( !Serial::DeserializeFromFile(file, publicKey, SerType::BINARY) )
        throw "Could not read public key from " + file;
    return publicKey;
}

SecretKey loadSecretKey(const string & filename)
{
    SecretKey secretKey;
    if ( !Serial::DeserializeFromFile(filename, secretKey, SerType::BINARY) )
        throw "Could not read secret key from " + filename;
    return secretKey;
}

Context makeContext(uint32_t multDepth, uint32_t scaleFactorBits, uint32_t batchSize,
                    int securityLevel, int & ringDimension, const string & rescale)
{
    auto seclvl = getSecurityLevel(securityLevel);
    auto rstech = getRescalingTechnique(rescale);
    Context context = CryptoContextFactory<Element>::genCryptoContextCKKS(
                          multDepth, scaleFactorBits, batchSize, seclvl, ringDimension, rstech
                      );
    context->Enable(ENCRYPTION);
    context->Enable(SHE);
    context->Enable(LEVELEDSHE);
    ringDimension = context->GetRingDimension();
    return context;
}

void saveCiphertext(Ciphertext_t & ciphertext, const string & filename)
{
    auto file = filename + CT_EXT;
    if ( !Serial::SerializeToFile(file, ciphertext, SerType::BINARY) )
        throw "Error writing serialization of ciphertext to " + file;
}

void saveContext(Context & context, const string & filename)
{
    auto file = filename + CTX_EXT;
    if ( !Serial::SerializeToFile(file, context, SerType::BINARY) )
        throw "Error writing serialization of crypto context to " + file;
}

void saveEvaluationKey(Context & context, const string & filename)
{
    auto fileMul = filename + MUL_EXT;
    ofstream foutMul(fileMul, std::ios::out | std::ios::binary);
    if ( foutMul.is_open() )
    {
        if ( context->SerializeEvalMultKey(foutMul, SerType::BINARY) == false )
            throw "Error writing serialization of the multiplication keys to " + fileMul;
    }
    else throw "Error serializing multiplication keys";

    auto fileRot = filename + ROT_EXT;
    ofstream foutRot(fileRot, std::ios::out | std::ios::binary);
    if ( foutRot.is_open() )
    {
        if ( context->SerializeEvalAutomorphismKey(foutRot, SerType::BINARY) == false )
            throw "Error writing serialization of the rotation keys to " + fileRot;
    }
    else throw "Error serializing rotation keys";
}

void saveParams(const string & filename, uint32_t multDepth, uint32_t scaleFactorBits, uint32_t batchSize,
                int securityLevel, int ringDimension, const string & rescale, const string & rotations)
{
    auto file = filename + PARAM_EXT;
    ofstream fout(file);
    if ( !fout ) throw "Cannot open " + file;
    fout << multDepth       << '\t';
    fout << scaleFactorBits << '\t';
    fout << batchSize       << '\t';
    fout << securityLevel   << '\t';
    fout << ringDimension   << '\t';
    fout << rescale         << '\t';
    fout << rotations       << '\n';
}

void savePublicKey(PublicKey & publicKey, const string & filename)
{
    auto file = filename + PUB_EXT;
    if ( !Serial::SerializeToFile(file, publicKey, SerType::BINARY) )
        throw "Error writing serialization of public key to " + file;
    try
    {
        auto pk = loadPublicKey(filename);
    }
    catch (...)
    {
        throw "Cannot reload public key.";
    }
}

void saveSecretKey(SecretKey & secretKey, const string & filename)
{
    if ( !Serial::SerializeToFile(filename, secretKey, SerType::BINARY) )
        throw "Error writing serialization of private key to " + filename;
}

Ciphertext_t stringToCiphertext(const string & strCiphertext)
{
    Ciphertext_t ciphertext;
    stringToCiphertext(strCiphertext, ciphertext);
    return ciphertext;
}

void stringToCiphertext(const string & strCiphertext, Ciphertext_t & ciphertext)
{
    istringstream is(strCiphertext);
    Serial::Deserialize(ciphertext, is, SerType::BINARY);
}

} // palisade_ckks

} // e3
