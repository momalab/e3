#pragma once

#include "ek_circ_seal.h"

namespace e3
{

class CircuitEvalKey_seal_X : public CircuitEvalKey_seal
{
    public:
        CircuitEvalKey_seal_X(std::string name) : CircuitEvalKey_seal(User::Alice, name) {}

        void save();
        using CircuitEvalKey_seal::key;
};

} // e3
