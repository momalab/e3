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


##ifeq ($(TFHE),1)
##OPTS += -I./$(TFHED0)/inc/tfhe
##OPTS += -I./$(TFHED0)/inc/fftwa
##OPTS += -I./$(TFHED0)/inc/fftw3
##endif

##ifeq ($(FHEW),1)
##OPTS += -I./$(FHEWD0)/inc/fhew
##OPTS += -I./$(FHEWD0)/inc/fftwa
##OPTS += -I./$(FHEWD0)/inc/fftw3
##endif

##ifeq ($(HELI),1)
##OPTS += -I./$(HELID0)/src
##endif

##ifeq ($(MPIR),1)
##OPTS += -I./$(MPIRD0)/src
##endif

include mak_mod_inc.mak
include mak_mod_cu.mak

##srccud =
##ifeq ($(CUDD),1)
##srccud = \
##cpu_stats.c      cuddAndAbs.c   cuddCof.c      cuddInteract.c  cuddSign.c      cuddZddGroup.c  mtrBasic.c	\
##cpu_time.c       cuddAnneal.c   cuddCompose.c  cuddLCache.c    cuddSolve.c     cuddZddIsop.c   mtrGroup.c	\
##cstringstream.c  cuddApa.c      cuddDecomp.c   cuddLevelQ.c    cuddSplit.c     cuddZddLin.c    pathsearch.c	\
##cuddAPI.c        cuddApprox.c   cuddEssent.c   cuddLinear.c    cuddSubsetHB.c  cuddZddMisc.c   pipefork.c	\
##cuddAddAbs.c     cuddBddAbs.c   cuddExact.c    cuddLiteral.c   cuddSubsetSP.c  cuddZddPort.c   prtime.c		\
##cuddAddApply.c   cuddBddCorr.c  cuddExport.c   cuddMatMult.c   cuddSymmetry.c  cuddZddReord.c  safe_mem.c	\
##cuddAddFind.c    cuddBddIte.c   cuddGenCof.c   cuddPriority.c  cuddTable.c     cuddZddSetop.c  st.c		\
##cuddAddInv.c     cuddBridge.c   cuddGenetic.c  cuddRead.c      cuddUtil.c      cuddZddSymm.c   strsav.c		\
##cuddAddIte.c     cuddCache.c    cuddGroup.c    cuddRef.c       cuddWindow.c    cuddZddUtil.c   texpand.c	\
##cuddAddNeg.c     cuddCheck.c    cuddHarwell.c  cuddReorder.c   cuddZddCount.c  datalimit.c     ucbqsort.c	\
##cuddAddWalsh.c   cuddClip.c     cuddInit.c     cuddSat.c       cuddZddFuncs.c  epd.c
##endif
##srccu := $(srccud:%.c=$(CUDIR)/%.c)
##objcu := $(srccud:%.c=$(BIN)/%.$(OEXT))

srccir = olc.cpp olrnd.cpp bbs.cpp crcl.cpp gram.cpp \
	simp.cpp crutil.cpp vars.cpp prep.cpp bdda.cpp
srccr := $(srccir:%.cpp=$(CRDIR)/%.cpp)
objcr := $(srccir:%.cpp=$(BIN)/%.$(OEXT))

srcl=cpp_cgt/main/cgt.cpp cpp_cgt/main/cfgparser.cpp cpp_cgt/main/platname.cpp \
	cpp_cgt/main/sec_circuit.cpp cpp_cgt/main/sectype.cpp \
	cpp_cgt/main/sec_native.cpp cpp_cgt/main/cloparser.cpp \
	cpp_cgt/main/sec_partial.cpp cpp_cgt/main/sec_bridge.cpp
objl := $(srcl:cpp_cgt/main/%.cpp=$(BIN)/%.$(OEXT))

##srcu1=cpp_cgt/util/os_filesys.cpp cpp_cgt/util/cgtutil.cpp cpp_cgt/util/timer.cpp
##obju1 := $(srcu1:cpp_cgt/util/%.cpp=$(BIN)/%.$(OEXT))

##srcu2=cpp_share/util/e3util.cpp \
##	cpp_share/util/def_tfhe$(TFHE).cpp \
##	cpp_share/util/def_fhew$(FHEW).cpp \
##	cpp_share/util/def_heli$(HELI).cpp \
##	cpp_share/util/def_mpir$(MPIR).cpp \
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

# srcu1 obju1 srck1 objk1
include mak_mod_sk.mak

##srck2= ${EKDIR}/ek_abstract.cpp ${EKDIR}/ek_native.cpp \
##	${EKDIR}/ek_circ_plain.cpp \
##	${EKDIR}/ek_circ_tfhe$(TFHE).cpp \
##	${EKDIR}/ek_circ_fhew$(FHEW).cpp \
##	${EKDIR}/ek_circ_heli$(HELI).cpp \
##	${EKDIR}/ek_circ_bdd.cpp \
##	${EKDIR}/ek_circ.cpp
##objk2 := $(srck2:${EKDIR}/%.cpp=$(BIN)/%.$(OEXT))

# srcu2 obju2 srck2 objk2
include mak_mod_ek.mak


all: $(BIN) $(CRDIR) cgt.exe

$(BIN):
	mkdir -p $(BIN)

$(CRDIR):
	cd cpp_crcl && $(MAKE)

cgt.exe: $(BIN) $(CRDIR) $(objl) $(obju2) $(obju1) $(objp) $(objk1) $(objk2) \
	$(objcr) $(BIN)/cuddObj.$(OEXT) $(objcu) $(LDF1)
	$(CCN) $(OPTS) $(objl) $(obju2) $(obju1) $(objp) \
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

$(objp): $(BIN)/%.$(OEXT):cpp_cgt/util/$(PLAT)/%.cpp cpp_cgt/main/*.h \
	cpp_cgt/util/*.h cpp_share/util/*.h
	$(CCN) -c -DPLAT=$(PLAT) $(OPTS) $< $(OOUT)$@

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
