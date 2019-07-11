#include <iostream>

#include "e3int.h"
#include "timer.h"

using namespace std;

static const SecureUint<8> sbox[256] =
{
    //0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
    _0x63_E, _0x7c_E, _0x77_E, _0x7b_E, _0xf2_E, _0x6b_E, _0x6f_E, _0xc5_E, _0x30_E, _0x01_E, _0x67_E, _0x2b_E, _0xfe_E, _0xd7_E, _0xab_E, _0x76_E,
    _0xca_E, _0x82_E, _0xc9_E, _0x7d_E, _0xfa_E, _0x59_E, _0x47_E, _0xf0_E, _0xad_E, _0xd4_E, _0xa2_E, _0xaf_E, _0x9c_E, _0xa4_E, _0x72_E, _0xc0_E,
    _0xb7_E, _0xfd_E, _0x93_E, _0x26_E, _0x36_E, _0x3f_E, _0xf7_E, _0xcc_E, _0x34_E, _0xa5_E, _0xe5_E, _0xf1_E, _0x71_E, _0xd8_E, _0x31_E, _0x15_E,
    _0x04_E, _0xc7_E, _0x23_E, _0xc3_E, _0x18_E, _0x96_E, _0x05_E, _0x9a_E, _0x07_E, _0x12_E, _0x80_E, _0xe2_E, _0xeb_E, _0x27_E, _0xb2_E, _0x75_E,
    _0x09_E, _0x83_E, _0x2c_E, _0x1a_E, _0x1b_E, _0x6e_E, _0x5a_E, _0xa0_E, _0x52_E, _0x3b_E, _0xd6_E, _0xb3_E, _0x29_E, _0xe3_E, _0x2f_E, _0x84_E,
    _0x53_E, _0xd1_E, _0x00_E, _0xed_E, _0x20_E, _0xfc_E, _0xb1_E, _0x5b_E, _0x6a_E, _0xcb_E, _0xbe_E, _0x39_E, _0x4a_E, _0x4c_E, _0x58_E, _0xcf_E,
    _0xd0_E, _0xef_E, _0xaa_E, _0xfb_E, _0x43_E, _0x4d_E, _0x33_E, _0x85_E, _0x45_E, _0xf9_E, _0x02_E, _0x7f_E, _0x50_E, _0x3c_E, _0x9f_E, _0xa8_E,
    _0x51_E, _0xa3_E, _0x40_E, _0x8f_E, _0x92_E, _0x9d_E, _0x38_E, _0xf5_E, _0xbc_E, _0xb6_E, _0xda_E, _0x21_E, _0x10_E, _0xff_E, _0xf3_E, _0xd2_E,
    _0xcd_E, _0x0c_E, _0x13_E, _0xec_E, _0x5f_E, _0x97_E, _0x44_E, _0x17_E, _0xc4_E, _0xa7_E, _0x7e_E, _0x3d_E, _0x64_E, _0x5d_E, _0x19_E, _0x73_E,
    _0x60_E, _0x81_E, _0x4f_E, _0xdc_E, _0x22_E, _0x2a_E, _0x90_E, _0x88_E, _0x46_E, _0xee_E, _0xb8_E, _0x14_E, _0xde_E, _0x5e_E, _0x0b_E, _0xdb_E,
    _0xe0_E, _0x32_E, _0x3a_E, _0x0a_E, _0x49_E, _0x06_E, _0x24_E, _0x5c_E, _0xc2_E, _0xd3_E, _0xac_E, _0x62_E, _0x91_E, _0x95_E, _0xe4_E, _0x79_E,
    _0xe7_E, _0xc8_E, _0x37_E, _0x6d_E, _0x8d_E, _0xd5_E, _0x4e_E, _0xa9_E, _0x6c_E, _0x56_E, _0xf4_E, _0xea_E, _0x65_E, _0x7a_E, _0xae_E, _0x08_E,
    _0xba_E, _0x78_E, _0x25_E, _0x2e_E, _0x1c_E, _0xa6_E, _0xb4_E, _0xc6_E, _0xe8_E, _0xdd_E, _0x74_E, _0x1f_E, _0x4b_E, _0xbd_E, _0x8b_E, _0x8a_E,
    _0x70_E, _0x3e_E, _0xb5_E, _0x66_E, _0x48_E, _0x03_E, _0xf6_E, _0x0e_E, _0x61_E, _0x35_E, _0x57_E, _0xb9_E, _0x86_E, _0xc1_E, _0x1d_E, _0x9e_E,
    _0xe1_E, _0xf8_E, _0x98_E, _0x11_E, _0x69_E, _0xd9_E, _0x8e_E, _0x94_E, _0x9b_E, _0x1e_E, _0x87_E, _0xe9_E, _0xce_E, _0x55_E, _0x28_E, _0xdf_E,
    _0x8c_E, _0xa1_E, _0x89_E, _0x0d_E, _0xbf_E, _0xe6_E, _0x42_E, _0x68_E, _0x41_E, _0x99_E, _0x2d_E, _0x0f_E, _0xb0_E, _0x54_E, _0xbb_E, _0x16_E
};

