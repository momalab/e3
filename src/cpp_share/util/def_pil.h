#ifndef _E3_DEF_PIL_H_
#define _E3_DEF_PIL_H_

#include <string>
#include <memory>

#include "def_mpir.h"

namespace e3
{

// operations are defined at eval key header (ek_circ_pil)
struct PilNum
{
    Bigun n;
    PilNum() {}
    PilNum(Bigun a): n(a) {}
    PilNum(unsigned long long a): n(a) {}
};

struct PilPair
{
    PilNum a, b;
    PilPair() {}
    PilPair(PilNum qa, PilNum qb): a(qa), b(qb) {}
};

struct PilQuad
{
    PilPair x, y;
    PilQuad() {}
    PilQuad(PilPair qa, PilPair qb): x(qa), y(qb) {}
    PilQuad(string s);
    string str() const;
};

} // e3


#endif // _E3_DEF_PIL_H_
