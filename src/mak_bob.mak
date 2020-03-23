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

##SKDIR=cpp_cgt/keysXXX # Bob - no access to SK
##EKDIR=cpp_share/keys

OPTU = $(OPTS) -I./
##OPTS += -I./cpp_share/util/
##OPTS += -I./${EKDIR}/

OPTS += -I./${USER}/


include mak_mod_inc.mak


##srcl=cpp_cgt/main/cgt.cpp cpp_cgt/main/cfgparser.cpp \
##	cpp_cgt/main/sec_circuit.cpp cpp_cgt/main/sectype.cpp \
##	cpp_cgt/main/sec_native.cpp
##objl := $(srcl:cpp_cgt/main/%.cpp=$(BIN)/%.$(OEXT))

srcp=cpp_cgt/util/$(PLAT)/os_file2.cpp
objp := $(srcp:cpp_cgt/util/$(PLAT)/%.cpp=$(BIN)/%.$(OEXT))



all: $(BIN) bob.exe # execute

execute: bob.exe cgt.exe
	./bob.exe | ./cgt.exe dec -c $(CGT) -s ${BITSIZE}

#	./bob.exe

$(BIN):
	mkdir -p $(BIN)


bob.exe: $(USER)/* secint.h secint.inc $(BIN)/secint.$(OEXT) \
	$(BIN)/cgtshared.$(OEXT) $(E3X)/e3x.$(OEXT) $(LDF2)
	@echo -n "Starting user code compilation: "
	@date
	$(CCT) $(OPTU) $(E3NOABORTMAK) $(USER)/*.cpp $(BIN)/secint.$(OEXT) \
	$(BIN)/cgtshared.$(OEXT) $(E3X)/e3x.$(OEXT) $(LDF2) \
	$(LDF3) $(EOUT)$@
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
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@
	@echo -n "(mak_bob) Finished secint compilation: "
	@date

$(BIN)/cgtshared.$(OEXT): cgtshared.cpp $(BIN) 
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


$(E3X)/e3x.$(OEXT): $(E3X)/e3x.c
	cd $(E3X); make
