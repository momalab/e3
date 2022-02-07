// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>

#include "e3int.h"
using Secure = NativeInt<64>;
//using Secure = NativeUint<32>;
using Secure2 = Native2Int<16>;

using Pil = PilUint<8>;

Secure f(Secure, Secure);
Secure2 g(Secure2, Secure2);
