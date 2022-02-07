// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.heli.cpp Name=$Name

const double NOISE_LIMITA = -20;
const double NOISE_LIMITX = -210;
const bool PRN_BOOT = false;

inline const FHEPubKey * $NameBit_ek()
{
    return e3heli::toek($NameBit::k()->native());
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

void recrypt(const FHEPubKey * ck, Ctxt & c, const string & s, bool ux)
{
    double lim = NOISE_LIMITA;
    if ( ux ) lim = NOISE_LIMITX;

    FHEPubKey * k = const_cast<FHEPubKey *>(ck);

    if (c.log_of_ratio() > lim)
    {
        if (PRN_BOOT) cout << "(" << s << ":" << (-c.log_of_ratio()) << "-" << std::flush;
        k->reCrypt(c);
        if (PRN_BOOT) cout << (-c.log_of_ratio()) << ")" << std::flush;;
    }
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    $NameBit r = a;
    Ctxt & c = r.nb.ctxt->b;
    c.multiplyBy(b.nb.ctxt->b);
    recrypt($NameBit_ek(), c, "and", false);
    return r;
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    return gate_not(gate_and(a, b));
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    $NameBit r = a;
    Ctxt & c = r.nb.ctxt->b;
    // c.addConstant(to_ZZX(1));
    c.addCtxt(unit->nb.ctxt->b);
    recrypt($NameBit_ek(), c, "not", false);
    return r;
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    $NameBit r = a, t = a;
    Ctxt & cr = r.nb.ctxt->b;
    Ctxt & ct = t.nb.ctxt->b;
    const Ctxt & cb = b.nb.ctxt->b;

    cr.multiplyBy(cb);
    ct.addCtxt(cb);
    cr.addCtxt(ct);

    recrypt($NameBit_ek(), cr, "or", false);
    return r;
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    return gate_and(gate_not(a), gate_not(b));
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r = a;
    Ctxt & cr = r.nb.ctxt->b;
    const Ctxt & cb = b.nb.ctxt->b;

    cr.addCtxt(cb);
    // cr.addConstant(to_ZZX(1));
    cr.addCtxt(unit->nb.ctxt->b);


    recrypt($NameBit_ek(), cr, "xnor", true);
    return r;
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    $NameBit r = a;
    Ctxt & cr = r.nb.ctxt->b;
    const Ctxt & cb = b.nb.ctxt->b;

    cr.addCtxt(cb);

    recrypt($NameBit_ek(), cr, "xor", true);
    return r;
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    $NameBit r = b;
    Ctxt & cr = r.nb.ctxt->b;
    const Ctxt & cc = c.nb.ctxt->b;
    const Ctxt & ca = a.nb.ctxt->b;

    cr.addCtxt(cc, true);
    cr.multiplyBy(ca);
    cr.addCtxt(cc);

    recrypt($NameBit_ek(), cr, "mux", false);
    return r;
}

// === END circuit.heli.cpp Name=$Name
