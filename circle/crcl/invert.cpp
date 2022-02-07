// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <cstring>
#include <numeric>
#include <chrono>

#include "cuddObj.hh"
#include "cuddInt.h"

#include "invert.h"
#include "eval.h"
#include "bdda.h"

#include "using.h"

// need e3::cr decl for cuddObj
namespace e3 { namespace cr {} }
using namespace e3::cr;

const bool INTERMIX = false;
const bool STATEREDUCE = true;
const bool FINALREDUCE = true;

using Val = BDD;
struct InvVisitor
{
    Val Xor(const Val & a, const Val & b) { return b ^ a ; }
    Val And(const Val & a, const Val & b) { return b & a ; }
    Val Or(const Val & a, const Val & b) { return b | a; }
    Val Not(const Val & a) { return !a; }

    std::map<string, Val> * m = nullptr;

    Val zr, un;
    const Val & zero() const { return zr; }
    const Val & unit() const { return un; }

    InvVisitor(Cudd & m) : zr(m.bddZero()), un(m.bddOne()) { mgr = &m; callback = reduceHeap;  }

    static Cudd * mgr; // need static (no thread safe) for callback
    void (*callback)();
    static void reduceHeap() { if (STATEREDUCE) mgr->ReduceHeap();  }
};

Cudd * InvVisitor::mgr = nullptr;

struct Invrec
{
    Statement * st;
    string delvar;
    Val G;
    Val g0, g1;
};

inline string str(const Val & x) { return x.FactoredFormString(); }
inline string str(const Val & x, const char ** n) { return x.FactoredFormString(n); }

void Invertor::invert(std::ostream & of)
{
    auto time_start = std::chrono::system_clock::now();
    Cudd mgr(0, 0);

    // testing - do not forget Cudd-0 interface
    if (0)
    {
        Val x = mgr.bddVar();
        Val y = mgr.bddVar();
        Val u = mgr.bddVar();
        Val z = y ^ u;
        Val a = y * x;

        cout << "x=" << x.FactoredFormString() << '\n';
        cout << "y=" << y.FactoredFormString() << '\n';
        cout << "z=" << z.FactoredFormString() << '\n';
        cout << "a=" << a.FactoredFormString() << '\n';
        cout << ' ' << x.getNode()->index << ' ' << u.getNode()->index << ' ' << y.getNode()->index << '\n';

        z = z.Compose(x, 2);
        cout << "z'=" << z.FactoredFormString() << '\n';
    }

    Val zeroIndexBdd_dummyVar = mgr.bddVar(); // let index 0 be excluded from variables
    // this is because index of formulas (non-terminals) is 0

    std::map<string, Val> name2var;
    std::map<string, size_t> name2idx;
    std::vector<string> idx2name {"?"};

    vstr inputs = module.inputs;
    vstr outputs = module.outputs;

    auto addvar = [&name2idx, &idx2name, &name2var, &mgr](string s)
    {
        if (name2idx.find(s) != name2idx.end()) return;
        Val v = mgr.bddVar();
        size_t idx = v.getNode()->index;
        while (idx2name.size() < idx + 1) idx2name.resize(idx + 1, "?");
        idx2name[idx] = s;
        name2idx[s] = idx;
        name2var[s] = v;
    };

    for (auto x : inputs) addvar(x);
    for (auto x : outputs) addvar(x);

    std::vector<Invrec> chain;

    // build last usage and chain
    {
        std::map<string, int> lastuse;
        int cnt = 0;
        for (auto x : module.statements)
        {
            vstr oe = x->getOutVars();
            if (oe.empty()) continue;
            if (oe.size() != 1)
            {
                ostr os; os << (*x);
                throw "Not flattened statement [" + os.str() + "]";
            }
            addvar(oe[0]);
            lastuse[oe[0]] = cnt;
            vstr ie = x->getInVars();
            for (auto y : ie)
            {
                addvar(y);
                lastuse[y] = cnt;
            }
            ++cnt;
        }

        // remove outputs from lastuse
        for ( auto x : outputs ) lastuse.erase(x);

        // print lastuse
        if (0) for (auto x : lastuse) cout << x.first << ' ' << x.second << '\n';

        // build chain
        cnt = 0;
        for (auto x : module.statements)
        {
            vstr oe = x->getOutVars();
            if (oe.empty()) continue;
            if (oe.size() != 1) never;
            chain.push_back(Invrec { x });
            for (const auto & y : lastuse)
            {
                if (y.second != cnt) continue;
                chain.push_back(Invrec { nullptr, y.first });
            }
            ++cnt;
        }
    }

    // init inames
    using ccp = const char *;
    ccp * inames = new ccp[idx2name.size()];
    for (size_t i = 0; i < idx2name.size(); i++)
    {
        //inames[i] = idx2name[i].c_str();
        const string & s = idx2name[i];
        auto sz = s.size() + 1;
        auto p = new char[sz];
        inames[i] = p;
        std::strncpy(p, s.c_str(), sz);
    }

    // print chain
    if (0) for (auto x : chain) (x.st ? (cout << *x.st) : (cout << '~')) << x.delvar << '\n';

    InvVisitor visitor(mgr);
    visitor.m = &name2var;

    auto mem =  mgr.ReadMemoryInUse();

    // process chain - calculate Gs
    Val prevG = visitor.zero();
    for (auto & rec : chain)
    {
        auto st = rec.st;
        if (st)
        {
            Val ov = name2var[st->getOutName()];
            Val iv = st->eval<InvVisitor, Val>(visitor);
            rec.G = prevG | (ov ^ iv);
        }
        else
        {
            int idx = (int)name2idx[rec.delvar]; // Compose requires int
            rec.g0 = prevG.Compose(visitor.zero(), idx);
            rec.g1 = prevG.Compose(visitor.unit(), idx);
            rec.G = rec.g0 & rec.g1;
        }
        prevG = rec.G;
        auto amem =  mgr.ReadMemoryInUse();
        if ( amem > mem ) mem = amem;
    }

    // print chain
    if (0) for (auto x : chain)
        {
            (x.st ? (cout << *x.st) : (cout << '~')) << x.delvar << '\n';
            cout << "G= " << str(x.G, inames) << '\n';
            if (!x.st)
            {
                cout << "g0= " << str(x.g0, inames) << '\n';
                cout << "g1= " << str(x.g1, inames) << '\n';
            }
            cout << '\n';
        }

    // output
    for (auto i = chain.size() - 1; i > 0; i--)
    {
        auto & rec = chain[i];
        if (rec.st) continue;
        of << rec.delvar << " = " << str(rec.g0, inames) << '\n';
    }

    for ( auto x : inputs ) of << x << " = " << x << '\n';

    // clean up
    for (size_t i = 0; i < idx2name.size(); i++) delete[] inames[i];
    delete[] inames;

    if (0) { string ss; std::cin >> ss; }

    auto time_end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = time_end - time_start;
    auto duration = diff.count();

    // report memory and time usage
    std::cout << "Memory used: " << mem / 1024 / 1024 << " Mb\n";
    std::cout << "Time taken: ";
    if ( duration < 1000 ) std::cout << duration;
    else std::cout << int(0.5 + duration);
    std::cout << " s\n";
}


