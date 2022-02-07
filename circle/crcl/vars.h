// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_VARS_H_
#define _E3_VARS_H_

#include "olc.h"

namespace e3
{
namespace cr
{

class Varman
{
    public:
        std::string input(int i) const { return "x" + ol::tos(i); }
        std::string output(int i) const { return "y" + ol::tos(i); }
        std::string middle(int i) const;

        std::string x(int i) const { return input(i); };
        std::string y(int i) const { return output(i); };
        std::string xy(bool f, int i) const { return f ? x(i) : y(i); };

        static void replaceNum(std::string & ln, const std::string & fr, int to);
};

}
} // e3::cr

#endif // _E3_VARS_H_
