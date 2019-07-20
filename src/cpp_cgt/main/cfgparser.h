#pragma once

#include <string>
#include <vector>

/// #include "sectype.h"

using std::string;
using std::vector;

class SecType;
class Bridge;

struct ConfigParser
{
    string file;
    string userdir;
    string password;
    bool isCloPassword = false;
    vector<SecType *> sectypes;

    ConfigParser(string file);

    ConfigParser(const ConfigParser &) = delete;
    ConfigParser & operator=(const ConfigParser &) = delete;

    ~ConfigParser();

    void makeSecint(string cgtdir, string e3_lib) const;
    void makeDepend() const;

    void loadOrGenKeys(bool forceGen, bool forceLoad);

    void setCloPassword(string p) { password = p; isCloPassword = true; }

    Bridge * getBridge(string name) const;
};
