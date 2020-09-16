PLAT=unx

ifneq (,$(wildcard macos))
PLAT=mac
endif

ifdef OS

ifeq ($(OS),Windows_NT)
PLAT=win
endif

else
#PLAT=unx
 ifdef MACHTYPE
 ifneq (,$(findstring apple,$(MACHTYPE)))
 PLAT=mac
 endif
 endif
endif

BINN=bn_$(PLAT)
BINT=bt_$(PLAT)

CUDD=0
FHEW=0
HELI=0
MPIR=0
SEAL=0
TFHE=0


FHEWD0=../3p/fhew_$(PLAT)
HELID0=../3p/heli_$(PLAT)
MPIRD0=../3p/mpir_$(PLAT)
SEALD0=../3p/seal_$(PLAT)
TFHED0=../3p/tfhe_$(PLAT)

$(info $(PLAT))
