// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "crcl.h"
#include "gram.h"

// circle := sequence of statements
// statement := oexpr = iexpr
// oexpr := name | args
// name := name
// args := (names comma sep'd)
// iexpr := name args | expr | <null>
// expr := xorm [ | xorm ]* // |==+
// xorm := term [ ^ term ]*
// term := prim [ & prim ]* // &=*
// prim := !prim | prim' | (expr) | name // !==~


#include "using.h"


void Oexpr::load(Pstream & is)
{
    string s; is >> s;
    if ( s != "(" )
    {
        name = Prim::isConst(s) ? s : context.name(s);
        return;
    }

    is << s;
    is >> args;
}

void Oexpr::out(std::ostream & os) const
{
    if (!name.empty())
    {
        os << name;
        return;
    }

    os << args;
}

vstr Oexpr::getVars() const
{
    if (!name.empty())
        return Prim::isConst(name) ? vstr() : vstr { name };

    return args.getVars();
}

void Oexpr::chVar(string nv, string ov)
{
    if (name.empty()) return args.chVar(nv, ov);
    if (ov == name) name = nv;
}



void Args::load(Pstream & is)
{
    string s; is >> s;

    if ( s != "(" ) throw "Expecting '(', got [" + s + "]";

    while ( 1 )
    {
        is >> s;
        if ( s == ")") return;
        names.push_back(Prim::isConst(s) ? s : context.name(s));
        is >> s;
        if ( s == ")") break;
        if ( s != "," ) throw "expecting ',' got [" + s + "]";
        if ( s == "" ) throw "unexpected EOL";
    }
}

void Args::out(std::ostream & os) const
{
    os << '(';
    for (const auto & x : names)
    {
        if (&x != &*names.begin()) os << ',';
        os << x;
    }
    os << ')';
}

vstr Args::getVars() const
{
    //return names; not so fast
    vstr r;
    for (auto x : names)
    {
        if (Prim::isConst(x)) continue;
        ol::merge(r, vstr { x });
    }
    return r;
}

void Args::chVar(string nv, string ov)
{
    for (auto & n : names)
        if (n == ov) n = nv;
}



void Iexpr::load(Pstream & is)
{
    string s;
    is >> s;
    if (s == "") throw "NUL statements not allowed";

    if ( expectblock )
    {
        if (s == "(") throw "Assign blocks not allowed, use {} syntax";
        is >> args;
        modname = s;
        typ = Typ::MOD;
        return;
    }
    is << s;
    node = Node::newnode(is);
    typ = Typ::EXP;
}

void Iexpr::out(std::ostream & os) const
{
    switch (typ)
    {
        case Typ::NUL: break;
        case Typ::MOD: os << ' ' << modname << args; break;
        case Typ::EXP: os << node->str(); break;
        default: nevers("typ");
    }
}

vstr Iexpr::getVars() const
{
    switch (typ)
    {
        case Typ::NUL: return vstr();
        case Typ::MOD: return args.getVars();
        case Typ::EXP: return node->getVars();
        default: nevers("typ");
    }
}

bool Iexpr::isVar(string * v) const
{
    if (!node) return false;
    const Prim * p = dynamic_cast<const Prim *>(node);
    if (!p) return false;
    if (p->neg) return false;
    if (p->expr) return false;
    *v = p->name;
    return true;
}



Node * Node::newnode(Pstream & is)
{
    return Expr::load(is);
}



Node * Expr::load(Pstream & is)
{
    Expr e;
    for (;;)
    {
        Node * xorm = Xorm::load(is);
        e.xorms.push_back(xorm);
        string s; is >> s;
        if ( s == "" ) break;
        if ( s == "+" || s == "|" ) continue;
        if ( s == ")" ) { is << s; break; }
        throw "expecting '+', '|' or EOL, got [" + s + "]";
    }

    if ( e.xorms.size() == 1 ) return e.xorms[0];
    if ( e.xorms.empty() ) nevers("bad expr");
    return new Expr(std::move(e));
}

