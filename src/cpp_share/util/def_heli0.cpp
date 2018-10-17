
#include "e3util.h"
#include "def_heli0.h"

std::string heli_impl() { return "0"; }

HeliNativeBit::HeliNativeBit(cHeliNativeEvalKey ek): p(new HeliCtxt) {}

HeliNativeBit::HeliNativeBit(const std::string & enc, cHeliNativeEvalKey ek)
    : HeliNativeBit(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in HeliNativeBit [" + enc + "]";
}

std::string HeliNativeBit::str(cHeliNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

HeliNativeBit::HeliNativeBit(const HeliNativeBit & b, cHeliNativeEvalKey ek)
    : HeliNativeBit(ek)
{
    p->b = b.p->b;
}

