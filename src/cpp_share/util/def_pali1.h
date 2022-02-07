// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_PALI1_H_
#define _E3_DEF_PALI1_H_

#include "def_pali.h"

#include "palisade.h"


namespace e3
{

// sis_fun types
namespace pali
{

using Elem = lbcrypto::DCRTPoly;

using Pt = lbcrypto::Plaintext;
using Ct = lbcrypto::Ciphertext<Elem>;
using Cc = lbcrypto::CryptoContext<Elem>;
using Keys = lbcrypto::LPKeyPair<Elem>;
using PubKey = lbcrypto::LPPublicKey<Elem>;
using SecKey = lbcrypto::LPPrivateKey<Elem>;
using vi64 = std::vector<int64_t>;

using CryParams = std::shared_ptr<lbcrypto::LPCryptoParameters<Elem>>;
using ParmType = std::shared_ptr<Elem::Params>;
using EncParams = lbcrypto::EncodingParams;
using IntType = typename Elem::Integer;

} // pali


struct PaliBfvCiphertext
{
    e3::pali::Ct ct;
};


// e3 conversions
namespace pali
{
inline  Cc * tocc(void * a) { return static_cast<Cc *>(a); }
inline  PubKey * topk(void * a) { return static_cast<PubKey *>(a); }
inline  SecKey * tosk(PaliBfvNativePrivKey a) { return static_cast<SecKey *>(a); }
} //pali



// sis_fun utility functions
namespace pali
{

Cc make_context(
    int plaintextModulus, uint32_t depth,
    int lambda, int maxDepth, uint32_t p_n);

void save_context(Cc & cc, string file);
Cc load_context(string file);

Keys gen_keys(Cc & cc);

void save_pub_main(PubKey & pubKey, string file);
void save_priv(SecKey & k, string file);
void save_pub_eval(Cc & cc, string file);

SecKey load_priv(string file);
void load_pub_eval(Cc & cc, string file);

PubKey load_pub_main(string file);
bool load_pub_possible(string file);

Ct encrypt(Cc & cc, PubKey & key, const vi64 & v);
Pt decrypt_pt(Cc & cc, SecKey & key, Ct & ct);
template <class T> T decrypt(Cc & cc, SecKey & key, Ct & ct, int sz);

void save_ct(Ct & ct, string f);
Ct load_ct(string f);

string ct2str(Ct & ct);
Ct str2ct(const string & s);
void str2ct(const string & s, Ct &);

void load_params(string file, int & polyDegree, int & muldepth,
                 int & useSlots, int & maxdepth, int & p_n);

void save_params(string file, int polyDegree, int muldepth,
                 int useSlots, int maxdepth, int p_n);


} // pali


} // e3

#endif // _E3_DEF_PALI1_H_
