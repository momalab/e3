// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.seal_bfv1.cpp Name=$Name
#include <iostream>

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
    $NameBit r;
    if ( $NameBit_ek()->params->plain_modulus() == 2 )
        $NameBit_ek()->evaluator->negate(a.nb.p->ct, r.nb.p->ct);
    else
        $NameBit_ek()->evaluator->sub(unit->nb.p->ct, a.nb.p->ct, r.nb.p->ct);
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    $NameBit_ek()->evaluator->multiply(a.nb.p->ct, b.nb.p->ct, r.nb.p->ct);
    $NameBit_ek()->evaluator->relinearize_inplace(r.nb.p->ct, $NameBit_ek()->relinkeys);
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    if ( $NameBit_ek()->params->plain_modulus() == 2 )
        r = gate_xor( gate_xor(a, b), gate_and(a, b) );
    else
    {
        $NameBit tmp;
        $NameBit_ek()->evaluator->multiply(a.nb.p->ct, b.nb.p->ct, tmp.nb.p->ct);
        $NameBit_ek()->evaluator->relinearize_inplace(tmp.nb.p->ct, $NameBit_ek()->relinkeys);
        $NameBit_ek()->evaluator->add(a.nb.p->ct, b.nb.p->ct, r.nb.p->ct);
        $NameBit_ek()->evaluator->sub_inplace(r.nb.p->ct, tmp.nb.p->ct);
    }
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    return gate_not( gate_and(a, b) );
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    return gate_and( gate_not(a), gate_not(b) );
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    return gate_not( gate_xor(a, b) );
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    if ( $NameBit_ek()->params->plain_modulus() == 2 )
    {
        $NameBit_ek()->evaluator->add(a.nb.p->ct, b.nb.p->ct, r.nb.p->ct);
    }
    else
    {
        $NameBit tmp;
        $NameBit_ek()->evaluator->multiply(a.nb.p->ct, b.nb.p->ct, tmp.nb.p->ct);
        $NameBit_ek()->evaluator->relinearize_inplace(tmp.nb.p->ct, $NameBit_ek()->relinkeys);
        $NameBit_ek()->evaluator->add_inplace(tmp.nb.p->ct, tmp.nb.p->ct);
        $NameBit_ek()->evaluator->add(a.nb.p->ct, b.nb.p->ct, r.nb.p->ct);
        $NameBit_ek()->evaluator->sub_inplace(r.nb.p->ct, tmp.nb.p->ct);
    }
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    $NameBit r;
    $NameBit_ek()->evaluator->sub(c.nb.p->ct, b.nb.p->ct, r.nb.p->ct);
    r = gate_and(a, r);
    $NameBit_ek()->evaluator->add_inplace(r.nb.p->ct, c.nb.p->ct);
    return r;
    // if ( $NameBit_ek()->params->plain_modulus() == 2 )
    //     return gate_xor(gate_and(a, b), gate_and(gate_not(a), c));
    // else
    //     return gate_or(gate_and(a, b), gate_and(gate_not(a), c));

}

$NameBit & $NameBit::rotate_columns()
{
    auto ek = $NameBit_ek();
    if ( ek->isBatchEncoder )
        ek->evaluator->rotate_columns_inplace( nb.p->ct, ek->galoiskeys );
    return *this;
}

$NameBit & $NameBit::rotate_rows(int s)
{
    auto ek = $NameBit_ek();
    if ( ek->isBatchEncoder )
        ek->evaluator->rotate_rows_inplace( nb.p->ct, s, ek->galoiskeys );
    return *this;
}

// === END circuit.seal_bfv1.cpp Name=$Name
