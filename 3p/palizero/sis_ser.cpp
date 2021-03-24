
#include "palisade.h"
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "pubkeylp-ser.h"
#include "scheme/bfvrns/bfvrns-ser.h"
#include "utils/serialize-binary.h"

#include "sis_fun.h"

using namespace lbcrypto;

void e3::pali::save_context(CryptoContext<DCRTPoly> & cc, string f)
{
    auto file = f + +"_pub_ctx.key";
    if (!Serial::SerializeToFile(file, cc, SerType::BINARY))
        throw "Error writing serialization of the crypto context to " + file;
}

CryptoContext<DCRTPoly> e3::pali::load_context(string f)
{
    auto file = f + +"_pub_ctx.key";
    CryptoContext<DCRTPoly> cc;
    if (!Serial::DeserializeFromFile(file, cc, SerType::BINARY))
        throw "Cannot read serialization from " + file;
    return cc;
}

void e3::pali::save_pub_main(LPPublicKey<DCRTPoly> & k, string f)
{
    auto file = f + +"_pub_pk.key";
    // Serialize the public key
    if (!Serial::SerializeToFile(file, k, SerType::BINARY))
        throw "Error writing serialization of public key to " + file;
}

e3::pali::PubKey e3::pali::load_pub_main(string f)
{
    auto file = f + +"_pub_pk.key";
    lbcrypto::LPPublicKey<DCRTPoly> pk;
    if (!Serial::DeserializeFromFile(file, pk, SerType::BINARY))
        throw "Could not read public key " + file;
    return pk;
}

void e3::pali::save_priv(LPPrivateKey<DCRTPoly> & k, string f)
{
    auto file = f + +"_secret.key";
    if (!Serial::SerializeToFile(file, k, SerType::BINARY))
        throw "Error writing serialization of private key to " + file;
}

e3::pali::SecKey e3::pali::load_priv(string f)
{
    auto file = f + +"_secret.key";
    SecKey sk;
    if (!Serial::DeserializeFromFile(file, sk, SerType::BINARY))
        throw "Could not read secret key " + file;
    return sk;
}

void e3::pali::save_pub_eval(CryptoContext<DCRTPoly> & cc, string f)
{

    auto fmul = f + +"_pub_mul.key";
    std::ofstream emkeyfile(fmul, std::ios::out | std::ios::binary);
    if (emkeyfile.is_open())
    {
        if (cc->SerializeEvalMultKey(emkeyfile, SerType::BINARY) == false)
            throw "Error writing serialization of the eval mult keys to " + fmul;
    }
    else
        throw "Error serializing eval mult keys";

    auto frot = f + +"_pub_rot.key";
    std::ofstream erkeyfile(frot, std::ios::out | std::ios::binary);
    if (erkeyfile.is_open())
    {
        if (cc->SerializeEvalAutomorphismKey(erkeyfile, SerType::BINARY) == false)
            throw "Error writing serialization of the eval rotation keys to " + frot;
    }
    else
        throw "Error serializing eval rotation keys";
}


void e3::pali::load_pub_eval(CryptoContext<DCRTPoly> & cc, string f)
{
    auto fmul = f + +"_pub_mul.key";

    std::ifstream emkeys(fmul, std::ios::in | std::ios::binary);
    if (!emkeys.is_open())
        throw "I cannot read serialization from " + fmul;

    if (!cc->DeserializeEvalMultKey(emkeys, SerType::BINARY))
        throw "Could not deserialize the eval mult key file " + fmul;


    auto frot = f + +"_pub_rot.key";

    std::ifstream erkeys(frot, std::ios::in | std::ios::binary);
    if (!erkeys.is_open())
        throw "I cannot read serialization from " + frot;

    if (!cc->DeserializeEvalAutomorphismKey(erkeys, SerType::BINARY))
        std::cerr << "Could not deserialize the eval rotation key file " + frot;
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

string e3::pali::ct2str(e3::pali::Ct & ct)
{
    std::ostringstream os;
    Serial::Serialize(ct, os, SerType::BINARY);
    return os.str();
}

e3::pali::Ct e3::pali::str2ct(const string & s)
{
    Ciphertext<DCRTPoly> ct;
    std::istringstream is(s);
    Serial::Deserialize(ct, is, SerType::BINARY);
    return ct;
}

