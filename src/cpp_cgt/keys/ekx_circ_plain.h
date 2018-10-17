#pragma once

#include "ek_circ_plain.h"

class CircuitEvalKey_plain_X : public CircuitEvalKey_plain
{
    public:
        CircuitEvalKey_plain_X(std::string name) : CircuitEvalKey_plain(User::Alice, name) {}

        void save();
        using CircuitEvalKey_plain::key;
};
