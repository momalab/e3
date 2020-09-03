#!/bin/bash

# gmp requires m4

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
# this is how you download a specific commit
# thus, new updates in the repo won't break the framework
	git -c http.sslVerify=false clone --branch master https://github.com/shaih/HElib heli
	cd heli
	git reset --hard 65ef24c6147196b2e1bffa070e942eb04b43a019
# this is the new repo for when we decide to update the helib support
# git -c http.sslVerify=false clone --depth 1 https://github.com/homenc/HElib heli
	cd $cwd
	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to checkout HELI"
		exit
	fi
fi

#wget --no-check-certificate https://gmplib.org/download/gmp/gmp-6.1.2.tar.lz
gmp=gmp-6.1.2
#gmp=gmp-6.1.0
file_gmp_tar=$gmp.tar
file_gmp_tlz=$file_gmp_tar.lz
gmppath=$root/gmp/$PLAT/$gmp

echo ""
echo "Step 2a"
echo -n "$me GMP tar: "
file=$file_gmp_tlz
down=https://gmplib.org/download/gmp/$file
path=$root/gmp/$PLAT/$file
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

	echo "$me downloading GMP"
	mkdir -p $gmppath
	cwd=`pwd`; cd $gmppath/../
	wget --no-check-certificate $down
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to download $file"
		exit
	fi
fi

ntl=ntl-11.0.0
file_ntl_tar=$ntl.tar.gz
ntlpath=$root/ntl/$PLAT/$ntl

echo ""
echo "Step 2b"
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
	cwd=`pwd`; cd $ntlpath/../
	wget --no-check-certificate $down
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
echo -n "$me checking tar/plzip: "
if tar --help > /dev/null; then
	echo "YES"
else
	echo "NO"
	echo "$me please install tar"
	exit
fi
if plzip --help > /dev/null; then
	echo "YES"
else
	echo "NO"
	echo "$me please install plzip"
	exit
fi

gmp=gmp
echo ""
echo "Step 4a"
echo -n "$me unpacked GMP: "
path=$gmppath/configure
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me untarring GMP"
	cwd=`pwd`; cd $gmppath/../
	plzip -d -k $file_gmp_tlz
	tar xvf $file_gmp_tar
	cd $cwd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to untar"
		exit
	fi
fi

ntl=ntl
echo ""
echo "Step 4b"
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

gmp=gmp-6.1.2
echo	 ""
echo "Step 5a"
echo -n "$me GMP lib: "
path=testgmp.exe

RED='\033[0;31m'
NC='\033[0m' # No Color

if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me building a test with GMP"
	#g++ -std=c++14 -I $root/gmp/$PLAT/$gmp testgmp.cpp -lgmp -o testgmp.exe
	g++ -std=c++14 testgmp.cpp -lgmp -o testgmp.exe

	if test -f $path; then
		echo "$me done"
	else
		echo "${RED}$me failed to make GMP test"
		echo "USER ATTENTION!"
		echo "This script does not automatically build GMP"
		echo "Please follow the user manual and install"
		echo "GMP libraries on this and the target platforms"
		echo "GMP library has already been downloaded and unpacked in"
		echo "../../e3_heli/gmp"
		echo "Use the following commands to install it:"
		echo "$ cd ../../e3_heli/gmp/unx/gmp-6.1.2"
		echo "$ ./configure"
		echo "$ make"
		echo "$ make check"
		echo "$ make install${NC}"
		exit
	fi
fi

echo	 ""
echo "Step 5b"
echo -n "$me NTL lib: "
path=testntlgmp.exe

if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me building a test with NTL/GMP"
	#g++ -std=c++14 -I $root/gmp/$PLAT/$gmp -I $root/ntl/$PLAT/ntl-11.0.0/include testntlgmp.cpp -lgmp -lntl -o testntlgmp.exe
	g++ -std=c++14 testntlgmp.cpp -lgmp -lntl -o testntlgmp.exe

	if test -f $path; then
		echo "$me done"
	else
		echo "${RED}$me failed to make NTL test"
		echo "USER ATTENTION!"
		echo "This script does not automatically build NTL"
		echo "Please follow the user manual and install"
		echo "NTL and GMP libraries on this and the target platforms"
		echo "NTL library has already been downloaded and unpacked in"
		echo "../../e3_heli/ntl"
		echo "Use the following commands to install it:"
		echo "$ cd ntl-xxx/src"
		echo "$ ./configure"
		echo "$ make"
		echo "$ make check"
		echo "$ sudo make install${NC}"
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
	mkdir -p heli_$PLAT/inc/gmp
	cp -R $helidir/src/* heli_$PLAT/src/
	mv heli_$PLAT/src/$testfile1.cpp heli_$PLAT/$testfile2.cpp
	#rm heli_$PLAT/src/local-defs.example
	cp $ntlpath/include/NTL/*.h heli_$PLAT/inc/ntl/
	cp $gmppath/* heli_$PLAT/inc/gmp/

	echo "$me done"
fi

libheli=fhe.a
ntl=ntl-11.0.0

echo ""
echo "Step 7"
echo -n "$me HELI $libheli: "
file=src/$libheli
path=heli_$PLAT/$file
if test -f $path; then
#if test -d .; then
	echo "YES"
else
	echo "NO $path"
	cwd=`pwd`; cd heli_$PLAT/src
	#echo "$me compiling libheli"
	#g++ -std=c++03 -I../inc/heli -I../inc/fftwa -c *.cpp
	#echo "$me lilnking $file"
	#cd ..
	#ar rcs $libheli libheli/*.o
	#make INC_NTL=-I ../inc/ntl/ INC_GMP=-I ../inc/gmp/ LIB_NTL=-L ../inc/ntl/ LIB_GMP=-L ../inc/gmp/
	make
	#make -f mak_heli_fhe.mak INC_NTL=./../3p/heli_$PLAT/inc/ntl INC_GMP=./../3p/heli_$PLAT/inc/gmp LIB_NTL=./../3p/heli_$PLAT/inc/ntl LIB_GMP=./../3p/heli_$PLAT/inc/gmp
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
	g++ -std=c++14 $file.cpp -L ./src -I ./src -I . src/*.o -I ./inc/ntl -lpthread -lntl -lgmp -o $file.exe
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
