
#include "e3util.h"
#include "def_heli0.h"

int e3::heli_impl() { return 0; }

e3::HeliNativeBt::HeliNativeBt(cHeliNativeEvalKey ek): ctxt(new HeliCtxt) {}

e3::HeliNativeBt::HeliNativeBt(const std::string & enc, cHeliNativeEvalKey ek)
    : HeliNativeBt(ek)
{
    if ( enc == "0" ) ctxt->b = false;
    else if ( enc == "1" ) ctxt->b = true;
    else throw "Bad init in HeliNativeBt [" + enc + "]";
}

std::string e3::HeliNativeBt::str(cHeliNativeEvalKey ek) const
{
    return ctxt->b ? "1" : "0";
}

e3::HeliNativeBt::HeliNativeBt(const HeliNativeBt & b, cHeliNativeEvalKey ek)
    : HeliNativeBt(ek)
{
    ctxt->b = b.ctxt->b;
}

