# E3 main makefile, 2018

ifeq ($(OS),Windows_NT)
 PLAT=win
else
 PLAT=unx
endif

USER=../tests/user/def
USER=user/def
CGT=$(USER)/cgt.cfg
CUDD=0
FHEW=0
HELI=0
MPIR=0
SEAL=0
TFHE=0

WUV=--warn-undefined-variables

secint=secint.inc secint.cpp secint.h

#all: cgt.exe $(secint) user.exe
#all: bob.exe alice.exe
all: cgt.exe

cgt.exe: */*/*.cpp */*/*.h
	cd cpp_crcl && $(MAKE)
	$(MAKE) $(WUV) -f mak_cgt.mak CUDD=$(CUDD) FHEW=$(FHEW) HELI=$(HELI) MPIR=$(MPIR) SEAL=$(SEAL) TFHE=$(TFHE)

$(secint): cgt.exe db/templ/*.* $(USER)/*
	$(MAKE) $(WUV) -f mak_sec.mak CGT=$(CGT) USER=$(USER)

bob: bob.exe

bob.exe: $(secint)
	$(MAKE) $(WUV) -f mak_bob.mak FHEW=$(FHEW) HELI=$(HELI) MPIR=$(MPIR) SEAL=$(SEAL) TFHE=$(TFHE) CGT=$(CGT) USER=$(USER)

alice: alice.exe

alice.exe: $(secint)
	$(MAKE) $(WUV) -f mak_alice.mak FHEW=$(FHEW) HELI=$(HELI) MPIR=$(MPIR) SEAL=$(SEAL) TFHE=$(TFHE) CGT=$(CGT) USER=$(USER)

clean:
	rm -rf secint.* *.exe *.o *.obj bn_* bt_* e3x/emulate/e3x.obj .vs *.dll
	rm -rf result.txt cgtshared.cpp cgtshared.h cgtkey.h cgtkey.cpp

cleankey:
	rm -rf secint.* *.key *.*.key x.15* *.key.cpp *.key.exe *.key.obj *.const

cleanall: clean cleankey

# working version - om
#c cleantotal: cleanall
c cleantotal: cleanall cleankey
	rm -f $(E3X)/*.$(OEXT) cgt.exe
	cd cpp_crcl && $(MAKE) clean

check:
ifeq ($(PLAT),unx)
	#chmod +x check_unx.sh
	./check_$(PLAT).sh
else
	sh check_$(PLAT).sh
endif
