// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_GATCOU_H_
#define _E3_SK_CIRC_GATCOU_H_

#include <vector>

#include "sk_circ.h"
#include "ekx_circ_gatcou.h"

namespace e3
{

class CircuitPrivKey_gatcou : public CircuitPrivKey
{
        using Bit = bool;
        virtual void gen() {}

        Bit encbit(bool b) const;
        bool decbit(const Bit & y) const;

    private:
        virtual bool load() { return true; }
        virtual void save() {}

    public:
        CircuitPrivKey_gatcou(KeyName name, bool forceGen,
                              bool forceLoad, std::string seed, int lam)
            : CircuitPrivKey(name, seed, 0)
        { init_final(forceGen, forceLoad); }


        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const
        {
            std::vector<bool> m(1, false);
            if (ok) *ok = false;
            try
            {
                auto x = std::stoi(s);
                if (ok) *ok = true;
                m[0] = !!x;
            }
            catch (...) { }
            return m;
        }

        virtual std::string encbitstr(std::vector<bool> b) const
        { return std::to_string(int(b[0])); }


        virtual string filename() const { return PrivKey::filename(); }
};

} // e3
#endif // _E3_SK_CIRC_GATCOU_H_
