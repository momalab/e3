// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// Circle - Circuit compiler - main
// Oleg Mazonka, 2018

//#define PRINT_DIR_ON_EXCEPTION 1

#ifdef _MSC_VER
#include <direct.h>
#endif

#include "crcl.h"
#include "bbs.h"
#include "main.h"
#include "ttbl.h"
#include "bdda.h"
#include "vars.h" // writeSimple
#include "simp.h"
#include "invar.h"
#include "prime.h"
#include "invert.h"

#include "using.h"

void docir(string opts, string file);
void dolbs(string opts, string file);
void dottf(string opts, string file);
void dover(string opts, string fil1, string fil2, string file_extra);
void help();


int main(int ac, char * av[])
try
{
    try
    {
        Module::PRN = true;
        if (ac < 2)
        {
            cout << LogoC;
            throw "no input file (use '-h' for help)";
        }

        if ( av[1][0] != '-' )
        {
            docir("s", av[1]);

            //docir("t", av[1]);
            //dottf("c", av[1]);
            return 0;
        }

        char c = av[1][1];
        if ( c == 'h' ) { help(); return 0; }

        if ( ac < 3 ) throw "file is required";

        if ( c == '\0' ) throw "bad option";
        else if ( c == 'c' ) docir(&av[1][2], av[2]);
        else if ( c == 'b' ) dolbs(&av[1][2], av[2]);
        else if ( c == 't' ) dottf(&av[1][2], av[2]);
        else if ( c == 'v' )
        {
            if (ac < 4) throw "-v requires 2 files";
            string extra;
            if (ac > 4) extra = av[4];
            dover(&av[1][2], av[2], av[3], extra);
        }
        else throw "Unexpected option [" + string(av[1]) + "]";

        return 0;
    }
    catch (...)
    {
#ifdef _MSC_VER
#ifdef PRINT_DIR_ON_EXCEPTION
        char b[1001]; _getcwd(b, 1000);
        cout << "Current directory: [" << b << "]\n";
#endif
#endif
        throw;
    }
}
catch (int e)
{
    cout << "Internal error: " << e << "\n";
    return 1;
}
catch (const char * e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (string e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Error: unknown exception\n";
    return 1;
}


void docir(string opts, string file)
{
    cout << "reading [" << file << "]\n";

    bool mdf = (opts.find('@') != string::npos);
    bool reo = true;

    if ( mdf && opts.find_first_of("bd") != string::npos )
    {
        mdf = false;
        reo = false;
    }

    Module prog(file, "", mdf);

    for ( auto c : opts )
    {
        if (c == '@') {}
        else if ( c == 's' )
        {
            cout << "\nSummary:\n";
            cout << prog.summary();
        }
        else if ( c == 'c' )
        {
            std::ofstream of(file + ".out");
            of << prog;
            cout << "circle written\n";
        }
        else if ( c == 'x' )
        {
            if (prog.reuse) throw "Reused vars - clean vars first";
            Invertor inv(prog);
            std::ofstream of(file + ".out");
            of << "# Inverter\n" << LogoF << '\n';
            inv.invert(of);
            cout << "circle written\n";
        }
        else if (c == 'g')
        {
            std::ofstream of(file + ".v");
            prog.verilog(of, mdf);
            cout << "Verilog written\n";
        }
        else if (c == 'l')
        {
            if (prog.reuse) throw "Reused vars - clean vars first";
            std::ofstream of(file + ".c");
            prog.outc_arr(of);
            cout << "C written\n";
        }
        else if ( c == 't' || c == 'a' )
        {
            writeTT(file + ".ttb", prog, c == 'a');
            //writeTT(file + ".ttb", prog, c == 'a', enforce_tbl_col);
            cout << "truth table written\n";
        }
        else if ( c == 'r' )
        {
            writePrime(file, prog);
            cout << "primals written\n";
        }
        else if ( c == 'b' || c == 'd' )
        {
            writeBDD(file + ".bdd", prog, c == 'd', reo);
            cout << "BDDed circle written\n";
        }
        else if (c == 'n')
        {
            std::ofstream of(file + ".out");
            prog.cleanVars();
            of << "# clean vars\n";
            of << prog;
            cout << "circle written\n";
        }
        else if (c == 'v')
        {
            if (prog.reuse) throw "Cannot replace on reused vars - clean vars first";
            std::ofstream of(file + ".out");
            prog.replaceAllVars();
            of << "# rename vars\n";
            of << prog;
            cout << "circle written\n";
        }
        else if (c == 'm') simplify(file + ".out", prog);
        else if (c == 'p' )
        {
            if (prog.reuse)
                throw "Cannot do progression with reused vars "
                "- clean vars first";

            writeProgTbl(file + ".out", prog);
            cout << "progression table written\n";
        }
        else if (c == 'i')
        {
            if (prog.reuse)
                throw "Cannot do invriant analysis with reused vars "
                "- clean vars first";

            findInvariants(file, file + ".ttb", file + ".out", prog, mdf);
            cout << "invariant file written\n";
        }
        else
            throw "Bad option [" + opts + "] : [" + c + "]";
    }
}

void dolbs(string opts, string file)
{
    bool kiss = (opts.find('@') != string::npos);
    if ( kiss ) Rnd::use = Rnd::Kiss;

    for ( auto c : opts )
    {
        if (c == '@') {}
        else if ( c == 'g' ) makeBbs(file);
        else if ( c == 'c' ) bbs2cir(file);
        else
            throw "Bad option [" + opts + "] : [" + c + "]";
    }
}

void dottf(string opts, string file)
{
    for ( auto c : opts )
    {
        if (0) {}
        else if ( c == 'c' )
        {
            std::ifstream in(file);
            if ( !in ) throw "Cannot open [" + file + "]";

            tt2Circle(in, file + ".cir");
            cout << "circle generated\n";
        }
        else
            throw "Bad option [" + opts + "] : [" + c + "]";
    }
}

void dover(string opts, string fil1, string fil2, string fex)
{
    bool kiss = (opts.find('@') != string::npos);
    if ( kiss ) Rnd::use = Rnd::Kiss;

    if ( opts.empty() ) opts = "s";

    for ( auto c : opts )
    {
        if (c == '@') {}
        else if ( c == 's' ) verify(fil1, fil2, false, fex, false);
        else if (c == 'r') verify(fil1, fil2, true, fex, false);
        else if (c == 'n') verify(fil1, fil2, true, fex, true);
        else
            throw "Bad option [" + opts + "] : [" + c + "]";
    }
}

void help()
{
    cout << LogoC;

    cout << "Usage: crcl [command] file(s)\n";
    cout << "Commands:\n";
    cout << "  -c\tread circle file\n";
    cout << "  -b\tread BBS file (Balanced Binary System)\n";
    cout << "  -t\tread truth table\n";
    cout << "  -v\tcompare two circles by evaluation\n";
    cout << "  -h\tprint help summary (this page)\n";
    cout << "Sub-commands for circle file (-c):\n";
    cout << "   c\toutput circle file\n";
    cout << "   b|d\toutput BDDed circle, d - other formats\n";
    cout << "   s\tprint summary\n";
    cout << "   n\tclean var reuse\n";
    cout << "   m\tsimplify (need clean vars)\n";
    cout << "   v\trename all vars\n";
    cout << "   g\toutput in Verilog syntax\n";
    cout << "   l\toutput in C syntax\n";
    cout << "   p\toutput progression table\n";
    cout << "   i\toutput invariant wires\n";
    cout << "   r\toutput gate circuit & wire matrix\n";
    cout << "   x\toutput inverted logic circuit\n";
    cout << "   @\t(modify) do not flatten / BDD no reorder / wire decl\n";
    cout << "   t\toutput text binary truth table (*)\n";
    cout << "   a\toutput arithmetic truth table (*)\n";
    cout << "   (*)\trecalculate if truth table file exists\n";
    cout << "Sub-commands for BBS (-b):\n";
    cout << "   g\tgenerate BBS file\n";
    cout << "   c\tconvert BBS into circle\n";
    cout << "   @\t(modifier) use inbuilt random generator\n";
    cout << "Sub-commands for truth table (-t):\n";
    cout << "   c\tgenerate circle\n";
    cout << "   a\tconvert to arithmetic\n";
    cout << "Sub-commands for comparing circles (-v) (*):\n";
    cout << "   r\trandom comparison\n";
    cout << "   s\tsequential comparison (default)\n";
    cout << "   n\tgenerate random inputs\n";
    cout << "   @\t(modifier) use inbuilt random generator\n";
    cout << "   (*)\tformat: file1 file2 [file3]\n";
    cout << "   \tfile3 - either table or seed-size file\n";
    cout << "Default: -cs\n";
}
