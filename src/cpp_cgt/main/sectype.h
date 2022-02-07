// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SECTYPE_H_
#define _E3_SECTYPE_H_

#include <map>
#include <set>
#include <vector>

#include "olc.h"
#include "privkeys.h"
#include "cfgnames.h"

struct ConfigParser;
class Bridge;

class SecType
{
    protected:
        // these are the same, except when SecType is bridged, then ename is the
        // name of the bridge
        e3::KeyName name;
        Bridge * bridge = nullptr;

        string postfixP;
        string postfixN;
        int plaintext_size = -1;
        int lambda;
        int maxinline_size = 120; // about 1 line; -1 for unlimited

        std::string encType; // library e.g. Palisade
        std::string scheme; // ckks,bfv,bgv
        std::string clsname() const; // class name for the $Name type (see e3key.h)

        std::shared_ptr<e3::PrivKey> sk;

        mutable std::vector<std::string> fileConsts;

        SecType(string n): name({n, n}) {}

        using pss = std::pair<string, string>;
        bool readKeyVal(std::istream & is, pss & p, string end_word) const;

        struct Consts { std::set<string> pos, neg; };
        Consts find_constants(string dir) const;
        string makeDefines(const std::set<string> &, bool neg) const;
        string makeDefines(const Consts & c) const; // delegate

        void loadPairs(std::istream & is, std::map<string, string *> & kv);
        void globPairs(std::map<string, string *> & kv, const std::map<string, string> & globs);

        virtual void fixEncType() = 0;
        void makeBridge(const ConfigParser * par, int index);
        std::map<string, string *> stdParams();

        string longConstBit(const string & s) const;
        string longConstTyp(const string & s) const;

    private:
        static string find_next_constant
        (const string & text, size_t & pos, const string & pfx);

    protected:
        string loadDbTemplRep(string root, string fn) const;
        string loadDbTemplNorep(string root, string fn) const;
        string implVer() const;

    public:
        static SecType * load
        (std::istream & is, string name, string typ, const std::map<string, string> & globs);

        virtual ~SecType() = 0;

        e3::PrivKey * get_sk_raw() const { return sk.get(); }
        std::shared_ptr<e3::PrivKey> get_sk_shared() const { return sk; }

        e3::KeyName getName() const { return name; }
        string getTypName() const { return name.typ; }
        string getFilName() const { return name.fil; }
        string getEncType() const { return encType; }
        string encrypt(const std::string & s) const;
        string decrypt(const std::string & s) const;
        bool isLoaded() { return sk->isLoaded(); }
        void checkPostfixes(std::set<string> & postfixes);

        virtual void writeH(string root, std::ostream & os, string user_dir) const = 0;
        virtual void writeInc(string root, std::ostream & os) const = 0;
        virtual void writeCpp(string root, std::ostream & os) const = 0;
        virtual void copyDependencies() const = 0;

        virtual void genKeys(bool forceGen, bool forceLoad,
                             std::string seed, const ConfigParser * par) = 0;

        virtual Bridge * getBridge() { return nullptr; }
        virtual const Bridge * getBridge() const { return nullptr; }

        void setMaxConst(int x) { maxinline_size = x; }
        void saveConsts() const;
};

inline SecType::~SecType() {}


#endif // _E3_SECTYPE_H_
