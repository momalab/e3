
string Bigun::str() const { return p->str(); }

Bigun::Bigun(unsigned long long x): p(new BigunNative(x)) {}
Bigun::Bigun(const Bigun & a) : Bigun() { *p = *a.p; }
Bigun::Bigun(Bigun && a): p(nullptr) { p.swap(a.p); }
Bigun & Bigun::operator=(const Bigun & a) { *p = *a.p; return *this; }
Bigun & Bigun::operator=(Bigun && a) { p.swap(a.p); return *this; }


Bigun & Bigun::operator+=(const Bigun & a) { *p += *a.p; return *this; }
Bigun & Bigun::operator-=(const Bigun & a) { *p -= *a.p; return *this; }
Bigun & Bigun::operator*=(const Bigun & a) { *p *= *a.p; return *this; }
Bigun & Bigun::operator/=(const Bigun & a) { *p /= *a.p; return *this; }
Bigun & Bigun::operator%=(const Bigun & a) { *p %= *a.p; return *this; }
Bigun & Bigun::operator|=(const Bigun & a) { *p |= *a.p; return *this; }

Bigun & Bigun::operator<<=(const Bigun & a) { *p <<= *a.p; return *this; }
Bigun & Bigun::operator>>=(const Bigun & a) { *p >>= *a.p; return *this; }

bool Bigun::operator==(const Bigun & a) const { return *p == *a.p; }
bool Bigun::operator<(const Bigun & a) const { return *p < *a.p; }


Bigun Bigun::powmod(Bigun x, Bigun y) const
{
    Bigun r;
    *r.p = this->p->powmod(*x.p, *y.p);
    return r;
}

Bigun Bigun::addmod(Bigun x, Bigun m) const
{
    Bigun r(*this);
    *r.p += *x.p;
    return r %= m;
}

Bigun Bigun::mulmod(Bigun x, Bigun m) const
{
    Bigun r;
    *r.p = this->p->mulmod(*x.p, *m.p);
    return r;
}

Bigun Bigun::submod(Bigun x, Bigun m) const
{
    Bigun r(*this);
    if ( *p < *x.p ) return r += (m - x);
    return r -= x;
}

