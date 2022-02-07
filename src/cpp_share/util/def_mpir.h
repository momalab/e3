// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_MPIR_H_
#define _E3_DEF_MPIR_H_

#include <string>
#include <memory>
#include <istream>
#include <ostream>
#include <vector>

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

    protected:

        using ull_t = unsigned long long;

    public:
        explicit Bigun( ull_t = 0 );
        Bigun(string x);

        Bigun(const Bigun & a);
        Bigun & operator=(const Bigun & a);

        Bigun(Bigun && a) noexcept;
        Bigun & operator=(Bigun && a) noexcept;

        static int maxbitsz();

        string str() const;
        string sth() const; // hex

        Bigun powmod(Bigun x, Bigun m) const;
        Bigun addmod(Bigun x, Bigun m) const;
        Bigun submod(Bigun x, Bigun m) const;
        Bigun mulmod(Bigun x, Bigun m) const;
        Bigun invmod(Bigun m) const;

        Bigun powmod(unsigned x, Bigun m) const { return powmod(Bigun(x),m); }

        bool isZero() const;
        explicit operator bool() { return !isZero(); }

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

        Bigun & operator|=(int a) { return *this |= Bigun(ull_t(a)); }
        Bigun & operator<<=(int a) { return *this <<= Bigun(ull_t(a)); }
        Bigun & operator>>=(int a) { return *this >>= Bigun(ull_t(a)); }
        Bigun operator<<(int a) const { Bigun r(*this); return r <<= a; }
        Bigun operator>>(int a) const { Bigun r(*this); return r >>= a; }

        Bigun & operator++();
        Bigun & operator--();
        Bigun operator++(int) { Bigun x(*this); ++*this; return x; }
        Bigun operator--(int) { Bigun x(*this); --*this; return x; }
        Bigun operator-() const;
        Bigun operator+() const { return *this; }

        Bigun operator+(const Bigun & a) const { Bigun r(*this); return r += a; }
        Bigun operator-(const Bigun & a) const { Bigun r(*this); return r -= a; }
        Bigun operator*(const Bigun & a) const { Bigun r(*this); return r *= a; }
        Bigun operator/(const Bigun & a) const { Bigun r(*this); return r /= a; }
        Bigun operator%(const Bigun & a) const { Bigun r(*this); return r %= a; }
        Bigun operator&(const Bigun & a) const { Bigun r(*this); return r &= a; }
        Bigun operator|(const Bigun & a) const { Bigun r(*this); return r |= a; }
        Bigun operator^(const Bigun & a) const { Bigun r(*this); return r ^= a; }
        Bigun operator<<(const Bigun & a) const { Bigun r(*this); return r <<= a; }
        Bigun operator>>(const Bigun & a) const { Bigun r(*this); return r >>= a; }
        Bigun operator~() const;
        bool operator!() const { return isZero(); }
        bool operator==(const Bigun & a) const;
        bool operator!=(const Bigun & a) const { return !(*this == a); }
        bool operator<(const Bigun & a) const;
        bool operator>=(const Bigun & a) const { return !(*this < a); }
        bool operator>(const Bigun & a) const { return a < *this; }
        bool operator<=(const Bigun & a) const { return !(a < *this); }
        bool operator&&(const Bigun & a) const { return !!*this && !!a; }
        bool operator||(const Bigun & a) const { return !!*this || !!a; }

        friend Bigun operator+(ull_t a, const Bigun & b) { return b + Bigun(a); }
        friend Bigun operator-(ull_t a, const Bigun & b) { return b - Bigun(a); }
        friend Bigun operator*(ull_t a, const Bigun & b) { return b * Bigun(a); }
        friend Bigun operator+(const Bigun & b, ull_t a) { return b + Bigun(a); }
        friend Bigun operator-(const Bigun & b, ull_t a) { return b - Bigun(a); }
        friend Bigun operator*(const Bigun & b, ull_t a) { return b * Bigun(a); }
        friend Bigun operator/(const Bigun & b, ull_t a) { return b / Bigun(a); }
        friend Bigun operator%(const Bigun & b, ull_t a) { return b % Bigun(a); }

        ull_t ull() const;

        // bit access
        ///struct BitVal
        ///{
        ///    Bigun v; // 0 or 1
        ///    bool operator!() const { return !v; }
        ///};
        ///using BitVal = Bigun;
        struct BitVal
        {
            bool v; // 0 or 1
            bool operator!() const { return !v; }
        };

        struct BitRef
        {
            Bigun * p = nullptr;
            int i;

            BitVal val() const;
            void setbit(BitVal b);

            BitRef operator=(BitVal b) { setbit(b); return *this; }
            BitRef operator=(int x) { setbit(BitVal {!!x}); return *this; }
            BitRef operator=(const BitRef & b) { setbit(b.val()); return *this; }

            bool operator!() const { return !val(); }
        };
        BitRef operator[](int i) { return BitRef {this, i}; }
        BitVal operator()(int i) const { Bigun t(*this); return t[i].val(); }
        friend Bigun operator*(BitVal a, const Bigun & b) { return (!a)?Bigun(0):b; }
        friend Bigun operator*(const BitRef &a, const Bigun & b) { return a.val() * b; }


        // CoPHEE
        std::vector<uint32_t> data() const;
        void data(const std::vector<uint32_t> &);
};


inline std::ostream & operator<<(std::ostream & os, const Bigun & x) { return os << x.str(); }

} // e3

#endif // _E3_DEF_MPIR_H_
