#pragma once

#include <string>

class AnyKey
{
    public: // need modify access from both Eval and Priv keys
        // it's possible to avoid public, but simplicity rules
        std::string name;

    public:
        AnyKey(std::string nm) : name(nm) {}
        virtual std::string filename() = 0;
};