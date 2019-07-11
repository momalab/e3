
#include "e3util.h"
#include "def_heli0.h"

int heli_impl() { return 0; }

HeliNativeBt::HeliNativeBt(cHeliNativeEvalKey ek): ctxt(new HeliCtxt) {}

HeliNativeBt::HeliNativeBt(const std::string & enc, cHeliNativeEvalKey ek)
    : HeliNativeBt(ek)
{
    if ( enc == "0" ) ctxt->b = false;
    else if ( enc == "1" ) ctxt->b = true;
    else throw "Bad init in HeliNativeBt [" + enc + "]";
}

std::string HeliNativeBt::str(cHeliNativeEvalKey ek) const
{
    return ctxt->b ? "1" : "0";
}

HeliNativeBt::HeliNativeBt(const HeliNativeBt & b, cHeliNativeEvalKey ek)
    : HeliNativeBt(ek)
{
    ctxt->b = b.ctxt->b;
}

