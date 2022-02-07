// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_PALISADE_CKKS0_H_
#define _E3_DEF_PALISADE_CKKS0_H_

#include <complex>
#include <vector>
#include "def_palisade_ckks.h"

namespace e3
{

struct PalisadeCkksCiphertext
{
    std::vector<std::complex<double>> x;
    std::string str() const;
    PalisadeCkksCiphertext() {}
    PalisadeCkksCiphertext(const PalisadeCkksCiphertext & a)
        : PalisadeCkksCiphertext(a.x) {}
    PalisadeCkksCiphertext(int a, int n)
        : PalisadeCkksCiphertext( double(a), n ) {}
    PalisadeCkksCiphertext(double a, int n)
        : PalisadeCkksCiphertext( std::complex<double>(a), n ) {}
    PalisadeCkksCiphertext(const std::complex<double> & a, int n)
        : PalisadeCkksCiphertext( std::vector<std::complex<double>>(n >> 1, a) ) {}
    PalisadeCkksCiphertext(const std::vector<int> &);
    PalisadeCkksCiphertext(const std::vector<double> &);
    PalisadeCkksCiphertext(const std::vector<std::complex<double>> &);

    PalisadeCkksCiphertext operator+(const PalisadeCkksCiphertext & a) const;
    PalisadeCkksCiphertext operator-(const PalisadeCkksCiphertext & a) const;
    PalisadeCkksCiphertext operator*(const PalisadeCkksCiphertext & a) const;
    PalisadeCkksCiphertext rotate(int s) const;
};

namespace palisade_ckks
{

void dummy();

} // palisade_ckks

} // e3

#endif // _E3_DEF_PALISADE_CKKS0_H_
