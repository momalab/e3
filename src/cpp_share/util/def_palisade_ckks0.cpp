// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <sstream>

#include "e3util.h"
#include "def_palisade_ckks.h"
#include "def_palisade_ckks0.h"
#include "ek_palisade_ckks.h"

using std::complex;
using std::string;
using std::vector;

namespace e3
{

// Native constructors

PalisadeCkksNativeCiphertext::PalisadeCkksNativeCiphertext()
{
    p = std::shared_ptr<PalisadeCkksCiphertext>(
            new PalisadeCkksCiphertext { vector<double>() }
        );
}

PalisadeCkksNativeCiphertext::PalisadeCkksNativeCiphertext(const PalisadeCkksNativeCiphertext & ct)
{
    p = ct.p;
}

PalisadeCkksNativeCiphertext::PalisadeCkksNativeCiphertext(const string & strCiphertext, const PalisadeCkksEvalKey * ek)
{
    vector<double> v;
    if ( ek->slots() < 2 )
        v = vector<double> { double( std::stod(strCiphertext) ) };
    else
    {
        vector<string> vs = util::split(strCiphertext, '^');
        for ( auto & s : vs ) v.push_back( std::stod(s) );
    }
    p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(v) );
}

// Native operations

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const PalisadeCkksNativeCiphertext & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + *a.p) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(int a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(double a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const std::complex<double> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const std::vector<int> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const std::vector<double> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const std::vector<std::complex<double>> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p + PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const PalisadeCkksNativeCiphertext & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - *a.p) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(int a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(double a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const std::complex<double> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const std::vector<int> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const std::vector<double> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const std::vector<std::complex<double>> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p - PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const PalisadeCkksNativeCiphertext & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p ** a.p) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(int a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p * PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(double a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p * PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const std::complex<double> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    int n = *( reinterpret_cast<int *>(context_ptr) );
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p * PalisadeCkksCiphertext(a, n) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const std::vector<int> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p * PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const std::vector<double> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p * PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const std::vector<std::complex<double>> & a, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(*p * PalisadeCkksCiphertext(a) ) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::rot(int s, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext( p->rotate(s) ) );
    return r;
}

vector<PalisadeCkksNativeCiphertext> PalisadeCkksNativeCiphertext::frot(const std::vector<int> & vs, void * context_ptr) const
{
    vector<PalisadeCkksNativeCiphertext> vr;
    for ( auto s : vs ) vr.push_back( this->rot(s, context_ptr) );
    return vr;
}

// Native functions

string PalisadeCkksNativeCiphertext::str() const
{
    return !!p ? p->str() : "";
}

// Non-native functions

PalisadeCkksCiphertext::PalisadeCkksCiphertext(const vector<int> & a)
{
    x = vector<complex<double>>( a.begin(), a.end() );
}

PalisadeCkksCiphertext::PalisadeCkksCiphertext(const vector<double> & a)
{
    x = vector<complex<double>>( a.begin(), a.end() );
}

PalisadeCkksCiphertext::PalisadeCkksCiphertext(const vector<complex<double>> & a)
{
    x.assign( a.begin(), a.end() );
}

static PalisadeCkksCiphertext e3_PalisadeCkksCiphertext_op(const PalisadeCkksCiphertext & a, const PalisadeCkksCiphertext & b, int op)
{
    PalisadeCkksCiphertext r;
    int sizeA = (int) a.x.size();
    int sizeB = (int) b.x.size();
    int size = std::max(sizeA, sizeB);
    r.x = a.x;
    r.x.resize(size, 0);

    for ( int i = 0; i < size; i++ )
    {
        if ( i < size ) switch (op)
            {
                case 0: r.x[i] += b.x[i]; break;
                case 1: r.x[i] -= b.x[i]; break;
                case 2: r.x[i] *= b.x[i]; break;
                default: throw "Unknown operation (def_palisade_ckks0.cpp)";
            }
    }
    return r;
}

PalisadeCkksCiphertext PalisadeCkksCiphertext::operator+(const PalisadeCkksCiphertext & a) const
{
    return e3_PalisadeCkksCiphertext_op(*this, a, 0);
}

PalisadeCkksCiphertext PalisadeCkksCiphertext::operator-(const PalisadeCkksCiphertext & a) const
{
    return e3_PalisadeCkksCiphertext_op(*this, a, 1);
}

PalisadeCkksCiphertext PalisadeCkksCiphertext::operator*(const PalisadeCkksCiphertext & a) const
{
    return e3_PalisadeCkksCiphertext_op(*this, a, 2);
}

PalisadeCkksCiphertext PalisadeCkksCiphertext::rotate(int s) const
{
    PalisadeCkksCiphertext r;
    auto size = x.size();
    r.x.resize(size);
    for ( size_t i = 0; i < size; i++ ) r.x[i] = x[ (i + s) % size ];
    return r;
}

string PalisadeCkksCiphertext::str() const
{
    return util::merge(x, "^");
}

} // e3
