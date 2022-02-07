// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_PALISADE_CKKS_H_
#define _E3_EK_PALISADE_CKKS_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_palisade_ckks.h"

namespace e3
{

class PalisadeCkksEvalKey : public EvalKey
{
    private:
        static const bool NOCOUT = true;

    public:
        PalisadeCkksNativeEvalKey key;

        uint32_t multDepth = 1;
        uint32_t scaleFactorBits = 50;
        uint32_t batchSize = 1;
        int securityLevel = 128;
        int ringDimension = 0;
        std::string rescale = "exact";
        std::string rotations = "none";

        std::string rawEncrypt(const std::string & strPlaintext, int msz) const;

    public:
        PalisadeCkksEvalKey(int) : EvalKey( {"", ""} ), key() {}
        PalisadeCkksEvalKey(User u, KeyName name) : EvalKey(name), key() { user(u); }

        bool load(std::string fname);
        virtual bool load() { return load( filename() ); }

        virtual std::string encrypt(const std::string & strPlaintext, int msz) const
        { return decor(rawEncrypt(strPlaintext, msz), true); }

        virtual size_t slots() const;
};

} // e3

#endif // _E3_EK_PALISADE_CKKS_H_
