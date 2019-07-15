#pragma once

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
