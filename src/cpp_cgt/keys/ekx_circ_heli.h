// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_CIRC_HELI_H_
#define _E3_EKX_CIRC_HELI_H_

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
#endif // _E3_EKX_CIRC_HELI_H_
