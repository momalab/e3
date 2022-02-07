// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "bbs.h"
#include "main.h"
#include "vars.h"
#include "olc.h"

#include "using.h"


std::ostream & e3::cr::operator<<(std::ostream & os, const vbool & v)
{
    int sz = (int)v.size();
    for ( int i = 0; i < sz; i++ ) { os << ' ' << int(v[i]); }

    os << '\n';
    return os;
}

std::ostream & e3::cr::operator<<(std::ostream & os, const vvbool & m)
{
    int sz = (int)m.size();
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            os << ' ' << int(m[i][j]);
        }
        os << '\n';
    }
    //os << '\n';
    return os;
}

std::istream & e3::cr::operator>>(std::istream & is, vbool & v)
{
    int z = 0, sz = (int)v.size();
    for ( int i = 0; i < sz; i++ ) { is >> z; v[i] = bool(z); }
    return is;
}

std::istream & e3::cr::operator>>(std::istream & is, vvbool & m)
{
    int z = 0, sz = (int)m.size();
    for ( int i = 0; i < sz; i++ )
        for ( int j = 0; j < sz; j++ ) { is >> z; m[i][j] = bool(z); }
    return is;
}






void e3::cr::makeBbs(string file)
{
    Bbsf bs(file, false);
    bs.generate();
    bs.save();
}


std::istream & e3::cr::operator>>(std::istream & is, Formula & f)
{
    string s;
    is >> s;
    if ( s.empty() ) throw "Formula cannot be empty";

    {
        auto j = s.find_first_not_of("NLFAR0123456789");
        if (  j != string::npos )
            throw "Bad formula [" + s + "] element (" + s[j] + ")";
    }

    int i = 0;
    int sz = (int)s.size();
    s += '0';
    for (; i < sz; i++ )
    {
        if (0);
        else if ( s[i] == 'L' ) f.elements.push_back(Element('L'));
        else if ( s[i] == 'F' ) f.elements.push_back(Element('N', 1));
        else if ( s[i] == 'A' || s[i] == 'R' || s[i] == 'N' )
        {
            int x = int(s[++i] - '0');
            if ( x < 0 || x > 9 ) throw "Bad formula (index)";
            f.elements.push_back(Element(s[i - 1], x));
        }
        else throw "Bad formula (unexpected)";
    }
    return is;
}

std::ostream & e3::cr::operator<<(std::ostream & of, const Formula & f)
{
    for ( auto i : f.elements )
        if ( i.typ == 'L' ) of << i.typ;
        else if ( i.typ == 'N' && i.siz == 1 ) of << 'F';
        else of << i.typ << i.siz;

    return of;
}


Lbs::Lbs(int z, bool load, std::istream & is, Rnd * r): sz(z), rnd(r)
{
    b1.resize(sz);
    b2.resize(sz);
    A1.resize(sz, vbool(sz));
    A2.resize(sz, vbool(sz));

    if (load) is >> b1 >> A1 >> b2 >> A2;
}

Fbs::Fbs(Element e, int z, bool load, std::istream & is, Rnd * r)
    : sz(z), rnd(r), element(e)
{
    if (!load) return;

    int n = 0;
    is >> n;
    for ( int i = 0; i < n; i++ )
    {
        int x; is >> x;
        idxs.push_back(x);
    }
}

Bbsf::Bbsf(string filename, bool load): file(filename)
{
    cout << "loading BBS file\n";

    std::ifstream in(file);
    if ( !in ) throw "Cannot open [" + file + "]";

    try { init(in, load, nullptr ); }
    catch (...)
    {
        cout << "Error: while loading [" << file << "]\n";
        throw;
    }
}

