#pragma once

#include <string>

class AnyKey
{
    protected:
        std::string name;

    public:
        AnyKey(std::string nm) : name(nm) {}
        virtual std::string filename() = 0;
};