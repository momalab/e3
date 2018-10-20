#!/bin/bash

PLAT=unx
me="=== 3p ==="

root=../../e3_heli
helidir=$root/heli

echo "$me Cooking HELI for $PLAT"

echo ""
echo "Step 1"
echo -n "$me HELI checkout: "
file=src/Makefile
path=$root/heli/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out HELI"
	mkdir -p $root
	cwd=`pwd`; cd $root
	git -c http.sslVerify=false clone --branch master https://github.com/lducas/heli.git
	cd $cwd
	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to checkout HELI"
		exit
	fi
fi

ntl=ntl-11.0.0
file_ntl_tar=$ntl.tar.gz
ntlpath=$root/ntl/$PLAT/$ntl

echo ""
echo "Step 2"
echo -n "$me NTL tar: "
file=$file_ntl_tar
down=http://www.shoup.net/ntl/ntl-11.0.0.tar.gz
path=$root/ntl/$PLAT/$file
if test -f $path; then
	echo "YES"
else
	echo "NO $path"

	if wget --help > /dev/null; then
		echo "$me using wget"
	else
		echo "$me wget not found, exiting"
		exit
	fi

	echo "$me downloading NTL"
	mkdir -p $ntlpath
	cwd=`pwd`; cd $ntlwpath/../
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

ntl=ntl
echo ""
echo "Step 4"
echo -n "$me unpacked NTL: "
path=$ntlpath/src/configure
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me untarring NTL"
	cwd=`pwd`; cd $ntlpath/../
	tar zxvf $file_ntl_tar
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to untar"
		exit
	fi
fi

echo	 ""
echo "Step 5"
echo -n "$me NTL lib: "
path=$fftwpath/.libs/libfftw3.a

#if test -f $path; then
if test -d .; then
	echo "SKIPPED"
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

bin=heli_$PLAT
testfile1=Test_binaryArith
testfile2=test

echo ""
echo "Step 6"
echo -n "$me HELI ingredients: "
path=$bin/$testfile2.cpp
if test -f $path; then
	echo "YES"
else
	echo "NO $path"
	echo "$me preparing ingredients"
	mkdir -p heli_$PLAT
	mkdir -p heli_$PLAT/src
	mkdir -p heli_$PLAT/inc/ntl
	cp -R $helidir/src/* heli_$PLAT/src/
	mv heli_$PLAT/src/$testfile1.cpp heli_$PLAT/$testfile2.cpp
	cp $ntlpath/include/NTL/*.h heli_$PLAT/inc/ntl/

	echo "$me done"
fi

libheli=fhe.a

echo ""
echo "Step 7"
echo -n "$me HELI $libheli: "
file=src/$libheli
path=heli_$PLAT/$file
#if test -f $path; then
if test -d .; then
	echo "SKIPPED"
else
	echo "NO"
	cwd=`pwd`; cd heli_$PLAT/libheli	
	echo "$me compiling libheli"
	g++ -std=c++03 -I../inc/heli -I../inc/fftwa -c *.cpp
	echo "$me lilnking $file"
	cd ..
	ar rcs $libheli libheli/*.o
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
	cwd=`pwd`; cd heli_$PLAT
	#g++ -std=c++14 -Iinc/heli $file.cpp $libheli libfftw3.a -o $file.exe
	g++ -std=c++14 $file.cpp -Isrc src/fhe.a -lpthread -lntl -lgmp -o $file.exe
	cd $cwd

	if test -f $path; then
		echo "DONE"
	else
		echo "Failed to compile test"
	fi
fi

echo ""
echo "Step 9 - faking plats"
file=$libheli
path1=$bin/native/$file
path2=$bin/target/$file
echo -n "$me $path1 $path2: "
if test -f $path1 && test -f $path2; then
	echo "YES"
else
	echo "NO"
	echo "$me faking platforms"
	#pushd heli_$PLAT > /dev/null
	cwd=`pwd`; cd heli_$PLAT
	mkdir -p native
	cp src/$libheli native/
	mkdir -p target
	cp src/$libheli target/
	#popd > /dev/null
	cd $cwd
fi
