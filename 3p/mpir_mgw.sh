#!/bin/bash

PLAT=mgw
me="=== 3p ==="

root=../../e3_mpir_$PLAT

mpirfname=mpir-3.0.0
mpirdir=$root/$mpirfname

echo "$me Cooking MPIR for $PLAT"

#git clone git://github.com/wbhart/mpir.git mpir
#http://mpir.org/mpir-3.0.0.tar.bz2
#yasm
#sh configure --disable-shared
#make
#cxx make libcxx.la

filetar=$mpirfname.tar.bz2
down=http://mpir.org/$filetar

echo ""
echo "Step 1"
echo -n "$me MPIR download: "
path=$root/$filetar
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

	echo "$me downloading MPIR"
	mkdir -p $mpirdir
	cwd=`pwd`; cd $mpirdir/../
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
echo "Step 2"
echo -n "$me MPIR untar (bzip2,tar): "
path=$mpirdir/configure
if test -f $path; then
	echo "YES"
else
	echo "NO $path"

	if bzip2 --help > /dev/null; then
		echo "$me using bzip2"
	else
		echo "$me bzip2 not found, exiting"
		exit
	fi

	if tar --help > /dev/null; then
		echo "$me using tar"
	else
		echo "$me tar not found, exiting"
		exit
	fi

	echo "$me untarring MPIR"
	cwd=`pwd`; cd $mpirdir/../
	bzip2 -d -k $filetar
    tar xvf $mpirfname.tar
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to untar $file"
		exit
	fi
fi

echo ""
echo "Step 3"
echo -n "$me check yasm: "
	if yasm --help > /dev/null; then
		echo "OK"
	else
		echo "not found, exiting (?# pacman -S mingw-w64-x86_64-yasm)"
		exit
	fi

echo ""
echo "Step 4"
echo -n "$me MPIR lib: "
path=$mpirdir/.libs/libmpir.a
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me making MPIR lib"
	cwd=`pwd`; cd $mpirdir
	sh configure --disable-shared
	make
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to make MPIR lib"
		exit
	fi
fi

echo ""
echo "Step 5"
echo -n "$me cxx lib: "
path=$mpirdir/cxx/.libs/libcxx.a
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me making cxx lib"
	cwd=`pwd`; cd $mpirdir/cxx
	make libcxx.la
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to make MPIR lib"
		exit
	fi
fi


echo ""
echo "Step 6"
echo -n "$me check libraries: "

bin=mpir_$PLAT
##path=$bin/$testfile2.cpp
mpirxx=libcxx.a
fmpirxxdir=$mpirdir/cxx/.libs
fmpirgcdir=$mpirdir/.libs
fmpirxxlib=$fmpirxxdir/$mpirxx

mkdir -p $bin

fcp()
{
	if test -f $1; then
		cp $1 $2/
	else
		echo "No file: $1"
		exit
	fi
}

if test -f $bin/$mpirxx; then
	echo "YES"
else
	echo "NO"
	echo "$me cheking if libraries are built"
	echo $fmpirxx
	if test -f $fmpirxxlib; then
		echo "copying mpir ingredients"

		# copy lib headers
		fcp $mpirdir/config.h $bin
		fcp $mpirdir/gmp-impl.h $bin
		fcp $mpirdir/gmp-mparam.h $bin
		fcp $mpirdir/mpirxx.h $bin
		fcp $mpirdir/mpir.h $bin

		# copy test files
		fcp $mpirdir/tests/memory.c $bin
		fcp $mpirdir/tests/misc.c $bin
		fcp $mpirdir/tests/tests.h $bin
		fcp $mpirdir/tests/cxx/t-binary.cc $bin

		# final copy
		fcp $fmpirgcdir/libmpir.a $bin
		fcp $fmpirgcdir/libmpir.la $bin
		fcp $fmpirxxdir/libcxx.a $bin
		fcp $fmpirxxdir/libcxx.la $bin

	else
		echo "The library $fmpirxxlib is not built"
	fi
fi


echo ""
echo "Step 7"
echo -n "$me check build: "

testfile=t-binary.exe

if test -f $bin/$testfile; then
	echo "YES"
else
	echo "NO"
	echo "$me compiling"
	cd $bin
	gcc -c misc.c memory.c
	g++ -std=c++14 -Wno-deprecated -DHAVE_SSTREAM=1 t-binary.cc misc.o memory.o -I. -L. -lcxx -lmpir -o $testfile
	cd ..

	if test -f $bin/$testfile; then
		echo "Compilation: ok"
	else
		echo "Compilation failed"
		exit
	fi
fi

echo ""
echo "Step 8 - faking plats"
files="libmpir.a libmpir.la libcxx.a libcxx.la"
path1=$bin/native/libcxx.a
path2=$bin/target/libcxx.a
echo -n "$me $path1 $path2: "
if test -f $path1 && test -f $path2; then
	echo "YES"
else
	echo "NO"
	echo "$me faking platforms"
	cd $bin
	mkdir -p native
	cp $files native/
	mkdir -p target
	cp $files target/
	cd ..
fi