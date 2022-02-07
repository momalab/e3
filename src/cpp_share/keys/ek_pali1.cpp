// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>
#include <vector>

#include "def_pali1.h"
#include "ek_pali.h"
#include "base64.h"


using std::string;

namespace e3
{


bool PaliBfvEvalKey::load(string fname)
{
    if ( !e3::pali::load_pub_possible(name.fil) ) return false;

    key.cc = new e3::pali::Cc;
    key.pk = new e3::pali::PubKey;

    e3::pali::Cc & cc = *e3::pali::tocc(key.cc);
    e3::pali::PubKey & pk = *e3::pali::topk(key.pk);

    cc = e3::pali::load_context(name.fil);
    pk = e3::pali::load_pub_main(name.fil);
    e3::pali::load_pub_eval(cc, name.fil);

    e3::pali::load_params(name.fil, polyDegree, mulDepth, useSlots, maxDepth, p_n);

    return true;
}

string PaliBfvEvalKey::rawEncrypt(const string & s, int msz) const
{
    using std::cout;

    e3::pali::vi64 v;
    if ( useSlots > 1 )
    {
        auto vs = e3::util::split(s, '_');
        for ( auto e : vs ) v.push_back( (int64_t) stoll(e) );
        v.resize( slots(), v.back() );
    }
    else v.push_back( (int64_t) stoll(s) );

    auto ct = e3::pali::encrypt(*e3::pali::tocc(key.cc), *e3::pali::topk(key.pk), v);

    string sct = e3::util::base64::enc(e3::pali::ct2str(ct));

    return sct;
}

size_t PaliBfvEvalKey::slots() const
{
    if ( useSlots == 1 ) return 1;

    return (*e3::pali::tocc(key.cc))->GetRingDimension();
}


struct PaliBfvQuery1 : e3::PaliBfvQuery
{
    virtual void print() const;

    string m_schemeId;
    size_t m_keyGenLevel;

    e3::pali::CryParams cryParams;
    e3::pali::ParmType parmType;
    e3::pali::EncParams encParams;

    uint32_t cycOrder;
    uint32_t ringDim;
    e3::pali::IntType modulus;
    e3::pali::IntType rootOfU;
    int qbits;

//  const usint GetCyclotomicOrder() const {
//  const usint GetRingDimension() const {
//  const IntType& GetModulus() const {
//  const IntType& GetRootOfUnity() const {

} paliBfvQuery1;

e3::PaliBfvQuery * PaliBfvEvalKey::query() const
{
    e3::pali::Cc & cc = *e3::pali::tocc(key.cc);

    e3::PaliBfvQuery1 & q = e3::paliBfvQuery1;

    q.m_schemeId = cc->getSchemeId();
    q.cryParams = cc->GetCryptoParameters();
    q.m_keyGenLevel = cc->GetKeyGenLevel();
    q.parmType = cc->GetElementParams();
    q.encParams = cc->GetEncodingParams();

    q.cycOrder = cc->GetCyclotomicOrder();
    q.ringDim = cc->GetRingDimension();
    q.modulus = cc->GetModulus();
    q.rootOfU = cc->GetRootOfUnity();

    {
        auto m = q.modulus;
        int b = 0;
        while ( (m >>= 1) > 0 ) ++b;
        q.qbits = ++b;
    }

    return &e3::paliBfvQuery1;
}

void PaliBfvQuery1::print() const
{
    std::cout << " ** Parameters for pali1 **\n";
    std::cout << "SchemeId    : " << m_schemeId << "\n";
    std::cout << "KeyGenLevel : " << m_keyGenLevel << "\n";

    std::cout << "CycOrder    : " << cycOrder << "\n";
    std::cout << "RingDim     : " << ringDim << "\n";
    std::cout << "Modulus     : " << modulus << "\n";
    std::cout << "Qbits       : " << qbits << "\n";
    std::cout << "RootOfU     : " << rootOfU << "\n";

    std::cout << "EncodingParams : " << *encParams << "\n\n";

    std::cout << " ** ParmType **\n" << *parmType << "\n";
    std::cout << " ** CryParams **\n" << *cryParams << "\n";
}

} // e3
