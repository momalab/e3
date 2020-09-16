#ifndef _E3_DEF_SEAL_CKKS1_H_
#define _E3_DEF_SEAL_CKKS1_H_

// this header def_seal_ckks1.h should not be included in any code except *seal_ckks1.cpp

#include "def_seal_ckks.h"

#include "seal/seal.h"

struct SealCkksCiphertext
{
    seal::Ciphertext ct;
    SealCkksCiphertext() {}
};

namespace e3seal_ckks
{

struct SealCkksPrivKey
{
    seal::SecretKey secretkey;
    seal::Decryptor * decryptor = nullptr;
};

struct SealCkksEvalKey
{
    seal::PublicKey publickey;
    seal::RelinKeys relinkeys;
    seal::EncryptionParameters * params = nullptr;
    seal::Encryptor * encryptor = nullptr;
    seal::Evaluator * evaluator = nullptr;
    seal::CKKSEncoder * encoder = nullptr;
    std::shared_ptr<seal::SEALContext> context;
    uint64_t scale = 0;
};

using sk = SealCkksPrivKey;
inline  sk * tosk(e3::SealCkksNativePrivKey a) { return static_cast<sk *>(a); }

using ek = SealCkksEvalKey;
inline  ek * toek(e3::SealCkksNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(e3::cSealCkksNativeEvalKey a) { return static_cast<const ek *>(a); }

} // e3seal_ckks
#endif // _E3_DEF_SEAL_CKKS1_H_
