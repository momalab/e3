// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.seal_bfv0.cpp Name=$Name

inline const e3::e3seal::SealEvalKey * $NameBit_ek()
{
    return e3::e3seal::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        r.nb.p->ct[i] = (a.nb.p->ct[i]?0:1);
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        ma &= mb;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        ma |= mb;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        ma = (ma & mb)?0:1;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        ma = (ma | mb)?0:1;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        ma = (ma ^ mb)?0:1;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        ma ^= mb;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    // auto plaintextModulus = $NameBit_ek()->plaintextModulus;
    size_t slots = $NameBit_ek()->isBatchEncoder ? $NameBit_ek()->polyModulusDegree : 1;
    $NameBit r;
    r.nb.p->ct.resize( slots );
    for ( size_t i = 0; i < r.nb.p->ct.size(); i++ )
    {
        auto ma = a.nb.p->ct[i];
        auto mb = b.nb.p->ct[i];
        auto mc = c.nb.p->ct[i];
        ma = ma ? mb : mc;
        r.nb.p->ct[i] = ma;
        // r.nb.p->ct[i] %= plaintextModulus;
    }
    return r;
}

$NameBit & $NameBit::rotate_columns()
{
    auto n = nb.p->ct.size();
    auto half = n >> 1;
    for ( size_t i = 0; i < half; i++ )
        std::swap( nb.p->ct[i], nb.p->ct[i + half] );
    return *this;
}

$NameBit & $NameBit::rotate_rows(int s)
{
    $NameBit a(*this);
    auto n = (int)nb.p->ct.size();
    auto half = n >> 1;
    s %= half;
    if (s < 0) s += half;
    for ( int i = 0; i < half; i++ )
    {
        nb.p->ct[i] = a.nb.p->ct[ (i + s) % half ];
        nb.p->ct[i + half] = a.nb.p->ct[ half + ((i + s) % half) ];
    }
    return *this;
}

// === END circuit.seal_bfv0.cpp Name=$Name
