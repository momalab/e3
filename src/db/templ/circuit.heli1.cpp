// === BEGIN circuit.heli.cpp Name=$Name

#include "def_heli1.h"

const double NOISE_LIMITA = -20;
const double NOISE_LIMITX = -210;
const bool PRN_BOOT = false;

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

void recrypt(const FHEPubKey * ck, Ctxt & c, const string & s, bool ux)
{
	double lim = NOISE_LIMITA;
	if( ux ) lim = NOISE_LIMITX;

	FHEPubKey * k = const_cast<FHEPubKey*>(ck);
	
    if (c.log_of_ratio() > lim)
    {
        if (PRN_BOOT) cout << "(" << s << ":" << (-c.log_of_ratio()) << "-" << std::flush;
        k->reCrypt(c);
        if (PRN_BOOT) cout << (-c.log_of_ratio()) << ")" << std::flush;;
    }
}

/*
Fhe::Bit Fhe::gate_and(const Bit & a, const Bit & b) const
{
    Fhe::Bit r = a;
    Ctxt & c = r.nb.ctxt;
    c.multiplyBy(b.nb.ctxt);
    recrypt(ek->key, c, "and",false);
    return r;
}
$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    bootsAND(&*r.nb.p, &*a.nb.p, &*b.nb.p, $NameBit_ek() );
    return r;
}
*/

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
    Ctxt & c = r.nb.ctxt->b;
    c.multiplyBy(b.nb.ctxt->b);
    recrypt(e3heli::toek(r.nb.ek), c, "and",false);
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r;
	throw("FIXME heli1 gate_not");
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
	throw("FIXME heli1 gate_or");
    return r;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    return gate_and(gate_not(a),gate_not(b));
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
	throw("FIXME heli1 gate_xnor");
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r;
	throw("FIXME heli1 gate_xor");
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    $NameBit r;
	throw ("FIXME heli1 gate_mux");
    return r;
}

// === END circuit.heli.cpp Name=$Name

