// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_SEAL_CKKS_H_
#define _E3_EK_SEAL_CKKS_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_seal_ckks.h"

namespace e3
{

class SealCkksBaseEvalKey : public EvalKey
{
    private:
        static const bool NOCOUT = true;

    public:
        SealCkksNativeEvalKey key;
        std::string rawEncrypt(const std::string & s, int msz) const;

    public:
        SealCkksBaseEvalKey(int) : EvalKey({"", ""}), key() {}
        SealCkksBaseEvalKey(User u, KeyName name) : EvalKey(name), key() { user(u); }

        bool load(std::string fname);
        virtual bool load() { return load(filename()); }

        virtual std::string encrypt(const std::string & s, int msz) const
        { return decor(rawEncrypt(s, msz), true); }

        virtual size_t slots();
};

} // e3

#endif // _E3_EK_SEAL_CKKS_H_
