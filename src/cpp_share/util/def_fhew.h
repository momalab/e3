#pragma once

#include <string>
#include <memory>

// FIXME add e3 namespace for all classes

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