static const SecureUint<8> rsbox[256] =
{
    _0x52_E, _0x09_E, _0x6a_E, _0xd5_E, _0x30_E, _0x36_E, _0xa5_E, _0x38_E, _0xbf_E, _0x40_E, _0xa3_E, _0x9e_E, _0x81_E, _0xf3_E, _0xd7_E, _0xfb_E,
    _0x7c_E, _0xe3_E, _0x39_E, _0x82_E, _0x9b_E, _0x2f_E, _0xff_E, _0x87_E, _0x34_E, _0x8e_E, _0x43_E, _0x44_E, _0xc4_E, _0xde_E, _0xe9_E, _0xcb_E,
    _0x54_E, _0x7b_E, _0x94_E, _0x32_E, _0xa6_E, _0xc2_E, _0x23_E, _0x3d_E, _0xee_E, _0x4c_E, _0x95_E, _0x0b_E, _0x42_E, _0xfa_E, _0xc3_E, _0x4e_E,
    _0x08_E, _0x2e_E, _0xa1_E, _0x66_E, _0x28_E, _0xd9_E, _0x24_E, _0xb2_E, _0x76_E, _0x5b_E, _0xa2_E, _0x49_E, _0x6d_E, _0x8b_E, _0xd1_E, _0x25_E,
    _0x72_E, _0xf8_E, _0xf6_E, _0x64_E, _0x86_E, _0x68_E, _0x98_E, _0x16_E, _0xd4_E, _0xa4_E, _0x5c_E, _0xcc_E, _0x5d_E, _0x65_E, _0xb6_E, _0x92_E,
    _0x6c_E, _0x70_E, _0x48_E, _0x50_E, _0xfd_E, _0xed_E, _0xb9_E, _0xda_E, _0x5e_E, _0x15_E, _0x46_E, _0x57_E, _0xa7_E, _0x8d_E, _0x9d_E, _0x84_E,
    _0x90_E, _0xd8_E, _0xab_E, _0x00_E, _0x8c_E, _0xbc_E, _0xd3_E, _0x0a_E, _0xf7_E, _0xe4_E, _0x58_E, _0x05_E, _0xb8_E, _0xb3_E, _0x45_E, _0x06_E,
    _0xd0_E, _0x2c_E, _0x1e_E, _0x8f_E, _0xca_E, _0x3f_E, _0x0f_E, _0x02_E, _0xc1_E, _0xaf_E, _0xbd_E, _0x03_E, _0x01_E, _0x13_E, _0x8a_E, _0x6b_E,
    _0x3a_E, _0x91_E, _0x11_E, _0x41_E, _0x4f_E, _0x67_E, _0xdc_E, _0xea_E, _0x97_E, _0xf2_E, _0xcf_E, _0xce_E, _0xf0_E, _0xb4_E, _0xe6_E, _0x73_E,
    _0x96_E, _0xac_E, _0x74_E, _0x22_E, _0xe7_E, _0xad_E, _0x35_E, _0x85_E, _0xe2_E, _0xf9_E, _0x37_E, _0xe8_E, _0x1c_E, _0x75_E, _0xdf_E, _0x6e_E,
    _0x47_E, _0xf1_E, _0x1a_E, _0x71_E, _0x1d_E, _0x29_E, _0xc5_E, _0x89_E, _0x6f_E, _0xb7_E, _0x62_E, _0x0e_E, _0xaa_E, _0x18_E, _0xbe_E, _0x1b_E,
    _0xfc_E, _0x56_E, _0x3e_E, _0x4b_E, _0xc6_E, _0xd2_E, _0x79_E, _0x20_E, _0x9a_E, _0xdb_E, _0xc0_E, _0xfe_E, _0x78_E, _0xcd_E, _0x5a_E, _0xf4_E,
    _0x1f_E, _0xdd_E, _0xa8_E, _0x33_E, _0x88_E, _0x07_E, _0xc7_E, _0x31_E, _0xb1_E, _0x12_E, _0x10_E, _0x59_E, _0x27_E, _0x80_E, _0xec_E, _0x5f_E,
    _0x60_E, _0x51_E, _0x7f_E, _0xa9_E, _0x19_E, _0xb5_E, _0x4a_E, _0x0d_E, _0x2d_E, _0xe5_E, _0x7a_E, _0x9f_E, _0x93_E, _0xc9_E, _0x9c_E, _0xef_E,
    _0xa0_E, _0xe0_E, _0x3b_E, _0x4d_E, _0xae_E, _0x2a_E, _0xf5_E, _0xb0_E, _0xc8_E, _0xeb_E, _0xbb_E, _0x3c_E, _0x83_E, _0x53_E, _0x99_E, _0x61_E,
    _0x17_E, _0x2b_E, _0x04_E, _0x7e_E, _0xba_E, _0x77_E, _0xd6_E, _0x26_E, _0xe1_E, _0x69_E, _0x14_E, _0x63_E, _0x55_E, _0x21_E, _0x0c_E, _0x7d_E
};

