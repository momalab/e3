// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_ARITH_SEAL_CKKS_H_
#define _E3_EK_ARITH_SEAL_CKKS_H_

#include "ek_seal_ckks.h"

namespace e3
{

class SealCkksEvalKey : public SealCkksBaseEvalKey
{
    public:
        SealCkksEvalKey(User u, KeyName name) : SealCkksBaseEvalKey(u, name) {}
};

} // e3
#endif // _E3_EK_ARITH_SEAL_CKKS_H_
