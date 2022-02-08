#!/bin/bash
# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

# this file generates amalgamation of cpp_cgt

# definitions
amanamesh=cgtshared
amaname=cgtkey
cppshare=cpp_cgt
crcl=cpp_crcl
crclcr=$crcl/cr
crclcu=$crcl/exp
main=$cppshare/main
util=$cppshare/util
keys=$cppshare/keys
header=$amaname.h
cxfile=$amaname.cpp

PLAT=unx
if [ "$OS" = "Windows_NT" ]; then
PLAT=win
 if test -f mingw || [ "$MINGW_CHOST" != "" ]; then
 PLAT=mgw
 fi
fi

echo "Amalgamating of cgt priv files (PLAT=$PLAT)"

if test -f cgt.exe; then
:
else
echo "Error: cgt.exe not found"
exit 1
fi

source ./codelib.sh


: > $cxfile
echo "" >> $cxfile
echo "#include <cstring>" >> $cxfile
echo "#include <cstdio>" >> $cxfile
echo "#include <time.h>" >> $cxfile
echo "#include <chrono>" >> $cxfile

echo "" >> $cxfile
echo "#include \"$header\"" >> $cxfile
echo "" >> $cxfile
#echo "using std::cout;" >> $cxfile
#echo "using std::string;" >> $cxfile
echo "" >> $cxfile

echo "// OS file functions" >> $cxfile
echo "#ifdef _MSC_VER" >> $cxfile
echo "#include <direct.h>" >> $cxfile
echo "#include <io.h>" >> $cxfile
echo "#include <fcntl.h>" >> $cxfile
echo "#include <sys/types.h>" >> $cxfile
echo "#include <sys/stat.h>" >> $cxfile
echo "#else" >> $cxfile
echo "#include <dirent.h>" >> $cxfile
echo "#include <sys/stat.h>" >> $cxfile
echo "#include <unistd.h>" >> $cxfile
echo "#endif" >> $cxfile
echo "" >> $cxfile

: > $header
echo "#pragma once" >> $header
echo "" >> $header
echo "#include <functional>" >> $header
echo "#include <random>" >> $header
echo "#include <string>" >> $header
echo "#include <iostream>" >> $header
echo "#include <fstream>" >> $header
echo "#include <cstdlib>" >> $header
echo "#include <string>" >> $header
echo "#include <sstream>" >> $header
echo "#include <cctype>" >> $header
echo "#include <iomanip>" >> $header
echo "#include <vector>" >> $header
echo "#include <algorithm>" >> $header
echo "#include <memory>" >> $header
echo "#include <map>" >> $header
echo "#include <set>" >> $header
echo "#include <filesystem>" >> $header
echo "" >> $header


echo "#include \"$amanamesh.h\"" >> $header
echo "" >> $header

# include specific libraries
echo "// TFHE=$TFHE SEAL=$SEAL FHEW=$FHEW HELI=$HELI MPIR=$MPIR CUDD=$CUDD PALI=$PALI" >> $header
echo "" >> $header

#if [ "$CUDD" = "1" ]; then
#echo "// including CUDD" >> $header
#echo "///#include \"FHE.h\"" >> $header
#echo "///#include \"EncryptedArray.h\"" >> $header
#fi


echo "// start header amalgama" >> $header

dof()
{
echo "" >> $1
echo "// *** begin $2" >> $1
cat $2 | grep -v "#pragma\|#include" >> $1
echo "// *** end $2" >> $1
}

# do crcl headers
dof $header $crclcr/olc.h
dof $header $crclcr/olrnd.h
dof $header $crclcr/crutil.h
dof $header $crclcr/gram.h
dof $header $crclcr/prep.h
dof $header $crclcr/crcl.h
dof $header $crclcr/bdda.h
dof $header $crclcr/bbs.h
dof $header $crclcr/eval.h
dof $header $crclcr/vars.h
dof $header $crclcr/simp.h
dof $header $crclcr/main.h

# do util headers
dof $header $util/cgtutil.h
dof $header $util/euler.h
dof $header $util/timer.h
dof $header $util/cgtutil.h
dof $header $util/os_filesys.h

# do main headers
dof $header $main/cfgnames.h
dof $header $main/secnames.h

# do key headers
dof $header $keys/sk_abstract.h

