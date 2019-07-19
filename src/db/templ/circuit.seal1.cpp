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
    $NameBit r;
    // bootsNOT( &*r.nb.p, &*a.nb.p, $NameBit_ek() );
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    // $NameBit_ek().multiply(&*r.nb.p, &*a.nb.p, &*b.nb.p);
    // $NameBit_ek().evaluator.multiply(&*r.nb.p, &*a.nb.p, &*b.nb.p);
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    // bootsOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    // bootsNAND(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    // bootsNOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    // bootsXNOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    // bootsXOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    $NameBit r;
    // bootsMUX(&*r.nb.p, &*a.nb.p, &*b.nb.p, &*c.nb.p, $NameBit_ek());
    return r;
}

// === END circuit.seal.cpp Name=$Name
