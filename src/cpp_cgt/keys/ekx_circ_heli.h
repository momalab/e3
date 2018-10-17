#pragma once

#include "ek_circ_heli.h"

class CircuitEvalKey_heli_X : public CircuitEvalKey_heli
{
    public:
        CircuitEvalKey_heli_X(std::string name) : CircuitEvalKey_heli(User::Alice, name) {}

        void save();
        using CircuitEvalKey_heli::key;
};
