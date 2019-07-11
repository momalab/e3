#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

static const uint8_t sbox[256] =
{
    //0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

static const uint8_t rsbox[256] =
{
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

static const uint8_t Rcon[11] =
{
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
};

#define AES_ROUND  10      // for 128 bit key size
#define KEYLEN 16           // key length in bytes
#define WORD_IN_KEY 4       // The number of 32 bit words in a key.
#define BYTE_IN_WORD 4      // this is known fact
#define ROUND 10            // The number of rounds in AES Cipher.
#define KEY_EXP_SIZE 176    // for 128 bit key size
#define COL_LEN 4           // for 128 bit key size



static uint8_t round_key[KEY_EXP_SIZE];
static uint8_t * master_key;

typedef uint8_t state_t[4][4];
static state_t * state;

void printAllRoundKeys(void);
void printRoundKey(int);
void printState(void);
void key_expansion(uint8_t *);

uint8_t xtime(uint8_t);
uint8_t Multiply(uint8_t, uint8_t);

void add_roundKey(int);

void aes_encrypt(void);
void sub_byte(void);
void shift_row(void);
void mix_column(void);

void AES_ECB_encrypt(const uint8_t *, const uint8_t *, uint8_t *, const uint32_t);
void AES_ECB_decrypt(const uint8_t *, const uint8_t *, uint8_t *, const uint32_t);


void aes_decrypt(void);
void inv_sub_byte(void);
void inv_shift_row(void);
void inv_mix_column(void);

void printArray( uint8_t * , size_t );
int main()
{
    /*
        static uint8_t master_key[16] = {   0x54, 0x68, 0x61, 0x74,
                                            0x73, 0x20, 0x6D, 0x79,
                                            0x20, 0x4B, 0x75, 0x6E,
                                            0x67, 0x20, 0x46, 0x75};

        uint8_t in[]  = {   0x54, 0x77, 0x6F, 0x20,
                            0x4F, 0x6E, 0x65, 0x20,
                            0x4E, 0x69, 0x6E, 0x65,
                            0x20, 0x54, 0x77, 0x6F};
    */

    static uint8_t master_key[16] = {   0x2B, 0x7E, 0x15, 0x16,
                                        0x28, 0xAE, 0xD2, 0xA6,
                                        0xAB, 0xF7, 0x15, 0x88,
                                        0x09, 0xCF, 0x4F, 0x3C
                                    };

    uint8_t in[]  = {   0x32, 0x43, 0xF6, 0xA8,
                        0x88, 0x5A, 0x30, 0x8D,
                        0x31, 0x31, 0x98, 0xA2,
                        0xE0, 0x37, 0x07, 0x34
                    };

    uint8_t expected_output[] = {   0x39, 0x25, 0x84, 0x1D,
                                    0x02, 0xDC, 0x09, 0xFB,
                                    0xDC, 0x11, 0x85, 0x97,
                                    0x19, 0x6A, 0x0B, 0x32
                                };

    uint8_t buffer[16];
    int i;

    printArray(in, 16);

    // AES_ECB_encrypt(in, master_key, buffer, 16);
    //for(int i=0; i<1000000; i++ )
    AES_ECB_decrypt(expected_output, master_key, buffer, 16);

    printf("ciphertext\t: ");
    for (i = 0; i < 16; i++)
        printf("%u ", expected_output[i]);
    printf("\n");

    printf("master key\t: ");
    for (i = 0; i < 16; i++)
        printf("%u ", master_key[i]);
    printf("\n");

    printf("plaintext\t: ");
    for (i = 0; i < 16; i++)
        printf("%u ", buffer[i]);
    printf("\n");


    if (0 == memcmp((char *) in, (char *) buffer, 16))
    {
        printf("SUCCESS!\n");
    }
    else
    {
        printf("FAILURE!\n");
    }

    return 0;
}

void AES_ECB_encrypt(const uint8_t * input, const uint8_t * key, uint8_t * output, const uint32_t length)
{
    /*
        input contains plaintext; key contains master key
        output shouldcontain ciphertext; length denotes the length of input.
        In this code, we assume the size of input is 16 byte
    */

    //copy input to output and run the algorithm in-memory
    memcpy(output, input, length);
    state = output;

    // key expansion algorithm, generates round keys based on AES master.
    // Key assumption here is AES-128 only.
    master_key = key;
    key_expansion(master_key);

    // AES encryption algorithm is executed in-memory.
    aes_encrypt();
}

void AES_ECB_decrypt(const uint8_t * input, const uint8_t * key, uint8_t * output, const uint32_t length)
{
    /*
        input contains ciphertext; key contains master key
        output shouldcontain plaintext; length denotes the length of input.
        In this code, we assume the size of input is 16 byte
    */

    //copy input to output and run the algorithm in-memory
    memcpy(output, input, length);
    state = output;

    // key expansion algorithm, generates round keys based on AES master.
    // Key assumption here is AES-128 only.
    master_key = key;
    key_expansion(master_key);

    // AES decryption algorithm is executed in-memory.
    aes_decrypt();
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
    uint8_t round = AES_ROUND;

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
    {
        for (j = 0; j < 4; j++)
        {
            (*state)[i][j] ^= round_key[round * 16 + i * 4 + j];
        }
    }
}

void sub_byte()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            (*state)[i][j] = sbox[(*state)[i][j]];
        }
    }
}

