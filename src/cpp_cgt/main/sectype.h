#pragma once

#include <map>
#include <set>

#include "ol.h"
#include "privkeys.h"
#include "cfgnames.h"

class SecType
{
        static const size_t MAX_C_STR = 12000; // to break long literals

    protected:
        string name;
        string postfixP;
        string postfixN;
        int plaintext_size = -1;

        shared_ptr<PrivKey> sk;

        SecType(string n): name(n) {}
        using pss = std::pair<string, string>;
        bool readKeyVal(std::istream & is, pss & p, string end_word) const;

        struct Consts { std::set<string> pos, neg; };
        Consts find_constants(string dir) const;
        string makeDefines(const std::set<string> &, bool neg) const;
        string makeDefines(const Consts & c) const; // delegate

        ///std::map<string, bool> find_constants(string dir) const;
        ///string makeDefines(const std::map<string, bool> &) const;

        void loadPairs(std::istream & is, std::map<string, string *> & kv);

    private:
        static string find_next_constant
        (const string & text, size_t & pos, const string & pfx);

    public:
        static SecType * load
        (std::istream & is, string name, string typ);

        virtual ~SecType() = 0;

        PrivKey * get_sk() const { return sk.get(); }
        std::string getName() const { return name; }
        std::string encrypt(const std::string & s) const;
        ///std::string decrypt(const std::string & s, bool * found) const;
        std::string decrypt(const std::string & s) const;
        bool isLoaded() { return sk->isLoaded(); }
        void checkPostfixes(std::set<string> & postfixes);

        virtual void writeH(std::ostream & os, string user_dir) const = 0;
        virtual void writeInc(std::ostream & os) const = 0;
        virtual void writeCpp(std::ostream & os) const = 0;
        virtual void copyDependencies() const = 0;

        virtual void genKeys(bool forceGen, bool forceLoad, std::string seed) = 0;
};

inline SecType::~SecType() {}


