# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
CCN=g++
CNC=gcc
CCT=g++
CCX=gcc
EOUT=-o
OOUT=-o
OEXT=o
EEXT=exe
#LEXT1=a
#LEXT2=so

#ifndef SOEXT
SOEXT ?= .so
#endif

#OPTS=-O2 -std=c++17 -Wall -Wno-parentheses
OPTS=-O2 -std=gnu++17 -Wall -Wno-parentheses
# changed c++17 to gnu++17 because popen did not work on cygwin
# OPTS=-O2 -std=gnu++17 -Wall -Wno-parentheses -Werror -DSEALVER=332
OPTS=-O2 -std=gnu++17 -Wall -Wno-parentheses -Werror

# palisade header has pragmas
OPTS += -Wno-unknown-pragmas

#COPTS=-O2 -Wall -Wpointer-to-int-cast
COPTS=-O2 -Wno-pointer-to-int-cast

LDFS=-lpthread -ldl
#LDFS=
LDF1=
LDF2=
LDF3=

COPYDLL1=echo no .so
COPYDLL2=echo no .so

ifeq ($(FHEW),1)
# lib dependency on 3p
FHEWD1=../3p/fhew_$(PLAT)/native
FHEWD2=../3p/fhew_$(PLAT)/target
LDF1+=$(FHEWD1)/libfhew.a $(FHEWD1)/libfftw3.a
LDF2+=$(FHEWD2)/libfhew.a $(FHEWD2)/libfftw3.a
endif

ifeq ($(HELI),1)
# lib dependency on 3p
HELID1=../3p/heli_$(PLAT)/native
HELID2=../3p/heli_$(PLAT)/target
LDF1+=$(HELID1)/fhe.a
LDF2+=$(HELID2)/fhe.a
LDF3+=-lntl -lgmp -lpthread
endif

ifneq ($(MPIR),0)
# lib dependency on 3p
MPIRD1=../3p/mpir_$(PLAT)/native
MPIRD2=../3p/mpir_$(PLAT)/target
LDF1+=$(MPIRD1)/libmpir.a $(MPIRD1)/libcxx.a
LDF2+=$(MPIRD2)/libmpir.a $(MPIRD2)/libcxx.a
endif

ifeq ($(SEAL),1)
# lib dependency on 3p
SEALD1=../3p/seal_$(PLAT)/native
SEALD2=../3p/seal_$(PLAT)/target
LDF1+=$(SEALD1)/libseal.a
LDF2+=$(SEALD2)/libseal.a -lpthread
endif

ifeq ($(TFHE),1)
# lib dependency on 3p
TFHED1=../3p/tfhe_$(PLAT)/native
TFHED2=../3p/tfhe_$(PLAT)/target
LDF1+=$(TFHED1)/libtfhe.a $(TFHED1)/libfftw3.a
LDF2+=$(TFHED2)/libtfhe.a $(TFHED2)/libfftw3.a
#LDF1+=$(TFHED1)/libtfhe-spqlios-fma.so
#LDF2+=$(TFHED2)/libtfhe-spqlios-fma.so
endif

ifeq ($(PALI),1)
PALID1=../3p/pali_$(PLAT)/native
PALID2=../3p/pali_$(PLAT)/target
LDF1+=$(PALID1)/libPALISADEpke$(SOEXT) $(PALID1)/libPALISADEcore$(SOEXT)
LDF2+=$(PALID2)/libPALISADEpke$(SOEXT) $(PALID2)/libPALISADEcore$(SOEXT)
endif
