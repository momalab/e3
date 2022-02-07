// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// Not using MPIR library
// Not using CophEE hardware

#include <vector>
#include "cophee.h"

using std::vector;

namespace e3
{

namespace cophee
{

int Cophee::handler = -1;
int Cophee::handlerArduino = -1;
int Cophee::baudRate = 0;
bool Cophee::inited = false;
bool Cophee::isUsingArduino = false;

Cophee::Cophee(int baudRate, bool isUsingArduino)
{
    Cophee::baudRate = baudRate;
    Cophee::isUsingArduino = isUsingArduino;
}

void Cophee::init() { }

void Cophee::init_arduino()
{
    throw "Cophee: 'init_arduino' shouldn't be called";
}

void Cophee::init_chip()
{
    throw "Cophee: 'init_chip' shouldn't be called";
}

void Cophee::init_port()
{
    throw "Cophee: 'init_port' shouldn't be called";
}

void Cophee::init_port_baud (uint32_t baud)
{
    throw "Cophee: 'init_port_baud' shouldn't be called";
}

uint32_t Cophee::read_serial (uint32_t address) const
{
    throw "Cophee: 'read_serial' shouldn't be called";
}

vector<uint32_t> Cophee::read_serial_n(uint32_t address, size_t size) const
{
    throw "Cophee: 'read_serial_n' shouldn't be called";
}


vector<uint32_t> Cophee::read_serial_1x (uint32_t address) const
{
    throw "Cophee: 'read_serial_1x' shouldn't be called";
}

vector<uint32_t> Cophee::read_serial_2x (uint32_t address) const
{
    throw "Cophee: 'read_serial_2x' shouldn't be called";
}

void Cophee::write_serial (uint32_t address, uint32_t data) const
{
    throw "Cophee: 'write_serial' shouldn't be called";
}

void Cophee::write_serial_n (uint32_t address, const vector<uint32_t> & data, size_t size) const
{
    throw "Cophee: 'write_serial_n' shouldn't be called";
}

void Cophee::write_serial_1x (uint32_t address, const vector<uint32_t> & data) const
{
    throw "Cophee: 'write_serial_1x' shouldn't be called";
}

void Cophee::write_serial_2x (uint32_t address, const vector<uint32_t> & data) const
{
    throw "Cophee: 'write_serial_2x' shouldn't be called";
}

bool Cophee::is_params_set() const
{
    throw "Cophee: 'is_params_set' shouldn't be called";
}

void Cophee::set_params(
    const std::vector<uint32_t> & n,
    const std::vector<uint32_t> & n2,
    const std::vector<uint32_t> & fkf
) const
{
    throw "Cophee: 'set_params' shouldn't be called";
}

void Cophee::set_params(
    const std::vector<uint32_t> & n,
    const std::vector<uint32_t> & n2,
    const std::vector<uint32_t> & rand0,
    const std::vector<uint32_t> & rand1,
    const std::vector<uint32_t> & fkf
) const
{
    throw "Cophee: 'set_params' shouldn't be called";
}

vector<uint32_t> Cophee::mod_mul (const vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    throw "Cophee: 'mod_mul' shouldn't be called";
}

vector<uint32_t> Cophee::mod_exp (const vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    throw "Cophee: 'mod_exp' shouldn't be called";
}

vector<uint32_t> Cophee::mod_inv (const vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    throw "Cophee: 'mod_inv' shouldn't be called";
}

vector<uint32_t> Cophee::gfunc (const vector<uint32_t> & a, const vector<uint32_t> & b) const
{
    throw "Cophee: 'gfunc' shouldn't be called";
}

void Cophee::wait_for_interrupt () const
{
    throw "Cophee: 'wait_for_interrupt' shouldn't be called";
}

} // cophee

} // e3
