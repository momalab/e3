// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_FHEW_H_
#define _E3_DEF_FHEW_H_

#include <string>
#include <memory>

namespace e3
{

struct LweCipherText;

using FhewNativePrivKey = void * ;
using FhewNativeEvalKey = void * ;
using cFhewNativeEvalKey = const void * ;

struct FhewNativeBt
{
    std::shared_ptr<LweCipherText> p;
    std::string str(cFhewNativeEvalKey) const;
    FhewNativeBt(cFhewNativeEvalKey ek); // new
    FhewNativeBt(const std::string & enc, cFhewNativeEvalKey ek);
    FhewNativeBt(const FhewNativeBt &) = delete;
    FhewNativeBt(const FhewNativeBt & b, cFhewNativeEvalKey ek);
};

int fhew_impl(); // 0 or 1

} // e3


#endif // _E3_DEF_FHEW_H_

