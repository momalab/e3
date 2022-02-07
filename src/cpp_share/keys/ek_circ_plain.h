// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_PLAIN_H_
#define _E3_EK_CIRC_PLAIN_H_

#include "ek_circ.h"
#include "e3util.h"

namespace e3
{

class CircuitEvalKey_plain : public CircuitEvalKey
{
    protected:
        e3::util::usi key;

    public:
        CircuitEvalKey_plain(User u, KeyName name)
            : CircuitEvalKey(name), key() { user(u); }

        virtual bool load();

        static bool dec(e3::util::usi x, e3::util::usi k) { return !!(x - k); }
        static e3::util::usi enc(bool x, e3::util::usi k) { return (x ? 1 : 0) + k; }

        bool dec(e3::util::usi x) const { return dec(x, key); }
        e3::util::usi enc(bool x) const { return enc(x, key); }
};

} // e3
#endif // _E3_EK_CIRC_PLAIN_H_
