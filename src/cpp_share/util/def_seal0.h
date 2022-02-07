// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_SEAL0_H_
#define _E3_DEF_SEAL0_H_

// this header def_seal0.h should not be included in any code except *seal0.cpp
#include <vector>

#include "def_seal.h"

namespace e3
{

struct SealCiphertext { std::vector<uint64_t> ct = {0}; };

namespace e3seal
{
// struct SealPrivKey
// {
// };

struct SealEvalKey
{
    uint64_t plaintextModulus = 0;
    uint64_t polyModulusDegree = 0;
    bool isBatchEncoder = false;
    uint64_t getPlaintextModulus() const { return plaintextModulus; }
};

// using sk = SealPrivKey;
// inline  sk * tosk(e3::SealNativePrivKey a) { return static_cast<sk *>(a); }

using ek = SealEvalKey;
inline  ek * toek(e3::SealNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(e3::cSealNativeEvalKey a) { return static_cast<const ek *>(a); }
} //e3seal
} // e3
#endif // _E3_DEF_SEAL0_H_
