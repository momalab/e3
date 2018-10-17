CCN=g++
CCT=g++
CCX=gcc
EOUT=-o 
OOUT=-o 
OEXT=o
EEXT=exe
#LEXT1=a
#LEXT2=so
OPTS=-O2 -std=c++14 -Wall

#LDF=-lpthread -ldl
LDF1=
LDF2=
LDF3=

COPYDLL1=echo no .so
COPYDLL2=echo no .so

ifeq ($(TFHE),1)
# lib dependency on 3p
TFHED1=../3p/tfhe_$(PLAT)/native
TFHED2=../3p/tfhe_$(PLAT)/target
LDF1=$(TFHED1)/libtfhe.a $(TFHED1)/libfftw3.a
LDF2=$(TFHED2)/libtfhe.a $(TFHED2)/libfftw3.a
endif


ifeq ($(HELI),1)
# lib dependency on 3p
TFHED1=../3p/heli_$(PLAT)/native
TFHED2=../3p/heli_$(PLAT)/target
LDF1+=$(TFHED1)/fhe.a
LDF2+=$(TFHED2)/fhe.a
LDF3+=-lntl -lgmp -lpthread
endif
