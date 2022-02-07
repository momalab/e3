// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_HELI_H_
#define _E3_DEF_HELI_H_

#include <string>
#include <memory>

namespace e3
{

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

} // e3

#endif // _E3_DEF_HELI_H_

