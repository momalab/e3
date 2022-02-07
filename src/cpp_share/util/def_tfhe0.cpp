// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "e3util.h"
#include "def_tfhe0.h"

int e3::tfhe_impl() { return 0; }

e3::TfheNativeBt::TfheNativeBt(cTfheNativeEvalKey ek): p(new LweSample) {}

e3::TfheNativeBt::TfheNativeBt(const std::string & enc, cTfheNativeEvalKey ek) : TfheNativeBt(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in TfheNativeBt [" + enc + "]";
}

std::string e3::TfheNativeBt::str(cTfheNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

e3::TfheNativeBt::TfheNativeBt(const TfheNativeBt & b, cTfheNativeEvalKey ek) : TfheNativeBt(ek)
{
    p->b = b.p->b;
}

