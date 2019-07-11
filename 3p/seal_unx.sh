#!/bin/bash

PLAT=unx
me="=== 3p ==="

root=../../e3_seal
sealdir=$root/SEAL
cwd=`pwd`
target=$cwd/seal_$PLAT

echo "$me Cooking SEAL for $PLAT"

echo ""
echo "Step 1"
echo -n "$me SEAL checkout: "
# file=Makefile
path=$sealdir #/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out SEAL"
	mkdir -p $root
	cd $root
	git -c http.sslVerify=false clone --depth 1 --branch master https://github.com/Microsoft/SEAL
	cd $cwd
	if [ -d "$path" ]; then
		echo "$me done"
	else
		echo "$me failed to checkout SEAL"
		exit
	fi
fi

echo "$me checking dependencies"

if cmake --help > /dev/null; then
	echo "$me using cmake"
else
	echo "$me cmake not found, exiting"
	echo "$me install with: sudo apt install cmake"
	exit
fi

echo ""
echo "Step 2"
echo "$me make"
mkdir $target
cd $path/native/src
cmake -DCMAKE_INSTALL_PREFIX=$target .
make
make install

echo ""
echo "Step 3"
echo "$me set up native and target"
cd $target
mkdir native
mkdir target
cp lib/*.a native/
cp lib/*.a target/

cd $cwd
exit
# ----------------------------------------------

bin=tfhe_$PLAT
testfile1=test-multiplication
testfile2=test

echo ""
echo "Step 6"
echo -n "$me TFHE ingredients: "
path=$bin/$testfile2.cpp
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me preparing ingredients"
	mkdir tfhe_$PLAT
	mkdir tfhe_$PLAT/inc
	mkdir tfhe_$PLAT/inc/tfhe
	mkdir tfhe_$PLAT/inc/fftwa
	mkdir tfhe_$PLAT/inc/fftw3
	mkdir tfhe_$PLAT/libtfhe
	mkdir tfhe_$PLAT/fftwa
##	echo "#include <string>" > tfhe_$PLAT/$testfile2.cpp
##	cat $tfhedir/src/test/$testfile1.cpp | grep -v "sys/time.h" >> tfhe_$PLAT/$testfile2.cpp
	cp $tfhedir/src/test/$testfile1.cpp tfhe_$PLAT/$testfile2.cpp
	cp $tfhedir/src/include/*.h tfhe_$PLAT/inc/tfhe/
	cp $tfhedir/src/libtfhe/*.cpp tfhe_$PLAT/libtfhe/
	cp $tfhedir/src/libtfhe/fft_processors/fftw/*.cpp tfhe_$PLAT/fftwa
	cp $tfhedir/src/libtfhe/fft_processors/fftw/*.h tfhe_$PLAT/inc/fftwa
	cp $fftwpath/api/fftw3.h tfhe_$PLAT/inc/fftw3/
	cp $fftwpath/.libs/libfftw3.a tfhe_$PLAT/
#	cp $fftwpath/$libfftw.dll tfhe_$PLAT/

	echo "$me done"
fi

libtfhe=libtfhe.a

echo ""
echo "Step 7"
echo -n "$me TFHE $libtfhe: "
file=$libtfhe
path=tfhe_$PLAT/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	cwd=`pwd`; cd tfhe_$PLAT/libtfhe
	echo "$me compiling libtfhe"
##	cl -EHsc -I../inc/tfhe -I../inc/fftwa -c -D"M_PI=std::acos(-1)" *.cpp
	g++ -std=c++14 -I../inc/tfhe -I../inc/fftwa -c *.cpp
	cd $cwd
	cwd=`pwd`; cd tfhe_$PLAT/fftwa
	echo "$me compiling fftwa"
##	cl -EHsc -I../inc/tfhe -I../inc/fftw3 -I../inc/fftwa -c -D"M_PI=std::acos(-1)" *.cpp
	g++ -std=c++11 -I../inc/tfhe -I../inc/fftw3 -I../inc/fftwa -c *.cpp
	cd ..
	echo "$me lilnking $file"
	ar rcs $libtfhe libtfhe/*.o fftwa/*.o
	cd $cwd
fi

echo ""
echo "Step 8"
file=$testfile2
path=$bin/$file.exe
echo -n "$me $path: "
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me compiling test"
	cwd=`pwd`; cd tfhe_$PLAT
	g++ -std=c++14 -Iinc/tfhe $file.cpp $libtfhe libfftw3.a -o $file.exe
	cd $cwd

	if test -f $path; then
		echo "DONE"
	else
		echo "Failed to compile test"
	fi
fi

echo ""
echo "Step 9 - faking plats"
file=$libtfhe
path1=$bin/native/$file
path2=$bin/target/$file
echo -n "$me $path1 $path2: "
if test -f $path1 && test -f $path2; then
	echo "YES"
else
	echo "NO"
	echo "$me faking platforms"
	cwd=`pwd`; cd tfhe_$PLAT
	mkdir -p native
	cp $libtfhe libfftw3.a native/
	mkdir -p target
	cp $libtfhe libfftw3.a target/
	cd $cwd
fi
