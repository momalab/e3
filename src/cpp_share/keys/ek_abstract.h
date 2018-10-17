#pragma once

#include <cstdlib>
#include <sstream>

#include "anykey.h"

class EvalKey : public AnyKey
{
    public:
        enum class User { Alice, Bob };

    private:
        void loadOrDie();

    protected:
        virtual std::string filename() { return name + ".eval.key"; }

        void user(User u) { if ( u == User::Bob ) loadOrDie(); }
        virtual bool load() = 0;

    public:
        EvalKey(std::string nm) : AnyKey(nm) {}
};
