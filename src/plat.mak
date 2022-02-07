# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
PLAT=unx

ifdef OS

ifeq ($(OS),Windows_NT)
PLAT=win

 ifdef MINGW_CHOST
 ifneq (,$(findstring mingw,$(MINGW_CHOST)))
 PLAT=mgw
 endif
 endif

endif

else
#PLAT=unx
 ifdef MACHTYPE
 ifneq (,$(findstring apple,$(MACHTYPE)))
 PLAT=mac
 endif
 endif
endif

ifneq (,$(wildcard macos))
PLAT=mac
endif

ifneq (,$(wildcard mingw))
PLAT=mgw
endif


BINN=bn_$(PLAT)
BINT=bt_$(PLAT)

CUDD=0
FHEW=0
HELI=0
MPIR=0
SEAL=0
TFHE=0
PALI=0


FHEWD0=../3p/fhew_$(PLAT)
HELID0=../3p/heli_$(PLAT)
MPIRD0=../3p/mpir_$(PLAT)
SEALD0=../3p/seal_$(PLAT)
TFHED0=../3p/tfhe_$(PLAT)
PALID0=../3p/pali_$(PLAT)

$(info $(PLAT))
