// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>
#include "palisade.h"

#include "base64.h"
#include "e3util.h"
#include "def_palisade_ckks1.h"

using std::complex;
using std::string;

namespace e3
{

// Native constructors

PalisadeCkksNativeCiphertext::PalisadeCkksNativeCiphertext()
{
    p = std::shared_ptr<PalisadeCkksCiphertext>(new PalisadeCkksCiphertext);
}

PalisadeCkksNativeCiphertext::PalisadeCkksNativeCiphertext(const PalisadeCkksNativeCiphertext & ct)
{
    p = ct.p;
}

PalisadeCkksNativeCiphertext::PalisadeCkksNativeCiphertext(const string & strCiphertext, const PalisadeCkksEvalKey * ek)
{
    string bin = util::base64::dec(strCiphertext);
    palisade_ckks::Ciphertext_t ct = palisade_ckks::stringToCiphertext(bin);
    p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(ct) );
}

// Native operations

enum class Operation { ADD, SUB, MUL };

template <class T>
palisade_ckks::Plaintext_t toPlaintext(const T & a, void * context_ptr)
{
    auto & context = *palisade_ckks::toContext(context_ptr);
    return context->MakeCKKSPackedPlaintext(a);
}

template <class T>
PalisadeCkksNativeCiphertext operation(const PalisadeCkksNativeCiphertext & a, const T & b, void * context_ptr, Operation op)
{
    PalisadeCkksNativeCiphertext r;
    palisade_ckks::Context & context = *palisade_ckks::toContext(context_ptr);
    palisade_ckks::Ciphertext_t ct;
    switch (op)
    {
        case Operation::ADD: ct = context->EvalAdd (a.p->ct, b); break;
        case Operation::SUB: ct = context->EvalSub (a.p->ct, b); break;
        case Operation::MUL: ct = context->EvalMult(a.p->ct, b); break;
        default: throw "Invalid operation (def_palisade_ckks1.cpp::operation)";
    }
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(ct) );
    return r;
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const PalisadeCkksNativeCiphertext & a, void * context_ptr) const
{
    return operation(*this, a.p->ct, context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(int a, void * context_ptr) const
{
    return operation(*this, a, context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(double a, void * context_ptr) const
{
    return operation(*this, a, context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const complex<double> & a, void * context_ptr) const
{
    auto & context = *palisade_ckks::toContext(context_ptr);
    auto slots = context->GetRingDimension() >> 1;
    vector<complex<double>> v(slots, a);
    return operation(*this, toPlaintext(v, context_ptr), context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const vector<int> & a, void * context_ptr) const
{
    vector<double> v( a.begin(), a.end() );
    return operation(*this, toPlaintext(v, context_ptr), context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const vector<double> & a, void * context_ptr) const
{
    return operation(*this, toPlaintext(a, context_ptr), context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::add(const vector<complex<double>> & a, void * context_ptr) const
{
    return operation(*this, toPlaintext(a, context_ptr), context_ptr, Operation::ADD);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const PalisadeCkksNativeCiphertext & a, void * context_ptr) const
{
    return operation(*this, a.p->ct, context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(int a, void * context_ptr) const
{
    return operation(*this, a, context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(double a, void * context_ptr) const
{
    return operation(*this, a, context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const complex<double> & a, void * context_ptr) const
{
    auto & context = *palisade_ckks::toContext(context_ptr);
    auto slots = context->GetRingDimension() >> 1;
    vector<complex<double>> v(slots, a);
    return operation(*this, toPlaintext(v, context_ptr), context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const vector<int> & a, void * context_ptr) const
{
    vector<double> v( a.begin(), a.end() );
    return operation(*this, toPlaintext(v, context_ptr), context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const vector<double> & a, void * context_ptr) const
{
    return operation(*this, toPlaintext(a, context_ptr), context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::sub(const vector<complex<double>> & a, void * context_ptr) const
{
    return operation(*this, toPlaintext(a, context_ptr), context_ptr, Operation::SUB);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const PalisadeCkksNativeCiphertext & a, void * context_ptr) const
{
    return operation(*this, a.p->ct, context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(int a, void * context_ptr) const
{
    return operation(*this, a, context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(double a, void * context_ptr) const
{
    return operation(*this, a, context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const complex<double> & a, void * context_ptr) const
{
    auto & context = *palisade_ckks::toContext(context_ptr);
    auto slots = context->GetRingDimension() >> 1;
    vector<complex<double>> v(slots, a);
    return operation(*this, toPlaintext(v, context_ptr), context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const vector<int> & a, void * context_ptr) const
{
    vector<double> v( a.begin(), a.end() );
    return operation(*this, toPlaintext(v, context_ptr), context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const vector<double> & a, void * context_ptr) const
{
    return operation(*this, toPlaintext(a, context_ptr), context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::mul(const vector<complex<double>> & a, void * context_ptr) const
{
    return operation(*this, toPlaintext(a, context_ptr), context_ptr, Operation::MUL);
}

PalisadeCkksNativeCiphertext PalisadeCkksNativeCiphertext::rot(int s, void * context_ptr) const
{
    PalisadeCkksNativeCiphertext r;
    palisade_ckks::Context & context = *palisade_ckks::toContext(context_ptr);
    palisade_ckks::Ciphertext_t ct;
    ct = context->EvalAtIndex(p->ct, s);
    r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(ct) );
    return r;
}

vector<PalisadeCkksNativeCiphertext> PalisadeCkksNativeCiphertext::frot(const vector<int> & vs, void * context_ptr) const
{
    vector<PalisadeCkksNativeCiphertext> vr;
    palisade_ckks::Context & context = *palisade_ckks::toContext(context_ptr);
    uint32_t cyclotomicOrder = context->GetRingDimension() << 1;
    auto ctPrecomp = context->EvalFastRotationPrecompute(p->ct);
    for ( auto i : vs )
    {
        PalisadeCkksNativeCiphertext r;
        palisade_ckks::Ciphertext_t ct = context->EvalFastRotation(p->ct, i, cyclotomicOrder, ctPrecomp);
        r.p = std::shared_ptr<PalisadeCkksCiphertext>( new PalisadeCkksCiphertext(ct) );
        vr.push_back(r);
    }
    return vr;
}

// Native functions

string PalisadeCkksNativeCiphertext::str() const
{
    string bin = palisade_ckks::ciphertextToString(p->ct);
    return util::base64::enc(bin);
}

// Non-native functions

PalisadeCkksCiphertext::PalisadeCkksCiphertext(const palisade_ckks::Ciphertext_t & ciphertext)
{
    ct = ciphertext;
}

} // e3
