#ifndef _E3_DEF_SEAL_H_
#define _E3_DEF_SEAL_H_

#include <string>
#include <memory>

struct SealCiphertext;

namespace e3
{

using SealNativePrivKey = void * ;
using SealNativeEvalKey = void * ;
using cSealNativeEvalKey = const void * ;

struct SealNativeCiphertext
{
    std::shared_ptr<SealCiphertext> p;
    std::string str() const;

    SealNativeCiphertext(); // new
    SealNativeCiphertext(const SealNativeCiphertext &); // = delete;
    SealNativeCiphertext(const std::string & enc, cSealNativeEvalKey ek);
};

int seal_impl(); // 0 or 1

} // e3

#endif // _E3_DEF_SEAL_H_
