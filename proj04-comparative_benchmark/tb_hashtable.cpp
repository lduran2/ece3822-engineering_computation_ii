// tb_hashtable.cpp
#include<iostream>
#include"hashtable.h"
using namespace std;

int main(){

    // declare table
    hash_table table1;

    // insert students into hash table
    table1.insert( student( "iyad" , "obeid" , 19143 , 4.00 ) );
    table1.insert( student( "joe" , "biden" , 20500 , 3.10 ) );
    table1.insert( student( "joe" , "dimaggio" , 40219 , 2.19 ) );
    table1.insert( student( "jeff" , "bridges" , 98231 , 3.25 ) );
    table1.insert( student( "jeff" , "daniels" , 20193 , 3.11 ) );
    table1.insert( student( "josh" , "bridges" , 38413 , 1.99 ) );
    table1.insert( student( "carl" , "sagan" , 12139 , 3.98 ) );
    table1.insert( student( "jill" , "biden" , 20500 , 3.95 ) );
    table1.insert( student( "jill" , "scott" , 19147 , 3.34 ) );

    // search for names in table
    // search-by-student?
    // search-by-firstname?

    table1.print_student("iyad"); // if "iyad" is found, print name and gpa

    string name2 = "joe";
    cout << name2 << (table1.search(name2)?" is ":" is not ") << "found" <<endl;

    string name3 = "eoj";
    cout << name3 << (table1.search(name3)?" is ":" is not ") << "found" <<endl;

    return 0;
}

