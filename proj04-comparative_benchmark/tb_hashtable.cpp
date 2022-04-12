#include<iostream>
#include<vector>
#include"student.h"
using namespace std;

class hash_table{

    public:
    void insert(student); // inserting a complete student record (first/last/zip/gpa)
    bool search (string,bool); // search by first name
    void print_student(string); // search for student, and if present, print
    hash_table(int);

    private:
    // old way: table is an array of strings
    // new way: table is an array of vectors of student
    
    // array of integers: option 1
    // int x[10]; <-- array length must be known ahead of time (compile-time)
    // array of integers: option 2
    // int *x = new int[10]; <-- array length can be decided at run time ("10" can be a variable)

    vector<*student> *table_first;
    vector<*student> *table_last;
    int array_len;
    int hash_function(string);
};

void hash_table::print_student(string target){
    search(target , true);
}

hash_table::hash_table(int n=100){
    // dynamic memory allocation for the table
    // array length is a user-defined variable
    array_len = n;
    table_first = new vector<*student>[array_len];
    table_last = new vector<*student>[array_len];
}

int hash_table::hash_function(string name){

    // a very crappy hash_function
    // return name.length() % array_len;

    // a slightly less bad hash_function
    // int s = 0;
    // for (int i = 0 ; i<name.length() ; i++){
    // s += (int)name[i];
    // } // returns sum of ascii character values in name

    // an even less crappy hash_function
    int s = 0;
    for (int i = 0; i<name.length(); i++){
        s += (i+1)* (int)name[i];
    }

    // force a collision: every string, regardless of value, maps to index 57
    // only useful for testing if collision resolution works
    // s = 57;             

    return s % array_len;

}

void hash_table::insert(student new_student){
    int index = hash_function( new_student.first_name ); // use the string first_name
    table_first[index].push_back(&new_student); // to create the hash index

    int index = hash_function( new_student.last_name ); // use the string last_name
    table_last[index].push_back(&new_student); // to create the hash index


    // collision strategy is to just overwrite whatever is in the table
    // we'll come back and make this less bad later

    // strategy 1: simply overwrite whenever there is a collision
    
    // strategy 2: compute index, if index is already used, try (index+1). repeat
    // until you find an empty spot, OR all spots are full

    // strategy 3: instead of having an array of STRING, have an array of VECTOR (linked list)
    // of STRING.
    // "iyad" -> hash -> index=27
    // OLD WAY: array[27] = "iyad"
    // NEW WAY: array[27].push_back("iyad");

}

bool hash_table::search(string target_first_name , bool print_flag = false){
    bool return_val = false;

    // this tells me which of the 100 linked lists to search
    int index = hash_function(target_first_name);

    // now I have to search the vector table[index] to see if it contains target
    for (int i = 0; i < table[index].size() ; i++){
        if (table[index][i].first_name == target_first_name){
            // target is found
            return_val = true;
            if (print_flag==true)
                table[index][i].display();
            break;
        }
    }

    return return_val;
}

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

