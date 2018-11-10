// === BEGIN native.inc Name=$Name

// Pointer to the manager
template <int SZ> NativeEvalKey * $NameUint<SZ>::pek = nullptr;

// ----- $NameUint ----- //

// Constructors/Destructors

template <int SZ>
$NameUint<SZ>::$NameUint()
{
    if ( !pek ) initEvalKey(name(), pek, g_pek_$Name);
}

template <int SZ>
$NameUint<SZ>::$NameUint(const std::string & c) : $NameUint<SZ>()
{
    x = e3util::hex2ull(c);
    // hack to have valid plaintext
    // not applicable to other classes
    e3util::ull m = pek->dec(x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
}

// Casting

template <int SZ> template <int Z>
$NameUint<SZ>::operator $NameUint<Z> () const
{
    e3util::ull m = pek->dec(x);
    m &= e3util::mask(Z);
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
    e3util::ull m = pek->dec(x);
    m += pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator-=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m -= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator*=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m *= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator/=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m /= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator%=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m %= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator&=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator^=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator|=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator<<=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m <<= pek->dec(a.x);
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> & $NameUint<SZ>::operator>>=(const $NameUint<SZ> & a)
{
    e3util::ull m = pek->dec(x);
    m >>= pek->dec(a.x);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator++(int)
{
    $NameUint r(*this);
    e3util::ull m = pek->dec(x);
    m++;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator++()
{
    e3util::ull m = pek->dec(x);
    m++;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return (*this);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator--(int)
{
    $NameUint r(*this);
    e3util::ull m = pek->dec(x);
    m--;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator--()
{
    e3util::ull m = pek->dec(x);
    m--;
    m &= e3util::mask(SZ);
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
    e3util::ull m = pek->dec(x);
    m = ~m;
    m &= e3util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!() const
{
    e3util::ull m = pek->dec(x);
    m = (e3util::ull) !m;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator==(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m == ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator!=(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m != ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m < ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator<=(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m <= ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m > ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator>=(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m >= ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator&&(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m && ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameUint<SZ>::operator||(const $NameUint<SZ> & a) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    m = (e3util::ull) m || ma;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const
{
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    e3util::ull mb = pek->dec(b.x);
    m = e3util::ull (m ? ma : mb);
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
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    e3util::ull mb = pek->dec(b.x);
    m = m ? ma : mb;
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return r;
}

template <int SZ>
inline $NameUint<SZ> $NameUint<SZ>::operator*(unsigned long long u) const
{
    return multiply_by_ull < $NameUint<SZ >> (u, *this);
}


// Functions

template <int SZ>
std::string $NameUint<SZ>::str() const
{
    std::string s = e3util::ull2hex(x);
    return s;
}


// ----- $NameInt ----- //

// Casting
template <int SZ> template <int Z>
$NameInt<SZ>::operator $NameInt<Z> () const
{
    e3util::ull m = pek->dec(x);
    m = e3util::signExtend(m, SZ);
    m &= e3util::mask(Z);
    $NameInt<Z> r;
    r.x = pek->enc(m);
    return r;
}

// Operators

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator/=(const $NameInt<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m /= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator%=(const $NameInt<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m %= ma;
    m &= e3util::mask(SZ);
    x = pek->enc(m);
    return *this;
}

template <int SZ>
inline $NameInt<SZ> & $NameInt<SZ>::operator>>=(const $NameInt<SZ> & a)
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m >>= ma;
    m &= e3util::mask(SZ);
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
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m < ma;
    m &= e3util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator<=(const $NameInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m <= ma;
    m &= e3util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>(const $NameInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m > ma;
    m &= e3util::mask(SZ);
    $NameUint<SZ> r;
    r.x = pek->enc(m);
    return $NameBool(r);
}

template <int SZ>
inline $NameBool $NameInt<SZ>::operator>=(const $NameInt<SZ> & a) const
{
    e3util::sll m = pek->dec(x);
    e3util::sll ma = pek->dec(a.x);
    m = e3util::signExtend(m, SZ);
    ma = e3util::signExtend(ma, SZ);
    m = m >= ma;
    m &= e3util::mask(SZ);
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
    e3util::ull ma = pek->dec(a.x);
    e3util::ull m = ma ? 1 : 0;
    x = pek->enc(m);
}

// Operators

inline $NameBool & $NameBool::operator+=(const $NameBool & a)
{
    e3util::ull m = pek->dec(x);
    m |= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator-=(const $NameBool & a)
{
    e3util::ull m = pek->dec(x);
    m ^= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator*=(const $NameBool & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator/=(const $NameBool & a)
{
    e3util::ull m = pek->dec(x);
    m &= pek->dec(a.x);
    // m &= e3util::mask(SZ); // not needed
    x = pek->enc(m);
    return *this;
}

inline $NameBool & $NameBool::operator%=(const $NameBool & a)
{
    e3util::ull m = pek->dec(x);
    m ^= m;
    // m &= e3util::mask(SZ); // not needed
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
    e3util::ull m = pek->dec(x);
    e3util::ull ma = pek->dec(a.x);
    auto mr = m ? ma : 0;
    $NameUint<SZ> r;
    r.x = pek->enc(mr);
    return r;
}

// === END native.inc Name=$Name
