#!/bin/bash

# for fast execution replace with SPQLIOS - see tfhe_unx_fast.txt

PLAT=unx
me="=== 3p ==="

root=../../e3_tfhe
tfhedir=$root/tfhe

echo "$me Cooking TFHE for $PLAT"

echo ""
echo "Step 1"
echo -n "$me TFHE checkout: "
file=Makefile
path=$root/tfhe/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out TFHE"
	mkdir -p $root
	cwd=`pwd`; cd $root
	git -c http.sslVerify=false clone --branch master https://github.com/tfhe/tfhe.git
	cd $cwd
	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to checkout TFHE"
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
wget=wgetZ
if test -f $path; then
	echo "YES"
else
	echo "NO"

	if $wget --help > /dev/null; then
		echo "$me using wget"
	else
		echo "$me wget not found, try curl"
		if curl --help > /dev/null; then
			echo "$me using curl"
			wget="curl -o $file"
		else
			echo "$me no wget nor curl found, exiting"
			exit
		fi
	fi

	echo "$me downloading FFTW"
	mkdir -p $fftwpath
	cwd=`pwd`; cd $fftwpath/../
	$wget $down
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

##libfftw=libfftw3-3

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
	cp $tfhedir/src/test/$testfile1.cpp tfhe_$PLAT/$testfile2.cpp
	cp $tfhedir/src/include/*.h tfhe_$PLAT/inc/tfhe/
	cp $tfhedir/src/libtfhe/*.cpp tfhe_$PLAT/libtfhe/
	cp $tfhedir/src/libtfhe/fft_processors/fftw/*.cpp tfhe_$PLAT/fftwa
	cp $tfhedir/src/libtfhe/fft_processors/fftw/*.h tfhe_$PLAT/inc/fftwa
	cp $fftwpath/api/fftw3.h tfhe_$PLAT/inc/fftw3/
	cp $fftwpath/.libs/libfftw3.a tfhe_$PLAT/

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
