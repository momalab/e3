
#include "e3util.h"
#include "def_heli1.h"
#include "ol.h"
#include "base64.h"

std::string heli_impl() { return "1"; }


std::string HeliNativeBit::str(cHeliNativeEvalKey ek) const
{
    std::ostringstream os;
    os << ctxt->b;
///    return os.str();
    return e3util::base64::enc(os.str());
}

HeliNativeBit::HeliNativeBit(cHeliNativeEvalKey e) : ek(e)
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

