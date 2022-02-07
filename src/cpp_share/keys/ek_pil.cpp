// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>

#include "ek_pil.h"

using std::cout;

const e3::PilEvalValues * e3::PilArith::use = nullptr;

bool e3::PilBaseEvalKey::load(string fname)
{
    std::ifstream in(fname, std::ios::binary);
    if (!in) return false;
    std::string s;

    if ( kv.ver != 22 ) throw "e3::PilBaseEvalKey::load: version";
    in >> s; kv.N = Bigun(s);
    in >> s; kv.S = PilNum(Bigun(s));
    in >> s; kv.A = PilNum(Bigun(s));
    in >> s; kv.B = PilNum(Bigun(s));
    in >> s; kv.C = PilNum(Bigun(s));
    in >> s; kv.D = PilNum(Bigun(s));
    in >> s; kv.E = PilNum(Bigun(s));
    in >> s; kv.F = PilNum(Bigun(s));

    if (!in) return false;
    return true;
}


void e3::PilArith::safe()
{
    if ( use ) return;

    string e = "PilArith is not switched on";
    cout << e << '\n';
    throw e;
}

e3::PilPair e3::operator*(PilPair x, PilPair y)
{
    return {x.a * y.a + x.b * y.b * PilArith::u()->S, x.a * y.b + x.b * y.a};
}


e3::PilQuad e3::operator*(PilQuad a, PilQuad b)
{
    const bool PLAINTEXT = false;
    if (PLAINTEXT ) return {a.x * b.x, a.y * b.y};

    auto u11 = a.x * b.x;
    auto u22 = a.y * b.y;
    auto u12 = a.x * b.y + a.y * b.x;

    const auto & A = PilArith::u()->A;
    const auto & B = PilArith::u()->B;
    const auto & C = PilArith::u()->C;
    const auto & D = PilArith::u()->D;
    const auto & E = PilArith::u()->E;
    const auto & F = PilArith::u()->F;

    auto x = A * u11 + B * u22 + C * u12;
    auto y = D * u11 + E * u22 + F * u12;

    return {x, y};
}

