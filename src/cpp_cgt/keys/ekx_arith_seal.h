#pragma once

#include "ek_arith_seal.h"
#include "e3util.h"

namespace e3
{

class SealBaseEvalKeyExt : public SealBaseEvalKey
{
    public:
        SealBaseEvalKeyExt(KeyName name) : SealBaseEvalKey(User::Alice, name) {}

        void save();
};

} // e3
