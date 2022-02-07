// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.tfhe.cpp Name=$Name

inline const TFheGateBootstrappingCloudKeySet * $NameBit_ek()
{
    return e3tfhe::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r;
    bootsNOT( &*r.nb.p, &*a.nb.p, $NameBit_ek() );
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsAND(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek() );
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsNAND(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsNOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsXNOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsXOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    $NameBit r;
    bootsMUX(&*r.nb.p, &*a.nb.p, &*b.nb.p, &*c.nb.p, $NameBit_ek());
    return r;
}

// === END circuit.tfhe.cpp Name=$Name
