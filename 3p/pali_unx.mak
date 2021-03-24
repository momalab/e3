GITROOT=../../..
GITPALI=e3_pali/palisade-release

IN=include/palisade

all: lib cereal include simple-integers.exe

lib: $(GITROOT)/$(GITPALI)/build/_ins/lib
	cp -R $< ./

include: $(GITROOT)/$(GITPALI)/build/_ins/include
	cp -R $< ./

cereal: $(GITROOT)/$(GITPALI)/third-party/cereal/include/cereal
	cp -R $< ./

simple-integers.cpp: $(GITROOT)/$(GITPALI)/src/pke/examples/simple-integers.cpp
	cp $< ./

INC = -I. -I$(IN)/pke -I$(IN)/core
LIBS = lib/libPALISADEpke.so lib/libPALISADEcore.so
simple-integers.exe: simple-integers.cpp
	g++ -std=gnu++17 -O2 $(INC) $< -o $@ $(LIBS)

# cannot use std=c++ because M_E constants
#	g++ -std=c++17 -O2 -I. -I$(IN)/pke -I$(IN)/core $< -o $@

clean c:
	rm -rf cereal include lib *.exe simple-integers.*

