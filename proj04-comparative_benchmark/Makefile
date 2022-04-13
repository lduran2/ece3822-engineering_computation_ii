# constants
compile=g++
version=--std=c++17

# builds
.PHONY: all build tests clean lean-build clean-tests

all: build tests

build: main.out

# main program
#main.out: main.cpp hashtable.o binarysearchthree.o
#	$(compile) $(version) -o $@ $^

tests: tb_hashtable.out tb_student.out
	# noop

# test benches
tb_hashtable.out: tb_hashtable.cpp hashtable.o student.o
	$(compile) $(version) -o $@ $^

tb_student.out: tb_student.cpp student.o
	$(compile) $(version) -o $@ $^

# data structures
hashtable.o: hashtable.cpp student.o
	$(compile) $(version) -c $<

#binarysearchtree.o: binarysearchtree.cpp
#	$(compile) $(version) -c $<

# value structures
student.o: student.cpp
	$(compile) $(version) -c $<

# clean 
clean:
	-rm -f *.o *.out

