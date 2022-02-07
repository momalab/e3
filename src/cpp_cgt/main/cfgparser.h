// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_CFGPARSER_H_
#define _E3_CFGPARSER_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class SecType;
class Bridge;

struct ConfigParser
{
    string file;
    string userdir;
    string password;
    string maxconst;

    bool isCloPassword = false;
    vector<SecType *> sectypes;

    ConfigParser(string file);

    ConfigParser(const ConfigParser &) = delete;
    ConfigParser & operator=(const ConfigParser &) = delete;

    ~ConfigParser();

    void makeSecint(string cgtdir, string e3_lib) const;
    void makeDepend() const;
    void saveConsts() const;

    void loadOrGenKeys(bool forceGen, bool forceLoad);

    void setCloPassword(string p) { password = p; isCloPassword = true; }

    Bridge * getBridge(string name) const;
};
#endif // _E3_CFGPARSER_H_
