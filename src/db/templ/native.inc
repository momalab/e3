// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN native.inc Name=$Name

// Pointer to the manager
template <int SZ> e3::NativeEvalKey * $NameUint<SZ>::pek = nullptr;

// ----- $NameUint ----- //

// Constructors/Destructors

template <int SZ>
$NameUint<SZ>::$NameUint()
{
    if ( !pek ) initEvalKey(e3::KeyName {typname(), filname()}, pek, g_pek_$Name);
}

template <int SZ>
$NameUint<SZ>::$NameUint(unsigned long long m) : $NameUint<SZ>()
{
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
}

template <int SZ>
$NameUint<SZ>::$NameUint(const std::string & s) : $NameUint<SZ>()
{
    string c = pek->decor(s, false);
    x = e3::util::hex2ull(c);
    // hack to have valid plaintext
    // not applicable to other classes
    e3::util::ull m = pek->dec(x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
}

// Casting

template <int SZ> template <int Z>
$NameUint<SZ>::operator $NameUint<Z> () const
{
    e3::util::ull m = pek->dec(x);
    m &= e3::util::mask(Z);
    $NameUint<Z> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
$NameUint<SZ>::operator $NameBool () const
{
    return $NameUint<1> (*this);
}

/*
template <int SZ>
$NameUint<SZ>::operator bool () const
{
    static_assert
    (SZ == (-1), "Implicit conversion of SecureInt to bool is not "
     "allowed; this would leak information about the encrypted data");
    throw 0;
}
*/

// Operators

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator+=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m += pek->dec(a.x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator-=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m -= pek->dec(a.x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator*=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m *= pek->dec(a.x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator/=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m /= pek->dec(a.x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator%=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m %= pek->dec(a.x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator&=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator^=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator|=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator<<=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m <<= pek->dec(a.x);
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator>>=(const $NameUint<SZ> & a)
{
    e3::util::ull m = pek->dec(x);
    m >>= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator++(int)
{
    $NameUint r(*this);
    e3::util::ull m = pek->dec(x);
    m++;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator++()
{
    e3::util::ull m = pek->dec(x);
    m++;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator--(int)
{
    $NameUint r(*this);
    e3::util::ull m = pek->dec(x);
    m--;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator--()
{
    e3::util::ull m = pek->dec(x);
    m--;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator+(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r += a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator-(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r -= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r *= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator/(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r /= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator%(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator&(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r &= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator^(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r ^= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator|(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r |= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator<<(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r <<= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator>>(const $NameUint<SZ> & a) const
{
    $NameUint<SZ> r(*this);
    r >>= a;
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
    e3::util::ull m = pek->dec(x);
    m = ~m;
    m &= e3::util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!() const
{
    e3::util::ull m = pek->dec(x);
    m = (e3::util::ull) !m;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator==(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m == ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!=(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m != ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m < ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<=(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m <= ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m > ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>=(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m >= ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator&&(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m && ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator||(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    m = (e3::util::ull) m || ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    e3::util::ull mb = pek->dec(b.x);
    m = e3::util::ull (m ? ma : mb);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline std::ostream & operator<<(std::ostream & os, const $NameUint<SZ> & x)
{
    return os << x.str();
}

template <int SZ>
inline $NameUint<SZ> $NameBool::mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    e3::util::ull mb = pek->dec(b.x);
    m = m ? ma : mb;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(unsigned long long u) const
{
    return e3::multiply_by_ull < $NameUint<SZ >> (*this, u);
}


// Functions

template <int SZ>
std::string $NameUint<SZ>::str() const
{
    std::string s = e3::util::ull2hex(x);
    return pek->decor(s, true);
}


// ----- $NameInt ----- //

// Casting
template <int SZ> template <int Z>
$NameInt<SZ>::operator $NameInt<Z> () const
{
    e3::util::ull m = pek->dec(x);
    m = e3::util::signExtend(m, SZ);
    m &= e3::util::mask(Z);
    $NameInt<Z> r;
    r.x = pek->enc(m);
    return r;
}

// Operators

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator/=(const $NameInt<SZ> & a)
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m /= ma;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator%=(const $NameInt<SZ> & a)
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m %= ma;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator>>=(const $NameInt<SZ> & a)
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m >>= ma;
    m &= e3::util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator/(const $NameInt<SZ> & a) const
{
    $NameInt<SZ> r(*this);
    r /= a;
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator%(const $NameInt<SZ> & a) const
{
    $NameInt<SZ> r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline $NameInt<SZ> $NameInt<SZ>::operator>>(const $NameInt<SZ> & a) const
{
    $NameInt<SZ> r(*this);
    r >>= a;
    return r;
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<(const $NameInt<SZ> & a) const
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m = m < ma;
    m &= e3::util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<=(const $NameInt<SZ> & a) const
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m = m <= ma;
    m &= e3::util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>(const $NameInt<SZ> & a) const
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m = m > ma;
    m &= e3::util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>=(const $NameInt<SZ> & a) const
{
    e3::util::sll m = pek->dec(x);
    e3::util::sll ma = pek->dec(a.x);
    m = e3::util::signExtend(m, SZ);
    ma = e3::util::signExtend(ma, SZ);
    m = m >= ma;
    m &= e3::util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline std::ostream & operator<<(std::ostream & os, const $NameInt<SZ> & x)
{
    return os << x.str();
}

// ----- $NameBool ----- //

// Constructors/Destructors

template <int SZ>
inline $NameBool::$NameBool(const $NameUint<SZ> & a)
{
    e3::util::ull ma = pek->dec(a.x);
    e3::util::ull m = ma ? 1 : 0;
    x = pek->enc(m);
}

// Operators

inline $NameBool & $NameBool::operator+=(const $NameBool & a)
{
    e3::util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    // m &= e3::util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator-=(const $NameBool & a)
{
    e3::util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    // m &= e3::util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator*=(const $NameBool & a)
{
    e3::util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3::util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator/=(const $NameBool & a)
{
    e3::util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3::util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator%=(const $NameBool & a)
{
    e3::util::ull m = pek->dec(x);
    m ^= m;
    // m &= e3::util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool $NameBool::operator+(const $NameBool & a) const
{
    $NameBool r(*this);
    r += a;
    return r;
}

inline $NameBool $NameBool::operator-(const $NameBool & a) const
{
    $NameBool r(*this);
    r -= a;
    return r;
}

inline $NameBool $NameBool::operator*(const $NameBool & a) const
{
    $NameBool r(*this);
    r *= a;
    return r;
}

inline $NameBool $NameBool::operator/(const $NameBool & a) const
{
    $NameBool r(*this);
    r /= a;
    return r;
}

inline $NameBool $NameBool::operator%(const $NameBool & a) const
{
    $NameBool r(*this);
    r %= a;
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameBool::operator*(const $NameUint<SZ> & a) const
{
    e3::util::ull m = pek->dec(x);
    e3::util::ull ma = pek->dec(a.x);
    auto mr = m ? ma : 0;
    $NameUint<SZ> r;
    r.x = pek->enc(mr);
    return r;
}

// === END native.inc Name=$Name
