#pragma once

#include <vector>
#include <string>

#include "ek_abstract.h"

class CircuitEvalKey : public EvalKey
{
    public:
        CircuitEvalKey(std::string name) : EvalKey(name) { }

        static std::vector<std::string> enc2bits(const std::string & e);
        static std::string bits2enc(const std::vector<std::string> & v);
        ///virtual std::string decor(const std::string &, bool add) const;
};

