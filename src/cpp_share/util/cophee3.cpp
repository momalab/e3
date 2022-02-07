// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// Using MPIR library
// Using CophEE hardware as a root-of-trust and an accelerator

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions          */
#include <errno.h>   /* ERROR Number Definitions           */
#include <unistd.h>
// #include "timer.h"

#include <vector>
#include "cophee.h"

using std::vector;

namespace e3
{

namespace cophee
{

// CONSTANTS

uint32_t INIT_BAUD_RATE         = 9600;
uint32_t RUN_BAUD_RATE          = 921600; //115200;
uint32_t FREQUENCY              = 24000000;
uint32_t DIVIDER                = FREQUENCY / RUN_BAUD_RATE;

uint32_t GPCFG_HOSTIRQ_PAD_CTL  = 0x40020018 ;
uint32_t GPCFG_N_ADDR0          = 0x40029000 ;
uint32_t GPCFG_NSQ_ADDR0        = 0x40029100 ;
uint32_t GPCFG_FKF_ADDR0        = 0x40029200 ;
uint32_t GPCFG_CLCTL_ADDR       = 0x40028004 ;
uint32_t GPCFG_CLEQCTL2         = 0x400200A8 ;
uint32_t GPCFG_RAND0_ADDR0      = 0x40029600 ;
uint32_t GPCFG_RAND1_ADDR0      = 0x40029680 ;
uint32_t GPCFG_CLSTATUS_ADDR    = 0x40028008 ;
uint32_t GPCFG_CLCTLP_ADDR      = 0x40028000 ;
uint32_t GPCFG_GPIO0_PAD_CTL    = 0x4002001C ;

uint32_t GPCFG_UARTM_BAUD_CTL   = 0x40020044 ;

uint32_t GPCFG_ARGA_ADDR0       = 0x40029300 ;
uint32_t GPCFG_ARGB_ADDR0       = 0x40029400 ;

uint32_t GPCFG_MUL_ADDR0        = 0x40029800 ;
uint32_t GPCFG_EXP_ADDR0        = 0x40029900 ;
uint32_t GPCFG_INV_ADDR0        = 0x40029A00 ;
uint32_t GPCFG_RES_ADDR0        = 0x40029700 ;

uint32_t cleq_ctl               = 0XC00027FD ;
uint32_t cleq_ctl2              = 0X000003FE ;
std::vector<uint32_t> cleq_N    = { 0X54330594, 0XCAEEF922, 0X52AEF179, 0XC2023770, 0X5F05CF9D, 0X412A3B26, 0X506E5692, 0X9CA7CD61,
                                    0X73B73572, 0X97A3F373, 0XF4D088CC, 0X000AB539, 0X572E300C, 0X82A5C05F, 0XC1AE5F5F, 0X1110BF98,
                                    0XEA7A93B3, 0XF81F0DD0, 0XABC6EB71, 0X00C53F55, 0X444357E7, 0X564D3095, 0X7B6E018F, 0X409B790B,
                                    0X8A66CEFF, 0XAC88E479, 0XF7C3A09C, 0X8EEC295D, 0X16DE7007, 0X94674EE0, 0X3EA28CA5, 0XD31A8FEF
                                  } ;

std::vector<uint32_t> cleq_NSQ  = { 0X1BB185D4, 0XDE94D51E, 0X64D92754, 0XE64C536F, 0XC557EFCF, 0X6D28ACE0, 0XF2F972B4, 0XE2520943,
                                    0X400B8E51, 0X2FB95147, 0X39941063, 0X2A014866, 0X9A5BBEB1, 0XDF1E5165, 0XFD372014, 0XCED19C16,
                                    0X2AF88810, 0XC09E9C8F, 0X1D9D7394, 0XE63E4DA0, 0X892C8B81, 0XF596A3F1, 0XEF7B19C5, 0XEE0771A1,
                                    0X82C24C76, 0X064E8DD2, 0XF583A263, 0X384C8B9F, 0X92BBF8E7, 0X851321BE, 0XE16B38FA, 0X955E94B8,
                                    0X5C557B63, 0X6D488408, 0XD96BA472, 0XE7598EF0, 0X44FB571E, 0XCEE3DFA2, 0XAB46CA36, 0X56A34F62,
                                    0X59920850, 0XF8FE4821, 0XE08376FA, 0XC5FFF9DD, 0XCFB59E45, 0XD73A8B00, 0X462C70D7, 0X08671440,
                                    0X331AFF2E, 0XB2C6DB38, 0XAA88F1C7, 0X4893AFA2, 0X8CD63C54, 0X5A2314CD, 0X9B0135C2, 0X81008825,
                                    0X6A3444BB, 0XA6460FA6, 0XFFDCE016, 0X59126243, 0X22EDE70A, 0X69E95BE4, 0XCA3BBE1B, 0X8778E121
                                  } ;

std::vector<uint32_t> cleq_rand0 = { 0X011C3DC4, 0XD6F8CA7A, 0X46373E00, 0XC0287C76, 0X7D0F26BB, 0X6DAB6C0B, 0XA9D6C907, 0X5D2971F4,
                                     0X557ECA39, 0XE984D85B, 0XDF7D4DE0, 0X7D3C44A3, 0XCC192C39, 0XC84C413D, 0XA79083FA, 0X6FA09257,
                                     0X6BF8EA35, 0XAE2AFBD0, 0X0FF79D38, 0X7DBD0CD6, 0X29C525EC, 0XDC6EFCE3, 0X28FDF73F, 0XC9248B2F,
                                     0X68E91B18, 0X18A58663, 0XABBCD353, 0XAB45F661, 0XC76A31A1, 0XEA0FC570, 0XC83490C3, 0X5FE08CF7
                                   } ;

std::vector<uint32_t> cleq_rand1 = { 0X04345AA8, 0XAB1006A3, 0XEF517A70, 0XAFA72C4E, 0X38609BD3, 0XC9F9B026, 0X5A7DDA5B, 0X053EB211,
                                     0X1973A4A3, 0X803411D7, 0X57FED817, 0X93346565, 0X975F9F8D, 0XD8F5A7A6, 0XCBCE2D2C, 0X0E1B168C,
                                     0XA0F51C86, 0XA3E6FCDE, 0X28EDA1CE, 0XBE5970B1, 0XFCF4C98D, 0X04E3ECCB, 0XD876BAF4, 0XF4329864,
                                     0X02DE3945, 0X27E291BD, 0X64165D1E, 0X14D2E4A2, 0X4A45CEF9, 0XE641AAC0, 0XE3C0021C, 0X4C17C9C9
                                   } ;

std::vector<uint32_t> cleq_fkf   = { 0X14124889, 0XD7B2F250, 0X8B3CF434, 0X153A43F6, 0X85C5992D, 0XA3DE651B, 0XF9AD4EB4, 0XC8A68780,
                                     0X6ADC1D62, 0XA573AA4C, 0X1092D305, 0X49922118, 0XCAC1731B, 0XA0087D54, 0X268FD3A8, 0XBF789053,
                                     0X22ECAB4E, 0X662060B9, 0XB54DBF01, 0XC4A2A950, 0X13E1F6C3, 0X965FC7B5, 0XEA443133, 0X92725734,
                                     0X668541C3, 0X36BC9215, 0XC3843192, 0XCB18BC4B, 0X53B561DD, 0XFED84032, 0X98F85626, 0X32F0A799,
                                     0X6A7451EF, 0XF665CF6D, 0XA002A2CD, 0XEC0ADB82, 0X7FEDC90E, 0X318AFD47, 0XB77861CD, 0X5707062A,
                                     0XD2485362, 0XE99BACA9, 0X47EA71C8, 0X48D7B823, 0XEF9B0785, 0XCD1BF251, 0X4180D669, 0X49363965,
                                     0XB0CB4730, 0XFEE41FAD, 0XFEC5C63A, 0XFBE41457, 0XEE6F1470, 0X05D8945A, 0XEE454D0E, 0X5DE864D1,
                                     0X5C59008C, 0X5EDAFD6F, 0X028B7854, 0XBE045FF2, 0X84C89369, 0X0FFCDEF6, 0XACCDF351, 0XF9421137
                                   } ;

int Cophee::handler = -1;
int Cophee::handlerArduino = -1;
int Cophee::baudRate = RUN_BAUD_RATE;
bool Cophee::inited = false;
bool Cophee::isUsingArduino = false;
bool Cophee::isParamsSet = false;

// INITIALIZATION

Cophee::Cophee(int baudRate, bool isUsingArduino)
{
    Cophee::baudRate = baudRate;
    Cophee::isUsingArduino = isUsingArduino;
    init();
}

void Cophee::init()
{
    if ( !inited )
    {
        init_port();
        init_chip();
        if (isUsingArduino) init_arduino();
        inited = true;
    }
}

void Cophee::init_arduino()
{
    printf("\nInit Arduino");
    handlerArduino = open("/dev/ttyACM3", O_RDWR | O_NOCTTY);
    if (handlerArduino == -1) /* Error Checking */
        printf("\n  Error! : Not able to open Serial Port of Arduino ");
    else
        printf("\n  Connection to Serial Port of Arduino successful ");

    struct termios SerialPortSettings;      /* Create the structure                          */
    tcgetattr(handlerArduino, &SerialPortSettings);     /* Get the current attributes of the Serial port */

    /* Setting the Baud rate */
    // cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
    // cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */
    cfsetospeed(&SerialPortSettings, 2000000);
    cfsetispeed(&SerialPortSettings, 2000000);

    /* 8N1 Mode */
    SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
    SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
    SerialPortSettings.c_cflag &= ~CSIZE;    /* Clears the mask for setting the data size             */
    SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

    SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
    SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */


    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

    SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

    /* Setting Time outs */
    SerialPortSettings.c_cc[VMIN] = 1 ; //3; /* Read at least 10 characters */
    SerialPortSettings.c_cc[VTIME] = 0; //0; /* Wait indefinetly   */
    SerialPortSettings.c_lflag = 0;

    if ((tcsetattr(handlerArduino, TCSANOW, &SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
        printf("\n  ERROR ! in setting attributes\n");
    else
        printf("\n  BaudRate = 2000000 \n  StopBits = 1 \n  Parity   = none \n");

    tcflush(handlerArduino, TCIFLUSH);   /* Discards old data in the rx buffer            */
}

void Cophee::init_chip()
{
    write_serial    (GPCFG_HOSTIRQ_PAD_CTL, 0x0012001A) ;
    write_serial    (GPCFG_CLCTL_ADDR, cleq_ctl)         ;
    write_serial    (GPCFG_CLEQCTL2, cleq_ctl2)          ;
    write_serial_1x (GPCFG_N_ADDR0, cleq_N)             ;
    write_serial_1x (GPCFG_RAND0_ADDR0, cleq_rand0)      ;
    write_serial_1x (GPCFG_RAND1_ADDR0, cleq_rand1)      ;
    write_serial_2x (GPCFG_NSQ_ADDR0, cleq_NSQ)          ;
    write_serial_2x (GPCFG_FKF_ADDR0, cleq_fkf)          ;
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000200)      ;
}

void Cophee::init_port()
{
    init_port_baud(INIT_BAUD_RATE);
    if (INIT_BAUD_RATE != baudRate)
    {
        unsigned divider = FREQUENCY / baudRate;
        write_serial(GPCFG_UARTM_BAUD_CTL, divider);
        sleep(2);
        close(handler);
        sleep(1);
        init_port_baud(baudRate);
    }
}

void Cophee::init_port_baud (uint32_t baud)
{
    printf("\n +----------------------------------+");
    printf("\n |        Serial Port Read          |");
    printf("\n +----------------------------------+");

    /*------------------------------- Opening the Serial Port -------------------------------*/

    /* Change /dev/ttyUSB0 to the one corresponding to your system */

    printf("\n  INFO: Connecting to Serial Port of Cryptoleq Hardware ");
    handler = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    // fd = open("/dev/cu.usbserial-FT162CZ2",O_RDWR | O_NOCTTY);    /* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
    /* O_RDWR   - Read/Write access to serial port       */
    /* O_NOCTTY - No terminal will control the process   */
    /* Open in blocking mode,read will wait              */



    if (handler == -1)                                           /* Error Checking */
        printf("\n  Error! : Not able to open Serial Port of Cryptoleq Hardware ");
    else
        printf("\n  Connection to Serial Port of Cryptoleq Hardware successful ");


    /*---------- Setting the Attributes of the serial port using termios structure --------- */

    struct termios SerialPortSettings;      /* Create the structure                          */

    tcgetattr(handler, &SerialPortSettings);     /* Get the current attributes of the Serial port */

    /* Setting the Baud rate */
    switch ( baud )
    {
        case 9600:
            cfsetispeed(&SerialPortSettings, B9600); /* Set Read  Speed as 9600                       */
            cfsetospeed(&SerialPortSettings, B9600); /* Set Write Speed as 9600                       */
            break;
        case 115200:
            cfsetispeed(&SerialPortSettings, B115200); /* Set Read  Speed as 9600                       */
            cfsetospeed(&SerialPortSettings, B115200); /* Set Write Speed as 9600                       */
            break;
        case 921600:
            cfsetispeed(&SerialPortSettings, B921600); /* Set Read  Speed as 9600                       */
            cfsetospeed(&SerialPortSettings, B921600); /* Set Write Speed as 9600                       */
            break;
        default:
            cfsetispeed(&SerialPortSettings, baud); /* Set Read  Speed as 9600                       */
            cfsetospeed(&SerialPortSettings, baud); /* Set Write Speed as 9600                       */
    }


    /* 8N1 Mode */
    SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
    SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
    SerialPortSettings.c_cflag &= ~CSIZE;    /* Clears the mask for setting the data size             */
    SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

    SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
    SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */


    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

    SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

    /* Setting Time outs */
    SerialPortSettings.c_cc[VMIN] = 4 ; //3; /* Read at least 10 characters */
    SerialPortSettings.c_cc[VTIME] = 0; //0; /* Wait indefinetly   */
    SerialPortSettings.c_lflag = 0;


    if ((tcsetattr(handler, TCSANOW, &SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
        printf("\n  ERROR ! in setting attributes\n");
    else
        printf("\n  BaudRate = %u \n  StopBits = 1 \n  Parity   = none \n", baud);

    tcflush(handler, TCIFLUSH);   /* Discards old data in the rx buffer            */
}

// COMMUNICATION

uint32_t Cophee::read_serial (uint32_t address) const
{
    usleep (100);
    uint32_t bytes_written, bytes_read, read_buffer;
    uint32_t rdstring       = 0x4D4D4D4D;

    uint32_t * ptr           = &rdstring;
    uint32_t * addptr        = &address;
    uint32_t * rdptr         = &read_buffer;
    bytes_written = write(handler, ptr, 4);
    bytes_written = write(handler, addptr, 4);
    bytes_read  = read(handler, rdptr, 4);

    return *rdptr ;
}

vector<uint32_t> Cophee::read_serial_n(uint32_t address, size_t size) const
{
    vector<uint32_t> arr(size);
    uint32_t addr_loc ;
    for (size_t i = 0 ; i < size; i++)
    {
        addr_loc = address + i * 0x4 ;
        arr[i] = read_serial(addr_loc);
    }
    return arr;
}

vector<uint32_t> Cophee::read_serial_1x (uint32_t address) const
{
    return read_serial_n(address, 32);
}

vector<uint32_t> Cophee::read_serial_2x (uint32_t address) const
{
    return read_serial_n(address, 64);
}

void Cophee::write_serial (uint32_t address, uint32_t data) const
{
    uint32_t bytes_written;
    uint32_t write_buffer   = data;
    uint32_t wrstring       = 0x34343434;

    uint32_t * ptr       = &wrstring;
    uint32_t * addptr    = &address;
    uint32_t * wrptr     = &data;

    bytes_written   = write(handler, ptr, 4);
    bytes_written   = write(handler, addptr, 4);
    bytes_written   = write(handler, wrptr, 4);
}

void Cophee::write_serial_n (uint32_t address, const vector<uint32_t> & data, size_t size) const
{
    uint32_t addr_loc, data_loc;
    if ( data.size() < size ) throw "Invalid vector size during CoPHEE write";
    for (size_t i = 0 ; i < size; i++)
    {
        addr_loc = address + i * 0x4;
        data_loc = data[i] ;
        write_serial (addr_loc, data_loc);
    }
}

void Cophee::write_serial_1x (uint32_t address, const vector<uint32_t> & data) const
{
    write_serial_n(address, data, 32);
}

void Cophee::write_serial_2x (uint32_t address, const vector<uint32_t> & data) const
{
    write_serial_n(address, data, 64);
}

// FUNCTIONS

bool Cophee::is_params_set() const
{
    return isParamsSet;
}

void Cophee::set_params(
    const std::vector<uint32_t> & n,
    const std::vector<uint32_t> & n2,
    const std::vector<uint32_t> & fkf
) const
{
    write_serial_1x (GPCFG_N_ADDR0, cleq_N);
    write_serial_2x (GPCFG_NSQ_ADDR0, cleq_NSQ);
    write_serial_2x (GPCFG_FKF_ADDR0, cleq_fkf);
    isParamsSet = true;
}

void Cophee::set_params(
    const std::vector<uint32_t> & n,
    const std::vector<uint32_t> & n2,
    const std::vector<uint32_t> & rand0,
    const std::vector<uint32_t> & rand1,
    const std::vector<uint32_t> & fkf
) const
{
    write_serial_1x (GPCFG_N_ADDR0, cleq_N);
    write_serial_1x (GPCFG_RAND0_ADDR0, cleq_rand0);
    write_serial_1x (GPCFG_RAND1_ADDR0, cleq_rand1);
    write_serial_2x (GPCFG_NSQ_ADDR0, cleq_NSQ);
    write_serial_2x (GPCFG_FKF_ADDR0, cleq_fkf);
    isParamsSet = true;
}

vector<uint32_t> Cophee::mod_mul (const std::vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000100);
    write_serial_2x (GPCFG_ARGA_ADDR0, a);
    write_serial_2x (GPCFG_ARGB_ADDR0, b);
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000001);

    wait_for_interrupt();

    auto result = read_serial_2x (GPCFG_MUL_ADDR0);
    write_serial (GPCFG_GPIO0_PAD_CTL, 0x0111001A);
    return result;
}

vector<uint32_t> Cophee::mod_exp (const std::vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000100);
    write_serial_2x (GPCFG_ARGA_ADDR0, a);
    write_serial_2x (GPCFG_ARGB_ADDR0, b);
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000002);

    wait_for_interrupt();

    auto result = read_serial_2x (GPCFG_EXP_ADDR0);
    write_serial (GPCFG_GPIO0_PAD_CTL, 0x0111001A);
    return result;
}

vector<uint32_t> Cophee::mod_inv (const std::vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000100);
    write_serial_2x (GPCFG_ARGA_ADDR0, a);
    write_serial_2x (GPCFG_ARGB_ADDR0, b);
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000004);

    wait_for_interrupt();

    auto error = read_serial(GPCFG_CLSTATUS_ADDR);
    if (error != 0x1) return read_serial_2x (GPCFG_INV_ADDR0);
    return vector<uint32_t>();
}

vector<uint32_t> Cophee::gfunc (const vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000100);
    write_serial_2x (GPCFG_ARGA_ADDR0, a);
    write_serial_2x (GPCFG_ARGB_ADDR0, b);
    write_serial    (GPCFG_CLCTLP_ADDR, 0x00000008);

    wait_for_interrupt();

    return read_serial_2x (GPCFG_RES_ADDR0);
}

void Cophee::wait_for_interrupt () const
{
    if (isUsingArduino)
    {
        char buf[2] = {0};
        uint32_t count;
        do { count = read(handlerArduino, buf, 1); }
        while (count == 0);
    }
    else sleep (1);
}

} // cophee

} // e3
