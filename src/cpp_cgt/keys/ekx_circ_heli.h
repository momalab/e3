#pragma once

#include "ek_circ_heli.h"

namespace e3
{

class CircuitEvalKey_heli_X : public CircuitEvalKey_heli
{
    public:
        CircuitEvalKey_heli_X(KeyName name) : CircuitEvalKey_heli(User::Alice, name) {}

        void save();
        using CircuitEvalKey_heli::key;
};

} // e3
