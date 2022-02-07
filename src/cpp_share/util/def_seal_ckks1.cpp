// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include <string>

#include "base64.h"
#include "def_seal_ckks1.h"

// using namespace seal;
using std::string;

std::string e3::SealCkksNativeCiphertext::str() const
{
    std::ostringstream os;
    p->ct.save(os);
    return e3::util::base64::enc(os.str());
}

namespace e3
{

SealCkksNativeCiphertext::SealCkksNativeCiphertext()
{
    p = std::shared_ptr<SealCkksCiphertext>(new SealCkksCiphertext());
}

SealCkksNativeCiphertext::SealCkksNativeCiphertext(const SealCkksNativeCiphertext & a)
    : p(new SealCkksCiphertext)
{
    p->ct = a.p->ct;
}

SealCkksNativeCiphertext::SealCkksNativeCiphertext(const std::string & enc, cSealCkksNativeEvalKey ek)
    : SealCkksNativeCiphertext()
{
    std::istringstream is( e3::util::base64::dec(enc), std::ios::binary );
    try
    {
        auto & context = e3seal_ckks::toek(ek)->context;
#if SEALVER == 332
        p->ct.load( context, is );
#else
        p->ct.load( context, is );
#endif
    }
    catch (...)
    {
        throw "Bad init in SealCkksNativeCiphertext [" + enc + "]";
    }
}

} // e3
