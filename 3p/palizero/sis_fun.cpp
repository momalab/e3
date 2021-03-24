
#include "palisade.h"
//#include "ciphertext-ser.h"
//#include "cryptocontext-ser.h"
//#include "pubkeylp-ser.h"
//#include "scheme/bfvrns/bfvrns-ser.h"
//#include "utils/serialize-binary.h"

#include "sis_fun.h"

using namespace lbcrypto;

e3::pali::Cc e3::pali::make_context(
    int plaintextModulus, uint32_t depth, int lambda)
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
        default: throw "lambda must have only predefined values: 0, 128, 192, 256";
    }

    //uint32_t depth = 2;

    // Instantiate the crypto context
    Cc cryptoContext =
        CryptoContextFactory<DCRTPoly>::genCryptoContextBFVrns(
            plaintextModulus, securityLevel, sigma, 0, depth, 0, OPTIMIZED);

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

