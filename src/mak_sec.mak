# E3 main makefile, 2018

CGT=cgt.cfg

include plat.mak
include plat_$(PLAT).mak


SKDIR=cpp_cgt/keys
EKDIR=cpp_share/keys

all: secint.inc secint.cpp secint.h

secint.inc secint.cpp secint.h: cgt.exe $(CGT) $(USER)/* db/* db/templ/*
	./cgt.exe gen -c $(CGT) -d $(USER)

cgt.exe:
	echo build cgt.exe

