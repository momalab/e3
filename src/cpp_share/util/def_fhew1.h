#pragma once

// this header def_fhew1.h should not be included in any code except *fhew1.cpp

#include "def_fhew.h"

#include "LWE.h"
#include "FHEW.h"


struct LweCipherText { LWE::CipherText b; };

namespace e3fhew
{

using sk = LWE::SecretKey;
inline  sk * tosk(FhewNativePrivKey a) { return static_cast<sk *>(a); }

using ek = FHEW::EvalKey;
inline  ek * toek(FhewNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(cFhewNativeEvalKey a) { return static_cast<const ek *>(a); }

} // e3fhew

void init_properties_fhew();
