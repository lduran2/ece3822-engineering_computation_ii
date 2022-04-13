// tb_hashtable.cpp
#include<cstddef>
#include<iostream>
#include<vector>
#include"hashtable.h"
using namespace std;

int main(){
    // fields for students
    enum { N_STUDENTS = 9 };
    string first_names[] = {
        "iyad",  "joe",   "joe",      "jeff",    "jeff",    "josh",
        "carl",  "jill",  "jill"
    };
    string last_names[] = {
        "obeid", "biden", "dimaggio", "bridges", "daniels", "bridges",
        "sagan", "biden", "scott"
    };
    int zip_codes[] = {
        19143,   20500,   40219,      98231,     20193,     38413,
        12139,   20500,   19147
    };
    float gpas[] = {
        4.00,    3.10,    2.19,       3.25,      3.11,      1.99,
        3.98,    3.95,    3.34
    };

    student a_student = student(first_names[0], last_names[0], zip_codes[0], gpas[0]);
    student b_student = student(first_names[1], last_names[1], zip_codes[1], gpas[1]);
    a_student.display();
    b_student.display();

    // initialize the students
    vector<student> students;
    for (size_t k = 0; (k < N_STUDENTS); ++k) {
        student s = student( first_names[k], last_names[k], zip_codes[k], gpas[k] );
        students.push_back(s);
    } // next k

    // print the student informations
    for (size_t k = 0; (k < N_STUDENTS); ++k) {
        students[k].display();
    } // next k

    return 0;
} // end int main()

