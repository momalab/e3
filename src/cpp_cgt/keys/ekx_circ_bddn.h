#pragma once

#include "ek_circ_bddn.h"

class CircuitEvalKey_bddn_X : public CircuitEvalKey_bddn
{
    public:
        CircuitEvalKey_bddn_X(std::string name) : CircuitEvalKey_bddn(User::Alice, name) {}

        void save();
        using CircuitEvalKey_bddn::key;
};
