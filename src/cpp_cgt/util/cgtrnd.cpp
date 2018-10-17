#include <chrono>

#include "ol.h"
#include "util.h"
#include "cgtrnd.h"

util::Rnd::Rnd(const string & ss) :
    sseed(fseed(ss)), sq(sseed.begin(), sseed.end()),
    reng(sq), rdist(0, 1), idist(),
    rrnd( std::bind(rdist, reng) ), irnd( std::bind(idist, reng) )
{}

string util::Rnd::fseed(const string & sseed)
{
    if ( !sseed.empty() ) return sseed;
    auto now = std::chrono::system_clock::now();
    return ol::tos(std::chrono::system_clock::to_time_t(now));
}
