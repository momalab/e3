// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_SEAL_H_
#define _E3_EKX_SEAL_H_

#include "ek_seal.h"

namespace e3
{

class SealBaseEvalKeyExt : public SealBaseEvalKey
{
    public:
        SealBaseEvalKeyExt(KeyName name) : SealBaseEvalKey(User::Alice, name) {}

        void save();
};

} // e3
#endif // _E3_EKX_SEAL_H_
