// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include <string>

#include "base64.h"
#include "def_tfhe1.h"

using std::string;

int e3::tfhe_impl() { return 1; }

std::string e3::TfheNativeBt::str(cTfheNativeEvalKey ek) const
{
    std::ostringstream os;
    auto params = e3tfhe::toek(ek)->params;
    export_gate_bootstrapping_ciphertext_toStream(os, &*p, params);
    return e3::util::base64::enc(os.str());
}

namespace e3
{

void delete_nativebit(LweSample * p) { delete_gate_bootstrapping_ciphertext(p); }
TfheNativeBt::TfheNativeBt(cTfheNativeEvalKey ek)
{
    auto params = e3tfhe::toek(ek)->params;
    p = std::shared_ptr<LweSample>(
            new_gate_bootstrapping_ciphertext_array(1, params),
            delete_nativebit);
}

} // e3

e3::TfheNativeBt::TfheNativeBt(const TfheNativeBt & b, cTfheNativeEvalKey ek) : TfheNativeBt(ek)
{
    p = b.p;
    bootsCOPY( &*p, &*b.p, e3tfhe::toek(ek) );
}

e3::TfheNativeBt::TfheNativeBt(const std::string & enc, cTfheNativeEvalKey ek) : TfheNativeBt(ek)
{
    auto params = e3tfhe::toek(ek)->params;
    std::istringstream is(e3::util::base64::dec(enc));
    try
    {
        import_gate_bootstrapping_ciphertext_fromStream(is, &*p, params);
    }
    catch (...)
    {
        throw "(def_tfhe1) Bad init in TfheNativeBt [" + enc + "]";
    }
}

