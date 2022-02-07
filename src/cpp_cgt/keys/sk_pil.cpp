// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>

#include "euler.h"

#include "cgtutil.h"
#include "sk_pil.h"

using std::string;
using std::cout;
using namespace e3::cr;

e3::PilBasePrivKey::PilBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : PrivKey(name, seed, lam), ekb(name)
{
    mxinited = false;
    init_final(forceGen, forceLoad);
}

string e3::PilBasePrivKey::filename() const
{
    return PrivKey::filename();
}

namespace sk_pil
{
static const char * err1 = "Lambda is too big: rebuild with MPIR=1 (lam,max): ";
static const char * err2 = "Lambda cannot be < 5, lambda=";
} // sk_pil

void e3::PilBasePrivKey::gen()
{
    if ( Bigun::maxbitsz() <= lambda * 2 )
        throw sk_pil::err1 + ol::tos(lambda) + " " + ol::tos(Bigun::maxbitsz());

    if ( 5 > lambda ) throw sk_pil::err2 + ol::tos(lambda);

    P = euler::prime(lambda, rnd, Bigun(0));
    Q = euler::prime(lambda, rnd, P);

    // testing
    if (0)
    {
        P = Bigun(3);
        Q = Bigun(5);
    }

    cout << "Primes generated: " << P << ' ' << Q << '\n';

    phi = (P - 1) * (Q - 1);

    initNS(ekb.kv);
    initmatrix();
    initAF(ekb.kv);
}


void e3::PilBasePrivKey::save()
{
    std::ofstream of(filename(), std::ios::binary);
    if (!of) throw "Cannot write to " + filename();
    of << lambda << '\n';
    of << P << '\t';
    of << Q << "\n\n";

    of << L.d11.n << '\t' << L.d12.n << '\n' ;
    of << L.d21.n << '\t' << L.d22.n << '\n';

    ekb.save();

    // testing
    if (0)
    {
        of << '\n' << phi << '\t' << T.n << "\n\n";
        of << Li.d11.n << '\t' << Li.d12.n << '\n' ;
        of << Li.d21.n << '\t' << Li.d22.n << '\n';
    }
}

bool e3::PilBasePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    in >> lambda;

    if ( Bigun::maxbitsz() <= lambda )
        throw sk_pil::err1 + ol::tos(lambda) + " " + ol::tos(Bigun::maxbitsz());

    in >> P; in >> Q;

    phi = (P - 1) * (Q - 1);

    in >> L.d11.n >> L.d12.n >> L.d21.n >> L.d22.n;

    if ( !in ) return false;

    initNS(ekb.kv);
    findT();
    invertL();
    initAF(ekb.kv);

    // at this point ek is initialised
    // we still may load it
    return ekb.load();
}


string e3::PilBasePrivKey::decrypt(const string & c) const
{
    if (!mxinited) nevers("Matrix not initialized");

    string s = ekb.decor(c, false);
    if ( s.empty() ) return s;

    e3::PilQuad bit(s);
    bit = rotate_tr(bit, L);

    const auto & a = bit.x.a;
    const auto & b = bit.x.b;

    Bigun m = ekb.kv.N;
    PilArith pilArith(&ekb);

    auto x = (a + b * PilNum(Q)) % PilNum(P);

    return x.n.str();
}

string e3::PilBasePrivKey::encrypt(const string & s, int msz) const
{
    if (!mxinited) nevers("Matrix not initialized");

    Bigun m = ekb.kv.N;
    PilArith pilArith(&ekb);

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

    e3::PilPair ab;

    Bigun nbm(s);

    ab.b = rb % PilNum(m);
    ab.a = ra - (ra + rb * PilNum(Q)) % PilNum(P) + PilNum(nbm);

    // validate
    e3::PilNum x = (ab.a + ab.b * PilNum(Q)) % PilNum(P);

    if ( x.n != nbm ) nevers("Encryption failed");

    e3::PilQuad bit( ab, e3::PilPair(r1, r2) );

    bit = rotate_tr(bit, Li);

    return ekb.decor(bit.str(), true);
}

