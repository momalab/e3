#pragma once

#include <istream>
#include <string>
#include <vector>
#include "e3util.h"

namespace util
{
bool isAlphaUnd(char c);
bool isAlnumUnd(char c);
bool isHex(char c);
bool isVarName(const std::string & name);
bool isNumber(const std::string & s);
bool isPositiveNumber(const std::string & s);
bool isHex(const std::string & s);

char addDec(char dec1, char dec2, bool * carry = nullptr);
std::string unsigned2signed(const std::string & dec, size_t bitsize);

std::string trim(const std::string &);

e3util::ull gen_plain(const std::string & seed);

bool isCpp(std::string filename);
std::string readVal(std::istream & is);

} // util
