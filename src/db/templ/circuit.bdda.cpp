// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.bdda.cpp Name=$Name

#define USENON$tid$Name$CtSize $Modifier

#include "x.$tid/bdd_not.c"

#if USENON$tid$Name$CtSize == 1
#include "x.$tid/bdd_nand.c"
#include "x.$tid/bdd_xnor.c"
#include "x.$tid/bdd_nor.c"
#else
#include "x.$tid/bdd_and.c"
#include "x.$tid/bdd_xor.c"
#include "x.$tid/bdd_or.c"
#endif


//#define FIZ std::cout<<(std::string("\nFIX ")+(__FILE__)+" : "+__FUNCTION__)<<'\n';

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit y;
    x_$tid_bdd_not_$CtSize_$CtSize(a.vc.data(), y.vc.data());
    return y;
}


// Using NAND, NOR, XNOR
#if USENON$tid$Name$CtSize == 1

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_nand_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_nand(a, b));
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_nor_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_nor(a, b));
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_xnor(a, b));
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_xnor_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    return gate_nand(gate_nand(a, b), gate_nand(gate_not(a), c));
}

// Using AND, OR, XOR
#else
$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_and_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_or_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
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
    $NameBit y;
    x_$tid_bdd_xor_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    return gate_or(gate_and(c, gate_not(a)), gate_and(b, a));
}

#endif


// === END circuit.bdda.cpp Name=$Name
