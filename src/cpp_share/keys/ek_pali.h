// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_PALI_H_
#define _E3_EK_PALI_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_pali.h"

namespace e3
{

struct PaliBfvQuery
{
    virtual void print() const = 0;
};

class PaliBfvEvalKey : public EvalKey
{
    private:
        static const bool NOCOUT = true;

    public:
        PaliBfvNativeEvalKey key;

        int polyDegree = 65537;
        int mulDepth = 2;
        int useSlots = 1;
        int maxDepth = 2;
        int p_n = 8 * 1024;

        std::string rawEncrypt(const std::string & s, int msz) const;

    public:
        PaliBfvEvalKey(int) : EvalKey({"", ""}), key() {}
        PaliBfvEvalKey(User u, KeyName name) : EvalKey(name), key() { user(u); }

        bool load(std::string fname);
        virtual bool load() { return load(filename()); }

        virtual std::string encrypt(const std::string & s, int msz) const
        { return decor(rawEncrypt(s, msz), true); }

        virtual size_t slots() const;

        PaliBfvQuery * query() const;
};

} // e3

#endif // _E3_EK_PALI_H_
