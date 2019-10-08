#ifndef _E3_EK_PAIL_H_
#define _E3_EK_PAIL_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_mpir.h"

namespace e3
{

class PailEvalKey : public EvalKey
{
    public: // need for access from ekx classes
        Bigun N, N2;
        void initN2() { N2 = N * N; }
        void initN(Bigun p, Bigun q) { N = p * q; initN2(); }


    public:
        PailEvalKey(int) : EvalKey({"", ""}) {} // when used as a member in key class
        PailEvalKey(User u, KeyName name) : EvalKey(name) { user(u); }

        bool load(string fname);
        virtual bool load() { return load(filename()); }

};

} // e3
#endif // _E3_EK_PAIL_H_
