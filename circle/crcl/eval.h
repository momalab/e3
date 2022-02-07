// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EVAL_H_
#define _E3_EVAL_H_

#include <map>

#include "crcl.h"

namespace e3
{
namespace cr
{

template<typename Visitor, typename Vx>
std::vector<Vx> Module::eval(Visitor & vis, const std::vector<Vx> & inps, bool threaded) const
{

    if ( !threaded )
    {
        // set inputs
        // go through all statements with deletions
        // set outputs
        // clean up

        std::map<std::string, Vx> mlocal;
        if ( !vis.m ) vis.m = &mlocal; // let Visitor collect info
        std::map<std::string, Vx> & m = *vis.m;

        if (inps.size() != inputs.size()) nevers("inputs");
        int i = 0;
        for (auto x : inputs) m[x] = inps[i++];

        for (i = 0; i < size(); i++)
        {
            const Statement & s = *statements[i];
            auto outvars = s.getOutVars();

            // handle bogus assignment, e.g. 0=x+y
            if (outvars.empty()) continue;

            if (outvars.size() != 1) nevers("not flat");
            m[outvars[0]] = s.eval<Visitor, Vx>(vis);

            if ( vis.callback ) vis.callback();

            // if not Vx&, delete values here from middles
        }

        std::vector<Vx> r(outputs.size(), vis.zero());
        i = 0;
        for (auto x : outputs) r[i++] = m[x];

        if (vis.m == &mlocal) vis.m = nullptr; // turn off local

        // if not Vx&, cleanup here

        return r;
    }
    else
    {
        // check unique names
        // no: a=x+y; x=a+b;
        throw "evalThread not yet implemented";
    }

}

template<typename Visitor, typename Vx> Vx Statement::eval(Visitor & vis) const
{
    return iexpr.eval<Visitor, Vx>(vis);
}

template<typename Visitor, typename Vx> Vx Iexpr::eval(Visitor & vis) const
{
    if (typ != Typ::EXP) throw "Cannot evaluate on non-flat circle";
    if (!node) nevers("node");
    return node->eval<Visitor, Vx>(vis);
}

template<typename Visitor, typename Vx> Vx Node::eval(Visitor & vis) const
{
    // cannot do virtual templates inside classes, so for now
    // lets make a selector - not complex
    const Expr * e = dynamic_cast<const Expr *>(this);
    const Term * t = dynamic_cast<const Term *>(this);
    const Prim * p = dynamic_cast<const Prim *>(this);
    const Xorm * x = dynamic_cast<const Xorm *>(this);

    if (0) {}
    else if (e) return e->eval<Visitor, Vx>(vis);
    else if (t) return t->eval<Visitor, Vx>(vis);
    else if (p) return p->eval<Visitor, Vx>(vis);
    else if (x) return x->eval<Visitor, Vx>(vis);

    nevers("node");
}

template<typename Visitor, typename Vx> Vx Expr::eval(Visitor & vis) const
{
    Vx r = vis.zero();
    for (const auto & t : xorms) r = vis.Or(r, t->eval<Visitor, Vx>(vis));
    return r;
}


template<typename Visitor, typename Vx> Vx Xorm::eval(Visitor & vis) const
{
    Vx r = vis.zero();
    for (const auto & t : terms) r = vis.Xor(r, t->eval<Visitor, Vx>(vis));
    return r;
}

template<typename Visitor, typename Vx> Vx Term::eval(Visitor & vis) const
{
    Vx r = vis.unit();
    for (const auto & t : prims) r = vis.And(r, t->eval<Visitor, Vx>(vis));
    return r;
}

template<typename Visitor, typename Vx> Vx Prim::eval(Visitor & vis) const
{
    if (expr)
    {
        if (!name.empty()) nevers("prim");
        Vx r = expr->eval<Visitor, Vx>(vis);
        if (neg) r = vis.Not(r);
        return r;
    }

    // its name
    if (isConst(name))
    {
        bool v = (name == "1");
        if (neg) v = !v;
        return v ? vis.unit() : vis.zero();
    }

    Vx r = (*vis.m)[name];
    return neg ? vis.Not(r) : r;
}

}
} // e3::cr

#endif // _E3_EVAL_H_
