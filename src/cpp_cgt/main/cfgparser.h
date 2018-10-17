#pragma once

#include <string>

#include "sectype.h"

using std::string;

struct ConfigParser
{
    string userdir;
    string password;
    bool isCloPassword = false;
    vector<SecType *> sectypes;

    ConfigParser(string file);

    ConfigParser(const ConfigParser &) = delete;
    ConfigParser & operator=(const ConfigParser &) = delete;

    ~ConfigParser();

    void makeSecint(string e3_lib) const;
    void makeDepend() const;

    void loadOrGenKeys(bool forceGen, bool forceLoad);

    void setCloPassword(string p) { password = p; isCloPassword = true; }
};
