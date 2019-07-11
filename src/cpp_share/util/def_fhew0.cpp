
#include "e3util.h"
#include "def_fhew0.h"

int fhew_impl() { return 0; }

FhewNativeBt::FhewNativeBt(cFhewNativeEvalKey ek): p(new LweCipherText) {}

FhewNativeBt::FhewNativeBt(const std::string & enc, cFhewNativeEvalKey ek)
    : FhewNativeBt(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in FhewNativeBt [" + enc + "]";
}

std::string FhewNativeBt::str(cFhewNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

FhewNativeBt::FhewNativeBt(const FhewNativeBt & b, cFhewNativeEvalKey ek)
    : FhewNativeBt(ek)
{
    p->b = b.p->b;
}

