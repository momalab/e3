# PLAT: w u

SRC=../
include ../mk_all.mak

CUD=c30
CULIB=cuddlib

O=$(TRG)

#src = ut.c

#obj := $($(CUD)/src:%.c=$O/%$(OEXT))


src = \
cpu_stats.c      cuddAndAbs.c   cuddCof.c      cuddInteract.c  cuddSign.c      cuddZddGroup.c  mtrBasic.c	\
cpu_time.c       cuddAnneal.c   cuddCompose.c  cuddLCache.c    cuddSolve.c     cuddZddIsop.c   mtrGroup.c	\
cstringstream.c  cuddApa.c      cuddDecomp.c   cuddLevelQ.c    cuddSplit.c     cuddZddLin.c    pathsearch.c	\
cuddAPI.c        cuddApprox.c   cuddEssent.c   cuddLinear.c    cuddSubsetHB.c  cuddZddMisc.c   pipefork.c	\
cuddAddAbs.c     cuddBddAbs.c   cuddExact.c    cuddLiteral.c   cuddSubsetSP.c  cuddZddPort.c   prtime.c		\
cuddAddApply.c   cuddBddCorr.c  cuddExport.c   cuddMatMult.c   cuddSymmetry.c  cuddZddReord.c  safe_mem.c	\
cuddAddFind.c    cuddBddIte.c   cuddGenCof.c   cuddPriority.c  cuddTable.c     cuddZddSetop.c  st.c		\
cuddAddInv.c     cuddBridge.c   cuddGenetic.c  cuddRead.c      cuddUtil.c      cuddZddSymm.c   strsav.c		\
cuddAddIte.c     cuddCache.c    cuddGroup.c    cuddRef.c       cuddWindow.c    cuddZddUtil.c   texpand.c	\
cuddAddNeg.c     cuddCheck.c    cuddHarwell.c  cuddReorder.c   cuddZddCount.c  datalimit.c     ucbqsort.c	\
cuddAddWalsh.c   cuddClip.c     cuddInit.c     cuddSat.c       cuddZddFuncs.c  epd.c

obj := $(src:%.c=$O/%$(OEXT))


srctrg = main.cpp
trg := $(srctrg:%.cpp=%$(EEXT))


all: $O $(trg) $O/$(CULIB)$(LEXT)

$O:
	mkdir -p $O

$(trg): %$(EEXT):%.cpp $O/$(CULIB)$(LEXT)
	$(COMPILER) $(OPT) $(INC) $< $O/$(CULIB)$(LEXT) \
	$(LDF) $(EOUT)$@

$O/$(CULIB)$(LEXT): $(obj) $O/cuddObj$(OEXT)
	$(ARCR)$O/$(CULIB)$(LEXT) $(obj) $O/cuddObj$(OEXT)

$(obj): $O/%$(OEXT):$(CUD)/%.c $(CUD)/*.h
	$(COMPILERC) -c $(OPTC) $(OPTCD) $(INC) $(FLAGS) $< $(OOUT)$@

$O/cuddObj$(OEXT): $(CUD)/cuddObj.cc
	$(COMPILER) -c $(OPT) $(OPTCD) $(INC) $(FLAGS) $< $(OOUT)$@


clean c:
	rm -rf $(TRG) *.obj *.exe
