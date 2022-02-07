// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_SEAL_CKKS_H_
#define _E3_DEF_SEAL_CKKS_H_

#include <string>
#include <memory>


namespace e3
{
struct SealCkksCiphertext;

using SealCkksNativePrivKey = void * ;
using SealCkksNativeEvalKey = void * ;
using cSealCkksNativeEvalKey = const void * ;

struct SealCkksNativeCiphertext
{
    std::shared_ptr<SealCkksCiphertext> p;
    std::string str() const;

    SealCkksNativeCiphertext(); // new
    SealCkksNativeCiphertext(const SealCkksNativeCiphertext &); // = delete;
    SealCkksNativeCiphertext(const std::string & enc, cSealCkksNativeEvalKey ek);
};

} // e3
#endif // _E3_DEF_SEAL_CKKS_H_
