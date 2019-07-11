#pragma once

#include "ek_pil.h"
#include "e3util.h"

namespace e3
{

class PilBaseEvalKeyExt : public PilBaseEvalKey
{
    public:
        PilBaseEvalKeyExt(std::string name) : PilBaseEvalKey(User::Alice, name) {}

        void save();
};

} // e3
