// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_SEAL_H_
#define _E3_EK_SEAL_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_seal.h"

namespace e3
{

class SealBaseEvalKey : public EvalKey
{
    private:
        static const bool NOCOUT = true;

    public:
        SealNativeEvalKey key;
        std::string rawEncrypt(const std::string & s, int msz) const;

    public:
        SealBaseEvalKey(int) : EvalKey({"", ""}), key() {} // when used as a member in key class
        SealBaseEvalKey(User u, KeyName name) : EvalKey(name), key() { user(u); }

        bool load(std::string fname);
        virtual bool load() { return load(filename()); }

        virtual std::string encrypt(const std::string & s, int msz) const
        { return decor(rawEncrypt(s, msz), true); }

        virtual size_t slots();

        uint64_t getPlaintextModulus() const;
};

} // e3

#endif // _E3_EK_SEAL_H_
