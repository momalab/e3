// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include <iostream>  // debug

// Palisade stuff
#include "palisade.h"

// Palisade serialization
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "pubkeylp-ser.h"
#include "scheme/bfvrns/bfvrns-ser.h"
#include "utils/serialize-binary.h"

#include "e3util.h"
#include "base64.h"
#include "def_pali1.h"


// PART 3/4 - sis_fun

using namespace lbcrypto;

e3::pali::Cc e3::pali::make_context(
    int plaintextModulus, uint32_t mulDepth,
    int lambda, int maxDepth, uint32_t p_n)
{
    // Set the main parameters
    //int plaintextModulus = 65537;
    double sigma = 3.2;
    SecurityLevel securityLevel = HEStd_128_classic;

    switch (lambda)
    {
        case 0: securityLevel = HEStd_NotSet; break;
        case 128: securityLevel = HEStd_128_classic; break;
        case 192: securityLevel = HEStd_192_classic; break;
        case 256: securityLevel = HEStd_256_classic; break;
        default: throw "lambda=" + std::to_string(lambda)
            + ", but must have only predefined values: 0, 128, 192, 256";
    }

    //uint32_t depth = 2;

    // Instantiate the crypto context
    Cc cryptoContext =
        CryptoContextFactory<DCRTPoly>::genCryptoContextBFVrns(
            plaintextModulus, securityLevel, sigma, 0, mulDepth, 0, OPTIMIZED,
            // );
            maxDepth, 0, 60, p_n); // FIXME use 4096

    // Enable features that you wish to use
    cryptoContext->Enable(ENCRYPTION);
    cryptoContext->Enable(SHE);

    return cryptoContext;
}


lbcrypto::LPKeyPair<lbcrypto::DCRTPoly> e3::pali::gen_keys(Cc & cc)
{
    // Initialize Public Key Containers
    LPKeyPair<DCRTPoly> keyPair;

    // Generate a public/private key pair
    keyPair = cc->KeyGen();

    // Generate the relinearization key
    cc->EvalMultKeyGen(keyPair.secretKey);

    // Generate the rotation evaluation keys
    cc->EvalAtIndexKeyGen(keyPair.secretKey, {1, 2, -1, -2});

    return keyPair;
}

e3::pali::Ct e3::pali::encrypt(Cc & cc, PubKey & pk, const vi64 & v)
{
    Pt plaintext = cc->MakePackedPlaintext(v);
    return cc->Encrypt(pk, plaintext);
}


e3::pali::Pt e3::pali::decrypt_pt(Cc & cc, SecKey & sk, Ct & ct)
{
    Pt pt;
    cc->Decrypt(sk, ct, &pt);
    return pt;
}

template <class T> T e3::pali::decrypt(Cc & cc, SecKey & sk, Ct & ct, int sz)
{
    throw string() + "e3::pali::decrypt for specialization ["
    + typeid(T).name() + "] not implemented";
}


template <> e3::pali::vi64
e3::pali::decrypt<e3::pali::vi64>(Cc & cc, SecKey & sk, Ct & ct, int sz)
{
    e3::pali::Pt pt = e3::pali::decrypt_pt(cc, sk, ct);
    pt->SetLength(sz);
    vi64 r = pt->GetPackedValue();
    return r;
}

template e3::pali::vi64
e3::pali::decrypt<e3::pali::vi64>(Cc & cc, SecKey & sk, Ct & ct, int sz);


// PART 4/4 - sis_ser

void e3::pali::save_context(CryptoContext<DCRTPoly> & cc, string f)
{
    auto file = f + "_ctx.key";
    if (!Serial::SerializeToFile(file, cc, SerType::BINARY))
        throw "Error writing serialization of the crypto context to " + file;
}


CryptoContext<DCRTPoly> e3::pali::load_context(string f)
{
    auto file = f + "_ctx.key";
    CryptoContext<DCRTPoly> cc;
    if (!Serial::DeserializeFromFile(file, cc, SerType::BINARY))
        throw "Cannot read serialization from " + file;
    return cc;
}

void e3::pali::save_pub_main(LPPublicKey<DCRTPoly> & k, string f)
{
    auto file = f + "_pub.key";
    // Serialize the public key
    if (!Serial::SerializeToFile(file, k, SerType::BINARY))
        throw "Error writing serialization of public key to " + file;
}