void shift_row()
{
    uint8_t temp;
    // first row no change

    //second row rotate by one byte
    temp = (*state)[0][1];
    (*state)[0][1] = (*state)[1][1];
    (*state)[1][1] = (*state)[2][1];
    (*state)[2][1] = (*state)[3][1];
    (*state)[3][1] = temp;

    // third row rotate by two byte
    temp = (*state)[0][2];
    (*state)[0][2] = (*state)[2][2];
    (*state)[2][2] = temp;

    temp = (*state)[1][2];
    (*state)[1][2] = (*state)[3][2];
    (*state)[3][2] = temp;

    //fourth row rotate by 3 byte
    temp = (*state)[0][3];
    (*state)[0][3] = (*state)[3][3];
    (*state)[3][3] = (*state)[2][3];
    (*state)[2][3] = (*state)[1][3];
    (*state)[1][3] = temp;

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
    int i, j;
    uint8_t mul_by_2[4];
    uint8_t temp;
    uint8_t temp_state[4];
    uint8_t current_state[4];

    for (i = 0; i < 4; i++)
    {
        mul_by_2[0] = (((*state)[i][0] << 1) ^ (0x1B * (((*state)[i][0] >> 7) & 1)));
        mul_by_2[1] = (((*state)[i][1] << 1) ^ (0x1B * (((*state)[i][1] >> 7) & 1)));
        mul_by_2[2] = (((*state)[i][2] << 1) ^ (0x1B * (((*state)[i][2] >> 7) & 1)));
        mul_by_2[3] = (((*state)[i][3] << 1) ^ (0x1B * (((*state)[i][3] >> 7) & 1)));

        temp_state[0] = mul_by_2[0] ^ (*state)[i][3] ^ (*state)[i][2] ^ (mul_by_2[1] ^ (*state)[i][1]);
        temp_state[1] = mul_by_2[1] ^ (*state)[i][0] ^ (*state)[i][3] ^ (mul_by_2[2] ^ (*state)[i][2]);
        temp_state[2] = mul_by_2[2] ^ (*state)[i][1] ^ (*state)[i][0] ^ (mul_by_2[3] ^ (*state)[i][3]);
        temp_state[3] = mul_by_2[3] ^ (*state)[i][2] ^ (*state)[i][1] ^ (mul_by_2[0] ^ (*state)[i][0]);

        (*state)[i][0] = temp_state[0];
        (*state)[i][1] = temp_state[1];
        (*state)[i][2] = temp_state[2];
        (*state)[i][3] = temp_state[3];
    }
}


