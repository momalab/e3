// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <vector>

#include "euler.h"
#include "sk_circ_pil.h"

using std::vector;

namespace e3
{

CircuitPrivKey_pilc::CircuitPrivKey_pilc
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam),
      sk(name, forceGen, forceLoad, seed, lam)
{
    // loading via sk, no init_final needed
}

CircuitPrivKey_pilc::CircuitPrivKey_pilc(const PilBasePrivKey & pil, string nm)
    : CircuitPrivKey(KeyName { nm, pil.name.fil }, "dummy", 0), sk(pil, nm)
{
    // rnd created dummy, lets reset it to the correct one
    delete rnd;
    rnd = pil.rnd;
}

vector<bool> CircuitPrivKey_pilc::decbitstr(const std::string & s, bool * ok) const
{
    if (!sk.mxinited) nevers("Matrix not initialized");

    PilQuad bit(s);
    bit = sk.rotate_tr(bit, sk.L);

    if (ok) *ok = true;

    const auto & a = bit.x.a;
    const auto & b = bit.x.b;

    Bigun m = sk.ekb.kv.N;
    PilArith pilArith(&sk.ekb);

    auto x = (a + b * PilNum(sk.Q)) % PilNum(sk.P);

    if ( x.n == Bigun(1) ) return vector<bool>(1, true);
    if ( x.n == Bigun(0) ) return vector<bool>(1, false);

    throw "Bad decryption in CircuitPrivKey_pilc::decbitstr - bit is a number [" + x.n.str() + "]";
}

std::string CircuitPrivKey_pilc::encbitstr(vector<bool> v) const
{
    if (!sk.mxinited) nevers("Matrix not initialized");
    auto bm = v[0];

    Bigun m = sk.ekb.kv.N;
    PilArith pilArith(&sk.ekb);

    PilNum ra(euler::random(m, rnd));
    PilNum rb(euler::random(m, rnd));
    PilNum r1(euler::random(m, rnd));
    PilNum r2(euler::random(m, rnd));

    // testing
    if (0)
    {
        ra = PilNum(0);
        rb = PilNum(0);
        r1 = PilNum(0);
        r2 = PilNum(4);
    }

    PilPair ab;

    Bigun nbm = bm ? Bigun(1) : Bigun(0);

    ab.b = rb % PilNum(m);
    ab.a = ra - (ra + rb * PilNum(sk.Q)) % PilNum(sk.P) + PilNum(nbm);

    // validate
    PilNum x = (ab.a + ab.b * PilNum(sk.Q)) % PilNum(sk.P);

    if ( x.n != nbm ) nevers("Encryption failed");

    PilQuad bit( ab, PilPair(r1, r2) );

    bit = sk.rotate_tr(bit, sk.Li);

    return bit.str();
}

void CircuitPrivKey_pilc::gen()
{
    // since init_final is not called, this is never called
    // sk is PilBasePrivKey
    never;
}

bool CircuitPrivKey_pilc::load()
{
    bool r = sk.load();
    return r;
}

} // e3
