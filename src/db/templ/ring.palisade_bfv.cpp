// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN ring.palisade.cpp Name=$Name

e3::PaliBfvEvalKey * g_pek_$Name = nullptr;
e3::PaliBfvEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

// op+ is basic op, op+= - derived

$Name & $Name::operator-=(const $Name & a)
{
    return *this = *this - a;
}

$Name & $Name::operator*=(const $Name & a)
{
    return *this = *this * a;
}

$Name & $Name::operator+=(const $Name & a)
{
    return *this = *this + a;
}

$Name $Name::operator+(const $Name & a) const
{
    $Name r;
    r.x = x.op_add(a.x, pek->key.cc);
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    $Name r;
    r.x = x.op_sub(a.x, pek->key.cc);
    return r;
}

$Name $Name::operator-() const
{
    return *zero - *this;
}

$Name $Name::operator*(const $Name & a) const
{
    $Name r;
    r.x = x.op_mul(a.x, pek->key.cc);
    return r;
}

$Name $Name::operator*(const std::vector<unsigned long long> & v) const
{
    $Name u(v);
    return *this * u;
}

$Name $Name::operator+(const std::vector<unsigned long long> & v) const
{
    $Name u(v);
    return *this + u;
}

$Name $Name::operator-(const std::vector<unsigned long long> & v) const
{
    $Name u(v);
    return *this - u;
}

// === END ring.palisade.cpp Name=$Name
