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

SKDIR=cpp_cgt/keys
EKDIR=cpp_share/keys
CRDIR=cpp_crcl/cr
CUDIR=cpp_crcl/d$(CUDD)


OPTU = $(OPTS) -I.
OPTS += -I./$(CRDIR)/
OPTS += -I./$(CUDIR)/
OPTS += -I./cpp_cgt/main/
OPTS += -I./cpp_cgt/util/
OPTS += -I./cpp_share/util/
OPTS += -I./${SKDIR}/
OPTS += -I./${EKDIR}/
OPTS += -I./${USER}/


include mak_mod_inc.mak


all: $(BIN) alice.exe # execute

execute: alice.exe cgt.exe
	./alice.exe | ./cgt.exe dec -c $(CGT) -s ${BITSIZE}

#	./alice.exe

$(BIN):
	mkdir -p $(BIN)

alice.exe: $(BIN) $(USER)/* secint.h secint.inc $(BIN)/secint.$(OEXT) \
	$(LDF2) $(BIN)/cgtkey.$(OEXT) $(BIN)/cgtshared.$(OEXT)
	@echo -n "Starting user code compilation: "
	@date
	$(CCT) $(OPTU) -DE3KEY=1 $(E3NOABORTMAK) $(USER)/*.cpp \
	$(BIN)/secint.$(OEXT) \
	$(BIN)/cgtkey.$(OEXT) $(BIN)/cgtshared.$(OEXT) \
	$(LDF2) $(LDF3) $(LDFS) $(EOUT)$@
	@echo -n "Finished user code compilation: "
	@date
	rm -f *.$(OEXT)
	@$(COPYDLL2)


cgt.exe:
	echo build cgt.exe


cgtshared.cpp: cpp_share/util/*.*  cpp_share/keys/*.* amalgam.sh
	bash amalgam.sh

cgtkey.cpp: cpp_cgt/util/*.*  cpp_cgt/keys/*.* amalkey.sh
	bash amalkey.sh

$(BIN)/cgtshared.$(OEXT): cgtshared.cpp $(BIN) 
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(BIN)/cgtkey.$(OEXT): cgtkey.cpp $(BIN) 
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


$(BIN)/secint.$(OEXT): secint.cpp cgtshared.cpp
	@echo -n "Starting secint compilation: "
	@date
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $(E3NOABORTMAK) $< $(OOUT)$@
	@echo -n "Finished secint compilation: "
	@date

${SKDIR}/sk_circ_tfhe.cpp: ${SKDIR}/sk_circ_tfhe0.cpp ${SKDIR}/sk_circ_tfhe1.cpp

##$(objcr): $(BIN)/%.$(OEXT):$(CRDIR)/%.cpp $(CRDIR)/*.h
##	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(BIN)/cuddObj.$(OEXT): $(CUDIR)/cuddObj.cc
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

