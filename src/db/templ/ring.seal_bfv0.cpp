// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.seal.cpp Name=$Name

e3::SealEvalKey * g_pek_$Name = nullptr;
e3::SealEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    auto plaintextModulus = e3::e3seal::toek(pek->key)->plaintextModulus;
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
    {
        x.p->ct[i] += a.x.p->ct[i];
        x.p->ct[i] %= plaintextModulus;
    }
    return *this;
}

$Name & $Name::operator-=(const $Name & a)
{
    auto plaintextModulus = e3::e3seal::toek(pek->key)->plaintextModulus;
    for ( size_t i = 0; i < x.p->ct.size(); i++ )
    {
        x.p->ct[i] += plaintextModulus - a.x.p->ct[i];
        x.p->ct[i] %= plaintextModulus;
    }
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    auto plaintextModulus = e3::e3seal::toek(pek->key)->plaintextModulus;
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

$Name $Name::operator-() const
{
    return *zero - *this;
}

$Name $Name::operator*(const $Name & a) const
{
    $Name r(*this);
    r *= a;
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

$Name & $Name::rotate_columns()
{
    if ( slots() > 1 )
    {
        auto n = x.p->ct.size();
        auto half = n >> 1;
        for ( size_t i = 0; i < half; i++ )
            std::swap( x.p->ct[i], x.p->ct[i + half] );
    }
    return *this;
}

$Name & $Name::rotate_rows(int s)
{
    if ( slots() > 1 )
    {
        $Name a(*this);
        auto n = static_cast<int>(x.p->ct.size());
        auto half = n >> 1;
        s %= half;
        if (s < 0) s += half;
        for ( int i = 0; i < half; i++ )
        {
            x.p->ct[i] = a.x.p->ct[ (i + s) % half ];
            x.p->ct[i + half] = a.x.p->ct[ half + ((i + s) % half) ];
        }
    }
    return *this;
}

// === END  ring.seal.cpp Name=$Name
