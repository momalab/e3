// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_SEAL_H_
#define _E3_EK_CIRC_SEAL_H_

#include "ek_circ.h"
#include "ek_seal.h"

using std::string;

namespace e3
{

class CircuitEvalKey_seal_bfv : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    protected:
        SealBaseEvalKey bek;

    public:
        CircuitEvalKey_seal_bfv(User u, KeyName name)
            : CircuitEvalKey(name), bek(0) { user(u); }

        virtual bool load() { return bek.load(filename()); }

        cSealNativeEvalKey native() const { return bek.key; }

        virtual string encbitstr(bool b) const
        {
            return bek.rawEncrypt(std::to_string(unsigned(b)), 1);
        }

        virtual std::string encrypt(const std::string & s, int msz) const
        {
            std::vector<string> numbers = e3::util::split(s, '_');
            std::vector<std::vector<bool>> bin(msz);
            for ( size_t i = 0; i < numbers.size(); i++ )
            {
                auto hexvalue = e3::util::dec2hex(numbers[i], msz);
                auto sbit = e3::util::hex2bin(hexvalue, msz);
                for ( size_t j = 0; j < sbit.size(); j++ )
                    bin[j].push_back( sbit[j] );
            }
            std::vector<string> bits;
            for ( auto b : bin )
                bits.push_back( bek.rawEncrypt(e3::util::merge(b, "_"), msz) );

            return decor( CircuitEvalKey::bits2enc(bits), true );
        }

        virtual string filename() const { return EvalKey::filename(); }
        virtual size_t slots() { return bek.slots(); }
};

} // e3
#endif // _E3_EK_CIRC_SEAL_H_
