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
Parameters: data to be stored in the element, k is the key associated with the element.
Precondition: Valid data and key provided
Postcondition: Element created with data and key, next and prev pointers initialized to nullptr
*/

template <typename T> 

Element<T> :: Element(){
    this -> data = T();
    this -> k = -1;
    this -> next = nullptr;
    this -> prev = nullptr;
}


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
 // index = k mod size (when k mod size >= 0)
 // index = (k mod size) + size (when k mod size < 0)
*/

template<typename T>
int HashTable<T>::h(int k) const {
    if (size == 0){
        return 0;
    }
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

    if (m <= 0){
        this -> size = 0;
        this -> n = 0;
        this -> table = nullptr;
        return;
    }

    this -> size = m;
    this -> n = 0;

    table = new Element<T>*[this -> size]();

}


/*
HashTable Destructor
Precondition: HashTable exists
Postcondition: HashTable and all its Elements are properly deallocated
*/


template<typename T>
HashTable<T>::~HashTable(){
    if (size == 0 || table == nullptr){
        return;
    }
    for (int i = 0; i < size; i++){
        Element<T>* current = table[i];
        while (current != nullptr){
            Element<T>* next = current -> next;
            delete current;
            current = next;
        }
    }
    delete[] table;
}

/*
Insert
Precondition: Valid data and int k as key provided
Postcondition: Element with data and key inserted at the head of the chain at index h(k)
*/

template <typename T>
void HashTable<T> :: insert(T data, int k){
    if (size == 0 || table == nullptr){
        return;
    }
    int index = h(k);
    Element<T>* node = new Element<T>(data, k);

    node -> prev = nullptr;
    node -> next = table[index];
    
    if (table[index] != nullptr){
        table[index] -> prev = node;
    }
    
    table[index] = node;
    
    this->n += 1;
}

/*
remove
Precondition: valid int k as key provided
Postcondition: Element with given key removed if it exists
*/

template <typename T>
void HashTable<T> :: remove (int k){
    if (size == 0 || table == nullptr){
        return;
    }
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


/*
member
Precondition: Valid data and key provided
Postcondition: Returns true if element with data and key, false otherwise
*/
template<typename T>
bool HashTable<T>::member(T data, int k) {
    if (size == 0 || table == nullptr){
        return false;
    }
    int index = h(k);
    Element<T>* current = table[index];
    
    // Traverse the chain at this index
    while (current != nullptr) {
        if (current->get_key() == k && current->get_data() == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/*
to_string
Precondition: HashTable exists
Postcondition: Returns string representation of the hash table
*/
template<typename T>
string HashTable<T>::to_string() {
    if (size == 0 || table == nullptr){
        return "";
    }
    stringstream ss;
    
    for (int i = 0; i < size; i++) {
        ss << i << ": ";
        
        Element<T>* current = table[i];
        
        
        while (current != nullptr) {
           
            ss << "(" << current->get_data() << "," << current->get_key() << ") ";
         
            current = current->next;
        }
        
        
        ss << "\n";
        
    }
    
    return ss.str();
}



