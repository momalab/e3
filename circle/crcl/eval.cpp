// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "eval.h"

#include "using.h"

struct ValEval
{
//  Val() = delete;
    ValEval() {} // need this while using map with Val& in eval

    enum T {};
    ValEval(T) {}
};

using Val = ValEval;

struct TestVisitor
{
    Val::T t;

    Val Xor(const Val & a, const Val & b) { return Val(t); }
    Val And(const Val & a, const Val & b) { return Val(t); }
    Val Or(const Val & a, const Val & b) { return Val(t); }
    Val Not(const Val & a) { return Val(t); }

    std::map<string, Val> * m = nullptr;

    Val zr, un;
    const Val & zero() const { return zr; }
    const Val & unit() const { return un; }

    TestVisitor(): t(), zr(t), un(t) {}
    void(*callback)() = nullptr;
};

void testEval(const Module & prog)
{
    TestVisitor vis;

    vector<Val> input(3, vis.zero());

    vector<Val> out = prog.eval(vis, input);
}

