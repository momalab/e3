#pragma once

#include <map>

#include "olc.h"

#include "crutil.h"

struct Node
{
    static Node * newnode(Pstream & is);
    virtual string str() const = 0;
    virtual vstr getVars() const = 0;
    virtual void chVar(string nv, string ov) = 0;
    virtual bool isConst(string * v) const = 0;

    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    using mss = std::map<string, string>;
    virtual void simplify(Node ** parent, const mss & m) = 0;

    // no clean up policy !
    virtual ~Node() {}
    bool need_paren(const Node * kid) const;
};

struct Expr;
struct Prim : Node
{
    bool neg;
    Node * expr;
    string name; // can be 0 or 1

    Prim() : neg(false), expr(nullptr) {}
    Prim(string n) : neg(false), expr(nullptr), name(n) {}

    static Node * load(Pstream & is);
    virtual string str() const;
    virtual vstr getVars() const;
    virtual void chVar(string nv, string ov);
    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;

    static bool isConst(string s) { return (s == "0" || s == "1"); }
    bool isConst(string * s) const;
    virtual void simplify(Node ** p, const mss & m);
};

struct Term : Node
{
    vector<Node *> prims;
    static Node * load(Pstream & is);
    virtual string str() const;
    virtual vstr getVars() const;
    virtual void chVar(string nv, string ov) { for (auto & x : prims) x->chVar(nv, ov); }
    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    bool isConst(string * s) const { return false; }
    virtual void simplify(Node ** p, const mss & m);
};

struct Xorm : Node
{
    vector<Node *> terms;
    static Node * load(Pstream & is);
    virtual string str() const;
    virtual vstr getVars() const;
    virtual void chVar(string nv, string ov) { for (auto & x : terms) x->chVar(nv, ov); }
    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    bool isConst(string * s) const { return false; }
    virtual void simplify(Node ** p, const mss & m);
};

struct Expr : Node
{
    vector<Node *> xorms;
    static Node * load(Pstream & is);
    virtual string str() const;
    virtual vstr getVars() const;
    virtual void chVar(string nv, string ov) { for (auto & x : xorms) x->chVar(nv, ov); }
    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    bool isConst(string * s) const { return false; }
    virtual void simplify(Node ** p, const mss & m);
};

struct Args
{
        vstr names;
        Args() {}

        friend Pstream & operator>>
        (Pstream & is, Args & e) { e.load(is); return is; }
        friend std::ostream & operator<<
        (std::ostream & os, const Args & s) { s.out(os); return os; }

        vstr getVars() const;
        void chVar(string nv, string ov);

    private:
        void load(Pstream & is);
        void out(std::ostream & os) const;
};

struct Oexpr
{
        string name;
        Args args;
        Oexpr() {}

        friend Pstream & operator>>
        (Pstream & is, Oexpr & e) { e.load(is); return is; }
        friend std::ostream & operator<<
        (std::ostream & os, const Oexpr & s) { s.out(os); return os; }

        vstr getVars() const;
        void chVar(string nv, string ov);

    private:
        void load(Pstream & is);
        void out(std::ostream & os) const;
};

struct Iexpr
{
        enum Typ { NUL, MOD, EXP } typ = NUL;
        Node * node = nullptr;
        Args args;
        string modname;
        bool expectblock = false;

        Iexpr() {}

        friend Pstream & operator>>
        (Pstream & is, Iexpr & e) { e.load(is); return is; }
        friend std::ostream & operator<<
        (std::ostream & os, const Iexpr & s) {s.out(os); return os;}

        vstr getVars() const;
        void chVar(string nv, string ov) { if (typ == EXP) node->chVar(nv, ov); }
        bool isConst(string * v) const { return node && node->isConst(v); }
        bool isVar(string * v) const;
        void simplify(const std::map<string, string> & m);

        template<typename Visitor, typename Vx> Vx eval(Visitor &) const;

    private:
        void load(Pstream & is);
        void out(std::ostream & os) const;
};


