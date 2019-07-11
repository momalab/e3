#pragma once

#include "ek_circ.h"
#include "e3util.h"

class CircuitEvalKey_plain : public CircuitEvalKey
{
    protected:
        e3util::usi key;

    public:
        CircuitEvalKey_plain(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();

        static bool dec(e3util::usi x, e3util::usi k) { return !!(x - k); }
        static e3util::usi enc(bool x, e3util::usi k) { return (x ? 1 : 0) + k; }

        bool dec(e3util::usi x) const { return dec(x, key); }
        e3util::usi enc(bool x) const { return enc(x, key); }

        ///virtual std::string decor(const std::string &, bool add) const;
};
