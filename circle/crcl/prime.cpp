// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "eval.h"

#include "prime.h"
#include "vars.h"
#include "main.h"
#include "crutil.h"

#include "using.h"


using Val = ValPrime;

Val VisitorPrime::pval(Val::Op op, ValPrime a, ValPrime b)
{
    if (a.id == 1 && op == Val::And) return b;
    if (b.id == 1 && op == Val::And) return a;
    if (a.id == 0 && op == Val::Or) return b;
    if (b.id == 0 && op == Val::Or) return a;

    Val r;
    r.op = op;
    r.a = a.id;
    r.b = b.id;
    r.id = (int)vars.size();
    vars.push_back(r);
    return r;
}

Val e3::cr::VisitorPrime::pval(string n)
{
    Val r;
    r.op = Val::Inp;
    r.name = n;
    r.a = r.b = ValPrime().a;
    r.id = (int)vars.size();
    vars.push_back(r);
    return r;
}

void e3::cr::writePrime(string ofile, const Module & prog)
{
    VisitorPrime vis;

    int sz = prog.input_size();
    vector<Val> input(sz);
    for (int i = 0; i < sz; i++) input[i] = vis.pval(prog.name_inp(i));

    vector<Val> out = prog.eval(vis, input);

    int szo = prog.output_size();
    for (int i = 0; i < szo; i++)
    {
        int id = out[i].id;
        string name = prog.name_out(i);
        vis.vars[id].name = name;
    }

    const auto & vars = vis.vars;

    {
        std::ofstream of(ofile + ".out");
        for ( auto i : vars )
        {
            //of << i.id << " [" << i.name << "] op: " << i.op << ' ' << i.a << ' ' << i.b << '\n';
            if ( i.op == Val::Inp ) continue;
            of << i.n() << " = ";

            if (0) {}
            else if ( i.op == Val::Not ) of << "! " << vars[i.a].n();
            else if ( i.op == Val::And ) of << vars[i.a].n() << " * " << vars[i.b].n();
            else if ( i.op == Val::Xor ) of << vars[i.a].n() << " ^ " << vars[i.b].n();
            else if ( i.op == Val::Or ) of << vars[i.a].n() << " | " << vars[i.b].n();
            else nevers("Bad op: " + ol::tos(i.op));

            of << '\n';
        }
    }

    {
        std::ofstream of(ofile + ".mx");
        for ( auto i : vars )
        {
            string s = i.n();
            while ( s.size() < 6 ) s += " ";
            of << s << "| ";

            for ( auto j : vars )
            {
                if (0) {}
                else if ( i.op == Val::Not && i.a == j.id ) of << ' ' << i.op;
                else if ( i.op != Val::Inp && ( i.a == j.id || i.b == j.id) ) of << ' ' << i.op;
                else of << " 0";
            }

            of << '\n';
        }
    }
}

