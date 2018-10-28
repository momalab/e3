#include <iostream>

#include "e3util.h"
#include "def_fhew1.h"
#include "base64.h"

std::string fhew_impl() { return "1"; }


std::string FhewNativeBit::str(cFhewNativeEvalKey ek) const
{
    const LWE::CipherText & nb = p->b;
    std::ostringstream os;
    for ( int i = 0; i < n; i++ ) os << nb.a[i] << '\n';
    os << '\n' << nb.b << '\n';
    return e3util::base64::enc(os.str());
}

FhewNativeBit::FhewNativeBit(cFhewNativeEvalKey ek)
{
    init_properties_fhew();
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
    ///std::istringstream is(enc);
    std::istringstream is(e3util::base64::dec(enc));
    for ( int i = 0; i < n; i++ ) is >> nb.a[i];
    is >> nb.b;
}

void init_properties_fhew()
{
    static bool inited = false;
    if ( inited ) return;
    inited = true;

    std::cout << "Initializing FHEW .. " << std::flush;
    FHEW::Setup();
    std::cout << "ok\n";
}

