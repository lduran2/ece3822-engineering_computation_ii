// student.cpp
#include"student.h"
#include<iostream>
using namespace std;

student::student(string f, string l, int z, float g){
        first_name = f;
        last_name = l;
        zip_code = z;
        gpa = g;
}

void student::display(){
        cout << first_name << " " << last_name << " " << zip_code << " " << gpa << endl;
}

