// hashtable.h
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include<vector>
#include<cstddef>
#include"student.h"


class hash_table{

    public:
    void insert(student); // inserting a complete student record (first/last/zip/gpa)
    bool search (string,bool print_flag=false); // search by first name
    void print_student(string); // search for student, and if present, print
    hash_table(int n=100);
    void display();

    private:
    // old way: table is an array of strings
    // new way: table is an array of vectors of student
    
    // array of integers: option 1
    // int x[10]; <-- array length must be known ahead of time (compile-time)
    // array of integers: option 2
    // int *x = new int[10]; <-- array length can be decided at run time ("10" can be a variable)

    vector<student> *table_fn;
    vector<student> *table_ln;
    size_t array_len;
    int hash_function(string);
};

#endif //ndef __HASHTABLE_H__

