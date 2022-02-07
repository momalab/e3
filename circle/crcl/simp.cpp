// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "crcl.h"
#include "simp.h"

#include "using.h"

void e3::cr::simplify(string file, Module & prog)
{
    if (prog.reuse) throw "Cannot simplify on reused vars - clean vars first";
    std::ofstream of(file);

    {
        auto inps = prog.inps();
        auto outs = prog.outs();

        while ( prog.simplify() );

        if ( inps != prog.inps() || outs != prog.outs() )
            cout << "Attention: number and order of inputs and outputs may change\n";
    }

    of << "# simplify\n";
    of << prog;
    cout << "circle written\n";
}


bool Module::simplify()
{
    bool changed = false;

    // remove dummy statements
    {
        vector<Statement *> new_statements;
        for (int i = 0; i < size(); i++)
        {
            Statement *& s = statements[i];
            if ( !s ) continue;
            vstr n = s->getOutVars();

            // do not remove "0 = x3" - explicit input
            if ( n.empty() )
            {
                string val;
                if (s->isVar(&val) && ol::isin(inputs, val) ) {}
                else continue;
            }

            if (n.size() > 1) throw "Circle is not flat";
            new_statements.push_back(s);
        }
        if (new_statements.size() < statements.size() )
        {
            new_statements.swap(statements);
            changed = true;
        }
    }

    std::map<string, string> outRedirect;

    std::map<string, string> resolvedVars;
    for (int i = 0; i < size(); i++)
    {
        Statement *& s = statements[i];
        s->simplify(resolvedVars);
        string val;

        // null statement with input
        if ( s->getOutVars().empty() ) continue;

        if (s->isConst(&val) || s->isVar(&val))
        {
            string name = s->getOutName();

            // if it's output do not replace
            if ( ol::isin(outputs, name) )
            {
                if ( s->isVar(&val) && !ol::isin(inputs, val) )
                    outRedirect[name] = val;
                continue;
            }

            resolvedVars[name] = val;

            for (int j = i + 1; j < size(); j++)
                statements[j]->chVar(val, name, false);

            // disable statement
            delete s;
            s = nullptr;
            changed = true;
        }
    }

    for ( const auto & r : outRedirect )
    {
        int idxo = findStatement(r.first);
        int idxm = findStatement(r.second);
        if ( idxo < 0 || idxm < 0 ) nevers("bad idx " + r.first + " = " + r.second);

        // find last use and check that it is actually idxo
        int nu = findNofUse(r.second);
        if ( nu < 1 ) nevers("not expected nofuse");

        // do not remove - it is used in other places
        if ( nu != 1 ) continue;

        Statement *& s = statements[idxm];
        statements[idxo]->redirect(s);
        delete s;
        s = nullptr;
        changed = true;
    }

    auto inps = inputs;
    auto outs = outputs;
    initIOMs();

    if ( !changed )
    {
        if ( inps == inputs && outs == outputs ) return false;
        nevers("Internal error: bad inouts");
    }

    if ( inps != inputs )
    {
        //cout << "inps1:"; for ( auto x : inps ) cout << ' ' << x; cout << '\n';
        //cout << "inps2:"; for ( auto x : inputs ) cout << ' ' << x; cout << '\n';

        // some imputs disappeared; add them
        for ( auto i : inps )
        {
            if ( ol::isin(inputs, i) ) continue;
            Statement * s = new Statement("0 = " + i);
            statements.push_back(s);
        }
    }

    // need while loop because removing may cause new bogus outputs to appear
    while ( outs != outputs )
    {
        //cout << "outs1:"; for ( auto x : outs ) cout << ' ' << x; cout << '\n';
        //cout << "outs2:"; for ( auto x : outputs ) cout << ' ' << x; cout << '\n';

        // some outputs appeared; remove them
        for ( auto i : outputs )
        {
            if ( ol::isin(outs, i) ) continue;
            int idx = findStatement(i);
            if ( idx < 0 ) nevers("Bad statement with [" + i + "]");
            Statement *& s = statements[idx];
            // disable statement
            delete s;
            s = nullptr;
        }
        initIOMs();
    }

    initIOMs();

    return true;
}

void Iexpr::simplify(const std::map<string, string> & m)
{
    if (node) node->simplify(&node, m);
}

void Expr::simplify(Node ** p, const mss & m)
{
    auto & elems = xorms;
    vector<Node *> nelems;

    for (auto & x : elems) x->simplify(&x, m);

    for (auto & x : elems)
    {
        string v;
        if (!x->isConst(&v)) nelems.push_back(x);
        else if (v == "0") { delete x; }
        else if (v == "1")
        {
            for (auto & j : elems) delete j;
            delete this;
            *p = new Prim(v);
            return;
        }
        else nevers("simplify");
    }

    if (nelems.size() > 1)
    {
        xorms.swap(nelems);
        return;
    }

    if (nelems.empty()) // all evaluated to "0"
    {
        *p = new Prim("0");
        return;
    }

    // size == 1
    delete *p;
    *p = nelems[0];
}

void Xorm::simplify(Node ** p, const mss & m)
{
    auto & elems = terms;
    vector<Node *> nelems;

    for (auto & x : elems) x->simplify(&x, m);

    for (auto & x : elems)
    {
        string v;
        if (!x->isConst(&v)) nelems.push_back(x);
        else if (v == "1") nelems.push_back(x);
        else if (v == "0") { delete x; }
        else nevers("simplify");
    }

    if (nelems.size() > 1)
    {
        terms.swap(nelems);
        return;
    }

    if (nelems.empty()) // all evaluated to "0"
    {
        *p = new Prim("0");
        return;
    }

    // size == 1
    delete *p;
    *p = nelems[0];
}

void Term::simplify(Node ** p, const mss & m)
{
    auto & elems = prims;
    vector<Node *> nelems;

    for (auto & x : elems) x->simplify(&x, m);

    for (auto & x : elems)
    {
        string v;
        if (!x->isConst(&v)) nelems.push_back(x);
        else if (v == "1") { delete x; x = nullptr; }
        else if (v == "0")
        {
            for (auto & j : elems) delete j;
            elems.clear();
            *p = new Prim(v);
            return;
        }
        else nevers("simplify");
    }

    if (nelems.size() > 1)
    {
        prims.swap(nelems);
        return;
    }

    if (nelems.empty()) // all evaluated to "1"
    {
        *p = new Prim("1");
        return;
    }

    // size == 1
    elems.clear();
    delete *p;
    *p = nelems[0];
}

void Prim::simplify(Node ** p, const mss & m)
{
    if (expr)
    {
        expr->simplify(&expr, m);
        string v;
        if (expr->isConst(&v))
        {
            delete expr;
            expr = nullptr;
            name = v;
        }
        return;
    }

    auto i = m.find(name);
    if ( i != m.end()) name = i->second;
}

