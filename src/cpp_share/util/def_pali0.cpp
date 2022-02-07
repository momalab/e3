// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include <algorithm>

#include "e3util.h"
#include "def_pali.h"
#include "def_pali0.h"
#include "ek_pali.h"

using std::string;

int e3::pali_impl() { return 0; }

e3::PaliBfvNativeCiphertext::PaliBfvNativeCiphertext()
{
    p = std::shared_ptr<e3::PaliBfvCiphertext>(
            new e3::PaliBfvCiphertext {std::vector<int64_t>()});
}

std::string e3::PaliBfvCiphertext::str() const
{
    return e3::util::merge(x, "^");
}

std::string e3::PaliBfvNativeCiphertext::str() const
{
    return !!p ? p->str() : "";
}

e3::PaliBfvNativeCiphertext::PaliBfvNativeCiphertext(const PaliBfvNativeCiphertext & x)
{
    p = x.p;
}

e3::PaliBfvNativeCiphertext::PaliBfvNativeCiphertext(const std::string & enc, const PaliBfvEvalKey * ek)
{
    if ( ek->slots() < 2 )
    {
        e3::pali::vi64 v {int64_t( std::stol(enc) )};
        p = std::shared_ptr<PaliBfvCiphertext>(new e3::PaliBfvCiphertext {v});
        return;
    }

    std::vector<string> sv = e3::util::split(enc, '^');
    e3::pali::vi64 m; for ( auto s : sv ) m.push_back(int64_t(std::stoull(s)));

    p = std::shared_ptr<e3::PaliBfvCiphertext>(new e3::PaliBfvCiphertext {m});
}


e3::PaliBfvNativeCiphertext e3::PaliBfvNativeCiphertext::op_add
(const e3::PaliBfvNativeCiphertext & a, void * pcc) const
{
    e3::PaliBfvNativeCiphertext r;
    r.p = std::shared_ptr<e3::PaliBfvCiphertext>(new PaliBfvCiphertext(*p + *a.p));
    return r;
}


e3::PaliBfvNativeCiphertext e3::PaliBfvNativeCiphertext::op_sub
(const e3::PaliBfvNativeCiphertext & a, void * pcc) const
{
    e3::PaliBfvNativeCiphertext r;
    r.p = std::shared_ptr<e3::PaliBfvCiphertext>(new PaliBfvCiphertext(*p - *a.p));
    return r;
}

e3::PaliBfvNativeCiphertext e3::PaliBfvNativeCiphertext::op_mul
(const e3::PaliBfvNativeCiphertext & a, void * pcc) const
{
    e3::PaliBfvNativeCiphertext r;
    r.p = std::shared_ptr<e3::PaliBfvCiphertext>(new PaliBfvCiphertext(*p ** a.p));
    return r;
}

static e3::PaliBfvCiphertext e3_PaliBfvCiphertext_op
(const e3::PaliBfvCiphertext & a, const e3::PaliBfvCiphertext & b, int op)
{
    e3::PaliBfvCiphertext r;

    int sza = (int)a.x.size();
    int szb = (int)b.x.size();
    int sz = std::max(sza, szb);
    r.x = a.x;
    r.x.resize(sz, 0);

    for ( int i = 0; i < szb; i++ ) /// if ( i < sz2 )
        switch (op)
        {
            case 0: r.x[i] += b.x[i]; break;
            case 1: r.x[i] -= b.x[i]; break;
            case 2: r.x[i] *= b.x[i]; break;
            default: throw "Internal error 88115";
        }

    return r;
}

e3::PaliBfvCiphertext e3::PaliBfvCiphertext::operator+(const e3::PaliBfvCiphertext & a) const
{
    return e3_PaliBfvCiphertext_op(*this, a, 0);
}

e3::PaliBfvCiphertext e3::PaliBfvCiphertext::operator-(const e3::PaliBfvCiphertext & a) const
{
    return e3_PaliBfvCiphertext_op(*this, a, 1);
}

e3::PaliBfvCiphertext e3::PaliBfvCiphertext::operator*(const e3::PaliBfvCiphertext & a) const
{
    return e3_PaliBfvCiphertext_op(*this, a, 2);
}
