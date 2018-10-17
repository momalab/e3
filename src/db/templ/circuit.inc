// === BEGIN circuit.inc Name=$Name

// Operators

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator+=(const $NameUint<SZ> & x)
{
    (*this) = (*this) + x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator-=(const $NameUint<SZ> & x)
{
    (*this) = (*this) - x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator*=(const $NameUint<SZ> & x)
{
    (*this) = (*this) * x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator/=(const $NameUint<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator%=(const $NameUint<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator&=(const $NameUint<SZ> & x)
{
    (*this) = (*this) & x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator|=(const $NameUint<SZ> & x)
{
    (*this) = (*this) | x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator^=(const $NameUint<SZ> & x)
{
    (*this) = (*this) ^ x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator<<=(const $NameUint<SZ> & x)
{
    (*this) = (*this) << x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator>>=(const $NameUint<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator++(int)
{
    $NameUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator++()
{
    $NameUint<SZ> r = (*this);
    d_inc(bits, r.bits);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator--(int)
{
    $NameUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator--()
{
    $NameUint<SZ> r = (*this);
    d_dec(bits, r.bits);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator+(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_add(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator-(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_sub(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_mul(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator/(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_div(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator%(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_mod(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator&(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_bitand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator|(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_bitor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator^(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_bitxor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator<<(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_sll(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator>>(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    d_slr(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(const $NameBool & a) const
{
    return a * (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator~() const
{
    $NameUint<SZ> r;
    d_bitnot(r.bits, bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!() const
{
    $NameBool r;
    d_lognot(r.bits, bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator==(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_eq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!=(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_ineq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_lt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<=(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_le(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_gt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>=(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_ge(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator&&(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_logand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator||(const $NameUint<SZ> & x) const
{
    $NameBool r;
    d_logor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const
{
    $NameUint<SZ> r;
    d_intmux(r.bits, bits, a.bits, b.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < $NameUint<SZ >> (u, *this);
}

// Functions

template <int SZ>
void $NameUint<SZ>::load(const std::string & c)
{
    auto s = $NameBit::k()->decor(c, false);
    if ( s.empty() ) throw "Bad decoration in $Name, expecting [] :" + c;
    auto bs = $NameBit::k()->enc2bits(s);
    if ( bs.empty() ) throw "Bad init in $Name, expecting [] :" + c;

    for ( int i = 0; i < SZ; i++ )
    {
        if ( i < (int)bs.size() ) bits[i] = $NameBit(bs[i]);
        else bits[i] = *$NameBit::zero;
    }
}

template <int SZ>
std::string $NameUint<SZ>::str() const
{
    std::vector<std::string> bs;
    for ( const auto & x : bits ) bs.push_back(x.str());
    auto s = $NameBit::k()->bits2enc(bs);
    return $NameBit::k()->decor(s, true);
}

// ----- $NameInt ----- //

// Operators

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator/=(const $NameInt<SZ> & x)
{
    (*this) = (*this) / x;
    return (*this);
}

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator%=(const $NameInt<SZ> & x)
{
    (*this) = (*this) % x;
    return (*this);
}

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator>>=(const $NameInt<SZ> & x)
{
    (*this) = (*this) >> x;
    return (*this);
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator/(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    d_divsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator%(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    d_modsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator>>(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    d_srasig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<(const $NameInt<SZ> & x) const
{
    $NameBool r;
    d_ltsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<=(const $NameInt<SZ> & x) const
{
    $NameBool r;
    d_lesig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>(const $NameInt<SZ> & x) const
{
    $NameBool r;
    d_gtsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>=(const $NameInt<SZ> & x) const
{
    $NameBool r;
    d_gesig(r.bits, bits, x.bits);
    return r;
}

// ----- $NameBool ----- //

// Constructors/Destructors

template <int SZ>
$NameBool::$NameBool(const $NameUint<SZ> & a)
{
    $NameUint<SZ>::d_redor(bits, a.bits);
}

// Operators

inline $NameBool & $NameBool::operator+=(const $NameBool & x)
{
    (*this) = (*this) + x;
    return (*this);
}

inline $NameBool & $NameBool::operator-=(const $NameBool & x)
{
    (*this) = (*this) - x;
    return (*this);
}

inline $NameBool & $NameBool::operator*=(const $NameBool & x)
{
    (*this) = (*this) * x;
    return (*this);
}

inline $NameBool & $NameBool::operator/=(const $NameBool & x)
{
    (*this) = (*this) / x;
    return (*this);
}

inline $NameBool & $NameBool::operator%=(const $NameBool & x)
{
    (*this) = (*this) % x;
    return (*this);
}

inline $NameBool $NameBool::operator+(const $NameBool & x) const
{
    $NameBool r;
    r = (*this) | x;
    return r;
}

inline $NameBool $NameBool::operator-(const $NameBool & x) const
{
    $NameBool r;
    r = (*this) ^ x;
    return r;
}

inline $NameBool $NameBool::operator*(const $NameBool & x) const
{
    $NameBool r;
    r = (*this) & x;
    return r;
}

inline $NameBool $NameBool::operator/(const $NameBool & x) const
{
    $NameBool r;
    r = (*this) & x;
    return r;
}

inline $NameBool $NameBool::operator%(const $NameBool & x) const
{
    $NameBool r;
    r = (*this) ^ (*this);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameBool::operator*(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r;
    $NameUint<SZ>::d_boolmul(r.bits, bits, a.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameBool::mux(const $NameUint<SZ> & x, const $NameUint<SZ> & y) const
{
    $NameUint<SZ> r;
    $NameUint<SZ>::d_boolmux(r.bits, bits, x.bits, y.bits);
    return r;
}
// === END circuit.inc Name=$Name
