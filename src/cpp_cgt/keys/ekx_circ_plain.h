#pragma once

#include "ek_circ_plain.h"

namespace e3
{

class CircuitEvalKey_plain_X : public CircuitEvalKey_plain
{
    public:
        CircuitEvalKey_plain_X(KeyName name) : CircuitEvalKey_plain(User::Alice, name) {}

        void save();
        using CircuitEvalKey_plain::key;
};

} // e3
