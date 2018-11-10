#!/bin/bash

if [ "$1" = "" ]; then
echo "Use: e3work.sh <E3path>"
exit
fi

if [ "$1" = "clean" ]; then
echo "e3work.sh: cleaning" `pwd`
rm -rf e3work *.*.key *.exe compile.log *.obj *.tmp *.dll
exit
fi

##cwd0=`pwd`

# set this to e3 directory
e3dir=$1

PLAT=unx
if [ "$OS" = "Windows_NT" ]; then
PLAT=win
fi

#echo "e3work.sh: (PLAT=$PLAT)"

#echo "This script generates classes and copies files necessary to build user's program"
#echo "Everithing is done inside 'e3work' directory"
#echo "To clean/rebuild remove 'e3work'"

if test ! -d $e3dir; then
echo "Cannot access directory $e3dir"
exit 1
fi

cwd=`pwd`
cd $e3dir
e3dt=`pwd`
cd $cwd
e3ds=$e3dt/src

cgt=$e3ds/cgt.exe
if test ! -f $cgt; then
echo "Cannot find $cgt"
echo "Please built cgt first"
exit 1
fi

if test ! -f cgt.cfg; then
echo "Cannot find cgt.cfg"
echo "Please make cgt.cfg first"
exit 1
fi

if [ "$2" = "decrypt" ]; then
  if [ "$3" = "" ]; then
    echo "arguments required"
    exit 1
  fi 
#echo "e3work.sh: decrypting [$3]"
#echo "$cgt dec -f $3"
if test -f dec ; then
	. ./dec
else
	$cgt dec -f $3
fi
exit 0
fi

# finished with preparation, goto working dir

mkdir -p e3work
cd e3work

# 1 copy templates
cp -R $e3ds/db ./

# 2 generate secint
#cp ../cgt.cfg ./
$cgt gen -c ../cgt.cfg -d ../

# 3 deduce libs
libstfh=(`cat secint.h | grep LibsTFH`)
TFHE=${libstfh[2]}
FHEW=${libstfh[3]}
HELI=${libstfh[4]}
echo "Libs build: TFHE=$TFHE FHEW=$FHEW HELI=$HELI"

cpp_share_k="ek_native.cpp ek_abstract.cpp ek_circ_plain.cpp ek_circ.cpp ek_circ_tfhe$TFHE.cpp"
cpp_share_u="e3util.cpp def_tfhe$TFHE.cpp def_fhew$FHEW.cpp base64.cpp"


# 4 copy files
cp $e3ds/e3int.h ./
cp $e3ds/cpp_share/keys/*.h ./
cp $e3ds/cpp_share/util/*.h ./

for i in $cpp_share_k
do
cp $e3ds/cpp_share/keys/$i ./
done

for i in $cpp_share_u
do
cp $e3ds/cpp_share/util/$i ./
done

# 5 copy keys up
cp *.eval.key ../
cp *.priv.key ../

# finished
cd ../


# set libraries
e3p=$e3dir/3p
TFHED0=$e3p/tfhe_$PLAT
TFHED2=$TFHED0/target

FHEWD0=$e3p/fhew_$PLAT
FHEWD2=$FHEWD0/target

HELID0=$e3p/heli_$PLAT
HELID2=$HELID0/target

OPTS=
LDFU=
LDFW=
COPYDLL="echo COPYDLL dummy"

if [ "$TFHE" = "1" ]; then
OPTS="$OPTS -I./$TFHED0/inc/tfhe"
OPTS="$OPTS -I./$TFHED0/inc/fftwa"
OPTS="$OPTS -I./$TFHED0/inc/fftw3"
LDFU="$TFHED2/libtfhe.a $TFHED2/libfftw3.a"
LDFW="$TFHED2/libfftw3-3.lib $TFHED2/libtfhe.lib"
COPYDLL="cp $TFHED2/libfftw3-3.dll ./"
fi

if [ "$FHEW" = "1" ]; then
OPTS="$OPTS -I./$FHEWD0/inc/fhew"
LDFU="$FHEWD2/libfhew.a $TFHED2/libfftw3.a"
fi

if [ "$HELI" = "1" ]; then
OPTS="$OPTS -I./$HELID0/src"
LDFU="$HELID2/fhe.a -lntl -lgmp -lpthread"
##echo AAA $OPTS
##exit
fi

cmd="g++ -std=c++14 -O2 -Ie3work $OPTS *.cpp e3work/*.cpp $LDFU -o bob.exe"
if [ "$PLAT" = "win" ]; then
cmd="cl -nologo -EHsc -Ie3work -Ox $OPTS *.cpp e3work/*.cpp $LDFW -Febob.exe"
$COPYDLL
fi

echo $cmd
$cmd 2>&1 > compile.log
rm -f *.obj

if test ! -f bob.exe ; then
echo "e3work.sh: Compilation failed, see compile.log"
exit 1
fi

#$COPYDLL

echo "e3work.sh: OK"
exit 0
