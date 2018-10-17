
#include "e3util.h"
#include "def_heli1.h"
#include "ol.h"

std::string heli_impl() { return "1"; }


std::string HeliNativeBit::str(cHeliNativeEvalKey ek) const
{
    never("FIXME");
}

HeliNativeBit::HeliNativeBit(cHeliNativeEvalKey ek)
{
    ctxt = std::shared_ptr<HeliCtxt>(new HeliCtxt(e3heli::toek(ek)));
}

HeliNativeBit::HeliNativeBit(const HeliNativeBit & b, cHeliNativeEvalKey ek)
    : HeliNativeBit(ek)
{
    never("FIXME");
}

HeliNativeBit::HeliNativeBit(const std::string & enc, cHeliNativeEvalKey ek)
    : HeliNativeBit(ek)
{
    never("FIXME");
}

