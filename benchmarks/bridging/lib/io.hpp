#pragma once

#include <functional>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "e3int.h"
#include "e3key.h"

template <class T> std::string e3::decrypt(int a) { return std::to_string(a); }
template <class T> void print(const T & e, std::function<string(T)> f = &e3::decrypt<T>);
template <class T> void print(const std::vector<T> & v, std::function<std::string(T)> f = &e3::decrypt<T>);
template <class T> void print(const std::vector<std::vector<T>> & m, std::function<std::string(T)> f = &e3::decrypt<T>);
template <class T> std::string scientificNotation(const T & n);
template <class T> void write(const T & e);
template <class T> void write(const std::vector<T> & v);

template <class T>
void print(const T & e, std::function<std::string(T)> f)
{
    std::cout << f(e) << '\n';
}

template <class T>
void print(const std::vector<T> & v, std::function<std::string(T)> f)
{
    std::cout << "{ ";
    for (auto & e : v) std::cout << f(e) << ' ';
    std::cout << "}\n";
}

template <class T>
void print(const std::vector<std::vector<T>> & m, std::function<std::string(T)> f)
{
    for (auto & v : m) print(v);
    std::cout << "\n";
}

template <class T>
std::string scientificNotation(const T & n)
{
    double m = n;
    int e = 0;
    while (m > 10)
    {
        m /= 10;
        e++;
    }
    return std::to_string(m) + "E+" + std::to_string(e);
}

template <class T> void write(const T & e)
{
    std::ofstream fout("dummy.tmp");
    fout << e << '\n';
}

template <class T> void write(const std::vector<T> & v)
{
    if (!v.empty()) write(v[0]);
}
