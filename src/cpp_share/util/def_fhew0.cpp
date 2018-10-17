
#include "e3util.h"
#include "def_fhew0.h"

std::string fhew_impl() { return "0"; }

FhewNativeBit::FhewNativeBit(cFhewNativeEvalKey ek): p(new LweCipherText) {}

FhewNativeBit::FhewNativeBit(const std::string & enc, cFhewNativeEvalKey ek)
    : FhewNativeBit(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in FhewNativeBit [" + enc + "]";
}

std::string FhewNativeBit::str(cFhewNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

FhewNativeBit::FhewNativeBit(const FhewNativeBit & b, cFhewNativeEvalKey ek)
    : FhewNativeBit(ek)
{
    p->b = b.p->b;
}

