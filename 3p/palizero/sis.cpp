// @file  simple-integers-serial.cpp - Simple example for BFVrns (integer
// arithmetic) with serialization.

#include "palisade.h"

// header files needed for serialization
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "pubkeylp-ser.h"
#include "scheme/bfvrns/bfvrns-ser.h"
#include "utils/serialize-binary.h"

using namespace lbcrypto;

const std::string DATAFOLDER = ".";

int main()
{
    // Sample Program: Step 1: Set CryptoContext

    // Set the main parameters
    int plaintextModulus = 65537;
    double sigma = 3.2;
    SecurityLevel securityLevel = HEStd_128_classic;
    uint32_t depth = 2;

    // Instantiate the crypto context
    CryptoContext<DCRTPoly> cryptoContext =
        CryptoContextFactory<DCRTPoly>::genCryptoContextBFVrns(
            plaintextModulus, securityLevel, sigma, 0, depth, 0, OPTIMIZED);

    // Enable features that you wish to use
    cryptoContext->Enable(ENCRYPTION);
    cryptoContext->Enable(SHE);

    std::cout << "\nThe cryptocontext has been generated." << std::endl;

    // Serialize cryptocontext
    if (!Serial::SerializeToFile(DATAFOLDER + "/cryptocontext.key", cryptoContext,
                                 SerType::BINARY))
    {
        std::cerr << "Error writing serialization of the crypto context to "
                  "cryptocontext.key"
                  << std::endl;
        return 1;
    }
    std::cout << "The cryptocontext has been serialized." << std::endl;

    // Deserialize the crypto context
    CryptoContext<DCRTPoly> cc;
    if (!Serial::DeserializeFromFile(DATAFOLDER + "/cryptocontext.key", cc,
                                     SerType::BINARY))
    {
        std::cerr << "I cannot read serialization from "
                  << DATAFOLDER + "/cryptocontext.key" << std::endl;
        return 1;
    }
    std::cout << "The cryptocontext has been deserialized." << std::endl;

    // Sample Program: Step 2: Key Generation

    // Initialize Public Key Containers
    LPKeyPair<DCRTPoly> keyPair;

    // Generate a public/private key pair
    keyPair = cc->KeyGen();

    std::cout << "The key pair has been generated." << std::endl;

    // Serialize the public key
    if (!Serial::SerializeToFile(DATAFOLDER + "/key-public.key",
                                 keyPair.publicKey, SerType::BINARY))
    {
        std::cerr << "Error writing serialization of public key to key-public.key"
                  << std::endl;
        return 1;
    }
    std::cout << "The public key has been serialized." << std::endl;

    // Serialize the secret key
    if (!Serial::SerializeToFile(DATAFOLDER + "/key-private.key",
                                 keyPair.secretKey, SerType::BINARY))
    {
        std::cerr << "Error writing serialization of private key to key-private.key"
                  << std::endl;
        return 1;
    }
    std::cout << "The secret key has been serialized." << std::endl;

    // Generate the relinearization key
    cc->EvalMultKeyGen(keyPair.secretKey);

    std::cout << "The eval mult keys have been generated." << std::endl;

    // Serialize the relinearization (evaluation) key for homomorphic
    // multiplication
    std::ofstream emkeyfile(DATAFOLDER + "/" + "key-eval-mult.key",
                            std::ios::out | std::ios::binary);
    if (emkeyfile.is_open())
    {
        if (cc->SerializeEvalMultKey(emkeyfile, SerType::BINARY) == false)
        {
            std::cerr << "Error writing serialization of the eval mult keys to "
                      "key-eval-mult.key"
                      << std::endl;
            return 1;
        }
        std::cout << "The eval mult keys have been serialized." << std::endl;

        emkeyfile.close();
    }
    else
    {
        std::cerr << "Error serializing eval mult keys" << std::endl;
        return 1;
    }

    // Generate the rotation evaluation keys
    cc->EvalAtIndexKeyGen(keyPair.secretKey, {1, 2, -1, -2});

    std::cout << "The rotation keys have been generated." << std::endl;

    // Serialize the rotation keyhs
    std::ofstream erkeyfile(DATAFOLDER + "/" + "key-eval-rot.key",
                            std::ios::out | std::ios::binary);
    if (erkeyfile.is_open())
    {
        if (cc->SerializeEvalAutomorphismKey(erkeyfile, SerType::BINARY) == false)
        {
            std::cerr << "Error writing serialization of the eval rotation keys to "
                      "key-eval-rot.key"
                      << std::endl;
            return 1;
        }
        std::cout << "The eval rotation keys have been serialized." << std::endl;

        erkeyfile.close();
    }
    else
    {
        std::cerr << "Error serializing eval rotation keys" << std::endl;
        return 1;
    }

    // Sample Program: Step 3: Encryption

    // First plaintext vector is encoded
    std::vector<int64_t> vectorOfInts1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Plaintext plaintext1 = cc->MakePackedPlaintext(vectorOfInts1);
    // Second plaintext vector is encoded
    std::vector<int64_t> vectorOfInts2 = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Plaintext plaintext2 = cc->MakePackedPlaintext(vectorOfInts2);
    // Third plaintext vector is encoded
    std::vector<int64_t> vectorOfInts3 = {1, 2, 5, 2, 5, 6, 7, 8, 9, 10, 11, 12};
    Plaintext plaintext3 = cc->MakePackedPlaintext(vectorOfInts3);

    std::cout << "Plaintext #1: " << plaintext1 << std::endl;
    std::cout << "Plaintext #2: " << plaintext2 << std::endl;
    std::cout << "Plaintext #3: " << plaintext3 << std::endl;

    LPPublicKey<DCRTPoly> pk;
    if (Serial::DeserializeFromFile(DATAFOLDER + "/key-public.key", pk,
                                    SerType::BINARY) == false)
    {
        std::cerr << "Could not read public key" << std::endl;
        return 1;
    }
    std::cout << "The public key has been deserialized." << std::endl;

    // The encoded vectors are encrypted
    auto ciphertext1 = cc->Encrypt(pk, plaintext1);
    auto ciphertext2 = cc->Encrypt(pk, plaintext2);
    auto ciphertext3 = cc->Encrypt(pk, plaintext3);

    std::cout << "The plaintexts have been encrypted." << std::endl;

    if (!Serial::SerializeToFile(DATAFOLDER + "/" + "ciphertext1.key",
                                 ciphertext1, SerType::BINARY))
    {
        std::cerr
                << "Error writing serialization of ciphertext 1 to ciphertext1.key"
                << std::endl;
        return 1;
    }
    std::cout << "The first ciphertext has been serialized." << std::endl;

    Ciphertext<DCRTPoly> ct1;
    if (Serial::DeserializeFromFile(DATAFOLDER + "/ciphertext1.key", ct1,
                                    SerType::BINARY) == false)
    {
        std::cerr << "Could not read the ciphertext" << std::endl;
        return 1;
    }
    std::cout << "The first ciphertext has been deserialized." << std::endl;

    // Sample Program: Step 4: Evaluation

    // Removing evaluation keys stored in the current cryptocontext
    // so we could load them from file
    cc->ClearEvalMultKeys();
    cc->ClearEvalAutomorphismKeys();

    std::ifstream emkeys(DATAFOLDER + "/key-eval-mult.key",
                         std::ios::in | std::ios::binary);
    if (!emkeys.is_open())
    {
        std::cerr << "I cannot read serialization from "
                  << DATAFOLDER + "/key-eval-mult.key" << std::endl;
        return 1;
    }
    if (cc->DeserializeEvalMultKey(emkeys, SerType::BINARY) == false)
    {
        std::cerr << "Could not deserialize the eval mult key file" << std::endl;
        return 1;
    }
    std::cout << "Deserialized the eval mult keys." << std::endl;

    std::ifstream erkeys(DATAFOLDER + "/key-eval-rot.key",
                         std::ios::in | std::ios::binary);
    if (!erkeys.is_open())
    {
        std::cerr << "I cannot read serialization from "
                  << DATAFOLDER + "/key-eval-rot.key" << std::endl;
        return 1;
    }
    if (cc->DeserializeEvalAutomorphismKey(erkeys, SerType::BINARY) == false)
    {
        std::cerr << "Could not deserialize the eval rotation key file"
                  << std::endl;
        return 1;
    }
    std::cout << "Deserialized the eval rotation keys." << std::endl;

    // Homomorphic additions
    auto ciphertextAdd12 = cc->EvalAdd(ct1, ciphertext2);
    auto ciphertextAddResult = cc->EvalAdd(ciphertextAdd12, ciphertext3);

    // Homomorphic multiplications
    auto ciphertextMul12 = cc->EvalMult(ct1, ciphertext2);
    auto ciphertextMultResult = cc->EvalMult(ciphertextMul12, ciphertext3);

    // Homomorphic rotations
    auto ciphertextRot1 = cc->EvalAtIndex(ct1, 1);
    auto ciphertextRot2 = cc->EvalAtIndex(ct1, 2);
    auto ciphertextRot3 = cc->EvalAtIndex(ct1, -1);
    auto ciphertextRot4 = cc->EvalAtIndex(ct1, -2);

    // Sample Program: Step 5: Decryption

    LPPrivateKey<DCRTPoly> sk;
    if (Serial::DeserializeFromFile(DATAFOLDER + "/key-private.key", sk,
                                    SerType::BINARY) == false)
    {
        std::cerr << "Could not read secret key" << std::endl;
        return 1;
    }
    std::cout << "The secret key has been deserialized." << std::endl;

    // Decrypt the result of additions
    Plaintext plaintextAddResult;
    cc->Decrypt(sk, ciphertextAddResult, &plaintextAddResult);

    // Decrypt the result of multiplications
    Plaintext plaintextMultResult;
    cc->Decrypt(sk, ciphertextMultResult, &plaintextMultResult);

    // Decrypt the result of rotations
    Plaintext plaintextRot1;
    cc->Decrypt(sk, ciphertextRot1, &plaintextRot1);
    Plaintext plaintextRot2;
    cc->Decrypt(sk, ciphertextRot2, &plaintextRot2);
    Plaintext plaintextRot3;
    cc->Decrypt(sk, ciphertextRot3, &plaintextRot3);
    Plaintext plaintextRot4;
    cc->Decrypt(sk, ciphertextRot4, &plaintextRot4);

    // Shows only the same number of elements as in the original plaintext vector
    // By default it will show all coefficients in the BFV-encoded polynomial
    plaintextRot1->SetLength(vectorOfInts1.size());
    plaintextRot2->SetLength(vectorOfInts1.size());
    plaintextRot3->SetLength(vectorOfInts1.size());
    plaintextRot4->SetLength(vectorOfInts1.size());

    // Output results
    std::cout << "\nResults of homomorphic computations" << std::endl;
    std::cout << "#1 + #2 + #3: " << plaintextAddResult << std::endl;
    std::cout << "#1 * #2 * #3: " << plaintextMultResult << std::endl;
    std::cout << "Left rotation of #1 by 1: " << plaintextRot1 << std::endl;
    std::cout << "Left rotation of #1 by 2: " << plaintextRot2 << std::endl;
    std::cout << "Right rotation of #1 by 1: " << plaintextRot3 << std::endl;
    std::cout << "Right rotation of #1 by 2: " << plaintextRot4 << std::endl;

    return 0;
}
