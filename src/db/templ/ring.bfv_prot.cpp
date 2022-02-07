// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN ring.bfv_prot.cpp Name=$Name

e3::BfvProtEvalKey * g_pek_$Name = nullptr;
e3::BfvProtEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    throw __LINE__;
}

$Name & $Name::operator-=(const $Name & a)
{
    throw __LINE__;
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    throw __LINE__;
    return *this;
}

$Name $Name::operator+(const $Name & a) const
{
    throw __LINE__;
    $Name r(*this);
    r += a;
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    throw __LINE__;
    $Name r(*this);
    r -= a;
    return r;
}

$Name $Name::operator-() const
{
    throw __LINE__;
    return *zero - *this;
}

$Name $Name::operator*(const $Name & a) const
{
    throw __LINE__;
    $Name r(*this);
    r *= a;
    return r;
}

$Name $Name::operator*(const std::vector<unsigned long long> & v) const
{
    throw __LINE__;
    $Name u(v);
    return *this * u;
}

$Name $Name::operator+(const std::vector<unsigned long long> & v) const
{
    throw __LINE__;
    $Name u(v);
    return *this + u;
}

$Name $Name::operator-(const std::vector<unsigned long long> & v) const
{
    throw __LINE__;
    $Name u(v);
    return *this - u;
}

// === END ring.bfv_prot.cpp Name=$Name
