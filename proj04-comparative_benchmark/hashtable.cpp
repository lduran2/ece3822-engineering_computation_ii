// hashtable.cpp
#include"hashtable.h"
#include<iostream>
#include<vector>
using namespace std;

void hash_table::print_student(string target){
    search(target , true);
}

hash_table::hash_table(int n){
    // dynamic memory allocation for the table
    // array length is a user-defined variable
    array_len = n;
    table_fn = new vector<student*>[array_len];
    table_ln = new vector<student*>[array_len];
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
    int index_fn = hash_function( new_student.first_name ); // use the string first_name
    table_fn[index_fn].push_back(&new_student); // to create the hash index

    int index_ln = hash_function( new_student.last_name ); // use the string last_name
    table_ln[index_ln].push_back(&new_student); // to create the hash index


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

bool hash_table::search(string target_first_name , bool print_flag){
    bool return_val = false;

    // use the first name table
    vector<student*> *table = table_fn;

    // this tells me which of the 100 linked lists to search
    int index = hash_function(target_first_name);

    // now I have to search the vector table[index] to see if it contains target
    for (int i = 0; i < table[index].size() ; i++){
        if (table[index][i]->first_name == target_first_name){
            // target is found
            return_val = true;
            if (print_flag==true)
                table[index][i]->display();
            break;
        }
    }

    return return_val;
}

