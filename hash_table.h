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
    int k;
public:

    Element<T>* next; 
    Element<T>* prev; 
    
    Element(const T& data, int k); 
    ~Element(); 

    // Pre-condition : Element exists
    // Post-condition : returns key value
    int get_key() const; 

    // Pre-condition : Element exists
    // Post-condition : returns data
    const T& get_data() const;

};

template<typename T>
class HashTable {
private:
    Element<T>** table; // pointers to Element (head of each chain)
    int size; // number of slots(m)
    int n;
    int h(int k) const;

public:
    
    HashTable(int m); // constructor
    ~HashTable(); // destructor
    
    // Insert operation
    // Pre-condition: valid data and key provided
    // Post-condition: Element with data and key inserted at head of appropriate chain
    void insert(T data, int k); 

    // Remove operation
    // Pre-condition: valid key provided
    // Post-condition: Element with given key removed if it exists
    void remove(int k);

    // Pre-condition: valid key provided
    // Post-condition : returns true if Element with data and key exists, false otherwise
    bool member(T data, int k);
    
    std::string to_string();

};

#include "hash_table.cpp"

#endif