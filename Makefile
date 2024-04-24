CC=gcc
CFLAGS=-I./include
OUT_ROOT=build/

build/rmath-test: test.cpp
	mkdir -p $(@D)
	$(CC) -o $(OUT_ROOT)rmath-test test.cpp $(CFLAGS)
