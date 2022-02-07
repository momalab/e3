// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "invar.h"
#include "main.h"
#include "ttbl.h"

#include "using.h"

using Val = ValTtbl;

void e3::cr::writeProgTbl(string file, const Module & prog, V3foot * vf)
{
    std::map<string, int> * v3 = 0;
    if (vf) v3 = &vf->v3;

    std::map<string, ol::ull> * vc = 0;
    if (vf) vc = &vf->c;

    ol::ull cntr = 1;
    if (vf) cntr = vf->count;

    using msb = std::map<string, bool>;
    vector<msb> ptbl = prog.progressTable();

    auto mxsz = ptbl[0].size();
    for (auto & x : ptbl) if (mxsz < x.size()) mxsz = x.size();

    std::ofstream of(file);

    for (auto & x : ptbl)
    {
        auto sz = x.size();

        for (auto y : x)
        {
            if ( !v3 ) of << 'x';
            else
            {
                switch ((*v3)[y.first])
                {
                    case 0: of << '0'; break;
                    case 1: of << '1'; break;
                    case 2: of << 'x'; break;
                }
            }
        }

        for (size_t i = 0; i < mxsz - sz; i++) of << '.';
        of << '\n';
    }

    of << "= = =\n";
    for (auto & x : ptbl)
    {
        for (auto y : x)
        {
            of << ' ' << y.first;
            if (v3)
            {
                int v = (*v3)[y.first];
                if ( 2 - v ) of << '=' << v;
            }
        }
        of << '\n';
    }

    of << "= = =\n";
    for (auto & x : ptbl)
    {
        if ( !vf || !cntr ) break;
        for (auto y : x)
        {
            auto c = 1.0 * (*vc)[y.first];
            of << ' ' << c; // << ':' <<  cntr;
        }
        of << '\n';
    }

    of << "= = =\n";
    int totm = 0, toti = 0, mid = 0;
    for (auto & x : ptbl)
    {
        for (auto y : x)
            if (v3 && ( 2 - (*v3)[y.first] ) )
            {
                if ( mid ) ++totm;
                else ++toti;
            }
        mid = 1;
    }

    of << "Input  " << toti << '\n';
    of << "Middle " << totm << '\n';
    of << "Total  " << (totm + toti) << '\n';
}

vector< std::map<string, bool> > Module::progressTable() const
{
    using msb = std::map<string, bool>;
    vector<msb> ptbl;

    msb entry, known;
    for (auto x : inputs) entry[x] = false;
    ptbl.push_back(entry);

    while (true)
    {
        known.insert(entry.begin(), entry.end());
        entry.clear();
        for (const auto & s : statements)
        {
            vstr ins = s->getInVars();

            // check if all ins are in knwon
            bool allin = true;
            for ( auto n : ins )
                if ( known.find(n) == known.end() )
                {
                    allin = false;
                    break;
                }
            if (!allin) continue;

            // this statement can be evaluated at this step
            //string outname = s->getOutName(); cannot do this as "0="
            vstr voutname = s->getOutVars();
            if (voutname.size() > 1) nevers("not flat");
            if (voutname.empty()) continue; // "0=" case
            string outname = voutname[0];
            if (known.find(outname) != known.end()) continue;
            entry[outname] = false;
        }
        if (entry.empty()) break;
        ptbl.push_back(entry);
    }

    return ptbl;
}

void report_progress(std::map<string, int> & v3)
{
    static int i = 0; i++;
    int s[3] = {0, 0, 0};
    for ( auto x : v3 ) ++s[x.second];

    cout << i << '\t' << s[0] << '\t' << s[1] << '\t' << s[2] << '\n';
}

void e3::cr::findInvariants(string file_in, string file_ttb,
                            string file_out, const Module & prog, bool prgr)
{
    int sz = prog.input_size();
    if (sz < 1) throw "Empty circle";

    TableIterator it(sz);
    using vvb = TableIterator::vvb;
    vvb ve;

    if (file_ttb.empty()) nevers("empty ttb");

    {
        std::ifstream in(file_ttb);
        if (!in) throw "Cannot open file [" + file_ttb + "]";
        bool cur_ari = checkFmt(file_ttb, in);
        loadTT(in, ve, sz, cur_ari);
        it.setvvb(ve);
    }

    V3foot vf;
    std::map<string, int> & v3 = vf.v3; // value 0-false, 1-true, 2-varies

    int cntr = 0;
    vector<Val> input(sz);
    for (; it.ok(); it.next())
    {
        if (++cntr > 10000)
        {
            cout << int(10000.0 * it.idx() / it.size()) / 100 << "%  \r";
            cntr = 0;
        }

        for (int j = 0; j < sz; j++)
            input[j] = Val { it.bit(j) };

        BitVisitorTtbl bitVisitor;
        std::map<string, Val> m;
        bitVisitor.m = &m;
        vector<Val> out1 = prog.eval(bitVisitor, input);

        for (const auto & x : m)
        {
            const string & n = x.first;
            const Val & v = x.second;
            int vi = (v.bit ? 1 : 0);
            if (v3.find(n) == v3.end()) v3[n] = vi;
            if (v3[n] != vi) v3[n] = 2;
            if (vi) ++vf.c[n];
        }

        if (prgr) ::report_progress(v3);
    }
    vf.count = cntr;

    writeProgTbl(file_out, prog, &vf);
}

