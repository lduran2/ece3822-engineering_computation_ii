#include<iostream>
#include<vector>
using namespace std;

class student{
    public:
    string first_name;
    string last_name;
    int zip_code;
    float gpa;
    student(string f, string l, int z, float g){
        first_name = f;
        last_name = l;
        zip_code = z;
        gpa = g;
    }
    void display(){
        cout << first_name << " " << last_name << " " << zip_code << " " << gpa << endl;
    }
};

