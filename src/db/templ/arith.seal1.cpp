// === BEGIN arith.seal.cpp Name=$Name

e3::PilaEvalKey * g_pek_$Name = nullptr;
e3::PilaEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name $Name::operator+(const $Name & a) const
{
    $Name r;
    $NameBit_ek()->evaluator->add(a.nb.p->b, b.nb.p->b, r.nb.p->b);
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    $Name r;
    $NameBit_ek()->evaluator->sub(unit->nb.p->b, a.nb.p->b, r.nb.p->b);
    return r;
}

$Name $Name::operator*(const $Name & a) const
{
    $Name r;
    $NameBit_ek()->evaluator->multiply(a.nb.p->b, b.nb.p->b, r.nb.p->b);
    $NameBit_ek()->evaluator->relinearize_inplace(r.nb.p->b, $NameBit_ek()->relinkeys);
    return r;
}


// === END arith.seal.cpp Name=$Name
