// === BEGIN circuit.tfhe.cpp Name=$Name

#include "def_fhew1.h"

inline const TFheGateBootstrappingCloudKeySet * $NameBit_ek()
{
    FIXME
    return e3fhew::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r;
    FHEW::HomNOT(&r.nb, a.nb);
    // bootsNOT( &*r.nb.p, &*a.nb.p, $NameBit_ek() );
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    FHEW::HomGate(&r.nb, AND, Fhe::fhe->ek->key, a.nb, b.nb);
    // bootsAND(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek() );
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    FHEW::HomGate(&r.nb, OR, Fhe::fhe->ek->key, a.nb, b.nb);
    // bootsOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    FHEW::HomGate(&r.nb, NOR, Fhe::fhe->ek->key, a.nb, b.nb);
    // bootsNOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit tmp1, tmp2, r;
    HomGate(&tmp1.nb, NOR, Fhe::fhe->ek->key, a.nb, b.nb);
    HomGate(&tmp2.nb, AND, Fhe::fhe->ek->key, a.nb, b.nb);
    HomGate(&r.nb, OR, Fhe::fhe->ek->key, tmp1.nb, tmp2.nb);
    // bootsXNOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    r = Fhe::gate_xnor(a, b);
    r = Fhe::gate_not(r);
    // bootsXOR(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek());
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    // (c and (not a)) or (b and a)
    $NameBit tmp1, tmp2;
    tmp1 = Fhe::gate_not(a);
    tmp1 = Fhe::gate_and(c, tmp1);
    tmp2 = Fhe::gate_and(b, a);
    return Fhe::gate_or(tmp1, tmp2);
    // bootsMUX(&*r.nb.p, &*a.nb.p, &*b.nb.p, &*c.nb.p, $NameBit_ek());
    return r;
}

// === END circuit.tfhe.cpp Name=$Name
