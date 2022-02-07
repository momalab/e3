// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_GRAM_H_
#define _E3_GRAM_H_

#include <map>

#include "olc.h"

#include "crutil.h"

namespace e3
{
namespace cr
{

struct Node
{
    static Node * newnode(Pstream & is);
    virtual std::string str() const = 0;
    virtual ol::vstr getVars() const = 0;
    virtual void chVar(std::string nv, std::string ov) = 0;
    virtual bool isConst(std::string * v) const = 0;

    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    using mss = std::map<std::string, std::string>;
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
    std::string name; // can be 0 or 1

    Prim() : neg(false), expr(nullptr) {}
    Prim(std::string n) : neg(false), expr(nullptr), name(n) {}

    static Node * load(Pstream & is);
    virtual std::string str() const;
    virtual ol::vstr getVars() const;
    virtual void chVar(std::string nv, std::string ov);
    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;

    static bool isConst(std::string s) { return (s == "0" || s == "1"); }
    bool isConst(std::string * s) const;
    virtual void simplify(Node ** p, const mss & m);
};

struct Term : Node
{
    std::vector<Node *> prims;
    static Node * load(Pstream & is);
    virtual std::string str() const;
    virtual ol::vstr getVars() const;

    virtual void chVar(std::string nv, std::string ov)
    { for (auto & x : prims) x->chVar(nv, ov); }

    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    bool isConst(std::string * s) const { return false; }
    virtual void simplify(Node ** p, const mss & m);
};

struct Xorm : Node
{
    std::vector<Node *> terms;
    static Node * load(Pstream & is);
    virtual std::string str() const;
    virtual ol::vstr getVars() const;

    virtual void chVar(std::string nv, std::string ov)
    { for (auto & x : terms) x->chVar(nv, ov); }

    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    bool isConst(std::string * s) const { return false; }
    virtual void simplify(Node ** p, const mss & m);
};

struct Expr : Node
{
    std::vector<Node *> xorms;
    static Node * load(Pstream & is);
    virtual std::string str() const;
    virtual ol::vstr getVars() const;

    virtual void chVar(std::string nv, std::string ov)
    { for (auto & x : xorms) x->chVar(nv, ov); }

    template<typename Visitor, typename Vx> Vx eval(Visitor &) const;
    bool isConst(std::string * s) const { return false; }
    virtual void simplify(Node ** p, const mss & m);
};

struct Args
{
        ol::vstr names;
        Args() {}

        friend Pstream & operator>>
        (Pstream & is, Args & e) { e.load(is); return is; }

        friend std::ostream & operator<<
        (std::ostream & os, const Args & s) { s.out(os); return os; }

        ol::vstr getVars() const;
        void chVar(std::string nv, std::string ov);

    private:
        void load(Pstream & is);
        void out(std::ostream & os) const;
};

struct Oexpr
{
        std::string name;
        Args args;
        Oexpr() {}

        friend Pstream & operator>>
        (Pstream & is, Oexpr & e) { e.load(is); return is; }
        friend std::ostream & operator<<
        (std::ostream & os, const Oexpr & s) { s.out(os); return os; }

        ol::vstr getVars() const;
        void chVar(std::string nv, std::string ov);

    private:
        void load(Pstream & is);
        void out(std::ostream & os) const;
};

struct Iexpr
{
        enum class Typ { NUL, MOD, EXP } typ = Typ::NUL;
        Node * node = nullptr;
        Args args;
        std::string modname;
        bool expectblock = false;

        Iexpr() {}

        friend Pstream & operator>>
        (Pstream & is, Iexpr & e) { e.load(is); return is; }
        friend std::ostream & operator<<
        (std::ostream & os, const Iexpr & s) {s.out(os); return os;}

        ol::vstr getVars() const;

        void chVar(std::string nv, std::string ov)
        { if (typ == Typ::EXP) node->chVar(nv, ov); }

        bool isConst(std::string * v) const { return node && node->isConst(v); }
        bool isVar(std::string * v) const;
        void simplify(const std::map<std::string, std::string> & m);

        template<typename Visitor, typename Vx> Vx eval(Visitor &) const;

    private:
        void load(Pstream & is);
        void out(std::ostream & os) const;
};


}
} // e3::cr

#endif // _E3_GRAM_H_
