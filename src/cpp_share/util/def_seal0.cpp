
#include "e3util.h"
#include "def_seal0.h"

int e3::seal_impl() { return 0; }

e3::SealNativeCiphertext::SealNativeCiphertext(cSealNativeEvalKey ek): p(new SealCiphertext) {}

e3::SealNativeCiphertext::SealNativeCiphertext(const std::string & enc, cSealNativeEvalKey ek) : SealNativeCiphertext(ek)
{
    if ( enc == "0" ) p->b = false;
    else if ( enc == "1" ) p->b = true;
    else throw "Bad init in SealNativeCiphertext [" + enc + "]";
}

std::string e3::SealNativeCiphertext::str(cSealNativeEvalKey ek) const
{
    return p->b ? "1" : "0";
}

e3::SealNativeCiphertext::SealNativeCiphertext(const SealNativeCiphertext & b, cSealNativeEvalKey ek) : SealNativeCiphertext(ek)
{
    p->b = b.p->b;
}
