#include <string>

#include "palisade.h"

using std::string;



namespace e3
{

namespace pali
{

using Pt = lbcrypto::Plaintext;
using Ct = lbcrypto::Ciphertext<lbcrypto::DCRTPoly>;
using Cc = lbcrypto::CryptoContext<lbcrypto::DCRTPoly>;
using Keys = lbcrypto::LPKeyPair<lbcrypto::DCRTPoly>;
using PubKey = lbcrypto::LPPublicKey<lbcrypto::DCRTPoly>;
using SecKey = lbcrypto::LPPrivateKey<lbcrypto::DCRTPoly>;
using vi64 = const std::vector<int64_t>;


Cc make_context(int plaintextModulus, uint32_t depth, int lambda);

void save_context(Cc & cc, string file);
Cc load_context(string file);

Keys gen_keys(Cc & cc);

void save_pub_main(PubKey & pubKey, string file);
void save_priv(SecKey & k, string file);
void save_pub_eval(Cc & cc, string file);

SecKey load_priv(string file);
void load_pub_eval(Cc & cc, string file);

PubKey load_pub_main(string file);

Ct encrypt(Cc & cc, PubKey & pubKey, const vi64 & v);
Pt decrypt_pt(Cc & cc, SecKey & pubKey, Ct & ct);
template <class T> T decrypt(Cc & cc, SecKey & pubKey, Ct & ct, int sz);

void save_ct(Ct & ct, string f);
Ct load_ct(string f);

string ct2str(Ct & ct);
Ct str2ct(const string & s);

} // pali
} // e3
