// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdint>
#include <cstddef>
#include <vector>

using std::uint32_t;

namespace e3
{

namespace cophee
{

class Cophee
{
    private:
        static int handler;
        static int handlerArduino;
        static int baudRate;
        static bool inited;
        static bool isUsingArduino;
        static bool isParamsSet;

        void init();
        void init_arduino();
        void init_chip();
        void init_port();
        void init_port_baud(uint32_t baud);

        uint32_t read_serial (uint32_t address) const;
        std::vector<uint32_t> read_serial_n  (uint32_t address, size_t size) const;
        std::vector<uint32_t> read_serial_1x (uint32_t address) const;
        std::vector<uint32_t> read_serial_2x (uint32_t address) const;

        void write_serial (uint32_t address, uint32_t data) const;
        void write_serial_n  (uint32_t address, const std::vector<uint32_t> & data, size_t size) const;
        void write_serial_1x (uint32_t address, const std::vector<uint32_t> & data) const;
        void write_serial_2x (uint32_t address, const std::vector<uint32_t> & data) const;

        void wait_for_interrupt() const;

    public:
        Cophee() : Cophee(true) {}
        Cophee(int baudRate) : Cophee(baudRate, false) {}
        Cophee(int baudRate, bool isUsingArduino);
        Cophee(const Cophee & a) : Cophee(a.baudRate, a.isUsingArduino) {}

        bool is_params_set() const;
        void set_params(const std::vector<uint32_t> & n, const std::vector<uint32_t> & n2,
                        const std::vector<uint32_t> & fkf) const;
        void set_params(const std::vector<uint32_t> & n, const std::vector<uint32_t> & n2,
                        const std::vector<uint32_t> & rand0, const std::vector<uint32_t> & rand1,
                        const std::vector<uint32_t> & fkf) const;
        std::vector<uint32_t> mod_mul (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
        std::vector<uint32_t> mod_exp (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
        std::vector<uint32_t> mod_inv (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
        std::vector<uint32_t> gfunc   (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
};

} // cophee

} // e3
