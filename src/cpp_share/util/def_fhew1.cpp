// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>

#include "e3util.h"
#include "def_fhew1.h"
#include "base64.h"

int e3::fhew_impl() { return 1; }


std::string e3::FhewNativeBt::str(cFhewNativeEvalKey ek) const
{
    const LWE::CipherText & nb = p->b;
    std::ostringstream os;
    for ( int i = 0; i < n; i++ ) os << nb.a[i] << '\n';
    os << '\n' << nb.b << '\n';
    return e3::util::base64::enc(os.str());
}

e3::FhewNativeBt::FhewNativeBt(cFhewNativeEvalKey ek)
{
    init_properties_fhew();
    p = std::shared_ptr<LweCipherText>(new LweCipherText);
}

e3::FhewNativeBt::FhewNativeBt(const FhewNativeBt & b, cFhewNativeEvalKey ek)
    : FhewNativeBt(ek)
{
    // p is initialized by previous c-tor
    p->b = b.p->b;
}

e3::FhewNativeBt::FhewNativeBt(const std::string & enc, cFhewNativeEvalKey ek)
    : FhewNativeBt(ek)
{
    LWE::CipherText & nb = p->b;
    std::istringstream is(e3::util::base64::dec(enc));
    for ( int i = 0; i < n; i++ ) is >> nb.a[i];
    is >> nb.b;
}

void e3::init_properties_fhew()
{
    static bool inited = false;
    if ( inited ) return;
    inited = true;

    std::cout << "Initializing FHEW .. " << std::flush;
    FHEW::Setup();
    std::cout << "ok\n";
}

