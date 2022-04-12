# constants
compile=g++
version=--std=c++17

# main program
main.out: main.cpp hashtable.o binarysearchthree.o
	$(compile) $(version) -o $@ $^

# data structures
hashtable.o: hashtable.cpp
	$(compile) $(version) -c $<

binarysearchtree.o: binarysearchtree.cpp
	$(compile) $(version) -c $<

# value structures
student.o: student.cpp
	$(compile) $(version) -c $<


