// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_PALISADE_CKKS1_H_
#define _E3_DEF_PALISADE_CKKS1_H_

#include "def_palisade_ckks.h"
#include "palisade.h"

namespace e3
{

namespace palisade_ckks
{

using Element        = lbcrypto::DCRTPoly;

using Plaintext_t    = lbcrypto::Plaintext;
using Ciphertext_t   = lbcrypto::Ciphertext<Element>;
using Context        = lbcrypto::CryptoContext<Element>;
using Keys           = lbcrypto::LPKeyPair<Element>;
using PublicKey      = lbcrypto::LPPublicKey<Element>;
using SecretKey      = lbcrypto::LPPrivateKey<Element>;

using CryptoParams   = std::shared_ptr<lbcrypto::LPCryptoParameters<Element>>;
using ParamType      = std::shared_ptr<Element::Params>;
using EncodingParams = lbcrypto::EncodingParams;

// e3 conversions
inline Context  *  toContext  (void           *          a) { return static_cast<Context *>(a); }
inline PublicKey * toPublicKey(void           *          a) { return static_cast<PublicKey *>(a); }
inline SecretKey * toSecretKey(PalisadeCkksNativePrivKey a) { return static_cast<SecretKey *>(a); }

// utility functions
std::string ciphertextToString(Ciphertext_t & ciphertext);
template<class T> T decrypt(Context & context, SecretKey & secretKey, Ciphertext_t & ciphertext, int size);
Plaintext_t decrypt(Context & context, SecretKey & secretKey, Ciphertext_t & ciphertext);
Ciphertext_t encrypt(Context & context, PublicKey & publicKey, const std::vector<double> & vectorPlaintext);
Ciphertext_t encrypt(Context & context, PublicKey & publicKey, const std::vector<std::complex<double>> & vectorPlaintext);
Keys generateKeys(Context & context, const std::string & rotations);
bool isLoadPublicKeyPossible(const std::string & filename);
Ciphertext_t loadCiphertext(const std::string & filename);
Context loadContext(const std::string & filename);
void loadEvaluationKey(Context & context, const std::string & filename);
void loadParams(const std::string & filename, uint32_t & multDepth, uint32_t & scaleFactorBits, uint32_t & batchSize,
                int & securityLevel, int & ringDimension, std::string & rescale, std::string & rotations);
PublicKey loadPublicKey(const std::string & filename);
SecretKey loadSecretKey(const std::string & filename);
Context makeContext(uint32_t multDepth, uint32_t scaleFactorBits, uint32_t batchSize, int securityLevel, int & ringDimension, const std::string & rescale);
void saveCiphertext(Ciphertext_t & ciphertext, const std::string & filename);
void saveContext(Context & context, const std::string & filename);
void saveEvaluationKey(Context & context, const std::string & filename);
void saveParams(const std::string & filename, uint32_t multDepth, uint32_t scaleFactorBits, uint32_t batchSize,
                int securityLevel, int ringDimension, const std::string & rescale, const std::string & rotations);
void savePublicKey(PublicKey & publicKey, const std::string & filename);
void saveSecretKey(SecretKey & secretkey, const std::string & filename);
Ciphertext_t stringToCiphertext(const std::string & str);
void stringToCiphertext(const std::string & str, Ciphertext_t & ciphertext);

} // palisade_ckks

struct PalisadeCkksCiphertext
{
    e3::palisade_ckks::Ciphertext_t ct;

    PalisadeCkksCiphertext() {}
    PalisadeCkksCiphertext(const palisade_ckks::Ciphertext_t &);
};

} // e3

#endif // _E3_DEF_PALISADE_CKKS1_H_