dof $header $keys/ekx_native.h
dof $header $keys/ekx_pil.h
dof $header $keys/ekx_pail.h
dof $header $keys/ekx_seal.h
dof $header $keys/ekx_seal_ckks.h
dof $header $keys/ekx_bfv_prot.h
dof $header $keys/ekx_pali.h
dof $header $keys/ekx_palisade_ckks.h
dof $header $keys/ekx_circ_plain.h
dof $header $keys/ekx_circ_fhew.h
dof $header $keys/ekx_circ_heli.h
dof $header $keys/ekx_circ_seal.h
dof $header $keys/ekx_circ_tfhe.h
dof $header $keys/ekx_circ_bdd.h
dof $header $keys/ekx_circ_pil.h
dof $header $keys/ekx_circ_gatcou.h

dof $header $keys/sk_native.h
dof $header $keys/sk_circ.h
dof $header $keys/sk_pil.h
dof $header $keys/sk_pail.h
dof $header $keys/sk_seal.h
dof $header $keys/sk_seal_ckks.h
dof $header $keys/sk_bfv_prot.h
dof $header $keys/sk_pali.h
dof $header $keys/sk_palisade_ckks.h
dof $header $keys/sk_arith_seal.h
dof $header $keys/sk_arith_seal_ckks.h
dof $header $keys/sk_circ_plain.h
dof $header $keys/sk_circ_fhew.h
dof $header $keys/sk_circ_heli.h
dof $header $keys/sk_circ_seal.h
dof $header $keys/sk_circ_tfhe.h
dof $header $keys/sk_circ_bdd.h
dof $header $keys/sk_circ_pil.h
dof $header $keys/sk_circ_gatcou.h

dof $header $keys/privkeys.h

# do cudd header
dof $header $crclcu/cuddObj.hh

# do util cpps
dof $cxfile $util/euler.cpp
dof $cxfile $util/timer.cpp
dof $cxfile $util/cgtutil.cpp
dof $cxfile $util/os_filesys.cpp
##dof $cxfile $util/$PLAT/os_file2.cpp

# do keys cpps
dof $cxfile $keys/sk_abstract.cpp
dof $cxfile $keys/sk_circ.cpp
dof $cxfile $keys/ekx_circ_bdd.cpp
dof $cxfile $keys/sk_circ_bdd.cpp
dof $cxfile $keys/ekx_circ_fhew$FHEW.cpp
dof $cxfile $keys/sk_circ_fhew$FHEW.cpp
dof $cxfile $keys/ekx_circ_heli$HELI.cpp
dof $cxfile $keys/sk_circ_heli$HELI.cpp
dof $cxfile $keys/ekx_circ_pil.cpp
dof $cxfile $keys/sk_circ_pil.cpp
dof $cxfile $keys/ekx_circ_plain.cpp
dof $cxfile $keys/sk_circ_plain.cpp
dof $cxfile $keys/ekx_circ_tfhe$TFHE.cpp
dof $cxfile $keys/sk_circ_tfhe$TFHE.cpp
dof $cxfile $keys/ekx_native.cpp
dof $cxfile $keys/sk_native.cpp
dof $cxfile $keys/ekx_pil.cpp
dof $cxfile $keys/sk_pil.cpp
dof $cxfile $keys/ekx_pail.cpp
dof $cxfile $keys/sk_pail.cpp
dof $cxfile $keys/ekx_seal$SEAL.cpp
dof $cxfile $keys/ekx_seal_ckks$SEAL.cpp
dof $cxfile $keys/sk_seal$SEAL.cpp
dof $cxfile $keys/sk_seal_ckks$SEAL.cpp
dof $cxfile $keys/ekx_bfv_prot.cpp
dof $cxfile $keys/sk_bfv_prot.cpp
dof $cxfile $keys/ekx_pali$PALI.cpp
dof $cxfile $keys/sk_pali$PALI.cpp
dof $cxfile $keys/ekx_palisade_ckks$PALI.cpp
dof $cxfile $keys/sk_palisade_ckks$PALI.cpp

# do main cpps
dof $cxfile $main/platname.cpp

# do crcl, first using decls
dof $cxfile $crclcr/using.h
dof $cxfile $crclcr/bdda.cpp
dof $cxfile $crclcr/prep.cpp
dof $cxfile $crclcr/simp.cpp
dof $cxfile $crclcr/crutil.cpp
dof $cxfile $crclcr/vars.cpp
dof $cxfile $crclcr/olc.cpp
dof $cxfile $crclcr/olrnd.cpp
dof $cxfile $crclcr/bbs.cpp
dof $cxfile $crclcr/gram.cpp
dof $cxfile $crclcr/crcl.cpp

# do cudd
dof $cxfile $crclcu/cuddObj.cc

# test compilation - remove later
#cl -c -EHsc -nologo -D_USING_V110_SDK71_=1 $amaname.cpp | head -5

echo "Files have been created: $cxfile and $header"
