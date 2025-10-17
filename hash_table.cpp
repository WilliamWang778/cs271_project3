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

/*
Precondition: Valid data and key provided
Postcondition: Returns true if element with data and key exists, false otherwise
*/
template<typename T>
bool HashTable<T>::member(T data, int key) {
    int index = key % size;
    Element<T>* current = table[index];
    
    // Traverse the chain at this index
    while (current != nullptr) {
        if (current->get_key() == key && current->get_data() == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/*
Precondition: HashTable exists
Postcondition: Returns string representation of the hash table
*/
template<typename T>
string HashTable<T>::to_string() {
    stringstream ss;
    
    for (int i = 0; i < size; i++) {
        ss << i << ":";
        
        Element<T>* current = table[i];
        bool first = true;
        
        while (current != nullptr) {
            if (!first) {
                ss << " ";
            }
            ss << "(" << current->get_data() << "," << current->get_key() << ")";
            first = false;
            current = current->next;
        }
        
        if (i < size - 1) {
            ss << "\n";
        }
    }
    
    return ss.str();
}