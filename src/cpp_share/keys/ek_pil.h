// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_PIL_H_
#define _E3_EK_PIL_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_pil.h"

namespace e3
{

struct PilEvalValues
{
    const static int ver = 22;
    Bigun N;
    PilNum S;
    PilNum A, B, C, D, E, F;
};

struct PilArith;

class PilBaseEvalKey : public EvalKey
{
    public: // need for access from ekx classes
        PilEvalValues kv;

    public:
        PilBaseEvalKey(int) : EvalKey({"", ""}) {} // when used as a member in key class
        PilBaseEvalKey(User u, KeyName name) : EvalKey(name) { user(u); }

        bool load(string fname);
        virtual bool load() { return load(filename()); }

        friend struct PilArith;
};

class PilaEvalKey : public PilBaseEvalKey
{
    protected:

    public:
        PilaEvalKey(User u, KeyName name) : PilBaseEvalKey(u, name) {}
};

struct PilArith
{
    PilArith(const PilBaseEvalKey * ek): old(use) { use = &ek->kv; }
    ~PilArith() { use = old; }

    static const PilEvalValues * use;
    const PilEvalValues * old;

    // use safe or faster method
    static const PilEvalValues * u() { return use; }
    //static const PilEvalValues * u() { safe(); return use; }
    static void safe();
};


// arithmetic

inline PilNum operator+(PilNum a, PilNum b) { return PilNum(a.n.addmod(b.n, PilArith::u()->N)); }
inline PilNum operator-(PilNum a, PilNum b) { return PilNum(a.n.submod(b.n, PilArith::u()->N)); }
inline PilNum operator*(PilNum a, PilNum b) { return PilNum(a.n.mulmod(b.n, PilArith::u()->N)); }
inline PilNum operator%(PilNum a, PilNum b) { return PilNum(a.n % b.n); }

inline bool operator==(PilNum a, PilNum b) { return a.n == b.n; }
inline bool operator!=(PilNum a, PilNum b) { return !(a == b); }

inline PilPair operator*(PilPair x, PilNum n) { return {x.a * n, x.b * n}; }
inline PilPair operator*(PilNum n, PilPair x) { return x * n; }
inline PilPair operator+(PilPair x, PilPair y) { return {x.a + y.a, x.b + y.b}; }
inline PilPair operator-(PilPair x, PilPair y) { return {x.a - y.a, x.b - y.b}; }
PilPair operator*(PilPair x, PilPair y);

inline PilQuad operator-(PilQuad a, PilQuad b) { return {a.x - b.x, a.y - b.y}; }
inline PilQuad operator+(PilQuad a, PilQuad b) { return {a.x + b.x, a.y + b.y}; }
PilQuad operator*(PilQuad a, PilQuad b);


} // e3
#endif // _E3_EK_PIL_H_
