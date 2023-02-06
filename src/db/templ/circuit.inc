// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.inc Name=$Name

// public encryption
template <int SZ>
$NameUint<SZ>::$NameUint(unsigned long long x) : $NameUint()
{
    std::string e = $NameBit::k()->encrypt(std::to_string(x), SZ);
    if ( !e.empty() ) { load(e); return; }

    for ( int i = 1; i < SZ; i++ ) bits[i] = *$NameBit::zero;

    if ( !x )
    {
        bits[0] = *$NameBit::zero;
        return;
    }

    bits[0] = *$NameBit::unit;

    // this does not (must not) call indirectly this ctor
    *this = e3::multiply_by_ull < $NameUint<SZ> > (*this, x);
}

template <int SZ>
$NameUint<SZ>::$NameUint(const std::vector<unsigned long long> & a) : $NameUint()
{
    std::string s = e3::util::merge(a, "_");
    std::string e = $NameBit::k()->encrypt(s, SZ);
    if ( !e.empty() ) { load(e); return; }
    throw "Operation not supported";
}

// Casting

template <int SZ> template <int Z>
$NameUint<SZ>::operator $NameUint<Z> () const
{
    $NameUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = *$NameBit::zero;
    }
    return r;
}

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
    this->d_inc(bits, r.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator++()
{
    $NameUint<SZ> r = (*this);
    this->d_inc(bits, r.bits);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator--(int)
{
    $NameUint<SZ> r = (*this);
    this->d_dec(bits, r.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator--()
{
    $NameUint<SZ> r = (*this);
    this->d_dec(bits, r.bits);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::bitsum() const
{
    $NameUint<SZ> r;
    this->d_bitsum(r.bits, bits, *$NameBit::zero);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator+(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;

    if (e3::CarryAdd::use) this->d_carryadd(r.bits, bits, x.bits);
    else this->d_add(r.bits, bits, x.bits);

    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator-(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_sub(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_mul(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator/(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_div(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator%(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_mod(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator&(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_bitand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator|(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_bitor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator^(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_bitxor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator<<(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_sll(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator>>(const $NameUint<SZ> & x) const
{
    $NameUint<SZ> r;
    this->d_slr(r.bits, bits, x.bits);
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
    this->d_bitnot(r.bits, bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!() const
{
    $NameBool r;
    this->d_lognot(r.bits, bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator==(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_eq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!=(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_ineq(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_lt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<=(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_le(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_gt(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>=(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_ge(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator&&(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_logand(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator||(const $NameUint<SZ> & x) const
{
    $NameBool r;
    this->d_logor(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const
{
    $NameUint<SZ> r;
    this->d_intmux(r.bits, bits, a.bits, b.bits);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(unsigned long long u) const
{
    return e3::multiply_by_ull < $NameUint<SZ> > (*this, u);
}

template <int SZ>
inline void $NameUint<SZ>::shiftLR(int n, int r)
{
    if ( n == 0 ) return;
    if ( n >= SZ )
    {
        for ( auto & b : bits ) b = *$NameBit::zero;
        return;
    }

    const auto & z = *$NameBit::zero;
    if ( r )
    {
        auto beg = bits.begin();
        bits.erase(beg, beg + n);
        bits.insert(bits.end(), n, z);
    }
    else
    {
        auto end = bits.end();
        bits.erase(end - n, end);
        bits.insert(bits.begin(), n, z);
    }
}

// Functions

template <int SZ>
void $NameUint<SZ>::load(const std::string & c)
{
    auto s = $NameBit::k()->decor(c, false);
    if ( s.empty() ) throw "Bad decoration in $Name [" + c + "]";
    auto bs = $NameBit::k()->enc2bits(s);
    if ( bs.empty() ) throw "(circuit.inc) Bad init in $Name [" + c + "]";

    for ( int i = 0; i < SZ; i++ )
    {
        if ( i < (int)bs.size() ) bits[i] = $NameBit(bs[i]);
        else bits[i] = *$NameBit::zero;
    }
}

template <int SZ>
$NameUint<SZ> & $NameUint<SZ>::rotate_columns()
{
    if ( slots() > 1 )
        for ( size_t i = 0; i < bits.size(); i++ ) bits[i].rotate_columns();
    return *this;
}

template <int SZ>
$NameUint<SZ> & $NameUint<SZ>::rotate_rows(int s)
{
    if ( slots() > 1 )
        for ( size_t i = 0; i < bits.size(); i++ ) bits[i].rotate_rows(s);
    return *this;
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

// Casting

template <int SZ> template <int Z>
$NameInt<SZ>::operator $NameInt<Z> () const
{
    $NameUint<Z> r;
    for ( int i = 0; i < Z; i++ )
    {
        if ( i < SZ ) r.bits[i] = bits[i];
        else r.bits[i] = bits[SZ - 1];
    }
    return r;
}

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
    this->d_divsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator%(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    this->d_modsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator-(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    this->d_sub(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator*(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    this->d_mul(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator+(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;

    if (e3::CarryAdd::use) this->d_carryadd(r.bits, bits, x.bits);
    else this->d_add(r.bits, bits, x.bits);

    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator>>(const $NameInt<SZ> & x) const
{
    $NameInt<SZ> r;
    this->d_srasig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<(const $NameInt<SZ> & x) const
{
    $NameBool r;
    this->d_ltsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<=(const $NameInt<SZ> & x) const
{
    $NameBool r;
    this->d_lesig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>(const $NameInt<SZ> & x) const
{
    $NameBool r;
    this->d_gtsig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>=(const $NameInt<SZ> & x) const
{
    $NameBool r;
    this->d_gesig(r.bits, bits, x.bits);
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator*(const $NameBool & a) const
{
    return a * (*this);
}

template <int SZ>
inline $NameInt<SZ> abs(const $NameInt<SZ> & x)
{
    $NameBool neg;
    neg[0] = x[SZ - 1];
    return x * !neg - x * neg;
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

inline $NameBool & $NameBool::operator&=(const $NameBool & x)
{
    (*this) = (*this) & x;
    return (*this);
}

inline $NameBool & $NameBool::operator|=(const $NameBool & x)
{
    (*this) = (*this) | x;
    return (*this);
}

inline $NameBool & $NameBool::operator^=(const $NameBool & x)
{
    (*this) = (*this) ^ x;
    return (*this);
}

inline $NameBool $NameBool::operator+(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) | $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator-(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) ^ $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator*(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) & $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator/(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) & $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator%(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) ^ $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator&(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) & $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator|(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) | $NameUint<1>(x) );
    return r;
}

inline $NameBool $NameBool::operator^(const $NameBool & x) const
{
    $NameBool r;
    r = $NameBool ( $NameUint<1>(*this) ^ $NameUint<1>(x) );
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
inline $NameInt<SZ> $NameBool::operator*(const $NameInt<SZ> & a) const
{
    $NameInt<SZ> r;
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
