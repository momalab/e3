// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.tfhe.cpp Name=$Name

inline const FHEW::EvalKey * $NameBit_ek()
{
    return e3fhew::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r;
    FHEW::HomNOT(&r.nb.p->b, a.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    FHEW::HomGate(&r.nb.p->b, AND, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    FHEW::HomGate(&r.nb.p->b, OR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    FHEW::HomGate(&r.nb.p->b, NOR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit tmp1, tmp2, r;
    HomGate(&tmp1.nb.p->b, NOR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    HomGate(&tmp2.nb.p->b, AND, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    HomGate(&r.nb.p->b, OR, *$NameBit_ek(), tmp1.nb.p->b, tmp2.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    r = gate_xnor(a, b);
    r = gate_not(r);
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    // (c and (not a)) or (b and a)
    $NameBit tmp1, tmp2;
    tmp1 = gate_not(a);
    tmp1 = gate_and(c, tmp1);
    tmp2 = gate_and(b, a);
    return gate_or(tmp1, tmp2);
}

// === END circuit.tfhe.cpp Name=$Name
