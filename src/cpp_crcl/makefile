# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

CUDD=0

C=cr
D=d$(CUDD)
CIR=../../circle/crcl

src = olc.cpp bbs.cpp olc.h bbs.h olrnd.cpp olrnd.h main.h \
	vars.h vars.cpp crcl.h crcl.cpp gram.h crutil.h \
	prep.h eval.h gram.cpp simp.cpp crutil.cpp \
	prep.cpp bdda.h bdda.cpp using.h simp.h

scu = 

#srcr := $(srch:%.cpp=$(CIR)/%.cpp)
srcr := $(src:%=$(CIR)/%)
srch := $(src:%=$C/%)


circle: $C $D/cuddObj.hh $(srch) exp/cuddObj.hh
	chmod -R 0777 cr $D exp

$C:
	mkdir -p $C

$D:
	mkdir -p $D

$D/cuddObj.hh: $D
	cp $(CIR)/../cudd$(CUDD)/c30/*.* $D/

# exp - files for users binaries
exp/cuddObj.hh: exp
	cp $(CIR)/../cudd0/c30/*.* exp/

exp:
	mkdir -p exp

#$(srch): $(srcr)
$(srch): $C/%:$(CIR)/%
	cp $< $@

clean c:
	rm -rf cr d1 d0 exp
