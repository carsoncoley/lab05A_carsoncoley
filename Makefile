#Makefile for lab05a

#CXX=clang++
#CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror
BINARIES= lab05test

lab05test: lab05test.o WordCount.o tddFuncs.o
	g++ $^ -o $@

tests: ${BINARIES}
	./lab05test

clean:
	/bin/rm -f ${BINARIES} *.o
