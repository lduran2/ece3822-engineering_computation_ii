# constants
cpp-v=c++17
compile=g++ -Wall -g --std=$(cpp-v)

# builds
.PHONY: all build tests clean lean-build clean-tests

all: build tests

build: main.out

# main program
#main.out: main.cpp hashtable.o binarysearchthree.o
#	$(compile) -o $@ $^

tests: tb_hashtable.out tb_student.out
	# noop

# test benches
tb_hashtable.out: tb_hashtable.cpp hashtable.o student.o
	$(compile) -o $@ $^

tb_student.out: tb_student.cpp student.o
	$(compile) -o $@ $^

# data structures
hashtable.o: hashtable.cpp student.o
	$(compile) -c $<

#binarysearchtree.o: binarysearchtree.cpp
#	$(compile) -c $<

# value structures
student.o: student.cpp
	$(compile) -c $<

# clean 
clean:
	-rm -f *.o *.out

