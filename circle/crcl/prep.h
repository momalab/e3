// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_PREP_H_
#define _E3_PREP_H_

#include <map>

#include "olc.h"

namespace e3
{
namespace cr
{

class Preprocessor
{
        std::map<std::string, int> pcons;
        ol::vstr order;

        ol::vstr expand1line(std::string ln, bool * mdf);
        std::string expandNames(const std::string & ln);
        std::string expand1name(const std::string & ln);
        std::string apply(const std::string & ln);
        bool procConDef(const std::string & ln);
        ol::vstr include(std::string file);

    public:
        static std::string tokenize(const std::string & line);
        ol::vstr expand(const std::string & line);
};

}
} // e3::cr

#endif // _E3_PREP_H_
