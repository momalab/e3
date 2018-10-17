
#include "e3util.h"
#include "def_tfhe0.h"

std::string tfhe_impl() { return "0"; }

TfheNativeBit::TfheNativeBit(cTfheNativeEvalKey ek): p(new LweSample) {}

TfheNativeBit::TfheNativeBit(const std::string & enc, cTfheNativeEvalKey ek) : TfheNativeBit(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in TfheNativeBit [" + enc + "]";
}

std::string TfheNativeBit::str(cTfheNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

TfheNativeBit::TfheNativeBit(const TfheNativeBit & b, cTfheNativeEvalKey ek) : TfheNativeBit(ek)
{
    p->b = b.p->b;
}

