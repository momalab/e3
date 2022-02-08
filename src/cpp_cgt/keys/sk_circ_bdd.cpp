// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>
#include <vector>

#include "olc.h"
#include "bbs.h"
#include "crcl.h"
#include "bdda.h"
#include "timer.h"

#include "cfgnames.h"
#include "secnames.h"

#include "e3util.h"
#include "sk_circ_bdd.h"
#include "os_filesys.h"

using std::vector;
using std::string;
using std::cout;
using namespace e3::cr;
using ol::vstr;

const bool VREN = false; // use BDD var renaming
const bool BDDREORDER = true;
const int BDDNTRY = 20;

// this flag used for debug and must be the same as in circuit.bdd.cpp
const bool NameBit_useHex = true;

extern const char * g_platname; // declaration outside namespace; used in save

namespace e3
{

CircuitPrivKey_bdd::CircuitPrivKey_bdd
(KeyName name, std::string seed,
 int lam,
 std::string form, std::string comp, std::string kern)
    : CircuitPrivKey(name, seed, lam), formula(form), compile(comp), kernel(kern)
{
    if ( formula.empty() )
    {
        formula = default_formula();
        std::cout << "Warning: formula is not defined for " << name.typ << ", using " << formula << '\n';
    }

    if ( kernel.empty() )
    {
        kernel = default_kernel();
        std::cout << "Warning: kernel is not defined for " << name.typ << ", using " << kernel << '\n';
    }
}

CircuitPrivKey_bddn::CircuitPrivKey_bddn
(KeyName name, bool forceGen, bool forceLoad,
 std::string seed, int lam, std::string form,
 std::string comp, std::string kern, bool mx)
    : CircuitPrivKey_bdd(name, seed, lam, form, comp, kern),
      modifier_xor(mx)
{
    init_final(forceGen, forceLoad);
}

CircuitPrivKey_bdda::CircuitPrivKey_bdda
(KeyName name, bool forceGen, bool forceLoad,
 std::string seed, int lam, std::string form,
 std::string comp, std::string kern, bool mn)
    : CircuitPrivKey_bdd(name, seed, lam, form, comp, kern),
      modifier_not(mn)
{
    init_final(forceGen, forceLoad);
}

CircuitPrivKey_bddf::CircuitPrivKey_bddf
(KeyName name, bool forceGen, bool forceLoad,
 std::string seed, int lam, std::string form,
 std::string comp, std::string kern, bool mm)
    : CircuitPrivKey_bdd(name, seed, lam, form, comp, kern),
      modifier_mux(mm)
{
    init_final(forceGen, forceLoad);
}

void CircuitPrivKey_bdd::gen_cir2c(string fn, bool ren)
{
    e3::cr::Module mod(fn);

    std::cout << fn << " clear vars: " << std::flush;
    mod.cleanVars();
    std::cout << "ok, " << std::flush;;

    if (ren)
    {
        std::cout << "rename vars: " << std::flush;
        mod.replaceAllVars();
        std::cout << "ok, " << std::flush;;
    }

    std::cout << "write c: " << std::flush;
    std::ofstream of(fn + ".c");
    mod.outc_arr(of);
    std::cout << "ok\n";
}

void CircuitPrivKey_bdd::gen_init(string & tid, string & dir)
{
    if (!cudd_impl())
    {
        cout << "\nWarning: Cudd library is not linked in\n";
        cout << "Warning: Encryption will not be secure!!!\n\n";
    }

    if ( formula.empty() ) nevers("Bad formula");
    if ( lambda < 3 ) throw "Lambda cannot be <3 for BDD encryption";

    static int tid_cntr = 0;
    tid = ol::tos(std::time(0) - 10000 * (tid_cntr++) );

    string xid = "x." + tid;
    ///os::makeDir(xid);
    fs::create_directories(xid);
    dir = xid + '/';
}

void CircuitPrivKey_bdd::gen_bbs(e3::cr::Bbs & bbs, string dir, bool hash)
{
    auto sz = lambda;
    string name = "encdec.bbs";
    string form = formula;

    if ( hash )
    {
        sz *= 2;
        name = "hash.bbs";
        form = "L";
    }

    ol::ostr os;
    os << "BBS#\n" << sz << " 0 " << form << '\n';
    ol::istr in(os.str());
    bbs.init(in, false, rnd);

    bbs.generate();
    bbs.save(std::ofstream(dir + name));
}

void CircuitPrivKey_bdd::gen_enc(Bbs & bbs, string dir, string & encfn, string & decfn)
{
    string enc, dec;
    {
        ol::ostr odec, oenc;
        bbs.cir(odec, oenc);
        enc = oenc.str();
        dec = odec.str();
    }

    decfn = dir + "dec";
    encfn = dir + "enc";
    ol::str2file(encfn, enc);
    ol::str2file(decfn, dec);

    // copy kernel
    auto kername = cfgNames::circleDir1 + cfgNames::kerdir + kernel;
    auto ker = ol::file2str(kername, true);
    if (ker.empty()) throw "Kernel '" + kernel + "' does not exist (" + kername + ")";
    ol::replaceAll(ker, secNames::R_lambda, ol::tos(lambda));

    bool needBbsHash = ol::replaceAll(ker, secNames::R_bbshash, "bbshash");
    ol::str2file(dir + cfgNames::kername, ker);

    if ( !needBbsHash ) return; // done

    // generate hash
    Bbs hash;
    gen_bbs(hash, dir, true);

    string henc, hdec;
    {
        ol::ostr odec, oenc;
        hash.cir(odec, oenc);
        henc = oenc.str();
        //hdec = odec.str();
    }

    string hashfn = dir + "bbshash";
    ol::str2file(hashfn, henc);
}


void CircuitPrivKey_bdd::gen_op(string opn, string pfx, string decfn,
                                string encfn, string & opfn, string & bddfn)
{
    string op = ol::file2str(opn);
    ol::replaceAll(op, secNames::R_lambda, ol::tos(lambda));
    ol::replaceAll(op, secNames::R_dec, decfn);
    ol::replaceAll(op, secNames::R_enc, encfn);

    opfn = hg_name(pfx);
    ol::str2file(opfn, op);

    bddfn = bd_name(pfx);

    {
        Timer tmr;
        std::cout << "cgt: process BDD [" << bddfn << "] .. " << std::flush;
        Module mod(opfn);

        if (cudd_impl())
            writeBDD(bddfn, mod, false, BDDREORDER);
        else
        {
            std::ofstream of(bddfn);
            of << mod;
        }

        std::cout << " " << ((tmr.get() + 500) / 1000) << "s\n";
    }
}

void CircuitPrivKey_bddf::trygen()
{
    std::cout << "cgt: generating BDDF keys\n";
    string tid;
    gen_init(tid, xdir);

    Bbs bbs;
    gen_bbs(bbs, xdir, false);

    string decfn, encfn;
    gen_enc(bbs, xdir, decfn, encfn);

    string opfn_nand, bddfn_nand;
    gen_op(cfgNames::op_nand, "nand", decfn, encfn, opfn_nand, bddfn_nand);

    string opfn_and, bddfn_and;
    gen_op(cfgNames::op_and, "and", decfn, encfn, opfn_and, bddfn_and);

    string opfn_xor, bddfn_xor;
    gen_op(cfgNames::op_xor_ker, "xor", decfn, encfn, opfn_xor, bddfn_xor);

    string opfn_not, bddfn_not;
    gen_op(cfgNames::op_not_ker, "not", decfn, encfn, opfn_not, bddfn_not);

    string opfn_or, bddfn_or;
    gen_op(cfgNames::op_or, "or", decfn, encfn, opfn_or, bddfn_or);

    string opfn_xnor, bddfn_xnor;
    gen_op(cfgNames::op_xnor, "xnor", decfn, encfn, opfn_xnor, bddfn_xnor);

    string opfn_nor, bddfn_nor;
    gen_op(cfgNames::op_nor, "nor", decfn, encfn, opfn_nor, bddfn_nor);

    if (modifier_mux)
    {
        string opfn_mux, bddfn_mux;
        gen_op(cfgNames::op_mux, "mux", decfn, encfn, opfn_mux, bddfn_mux);
        gen_cir2c(bddfn_mux, VREN);
    }

    gen_cir2c(decfn, true);
    gen_cir2c(encfn, true);

    gen_cir2c(bddfn_and, VREN);
    gen_cir2c(bddfn_xor, VREN);
    gen_cir2c(bddfn_not, VREN);
    gen_cir2c(bddfn_or, VREN);
    gen_cir2c(bddfn_nand, VREN);
    gen_cir2c(bddfn_xnor, VREN);
    gen_cir2c(bddfn_nor, VREN);

    key = tid;

    std::cout << "cgt: generating BDDF keys .. done\n";
}

bool CircuitPrivKey_bddf::checkio() const
{
    std::cout << "cgt: check key " << key << "\n";

    if ( !checkbdd("not") ) return false;
    if ( !checkbdd("nand") ) return false;
    if ( !checkbdd("xnor") ) return false;
    if ( !checkbdd("nor") ) return false;
    if ( !checkbdd("and") ) return false;
    if ( !checkbdd("xor") ) return false;
    if ( !checkbdd("or") ) return false;
    if (modifier_mux)
    {
        if ( !checkbdd("mux") ) return false;
    }

    return true;
}

void CircuitPrivKey_bdda::trygen()
{
    std::cout << "cgt: generating BDDA keys\n";
    string tid;
    gen_init(tid, xdir);

    Bbs bbs;
    gen_bbs(bbs, xdir, false);

    string decfn, encfn;
    gen_enc(bbs, xdir, decfn, encfn);

    gen_cir2c(decfn, true);
    gen_cir2c(encfn, true);

    // op_not.ker
    string opfn_not, bddfn_not;
    gen_op(cfgNames::op_not_ker, "not", decfn, encfn, opfn_not, bddfn_not);
    gen_cir2c(bddfn_not, VREN);

    if (modifier_not)
    {
        string opfn_nand, bddfn_nand;
        gen_op(cfgNames::op_nand, "nand", decfn, encfn, opfn_nand, bddfn_nand);

        string opfn_xnor, bddfn_xnor;
        gen_op(cfgNames::op_xnor, "xnor", decfn, encfn, opfn_xnor, bddfn_xnor);

        string opfn_nor, bddfn_nor;
        gen_op(cfgNames::op_nor, "nor", decfn, encfn, opfn_nor, bddfn_nor);

        gen_cir2c(bddfn_nand, VREN);
        gen_cir2c(bddfn_xnor, VREN);
        gen_cir2c(bddfn_nor, VREN);
    }
    else
    {
        string opfn_and, bddfn_and;
        gen_op(cfgNames::op_and, "and", decfn, encfn, opfn_and, bddfn_and);

        string opfn_xor, bddfn_xor;
        gen_op(cfgNames::op_xor_ker, "xor", decfn, encfn, opfn_xor, bddfn_xor);

        string opfn_or, bddfn_or;
        gen_op(cfgNames::op_or, "or", decfn, encfn, opfn_or, bddfn_or);

        gen_cir2c(bddfn_and, VREN);
        gen_cir2c(bddfn_xor, VREN);
        gen_cir2c(bddfn_or, VREN);
    }

    key = tid;

    std::cout << "cgt: generating BDDA keys .. done\n";
}

bool CircuitPrivKey_bdda::checkio() const
{
    std::cout << "cgt: check key " << key << "\n";
    if ( !checkbdd("not") ) return false;
    if (modifier_not)
    {
        if ( !checkbdd("nand") ) return false;
        if ( !checkbdd("xnor") ) return false;
        if ( !checkbdd("nor") ) return false;
    }
    else
    {
        if ( !checkbdd("and") ) return false;
        if ( !checkbdd("xor") ) return false;
        if ( !checkbdd("or") ) return false;
    }

    return true;
}

void CircuitPrivKey_bddn::trygen()
{
    std::cout << "cgt: generating BDDN keys\n";
    string tid;
    gen_init(tid, xdir);

    Bbs bbs;
    gen_bbs(bbs, xdir, false);

    string decfn, encfn;
    gen_enc(bbs, xdir, decfn, encfn);

    gen_cir2c(decfn, true);
    gen_cir2c(encfn, true);

    string opfn_nand, bddfn_nand;
    gen_op(cfgNames::op_nand, "nand", decfn, encfn, opfn_nand, bddfn_nand);

    string opfn_not, bddfn_not;
    if ( modifier_xor )
    {
        gen_op(cfgNames::op_not_nok, "not", decfn, encfn, opfn_not, bddfn_not);

        string opfn_xor, bddfn_xor;
        gen_op(cfgNames::op_xor_nok, "xor", decfn, encfn, opfn_xor, bddfn_xor);

        gen_cir2c(bddfn_xor, VREN);
    }
    else
    {
        gen_op(cfgNames::op_not_nand, "not", decfn, encfn, opfn_not, bddfn_not);
    }

    gen_cir2c(bddfn_nand, VREN);
    gen_cir2c(bddfn_not, VREN);

    key = tid;

    std::cout << "cgt: generating BDDN keys .. done\n";
}

bool CircuitPrivKey_bddn::checkio() const
{
    std::cout << "cgt: check key " << key << "\n";
    if ( !checkbdd("nand") ) return false;
    if ( !checkbdd("not") ) return false;
    if (modifier_xor)
    {
        if ( !checkbdd("xor") ) return false;
    }
    return true;
}

string CircuitPrivKey_bdd::filename() const { return PrivKey::filename(); }
string CircuitPrivKey_bdd::filecpp() const { return filename() + ".cpp"; }
string CircuitPrivKey_bdd::fileexe() const { return filename() + ".exe"; }

void CircuitPrivKey_bdd::save()
{
    string cpp = ol::file2str(cfgNames::bddmain);
    ol::replaceAll(cpp, secNames::R_lambda, ol::tos(lambda));
    ol::replaceAll(cpp, secNames::R_tid, key);

    {
        std::ofstream in(filecpp(), std::ios::binary);
        in << "// " << key << ' ' << lambda << '\n';
        in << cpp;
    }

    ///os::rmFile(fileexe());
    fs::remove(fileexe());

    // try compilation
    if ( !compile.empty() )
    {
        vstr v = ol::str2vstr(compile, "][");
        for ( auto x : v )
        {
            x = ol::eatSpaces(x);
            vstr vx = ol::str2vstr(x, " ");
            if ( vx.size() < 3 || vx[1] != ":" ) throw "Bad compile format";
            if ( vx[0] != g_platname ) continue;
            string cmd = vx[2];
            for ( size_t i = 3; i < vx.size(); i++ ) cmd += " " + vx[i];
            ol::replaceAll(cmd, "$", filename());
            std::cout << "cgt: compiling [" << cmd << "]\n";
            string out = ol::eatSpaces(os::execOut(cmd, false));
            std::cout << "cgt: compiler says: [" << out << "]\n";
        }
    }
}

bool CircuitPrivKey_bdd::load()
{
    std::ifstream in(filecpp(), std::ios::binary);
    if ( !in ) return false;
    string x;
    int lam = -1;
    in >> x >> key >> lam;

    if ( lambda == 0 )
    {
        lambda = lam;
        //std::cout << "Warning: using lambda=" << lambda
        //          << " from the loaded key: " << name << '\n';
    }
    else if ( lam != lambda )
        throw "Mismatch betweem lambdas, check cfg ["
        + ol::tos(lambda) + "] and key [" + ol::tos(lam) + "]";

    return true;
}

std::string CircuitPrivKey_bdd::encbitstr(vector<bool> v) const
{
    auto b = v[0];
    string exe = fileexe();
    ///if ( !os::isFile(exe) )
    if ( !fs::is_regular_file(exe) )
        throw "No private key executable [" + exe + "] found";

    string inp;
    inp = b ? "1" : "0";
    for ( int i = 1; i < lambda; i++ ) inp += ((*rnd)() % 2) ? "1" : "0";
    string cmd = exe + " enc " + inp;
    string out = ol::eatSpaces(os::execOut(cmd, true));

    if ( (int)out.size() != lambda )
        throw "Bad response size from encryption exec [" + out + "]";

    std::vector<bool> vb(out.size());
    for ( int i = 0; i < lambda; i++ ) vb[i] = (out[i] != '0');
    return NameBit_useHex ? e3::util::bin2hex(vb) : e3::util::bin2sbn(vb);
}

vector<bool> CircuitPrivKey_bdd::decbitstr(const std::string & as, bool * ok) const
{
    if (ok) *ok = false;

    auto vb = NameBit_useHex
              ? e3::util::hex2bin(as, lambda) : e3::util::sbn2bin(as, lambda);

    if (vb.empty()) return vector<bool>(1, false);

    string inp;
    for ( int i = 0; i < lambda; i++ ) inp += '0' + char(vb[i]);

    string exe = fileexe();
    ///if ( !os::isFile(exe) )
    if ( !fs::is_regular_file(exe) )
        throw "No private key executable [" + exe + "] found";

    string cmd = exe + " dec " + inp;
    string out = ol::eatSpaces(os::execOut(cmd, true));

    if ( (int)out.size() != lambda )
        throw "Bad response size from encryption exec [" + out + "]";

    if (ok) *ok = true;
    return vector<bool>(1, (out[0] != '0') );
}

void CircuitPrivKey_bdd::gen()
{
    for ( int ntry = 1; ntry < BDDNTRY; ntry++ )
    {
        trygen();
        if ( checkio() ) return;
        std::cout << "(" << ntry << ") key gen failed, next try\n";
    }

    throw "Cannot BDD process, D/E/H too simple";
}

bool CircuitPrivKey_bdd::checkbdd(string name) const
{
    auto hgn = hg_name(name);
    auto bdn = bd_name(name);

    Module mod(hgn), bdd(bdn);

    if ( bdd.input_size() == mod.input_size() &&
            bdd.output_size() == mod.output_size() ) return true;

    std::cout <<  "BDD io: " << bdd.input_size() << ' ' << bdd.output_size()
              << " HG io: " << mod.input_size() << ' ' << mod.output_size() << '\n';

    return false;
}

} // e3
