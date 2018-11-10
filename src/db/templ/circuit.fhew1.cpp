// === BEGIN circuit.tfhe.cpp Name=$Name

#include "def_fhew1.h"

inline const FHEW::EvalKey * $NameBit_ek()
{
    return e3fhew::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r;
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    FHEW::HomNOT(&r.nb.p->b, a.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    ///std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    FHEW::HomGate(&r.nb.p->b, AND, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    FHEW::HomGate(&r.nb.p->b, OR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    // FHEW::HomGate(&r.nb, OR, Fhe::fhe->ek->key, a.nb, b.nb);
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    FHEW::HomGate(&r.nb.p->b, NOR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit tmp1, tmp2, r;
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    HomGate(&tmp1.nb.p->b, NOR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    HomGate(&tmp2.nb.p->b, AND, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    HomGate(&r.nb.p->b, OR, *$NameBit_ek(), tmp1.nb.p->b, tmp2.nb.p->b);
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    r = gate_xnor(a, b);
    r = gate_not(r);
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    // (c and (not a)) or (b and a)
    $NameBit tmp1, tmp2;
    ///std::cout << "AAA c " << __LINE__ << ' ' << __FUNCTION__ << '\n';
    tmp1 = gate_not(a);
    tmp1 = gate_and(c, tmp1);
    tmp2 = gate_and(b, a);
    return gate_or(tmp1, tmp2);
}

// === END circuit.tfhe.cpp Name=$Name
