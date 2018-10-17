// === BEGIN atop.h
// FIXME e add info on cgt version, libraries included, and config used;
// also list all classes generated
// this info must go at the very beginning of secint.h
// .inc and .cpp should also be tagged by unique ID referenced to .h
// so the user does not mix different gen builds

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

#include "e3util.h"
///#include "base64.h"
#include "evalkeys.h"

template <class T, class N = T> void initEvalKey(std::string name, T *& pek, T *& gpek);

template <class T> T multiply_by_ull(unsigned long long u, const T & x);

// === END atop.h