void Bbs::init(std::istream & in, bool load, Rnd * rn)
{
    string line, s;
    std::getline(in, line);
    istr(line) >> s;
    if ( s != "BBS#" ) throw "File is not BBS file";

    in >> sz >> seed >> formula;
    if ( ! in ) throw "File corrupted\n";

    rnd = rn;
    if ( !rnd ) rnd = Rnd::newRnd(seed);

    for ( auto i : formula.elements )
    {
        if ( i.typ == 'L' )
        {
            Lbs bs(sz, load, in, &*rnd);
            lbs.push_back(bs);
        }
        else
        {
            if ( sz > 2 )
            {
                Fbs bs(i, sz, load, in, &*rnd);
                fbs.push_back(bs);
            }
            else
            {
                static bool msg = false;
                if ( !msg )
                    std::cout << "Warning: non-linear formula ignored\n";
                msg = true;
            }
        }
    }

    // now set references to Bbs objects - (!) no resize on vectors anymore
    int ilb = 0, ifb = 0;
    for ( auto i : formula.elements )
    {
        if ( i.typ == 'L' )
            bbs.push_back(&lbs[ilb++]);
        else
        {
            if ( sz > 2 ) bbs.push_back(&fbs[ifb++]);
        }
    }
}

void Bbsf::save(string fn)
{
    std::ofstream of(fn, std::ios::binary);
    if ( !of ) throw "Cannot open [" + file + "]";

    Bbs::save(of);
}

void Bbs::save(std::ostream & of)
{
    of << "BBS#\tsize\tseed\tformula\n";
    of << '\t' << sz << '\t' << seed << '\t' << formula << "\n";
    for ( auto i : bbs ) { of << '\n'; i->save(of); }
}

void Lbs::save(std::ostream & of)
{
    of << b1 << '\n';
    of << A1 << '\n';
    of << b2 << '\n';
    of << A2 << '\n';
}

void Fbs::save(std::ostream & of)
{
    of << idxs.size();
    for ( auto i : idxs ) of << ' ' << i;
    of << "\n\n";
}


vector<Rcop> Lbs::genRcops()
{
    // following Gauss-Jordan elimination sequence
    {
        int k = 1;
        vector<Rcop> r;

        // e.g. 0 1 2 3 => 4
        // 01 12 23  32 21 10
        // 02 13     31 20
        // 03        30

        int n = sz - 1;

        for ( int ik = 0; ik < k; ik ++ )
            for ( int up = 0; up < 2; up++ )
            {
                for ( int i = 0; i < n; i++ )
                    for ( int j = i + 1; j < sz; j++ )
                    {
                        int ai = i, aj = j;
                        if ( up ) { ai = n - i, aj = n - j; }
                        ol::ull rn = rnd->next();
                        if ( (rn & (1ull << 17))  )
                            //if ( !(rn & (31ull << 17))  ) test sparse
                            r.push_back ( Rcop { 0, ai, aj } );
                    }
            }

        return r;
    }
}

vvbool Lbs::unit(int sz)
{
    vvbool r;
    r.resize(sz, vbool(sz));

    for ( int i = 0; i < sz; i++ )
        for ( int j = 0; j < sz; j++ )
            r[i][j] = (i == j);

    return r;
}

void Bbs::generate()
{
    for ( auto i : bbs ) i->generate();
}

void Fbs::generate()
{
    int opsz = element.siz;
    int vsz = opsz + 2;

    if ( sz < vsz ) throw "Cannot generate F: cipher size too small";

    for ( int i = 0; i < 1000000; i++ )
    {
        int idx = rnd->next() % sz;
        if ( ol::isin(idxs, idx) ) continue;
        idxs.push_back(idx);
        if ( (int)idxs.size() == vsz ) return;
    }

    nevers("Cannot generate F: random generator fails");
}

void Lbs::generate()
{
    vector<Rcop> v = genRcops();
    A2 = A1 = unit(sz);

    int rcsz = (int)v.size();
    for (int i = 0; i < rcsz; i++)
    {
        int j = rcsz - 1 - i;
        apply(A1, v[i]);
        apply(A2, v[j]);
    }

    {
        // validate
        vvbool U = unit(sz);
        vvbool A3 = mul(A1, A2);
        if (!equal(A3, U)) never;
        A3 = mul(A2, A1);
        if (!equal(A3, U)) never;
    }

    for ( int i = 0; i < sz; i++ )
        b1[i] = (rnd->next() & (1ull << 17));

    mul(b2, A2, b1);
}

