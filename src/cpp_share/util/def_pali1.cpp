// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include <iostream>  // debug

// Palisade stuff
#include "palisade.h"

#include "e3util.h"
#include "base64.h"
#include "def_pali1.h"


// PART 1/4 - standard functions

int e3::pali_impl() { return 1; }


e3::PaliBfvNativeCiphertext::PaliBfvNativeCiphertext()
{
    p = std::shared_ptr<PaliBfvCiphertext>(new e3::PaliBfvCiphertext);
}

std::string e3::PaliBfvNativeCiphertext::str() const
{
    string bin = e3::pali::ct2str(p->ct);
    return e3::util::base64::enc(bin);
}

e3::PaliBfvNativeCiphertext::PaliBfvNativeCiphertext(const PaliBfvNativeCiphertext & x)
{
    p = x.p;
}

e3::PaliBfvNativeCiphertext::PaliBfvNativeCiphertext(const std::string & enc, const PaliBfvEvalKey * ek)
{
    string bin = e3::util::base64::dec(enc);
    e3::pali::Ct ct = e3::pali::str2ct(bin);

    p = std::shared_ptr<PaliBfvCiphertext>(new e3::PaliBfvCiphertext {ct});
}


// PART 2/4 - sis_fun


e3::PaliBfvNativeCiphertext e3::PaliBfvNativeCiphertext::op_add
(const e3::PaliBfvNativeCiphertext & a, void * pcc) const
{
    e3::PaliBfvNativeCiphertext r;
    e3::pali::Cc & cc = *e3::pali::tocc(pcc);
    auto ctadd = cc->EvalAdd(p->ct, a.p->ct);
    r.p = std::shared_ptr<e3::PaliBfvCiphertext>(new PaliBfvCiphertext {ctadd});
    return r;
}

e3::PaliBfvNativeCiphertext e3::PaliBfvNativeCiphertext::op_sub
(const e3::PaliBfvNativeCiphertext & a, void * pcc) const
{
    e3::PaliBfvNativeCiphertext r;
    e3::pali::Cc & cc = *e3::pali::tocc(pcc);
    auto ctadd = cc->EvalSub(p->ct, a.p->ct);
    r.p = std::shared_ptr<e3::PaliBfvCiphertext>(new PaliBfvCiphertext {ctadd});
    return r;
}

e3::PaliBfvNativeCiphertext e3::PaliBfvNativeCiphertext::op_mul
(const e3::PaliBfvNativeCiphertext & a, void * pcc) const
{
    e3::PaliBfvNativeCiphertext r;
    e3::pali::Cc & cc = *e3::pali::tocc(pcc);
    auto ctadd = cc->EvalMult(p->ct, a.p->ct);
    r.p = std::shared_ptr<e3::PaliBfvCiphertext>(new PaliBfvCiphertext {ctadd});
    return r;
}