e3::pali::PubKey e3::pali::load_pub_main(string f)
{
    auto file = f + "_pub.key";
    lbcrypto::LPPublicKey<DCRTPoly> pk;
    if (!Serial::DeserializeFromFile(file, pk, SerType::BINARY))
        throw "Could not read public key " + file;
    return pk;
}

bool e3::pali::load_pub_possible(string file)
{
    auto f1 = file + "_pub.key";
    auto f2 = file + "_ctx.key";

    std::ifstream in1(f1), in2(f2);

    return !!in1 && !!in2;
}


void e3::pali::save_priv(LPPrivateKey<DCRTPoly> & k, string f)
{
    if (!Serial::SerializeToFile(f, k, SerType::BINARY))
        throw "Error writing serialization of private key to " + f;
}


e3::pali::SecKey e3::pali::load_priv(string f)
{
    SecKey sk;
    if (!Serial::DeserializeFromFile(f, sk, SerType::BINARY))
        throw "Could not read secret key " + f;
    return sk;
}


void e3::pali::save_pub_eval(CryptoContext<DCRTPoly> & cc, string f)
{

    auto fmul = f + +"_mul.key";
    std::ofstream emkeyfile(fmul, std::ios::out | std::ios::binary);
    if (emkeyfile.is_open())
    {
        if (cc->SerializeEvalMultKey(emkeyfile, SerType::BINARY) == false)
            throw "Error writing serialization of the eval mult keys to " + fmul;
    }
    else
        throw "Error serializing eval mult keys";

    auto frot = f + +"_rot.key";
    std::ofstream erkeyfile(frot, std::ios::out | std::ios::binary);
    if (erkeyfile.is_open())
    {
        if (cc->SerializeEvalAutomorphismKey(erkeyfile, SerType::BINARY) == false)
            throw "Error writing serialization of the eval rotation keys to " + frot;
    }
    else
        throw "Error serializing eval rotation keys";
}


void e3::pali::save_ct(Ct & ct, string f)
{
    auto file = f + +".ct";
    if (!Serial::SerializeToFile(file, ct, SerType::BINARY))
        throw "Error writing serialization of ciphertext to " + file;
}

e3::pali::Ct e3::pali::load_ct(string f)
{
    Ciphertext<DCRTPoly> ct;
    auto file = f + +".ct";
    if (!Serial::DeserializeFromFile(file, ct, SerType::BINARY))
        throw "Could not read the ciphertext from " + file;
    return ct;
}

void e3::pali::load_pub_eval(CryptoContext<DCRTPoly> & cc, string f)
{
    auto fmul = f + +"_mul.key";

    std::ifstream emkeys(fmul, std::ios::in | std::ios::binary);
    if (!emkeys.is_open())
        throw "I cannot read serialization from " + fmul;

    if (!cc->DeserializeEvalMultKey(emkeys, SerType::BINARY))
        throw "Could not deserialize the eval mult key file " + fmul;


    auto frot = f + +"_rot.key";

    std::ifstream erkeys(frot, std::ios::in | std::ios::binary);
    if (!erkeys.is_open())
        throw "I cannot read serialization from " + frot;

    if (!cc->DeserializeEvalAutomorphismKey(erkeys, SerType::BINARY))
        std::cerr << "Could not deserialize the eval rotation key file " + frot;
}


string e3::pali::ct2str(e3::pali::Ct & ct)
{
    std::ostringstream os;
    Serial::Serialize(ct, os, SerType::BINARY);
    return os.str();
}

e3::pali::Ct e3::pali::str2ct(const string & s)
{
    Ciphertext<DCRTPoly> ct;
    str2ct(s, ct);
    return ct;
}

void e3::pali::str2ct(const string & s, Ct & ct)
{
    std::istringstream is(s);
    Serial::Deserialize(ct, is, SerType::BINARY);
}

void e3::pali::load_params(string file, int & polyDegree,
                           int & muldepth, int & useSlots, int & maxdepth, int & p_n)
{
    auto f = file + "_par.key";
    std::ifstream in(f);
    in >> polyDegree >> muldepth >> useSlots >> maxdepth >> p_n;
    if ( !in ) throw "Cannot open " + f;
}

void e3::pali::save_params(string file, int polyDegree, int muldepth,
                           int useSlots, int maxdepth, int p_n)
{
    auto f = file + "_par.key";
    std::ofstream of(f);
    if ( !of ) throw "Cannot open " + f;
    of << polyDegree << "\t";
    of << muldepth << "\t";
    of << useSlots << "\t";
    of << maxdepth << "\t";
    of << p_n << "\n";
}
