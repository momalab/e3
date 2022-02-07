// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>

#include "ek_circ_bdd.h"

bool e3::CircuitEvalKey_bdd::load() { return true; }

std::string e3::CircuitEvalKey_bdd::filename() const { return EvalKey::filename(); }

