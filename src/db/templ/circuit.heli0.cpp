// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.heli.cpp Name=$Name

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r;
    auto y = a.nb.ctxt->b;

    y = !y;

    r.nb.ctxt->b = y;
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;

    ma &= mb;

    r.nb.ctxt->b = ma;
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;

    ma |= mb;

    r.nb.ctxt->b = ma;
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;

    ma = !(ma & mb);

    r.nb.ctxt->b = ma;
    return r;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;

    ma = !(ma | mb);

    r.nb.ctxt->b = ma;
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;

    ma = !(ma ^ mb);

    r.nb.ctxt->b = ma;
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;

    ma ^= mb;

    r.nb.ctxt->b = ma;
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    $NameBit r;
    auto ma = a.nb.ctxt->b;
    auto mb = b.nb.ctxt->b;
    auto mc = c.nb.ctxt->b;

    ma = ma ? mb : mc;

    r.nb.ctxt->b = ma;
    return r;
}

// === END circuit.heli.cpp Name=$Name
