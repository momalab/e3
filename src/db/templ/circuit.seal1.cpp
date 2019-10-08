// === BEGIN circuit.seal.cpp Name=$Name
#include <iostream>

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
    if ( $NameBit_ek()->params->plain_modulus() == 2 )
        $NameBit_ek()->evaluator->negate(a.nb.p->b, r.nb.p->b);
    else
        $NameBit_ek()->evaluator->sub(unit->nb.p->b, a.nb.p->b, r.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    $NameBit_ek()->evaluator->multiply(a.nb.p->b, b.nb.p->b, r.nb.p->b);
    $NameBit_ek()->evaluator->relinearize_inplace(r.nb.p->b, $NameBit_ek()->relinkeys);
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
        $NameBit_ek()->evaluator->multiply(a.nb.p->b, b.nb.p->b, tmp.nb.p->b);
        $NameBit_ek()->evaluator->relinearize_inplace(tmp.nb.p->b, $NameBit_ek()->relinkeys);
        $NameBit_ek()->evaluator->add(a.nb.p->b, b.nb.p->b, r.nb.p->b);
        $NameBit_ek()->evaluator->sub_inplace(r.nb.p->b, tmp.nb.p->b);
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
        $NameBit_ek()->evaluator->add(a.nb.p->b, b.nb.p->b, r.nb.p->b);
    }
    else
    {
        $NameBit tmp;
        $NameBit_ek()->evaluator->multiply(a.nb.p->b, b.nb.p->b, tmp.nb.p->b);
        $NameBit_ek()->evaluator->relinearize_inplace(tmp.nb.p->b, $NameBit_ek()->relinkeys);
        $NameBit_ek()->evaluator->add_inplace(tmp.nb.p->b, tmp.nb.p->b);
        $NameBit_ek()->evaluator->add(a.nb.p->b, b.nb.p->b, r.nb.p->b);
        $NameBit_ek()->evaluator->sub_inplace(r.nb.p->b, tmp.nb.p->b);
    }
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    if ( $NameBit_ek()->params->plain_modulus() == 2 )
        return gate_xor(gate_and(a, b), gate_and(gate_not(a), c));
    else
        return gate_or(gate_and(a, b), gate_and(gate_not(a), c));
}

// === END circuit.seal.cpp Name=$Name
