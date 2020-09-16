#ifndef _E3_DEF_SEAL0_H_
#define _E3_DEF_SEAL0_H_

// this header def_seal0.h should not be included in any code except *seal0.cpp
#include <vector>

#include "def_seal.h"

struct SealCiphertext { std::vector<uint64_t> ct; };

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
};

// using sk = SealPrivKey;
// inline  sk * tosk(e3::SealNativePrivKey a) { return static_cast<sk *>(a); }

using ek = SealEvalKey;
inline  ek * toek(e3::SealNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(e3::cSealNativeEvalKey a) { return static_cast<const ek *>(a); }
} //e3seal
#endif // _E3_DEF_SEAL0_H_
