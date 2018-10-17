CCN=cl
CCT=cl
CCX=cl
#EOUT=-o 
EOUT=/Fe
OOUT=/Fo
OEXT=obj
EEXT=exe
#LEXT1=lib
#LEXT2=obj
OPTS=-EHsc -nologo -Ox

LEXT=lib
#LDF=WS2_32.Lib advapi32.lib
LDF1=
LDF2=

COPYDLL1=echo no .dll
COPYDLL2=echo no .dll

ifeq ($(TFHE),1)
# lib dependency on 3p
TFHED1=../3p/tfhe_$(PLAT)/native
TFHED2=../3p/tfhe_$(PLAT)/target
LDF1=$(TFHED1)/libfftw3-3.lib $(TFHED1)/libtfhe.lib
LDF2=$(TFHED2)/libfftw3-3.lib $(TFHED2)/libtfhe.lib
# copy FFTW3 dll
COPYDLL1=cp $(TFHED1)/libfftw3-3.dll ./
COPYDLL2=cp $(TFHED2)/libfftw3-3.dll ./
##LDFDLLLOC=libfftw3-3.dll
##LDFDLLREM=$(TFHED1)/$(LDFDLLLOC)
endif

