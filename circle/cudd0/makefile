# PLAT: w u

SRC=../
include ../mk_all.mak

CUD=c30
CULIB=cuddlib

O=$(TRG)

#src = ut.c

#obj := $($(CUD)/src:%.c=$O/%$(OEXT))


srctrg = main.cpp
trg := $(srctrg:%.cpp=%$(EEXT))


all: $O $(trg) $O/$(CULIB)$(LEXT)

$O:
	mkdir -p $O

$(trg): %$(EEXT):%.cpp $O/$(CULIB)$(LEXT)
	$(COMPILER) $(OPT) $(INC) $< $O/$(CULIB)$(LEXT) \
	$(LDF) $(EOUT)$@

$O/$(CULIB)$(LEXT): $O/cuddObj$(OEXT)
	$(ARCR)$O/$(CULIB)$(LEXT) $O/cuddObj$(OEXT)

$(obj): $O/%$(OEXT):$(CUD)/%.c $(CUD)/*.h
	$(COMPILERC) -c $(OPTC) $(OPTCD) $(INC) $(FLAGS) $< $(OOUT)$@

$O/cuddObj$(OEXT): $(CUD)/cuddObj.cc
	$(COMPILER) -c $(OPT) $(OPTCD) $(INC) $(FLAGS) $< $(OOUT)$@


clean c:
	rm -rf $(TRG) *.obj *.exe
