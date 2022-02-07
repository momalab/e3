// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_PIL_H_
#define _E3_EKX_PIL_H_

#include "ek_pil.h"
#include "e3util.h"

namespace e3
{

class PilBaseEvalKeyExt : public PilBaseEvalKey
{
    public:
        PilBaseEvalKeyExt(KeyName name) : PilBaseEvalKey(User::Alice, name) {}

        void save();
};

} // e3
#endif // _E3_EKX_PIL_H_
