// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_PRIME_H_
#define _E3_PRIME_H_

#include "olc.h"

#include "crcl.h"

namespace e3
{
namespace cr
{

void writePrime(std::string ofile, const Module & prog);

struct VisitorPrime;


struct ValPrime // keep ODR
{
    int id;
    std::string name;
    enum Op { Inp = 8, Not = 1, And = 2, Or = 3, Xor = 4 };
    Op op;
    int a, b;

    ValPrime(): ValPrime(-1) {}
    ValPrime(int i): id(i), op(Inp), a(-1), b(-1) {}
    ValPrime(const ValPrime &) = default;

    std::string n() const
    {
        if ( id == 0 ) return "0";
        if ( id == 1 ) return "1";
        return name == "" ? "_" + ol::tos(id) : name;
    }
};

struct VisitorPrime
{
    using Val = ValPrime; // keep ODR

    std::vector<Val> vars;

    Val pval(Val::Op op, ValPrime a, ValPrime b);
    Val pval(std::string n);

    Val Xor(const Val & a, const Val & b) { return pval(Val::Xor, a, b); }
    Val And(const Val & a, const Val & b) { return pval(Val::And, a, b); }
    Val Or(const Val & a, const Val & b) { return pval(Val::Or, a, b); }
    Val Not(const Val & a) { return pval(Val::Not, a, a); }

    std::map<std::string, Val> * m = nullptr;

    VisitorPrime() { vars.push_back(Val(0)); vars.push_back(Val(1)); }
    Val zero() const { return vars[0]; }
    Val unit() const { return vars[1]; }

    void(*callback)() = nullptr;
};


}
} // e3::cr

#endif // _E3_PRIME_H_
