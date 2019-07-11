#pragma once

#include <map>

#include "olc.h"

using namespace ol;

class Preprocessor
{
        std::map<string, int> pcons;
        vstr order;

        vstr expand1line(string ln, bool * mdf);
        string expandNames(const string & ln);
        string expand1name(const string & ln);
        string apply(const string & ln);
        bool procConDef(const string & ln);
        vstr include(string file);

    public:
        static string tokenize(const string & line);
        vstr expand(const string & line);
};

