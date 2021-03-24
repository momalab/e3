
#include <iostream>

#include "sis_fun.h"

using std::cout;

void begin()
{
    auto cc = e3::pali::make_context(65537, 2, 128);
    cout << "\nThe cryptocontext has been generated." << std::endl;

    cout << "GetRingDimension: " << cc->GetRingDimension() << '\n';

    e3::pali::save_context(cc, "z");
    std::cout << "The cryptocontext has been serialized." << std::endl;

    cc = e3::pali::load_context("z");
    std::cout << "The cryptocontext has been deserialized." << std::endl;

    auto keys = e3::pali::gen_keys(cc);
    std::cout << "Keys has been generated." << std::endl;

    //  LPPublicKey<Element> publicKey;
    //  LPPrivateKey<Element> secretKey;
    e3::pali::save_pub_main(keys.publicKey, "z");
    std::cout << "The public key has been serialized." << std::endl;

    e3::pali::save_priv(keys.secretKey, "z");
    std::cout << "The secret key has been serialized." << std::endl;

    e3::pali::save_pub_eval(cc, "z");
    std::cout << "The eval keys has been serialized." << std::endl;
}


void encryption()
{
    e3::pali::Cc cc = e3::pali::load_context("z");
    e3::pali::PubKey pk = e3::pali::load_pub_main("z");
    std::vector<int64_t> va {1, 2, 3}, vb {2, 3, 4};
    auto cta = e3::pali::encrypt(cc, pk, va);
    auto ctb = e3::pali::encrypt(cc, pk, vb);

    e3::pali::save_ct(cta, "z_a");
    e3::pali::save_ct(ctb, "z_b");
}

void evaluate()
{
    e3::pali::Cc cc = e3::pali::load_context("z");
    auto cta = e3::pali::load_ct("z_a");
    auto ctb = e3::pali::load_ct("z_b");

    auto ctadd = cc->EvalAdd(cta, ctb);
    auto ctmul = cc->EvalMult(ctadd, ctadd);
    auto ctrot = cc->EvalAtIndex(ctmul, 1);
    e3::pali::save_ct(ctrot, "z_res");
    e3::pali::save_ct(ctmul, "z_res");
}

void decryption()
{
    e3::pali::Cc cc = e3::pali::load_context("z");
    auto ct = e3::pali::load_ct("z_res");
    e3::pali::SecKey sk = e3::pali::load_priv("z");

    e3::pali::Pt pt = e3::pali::decrypt_pt(cc, sk, ct);
    pt->SetLength(5);


    std::cout << "\nResults of homomorphic computations" << std::endl;
    std::cout << pt << '\n';

    // test string serialize
    string sct = e3::pali::ct2str(ct);
    auto cty = e3::pali::str2ct(sct);

    e3::pali::vi64 x = e3::pali::decrypt<e3::pali::vi64>(cc, sk, ct, 4);
    e3::pali::vi64 y = e3::pali::decrypt<e3::pali::vi64>(cc, sk, cty, 4);

    for ( auto i : x ) cout << ' ' << i; cout << '\n';
    for ( auto i : y ) cout << ' ' << i; cout << '\n';
}

int main()
try
{
    begin();
    encryption();
    evaluate();
    decryption();
}
catch (const char * e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (string e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "exception\n";
    return 1;
}
