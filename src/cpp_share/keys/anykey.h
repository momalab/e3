#pragma once

#include <string>

class AnyKey
{
    public: // need modify access from both Eval and Priv keys
        // it's possible to avoid public, but simplicity rules
        std::string name;
        //std::string decorname; // FIXME o InitEvalKey add tName

        ///private:
        // utility function for decor
        ///static std::string prefix(
        ///const std::string & s, bool add, std::string pfx);

    public:
        AnyKey(std::string nm) : name(nm) {}

        virtual std::string filename() const = 0;

        static std::string decor(const std::string & what, bool add, std::string pfx);
};