static const SecureUint<8> Rcon[11] =
{
    _0x8d_E, _0x01_E, _0x02_E, _0x04_E, _0x08_E, _0x10_E, _0x20_E, _0x40_E, _0x80_E, _0x1b_E, _0x36_E
};

#define AES_ROUND  10      // for 128 bit key size
#define KEYLEN 16           // key length in bytes
#define WORD_IN_KEY 4       // The number of 32 bit words in a key.
#define BYTE_IN_WORD 4      // this is known fact
#define ROUND 10            // The number of rounds in AES Cipher.
#define KEY_EXP_SIZE 176    // for 128 bit key size
#define COL_LEN 4           // for 128 bit key size

static SecureUint<8> round_key[KEY_EXP_SIZE];
// static SecureUint<8>* master_key;

typedef SecureUint<8> state_t[4][4];
static state_t state;

void printAllRoundKeys(void);
void printRoundKey(int);
void printState(void);
void key_expansion(const SecureUint<8> *);

SecureUint<8> xtime(const SecureUint<8> &);
SecureUint<8> Multiply(const SecureUint<8> &, unsigned);

void add_roundKey(int);

void aes_encrypt(void);
void sub_byte(void);
void shift_row(void);
void mix_column(void);

void AES_ECB_encrypt(const SecureUint<8> *, const SecureUint<8> *, SecureUint<8> *, const uint32_t);
void AES_ECB_decrypt(const SecureUint<8> *, const SecureUint<8> *, SecureUint<8> *, const uint32_t);

void aes_decrypt(void);
void inv_sub_byte(void);
void inv_shift_row(void);
void inv_mix_column(void);

SecureUint<8> lookup(const SecureUint<8> & index, const SecureUint<8> box[]);

template <class S, class T>
void array2matrix( S * m, const T * a, size_t rows, size_t cols );

template <class S, class T>
void matrix2array( S * a, const T * m, size_t rows, size_t cols );

void printArray( SecureUint<8> * a, size_t sz );

int main()
{
    static SecureUint<8> master_key[16] =
    {
        _0x2B_E, _0x7E_E, _0x15_E, _0x16_E,
        _0x28_E, _0xAE_E, _0xD2_E, _0xA6_E,
        _0xAB_E, _0xF7_E, _0x15_E, _0x88_E,
        _0x09_E, _0xCF_E, _0x4F_E, _0x3C_E
    };

    SecureUint<8> plaintext[]  =
    {
        _0x32_E, _0x43_E, _0xF6_E, _0xA8_E,
        _0x88_E, _0x5A_E, _0x30_E, _0x8D_E,
        _0x31_E, _0x31_E, _0x98_E, _0xA2_E,
        _0xE0_E, _0x37_E, _0x07_E, _0x34_E
    };

    SecureUint<8> ciphertext[] =
    {
        _0x39_E, _0x25_E, _0x84_E, _0x1D_E,
        _0x02_E, _0xDC_E, _0x09_E, _0xFB_E,
        _0xDC_E, _0x11_E, _0x85_E, _0x97_E,
        _0x19_E, _0x6A_E, _0x0B_E, _0x32_E
    };

    SecureUint<8> buffer[16];
    // int i;
    // cout << "master key.: " << flush;
    // printArray(master_key, 16);

    // cout << "\nENCRYPTING\n";
    // cout << "plaintext..: " << flush;
    // printArray(plaintext, 16);
    Timer t;
    AES_ECB_encrypt(plaintext, master_key, buffer, 16);
    auto r = t.get();

    // cout << "ciphertext.: " << flush;
    // printArray(buffer, 16);
    // cout << "expected...: ";
    // printArray(ciphertext, 16);
    // SecureBool success = _1_E;
    // for ( i = 0; i < 16; i++ ) success &= buffer[i] == ciphertext[i];
    // cout << "SUCCESS: " << success << '\n';

    cout << "Runtime: " << r << " us\n";

    // cout << "\nDECRYPTING\n";
    // cout << "ciphertext.: " << flush;
    // printArray(ciphertext, 16);
    // AES_ECB_decrypt(ciphertext, master_key, buffer, 16);
    // cout << "plaintext..: " << flush;
    // printArray(buffer, 16);
    // cout << "expected...: " << flush;
    // printArray(plaintext, 16);
    // success = _1_E;
    // for ( i = 0; i < 16; i++ ) success &= buffer[i] == plaintext[i];
    // cout << "SUCCESS: " << success << '\n';
}

