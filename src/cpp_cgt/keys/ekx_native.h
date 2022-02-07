// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_NATIVE_H_
#define _E3_EKX_NATIVE_H_

#include "ek_native.h"
#include "e3util.h"

namespace e3
{

class NativeEvalKeyExt : public NativeEvalKey
{
    public:
        NativeEvalKeyExt(KeyName name) : NativeEvalKey(User::Alice, name) {}

        void save();
        using NativeEvalKey::key;
};

} // e3
#endif // _E3_EKX_NATIVE_H_
