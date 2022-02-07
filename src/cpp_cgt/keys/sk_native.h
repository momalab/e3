// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_NATIVE_H_
#define _E3_SK_NATIVE_H_

#include "sk_abstract.h"
#include "ekx_native.h"
#include "e3util.h"

namespace e3
{

class NativePrivKey : public PrivKey
{
        virtual void gen();

    private:
        e3::util::ull key;
        NativeEvalKeyExt ek; // decryption and encryption are there

    public:
        NativePrivKey(KeyName name, bool forceGen,
                      bool forceLoad, std::string seed);

        virtual std::string decrypt(const std::string & s) const;
        virtual std::string encrypt(const std::string & s, int msz) const;
        virtual bool load();
        virtual void save();
};

} // e3
#endif // _E3_SK_NATIVE_H_
