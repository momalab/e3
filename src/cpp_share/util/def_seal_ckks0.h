#ifndef _E3_DEF_SEAL_CKKS0_H_
#define _E3_DEF_SEAL_CKKS0_H_

// this header def_seal_ckks0.h should not be included in any code except *seal_ckks0.cpp

#include <vector>
#include "def_seal_ckks.h"

struct SealCkksCiphertext { std::vector<double> ct; };

namespace e3seal_ckks
{
// struct SealCkksPrivKey
// {
// };

struct SealCkksEvalKey
{
    uint64_t polyModulusDegree = 0;
    uint64_t scale = 0;
};

// using sk = SealCkksPrivKey;
// inline  sk * tosk(e3::SealCkksNativePrivKey a) { return static_cast<sk *>(a); }

using ek = SealCkksEvalKey;
inline  ek * toek(e3::SealCkksNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(e3::cSealCkksNativeEvalKey a) { return static_cast<const ek *>(a); }
} // e3seal_ckks
#endif // _E3_DEF_SEAL_CKKS0_H_
