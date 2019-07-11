#pragma once

#include <cstdlib>
#include <sstream>
#include <string>

#include "anykey.h"

class EvalKey : public AnyKey
{
    public:
        enum class User { Alice, Bob };

    private:
        void loadOrDie();

    protected:
        std::string filenamex(std::string fx) const { return name + fx + ".eval.key"; }
        virtual std::string filename() const { return filenamex(""); }

        void user(User u) { if ( u == User::Bob ) loadOrDie(); }
        virtual bool load() = 0;

    public:
        EvalKey(std::string nm) : AnyKey(nm) {}
};
