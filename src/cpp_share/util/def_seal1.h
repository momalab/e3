// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_SEAL1_H_
#define _E3_DEF_SEAL1_H_

// this header def_seal1.h should not be included in any code except *seal1.cpp

#include "def_seal.h"

#include "seal/seal.h"

namespace e3
{

struct SealCiphertext
{
    seal::Ciphertext ct;
    SealCiphertext() {}
};

namespace e3seal
{

struct SealPrivKey
{
    seal::SecretKey secretkey;
    seal::Decryptor * decryptor = nullptr;
};

struct SealEvalKey
{
    seal::PublicKey publickey;
    seal::RelinKeys relinkeys;
    seal::GaloisKeys galoiskeys;
    seal::EncryptionParameters * params = nullptr;
    seal::Encryptor * encryptor = nullptr;
    seal::Evaluator * evaluator = nullptr;
#if SEALVER == 332
    seal::IntegerEncoder * encoder = nullptr;
#endif
    seal::BatchEncoder * batchEncoder = nullptr;
    bool isBatchEncoder = false;
#if SEALVER == 332
    std::shared_ptr<seal::SEALContext> context;
#else
    seal::SEALContext context;
    SealEvalKey(seal::EncryptionParameters &p): params(&p), context(p) {}
#endif

    uint64_t getPlaintextModulus() const { return params->plain_modulus().value(); }
};

using sk = SealPrivKey;
inline  sk * tosk(e3::SealNativePrivKey a) { return static_cast<sk *>(a); }

using ek = SealEvalKey;
inline  ek * toek(e3::SealNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(e3::cSealNativeEvalKey a) { return static_cast<const ek *>(a); }

template <class T>
seal::Plaintext batchEncode(const std::vector<T> & v, seal::BatchEncoder & encoder)
{
    seal::Plaintext p;
    size_t size = encoder.slot_count();
    size_t max = v.size() < size ? v.size() : size;
    std::vector<uint64_t> u( size, 0 );
    for ( size_t i = 0; i < max; i++ ) u[i] = uint64_t(v[i]);
    encoder.encode(u, p);
    return p;
}

} // e3seal
} // e3

#endif // _E3_DEF_SEAL1_H_
