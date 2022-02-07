// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_TTBL_H_
#define _E3_TTBL_H_

#include "olc.h"

#include "crcl.h"

namespace e3
{
namespace cr
{

void writeTT(std::string ofile, const Module & prog, bool arith);
void tt2Circle(std::istream & in, std::string file);
void verify(std::string fil1, std::string fil2, bool brnd, std::string extra, bool nonly);


class TableIterator
{
    public:
        using vvb = std::vector< std::vector<bool> >;

    private:
        int sz;
        ol::ull N, i;
        vvb * v;
    public:

        TableIterator(int z) : sz(z), N(1ull << sz), i(0), v(nullptr) {}
        void setvvb(vvb & x) { v = &x; N = x.size(); }

        bool bit(int idx) const;
        ol::ull size() const { return N; }
        ol::ull idx() const { return i; }
        void next() { ++i; }
        bool ok() { return i < N; }
};

struct ValTtbl // keep ODR
{
    bool bit;
    ValTtbl(bool a = false) : bit(a) {}
};

struct BitVisitorTtbl
{
    using Val = ValTtbl; // keep ODR
    Val Xor(const Val & a, const Val & b) { return Val { b.bit != a.bit }; }
    Val And(const Val & a, const Val & b) { return Val { b.bit && a.bit }; }
    Val Or(const Val & a, const Val & b) { return Val { b.bit || a.bit }; }
    Val Not(const Val & a) { return Val { !a.bit }; }

    std::map<std::string, Val> * m = nullptr;

    Val zr = false, un = true;
    const Val & zero() const { return zr; }
    const Val & unit() const { return un; }

    void(*callback)() = nullptr;
};

bool checkFmt(std::string file, std::istream & in);
void loadTT(std::istream & in, TableIterator::vvb & v, int sz, bool ari);

}
} // e3::cr

#endif // _E3_TTBL_H_
