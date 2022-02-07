# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
# PLAT: w u

CUDD=1

SRC=../
include ../mk_all.mak

O=$(TRG)

CUD=../cudd$(CUDD)/c30
CULIBNAME=cuddlib
CULIB=$(CUD)/../$O/$(CULIBNAME)$(LEXT)

INC += -I$(CUD)


src = bbs.cpp prime.cpp crcl.cpp main.cpp ttbl.cpp bdda.cpp \
	eval.cpp vars.cpp simp.cpp gram.cpp crutil.cpp prep.cpp \
	invar.cpp olc.cpp olrnd.cpp invert.cpp

obj := $(src:%.cpp=$O/%$(OEXT))


srctrg = main.cpp
trg := $(srctrg:%.cpp=%_$(PLAT)$(EEXT))

CRCL = crcl$(EEXT)

#all: $O $(trg)
all: $O $(CRCL)

$O:
	mkdir -p $O

$(CRCL): $(obj) $(CULIB)
	$(COMPILER) $(OPT) $(INC) $(obj) $(CULIB) $(LDF) $(EOUT)$@

$(trg): %$(EEXT):%.cpp $(obj)
	$(COMPILER) $(OPT) $(INC) $< $(obj) $(LDF) $(EOUT)$@

$(obj): $O/%$(OEXT):%.cpp *.h
	$(COMPILER) -c $(OPT) $(INC) $(FLAGS) $< $(OOUT)$@

_ol.cpp: ../u/ol.cpp
	cp $< $@

clean c:
	rm -rf $(TRG) *.obj *.exe _*.*

fixxer: fixxer.cpp $O/_ol$(OEXT)
	$(COMPILER) $(OPT) $(INC) $< $O/_ol$(OEXT) $(LDF) $(EOUT)$@


