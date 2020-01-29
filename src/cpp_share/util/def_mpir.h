#ifndef _E3_DEF_MPIR_H_
#define _E3_DEF_MPIR_H_

#include <string>
#include <memory>
#include <istream>
#include <ostream>

using std::string;

namespace e3
{

int mpir_impl(); // 0 or 1

struct BigunNative;

class Bigun;
std::istream & operator>>(std::istream & is, Bigun & x);
std::ostream & operator<<(std::ostream & os, const Bigun & x);

class Bigun
{
        std::shared_ptr<BigunNative> p;
        using ull = unsigned long long;

    public:
        Bigun( ull = 0 );
        Bigun(string x);

        Bigun(const Bigun & a);
        Bigun & operator=(const Bigun & a);

        Bigun(Bigun && a);
        Bigun & operator=(Bigun && a);

        static int maxbitsz();

        string str() const;
        Bigun powmod(Bigun x, Bigun m) const;
        Bigun addmod(Bigun x, Bigun m) const;
        Bigun submod(Bigun x, Bigun m) const;
        Bigun mulmod(Bigun x, Bigun m) const;
        Bigun invmod(Bigun m) const;

        bool isZero() const;

        friend std::istream & operator>>(std::istream & is, Bigun & x);
        friend std::ostream & operator<<(std::ostream & os, const Bigun & x);

        Bigun & operator+=(const Bigun & a);
        Bigun & operator-=(const Bigun & a);
        Bigun & operator*=(const Bigun & a);
        Bigun & operator/=(const Bigun & a);
        Bigun & operator%=(const Bigun & a);
        Bigun & operator&=(const Bigun & a);
        Bigun & operator|=(const Bigun & a);
        Bigun & operator^=(const Bigun & a);
        Bigun & operator<<=(const Bigun & a);
        Bigun & operator>>=(const Bigun & a);
        Bigun operator++();
        Bigun operator++(int);
        Bigun operator--();
        Bigun operator--(int);

        Bigun operator+(const Bigun & a) const { Bigun r(*this); return r += a; }
        Bigun operator-(const Bigun & a) const { Bigun r(*this); return r -= a; }
        Bigun operator*(const Bigun & a) const { Bigun r(*this); return r *= a; }
        Bigun operator/(const Bigun & a) const { Bigun r(*this); return r /= a; }
        Bigun operator%(const Bigun & a) const { Bigun r(*this); return r %= a; }
        Bigun operator&(const Bigun & a) const;
        Bigun operator|(const Bigun & a) const { Bigun r(*this); return r |= a; }
        Bigun operator^(const Bigun & a) const;
        Bigun operator<<(const Bigun & a) const { Bigun r(*this); return r <<= a; }
        Bigun operator>>(const Bigun & a) const { Bigun r(*this); return r >>= a; }
        Bigun operator~() const;
        bool operator!() const { return (*this == Bigun(0)); }
        bool operator==(const Bigun & a) const;
        bool operator!=(const Bigun & a) const { return !(*this == a); }
        bool operator<(const Bigun & a) const;
        bool operator>=(const Bigun & a) const { return !(*this < a); }
        bool operator>(const Bigun & a) const { return a < *this; }
        bool operator<=(const Bigun & a) const { return !(a < *this); }
        bool operator&&(const Bigun & a) const;
        bool operator||(const Bigun & a) const;

        friend Bigun operator+(ull a, const Bigun & b) { return b + a; }
        friend Bigun operator-(ull a, const Bigun & b) { return b - a; }
        friend Bigun operator*(ull a, const Bigun & b) { return b * a; }
};


inline std::ostream & operator<<(std::ostream & os, const Bigun & x) { return os << x.str(); }

} // e3

#endif // _E3_DEF_MPIR_H_
