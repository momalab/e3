// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.seal_ckks.cpp Name=$Name

e3::SealCkksEvalKey * g_pek_$Name = nullptr;
e3::SealCkksEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
        x.p->ct[i] += a.x.p->ct[i];
    return *this;
}

$Name & $Name::operator-=(const $Name & a)
{
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
        x.p->ct[i] -= a.x.p->ct[i];
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
        x.p->ct[i] *= a.x.p->ct[i];
    return *this;
}

$Name $Name::operator+(const $Name & a) const
{
    $Name r(*this);
    r += a;
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    $Name r(*this);
    r -= a;
    return r;
}

$Name $Name::operator*(const $Name & a) const
{
    $Name r(*this);
    r *= a;
    return r;
}

// === END  ring.seal_ckks.cpp Name=$Name
