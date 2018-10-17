#pragma once

#include <string>
#include <memory>

struct LweCipherText;

using FhewNativePrivKey = void * ;
using FhewNativeEvalKey = void * ;
using cFhewNativeEvalKey = const void * ;

struct FhewNativeBit
{
    std::shared_ptr<LweCipherText> p;
    std::string str(cFhewNativeEvalKey) const;
    FhewNativeBit(cFhewNativeEvalKey ek); // new
    FhewNativeBit(const std::string & enc, cFhewNativeEvalKey ek);
    FhewNativeBit(const FhewNativeBit &) = delete;
    FhewNativeBit(const FhewNativeBit & b, cFhewNativeEvalKey ek);
};

std::string fhew_impl(); // 0 or 1
