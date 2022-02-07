// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
namespace e3
{

string Bigun::str() const { return p->str(); }

Bigun::Bigun(unsigned long long x): p(new BigunNative(x)) {}
Bigun::Bigun(const Bigun & a) : Bigun() { *p = *a.p; }
Bigun::Bigun(Bigun && a) noexcept : p(nullptr)  { p.swap(a.p); }
Bigun & Bigun::operator=(const Bigun & a) { *p = *a.p; return *this; }
Bigun & Bigun::operator=(Bigun && a) noexcept { p.swap(a.p); return *this; }


Bigun & Bigun::operator+=(const Bigun & a) { *p += *a.p; return *this; }
Bigun & Bigun::operator-=(const Bigun & a) { *p -= *a.p; return *this; }
Bigun & Bigun::operator*=(const Bigun & a) { *p *= *a.p; return *this; }
Bigun & Bigun::operator/=(const Bigun & a) { *p /= *a.p; return *this; }
Bigun & Bigun::operator%=(const Bigun & a) { *p %= *a.p; return *this; }
Bigun & Bigun::operator|=(const Bigun & a) { *p |= *a.p; return *this; }
Bigun & Bigun::operator^=(const Bigun & a) { *p ^= *a.p; return *this; }
Bigun & Bigun::operator&=(const Bigun & a) { *p &= *a.p; return *this; }

Bigun & Bigun::operator<<=(const Bigun & a) { *p <<= *a.p; return *this; }
Bigun & Bigun::operator>>=(const Bigun & a) { *p >>= *a.p; return *this; }

bool Bigun::operator==(const Bigun & a) const { return *p == *a.p; }
bool Bigun::operator<(const Bigun & a) const { return *p < *a.p; }

Bigun Bigun::operator~() const { *p = ~*p; return *this; }
Bigun Bigun::operator-() const { *p = -*p; return *this; }
Bigun & Bigun::operator--() { --*p; return *this; }
Bigun & Bigun::operator++() { ++*p; return *this; }


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

Bigun Bigun::invmod(Bigun m) const
{
    Bigun r;
    *r.p = this->p->invmod(*m.p);
    return r;
}

bool Bigun::isZero() const
{
    return this->p->isZero();
}

std::vector<uint32_t> Bigun::data() const
{
    return this->p->data();
}

void Bigun::data(const std::vector<uint32_t> & a)
{
    this->p->data(a);
}

} // e3

string e3::Bigun::sth() const
{
    static const char ch[16] =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    std::vector<char> stk;

    Bigun x(*this);

    while (!x.isZero())
    {
        auto k = x % 16;
        int q = 0;
        for ( int j = 0; j < 4; j++ ) { int p = 1 << j; q |= (k & Bigun(p)).isZero() ? 0 : p; }
        stk.push_back(ch[q]);
        x >>= 4;
    }

    if ( stk.empty() ) return "0";

    string r;
    for ( auto i = stk.size(); i > 0; ) r += stk[--i];
    return r;
}

e3::Bigun::ull_t e3::Bigun::ull() const
{
    return this->p->ull();
}

void e3::Bigun::BitRef::setbit(Bigun::BitVal a)
{
    if ( !p ) throw "uninitialized bit reference in " + std::string(__func__);
    e3::Bigun b(1); b <<= i;
    *p |= b;
    if ( !a.v ) *p ^= b;
}

e3::Bigun::BitVal e3::Bigun::BitRef::val() const
{
    if ( !p ) throw "uninitialized bit reference in " + std::string(__func__);
	Bigun q(*p);
    return BitVal { !((q >> i) & Bigun(1)).isZero() };
}
