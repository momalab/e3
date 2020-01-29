// === BEGIN  ring.seal.cpp Name=$Name

e3::SealEvalKey * g_pek_$Name = nullptr;
e3::SealEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    auto plaintextModulus = e3seal::toek(pek->key)->plaintextModulus;
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
    {
        x.p->ct[i] += a.x.p->ct[i];
        x.p->ct[i] %= plaintextModulus;
    }
    return *this;
}

$Name & $Name::operator-=(const $Name & a)
{
    auto plaintextModulus = e3seal::toek(pek->key)->plaintextModulus;
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
    {
        x.p->ct[i] -= a.x.p->ct[i];
        x.p->ct[i] %= plaintextModulus;
    }
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    auto plaintextModulus = e3seal::toek(pek->key)->plaintextModulus;
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
    {
        x.p->ct[i] *= a.x.p->ct[i];
        x.p->ct[i] %= plaintextModulus;
    }
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
