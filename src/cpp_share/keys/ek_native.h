#pragma once

#include "ek_abstract.h"
#include "e3util.h"

class NativeEvalKey : public EvalKey
{
    protected:
        e3util::ull key;

    public:
        NativeEvalKey(User u, std::string name) : EvalKey(name) { user(u); } // user must be called here

        virtual bool load(); // load has to be public so PrivKey can call it. Another solution would be SK calling the construction of EK

        e3util::ull dec(e3util::ull x) const { return dec(x, key); }
        e3util::ull enc(e3util::ull x) const { return enc(x, key); }
        static e3util::ull dec(e3util::ull x, e3util::ull k) { return x ^ k; }
        static e3util::ull enc(e3util::ull x, e3util::ull k) { return x ^ k; }
};
