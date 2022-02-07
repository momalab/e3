// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include <cstdio>

#include "cuddObj.hh"
#include "eval.h"
#include "bdda.h"

const bool INTERMIX = false;
bool g_BddReorder = true;

// example
//void main(){Cudd mgr(0, 0);BDD a0 = mgr.bddVar();}

namespace e3 { namespace cr {} }
using namespace e3::cr;
using std::string;
using std::vector;

using Val = BDD;
struct BddVisitorBdd
{
    Val Xor(const Val & a, const Val & b) { return b ^ a ; }
    Val And(const Val & a, const Val & b) { return b & a ; }
    Val Or(const Val & a, const Val & b) { return b | a; }
    Val Not(const Val & a) { return !a; }

    std::map<string, Val> * m = nullptr;

    Val zr, un;
    const Val & zero() const { return zr; }
    const Val & unit() const { return un; }

    BddVisitorBdd(Cudd & m) : zr(m.bddZero()), un(m.bddOne()) { mgr = &m; callback = reduceHeap;  }

    static Cudd * mgr; // need static (no thread safe) for callback
    void (*callback)();
    static void reduceHeap() { if (g_BddReorder) mgr->ReduceHeap();  }
};

Cudd * BddVisitorBdd::mgr = nullptr;

void e3::cr::writeBDD(string file, const Module & prog, bool dot, bool reorder)
{
    g_BddReorder = reorder;

    Cudd mgr(0, 0);

    if ( g_BddReorder ) mgr.AutodynEnable();
    else mgr.AutodynDisable();

    int sz = prog.input_size();
    if (sz < 1) throw "Empty circle";

    vector<Val> input(sz);

    if ( INTERMIX && sz % 2 == 0 )
    {
        for (int i = 0; i < sz / 2; i++)
        {
            input[i] = mgr.bddVar();
            input[sz / 2 + i] = mgr.bddVar();
        }
    }
    else
        for (int i = 0; i < sz; i++) input[i] = mgr.bddVar();

    BddVisitorBdd bddVisitor(mgr);
    vector<Val> out = prog.eval(bddVisitor, input);

    if ( g_BddReorder ) mgr.ReduceHeap();

    FILE * fp = fopen(file.c_str(), "w");
    mgr.DumpDDcal(out, 0, 0, fp);
    fclose(fp);

    if ( dot )
    {
        {
            FILE * fd = fopen((file + ".dot").c_str(), "w");
            mgr.DumpDot(out, 0, 0, fd);
            fclose(fd);
        }
        {
            FILE * fd = fopen((file + ".dav").c_str(), "w");
            mgr.DumpDaVinci(out, 0, 0, fd);
            fclose(fd);
        }
        {
            FILE * fd = fopen((file + ".blf").c_str(), "w");
            mgr.DumpBlif(out, 0, 0, 0, fd);
            fclose(fd);
        }
        {
            FILE * fd = fopen((file + ".fac").c_str(), "w");
            mgr.DumpFactoredForm(out, 0, 0, fd);
            fclose(fd);
        }
    }
}

int e3::cr::cudd_impl()
{
    if ( Cudd(0, 0).ReadTimeLimit() == 0xBAD ) return 0;
    return 1;
}