e3::PilQuad e3::PilBasePrivKey::rotate_tr(const e3::PilQuad & bit, const Matrix & mx) const
{
    PilArith pilArith(&ekb);
    Bit r;
    r.x = bit.x * mx.d11 + bit.y * mx.d12;
    r.y = bit.x * mx.d21 + bit.y * mx.d22;
    return r;
}

void e3::PilBasePrivKey::initmatrix()
{
    Bigun m = ekb.kv.N;
    PilArith pilArith(&ekb);

    bool ok = false;
    for ( int i = 0; i < 1000; i++ ) // try 1000 times
    {
        // gen random
        L.d11 = PilNum(euler::random(m, rnd));
        L.d12 = PilNum(euler::random(m, rnd));
        L.d21 = PilNum(euler::random(m, rnd));
        L.d22 = PilNum(euler::random(m, rnd));

        // testing
        if (0)
        {
            L.d11 = PilNum(Bigun(1));
            L.d12 = PilNum(Bigun(1));
            L.d21 = PilNum(Bigun(0));
            L.d22 = PilNum(Bigun(1));
        }

        while (1)
        {
            findT();
            if ( euler::gcd(m, T.n) == Bigun(1) ) { ok = true; break; }
            L.d22.n += Bigun(1);
            if ( L.d22.n >= m ) break;
        }

        if ( ok ) break;
        cout << i << "trying new random matrix\n";
    }

    if ( !ok ) throw "Not able to generate matrix";

    invertL();
}

void e3::PilBasePrivKey::findT()
{
    Bigun m = ekb.kv.N;
    PilArith pilArith(&ekb);
    auto det = L.det();
    T = PilNum(det.n.powmod(phi - 1, m));

    // validate
    if (0) // testing
    {
        auto u = det.n.powmod(phi, m);
        if (u != Bigun(1) ) nevers("bad powmod phi");
        if (T * det != PilNum(1) ) nevers("bad T*det");
    }
}

void e3::PilBasePrivKey::invertL()
{
    PilArith pilArith(&ekb);

    Li.d11 = L.d22 * T;
    Li.d12 = PilNum(0) - L.d12 * T;
    Li.d21 = PilNum(0) - L.d21 * T;
    Li.d22 = L.d11 * T;

    // validate 1) T*det 2) L*Lm1
    {
        auto u = T * L.det();
        if (Bigun(1) != u.n)
        {
            cout << "N=" << ekb.kv.N << " S=" << ekb.kv.S.n << '\n';
            cout << "det=" << L.det().n << " T=" << T.n << " u=" << u.n << '\n';
            nevers("bad T");
        }
    }

    auto I11 = L.d11 * Li.d11 + L.d12 * Li.d21;
    auto I12 = L.d11 * Li.d12 + L.d12 * Li.d22;
    auto I21 = L.d21 * Li.d11 + L.d22 * Li.d21;
    auto I22 = L.d21 * Li.d12 + L.d22 * Li.d22;
    if ( Bigun(1) != I11.n ) nevers("bad Inv1");
    if ( Bigun(0) != I12.n ) nevers("bad Inv2");
    if ( Bigun(0) != I21.n ) nevers("bad Inv3");
    if ( Bigun(1) != I22.n ) nevers("bad Inv4");

    mxinited = true;
}

e3::PilNum e3::PilBasePrivKey::Matrix::det() const
{
    return d11 * d22 - d12 * d21;
}

void e3::PilBasePrivKey::initNS(PilEvalValues & kv)
{
    auto q = Q % P;
    kv.N = P * Q;
    kv.S = PilNum(q.mulmod(q, P));
}

void e3::PilBasePrivKey::initAF(PilEvalValues & kv)
{
    // set modulo for simplicity
    PilArith pa(&ekb);

    auto a = L.d11 * L.d21;
    auto b = L.d12 * L.d22;
    auto c = L.d12 - L.d22;
    auto d = L.d11 - L.d21;
    auto e = L.d11 * L.d11 * L.d22 - L.d12 * L.d21 * L.d21;
    auto f = L.d11 * L.d22 * L.d22 - L.d12 * L.d12 * L.d21;

    kv.A = T * e;
    kv.B = T * b * c;
    kv.C = T * b * d;
    kv.D = PilNum(0) - T * a * d;
    kv.E = T * f;
    kv.F = PilNum(0) - T * a * c;
}

