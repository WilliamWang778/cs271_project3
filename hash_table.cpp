//  Project 3 Hash Table
//  Created by Lukas Cho, William Wang, Flynn Pham
//  This is the cpp implementation file

#include <iostream>
#include <string>
#include <sstream>
#include "hash_table.h"

using namespace std;

////////////////////////////////////////////////////////////////////////

/*
Element Constructor
Parameters: None
Precondition: None
Postcondition: Element created with default data and key values, next and prev pointers initialized to nullptr
*/

template <typename T> 

Element<T> :: Element(){
    // int = 0, set string -> ""
    this -> data = T();
    // set k = -1
    this -> k = -1;
    this -> next = nullptr;
    this -> prev = nullptr;
}

/*
Element Constructor with parameters
Parameters: data to be stored in the element, k is the key associated with the element.
Precondition: Valid data and key provided
Postcondition: Element created with data and key, next and prev pointers initialized to nullptr
*/

template<typename T>
Element<T>::Element(const T& data, int k){
    this -> data = data;
    this -> k = k;
    this -> next = nullptr;
    this -> prev = nullptr;
}

/*
Deconstructor
Parameters: None
Precondition: Element exists
Postcondition: Element will be properly deallocated
*/

template<typename T>

Element<T>:: ~Element(){

}

/*
get_key
Parameters: None
Precondition: Element exists
Postcondition: returns key value
*/

template<typename T>
int Element<T>::get_key() const {
    return k;
}

/*
get_data
Parameters: None
Precondition: Element exists
Postcondition: returns data
*/

template<typename T>
const T& Element<T>::get_data() const { 
    return data;
}

////////////////////////////////////////////////////////////////////////



/* 
H function
Parameters: int k is the key
Precondition: HashTable exists
Postcondition: returns index in tabl for given key k
*/

template<typename T>
int HashTable<T>::h(int k) const {
    // if empty buckets, return 0.
    if (size == 0){
        return 0;
    }
    // compute k mod size. fix negatives so result is in [0, size-1].
    int index = k % size;
    if (index < 0){
        index = index + size;
    }
    return index;
}


/*
HashTable Constructor
Parameters: int m is the number of slots in the hash table
Precondition: m is a valid integer
Postcondition: HashTable created with m slots, it is initialized to be empty
*/

template <typename T>
HashTable<T>::HashTable(int m){

    // if size of table is smaller or equal to 0, we create a hash table with size and n to 0
    if (m <= 0){
        this -> size = 0;
        this -> n = 0;
        this -> table = nullptr;
        return;
    }
    // give value to size, size = m
    this -> size = m;
    // n at first is 0
    this -> n = 0;

    // create the new hash table for the specific size
    table = new Element<T>*[this -> size]();

}


/*
HashTable Destructor
Parameters: None
Precondition: HashTable exists
Postcondition: HashTable and all its Elements are properly deallocated
*/


template<typename T>
HashTable<T>::~HashTable(){

    // if size is 0, table is nullptr, do nothing.
    if (size == 0 || table == nullptr){
        return;
    }
    // walk through each bucket
    for (int i = 0; i < size; i++){
        // save next before deleting current
        Element<T>* current = table[i];
        // delete all nodes in this bucket's doubly linked list.
        while (current != nullptr){
            Element<T>* next = current -> next;
            delete current;
            current = next;
        }
    }
    // free the array of bucket heads.
    delete[] table;
}

/*
Insert
Parameters: Valid data and int k as key
Precondition: Valid data and int k as key provided
Postcondition: Element with data and key inserted at the head of the chain at index h(k)
*/

template <typename T>
void HashTable<T> :: insert(T data, int k){
    // if size is 0, table is nullptr, do nothing.
    if (size == 0 || table == nullptr){
        return;
    }
    // compute bucket index via h(k). 
    int index = h(k);
    // allocate a new node for (data, key)
    Element<T>* node = new Element<T>(data, k);

    // insert at head of the bucket's doubly linked list.
    node -> prev = nullptr;
    node -> next = table[index];

    // if the current head exists, fix its prev pointer to the new node.
    if (table[index] != nullptr){
        table[index] -> prev = node;
    }
    
    // update bucket head, change it to node
    table[index] = node;
    // update n
    this->n += 1;
}

/*
remove
Parameters: Valid int k as key
Precondition: valid int k as key provided
Postcondition: Element with given key removed if it exists
*/

template <typename T>
void HashTable<T> :: remove (int k){
    // if size is 0, table is nullptr, do nothing.
    if (size == 0 || table == nullptr){
        return;
    }
    // find the bucket for key k.
    int index = h(k);
    Element<T>* current = table[index];
    while (current != nullptr){
        if (current->get_key() == k){
            // relink previous node over current.
            if (current -> prev != nullptr){
                current -> prev -> next = current -> next;
            }
            else{
                // delete the head: move bucket head to next.
                table[index] = current -> next;
            }

            // relink next node back to previous.
            if (current -> next != nullptr){
                current -> next -> prev = current -> prev;
            }
            // free the removed node
            delete current;
            // update number of elemens
            n -= 1;
            return;
        }
        current = current -> next; 
    }
}


/*
member
Parameters: Valid data and int k as key
Precondition: Valid data and key provided
Postcondition: Returns true if element with data and key, false otherwise
*/
template<typename T>
bool HashTable<T>::member(T data, int k) {
    // if size is 0, table is nullptr, do nothing.
    if (size == 0 || table == nullptr){
        return false;
    }
    // find the bucket for key k.
    int index = h(k);
    Element<T>* current = table[index];
    
    // Traverse the chain at this index
    while (current != nullptr) {
        // match requires both key and data to be equal.
        if (current->get_key() == k && current->get_data() == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/*
to_string
Parameters: None
Precondition: HashTable exists
Postcondition: Returns string representation of the hash table
*/
template<typename T>
string HashTable<T>::to_string() {

    // empty table returns empty string 
    if (size == 0 || table == nullptr){
        return "";
    }
    stringstream ss;
    // for each bucket index i
    for (int i = 0; i < size; i++) {
        ss << i << ": ";

        // walk the doubly linked list at bucket i (head to tail).
        Element<T>* current = table[i];
        while (current != nullptr) {
            // print as "(data,key)" followed by a single space
            ss << "(" << current->get_data() << "," << current->get_key() << ") ";
            current = current->next;
        }
        // end the bucket with newline
        ss << "\n";
        
    }
    
    return ss.str();
}