string Expr::str() const
{
    string r;
    for ( const auto & x : xorms )
    {
        if ( &x != &*xorms.begin() ) r += " |";
        r += x->str();
    }
    return r;
}

vstr Expr::getVars() const
{
    vstr r;
    for (auto x : xorms) ol::merge(r, x->getVars());
    return r;
}



Node * Xorm::load(Pstream & is)
{
    Xorm x;
    for (;;)
    {
        Node * term = Term::load(is);
        x.terms.push_back(term);
        string s; is >> s;
        if (s == "") break;
        if (s == "^" ) continue;
        is << s; break;
    }

    if (x.terms.size() == 1) return x.terms[0];
    if (x.terms.empty()) nevers("bad xorm");
    return new Xorm(std::move(x));
}

string Xorm::str() const
{
    string r;
    for (const auto & x : terms)
    {
        if (&x != &*terms.begin()) r += " ^";

        if (need_paren(x))
            r += " (" + x->str() + " )";
        else
            r += x->str();
    }
    return r;
}

vstr Xorm::getVars() const
{
    vstr r;
    for (auto x : terms) ol::merge(r, x->getVars());
    return r;
}



Node * Term::load(Pstream & is)
{
    Term t;
    for (;;)
    {
        Node * prim = Prim::load(is);
        t.prims.push_back(prim);
        string s; is >> s;
        if ( s == "" ) break;
        if ( s == "*" || s == "&" ) continue;
        is << s; break;
    }

    if ( t.prims.size() == 1 ) return t.prims[0];
    if ( t.prims.empty() ) nevers("bad term");
    return new Term(std::move(t));
}

string Term::str() const
{
    string r;
    for ( const auto & x : prims )
    {
        if ( &x != &*prims.begin() ) r += " &";

        if ( need_paren(x) )
            r += " (" + x->str() + " )";
        else
            r += x->str();
    }
    return r;
}

vstr Term::getVars() const
{
    vstr r;
    for (auto x : prims) ol::merge(r, x->getVars());
    return r;
}


Node * Prim::load(Pstream & is)
{
    Prim p;

    string s;
prefix:
    is >> s;
    if ( s == "" ) throw s + "Unexpected EOL";

    if ( s == "!" || s == "~") { p.neg = !p.neg; goto prefix; }

    if ( s == "(" )
    {
        p.expr = Expr::load(is);
        is >> s;
        if ( s != ")" ) throw "Expecting ')', got [" + s + "]";
    }
    else
        p.name = isConst(s) ? s : context.name(s);

postfix:
    is >> s;
    if (s == "") goto done;
    if ( s == "'" ) { p.neg = !p.neg; goto postfix; }
    is << s;

done:
    if ( !p.neg && p.expr ) return p.expr;
    return new Prim(std::move(p));
}

string Prim::str() const
{
    string r = " ";
    if (neg) r += "!";

    if ( expr )
        r += "(" + expr->str() + " )";
    else
        r += name;

    return r;
}

vstr Prim::getVars() const
{
    if (expr) return expr->getVars();
    return isConst(name) ? vstr() : vstr { name };
}

void Prim::chVar(string nv, string ov)
{
    if (expr) return expr->chVar(nv, ov);
    if (name == ov) name = nv;
}

bool Prim::isConst(string * s) const
{
    if (expr) return false;
    if (!isConst(name)) return false;
    bool one = (name == "1");
    if (neg && one ) *s = "0";
    else if (!neg && one ) *s = "1";
    else if (neg && !one) *s = "1";
    else if (!neg && !one) *s = "0";
    return true;
}



bool Node::need_paren(const Node * kid) const
{
    // no double dispatch - just simple test for types
    if (dynamic_cast<const Term *>(this))
    {
        if (dynamic_cast<const Expr *>(kid)) return true;
        if (dynamic_cast<const Xorm *>(kid)) return true;
    }

    if (dynamic_cast<const Xorm *>(this))
    {
        if (dynamic_cast<const Expr *>(kid)) return true;
    }

    return false;
}
