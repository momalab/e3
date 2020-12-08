#ifndef _E3_SK_PALI_H_
#define _E3_SK_PALI_H_

#include "sk_abstract.h"
#include "ekx_pali.h"
#include "e3util.h"

namespace e3
{

class CircuitPrivKey_palibfv;
class PaliBfvPrivKey : public PrivKey
{
        virtual void gen();

    private:
        ///PaliBfvNativePrivKey key;
        PaliBfvEvalKeyExt ek;
        PaliBfvNativePrivKey sk;

    protected:
        virtual bool load();
        virtual void save();
        std::vector<std::string> rawDecrypt(const std::string & s) const;

    public:
        PaliBfvPrivKey(KeyName name, bool forceGen,
                       bool forceLoad, std::string seed, int lam,
                       std::string polyDegree, std::string depth,
                       int useSlots, string maxdep, string sp_n);

        PaliBfvPrivKey(const PaliBfvPrivKey &) = default;
        PaliBfvPrivKey(const PaliBfvPrivKey & k, std::string nm)
            : PaliBfvPrivKey(k) { ek.name.typ = name.typ = nm; }

        virtual std::string decrypt(const std::string & s) const;

        virtual std::string encrypt(const std::string & s, int msz) const { return ek.encrypt(s, msz); }
        virtual std::string filename() const;

        friend class CircuitPrivKey_palibfv;
        size_t slots() { return ek.slots(); }
};

inline std::string PaliBfvPrivKey::decrypt(const std::string & s) const
{
    auto v = rawDecrypt( ek.decor(s, false) );
    std::string r = "";
    bool isTrailing = false;
    if ( v.size() > 1 )
    {
        if ( v.size() == 2 ) r += v[0] + "_" + v[1];
        else
        {
            auto lastValue = v.back();
            auto penultimate = v[ v.size() - 2 ];
            isTrailing = lastValue == penultimate;
            r += "_" + penultimate + "_" + lastValue;
            if ( isTrailing ) r += "...";
            for ( size_t i = v.size() - 3; i > 0; i-- )
            {
                if ( !isTrailing || v[i] != v.back() )
                {
                    r = "_" + v[i] + r;
                    isTrailing = false;
                }
            }
            isTrailing &= v[0] == lastValue;
        }
    }
    if ( isTrailing ) r = r.substr(1);
    else r = v[0] + r;
    return r;
}

} // e3
#endif // _E3_SK_PALI_H_
