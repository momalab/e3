#pragma once

#include "olc.h"
///#include "crcl.h"

class Varman
{
    public:
        string input(int i) const { return "x" + ol::tos(i); }
        string output(int i) const { return "y" + ol::tos(i); }
        string middle(int i) const;

        string x(int i) const { return input(i); };
        string y(int i) const { return output(i); };
        string xy(bool f, int i) const { return f ? x(i) : y(i); };

        static void replaceNum(string & ln, const string & fr, int to);
};


