// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_ARITH_SEAL_H_
#define _E3_SK_ARITH_SEAL_H_

#include "sk_seal.h"
#include "ekx_arith_seal.h"

namespace e3
{

class SealPrivKey : public SealBasePrivKey
{
    public:
        SealPrivKey(KeyName name, bool forceGen,
                    bool forceLoad, string seed, int lam,
                    string polyModulusDegree, string plainModulus, string encoder)
            : SealBasePrivKey(name, forceGen, forceLoad, seed, lam, polyModulusDegree, plainModulus, encoder) {}

        SealPrivKey(const SealBasePrivKey & privkey, string nm)
            : SealBasePrivKey(privkey, nm) {}
};

} // e3
#endif // _E3_SK_ARITH_SEAL_H_
