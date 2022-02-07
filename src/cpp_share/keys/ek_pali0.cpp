// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>
#include <vector>

#include "def_pali0.h"
#include "ek_pali.h"


using std::string;

namespace e3
{

struct PaliBfvQuery0 : e3::PaliBfvQuery
{
    virtual void print() const;
} paliBfvQuery0;

bool PaliBfvEvalKey::load(string fname)
{
    std::ifstream in(filename(), std::ios::binary);

    if ( !in ) return false;
    in >> polyDegree >> mulDepth >> useSlots >> maxDepth >> p_n;

    if ( !in ) return false;

    key.pk = &useSlots;

    pali::load_dummy();

    return true;
}

string PaliBfvEvalKey::rawEncrypt(const string & s, int msz) const
{
    e3::pali::vi64 v;
    if ( useSlots > 1 )
    {
        auto vs = e3::util::split(s, '_');
        for ( auto e : vs ) v.push_back( (int64_t) stoll(e) );
        v.resize( slots(), v.back() );
    }
    else v.push_back( (int64_t) stoll(s) );

    PaliBfvCiphertext ct {v};

    return ct.str();
}

size_t PaliBfvEvalKey::slots() const
{
    return useSlots;
}

e3::PaliBfvQuery * PaliBfvEvalKey::query() const
{
    return &e3::paliBfvQuery0;
}

void PaliBfvQuery0::print() const
{
    std::cout << "No parameters for pali0\n";
}

} // e3
