// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_PALISADE_CKKS_H_
#define _E3_DEF_PALISADE_CKKS_H_

#include <complex>
#include <memory>
#include <string>
#include <vector>

namespace e3
{

struct PalisadeCkksCiphertext;
class PalisadeCkksEvalKey;

struct PalisadeCkksNativeEvalKey
{
    void * cc;
    void * pk;
};

using PalisadeCkksNativePrivKey = void * ;
using cPalisadeCkksNativeEvalKey = const void * ;

struct PalisadeCkksNativeCiphertext
{
    std::shared_ptr<PalisadeCkksCiphertext> p;

    std::string str() const;

    PalisadeCkksNativeCiphertext(); // new
    PalisadeCkksNativeCiphertext(const PalisadeCkksNativeCiphertext &); // = delete;
    PalisadeCkksNativeCiphertext(const std::string & enc, const PalisadeCkksEvalKey * ek);

    using This = PalisadeCkksNativeCiphertext;

    This add(const This & a, void * cc) const;
    This add(int a, void * cc) const;
    This add(double a, void * cc) const;
    This add(const std::complex<double> & a, void * cc) const;
    This add(const std::vector<int> & a, void * cc) const;
    This add(const std::vector<double> & a, void * cc) const;
    This add(const std::vector<std::complex<double>> & a, void * cc) const;

    This sub(const This & a, void * cc) const;
    This sub(int a, void * cc) const;
    This sub(double a, void * cc) const;
    This sub(const std::complex<double> & a, void * cc) const;
    This sub(const std::vector<int> & a, void * cc) const;
    This sub(const std::vector<double> & a, void * cc) const;
    This sub(const std::vector<std::complex<double>> & a, void * cc) const;

    This mul(const This & a, void * cc) const;
    This mul(int a, void * cc) const;
    This mul(double a, void * cc) const;
    This mul(const std::complex<double> & a, void * cc) const;
    This mul(const std::vector<int> & a, void * cc) const;
    This mul(const std::vector<double> & a, void * cc) const;
    This mul(const std::vector<std::complex<double>> & a, void * cc) const;

    This rot(int s, void * cc) const;
    std::vector<This> frot(const std::vector<int> & vs, void * cc) const;
};

// int pali_impl();

} // e3

#endif // _E3_DEF_PALISADE_CKKS_H_
