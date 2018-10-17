#pragma once

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

bool isNegative(const std::string & hex, size_t bitsize);
char maskHex(char c, size_t bitsize);
char negation(char hex);
std::string negation(const std::string & hex, size_t bitsize);
char addDec(char dec1, char dec2, bool * carry = nullptr);
char addHex(char hex1, char hex2, bool * carry = nullptr);
std::string add(const std::string & dec, unsigned value);
std::string multiply(const std::string & dec, unsigned value);
std::string divide(const std::string & dec, unsigned div);
unsigned mod(const std::string & dec, unsigned div);
std::string increment(const std::string & hex, size_t bitsize);
std::string twosComplement(const std::string & hex, size_t bitsize);
std::string removeLeadingZeros(const std::string & s);
std::string bin2hex(const std::vector<bool> & bin);
std::vector<bool> hex2bin(const std::string & hex, size_t bitsize = 0);
unsigned hex2dec(char hex);
char hex2dec(char hex, bool * carry);
std::string hex2dec(const std::string & hex, size_t bitsize = 0, bool sign = false);
char dec2hex(unsigned dec);
std::string dec2hex(const std::string & dec, size_t bitsize);
std::string unsigned2signed(const std::string & dec, size_t bitsize);

std::string trim(const std::string &);

e3util::ull gen_plain(const std::string & seed);

bool isCpp(std::string filename);

} // util
