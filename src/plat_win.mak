# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
CCN=cl
CNC=cl
CCT=cl
CCX=cl
#EOUT=-o
EOUT=-Fe
OOUT=-Fo
OEXT=obj
EEXT=exe
#LEXT1=lib
#LEXT2=obj

#OPTS=-EHsc -nologo -D_USING_V110_SDK71_=1
#OPTS=-EHsc -nologo -Ox -D_USING_V110_SDK71_=1 -bigobj /std:c++17 -DSEALVER=332
OPTS=-EHsc -nologo -Ox -D_USING_V110_SDK71_=1 -bigobj /std:c++17

COPTS=-nologo -Ox -D_CRT_SECURE_NO_DEPRECATE=1 -D_USING_V110_SDK71_=1

# -WX -W4 -D_CRT_SECURE_NO_DEPRECATE=1 /wd4355 /wd4127 /wd4702 /wd4100 /wd4290
# /wd4589 -D_USING_V110_SDK71_=1 /wd4244 /wd4204 /wd4245 /wd4018

LEXT=lib
LDFS=WS2_32.Lib advapi32.lib psapi.lib
LDFS=WS2_32.Lib advapi32.lib
LDF1=
LDF2=
LDF3=

COPYDLL1=echo no .dll
COPYDLL2=echo no .dll

ifneq ($(MPIR),0)
# lib dependency on 3p
MPIRD1=../3p/mpir_$(PLAT)/native
MPIRD2=../3p/mpir_$(PLAT)/target
LDF1+=$(MPIRD1)/mpir.lib $(MPIRD1)/mpirxx.lib
LDF2+=$(MPIRD2)/mpir.lib $(MPIRD2)/mpirxx.lib
endif

ifeq ($(TFHE),1)
# lib dependency on 3p
TFHED1=../3p/tfhe_$(PLAT)/native
TFHED2=../3p/tfhe_$(PLAT)/target
LDF1+=$(TFHED1)/libfftw3-3.lib $(TFHED1)/libtfhe.lib
LDF2+=$(TFHED2)/libfftw3-3.lib $(TFHED2)/libtfhe.lib
# copy FFTW3 dll
COPYDLL1=cp $(TFHED1)/libfftw3-3.dll ./
COPYDLL2=cp $(TFHED2)/libfftw3-3.dll ./
##LDFDLLLOC=libfftw3-3.dll
##LDFDLLREM=$(TFHED1)/$(LDFDLLLOC)
endif

ifeq ($(SEAL),1)
# lib dependency on 3p
SEALD1=../3p/seal_$(PLAT)/native
SEALD2=../3p/seal_$(PLAT)/target
LDF1+=$(SEALD1)/seal.lib
LDF2+=$(SEALD2)/seal.lib
endif

ifeq ($(PALI),1)
$(error Palisade is not supported with MS, use MSYS)
endif
