// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_BFVPROT_H_
#define _E3_EKX_BFVPROT_H_

#include "ek_bfv_prot.h"

namespace e3
{

class BfvProtEvalKeyExt : public BfvProtEvalKey
{
    public:
        BfvProtEvalKeyExt(KeyName name) : BfvProtEvalKey(User::Alice, name) {}

        void save();
};

} // e3
#endif // _E3_EKX_BFVPROT_H_
