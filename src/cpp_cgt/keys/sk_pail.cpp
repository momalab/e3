// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>

#include "euler.h"

#include "cgtutil.h"
#include "sk_pail.h"

const bool TESTENCDEC = false;

using std::string;
using std::cout;
using namespace e3::cr;

e3::PailBasePrivKey::PailBasePrivKey
(KeyName name, std::string seed, int lam)
    : PrivKey(name, seed, lam), ekb(name)
{
    //init_final(forceGen, forceLoad); this must be called one level down
}

e3::PailPrivKey::PailPrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : PailBasePrivKey(name, seed, lam)
{
    init_final(forceGen, forceLoad);
}

e3::PailgPrivKey::PailgPrivKey
(KeyName name, bool forceGen, bool forceLoad,
 std::string seed, int lam, int b)
    : PailBasePrivKey(name, seed, lam), beta(b)
{
    init_final(forceGen, forceLoad);
}

string e3::PailBasePrivKey::filename() const
{
    return PrivKey::filename();
}


namespace sk_pail
{
static const char * err1 = "Lambda is too big: rebuild with MPIR=1 (lam,max): ";
static const char * err2 = "Lambda cannot be < 5, lambda=";
}

void e3::PailBasePrivKey::genBase()
{
    if ( Bigun::maxbitsz() <= lambda * 2 )
        throw sk_pail::err1 + ol::tos(lambda) + " "
        + ol::tos(Bigun::maxbitsz() / 2);

    if ( 5 > lambda ) throw sk_pail::err2 + ol::tos(lambda);

    P = euler::prime(lambda, rnd, Bigun(0));
    Q = euler::prime(lambda, rnd, P);

    // testing
    if (0)
    {
        P = Bigun(3);
        Q = Bigun(5);
    }

    cout << "Primes generated: " << P << ' ' << Q << '\n';

    ekb.setN(P, Q);
    initphi();
}

void e3::PailBasePrivKey::gen()
{
    genBase();
    cout << "Processor(B): " << ekb.show() << " (fkf=" << phph1.str() << ")\n";
}

void e3::PailPrivKey::gen()
{
    genBase();
    cout << "Processor(P): " << ekb.show() << " (fkf=" << phph1.str() << ")\n";
}

void e3::PailgPrivKey::gen()
{
    genBase();
    if ( beta ) ekb.setBeta(beta);
    cout << "Processor(G): " << ekb.show() << " (fkf=" << phph1.str() << ")\n";
}

void e3::PailBasePrivKey::initphi()
{
    const auto & N = ekb.getN();
    const auto & N2 = ekb.getN2();
    ph = (P - 1) * (Q - 1);
    auto ph1 = ph.invmod(N);
    phph1 = ph1.mulmod(ph, N2);
}

void e3::PailBasePrivKey::save()
{
    {
        std::ofstream of(filename(), std::ios::binary);
        if (!of) throw "Cannot write to " + filename();
        of << lambda << '\n';
        of << P << '\t';
        of << Q << "\n\n";
    }

    ekb.save();
}

bool e3::PailBasePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    in >> lambda;

    if ( Bigun::maxbitsz() <= lambda * 2 )
        throw sk_pail::err1 + ol::tos(lambda) + " "
        + ol::tos(Bigun::maxbitsz() / 2);

    in >> P; in >> Q;

    if ( !in ) throw "corrupted [" + filename() + "]";

    // init on load
    auto r = ekb.load();

    if ( ekb.getN() != P * Q ) throw "bad public key for [" + filename() + "]";
    initphi();

    return r;
}


string e3::PailBasePrivKey::decrypt(const string & c) const
{
    const auto & N = ekb.getN();
    const auto & N2 = ekb.getN2();

    string dc = ekb.decor(c, false);
    if ( dc.empty() ) return "";

    Bigun x(dc);
    auto y = x.powmod(phph1, N2); // 1+Nm
    y -= Bigun(1);
    auto z = y / N;

    return z.str();
}

// rN*(1+Nm)
string e3::PailBasePrivKey::encrypt(const string & s, int msz) const
{
    const auto & N = ekb.getN();
    const auto & N2 = ekb.getN2();

    auto r = euler::random(N, rnd);

    // important for small moduli
    for ( int i = 0; i < 100; i++ )
    {
        auto g = e3::euler::gcd(r, N);
        if ( g == Bigun(1) ) break;
        r = euler::random(N, rnd);
        if ( i > 90 ) nevers("Failed to generate random");
    }

    auto rN = r.powmod(N, N2);

    Bigun x(s);

    auto g = N;
    g = g.mulmod(x % N, N2);
    g += Bigun(1);

    x = rN.mulmod(g, N2);

    auto ret = ekb.decor(x.str(), true);

    if ( TESTENCDEC )
    {
        auto dec = decrypt(ret);
        if ( dec != s )
        {
            cout << "N=" << N.str() << " r=" << r.str()
                 << " rN=" << rN.str() << '\n';
            throw "Error while encrypting [" + s + "] -> [" + dec + "]";
        }
        else
            cout << "Encrypted: " << s << '\n';
    }

    return ret;
}

