// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_SEAL_H_
#define _E3_SK_CIRC_SEAL_H_

#include "sk_circ.h"
#include "ekx_circ_seal.h"
#include "sk_seal.h"

namespace e3
{

class CircuitPrivKey_seal_bfv : public CircuitPrivKey
{
        using Bit = SealNativeCiphertext;

        virtual void gen() { never; }
        Bit encbit(bool b) const;
        bool decbit(const Bit & y) const;

    private:
        SealBasePrivKey bsk;

        uint64_t polyModulusDegree = 1 << 15;
        uint64_t plainModulus = 2;
        virtual bool load() { return bsk.load(); }
        virtual void save() { bsk.save(); }

    public:
        CircuitPrivKey_seal_bfv(KeyName name, bool forceGen, bool forceLoad, std::string seed,
                                int lam, std::string polyModulusDegree, std::string plainModulus, std::string encoder)
            : CircuitPrivKey(name, seed, lam),
              bsk(name, forceGen, forceLoad, seed, lam, polyModulusDegree, plainModulus, encoder)
        { }

        CircuitPrivKey_seal_bfv(const SealBasePrivKey & key, std::string name)
            : CircuitPrivKey(KeyName { name, key.name.fil }, "dummy", 0), bsk(key, name)
        { }

        virtual std::string encbitstr(std::vector<bool> b) const
        {
            auto sbit = e3::util::merge(b, "_");
            // std::string sbit = std::to_string(unsigned(b[0]));
            // for ( size_t i = 1; i < b.size(); i++ ) sbit += "_" + std::to_string(unsigned(b[i]));
            return bsk.ek.rawEncrypt(sbit, 1);
        }

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const
        {
            auto sbit = bsk.rawDecrypt(s);
            /// std::cout << __func__ << " INPUT: [" << ( s.size() > 10 ? s.substr(0,10) : s ) << "]\n";

            if (ok) *ok = true;
            std::vector<bool> bit;
            for ( auto s : sbit )
            {
                bit.push_back( s == "1" );
                if (ok) *ok = *ok && (s == "0" || s == "1");
            }

            return bit;
        }

        virtual std::string filename() const { return bsk.filename(); }
        size_t slots() { return bsk.slots(); }
};

} // e3
#endif // _E3_SK_CIRC_SEAL_H_
