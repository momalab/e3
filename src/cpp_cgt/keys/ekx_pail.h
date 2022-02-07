// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_PAIL_H_
#define _E3_EKX_PAIL_H_

#include "ek_pail.h"
#include "e3util.h"

namespace e3
{

class PailEvalKeyExt : public PailEvalKey
{
    public:
        PailEvalKeyExt(KeyName name) : PailEvalKey(User::Alice, name) {}

        void save();
};

} // e3
#endif // _E3_EKX_PAIL_H_
