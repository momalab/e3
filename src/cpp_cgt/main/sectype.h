#pragma once

#include <map>
#include <set>

#include "olc.h"
#include "privkeys.h"
#include "cfgnames.h"

struct ConfigParser;
class Bridge;

class SecType
{
        static const size_t MAX_C_STR = 12000; // to break long literals

    protected:
        string tname, ename; // name of the type and name of the encryption key
        // these are the same, except when SecType is bridged, then ename is the
        // name of the bridge
        Bridge * bridge = nullptr;

        string postfixP;
        string postfixN;
        int plaintext_size = -1;
        int lambda;

        std::string encType;
        shared_ptr<PrivKey> sk;

        SecType(string n): tname(n), ename(n) {}
        using pss = std::pair<string, string>;
        bool readKeyVal(std::istream & is, pss & p, string end_word) const;

        struct Consts { std::set<string> pos, neg; };
        Consts find_constants(string dir) const;
        string makeDefines(const std::set<string> &, bool neg) const;
        string makeDefines(const Consts & c) const; // delegate

        void loadPairs(std::istream & is, std::map<string, string *> & kv);
        void globPairs(std::map<string, string *> & kv, const std::map<string, string> & globs);

        virtual void fixEncType() = 0;
        void make_bridge(const ConfigParser * par, int index);

    private:
        static string find_next_constant
        (const string & text, size_t & pos, const string & pfx);

    public:
        static SecType * load
        (std::istream & is, string name, string typ, const std::map<string, string> & globs);

        virtual ~SecType() = 0;

        PrivKey * get_sk_raw() const { return sk.get(); }
        shared_ptr<PrivKey> get_sk_shared() const { return sk; }

        string getTname() const { return tname; }
        string getEname() const { return ename; }
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
};

inline SecType::~SecType() {}


