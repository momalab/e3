
#include "e3util.h"
#include "def_seal0.h"

int e3::seal_impl() { return 0; }

e3::SealNativeBt::SealNativeBt(cSealNativeEvalKey ek): p(new SealCiphertext) {}

e3::SealNativeBt::SealNativeBt(const std::string & enc, cSealNativeEvalKey ek) : SealNativeBt(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in SealNativeBt [" + enc + "]";
}

std::string e3::SealNativeBt::str(cSealNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

e3::SealNativeBt::SealNativeBt(const SealNativeBt & b, cSealNativeEvalKey ek) : SealNativeBt(ek)
{
    p->b = b.p->b;
}
