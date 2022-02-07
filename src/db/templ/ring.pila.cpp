// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.pila.cpp Name=$Name

e3::PilaEvalKey * g_pek_$Name = nullptr;
e3::PilaEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

// public encryption
$Name::$Name(unsigned long long z) : $Name()
{
    e3::init_by_ull < $Name, e3::PilQuad, e3::PilaEvalKey >
    (*this, x, z, *zero, *unit, pek);
}


$Name $Name::operator+(const $Name & a) const
{
    e3::PilArith pa(pek);
    $Name r;
    r.x = x + a.x;
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    e3::PilArith pa(pek);
    $Name r;
    r.x = x - a.x;
    return r;
}

$Name $Name::operator*(const $Name & a) const
{
    e3::PilArith pa(pek);
    $Name r;
    r.x = x * a.x;
    return r;
}


// === END  ring.pila.cpp Name=$Name
