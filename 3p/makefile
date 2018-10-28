
ifeq ($(OS),Windows_NT)
PLAT=win
else
PLAT=unx
endif

TFHEBIN=tfhe_$(PLAT)

all:
	@echo "make TFHE|FHEW|HELI"

TFHE:
	sh tfhe_$(PLAT).sh

FHEW:
	sh fhew_$(PLAT).sh

HELI:
	sh heli_$(PLAT).sh


clean:
	rm -rf tfhe_win tfhe_unx fhew_win fhew_unx heli_win heli_unx
