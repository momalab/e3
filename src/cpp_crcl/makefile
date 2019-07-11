
CUDD=0

C=cr
D=d$(CUDD)
CIR=../../circle/crcl

src = olc.cpp bbs.cpp olc.h bbs.h olrnd.cpp olrnd.h main.h \
	vars.h vars.cpp crcl.h crcl.cpp gram.h crutil.h \
	prep.h eval.h gram.cpp simp.cpp crutil.cpp \
	prep.cpp bdda.h bdda.cpp

scu = 

#srcr := $(srch:%.cpp=$(CIR)/%.cpp)
srcr := $(src:%=$(CIR)/%)
srch := $(src:%=$C/%)


circle: $C $D/cuddObj.hh $(srch)

$C:
	mkdir -p $C

$D:
	mkdir -p $D

$D/cuddObj.hh: $D
	cp $(CIR)/../cudd$(CUDD)/c30/*.* $D/

#$(srch): $(srcr)
$(srch): $C/%:$(CIR)/%
	cp $< $@

clean c:
	rm -rf cr d1 d0
