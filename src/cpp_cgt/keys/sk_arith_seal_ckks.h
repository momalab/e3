// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_ARITH_SEAL_CKKS_H_
#define _E3_SK_ARITH_SEAL_CKKS_H_

#include "sk_seal_ckks.h"
#include "ekx_arith_seal_ckks.h"

namespace e3
{

class SealCkksPrivKey : public SealCkksBasePrivKey
{
    public:
        SealCkksPrivKey(KeyName name) : SealCkksPrivKey(name, false, true, "", 0, "", "", "") {}
        SealCkksPrivKey(KeyName name, bool forceGen,
                        bool forceLoad, string seed, int lam,
                        string polyModulusDegree,
                        string primes, string scale)
            : SealCkksBasePrivKey(name, forceGen, forceLoad, seed, lam,
                                  polyModulusDegree, primes, scale) {}

        SealCkksPrivKey(const SealCkksBasePrivKey & privkey, string nm)
            : SealCkksBasePrivKey(privkey, nm) {}
};

} // e3
#endif // _E3_SK_ARITH_SEAL_CKKS_H_
