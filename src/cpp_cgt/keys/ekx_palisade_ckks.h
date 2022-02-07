// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_PALISADE_CKKS_H_
#define _E3_EKX_PALISADE_CKKS_H_

#include "ek_palisade_ckks.h"

namespace e3
{

class PalisadeCkksEvalKeyExt : public PalisadeCkksEvalKey
{
    public:
        PalisadeCkksEvalKeyExt(KeyName name) : PalisadeCkksEvalKey(User::Alice, name) {}

        void save();
};

} // e3

#endif // _E3_EKX_PALISADE_CKKS_H_
