#pragma once

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
