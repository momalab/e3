// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_FHEW1_H_
#define _E3_DEF_FHEW1_H_

// this header def_fhew1.h should not be included in any code except *fhew1.cpp

#include "def_fhew.h"

#include "LWE.h"
#include "FHEW.h"

namespace e3
{

struct LweCipherText { LWE::CipherText b; };

namespace fhew
{

using sk = LWE::SecretKey;
inline  sk * tosk(FhewNativePrivKey a) { return static_cast<sk *>(a); }

using ek = FHEW::EvalKey;
inline  ek * toek(FhewNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(cFhewNativeEvalKey a) { return static_cast<const ek *>(a); }

} // fhew

void init_properties_fhew();

} // e3

#endif // _E3_DEF_FHEW1_H_
