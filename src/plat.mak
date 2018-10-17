
ifeq ($(OS),Windows_NT)
PLAT=win
else
PLAT=unx
endif

BINN=bn_$(PLAT)
BINT=bt_$(PLAT)

TFHE=0
FHEW=0
HELI=0

TFHED0=../3p/tfhe_$(PLAT)
FHEWD0=../3p/fhew_$(PLAT)
HELID0=../3p/heli_$(PLAT)
