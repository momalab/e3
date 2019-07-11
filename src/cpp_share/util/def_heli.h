#pragma once

#include <string>
#include <memory>

// FIXME add e3 namespace for all classes

struct HeliCtxt;

using HeliNativePrivKey = void * ;
using HeliNativeEvalKey = void * ;
using cHeliNativeEvalKey = const void * ;

struct NativeProperties;

struct HeliNativeBt
{
    cHeliNativeEvalKey ek;
    std::shared_ptr<HeliCtxt> ctxt;
    std::string str(cHeliNativeEvalKey) const;
    HeliNativeBt(cHeliNativeEvalKey ek); // new
    HeliNativeBt(const std::string & enc, cHeliNativeEvalKey ek);
    HeliNativeBt(const HeliNativeBt &) = delete;
    HeliNativeBt(const HeliNativeBt & b, cHeliNativeEvalKey ek);
};

int heli_impl(); // 0 or 1

