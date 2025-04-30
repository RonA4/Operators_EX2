#Email ---> ronamsalem4@gmail.com
# Makefile
# This Makefile is used to build and run  C++ project.
# It supports compiling the main program, running unit tests,
# checking for memory leaks using valgrind, and cleaning up files.
# Targets:
# make main     - Compiles and builds the demo program (main.cpp).
# make test     - Compiles and runs unit tests (test.cpp with doctest).
# make valgrind - Runs valgrind on the demo to detect memory leaks.
# make clean    - Deletes all compiled files (binaries and temporary files).

CXX = g++
CXXFLAGS = -std=c++17 -pedantic -g -I.
SRC_DIR = SquareMat
TEST_DIR = Test

SRC = $(SRC_DIR)/SquareMat.cpp
DEMO = main.cpp
TEST = $(TEST_DIR)/test.cpp
DOCTEST = $(TEST_DIR)/doctest.h

TARGET = main
TEST_TARGET = test

.PHONY: all main test valgrind clean

all: main

main: $(SRC) $(DEMO)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(DEMO) $(SRC)

test: $(SRC) $(TEST) $(DOCTEST)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST) $(SRC)
	./$(TEST_TARGET)

valgrind: main
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.out *.o core
