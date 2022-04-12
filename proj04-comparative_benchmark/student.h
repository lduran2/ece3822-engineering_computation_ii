// student.h

// guard against loading student.h more than once
#ifndef __STUDENT_H__
#define __STUDENT_H__

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

#endif // __STUDENT_H__

