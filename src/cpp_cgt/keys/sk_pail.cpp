#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>

#include "euler.h"

#include "cgtutil.h"
#include "sk_pail.h"

using std::string;

e3::PailPrivKey::PailPrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : PrivKey(name, seed, lam), ekb(name)
{
    init_final(forceGen, forceLoad);
}

string e3::PailPrivKey::filename() const
{
    return PrivKey::filename();
}


static const char * err1 = "Lambda is too big: rebuild with MPIR=1 (lam,max): ";
static const char * err2 = "Lambda cannot be < 5, lambda=";

void e3::PailPrivKey::gen()
{
    if ( Bigun::maxbitsz() <= lambda * 2 )
        throw err1 + ol::tos(lambda) + " " + ol::tos(Bigun::maxbitsz());

    if ( 5 > lambda ) throw err2 + ol::tos(lambda);

    P = euler::prime(lambda, rnd, 0);
    Q = euler::prime(lambda, rnd, P);

    // testing
    if (0)
    {
        P = 3;
        Q = 5;
    }

    cout << "Primes generated: " << P << ' ' << Q << '\n';

    ///phi = (P - 1) * (Q - 1);
    ekb.initN(P, Q);
    initphi();
}

void e3::PailPrivKey::initphi()
{
    const auto & N = ekb.N;
    const auto & N2 = ekb.N2;
    ph = (P - 1) * (Q - 1);
    auto ph1 = ph.invmod(N);
    phph1 = ph1.mulmod(ph, N2);
}

void e3::PailPrivKey::save()
{
    std::ofstream of(filename(), std::ios::binary);
    if (!of) throw "Cannot write to " + filename();
    ///cout << "Primes saving: " << P << ' ' << Q << '\n';
    of << lambda << '\n';
    of << P << '\t';
    of << Q << "\n\n";

    ekb.save();
}

bool e3::PailPrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    in >> lambda;

    if ( Bigun::maxbitsz() <= lambda )
        throw err1 + ol::tos(lambda) + " " + ol::tos(Bigun::maxbitsz());

    in >> P; in >> Q;

    ///auto phi = (P - 1) * (Q - 1);

    if ( !in ) throw "corrupted [" + filename() + "]";

    // init on load
    auto r = ekb.load();

    if ( ekb.N != P * Q ) throw "bad public key for [" + filename() + "]";
    initphi();

    return r;
}


string e3::PailPrivKey::decrypt(const string & c) const
{
    const auto & N = ekb.N;
    const auto & N2 = ekb.N2;

    string dc = ekb.decor(c, false);
    if ( dc.empty() ) return "";

    Bigun x(dc);
    auto y = x.powmod(phph1, N2); // 1+Nm
    y -= 1;
    auto z = y / N;

    ///never("e3::PailPrivKey::decrypt");
    return z.str();
}

// rN*(1+Nm)
string e3::PailPrivKey::encrypt(const string & s, int msz) const
{
    const auto & N = ekb.N;
    const auto & N2 = ekb.N2;

    auto r = euler::random(N, rnd);
    auto rN = r.powmod(N, N2);

    Bigun x(s);

    ///auto g = N + 1;
    ///g = g.powmod( x % N, N2 );
    auto g = N;
    g = g.mulmod(x % N, N2);
    g += 1;

    x = rN.mulmod(g, N2);

    return ekb.decor(x.str(), true);
}

