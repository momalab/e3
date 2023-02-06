#pragma once

#include <chrono>

namespace chron
{

struct Time_point
{
    std::chrono::steady_clock::time_point t;
    static Time_point now() { return Time_point {std::chrono::steady_clock::now()}; }

    unsigned long long gap(Time_point end) const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>
               (end.t - t).count();
        //std::chrono::duration_cast<std::chrono::microseconds>
        //std::chrono::duration_cast<std::chrono::nanoseconds>
    }
};

inline Time_point now() { return Time_point::now(); }
inline unsigned long long operator-(Time_point e, Time_point s) { return s.gap(e); }

} // chron

