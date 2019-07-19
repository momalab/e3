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


srcl=cpp_cgt/main/cgt.cpp cpp_cgt/main/cfgparser.cpp \
	cpp_cgt/main/sec_circuit.cpp cpp_cgt/main/sectype.cpp \
	cpp_cgt/main/sec_native.cpp
objl := $(srcl:cpp_cgt/main/%.cpp=$(BIN)/%.$(OEXT))

##srcu1=cpp_cgt/util/os_filesys.cpp cpp_cgt/util/ol.cpp cpp_cgt/util/util.cpp \
##	cpp_cgt/util/cgtrnd.cpp
##obju1 := $(srcu1:cpp_cgt/util/%.cpp=$(BIN)/%.$(OEXT))

##srcu2=cpp_share/util/e3util.cpp \
##	cpp_share/util/def_tfhe$(TFHE).cpp \
##	cpp_share/util/def_fhew$(FHEW).cpp \
##	cpp_share/util/def_heli$(HELI).cpp \
##	cpp_share/util/base64.cpp
##obju2 := $(srcu2:cpp_share/util/%.cpp=$(BIN)/%.$(OEXT))

srcp=cpp_cgt/util/$(PLAT)/os_file2.cpp
objp := $(srcp:cpp_cgt/util/$(PLAT)/%.cpp=$(BIN)/%.$(OEXT))

##srck2= ${EKDIR}/ek_abstract.cpp ${EKDIR}/ek_native.cpp \
##	${EKDIR}/ek_circ_plain.cpp \
##	${EKDIR}/ek_circ_tfhe$(TFHE).cpp \
##	${EKDIR}/ek_circ_fhew$(FHEW).cpp \
##	${EKDIR}/ek_circ_heli$(HELI).cpp \
##	${EKDIR}/ek_circ_bdd.cpp \
##	${EKDIR}/ek_circ.cpp
##objk2 := $(srck2:${EKDIR}/%.cpp=$(BIN)/%.$(OEXT))

# srck2 objk2
#include mak_mod_ek.mak


#all: $(BIN) bob.exe # execute
all: bob.exe # execute

execute: bob.exe cgt.exe
	./bob.exe | ./cgt.exe dec -c $(CGT) -s ${BITSIZE}

#	./bob.exe

# $(BIN):
# 	mkdir -p $(BIN)

# bob.exe: $(BIN) $(USER)/* secint.h secint.inc $(BIN)/secint.$(OEXT) $(E3X)/e3x.$(OEXT) \
# 	$(objk2) $(obju2) $(LDF2)
# 	@echo -n "Starting user code compilation: "
# 	@date
# 	$(CCT) $(OPTU) $(USER)/*.cpp $(BIN)/secint.$(OEXT) $(objk2) $(obju2) \
# 	$(E3X)/e3x.$(OEXT) $(LDF2) $(LDF3) $(EOUT)$@
# 	@echo -n "Finished user code compilation: "
# 	@date
# 	rm -f *.$(OEXT)
# 	@$(COPYDLL2)

bob.exe: $(USER)/* secint.h secint.inc secint.cpp cgtshared.cpp $(E3X)/e3x.$(OEXT) $(LDF2)
	@echo -n "Starting user code compilation: "
	@date
	$(CCT) $(OPTU) $(USER)/*.cpp secint.cpp cgtshared.cpp \
	$(E3X)/e3x.$(OEXT) $(LDF2) $(LDF3) $(EOUT)$@
	@echo -n "Finished user code compilation: "
	@date
	rm -f *.$(OEXT)
	@$(COPYDLL2)

cgt.exe:
	echo build cgt.exe

cgtshared.cpp: cpp_share/util/*.*  cpp_share/keys/*.*
	bash amalgam.sh

$(BIN)/secint.$(OEXT): secint.cpp cgtshared.cpp
	@echo -n "Starting secint compilation: "
	@date
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@
	@echo -n "Finished secint compilation: "
	@date

##$(objl): $(BIN)/%.$(OEXT):cpp_cgt/main/%.cpp cpp_cgt/main/*.h \
##	${SKDIR}/*.h ${EKDIR}/*.h cpp_cgt/util/*.h cpp_share/util/*.h
##	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


##$(obju2): $(BIN)/%.$(OEXT):cpp_share/util/%.cpp cpp_share/util/*.h
##	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

##$(objp): $(BIN)/%.$(OEXT):cpp_cgt/util/$(PLAT)/%.cpp cpp_cgt/main/*.h \
##	cpp_cgt/util/*.h cpp_share/util/*.h
##	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


##${SKDIR}/sk_circ_tfhe.cpp: ${SKDIR}/sk_circ_tfhe0.cpp ${SKDIR}/sk_circ_tfhe1.cpp
##${SKDIR}/sk_circ_seal.cpp: ${SKDIR}/sk_circ_seal0.cpp ${SKDIR}/sk_circ_seal1.cpp


$(objk2): $(BIN)/%.$(OEXT):${EKDIR}/%.cpp cpp_cgt/main/*.h ${EKDIR}/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(E3X)/e3x.$(OEXT): $(E3X)/e3x.c
	cd $(E3X); make
