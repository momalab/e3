// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_E3MATH_H_
#define _E3_E3MATH_H_

#include <string>
#include <vector>
#include <utility>

namespace e3
{
namespace math
{

template<typename T> bool invert(const T & x, const T & mod, T * r);

template<typename Unumber>
struct UnumberContractor
{
    using UC = UnumberContractor;

    Unumber x;
    UnumberContractor() {}
    UnumberContractor(const Unumber & a) : x(a) {}

    // Constrains
    bool operator==(const UC & a) const { return x == a.x; }
    bool operator<(const UC & a) const { return x < a.x; }
    void add(const UC & b) { x += b.x; }
    void sub(const UC & b) { x -= b.x; }
    std::string str() const { return x.str(); }

    // Derived
    bool operator!=(const UC & a) const { return !(*this == a); }
    void subMod(const UC & b, const UC & mod) { if ( *this < b) add(mod); sub(b); }
    void addMod(const UC & b, const UC & mod)
    {
        add(b);
            while (1) if ( *this < mod ) break; else sub(mod);
    }
    bool operator>(const UC & a) const { return !(*this < a || *this == a); }

    void swap(UC & a) { x.swap(a.x); }
    void mulMod(const UC & b, const UC & mod) { x = x.mul(b.x, mod.x); }
    static void divABRQ(const UC & a, const UC & b, UC * r, UC * q)
    { a.x.divABRQ(b.x, r ? &r->x : 0, q ? &q->x : 0); }
};

template<>
struct UnumberContractor<e3::util::ull>
{
    using UC = UnumberContractor;
    using Unumber = e3::util::ull;

    Unumber x;
    UnumberContractor(): x() {}
    UnumberContractor(const Unumber & a) : x(a) {}

    // Constrains
    bool operator==(const UC & a) const { return x == a.x; }
    bool operator<(const UC & a) const { return x < a.x; }
    void add(const UC & b) { x += b.x; }
    void sub(const UC & b) { x -= b.x; }
    std::string str() const { return std::to_string(x); }

    // Derived
    bool operator!=(const UC & a) const { return !(*this == a); }
    void subMod(const UC & b, const UC & mod) { if ( *this < b) add(mod); sub(b); }
    void addMod(const UC & b, const UC & mod)
    {
        add(b);
            while (1) if ( *this < mod ) break; else sub(mod);
    }
    bool operator>(const UC & a) const { return !(*this < a || *this == a); }

    void swap(UC & a) { std::swap(x, a.x); }
    void mulMod(const UC & b, const UC & mod) { x = (x * b.x % mod.x); }
    static void divABRQ(const UC & a, const UC & b, UC * r, UC * q)
    { if (r) r->x = a.x % b.x; if (q) q->x = a.x / b.x; }
};

template <class T>
class Meuclid
{
    public:

        struct Rec
        {
            T a, b, c, d, e, f, g;
        };

    private:

        T et, ft;
        typedef std::vector<Rec> Vr;
        Vr v;
        T gsmall;

        T mod;

        void fillAB(T x, T y);
        void fillEF();
        void fillG();

        void checkRec(const Rec & v0, const Rec & v,
                      const Rec & vb, T et, T ft);

        T mul(const T & a, const T & b) const { T t(a); t.mulMod(b, mod); return t; }
        T sub(const T & a, const T & b) const { T t(a); t.subMod(b, mod); return t; }
        T add(const T & a, const T & b) const { T t(a); t.addMod(b, mod); return t; }
        T neg(const T & a) const { T t(0); t.subMod(a, mod); return t; }
        T divq(const T & a, const T & b) const { T q; T::divABRQ(a, b, 0, &q); return q; }

    public:
        Meuclid(T x, T y, T m): et(0), ft(1), gsmall(0), mod(m) { fillAB(x, y); fillEFG(); }

        void fillEFG() { fillEF(); fillG(); }
        void setEF(T e, T f) { et = e; ft = f; }

        T gcd() const { return v[v.size() - 1].b; }

        std::string str() const;
        int size() const { return int(v.size()); }

        const Rec & operator[](int i) const { return v[i]; }

        T smallg() const { return gsmall; }

};


template <class T>
class Invertor
{
        Meuclid<T> e;
    public:
        Invertor(T x, T m): e(x, m, m) {}

        bool isOk() const { return e[e.size() - 1].b == T(1); }
        T get() const { return e[e.size() - 1].f; }
};



} // math
} // e3

#endif // _E3_E3MATH_H_
