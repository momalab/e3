// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_PALI0_H_
#define _E3_DEF_PALI0_H_

#include <vector>

#include "def_pali.h"

namespace e3
{

namespace pali
{
using vi64 = std::vector<int64_t>;
} // pali

} // e3

namespace e3
{

struct PaliBfvCiphertext
{
    std::vector<int64_t> x;
    std::string str() const;
    PaliBfvCiphertext operator+(const PaliBfvCiphertext & a) const;
    PaliBfvCiphertext operator-(const PaliBfvCiphertext & a) const;
    PaliBfvCiphertext operator*(const PaliBfvCiphertext & a) const;
};

namespace pali
{
void load_dummy();
} // pali

} // e3

#endif // _E3_DEF_PALI0_H_
