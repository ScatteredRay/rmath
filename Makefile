CC=g++
CFLAGS=-I./include -I./external/doctest/doctest
OUT_ROOT=build/

build/rmath-test: tests/test.cpp
	mkdir -p $(@D)
	$(CC) -o $(OUT_ROOT)rmath-test tests/test.cpp $(CFLAGS)
