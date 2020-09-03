// === BEGIN circuit.seal.cpp Name=$Name

inline const e3seal::SealEvalKey * $NameBit_ek()
{
    return e3seal::toek($NameBit::k()->native());
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
        r.nb.p->ct[i] = !a.nb.p->ct[i];
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
        ma = !(ma & mb);
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
        ma = !(ma | mb);
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
        ma = !(ma ^ mb);
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

// === END circuit.seal.cpp Name=$Name
