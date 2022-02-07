// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_BFVPROT_H_
#define _E3_EK_BFVPROT_H_

#include "ek_abstract.h"
#include "e3util.h"

namespace e3
{

class BfvProtEvalKey : public EvalKey
{
    private:
        static const bool NOCOUT = false;

    public: // access from PrivKey
        int nslots = 1;

        uint64_t polyModulusDegree = 1 << 1;
        uint64_t plainModulus = 2;

    public:
        std::string rawEncrypt(const std::string & s, int msz) const;

    public:
        BfvProtEvalKey(int) : EvalKey({"", ""}) {} // when used as a member in key class
        BfvProtEvalKey(User u, KeyName name) : EvalKey(name) { user(u); }

        bool load(std::string fname);
        virtual bool load() { return load(filename()); }

        virtual std::string encrypt(const std::string & s, int msz) const
        { return decor(rawEncrypt(s, msz), true); }

        virtual size_t slots();
};

} // e3

#endif // _E3_EK_BFVPROT_H_
