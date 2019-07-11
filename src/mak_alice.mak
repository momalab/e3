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


OPTU = $(OPTS) -I./
OPTS += -I./$(CRDIR)/
OPTS += -I./$(CUDIR)/
OPTS += -I./cpp_cgt/main/
OPTS += -I./cpp_cgt/util/
OPTS += -I./cpp_share/util/
OPTS += -I./${SKDIR}/
OPTS += -I./${EKDIR}/


include mak_mod_inc.mak



#srcl=cpp_cgt/main/cgt.cpp cpp_cgt/main/cfgparser.cpp cpp_cgt/main/platname.cpp \
#	cpp_cgt/main/sec_circuit.cpp cpp_cgt/main/sectype.cpp \
#	cpp_cgt/main/sec_native.cpp cpp_cgt/main/cloparser.cpp
srcl=cpp_cgt/main/platname.cpp
objl := $(srcl:cpp_cgt/main/%.cpp=$(BIN)/%.$(OEXT))

##srcu1=cpp_cgt/util/os_filesys.cpp cpp_cgt/util/cgtutil.cpp cpp_cgt/util/timer.cpp
##obju1 := $(srcu1:cpp_cgt/util/%.cpp=$(BIN)/%.$(OEXT))

srccir = olc.cpp olrnd.cpp bbs.cpp crcl.cpp gram.cpp \
	simp.cpp crutil.cpp vars.cpp prep.cpp bdda.cpp
srccr := $(srccir:%.cpp=$(CRDIR)/%.cpp)
objcr := $(srccir:%.cpp=$(BIN)/%.$(OEXT))


##srcu2=cpp_share/util/e3util.cpp \
##	cpp_share/util/def_tfhe$(TFHE).cpp \
##	cpp_share/util/def_fhew$(FHEW).cpp \
##	cpp_share/util/def_heli$(HELI).cpp \
##	cpp_share/util/base64.cpp
##obju2 := $(srcu2:cpp_share/util/%.cpp=$(BIN)/%.$(OEXT))

srcp=cpp_cgt/util/$(PLAT)/os_file2.cpp
objp := $(srcp:cpp_cgt/util/$(PLAT)/%.cpp=$(BIN)/%.$(OEXT))

##srck1= ${SKDIR}/sk_native.cpp ${SKDIR}/ekx_native.cpp \
##	${SKDIR}/sk_circ_plain.cpp ${SKDIR}/sk_abstract.cpp \
##	${SKDIR}/ekx_circ_plain.cpp \
##	${SKDIR}/sk_circ_tfhe$(TFHE).cpp ${SKDIR}/ekx_circ_tfhe$(TFHE).cpp \
##	${SKDIR}/sk_circ_fhew$(FHEW).cpp ${SKDIR}/ekx_circ_fhew$(FHEW).cpp \
##	${SKDIR}/sk_circ_heli$(HELI).cpp ${SKDIR}/ekx_circ_heli$(HELI).cpp \
##	${SKDIR}/sk_circ_bdd.cpp ${SKDIR}/ekx_circ_bdd.cpp \
##	${SKDIR}/sk_circ.cpp
##objk1 := $(srck1:${SKDIR}/%.cpp=$(BIN)/%.$(OEXT))

# srck1 objk1
include mak_mod_sk.mak

##srck2= ${EKDIR}/ek_abstract.cpp ${EKDIR}/ek_native.cpp \
##	${EKDIR}/ek_circ_plain.cpp \
##	${EKDIR}/ek_circ_tfhe$(TFHE).cpp \
##	${EKDIR}/ek_circ_fhew$(FHEW).cpp \
##	${EKDIR}/ek_circ_heli$(HELI).cpp \
##	${EKDIR}/ek_circ_bdd.cpp \
##	${EKDIR}/ek_circ.cpp
##objk2 := $(srck2:${EKDIR}/%.cpp=$(BIN)/%.$(OEXT))

# srck2 objk2
include mak_mod_ek.mak



all: $(BIN) alice.exe # execute

execute: alice.exe cgt.exe
	./alice.exe | ./cgt.exe dec -c $(CGT) -s ${BITSIZE}

#	./alice.exe

$(BIN):
	mkdir -p $(BIN)

alice.exe: $(BIN) $(USER)/* secint.h secint.inc $(BIN)/secint.$(OEXT) $(E3X)/e3x.$(OEXT) $(objl) \
	$(objk2) $(obju2) $(objk1) $(obju1) $(LDF2) $(objp) $(objcr) $(BIN)/cuddObj.$(OEXT)
	@echo -n "Starting user code compilation: "
	@date
	$(CCT) $(OPTU) -DE3ALICE=1 $(USER)/*.cpp $(BIN)/secint.$(OEXT) $(objk2) $(obju2) \
	$(objp) $(objk1) $(obju1) $(objcr) $(objl) $(BIN)/cuddObj.$(OEXT) $(E3X)/e3x.$(OEXT) \
	$(LDF2) $(LDF3) $(EOUT)$@
	@echo -n "Finished user code compilation: "
	@date
	rm -f *.$(OEXT)
	@$(COPYDLL2)


cgt.exe:
	echo build cgt.exe

#$(LDFDLLLOC): $(LDFDLLREM)
#	cp $< $@

$(BIN)/secint.$(OEXT): secint.cpp
	@echo -n "Starting secint compilation: "
	@date
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@
	@echo -n "Finished secint compilation: "
	@date

$(objl): $(BIN)/%.$(OEXT):cpp_cgt/main/%.cpp cpp_cgt/main/*.h \
	${SKDIR}/*.h ${EKDIR}/*.h cpp_cgt/util/*.h cpp_share/util/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(obju1): $(BIN)/%.$(OEXT):cpp_cgt/util/%.cpp cpp_cgt/util/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(obju2): $(BIN)/%.$(OEXT):cpp_share/util/%.cpp cpp_share/util/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objp): $(BIN)/%.$(OEXT):cpp_cgt/util/$(PLAT)/%.cpp cpp_cgt/main/*.h \
	cpp_cgt/util/*.h cpp_share/util/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objk1): $(BIN)/%.$(OEXT):${SKDIR}/%.cpp cpp_cgt/main/*.h ${SKDIR}/*.h ${EKDIR}/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

${SKDIR}/sk_circ_tfhe.cpp: ${SKDIR}/sk_circ_tfhe0.cpp ${SKDIR}/sk_circ_tfhe1.cpp
${SKDIR}/sk_circ_seal.cpp: ${SKDIR}/sk_circ_seal0.cpp ${SKDIR}/sk_circ_seal1.cpp

$(objk2): $(BIN)/%.$(OEXT):${EKDIR}/%.cpp cpp_cgt/main/*.h ${EKDIR}/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(E3X)/e3x.$(OEXT): $(E3X)/e3x.c
	cd $(E3X); make

$(objcr): $(BIN)/%.$(OEXT):$(CRDIR)/%.cpp $(CRDIR)/*.h
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(BIN)/cuddObj.$(OEXT): $(CUDIR)/cuddObj.cc
	$(CCT) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@
