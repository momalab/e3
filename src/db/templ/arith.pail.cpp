// === BEGIN arith.pail.cpp Name=$Name

e3::PailEvalKey * g_pek_$Name = nullptr;
e3::PailEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name $Name::operator+(const $Name & a) const
{
    $Name r;
    r.x = x.mulmod(a.x, pek->N2);
    return r;
}

$Name $Name::operator-() const
{
    $Name r;
    r.x = x.invmod(pek->N2);
    return r;
}

// === END arith.pail.cpp Name=$Name
