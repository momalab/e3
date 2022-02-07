// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_PALI_H_
#define _E3_DEF_PALI_H_

#include <string>
#include <memory>


namespace e3
{

struct PaliBfvCiphertext;
class PaliBfvEvalKey;

struct PaliBfvNativeEvalKey
{
    void * cc;
    void * pk;
};

using PaliBfvNativePrivKey = void * ;
using cPaliBfvNativeEvalKey = const void * ;

struct PaliBfvNativeCiphertext
{
    std::shared_ptr<PaliBfvCiphertext> p;

    std::string str() const;

    PaliBfvNativeCiphertext(); // new
    PaliBfvNativeCiphertext(const PaliBfvNativeCiphertext &); // = delete;
    PaliBfvNativeCiphertext(const std::string & enc, const PaliBfvEvalKey * ek);

    using This = PaliBfvNativeCiphertext;
    This op_add(const This & a, void * cc) const;
    This op_sub(const This & a, void * cc) const;
    This op_mul(const This & a, void * cc) const;
};

int pali_impl(); // 0 or 1

} // e3
#endif // _E3_DEF_PALI_H_
