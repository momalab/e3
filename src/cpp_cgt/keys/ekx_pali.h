// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_PALI_H_
#define _E3_EKX_PALI_H_

#include "ek_pali.h"

namespace e3
{

class PaliBfvEvalKeyExt : public PaliBfvEvalKey
{
    public:
        PaliBfvEvalKeyExt(KeyName name) : PaliBfvEvalKey(User::Alice, name) {}

        void save();
};

} // e3
#endif // _E3_EKX_PALI_H_
