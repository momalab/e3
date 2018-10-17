#pragma once

#include <string>
#include <memory>

struct LweSample;

using TfheNativePrivKey = void * ;
using TfheNativeEvalKey = void * ;
using cTfheNativeEvalKey = const void * ;

///CircuitTfheEvalKey *

struct TfheNativeBit
{
    std::shared_ptr<LweSample> p;
    std::string str(cTfheNativeEvalKey) const;
    TfheNativeBit(cTfheNativeEvalKey ek); // new
    TfheNativeBit(const std::string & enc, cTfheNativeEvalKey ek);
    TfheNativeBit(const TfheNativeBit &) = delete;
    TfheNativeBit(const TfheNativeBit & b, cTfheNativeEvalKey ek);
};

std::string tfhe_impl(); // 0 or 1