void Lbs::apply(vvbool & a, Rcop z)
{
    int s = (int)a.size();
    if ( z.rc )
        for ( int i = 0; i < s; i++ ) a[z.x][i] = (a[z.x][i] != a[z.y][i]);
    else
        for ( int i = 0; i < s; i++ ) a[i][z.x] = (a[i][z.x] != a[i][z.y]);
}

void Lbs::mul(vbool & y, const vvbool & a, const vbool x)
{
    int s = (int)y.size();
    for (int i = 0; i < s; i++)
    {
        y[i] = false;
        for (int j = 0; j < s; j++)
        {
            bool z = (a[i][j] && x[j]);
            y[i] = (y[i] != z);
        }
    }
}

vvbool Lbs::mul(const vvbool & a, const vvbool & b)
{
    int s = (int)a.size();
    vvbool r(s, vbool(s));

    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
        {
            r[i][j] = false;
            for (int k = 0; k < s; k++)
            {
                bool x = a[i][k] && b[k][j];
                r[i][j] = (r[i][j] != x);
            }
        }
    return r;
}

bool Lbs::equal(const vvbool & a, const vvbool & b)
{
    int s = (int)a.size();
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            if ( a[i][j] != b[i][j] ) return false;
    return true;
}


void lbs2cir(std::ostream & of, const vvbool & a, const vbool & b, bool xy)
{
    int sz = (int)a.size();
    int szo = sz, szi = sz;

    Varman vm;

    for (int i = 0; i < szo; i++) // each output
    {
        of << vm.xy(!xy, i) << " = ";
        bool plus = false;
        for (int j = 0; j < szi; j++) // each input
        {
            if (!a[i][j]) continue;
            if (plus) of << " ^ ";
            of << vm.xy(xy, j);
            plus = true;
        }

        if (!plus) of << "0";

        of << '\n';
    }

    for (int i = 0; i < szo; i++) // each output
    {
        if (!b[i]) continue;
        of << vm.xy(!xy, i) << " = !" << vm.xy(!xy, i) << '\n';
    }
}

void e3::cr::bbs2cir(string file)
{
    Bbsf bs(file, true);
    bs.cir();
}

void Bbsf::cir()
{
    std::ofstream of1(file + ".1.cir", std::ios::binary);
    std::ofstream of2(file + ".2.cir", std::ios::binary);
    Bbs::cir(of1, of2);
}

void Bbs::cir(std::ostream & of1, std::ostream & of2)
{

    //bbs2cir(file + ".1.cir", lbs.A1, lbs.b1);
    //bbs2cir(file + ".2.cir", lbs.A2, lbs.b2);

    {
        of1 << LogoF;

        bool xy = true;
        for ( auto i : bbs ) { of1 << '\n'; i->cir(of1, true, xy); }
    }


    // now write down the opposite
    {
        of2 << LogoF;

        bool xy = true;
        for ( size_t i = 0; i < bbs.size(); i++ )
        {
            of2 << '\n';
            auto j = bbs.size() - 1 - i;
            bbs[j]->cir(of2, false, xy);
        }
    }
}


void Lbs::cir(std::ostream & of, bool fwdmx, bool & xy)
{
    if ( fwdmx ) lbs2cir(of, A1, b1, xy);
    else lbs2cir(of, A2, b2, xy);

    // flip in-out for the next iteration
    xy = !xy;
}

void Fbs::cir(std::ostream & of, bool fwdmx, bool & xy)
{
    Varman vm;

    auto typ = element.typ;

    if ( idxs.size() < 2 ) nevers("Not enough variables for F");
    of << vm.xy(xy, idxs[0]) << " = " << vm.xy(xy, idxs[0]) << " ^ ";
    if ( typ == 'N' )
    {
        of << '!';
        typ = 'A';
    }
    of << "( " << vm.xy(xy, idxs[1]);

    string op = " * ";
    if ( typ == 'A' ) {}
    else if ( typ == 'R' ) op = " | ";
    else nevers("Bad element type");

    for ( size_t i = 2; i < idxs.size(); i++ ) of << op << vm.xy(xy, idxs[i]);

    of << " )\n";

    for ( size_t i = 1; i < idxs.size(); i++ )
    {
        auto y = vm.xy(xy, idxs[i]);
        of << y << " = " << y << '\n';
    }
}
