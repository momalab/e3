// === BEGIN  ring.seal.cpp Name=$Name

e3::SealEvalKey * g_pek_$Name = nullptr;
e3::SealEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    e3seal::toek(pek->key)->evaluator->add_inplace(x.p->ct, a.x.p->ct);
    return *this;
}

$Name & $Name::operator-=(const $Name & a)
{
    e3seal::toek(pek->key)->evaluator->sub_inplace(x.p->ct, a.x.p->ct);
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    auto ek = e3seal::toek(pek->key);
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

// === END  ring.seal.cpp Name=$Name
