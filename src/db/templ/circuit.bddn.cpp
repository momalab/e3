// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.bddn.cpp Name=$Name

// using BDD not is faster with BDDing NOT via NAND
#define USEBDDNOT 1

#include "x.$tid/bdd_nand.c"

#ifdef USEBDDNOT
#include "x.$tid/bdd_not.c"
#endif

#define USEXOR$tid$Name$CtSize $Modifier

#if USEXOR$tid$Name$CtSize == 1
#include "x.$tid/bdd_xor.c"
#else
void x_$tid_bdd_xor_binop_$CtSize(const char * a_, const char * b_, char * y_) {}
#endif

$NameBit $NameBit::gate_not(const $NameBit & a)
{
#ifdef USEBDDNOT
    $NameBit y;
    x_$tid_bdd_not_$CtSize_$CtSize(a.vc.data(), y.vc.data());
    return y;
#else
    return gate_nand(a, a);
#endif
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit x = gate_nand(a, b);
    return gate_not(x);
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    return gate_nand(gate_not(a), gate_not(b));
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_nand_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_nand(gate_not(a), gate_not(b)));
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
#if USEXOR$tid$Name$CtSize == 1
    return gate_not(gate_xor(a, b));
#else
#ifdef USEBDDNOT
    // [ ( A NAND B ) NAND ( NOT(A) NAND NOT(B) ) ]
    return gate_nand(gate_nand(a, b), gate_nand(gate_not(a), gate_not(b)));
#else
    return gate_not(gate_xor(a, b));
#endif
#endif
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
#if USEXOR$tid$Name$CtSize == 1
//#pragma message ("Using direct XOR")
    $NameBit y;
    x_$tid_bdd_xor_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
#else
//#pragma message ("Using NAND for XOR")
#ifdef USEBDDNOT
    // [ ( NOT(A) NAND B ) NAND ( A NAND NOT(B) ) ]
    return gate_nand(gate_nand(gate_not(a), b), gate_nand(a, gate_not(b)));
#else
    // [ A NAND ( A NAND B ) ] NAND [ B NAND ( A NAND B ) ]
    $NameBit ab = gate_nand(a, b);
    $NameBit aab = gate_nand(a, ab);
    $NameBit bab = gate_nand(b, ab);
    return gate_nand(aab, bab);
#endif
#endif
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
#if USEXOR$tid$Name$CtSize == 1
    // return gate_xor(gate_xor(gate_nand(a, b), gate_nand(a, c)),c);
    return gate_xor(gate_nand(a, b), gate_nand(gate_not(a), c));
#else
    return gate_nand(gate_nand(a, b), gate_nand(gate_not(a), c));
#endif
}

// === END circuit.bddn.cpp Name=$Name
