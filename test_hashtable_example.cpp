//
//  test_hashtable_example.cpp
//  CS 271 Hash Table Project: Example Test File
//
//  Created by Dr. Stacey Truex
//

#include <iostream>
#include "usecase.cpp"

using namespace std;

void test_get_key()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << empty_elem.get_key() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << e.get_key() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_get_data()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << empty_elem.get_data() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got : " << e.get_data() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if (ht.to_string() != "0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.remove(5);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

void test_member()
{
    try
    {
        HashTable<int> empty_ht(0);
        if (empty_ht.member(10, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to determine membership in empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.member(11, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht.member(10, 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
}

void test_login()
{
    try
    {
        HashTable<string> *ht = create_table<string>("logins.csv", 10);
        string username = "IEv";
        string password = "7170790290";
        if (!login(ht, username, password))
        {
            cout << "Incorrect result validating accurate login information" << endl;
        }
        username = "bad-user";
        password = "98213873";
        if (login(ht, username, password))
        {
            cout << "Incorrect result validating inaccurate login information" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in accomplishing login validation : " << e.what() << endl;
    }
}

int main()
{
    string file_name = "usecase.cpp";
    cout << endl
         << "Running tests for " << file_name << endl
         << endl;

    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();
    test_login();

    cout << "Testing completed" << endl;

    return 0;
}