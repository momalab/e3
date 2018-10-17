#pragma once

#include <string>
#include <memory>

struct HeliCtxt;

using HeliNativePrivKey = void * ;
using HeliNativeEvalKey = void * ;
using cHeliNativeEvalKey = const void * ;

struct NativeProperties;

struct HeliNativeBit
{
    std::shared_ptr<HeliCtxt> ctxt;
    std::string str(cHeliNativeEvalKey) const;
    HeliNativeBit(cHeliNativeEvalKey ek); // new
    HeliNativeBit(const std::string & enc, cHeliNativeEvalKey ek);
    HeliNativeBit(const HeliNativeBit &) = delete;
    HeliNativeBit(const HeliNativeBit & b, cHeliNativeEvalKey ek);
};

std::string heli_impl(); // 0 or 1
