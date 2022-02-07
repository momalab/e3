// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_BFV_H_
#define _E3_DEF_BFV_H_

#include <string>
#include <memory>

namespace e3
{

class BfvProtEvalKey;

struct BfvProtNativeCiphertext
{
    std::string str() const;

    BfvProtNativeCiphertext(); // new
    BfvProtNativeCiphertext(const BfvProtNativeCiphertext &); // = delete;
    BfvProtNativeCiphertext(const std::string & enc, BfvProtEvalKey * ek);
};

} // e3

#endif // _E3_DEF_BFV_H_
