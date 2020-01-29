
all: crcl.exe

crcl.exe: cudd1/main.exe cudd0/main.exe
	cd crcl && make

cudd1/main.exe:
	cd cudd1 && make

cudd0/main.exe:
	cd cudd0 && make

c clean:
	cd crcl && make clean
	cd cudd1 && make clean
	cd cudd0 && make clean

