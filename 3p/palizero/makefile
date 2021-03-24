include plat.mak

$(info $(PLAT) $(SOEXT))


GITROOT=../../..
GITPALI=e3_pali/palisade-release

IN=include/palisade

#all: lib cereal include simple-integers.exe sis.exe
all: lib cereal include sis_fun.exe

lib: $(GITROOT)/$(GITPALI)/build/_ins/lib
	cp -R $< ./

include: $(GITROOT)/$(GITPALI)/build/_ins/include
	cp -R $< ./

cereal: $(GITROOT)/$(GITPALI)/third-party/cereal/include/cereal
	cp -R $< ./

simple-integers.cpp: $(GITROOT)/$(GITPALI)/src/pke/examples/simple-integers.cpp
	cp $< ./

INC = -I. -I$(IN)/pke -I$(IN)/core
LIBS = lib/libPALISADEpke$(SOEXT) lib/libPALISADEcore$(SOEXT)
OPT = -DPALISADE_VERSION=1.10.5 -fopenmp
simple-integers.exe: simple-integers.cpp
	g++ -std=gnu++17 -O2 $(INC) $(OPT) $< -o $@ $(LIBS)

# cannot use std=c++ because M_E constants
#	g++ -std=c++17 -O2 -I. -I$(IN)/pke -I$(IN)/core $< -o $@

clean c:
	rm -rf cereal include lib *.exe simple-integers.* *.key *.o *.ct

sis.exe: sis.cpp
	g++ -std=gnu++17 -O2 $(INC) $(OPT) $< -o $@ $(LIBS)

src = sis_main.cpp sis_fun.cpp sis_ser.cpp
obj := $(src:%.cpp=%.o)

sis_fun.exe: $(obj)
	g++ -std=gnu++17 -O2 $(OPT) $^ -o $@ $(LIBS)

#sis01.o: sis01.cpp sis0.h
#	g++ -c -std=gnu++17 -O2 $(INC) $(OPT) $< -o $@


$(obj): %.o:%.cpp sis_fun.h
	g++ -c -std=gnu++17 -O2 $(INC) $(OPT) $< -o $@

style:
	style.bat *.cpp *.h
