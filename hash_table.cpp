//  Project 3 Hash Table
//  Created by Lukas Cho, William Wang, Flynn Pham
//  This is the cpp implementation file

#include <iostream>
#include <string>
#include "hash_table.h"

using namespace std;

/*
Parameters: 
Precondition: 
Postcondition:
*/

template<typename T>
Element<T>::Element(T data, int key){
    this -> data = data;
    this -> key = key;
    this -> next = nullptr;
    this -> prev = nullptr;
}

/*
get_key
*/
template<typename T>
int Element<T>::get_key() {
    return key;
}

/*
get_data
*/

template<typename T>
T Element<T>::get_data() { 
    return data;
}