void AES_ECB_encrypt(const SecureUint<8> * input, const SecureUint<8> * key, SecureUint<8> * output, const uint32_t length)
{
    /*
        input contains plaintext; key contains master key
        output shouldcontain ciphertext; length denotes the length of input.
        In this code, we assume the size of input is 16 byte
    */

    //copy input to output and run the algorithm in-memory
    array2matrix(state, input, 4, 4);

    // key expansion algorithm, generates round keys based on AES master.
    // Key assumption here is AES-128 only.
    key_expansion(key);

    // AES encryption algorithm is executed in-memory.
    aes_encrypt();
    matrix2array(output, state, 4, 4);
}

void AES_ECB_decrypt(const SecureUint<8> * input, const SecureUint<8> * key, SecureUint<8> * output, const uint32_t length)
{
    /*
        input contains ciphertext; key contains master key
        output shouldcontain plaintext; length denotes the length of input.
        In this code, we assume the size of input is 16 byte
    */

    //copy input to output and run the algorithm in-memory
    array2matrix(state, input, 4, 4);

    // key expansion algorithm, generates round keys based on AES master.
    // Key assumption here is AES-128 only.
    // master_key = key;
    // key_expansion(master_key);
    key_expansion(key);

    // AES decryption algorithm is executed in-memory.
    aes_decrypt();
    matrix2array(output, state, 4, 4);
}

//The is the main AES algorithm, which encrypts 128 bit plaintext using the master key
void aes_encrypt()
{
    int round = 0;
    // pre-whitening layer
    add_roundKey(round);

    // run this loop for n-1 rounds; 9 roundsfor AES-128
    for (round = 1; round < AES_ROUND; round++)
    {
        sub_byte();
        shift_row();
        mix_column();
        add_roundKey(round);
    }

    // final round
    sub_byte();
    shift_row();
    add_roundKey(round);
}

//The is the main AES algorithm, which decrypts 128 bit ciphertext using the master key
void aes_decrypt()
{
    unsigned round = AES_ROUND;

    add_roundKey(round);

    for (round = (AES_ROUND - 1); round > 0; --round)
    {
        inv_shift_row();
        inv_sub_byte();
        add_roundKey(round);
        inv_mix_column();
    }

    inv_shift_row();
    inv_sub_byte();
    add_roundKey(0);
}

void add_roundKey(int round)
{
    /*
    round_key is 1D array of size (11 (rounds) * 4 (word) * 4(bytes in word)) bytes
    round *16 gives the starting position of round key
    i*4 + j is just a sequential access as per the loop.
    */
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            state[i][j] ^= round_key[round * 16 + i * 4 + j];
}

void sub_byte()
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            state[i][j] = lookup(state[i][j], sbox);
}

void shift_row()
{
    SecureUint<8> temp;
    // first row no change

    //second row rotate by one byte
    temp = state[0][1];
    state[0][1] = state[1][1];
    state[1][1] = state[2][1];
    state[2][1] = state[3][1];
    state[3][1] = temp;

    // third row rotate by two byte
    temp = state[0][2];
    state[0][2] = state[2][2];
    state[2][2] = temp;

    temp = state[1][2];
    state[1][2] = state[3][2];
    state[3][2] = temp;

    //fourth row rotate by 3 byte
    temp = state[0][3];
    state[0][3] = state[3][3];
    state[3][3] = state[2][3];
    state[2][3] = state[1][3];
    state[1][3] = temp;

    /*
        Shift row operation with respect to the state arrays.
        State is a pointer, hence NEXT POINTER points to next row in same column
        00  10  20  30      00  10  20  30
        01  11  21  31      11  21  31  01
        02  12  22  32      22  32  02  12
        03  13  23  33      33  03  13  23
    */

}

