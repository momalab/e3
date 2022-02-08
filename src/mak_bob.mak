# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
# E3 main makefile, 2018

USER=user/def
BITSIZE=64
CGT=$(USER)/cgt.cfg

include plat.mak
include plat_$(PLAT).mak

BIN=$(BINT)


E3X=e3x/openrisc
E3X=e3x/riscv
E3X=e3x/emulate

OPTU = $(OPTS) -I.

OPTS += -I./${USER}/


include mak_mod_inc.mak

##srcp=cpp_cgt/util/$(PLAT)/os_file2.cpp
##objp := $(srcp:cpp_cgt/util/$(PLAT)/%.cpp=$(BIN)/%.$(OEXT))



all: $(BIN) bob.exe # execute

execute: bob.exe cgt.exe
	./bob.exe | ./cgt.exe dec -c $(CGT) -s ${BITSIZE}

#	./bob.exe

$(BIN):
	mkdir -p $(BIN)


#bob.exe: $(USER)/* secint.h secint.inc $(BIN)/secint.$(OEXT) \
#	$(BIN)/cgtshared.$(OEXT) $(E3X)/e3x.$(OEXT) $(LDF2)
#	@echo -n "Starting user code compilation: "
#	@date
#	$(CCT) $(OPTU) $(E3NOABORTMAK) $(USER)/*.cpp $(BIN)/secint.$(OEXT) \
#	$(BIN)/cgtshared.$(OEXT) $(E3X)/e3x.$(OEXT) $(LDF2) \
#	$(LDF3) $(LDFS) $(EOUT)$@
#	@echo -n "Finished user code compilation: "
#	@date
#	rm -f *.$(OEXT)
#	@$(COPYDLL2)

bob.exe: $(USER)/* secint.h secint.inc $(BIN)/secint.$(OEXT) \
	$(BIN)/cgtshared.$(OEXT) $(LDF2)
	@echo -n "Starting user code compilation: "
	@date
	$(CCT) $(OPTU) $(E3NOABORTMAK) $(USER)/*.cpp $(BIN)/secint.$(OEXT) \
	$(BIN)/cgtshared.$(OEXT) $(LDF2) \
	$(LDF3) $(LDFS) $(EOUT)$@
	@echo -n "Finished user code compilation: "
	@date
	rm -f *.$(OEXT)
	@$(COPYDLL2)

cgt.exe:
	echo build cgt.exe

cgtshared.cpp: cpp_share/util/*.*  cpp_share/keys/*.*
	bash amalgam.sh

$(BIN)/secint.$(OEXT): secint.cpp cgtshared.cpp $(BIN) 
	@echo -n "(mak_bob) Starting secint compilation: "
	@date
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $(E3NOABORTMAK) $< $(OOUT)$@
	@echo -n "(mak_bob) Finished secint compilation: "
	@date

$(BIN)/cgtshared.$(OEXT): cgtshared.cpp $(BIN) 
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


$(E3X)/e3x.$(OEXT): $(E3X)/e3x.c
	cd $(E3X); make PLAT=$(PLAT)

