#!/bin/bash

PLAT=win
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
	pushd $root
	git -c http.sslVerify=false clone --branch master https://github.com/tfhe/tfhe.git tfhe
#	cd tfhe
#	git reset --hard 76db530cf736a25115ea0b0ccdb9267b401bb9a7
	popd
		if test -f $path; then
			echo "$me done"
		else
			echo "$me failed to checkout TFHE"
			exit
		fi
fi

x3264=`bash test_win.sh`

if [ "$x3264" == "x64" ] ; then
file_fftw_zip=fftw-3.3.5-dll64.zip
else
file_fftw_zip=fftw-3.3.5-dll32.zip
fi
fftwpath=$root/fftw/$PLAT.$x3264

echo ""
echo "Step 2"
echo -n "$me FFTW3 zip: "
file=$file_fftw_zip
down=ftp://ftp.fftw.org/pub/fftw/$file
path=$fftwpath/$file
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
	pushd $fftwpath
	wget $down
	popd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to download $file"
		exit
	fi
fi

echo ""
echo "Step 3"
if unzip.exe > /dev/null; then
 echo unzip is installed
else
 echo -n "$me unzip.exe: "
 file=unzip.exe
 down=http://mazonka.com/bin/$file
 path=$fftwpath/$file
 if test -f $path; then
	echo "YES"
 else
	echo "NO"
	echo "$me downloading unzip"
	pushd $fftwpath
	wget $down
	popd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to download $unzipfile"
		exit
	fi
 fi
fi

libfftw=libfftw3-3

echo ""
echo "Step 4"
echo -n "$me unpacked FFTW: "
file=$libfftw.dll
path=$fftwpath/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me unzipping FFTW"
	pushd $fftwpath
	test -f unzip.exe && chmod 0777 unzip.exe
	unzip.exe $file_fftw_zip
	popd

	if test -f $path; then
		echo "$me done"
	else
		echo "$me failed to unzip"
		exit
	fi
fi

##libfftwlib=libfftw3-3.lib

echo ""
echo "Step 5"
echo -n "$me FFTW lib: "
file=$libfftw.lib
path=$fftwpath/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me making FFTW lib"
	pushd $fftwpath
	lib /def:$libfftw.def
	popd

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
	echo "#include <string>" > tfhe_$PLAT/$testfile2.cpp
	cat $tfhedir/src/test/$testfile1.cpp | grep -v "sys/time.h" >> tfhe_$PLAT/$testfile2.cpp
	cp $tfhedir/src/include/*.h tfhe_$PLAT/inc/tfhe/
	cp $tfhedir/src/libtfhe/*.cpp tfhe_$PLAT/libtfhe/
	# remove abort from die_dramatically as we would handle the exceptions
	cat $tfhedir/src/libtfhe/tfhe_gate_bootstrapping.cpp | grep -v "abort()" > tfhe_$PLAT/libtfhe/tfhe_gate_bootstrapping.cpp
	cp $tfhedir/src/libtfhe/fft_processors/fftw/*.cpp tfhe_$PLAT/fftwa
	cp $tfhedir/src/libtfhe/fft_processors/fftw/*.h tfhe_$PLAT/inc/fftwa
	cp $fftwpath/*.h tfhe_$PLAT/inc/fftw3/
	cp $fftwpath/$libfftw.lib tfhe_$PLAT/
	cp $fftwpath/$libfftw.dll tfhe_$PLAT/

	echo "$me done"
fi

libtfhe=libtfhe.lib

echo ""
echo "Step 7"
echo -n "$me TFHE libs: "
file=$libtfhe
path=tfhe_$PLAT/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	pushd tfhe_$PLAT/libtfhe	
	echo "$me compiling libtfhe"
	cl -wd4297 -nologo -EHsc -I../inc/tfhe -I../inc/fftwa -c -D"M_PI=std::acos(-1)" -D"and=&&" *.cpp
	popd
	pushd tfhe_$PLAT/fftwa
	echo "$me compiling fftwa"
	cl -nologo -EHsc -I../inc/tfhe -I../inc/fftw3 -I../inc/fftwa -c -D"M_PI=std::acos(-1)" *.cpp
	cd ..
	echo "$me lilnking $file"
	lib /OUT:libtfhe.lib libtfhe/*.obj fftwa/*.obj
	popd
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
	pushd tfhe_$PLAT
	cl -nologo -EHsc -Iinc/tfhe $file.cpp $libtfhe $libfftw.lib
	popd
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
	pushd tfhe_$PLAT > /dev/null
	mkdir -p native
	cp $libtfhe $libfftw.lib $libfftw.dll native/
	mkdir -p target
	cp $libtfhe $libfftw.lib $libfftw.dll target/
	popd > /dev/null
fi
