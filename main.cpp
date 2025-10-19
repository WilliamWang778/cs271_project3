#include <iostream>
#include <string>
using namespace std;
#include "hash_table.h"
#include "usecase.cpp"
/*
Main function

Description: 
This file demonstrates the usecase implementation of a hash table based login system.
It shows the funtionality of the create_table and login functions defined on usecase.cpp.

Functionality:
1. Performs automated test cases to verify login functionality:
- Tests a valid username-password combination
- Tests an invalid username-password combination
2. Provides an interactive terminal interface for user login attempts

Input :
- CSV file "logins.csv" with username,password pairs
- User input with username and password.

Output:
- Results of automated login tests
- Interactive login result (Access granted/denied)

*/
int main(){

    const string csv = "logins.csv"; 

    const int m = 10;

    HashTable<string>* ht = create_table<string>(csv, m);

    if (ht == nullptr){
        cerr << "Failed to create hash table.\n";
        return 1;
    }
    // set the username and password we want to test with, one is granted, another is denied.
    string username1 = "EaQrMZZQisY";
    string password1 = "2091698288";
    string username2 = "fake-user";
    string password2 = "1122334455";

    // set two boolean variables to call login method
    bool check1 = login(ht, username1, password1);
    bool check2 = login(ht, username2, password2);

    // check if they are granted ot denied
    if (check1) {
        cout << "(" << username1 << "," << password1 << ") : granted\n";
    } else {
        cout << "(" << username1 << "," << password1 << ") : denied\n";
    }

    if (check2) {
        cout << "(" << username2 << "," << password2 << ") : granted\n";
    } else {
        cout << "(" << username2 << "," << password2 << ") : denied\n";
    }

    // print out the login interative page
    cout << "\n=== Login ===\n";
    cout << "Enter username: ";
    string user;
    if (! getline(cin, user)) return 0;

    cout << "Enter password: ";
    string pass;
    if (! getline(cin, pass)) return 0;

    if (login(ht, user, pass)) {
        cout << "Access granted\n";
    } else {
        cout << "Access denied\n";
    }

    // delete the hastable
    delete ht;
    return 0;
}








