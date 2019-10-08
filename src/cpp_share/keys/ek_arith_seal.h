#ifndef _E3_EK_ARITH_SEAL_H_
#define _E3_EK_ARITH_SEAL_H_

#include "ek_abstract.h"
#include "e3util.h"
#include "def_seal.h"

namespace e3
{

using std::string;

class SealBasePrivKey;
class SealBaseEvalKey : public EvalKey
{
    private:
        static const bool NOCOUT = true;

    public:
        using Snek = SealNativeEvalKey;

    protected:
        Snek key;

    public:
        SealBaseEvalKey(int) : EvalKey({"", ""}) {} // when used as a member in key class
        SealBaseEvalKey(User u, KeyName name) : EvalKey(name) { user(u); }

        bool load(string fname);
        virtual bool load() { return load(filename()); }

        friend class SealBasePrivKey;
};

class SealEvalKey : public SealBaseEvalKey
{
    protected:

    public:
        SealEvalKey(User u, KeyName name) : SealBaseEvalKey(u, name) {}
};

} // e3
#endif // _E3_EK_ARITH_SEAL_H_
