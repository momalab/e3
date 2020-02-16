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
        static bool inited;
        static bool isFasterUART;
        static bool isUsingArduino;

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
        Cophee() : Cophee(true) { }
        Cophee(bool isFasterUART) : Cophee(isFasterUART, false) {}
        Cophee(bool isFasterUART, bool isUsingArduino);
        Cophee(const Cophee & a) : Cophee(a.isFasterUART, a.isUsingArduino) {}

        std::vector<uint32_t> mod_mul (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
        std::vector<uint32_t> mod_exp (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
        std::vector<uint32_t> mod_inv (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
        std::vector<uint32_t> gfunc   (const std::vector<uint32_t> & a, const std::vector<uint32_t> & b) const;
};

} // cophee

} // e3
