// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_PAIL_H_
#define _E3_EK_PAIL_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_mpir.h"

namespace e3
{

class PailEvalKey : public EvalKey
{
    protected:
        struct Processor
        {
            Bigun N, N2, B2, A2;
            int beta = 0, high_bit_posN = 0, high_bit_posN2 = 0;
            Bigun Xp1, Xp2;

            void setB2Beta(int beta);
            void init(Bigun n);
            string show() const;

            bool leq_x(const e3::Bigun & x) const { return (x < Xp1 || Xp2 < x); }
        };

        Processor proc;

    public:
        void setN(Bigun p, Bigun q) { setN(p * q); }
        void setN(Bigun aN) { proc.init(aN); }

        friend class PailEvalKeyExt;

    public:
        PailEvalKey(int) : EvalKey({"", ""}) {} // when used as a member in key class
        PailEvalKey(User u, KeyName name) : EvalKey(name) { user(u); }

        bool load(string fname);
        virtual bool load() { return load(filename()); }

        const Bigun & getN() const { return proc.N; }
        const Bigun & getN2() const { return proc.N2; }
        int getBeta() const { return proc.beta; }
        const Bigun & getB2() const { return proc.B2; }

        string show() const { return proc.show(); }
        void setBeta(int b) { proc.setB2Beta(b); }
        bool leq(Bigun a) { return proc.leq_x(a); }
};

} // e3

#endif // _E3_EK_PAIL_H_
