#pragma once

#include <string>

namespace e3
{

// There are 3 names used in the code
// 1. Decoration name (= name of the type) [KeyName::typ]
// 2. Encryption file name - name of the key [KeyName::fil]
// 3. Encryption type name - postfix for the Key class (~=cfg encryption) [clsenc]
struct KeyName
{
    std::string typ, fil;
};

class AnyKey
{
    public: // need modify access from both Eval and Priv keys
        // it's possible to avoid public, but simplicity rules
        KeyName name;
        ///std::string decorname;

        ///private:
        // utility function for decor
        static std::string prefix(
            const std::string & s, bool add, std::string pfx);

    public:
        AnyKey(KeyName nm) : name(nm) {}

        virtual std::string filename() const = 0;

        std::string decor(const std::string & what, bool add) const;
};

} // e3