void inv_sub_byte()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            (*state)[i][j] = rsbox[(*state)[i][j]];
        }
    }
}

void inv_shift_row()
{
    uint8_t temp;

    // Rotate first row 1 columns to right
    temp = (*state)[3][1];
    (*state)[3][1] = (*state)[2][1];
    (*state)[2][1] = (*state)[1][1];
    (*state)[1][1] = (*state)[0][1];
    (*state)[0][1] = temp;

    // Rotate second row 2 columns to right
    temp = (*state)[0][2];
    (*state)[0][2] = (*state)[2][2];
    (*state)[2][2] = temp;

    temp = (*state)[1][2];
    (*state)[1][2] = (*state)[3][2];
    (*state)[3][2] = temp;

    // Rotate third row 3 columns to right
    temp = (*state)[0][3];
    (*state)[0][3] = (*state)[1][3];
    (*state)[1][3] = (*state)[2][3];
    (*state)[2][3] = (*state)[3][3];
    (*state)[3][3] = temp;
}

void inv_mix_column()
{
    int i;
    uint8_t b0, b1, b2, b3;
    for (i = 0; i < 4; ++i)
    {
        b0 = (*state)[i][0];
        b1 = (*state)[i][1];
        b2 = (*state)[i][2];
        b3 = (*state)[i][3];

        (*state)[i][0] = Multiply(b0, 0x0e) ^ Multiply(b1, 0x0b) ^ Multiply(b2, 0x0d) ^ Multiply(b3, 0x09);
        (*state)[i][1] = Multiply(b0, 0x09) ^ Multiply(b1, 0x0e) ^ Multiply(b2, 0x0b) ^ Multiply(b3, 0x0d);
        (*state)[i][2] = Multiply(b0, 0x0d) ^ Multiply(b1, 0x09) ^ Multiply(b2, 0x0e) ^ Multiply(b3, 0x0b);
        (*state)[i][3] = Multiply(b0, 0x0b) ^ Multiply(b1, 0x0d) ^ Multiply(b2, 0x09) ^ Multiply(b3, 0x0e);
    }
}

//This is multiply 2.x and reduced using 0x1B.
uint8_t xtime(uint8_t x)
{
    return ((x << 1) ^ (0x1B * ((x >> 7) & 1)));
}

/*
    This is specifically for AES because, y ={0E, 0B, 0D, 09} from the matrix
    For each bit in y, x is multiplied by power of 2, correspondingly with hte position of bit in y
*/
uint8_t Multiply(uint8_t x, uint8_t y)
{
    return (((y & 1) * x) ^
            ((y >> 1 & 1) * xtime(x)) ^
            ((y >> 2 & 1) * xtime(xtime(x))) ^
            ((y >> 3 & 1) * xtime(xtime(xtime(x)))) ^
            ((y >> 4 & 1) * xtime(xtime(xtime(xtime(x))))));
}

// written specifically for 128 bit key size. Need to generalize for other key sizes also
void key_expansion(uint8_t * key)
{
    int i;
    uint8_t temp[4], k;

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
            temp[0] = sbox[temp[0]];
            temp[1] = sbox[temp[1]];
            temp[2] = sbox[temp[2]];
            temp[3] = sbox[temp[3]];

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
    for (i; i < (round + 1) * 16; i++)
        printf( "%u ", round_key[i]);
    printf("\n");
}

void printState()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%u ", (*state)[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void printArray( uint8_t * a, size_t sz )
{
    for ( size_t i = 0; i < sz; i++ ) printf("%u ", a[i]);
    printf("\n");
}

/*
References
1. https://en.wikipedia.org/wiki/Rijndael_MixColumns
2. https://kavaliro.com/wp-content/uploads/2014/03/AES.pdf
3. http://www.samiam.org/mix-column.html
4. http://www.samiam.org/galois.html
5. https://www.nist.gov/publications/advanced-encryption-standard-aes

*/
