# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

srccud =
ifeq ($(CUDD),1)
srccud = \
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
endif
srccu := $(srccud:%.c=$(CUDIR)/%.c)
objcu := $(srccud:%.c=$(BIN)/%.$(OEXT))

