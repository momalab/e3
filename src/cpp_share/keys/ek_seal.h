#ifndef _E3_EK_SEAL_H_
#define _E3_EK_SEAL_H_

#include <string>

#include "ek_abstract.h"

namespace e3
{

using namespace std::string;
using namespace std::vector;

class SealEvalKey : public EvalKey
{
    public:
        SealEvalKey(KeyName name) : EvalKey(name) { }

        static std::vector<std::string> enc2bits(const std::string & e);
        static std::string bits2enc(const std::vector<std::string> & v);
};

} // e3
#endif // _E3_EK_SEAL_H_
