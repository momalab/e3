#pragma once

#include <map>
#include <set>
#include <utility>

#include "olc.h"

#include "gram.h"
#include "prep.h"

using namespace ol;

extern int g_instance_cntr;

struct Context
{
    string prefix;
    string file;

    static string cookfile(string oldfile, string name);
    static string cookprefix(string name, int cntr);

    string name(string s) const { return prefix + s; }
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
        static vector<Statement *> bind_ios(vstr modins, vstr args, bool inp);

    public:
        Statement(string line);
        static vector<Statement *> load(string line);
        friend std::ostream & operator<<
        (std::ostream & os, const Statement & s) { s.out(os); return os; }

        vstr getOutVars() const { return oexpr.getVars(); }
        vstr getInVars() const { return iexpr.getVars(); }
        void chVar(string nv, string ov, bool outonly);
        void simplify(const std::map<string, string> & m) { iexpr.simplify(m); }
        bool isConst(string * v) const { return iexpr.isConst(v); }
        bool isVar(string * v) const { return iexpr.isVar(v); }
        string getOutName() const;

        template<typename Visitor, typename Vx> Vx eval(Visitor &) const;

        void redirect(Statement * x) { std::swap(iexpr, x->iexpr); }
};

class Invertor;

class Module
{
        friend class Invertor;

        static const int MAXDEPTH = 40; // flatenning depth

        Preprocessor prep;
        vector<Statement *> statements;
        vstr outputs, inputs;
        vector<vstr> middles; // and their last usage

        int size() const { return (int)statements.size(); }
        void out(std::ostream & os) const;
        void outc_replaceVars();

        string filename;
        bool flat;

        int instance_cntr;

    public:
        static bool PRN;
        bool reuse;

    private:

        void load(std::istream & is);
        std::map<string, int> chkReuse() const;
        std::set<string> getAllVars() const;
        void initIOMs();
        static bool chkSameSz(const vstr & io);
        int findStatement(string oname) const;
        int findLastUse(string mname) const;
        int findNofUse(string name) const;

        static string warnS(string z)
        {
            return ""; // no warning necessary after switched to human order
            string x = "Warning: $ names are not of the same size\n";
            replaceAll(x, "$", z);
            return x;
        }
        static string warnI() { return warnS("input"); }
        static string warnO() { return warnS("output"); }

    public:

        Module(string file, string prefix = "", bool noflatten = false);
        friend std::ostream & operator<<
        (std::ostream & os, const Module & m) { m.out(os); return os; }
        void verilog(std::ostream & os, bool wire_decl); // non-const since change vars
        void outc_arr(std::ostream & os); // non-const since change vars
        void outc_arg(std::ostream & os); // non-const since change vars

        template<typename Visitor, typename Vx>
        vector<Vx> eval(Visitor &, const vector<Vx> &, bool threaded = false) const;
        // threaded option should not be used unless boolean operations
        // are too slow, e.g. an FHE library

        int input_size() const { return (int)inputs.size(); }
        int output_size() const { return (int)outputs.size(); }
        string name_inp(int i) const { return inputs[i]; }
        string name_out(int i) const { return outputs[i]; }
        vstr inps() const { return inputs; }
        vstr outs() const { return outputs; }

        string summary() const;
        void cleanVars();
        void replaceAllVars();
        void replaceVar(string nv, string ov);
        bool simplify();
        vector< std::map<string, bool> > progressTable() const;

        friend class Statement;
};

