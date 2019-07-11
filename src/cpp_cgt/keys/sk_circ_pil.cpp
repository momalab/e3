#include <fstream>

#include "euler.h"

#include "sk_circ_pil.h"

e3::CircuitPrivKey_pilc::CircuitPrivKey_pilc
(std::string name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam, &ekx), ekx(name),
      sk(name, forceGen, forceLoad, seed, lam)
{
    // loading via sk //init_final(forceGen, forceLoad);
    // just copy from sk
    ekx.bek = sk.ekb;
}

e3::CircuitPrivKey_pilc::CircuitPrivKey_pilc(const PilBasePrivKey & pil)
    : CircuitPrivKey(pil.name, "dummy", 0, &ekx), ekx(pil.name), sk(pil)
{
    ekx.bek = pil.ekb;
    // rnd created dummy, lets reset it to the correct one
    delete rnd;
    rnd = pil.rnd;
}


void e3::CircuitPrivKey_pilc::gen()
{
    never("called e3::CircuitPrivKey_pilc::gen");
    sk.gen();

    // no init ekx by gen
    //ekx.gen();

    // copy inited data to ekx
    ekx.bek = sk.ekb;
}

bool e3::CircuitPrivKey_pilc::load()
{
    bool r = sk.load();
    ekx.bek = sk.ekb;
    return r;
}

std::string e3::CircuitPrivKey_pilc::encbitstr(bool bm) const
{
    if (!sk.mxinited) never("Matrix not initialized");

    Bigun m = ekx.bek.kv.N;
    PilArith pilArith(&ekx.bek);

    PilNum ra = euler::random(m, rnd);
    PilNum rb = euler::random(m, rnd);
    PilNum r1 = euler::random(m, rnd);
    PilNum r2 = euler::random(m, rnd);

    // testing
    if (0)
    {
        //cout<< "AAA "<<r2<<'\n';
        ra = 0;
        rb = 0;
        r1 = 0;
        r2 = 4;
    }

    e3::PilPair ab;

    Bigun nbm = bm ? Bigun(1) : Bigun(0);

    ab.b = rb % m;
    ab.a = ra - (ra + rb * sk.Q) % sk.P + nbm;

    // validate
    e3::PilNum x = (ab.a + ab.b * sk.Q) % sk.P;

    if ( x.n != nbm ) never("Encryption failed");

    e3::PilQuad bit( ab, e3::PilPair(r1, r2) );

    bit = sk.rotate_tr(bit, sk.Li);

    return bit.str();
}

bool e3::CircuitPrivKey_pilc::decbitstr(const std::string & s, bool * ok) const
{
    if (!sk.mxinited) never("Matrix not initialized");

    e3::PilQuad bit(s);
    bit = sk.rotate_tr(bit, sk.L);

    if (ok) *ok = true;

    const auto & a = bit.x.a;
    const auto & b = bit.x.b;

    ///Bigun m = PilNum::mod = ek.kv.N;
    Bigun m = ekx.bek.kv.N;
    PilArith pilArith(&ekx.bek);

    auto x = (a + b * sk.Q) % sk.P;

    if ( x.n == Bigun(1) ) return true;
    if ( x.n == Bigun(0) ) return false;

    throw "Bad decryption in CircuitPrivKey_pilc::decbitstr - bit is a number [" + x.n.str() + "]";
}

