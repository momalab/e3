#include <sstream>
#include <string>

#include "base64.h"
#include "def_tfhe1.h"

using std::string;

std::string tfhe_impl() { return "1"; }

std::string TfheNativeBit::str(cTfheNativeEvalKey ek) const
{
    std::ostringstream os;
    auto params = e3tfhe::toek(ek)->params;
    export_gate_bootstrapping_ciphertext_toStream(os, &*p, params);
    return e3util::base64::enc(os.str());
}

void delete_nativebit(LweSample * p) { delete_gate_bootstrapping_ciphertext(p); }
TfheNativeBit::TfheNativeBit(cTfheNativeEvalKey ek)
{
    auto params = e3tfhe::toek(ek)->params;
    p = std::shared_ptr<LweSample>(
            new_gate_bootstrapping_ciphertext_array(1, params),
            delete_nativebit);
}

TfheNativeBit::TfheNativeBit(const TfheNativeBit & b, cTfheNativeEvalKey ek) : TfheNativeBit(ek)
{
    p = b.p;
    bootsCOPY( &*p, &*b.p, e3tfhe::toek(ek) );
}

TfheNativeBit::TfheNativeBit(const std::string & enc, cTfheNativeEvalKey ek) : TfheNativeBit(ek)
{
    auto params = e3tfhe::toek(ek)->params;
    std::istringstream is(e3util::base64::dec(enc));
    try
    {
        import_gate_bootstrapping_ciphertext_fromStream(is, &*p, params);
    }
    catch (...)
    {
        throw "Bad init in TfheNativeBit [" + enc + "]";
    }
}

