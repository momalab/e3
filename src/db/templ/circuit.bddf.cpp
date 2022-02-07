// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.bddf.cpp Name=$Name

#include "x.$tid/bdd_and.c"
#include "x.$tid/bdd_xor.c"
#include "x.$tid/bdd_not.c"
#include "x.$tid/bdd_or.c"

#include "x.$tid/bdd_nand.c"
#include "x.$tid/bdd_xnor.c"
#include "x.$tid/bdd_nor.c"

#define USEMUX$tid$Name$CtSize $Modifier

#if USEMUX$tid$Name$CtSize == 1
#include "x.$tid/bdd_mux.c"
#else
void x_$tid_bdd_mux_triop_$CtSize(const char * a_, const char * b_, const char * c_, char * y_) {}
#endif

//#define FIZ std::cout<<(std::string("\nFIX ")+(__FILE__)+" : "+__FUNCTION__)<<'\n';

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit y;
    x_$tid_bdd_not_$CtSize_$CtSize(a.vc.data(), y.vc.data());
    return y;
}

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
    $NameBit y;
    x_$tid_bdd_nand_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_nor_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit y;
    x_$tid_bdd_xnor_binop_$CtSize(a.vc.data(), b.vc.data(), y.vc.data());
    return y;
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
#if USEMUX$tid$Name$CtSize == 1
//#pragma message ("Using direct MUX")
    $NameBit y;
    x_$tid_bdd_mux_triop_$CtSize(a.vc.data(), b.vc.data(), c.vc.data(), y.vc.data());
    return y;
#else
//#pragma message ("Using NAND for MUX")
    return gate_nand(gate_nand(a, b), gate_nand(gate_not(a), c));
#endif
}

// === END circuit.bddf.cpp Name=$Name
