// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "e3util.h"
#include "def_fhew0.h"

int e3::fhew_impl() { return 0; }

e3::FhewNativeBt::FhewNativeBt(cFhewNativeEvalKey ek): p(new LweCipherText) {}

e3::FhewNativeBt::FhewNativeBt(const std::string & enc, cFhewNativeEvalKey ek)
    : FhewNativeBt(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in FhewNativeBt [" + enc + "]";
}

std::string e3::FhewNativeBt::str(cFhewNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

e3::FhewNativeBt::FhewNativeBt(const FhewNativeBt & b, cFhewNativeEvalKey ek)
    : FhewNativeBt(ek)
{
    p->b = b.p->b;
}

