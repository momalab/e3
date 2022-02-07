// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.pilc.cpp Name=$Name

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    e3::PilArith pa(kb());
    $NameBit r;
    r.x = unit->x - a.x;
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    e3::PilArith pa(kb());
    $NameBit r;
    r.x = a.x * b.x;
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    e3::PilArith pa(kb());
    $NameBit r;
    r.x = a.x + b.x - a.x * b.x;
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_or(a, b));
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_xor(a, b));
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    e3::PilArith pa(kb());
    $NameBit r;
    auto z = a.x * b.x;
    r.x = a.x + b.x - ( z + z );
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    e3::PilArith pa(kb());
    $NameBit r;
    auto z = a.x * b.x;
    auto u = a.x * c.x;
    r.x = z - u + c.x;
    return r;
}

// === END circuit.pilc.cpp Name=$Name
