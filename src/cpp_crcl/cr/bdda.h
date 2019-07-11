#pragma once

#include "olc.h"
#include "crcl.h"

void writeBDD(string file, const Module & prog, bool dot, bool reord);

int cudd_impl(); // returns 0 or 1

