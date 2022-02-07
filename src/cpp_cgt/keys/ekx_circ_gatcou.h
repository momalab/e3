// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_CIRC_GATCOU_H_
#define _E3_EKX_CIRC_GATCOU_H_

#include "ek_circ_gatcou.h"

namespace e3
{

class CircuitEvalKey_gatcou_X : public CircuitEvalKey_gatcou
{
    public:
        CircuitEvalKey_gatcou_X(KeyName name) : CircuitEvalKey_gatcou(User::Alice, name) {}

        void save() {}
};

} // e3
#endif // _E3_EKX_CIRC_GATCOU_H_
