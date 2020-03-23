
ifeq ($(OS),Windows_NT)
PLAT=win
else
PLAT=unx
endif

TFHEBIN=tfhe_$(PLAT)

all:
	@echo "make FHEW|HELI|MPIR|SEAL|TFHE"

FHEW:
	sh fhew_$(PLAT).sh

HELI:
	sh heli_$(PLAT).sh

MPIR:
	sh mpir_$(PLAT).sh

SEAL:
	sh seal_$(PLAT).sh

TFHE:
	sh tfhe_$(PLAT).sh


clean:
	rm -rf fhew_win fhew_unx heli_win heli_unx seal_win seal_unx tfhe_win tfhe_unx mpir_win mapir_unx
