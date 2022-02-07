// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include <string>

#include "base64.h"
#include "def_seal1.h"

// using namespace seal;
using std::string;

int e3::seal_impl() { return 1; }

std::string e3::SealNativeCiphertext::str() const
{
    std::ostringstream os;
    p->ct.save(os);
    return e3::util::base64::enc(os.str());
}

namespace e3
{

SealNativeCiphertext::~SealNativeCiphertext(){}

SealNativeCiphertext::SealNativeCiphertext()
{
    p = std::shared_ptr<SealCiphertext>(new SealCiphertext());
}

SealNativeCiphertext::SealNativeCiphertext(const SealNativeCiphertext & a)
    : p(new SealCiphertext)
{
    p->ct = a.p->ct;
}

SealNativeCiphertext::SealNativeCiphertext(const std::string & enc, cSealNativeEvalKey ek)
    : SealNativeCiphertext()
{
    std::istringstream is( e3::util::base64::dec(enc), std::ios::binary );
    try
    {
        auto & context = e3seal::toek(ek)->context;
#if SEALVER == 332
        p->ct.load( context, is );
#else
        p->ct.load( context, is );
#endif
    }
    catch (...)
    {
        throw "(def_seal1) Bad init in SealNativeCiphertext [" + enc + "]";
    }
}

} // e3
