// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_H_
#define _E3_EK_CIRC_H_

#include <vector>
#include <string>

#include "ek_abstract.h"

namespace e3
{

class CircuitEvalKey : public EvalKey
{
    public:
        CircuitEvalKey(KeyName name) : EvalKey(name) { }

        static std::vector<std::string> enc2bits(const std::string & e);
        static std::string bits2enc(const std::vector<std::string> & v);
};

} // e3
#endif // _E3_EK_CIRC_H_
