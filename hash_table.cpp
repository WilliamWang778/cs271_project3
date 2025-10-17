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
Element<T>::Element(const T& data, int k){
    this -> data = data;
    this -> k = k;
    this -> next = nullptr;
    this -> prev = nullptr;
}

template<typename T>
Element<T>:: ~Element(){

}

/*
get_key
*/
template<typename T>
int Element<T>::get_key() const {
    return k;
}

/*
get_data
*/

template<typename T>
const T& Element<T>::get_data() const { 
    return data;
}

