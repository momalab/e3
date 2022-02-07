// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_ARITH_SEAL_H_
#define _E3_EK_ARITH_SEAL_H_

#include "ek_seal.h"

namespace e3
{

class SealEvalKey : public SealBaseEvalKey
{
    public:
        SealEvalKey(User u, KeyName name) : SealBaseEvalKey(u, name) {}
};

} // e3
#endif // _E3_EK_ARITH_SEAL_H_
