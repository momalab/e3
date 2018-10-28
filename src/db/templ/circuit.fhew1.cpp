// === BEGIN circuit.tfhe.cpp Name=$Name

#include "def_fhew1.h"

inline const FHEW::EvalKey * $NameBit_ek()
{
    return e3fhew::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return a;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_or(a, b));
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    std::cout << "AAA c a " << ((void *)&a.nb.p->b) << '\n';
    std::cout << "AAA c b " << ((void *)&b.nb.p->b) << '\n';
    if ( &a.nb.p->b == &b.nb.p->b ) return gate_not(a);
    $NameBit r;
    FHEW::HomGate(&r.nb.p->b, NOR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
/// if( a.nb.p->b == b.nb.p->b ) return a;
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    std::cout << "AAA c a " << ((void *)&a.nb.p->b) << '\n';
    std::cout << "AAA c b " << ((void *)&b.nb.p->b) << '\n';
    $NameBit na = gate_not(a);
    $NameBit nb = gate_not(b);
    std::cout << "AAA cna " << ((void *)&na.nb.p->b) << '\n';
    std::cout << "AAA cnb " << ((void *)&nb.nb.p->b) << '\n';

    $NameBit r;
    FHEW::HomGate(&r.nb.p->b, OR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return r;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    $NameBit r;
    FHEW::HomNOT(&r.nb.p->b, a.nb.p->b);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return r;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
//  LWE::CipherText x,y,z;
//    FHEW::HomGate(&z, AND, *$NameBit_ek(), x, y);


    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << ' ' << ((void *)$NameBit_ek()) << '\n';
    $NameBit r;
    FHEW::HomGate(&r.nb.p->b, AND, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return r;
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
//std::cout<<"AAA c0 "<<__LINE__<<__FUNCTION__<<'\n';
    //return gate_not(gate_xor(a, b));
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    std::cout << "AAA c a " << ((void *)&a.nb.p->b) << '\n';
    std::cout << "AAA c b " << ((void *)&b.nb.p->b) << '\n';
    $NameBit tmp1, tmp2, r;
    HomGate(&tmp1.nb.p->b, NOR, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    std::cout << "AAA c1 " << __LINE__ << __FUNCTION__ << '\n';
    HomGate(&tmp2.nb.p->b, AND, *$NameBit_ek(), a.nb.p->b, b.nb.p->b);
    std::cout << "AAA c2 " << __LINE__ << __FUNCTION__ << '\n';
    HomGate(&r.nb.p->b, OR, *$NameBit_ek(), tmp1.nb.p->b, tmp2.nb.p->b);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    // (c and (not a)) or (b and a)
    $NameBit tmp1, tmp2;
    tmp1 = gate_not(a);
    tmp1 = gate_and(c, tmp1);
    tmp2 = gate_and(b, a);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return gate_or(tmp1, tmp2);
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    $NameBit r;
    r = gate_xnor(a, b);
    r = gate_not(r);
    std::cout << "AAA c " << __LINE__ << __FUNCTION__ << '\n';
    return r;
}

// === END circuit.tfhe.cpp Name=$Name
