//  Project 3 Hash Table - Use Case
//  Created by Lukas Cho, William Wang, Flynn Pham
//  This file implements the login system use case

#include "hash_table.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
passwordHash - converts password string to numeric hash
Parameters: const string& password - password to hash
Precondition: password is a valid string
Postcondition: returns numeric hash value for the password
*/
int passwordHash(const string& password) {
    int hash = 0;
    for (char c : password) {
        hash = hash * 31 + c;
        // Keep hash within reasonable bounds to avoid overflow
        hash = hash % 1000000007;
    }
    return abs(hash);
}

/*
create_table - creates hash table from CSV file
Parameters: string fname - filename of CSV, int m - size of hash table
Precondition: fname is valid filename, m > 0
Postcondition: returns pointer to HashTable containing username/password pairs
*/
HashTable<string>* create_table(string fname, int m) {
    HashTable<string>* ht = new HashTable<string>(m);
    
    ifstream file(fname);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fname << endl;
        return ht;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password;
        
        // Parse CSV line
        if (getline(ss, username, ',') && getline(ss, password)) {
            // Trim whitespace from username
            size_t start = username.find_first_not_of(" \t\r\n");
            size_t end = username.find_last_not_of(" \t\r\n");
            if (start != string::npos && end != string::npos) {
                username = username.substr(start, end - start + 1);
            }
            
            // Trim whitespace from password
            start = password.find_first_not_of(" \t\r\n");
            end = password.find_last_not_of(" \t\r\n");
            if (start != string::npos && end != string::npos) {
                password = password.substr(start, end - start + 1);
            }
            
            // Store username as data and password hash as key
            int passKey = passwordHash(password);
            ht->insert(username, passKey);
        }
    }
    
    file.close();
    return ht;
}

/*
login - checks if username/password pair exists in hash table
Parameters: HashTable<string>* ht - the hash table, string username - username to check,
           string password - password to check
Precondition: ht is a valid hash table pointer
Postcondition: returns true if username/password pair exists, false otherwise
*/
bool login(HashTable<string>* ht, string username, string password) {
    if (ht == nullptr) {
        return false;
    }
    
    // Convert password to hash key
    int passKey = passwordHash(password);
    
    // Check if the username-password pair exists in the hash table
    return ht->member(username, passKey);
}