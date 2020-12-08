
ifeq ($(OS),Windows_NT)
PLAT=win
else
PLAT=unx
endif

TFHEBIN=tfhe_$(PLAT)

all:
	@echo "make FHEW|HELI|MPIR|SEAL|TFHE"

FHEW:
	bash fhew_$(PLAT).sh

HELI:
	bash heli_$(PLAT).sh

MPIR:
	bash mpir_$(PLAT).sh

SEAL:
	bash seal_$(PLAT).sh

TFHE:
	bash tfhe_$(PLAT).sh

PALI:
	bash pali.sh

clean c:
	rm -rf fhew_win heli_win seal_win tfhe_win mpir_win pali_win
	rm -rf fhew_unx heli_unx seal_unx tfhe_unx mpir_unx pali_unx
	rm -rf fhew_mgw heli_mgw seal_mgw tfhe_mgw mpir_mgw pali_mgw
