// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_CIRC_PLAIN_H_
#define _E3_EKX_CIRC_PLAIN_H_

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
#endif // _E3_EKX_CIRC_PLAIN_H_