/*
    a[i] = input column byte; b[i] = multiply(a[i],2); r[i] = output column byte

    r[0] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1];  2 * a0 + a3 + a2 + 3 * a1
    r[1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2];  2 * a1 + a0 + a3 + 3 * a2
    r[2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3];  2 * a2 + a1 + a0 + 3 * a3
    r[3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0];  2 * a3 + a2 + a1 + 3 * a0

    Multiply(x,2) = x <<1 and conditional XOR with new x
    Multiply(x,3) = Multiply(x,2) ^ x

    Multiply(x,2)
        1. (new x) = left shift x
        2. if MSB of (old x) is 1, then (new x) ^ 0x1B
        (MSB(x) =1 denotes, reduction is required and 0x1B is reducing polynomial)
*/
void mix_column()
{
    int i;
    SecureUint<8> mul_by_2[4];
    SecureUint<8> temp;
    SecureUint<8> temp_state[4];
    SecureUint<8> current_state[4];
    SecureUint<8> aux = _0_E;

    for (i = 0; i < 4; i++)
    {
        aux[0] = state[i][0][7];
        mul_by_2[0] = ((state[i][0] << 1) ^ (0x1B * aux));
        aux[0] = state[i][1][7];
        mul_by_2[1] = ((state[i][1] << 1) ^ (0x1B * aux));
        aux[0] = state[i][2][7];
        mul_by_2[2] = ((state[i][2] << 1) ^ (0x1B * aux));
        aux[0] = state[i][3][7];
        mul_by_2[3] = ((state[i][3] << 1) ^ (0x1B * aux));

        temp_state[0] = mul_by_2[0] ^ state[i][3] ^ state[i][2] ^ (mul_by_2[1] ^ state[i][1]);
        temp_state[1] = mul_by_2[1] ^ state[i][0] ^ state[i][3] ^ (mul_by_2[2] ^ state[i][2]);
        temp_state[2] = mul_by_2[2] ^ state[i][1] ^ state[i][0] ^ (mul_by_2[3] ^ state[i][3]);
        temp_state[3] = mul_by_2[3] ^ state[i][2] ^ state[i][1] ^ (mul_by_2[0] ^ state[i][0]);

        state[i][0] = temp_state[0];
        state[i][1] = temp_state[1];
        state[i][2] = temp_state[2];
        state[i][3] = temp_state[3];
    }
}


void inv_sub_byte()
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            state[i][j] = lookup(state[i][j], rsbox);
}

void inv_shift_row()
{
    SecureUint<8> temp;

    // Rotate first row 1 columns to right
    temp = state[3][1];
    state[3][1] = state[2][1];
    state[2][1] = state[1][1];
    state[1][1] = state[0][1];
    state[0][1] = temp;

    // Rotate second row 2 columns to right
    temp = state[0][2];
    state[0][2] = state[2][2];
    state[2][2] = temp;

    temp = state[1][2];
    state[1][2] = state[3][2];
    state[3][2] = temp;

    // Rotate third row 3 columns to right
    temp = state[0][3];
    state[0][3] = state[1][3];
    state[1][3] = state[2][3];
    state[2][3] = state[3][3];
    state[3][3] = temp;
}

void inv_mix_column()
{
    int i;
    SecureUint<8> b0, b1, b2, b3;
    for (i = 0; i < 4; ++i)
    {
        b0 = state[i][0];
        b1 = state[i][1];
        b2 = state[i][2];
        b3 = state[i][3];

        state[i][0] = Multiply(b0, 0x0e) ^ Multiply(b1, 0x0b) ^ Multiply(b2, 0x0d) ^ Multiply(b3, 0x09);
        state[i][1] = Multiply(b0, 0x09) ^ Multiply(b1, 0x0e) ^ Multiply(b2, 0x0b) ^ Multiply(b3, 0x0d);
        state[i][2] = Multiply(b0, 0x0d) ^ Multiply(b1, 0x09) ^ Multiply(b2, 0x0e) ^ Multiply(b3, 0x0b);
        state[i][3] = Multiply(b0, 0x0b) ^ Multiply(b1, 0x0d) ^ Multiply(b2, 0x09) ^ Multiply(b3, 0x0e);
    }
}

