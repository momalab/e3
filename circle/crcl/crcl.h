// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_CRCL_H_
#define _E3_CRCL_H_

#include <map>
#include <set>
#include <utility>

#include "olc.h"

#include "gram.h"
#include "prep.h"

namespace e3
{
namespace cr
{

extern int g_instance_cntr;

struct Context
{
    std::string prefix;
    std::string file;

    static std::string cookfile(std::string oldfile, std::string name);
    static std::string cookprefix(std::string name, int cntr);

    std::string name(std::string s) const { return prefix + s; }
};

// Context is the global object holding household info
// of the currently processed module
// this is not thread safe and done only for simplicity
// in thread safe - all constructors should receive a pointer
// to this object, and there should not be the global one
extern Context context;

class Statement
{
        Oexpr oexpr;
        Iexpr iexpr;

        void out(std::ostream & os) const;
        static std::vector<Statement *> bind_ios(ol::vstr modins, ol::vstr args, bool inp);

    public:
        Statement(std::string line);
        static std::vector<Statement *> load(std::string line);
        friend std::ostream & operator<<
        (std::ostream & os, const Statement & s) { s.out(os); return os; }

        ol::vstr getOutVars() const { return oexpr.getVars(); }
        ol::vstr getInVars() const { return iexpr.getVars(); }
        void chVar(std::string nv, std::string ov, bool outonly);
        void simplify(const std::map<std::string, std::string> & m) { iexpr.simplify(m); }
        bool isConst(std::string * v) const { return iexpr.isConst(v); }
        bool isVar(std::string * v) const { return iexpr.isVar(v); }
        std::string getOutName() const;

        template<typename Visitor, typename Vx> Vx eval(Visitor &) const;

        void redirect(Statement * x) { std::swap(iexpr, x->iexpr); }
};

class Invertor;

class Module
{
        friend class Invertor;

        static const int MAXDEPTH = 40; // flatenning depth

        Preprocessor prep;
        std::vector<Statement *> statements;
        ol::vstr outputs, inputs;
        std::vector<ol::vstr> middles; // and their last usage

        int size() const { return (int)statements.size(); }
        void out(std::ostream & os) const;
        void outc_replaceVars();

        std::string filename;
        bool flat;

        int instance_cntr;

    public:
        static bool PRN;
        bool reuse;

    private:

        void load(std::istream & is);
        std::map<std::string, int> chkReuse() const;
        std::set<std::string> getAllVars() const;
        void initIOMs();
        static bool chkSameSz(const ol::vstr & io);
        int findStatement(std::string oname) const;
        int findLastUse(std::string mname) const;
        int findNofUse(std::string name) const;

        static std::string warnS(std::string z)
        {
            return ""; // no warning necessary after switched to human order
            std::string x = "Warning: $ names are not of the same size\n";
            ol::replaceAll(x, "$", z);
            return x;
        }
        static std::string warnI() { return warnS("input"); }
        static std::string warnO() { return warnS("output"); }

    public:

        Module(std::string file, std::string prefix = "", bool noflatten = false);
        friend std::ostream & operator<<
        (std::ostream & os, const Module & m) { m.out(os); return os; }
        void verilog(std::ostream & os, bool wire_decl); // non-const since change vars
        void outc_arr(std::ostream & os); // non-const since change vars
        void outc_arg(std::ostream & os); // non-const since change vars

        template<typename Visitor, typename Vx>
        std::vector<Vx> eval(Visitor &, const std::vector<Vx> &, bool threaded = false) const;
        // threaded option should not be used unless boolean operations
        // are too slow, e.g. an FHE library

        int input_size() const { return (int)inputs.size(); }
        int output_size() const { return (int)outputs.size(); }
        std::string name_inp(int i) const { return inputs[i]; }
        std::string name_out(int i) const { return outputs[i]; }
        ol::vstr inps() const { return inputs; }
        ol::vstr outs() const { return outputs; }

        std::string summary() const;
        void cleanVars();
        void replaceAllVars();
        void replaceVar(std::string nv, std::string ov);
        bool simplify();
        std::vector< std::map<std::string, bool> > progressTable() const;

        friend class Statement;
};

}
} // e3::cr

#endif // _E3_CRCL_H_
