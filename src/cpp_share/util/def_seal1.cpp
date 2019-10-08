#include <sstream>
#include <string>

#include "base64.h"
#include "def_seal1.h"

using namespace seal;
using std::string;

int e3::seal_impl() { return 1; }

std::string e3::SealNativeCiphertext::str(cSealNativeEvalKey ek) const
{
    std::ostringstream os;
    p->b.save(os);
    return e3util::base64::enc(os.str());
}

namespace e3
{

// void delete_nativebit(SealCiphertext * p)
// {
//     p->b.release();
// }

SealNativeCiphertext::SealNativeCiphertext(cSealNativeEvalKey ek)
{
    p = std::shared_ptr<SealCiphertext>(new SealCiphertext());
}

} // e3

e3::SealNativeCiphertext::SealNativeCiphertext(const SealNativeCiphertext & b, cSealNativeEvalKey ek) : SealNativeCiphertext(ek)
{
    p->b = b.p->b;
}

e3::SealNativeCiphertext::SealNativeCiphertext(const std::string & enc, cSealNativeEvalKey ek) : SealNativeCiphertext(ek)
{
    std::istringstream is(e3util::base64::dec(enc));
    try
    {
        auto context = e3seal::toek(ek)->context;
        p->b.load( context, is );
    }
    catch (...)
    {
        throw "Bad init in SealNativeCiphertext [" + enc + "]";
    }
}
