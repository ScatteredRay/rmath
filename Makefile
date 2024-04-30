CC=g++
CFLAGS=-I./include -I./external/doctest/doctest
OUT_ROOT=build/

build/rmath-test: tests/test.cpp source/vectormath.cpp
	mkdir -p $(@D)
	$(CC) -o $(OUT_ROOT)rmath-test tests/test.cpp source/vectormath.cpp $(CFLAGS)
