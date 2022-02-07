// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "base64.h"

using std::string;

namespace
{
inline void fill2encode(unsigned char * in, unsigned char * out)
{
    out[0] = (in[0] & 0xfc) >> 2;
    out[1] = ((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4);
    out[2] = ((in[1] & 0x0f) << 2) + ((in[2] & 0xc0) >> 6);
    out[3] = in[2] & 0x3f;
}

inline void fill2decode(unsigned char * in, unsigned char * out)
{
    out[0] = (in[0] << 2) + ((in[1] & 0x30) >> 4);
    out[1] = ((in[1] & 0xf) << 4) + ((in[2] & 0x3c) >> 2);
    out[2] = ((in[2] & 0x3) << 6) + in[3];
}

inline const string & b64_table()
{
    static const string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    return table;
}

} // namespace

string e3::util::base64::encode(unsigned char const * data, unsigned int data_length)
{
    int i = 0;
    int j = 0;
    string encoded_data;
    unsigned char data_block[3];
    unsigned char encoded_block[4];

    while (data_length--)
    {
        data_block[i++] = *(data++);
        if (i == 3)
        {
            fill2encode(data_block, encoded_block);
            for (i = 0; (i < 4) ; i++)
                encoded_data += b64_table()[encoded_block[i]];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
            data_block[j] = '\0';

        fill2encode(data_block, encoded_block);

        for (j = 0; (j < i + 1); j++)
            encoded_data += b64_table()[encoded_block[j]];

        while ((i++ < 3))
            encoded_data += '=';

    }

    return encoded_data;

}

string e3::util::base64::decode(string const & data)
{
    int data_length = (int)data.size();
    int i = 0;
    int j = 0;
    int k = 0;
    unsigned char data_block[4], decoded_block[3];
    string decoded_data;

    while (data_length-- && ( data[k] != '=') && (isalnum(data[k]) || (data[k] == '+') || (data[k] == '/')))
    {
        data_block[i++] = data[k];
        k++;
        if (i == 4)
        {
            for (i = 0; i < 4; i++)
                data_block[i] = (unsigned char)b64_table().find(data_block[i]);

            fill2decode (data_block, decoded_block);

            for (i = 0; (i < 3); i++)
                decoded_data += decoded_block[i];
            i = 0;
        }
    }

    if (i != 0)
    {
        for (j = i; j < 4; j++)
            data_block[j] = '\0';

        for (j = 0; j < 4; j++)
            data_block[j] = (unsigned char)b64_table().find(data_block[j]);

        fill2decode (data_block, decoded_block);
        for (j = 0; (j < i - 1); j++) decoded_data += decoded_block[j];
    }

    return decoded_data;
}