//This is multiply 2.x and reduced using 0x1B.
SecureUint<8> xtime(const SecureUint<8> & x)
{
    SecureUint<8> aux = _0_E;
    aux[0] = x[7];
    return ((x << 1) ^ (0x1B * aux));
}

/*
    This is specifically for AES because, y ={0E, 0B, 0D, 09} from the matrix
    For each bit in y, x is multiplied by power of 2, correspondingly with hte position of bit in y
*/
SecureUint<8> Multiply(const SecureUint<8> & x, unsigned y)
{
    return (((y & 1) * x) ^
            ((y >> 1 & 1) * xtime(x)) ^
            ((y >> 2 & 1) * xtime(xtime(x))) ^
            ((y >> 3 & 1) * xtime(xtime(xtime(x)))) ^
            ((y >> 4 & 1) * xtime(xtime(xtime(xtime(x))))));
}

// written specifically for 128 bit key size. Need to generalize for other key sizes also
void key_expansion(const SecureUint<8> * key)
{
    int i;
    SecureUint<8> temp[4], k;

    // first round key is same as master key
    for (i = 0; i < WORD_IN_KEY; i++)
    {
        round_key[(i * 4) + 0] = key[(i * 4) + 0];
        round_key[(i * 4) + 1] = key[(i * 4) + 1];
        round_key[(i * 4) + 2] = key[(i * 4) + 2];
        round_key[(i * 4) + 3] = key[(i * 4) + 3];
    }

    for (i = 4; i < WORD_IN_KEY * (ROUND + 1); i++)
    {
        // STEP 1 : temp = WORD[i-1]
        temp[0] = round_key[((i - 1) * 4) + 0];
        temp[1] = round_key[((i - 1) * 4) + 1];
        temp[2] = round_key[((i - 1) * 4) + 2];
        temp[3] = round_key[((i - 1) * 4) + 3];

        //STEP 2 : if (i%4 = 0) then temp = SubWord(RotWord(temp)) ^ RCon[i/4]
        if (i % 4 == 0)
        {
            // RotWord(temp)
            k = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = k;

            //SubWord(RotWord(temp))
            temp[0] = lookup(temp[0], sbox);
            temp[1] = lookup(temp[1], sbox);
            temp[2] = lookup(temp[2], sbox);
            temp[3] = lookup(temp[3], sbox);

            //SubWord(RotWord(temp)) ^ RCon[i/4]
            temp[0] = temp[0] ^ Rcon[i / 4];
        }

        //STEP 3 : WORD[i] = WORD[i-4] ^ temp
        round_key[(i * 4) + 0] = round_key[((i - 4) * 4) + 0] ^ temp[0];
        round_key[(i * 4) + 1] = round_key[((i - 4) * 4) + 1] ^ temp[1];
        round_key[(i * 4) + 2] = round_key[((i - 4) * 4) + 2] ^ temp[2];
        round_key[(i * 4) + 3] = round_key[((i - 4) * 4) + 3] ^ temp[3];
    }
}


void printAllRoundKeys()
{
    int i;
    for (i = 0; i < 11; i++)
        printRoundKey(i);
}

void printRoundKey(int round)
{
    int i = round * 16;
    for (; i < (round + 1) * 16; i++)
        cout << round_key[i] << ' ' << flush;
    cout << '\n';
}

void printState()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++) cout << state[j][i] << ' ' << flush;
        cout << '\n';
    }
    cout << '\n';
}

SecureUint<8> lookup(const SecureUint<8> & index, const SecureUint<8> box[] )
{
    SecureUint<8> sub, i;
    sub = i = _0_E;
    for ( size_t b = 0; b < 256; b++ ) sub += (index == i++) * box[b];
    return sub;
}

template <class S, class T>
void array2matrix( S * m, const T * a, size_t rows, size_t cols )
{
    for ( size_t i = 0; i < rows; i++ )
        for ( size_t j = 0; j < cols; j++ )
            m[i][j] = a[cols * i + j];
}

template <class S, class T>
void matrix2array( S * a, const T * m, size_t rows, size_t cols )
{
    for ( size_t i = 0; i < rows; i++ )
        for ( size_t j = 0; j < cols; j++ )
            a[cols * i + j] = m[i][j];
}

void printArray( SecureUint<8> * a, size_t sz )
{
    for ( size_t i = 0; i < sz; i++ ) cout << a[i] << ' ' << flush;
    cout << '\n';
}
