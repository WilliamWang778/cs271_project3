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

template <typename T>
HashTable<T>::HashTable(int m){
    if (m <= 0){
        m = 1;
    }
    this -> size = m;
    this -> n = 0;
    table = new Element<T>*[this -> size]();

}

template<typename T>
HashTable<T>::~HashTable(){
   
    for (int i = 0; i < size;i++){
        Element<T>* current = table[i];
        while (current != nullptr){
            Element<T>* next = current -> next;
            delete current;
            current = next;
        }
    }
    delete[] table;
}


template <typename T>
void HashTable<T> :: insert(T data, int k){
    int index = h(k);
    Element<T>* node = new Element<T>(data, k);
    node -> prev = nullptr;
    node -> next = table[index];
    if (table[index] != nullptr){
        table[index] -> prev = node;
    }
    table[index] = node;
    n += 1;
}

template <typename T>
void HashTable<T> :: remove (int k){
    int index = h(k);
    Element<T>* current = table[index];
    while (current != nullptr){
        if (current->get_key() == k){
            if (current -> prev != nullptr){
                current -> prev -> next = current -> next;
            }
            else{
                table[index] = current -> next;
            }

            if (current -> next != nullptr){
                current -> next -> prev = current -> prev;
            }
            delete current;
            n -= 1;
            return;
        }
        current = current -> next; 
    }
}






// H function
template<typename T>
int HashTable<T>::h(int k) const {
    int index = k % size;
    if (index < 0){
        index = index + size;
    }
    return index;
}

/*
Precondition: Valid data and key provided
Postcondition: Returns true if element with data and key exists, false otherwise
*/
template<typename T>
bool HashTable<T>::member(T data, int k) {
    int index = h(k);
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
