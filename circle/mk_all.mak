# Hasq Technology Pty Ltd (C) 2013-2016

ifeq ($(OS),Windows_NT)
PLAT=win
else
PLAT=unx
endif

BINR=$(PLAT)
TRG=_bin_$(BINR)

include $(SRC)mk_$(PLAT).mak

