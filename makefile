# This file demonstrates how to compile the hello-world project
# on Linux. Just run "make" to compile it.

GPP=g++
GCC=gcc
OUTFILE="helloworld.so"

COMPILE_FLAGS=-c -O3 -w -DLINUX -I../SDK/amx/

all:
	$(GCC) $(COMPILE_FLAGS) ../SDK/amx/*.c
	$(GPP) $(COMPILE_FLAGS) ../SDK/*.cpp
	$(GPP) $(COMPILE_FLAGS) *.cpp
	$(GPP) -O2 -fshort-wchar -shared -o $(OUTFILE) *.o