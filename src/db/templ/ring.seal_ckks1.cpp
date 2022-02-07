// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.seal_ckks.cpp Name=$Name

e3::SealCkksEvalKey * g_pek_$Name = nullptr;
e3::SealCkksEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    e3seal_ckks::toek(pek->key)->evaluator->add_inplace(x.p->ct, a.x.p->ct);
    return *this;
}

$Name & $Name::operator-=(const $Name & a)
{
    e3seal_ckks::toek(pek->key)->evaluator->sub_inplace(x.p->ct, a.x.p->ct);
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    auto ek = e3seal_ckks::toek(pek->key);
    ek->evaluator->multiply_inplace(x.p->ct, a.x.p->ct);
    ek->evaluator->relinearize_inplace(x.p->ct, ek->relinkeys);
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
