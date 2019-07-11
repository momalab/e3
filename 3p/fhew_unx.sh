#!/bin/bash

PLAT=unx
me="=== 3p ==="

root=../../e3_fhew
fhewdir=$root/fhew

echo "$me Cooking FHEW for $PLAT"

echo ""
echo "Step 1"
echo -n "$me FHEW checkout: "
file=Makefile
path=$root/fhew/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out FHEW"
	mkdir -p $root
	cwd=`pwd`; cd $root
	git -c http.sslVerify=false clone --branch master https://github.com/lducas/fhew.git
	cd $cwd
	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to checkout FHEW"
		exit
	fi
fi

fftw=fftw-3.3.8
file_fftw_tar=$fftw.tar.gz
fftwpath=$root/fftw/$PLAT/$fftw

echo ""
echo "Step 2"
echo -n "$me FFTW3 tar: "
file=$file_fftw_tar
down=http://www.fftw.org/$file
path=$fftwpath/../$file
if test -f $path; then
	echo "YES"
else
	echo "NO"

	if wget --help > /dev/null; then
		echo "$me using wget"
	else
		echo "$me wget not found, exiting"
		exit
	fi

	echo "$me downloading FFTW"
	mkdir -p $fftwpath
	cwd=`pwd`; cd $fftwpath/../
	wget $down
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to download $file"
		exit
	fi
fi

echo ""
echo "Step 3"
echo -n "$me checking tar: "
if tar --help > /dev/null; then
	echo "YES"
else
	echo "NO"
	echo "$me please install tar"
	exit
fi

libfftw=libfftw3

echo ""
echo "Step 4"
echo -n "$me unpacked FFTW: "
##file=$libfftw.dll
path=$fftwpath/configure
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me untarring FFTW"
	cwd=`pwd`; cd $fftwpath/../
	tar zxvf $file_fftw_tar
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to untar"
		exit
	fi
fi

echo ""
echo "Step 5"
echo -n "$me FFTW lib: "
##file=$libfftw.lib
path=$fftwpath/.libs/libfftw3.a
#echo $path
#exit
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me making FFTW lib"
	cwd=`pwd`; cd $fftwpath
	./configure
	make
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to make FFTW lib"
		exit
	fi
fi

bin=fhew_$PLAT
testfile1=fhewTest
testfile2=test

echo ""
echo "Step 6"
echo -n "$me FHEW ingredients: "
path=$bin/$testfile2.cpp
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me preparing ingredients"
	mkdir fhew_$PLAT
	mkdir fhew_$PLAT/inc
	mkdir fhew_$PLAT/inc/fhew
	mkdir fhew_$PLAT/inc/fftwa
	mkdir fhew_$PLAT/inc/fftw3
	mkdir fhew_$PLAT/libfhew
	mkdir fhew_$PLAT/fftwa
##	echo "#include <string>" > fhew_$PLAT/$testfile2.cpp
##	echo "" > fhew_$PLAT/$testfile2.cpp
##	cp $fhewdir/$testfile1.cpp fhew_$PLAT/$testfile2.cpp
	cp $fhewdir/*.h fhew_$PLAT/inc/fhew/
	cp $root/fftw/$PLAT/fftw-3.3.8/api/fftw3.h fhew_$PLAT/inc/fhew
	cp $fhewdir/*.cpp fhew_$PLAT/libfhew/
	mv fhew_$PLAT/libfhew/$testfile1.cpp fhew_$PLAT/$testfile2.cpp
##	# remove abort from die_dramatically as we would handle the exceptions
##	cat $fhewdir/src/libfhew/fhew_gate_bootstrapping.cpp | grep -v "abort()" > fhew_$PLAT/libfhew/fhew_gate_bootstrapping.cpp
##	cp $fhewdir/src/libfhew/fft_processors/fftw/*.cpp fhew_$PLAT/fftwa
##	cp $fhewdir/src/libfhew/fft_processors/fftw/*.h fhew_$PLAT/inc/fftwa
	cp $fftwpath/*.h fhew_$PLAT/inc/fftw3/
	cp $fftwpath/.libs/$libfftw.a fhew_$PLAT/

	echo "$me done"
fi

libfhew=libfhew.a

echo ""
echo "Step 7"
echo -n "$me FHEW $libfhew: "
file=$libfhew
path=fhew_$PLAT/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	cwd=`pwd`; cd fhew_$PLAT/libfhew	
	echo "$me compiling libfhew"
	g++ -std=c++03 -I../inc/fhew -I../inc/fftwa -c *.cpp
	echo "$me lilnking $file"
	cd ..
	ar rcs $libfhew libfhew/*.o
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
	cwd=`pwd`; cd fhew_$PLAT
	g++ -std=c++14 -Iinc/fhew $file.cpp $libfhew libfftw3.a -o $file.exe
	cd $cwd

	if test -f $path; then
		echo "DONE"
	else
		echo "Failed to compile test"
	fi
fi

echo ""
echo "Step 9 - faking plats"
file=$libfhew
path1=$bin/native/$file
path2=$bin/target/$file
echo -n "$me $path1 $path2: "
if test -f $path1 && test -f $path2; then
	echo "YES"
else
	echo "NO"
	echo "$me faking platforms"
	cwd=`pwd`; cd fhew_$PLAT
	mkdir -p native
	cp $libfhew libfftw3.a native/
	mkdir -p target
	cp $libfhew libfftw3.a target/
	cd $cwd
fi
