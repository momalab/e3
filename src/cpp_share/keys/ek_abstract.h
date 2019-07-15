#pragma once

#include <cstdlib>
#include <sstream>
#include <string>

#include "anykey.h"

namespace e3
{

class EvalKey : public AnyKey
{
    public:
        enum class User { Alice, Bob };

    private:
        void loadOrDie();

    protected:
        std::string filenamex(std::string fx) const
        { return name.fil + fx + ".eval.key"; }

        virtual std::string filename() const { return filenamex(""); }

        void user(User u) { if ( u == User::Bob ) loadOrDie(); }
        virtual bool load() = 0;

    public:
        EvalKey(KeyName nm) : AnyKey(nm) {}
};

} // e3
