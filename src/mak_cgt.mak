# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
# E3 main makefile, 2018

include plat.mak
include plat_$(PLAT).mak

BIN=$(BINN)

SKDIR=cpp_cgt/keys
EKDIR=cpp_share/keys
CRDIR=cpp_crcl/cr
CUDIR=cpp_crcl/d$(CUDD)

OPTS += -I./$(CRDIR)/
OPTS += -I./$(CUDIR)/
OPTS += -I./cpp_cgt/main/
OPTS += -I./cpp_cgt/util/
OPTS += -I./cpp_share/util/
OPTS += -I./${SKDIR}/
OPTS += -I./${EKDIR}/


include mak_mod_inc.mak
include mak_mod_cu.mak

srccir = olc.cpp olrnd.cpp bbs.cpp crcl.cpp gram.cpp \
	simp.cpp crutil.cpp vars.cpp prep.cpp bdda.cpp
srccr := $(srccir:%.cpp=$(CRDIR)/%.cpp)
objcr := $(srccir:%.cpp=$(BIN)/%.$(OEXT))

srcl=cpp_cgt/main/cgt.cpp cpp_cgt/main/cfgparser.cpp cpp_cgt/main/platname.cpp \
	cpp_cgt/main/sec_circuit.cpp cpp_cgt/main/sectype.cpp \
	cpp_cgt/main/sec_native.cpp cpp_cgt/main/cloparser.cpp \
	cpp_cgt/main/sec_partial.cpp cpp_cgt/main/sec_bridge.cpp
objl := $(srcl:cpp_cgt/main/%.cpp=$(BIN)/%.$(OEXT))

##srcp=cpp_cgt/util/$(PLAT)/os_file2.cpp
##objp := $(srcp:cpp_cgt/util/$(PLAT)/%.cpp=$(BIN)/%.$(OEXT))


# srcu1 obju1 srck1 objk1
include mak_mod_sk.mak

# srcu2 obju2 srck2 objk2
include mak_mod_ek.mak


all: $(BIN) $(CRDIR) cgt.exe

$(BIN):
	mkdir -p $(BIN)

$(CRDIR):
	cd cpp_crcl && $(MAKE)

##cgt.exe: $(BIN) $(CRDIR) $(objl) $(obju2) $(obju1) $(objp) $(objk1) $(objk2) \
##	$(objcr) $(BIN)/cuddObj.$(OEXT) $(objcu) $(LDF1)
##	$(CCN) $(OPTS) $(objl) $(obju2) $(obju1) $(objp) \
##	$(objcu) $(objk1) $(objk2) $(objcr) $(BIN)/cuddObj.$(OEXT) \
##	$(LDF1) $(LDF3) $(LDFS) $(EOUT)$@
##	@$(COPYDLL1)

cgt.exe: $(BIN) $(CRDIR) $(objl) $(obju2) $(obju1) $(objk1) $(objk2) \
	$(objcr) $(BIN)/cuddObj.$(OEXT) $(objcu) $(LDF1)
	$(CCN) $(OPTS) $(objl) $(obju2) $(obju1) \
	$(objcu) $(objk1) $(objk2) $(objcr) $(BIN)/cuddObj.$(OEXT) \
	$(LDF1) $(LDF3) $(LDFS) $(EOUT)$@
	@$(COPYDLL1)

$(objl): $(BIN)/%.$(OEXT):cpp_cgt/main/%.cpp cpp_cgt/main/*.h \
	${SKDIR}/*.h ${EKDIR}/*.h cpp_cgt/util/*.h cpp_share/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(obju1): $(BIN)/%.$(OEXT):cpp_cgt/util/%.cpp cpp_cgt/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(obju2): $(BIN)/%.$(OEXT):cpp_share/util/%.cpp cpp_share/util/*.h cpp_share/util/*.inc
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

##$(objp): $(BIN)/%.$(OEXT):cpp_cgt/util/$(PLAT)/%.cpp cpp_cgt/main/*.h \
##	cpp_cgt/util/*.h cpp_share/util/*.h
##	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objk1): $(BIN)/%.$(OEXT):${SKDIR}/%.cpp cpp_cgt/main/*.h ${SKDIR}/*.h ${EKDIR}/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@


$(objk2): $(BIN)/%.$(OEXT):${EKDIR}/%.cpp cpp_cgt/main/*.h ${EKDIR}/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objcr): $(BIN)/%.$(OEXT):$(CRDIR)/%.cpp $(CRDIR)/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(BIN)/cuddObj.$(OEXT): $(CUDIR)/cuddObj.cc
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

$(objcu): $(BIN)/%.$(OEXT):$(CUDIR)/%.c $(CRDIR)/*.h
	$(CNC) -c $(COPTS) $< $(OOUT)$@


clean:
	rm -rf cgt.exe *.o *.obj bn_* bt_*
