// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_NATIVE_H_
#define _E3_EK_NATIVE_H_

#include "ek_abstract.h"
#include "e3util.h"

namespace e3
{

class NativeEvalKey : public EvalKey
{
    protected:
        e3::util::ull key;

    public:
        NativeEvalKey(User u, KeyName name)
            : EvalKey(name), key() { user(u); } // user must be called here

        virtual bool load(); // load has to be public so PrivKey can call it.
        // Another solution would be SK calling the construction of EK

        e3::util::ull dec(e3::util::ull x) const { return dec(x, key); }
        e3::util::ull enc(e3::util::ull x) const { return enc(x, key); }
        static e3::util::ull dec(e3::util::ull x, e3::util::ull k) { return x ^ k; }
        static e3::util::ull enc(e3::util::ull x, e3::util::ull k) { return x ^ k; }
};

} // e3
#endif // _E3_EK_NATIVE_H_
