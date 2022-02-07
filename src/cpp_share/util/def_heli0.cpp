// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "e3util.h"
#include "def_heli0.h"

int e3::heli_impl() { return 0; }

e3::HeliNativeBt::HeliNativeBt(cHeliNativeEvalKey k): ek(k), ctxt(new HeliCtxt) {}

e3::HeliNativeBt::HeliNativeBt(const std::string & enc, cHeliNativeEvalKey k)
    : HeliNativeBt(k)
{
    if ( enc == "0" ) ctxt->b = false;
    else if ( enc == "1" ) ctxt->b = true;
    else throw "Bad init in HeliNativeBt [" + enc + "]";
}

std::string e3::HeliNativeBt::str(cHeliNativeEvalKey k) const
{
    return ctxt->b ? "1" : "0";
}

e3::HeliNativeBt::HeliNativeBt(const HeliNativeBt & b, cHeliNativeEvalKey k)
    : HeliNativeBt(k)
{
    ctxt->b = b.ctxt->b;
}

