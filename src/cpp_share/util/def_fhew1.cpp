
#include "e3util.h"
#include "def_fhew1.h"

std::string fhew_impl() { return "1"; }


std::string FhewNativeBit::str(cFhewNativeEvalKey ek) const
{
    const LWE::CipherText & nb = p->b;
    std::ostringstream os;
    for ( int i = 0; i < n; i++ ) os << nb.a[i] << '\n';
    os << '\n' << nb.b << '\n';
    return os.str();
}

inline int FhewInit() { FHEW::Setup(); return 1; }
FhewNativeBit::FhewNativeBit(cFhewNativeEvalKey ek)
{
    static bool inited = false;
    if ( !inited ) { FhewInit(); inited = true; }
    p = std::shared_ptr<LweCipherText>(new LweCipherText);
}

FhewNativeBit::FhewNativeBit(const FhewNativeBit & b, cFhewNativeEvalKey ek)
    : FhewNativeBit(ek)
{
    // p is initialized by previous c-tor
    p->b = b.p->b;
}

FhewNativeBit::FhewNativeBit(const std::string & enc, cFhewNativeEvalKey ek)
    : FhewNativeBit(ek)
{
    LWE::CipherText & nb = p->b;
    std::istringstream is(enc);
    for ( int i = 0; i < n; i++ ) is >> nb.a[i];
    is >> nb.b;
}

