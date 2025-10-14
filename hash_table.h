//
//  Project 3 Hash Table
//  Created by Lukas Cho, William Wang, Flynn Pham
//  This is the header file

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

template<typename T> 
class Element {
private:
    T data;
    int key;
public:

    Element<T>* next; // next
    Element<T>* prev; // prev
    
    Element(T data, int key); // constructor 
    ~Element(); // destructor

    // Pre-condition : Element exists
    // Post-condition : returns key value
    int get_key(); 

    // Pre-condition : Element exists
    // Post-condition : returns data
    T get_data();

};

template<typename T>
class HashTable {
private:
    Element<T>** table; // pointers to Element (head of each chain)
    int size; // number of slots(m)

public:
    
    HashTable(int m); // constructor
    ~HashTable(); // destructor

    //
    void insert(T data, int key); 

    void remove(int key);

    void member(T data, int key);

    std::string to_string();

}

#include "hash_table.cpp"

#endif