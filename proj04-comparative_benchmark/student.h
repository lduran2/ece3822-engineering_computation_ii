// student.h
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include<string>
using namespace std;

class student{
public:
    string first_name;
    string last_name;
    int zip_code;
    float gpa;
    student(string f, string l, int z, float g);
    void display();
};

#endif//ndef __STUDENT_H__

