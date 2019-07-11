#pragma once

#include "ek_circ_pil.h"

namespace e3
{

class CircuitEvalKey_pilc_X : public CircuitEvalKey_pilc
{
    public:
        CircuitEvalKey_pilc_X(std::string name) : CircuitEvalKey_pilc(User::Alice, name) {}

        void save();
        using CircuitEvalKey_pilc::bek;
};

} // e3
