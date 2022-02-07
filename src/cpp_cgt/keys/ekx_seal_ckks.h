// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_SEAL_CKKS_H_
#define _E3_EKX_SEAL_CKKS_H_

#include "ek_seal_ckks.h"

namespace e3
{

class SealCkksBaseEvalKeyExt : public SealCkksBaseEvalKey
{
    public:
        SealCkksBaseEvalKeyExt(KeyName name) : SealCkksBaseEvalKey(User::Alice, name) {}

        void save();
};

} // e3
#endif // _E3_EKX_SEAL_CKKS_H_
