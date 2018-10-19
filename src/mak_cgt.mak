# E3 main makefile, 2018

##TFHE=0

include plat.mak
include plat_$(PLAT).mak

BIN=$(BINN)

SKDIR=cpp_cgt/keys
EKDIR=cpp_share/keys

OPTS += -I./cpp_cgt/main/
OPTS += -I./cpp_cgt/util/
OPTS += -I./cpp_share/util/
OPTS += -I./${SKDIR}/
OPTS += -I./${EKDIR}/


ifeq ($(TFHE),1)
OPTS += -I./$(TFHED0)/inc/tfhe
OPTS += -I./$(TFHED0)/inc/fftwa
OPTS += -I./$(TFHED0)/inc/fftw3
endif

ifeq ($(FHEW),1)
OPTS += -I./$(FHEWD0)/inc/fhew
OPTS += -I./$(FHEWD0)/inc/fftwa
OPTS += -I./$(FHEWD0)/inc/fftw3
endif

ifeq ($(HELI),1)
OPTS += -I./$(HELID0)/src
endif

srcl=cpp_cgt/main/cgt.cpp cpp_cgt/main/cfgparser.cpp \
	cpp_cgt/main/sec_circuit.cpp cpp_cgt/main/sectype.cpp \
	cpp_cgt/main/sec_native.cpp cpp_cgt/main/cloparser.cpp
objl := $(srcl:cpp_cgt/main/%.cpp=$(BIN)/%.$(OEXT))

srcu1=cpp_cgt/util/os_filesys.cpp cpp_cgt/util/ol.cpp cpp_cgt/util/util.cpp \
	cpp_cgt/util/cgtrnd.cpp
obju1 := $(srcu1:cpp_cgt/util/%.cpp=$(BIN)/%.$(OEXT))

srcu2=cpp_share/util/e3util.cpp \
	cpp_share/util/def_tfhe$(TFHE).cpp \
	cpp_share/util/def_fhew$(FHEW).cpp \
	cpp_share/util/def_heli$(HELI).cpp \
	cpp_share/util/base64.cpp
obju2 := $(srcu2:cpp_share/util/%.cpp=$(BIN)/%.$(OEXT))

srcp=cpp_cgt/util/$(PLAT)/os_file2.cpp
objp := $(srcp:cpp_cgt/util/$(PLAT)/%.cpp=$(BIN)/%.$(OEXT))

srck1= ${SKDIR}/sk_native.cpp ${SKDIR}/ekx_native.cpp \
	${SKDIR}/sk_circ_plain.cpp ${SKDIR}/sk_abstract.cpp \
	${SKDIR}/ekx_circ_plain.cpp \
	${SKDIR}/sk_circ_tfhe$(TFHE).cpp ${SKDIR}/ekx_circ_tfhe$(TFHE).cpp \
	${SKDIR}/sk_circ_fhew$(FHEW).cpp ${SKDIR}/ekx_circ_fhew$(FHEW).cpp \
	${SKDIR}/sk_circ_heli$(HELI).cpp ${SKDIR}/ekx_circ_heli$(HELI).cpp \
	${SKDIR}/sk_circ.cpp
objk1 := $(srck1:${SKDIR}/%.cpp=$(BIN)/%.$(OEXT))

srck2= ${EKDIR}/ek_abstract.cpp ${EKDIR}/ek_native.cpp \
	${EKDIR}/ek_circ_plain.cpp \
	${EKDIR}/ek_circ_tfhe$(TFHE).cpp \
	${EKDIR}/ek_circ_fhew$(FHEW).cpp \
	${EKDIR}/ek_circ_heli$(HELI).cpp \
	${EKDIR}/ek_circ.cpp
objk2 := $(srck2:${EKDIR}/%.cpp=$(BIN)/%.$(OEXT))


all: $(BIN) cgt.exe

$(BIN):
	mkdir -p $(BIN)

cgt.exe: $(BIN) $(objl) $(obju2) $(obju1) $(objp) $(objk1) $(objk2) $(LDF1)
	$(CCN) $(OPTS) $(objl) $(obju2) $(obju1) $(objp) \
	$(objk1) $(objk2) $(LDF1) $(LDF3) $(EOUT)$@
	@$(COPYDLL1)

$(objl): $(BIN)/%.$(OEXT):cpp_cgt/main/%.cpp cpp_cgt/main/*.h \
	${SKDIR}/*.h ${EKDIR}/*.h cpp_cgt/util/*.h cpp_share/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(obju1): $(BIN)/%.$(OEXT):cpp_cgt/util/%.cpp cpp_cgt/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(obju2): $(BIN)/%.$(OEXT):cpp_share/util/%.cpp cpp_share/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objp): $(BIN)/%.$(OEXT):cpp_cgt/util/$(PLAT)/%.cpp cpp_cgt/main/*.h \
	cpp_cgt/util/*.h cpp_share/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objk1): $(BIN)/%.$(OEXT):${SKDIR}/%.cpp cpp_cgt/main/*.h ${SKDIR}/*.h ${EKDIR}/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


$(objk2): $(BIN)/%.$(OEXT):${EKDIR}/%.cpp cpp_cgt/main/*.h ${EKDIR}/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

clean:
	rm -rf cgt.exe *.o *.obj bn_* bt_*
