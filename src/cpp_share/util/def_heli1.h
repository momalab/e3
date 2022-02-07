// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_HELI1_H_
#define _E3_DEF_HELI1_H_

// this header def_heli1.h should not be included in any code except *heli1.cpp

#include "def_heli.h"

#include "FHE.h"
#include "EncryptedArray.h"


namespace e3
{


struct NativeProperties
{
    FHEcontext * pcontext;
};

namespace heli
{

using sk = FHESecKey ;
inline  sk * tosk(HeliNativePrivKey a) { return static_cast<sk *>(a); }

using ek = FHEPubKey ;
inline  ek * toek(HeliNativeEvalKey a) { return static_cast<ek *>(a); }
inline  const ek * toek(cHeliNativeEvalKey a) { return static_cast<const ek *>(a); }

const bool PRN = false;

} // heli

struct HeliCtxt
{
    Ctxt b;
    HeliCtxt(const FHEPubKey * ek): b(*ek) {}
};

void init_properties_heli(NativeProperties ** ppprop, std::string & name);

} // e3

#endif // _E3_DEF_HELI1_H_
