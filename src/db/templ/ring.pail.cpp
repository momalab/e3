// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.pail.cpp Name=$Name

e3::PailEvalKey * g_pek_$Name = nullptr;
e3::PailEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

// public encryption
$Name::$Name(unsigned long long z) : $Name()
{
    e3::init_by_ull < $Name, e3::Bigun, e3::PailEvalKey >
    (*this, x, z, *zero, *unit, pek);
}

$Name $Name::operator+(const $Name & a) const
{
    $Name r;
    r.x = x.mulmod(a.x, pek->getN2());
    return r;
}

$Name $Name::operator-() const
{
    $Name r;
    r.x = x.invmod(pek->getN2());
    return r;
}

// === END  ring.pail.cpp Name=$Name
