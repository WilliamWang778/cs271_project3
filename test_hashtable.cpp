#include <iostream>
#include <limits>
#include <string>
#include "usecase.cpp"


using namespace std;


void test_get_key()
{
  cout << "Testing Element get_key()" << endl;

  try
    {   
        // Default Constructor
        Element<int> element_empty;
        if (element_empty.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << element_empty.get_key() << endl;
        }

        // Positive Key
        Element<int> element_positive(10, 6);
        if (element_positive.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << element_positive.get_key() << endl;
        }
        
        // Negative key
        Element<string> element_negative("data1", -95);
        if (element_negative.get_key() != -95) {
            cout << "Incorrect result from get key. Expected -95 but got: " << element_negative.get_key() << endl;
        }

        // zero key
        Element<string> e_zero("data2", 0);
        if (e_zero.get_key() != 0) {
            cout << "Incorrect result from get key. Expected 0 but got: " << e_zero.get_key() << endl;
        }
        
        cout << "PASSED" << endl;

    }

    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}




void test_get_data()
{
    cout << "Testing Element get_data()" << endl;
    
    try
    {
        // Default Constructor - int
        Element<int> element_empty_int;
        if (element_empty_int.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got: " << element_empty_int.get_data() << endl;
        }
        
        // Positive data - int
        Element<int> element_int(10, 6);
        if (element_int.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got: " << element_int.get_data() << endl;
        }
        
        // String data
        Element<string> element_string("LukasWilliamFlynn", 69);
        if (element_string.get_data() != "LukasWilliamFlynn")
        {
            cout << "Incorrect result from get data. Expected 'LukasWilliamFlynn' but got: " << element_string.get_data() << endl;
        }
        
        // Empty string data
        Element<string> element_empty_string("", 74);
        if (element_empty_string.get_data() != "")
        {
            cout << "Incorrect result from get data. Expected empty string but got: " << element_empty_string.get_data() << endl;
        }
        
        // Double data
        Element<double> element_double(3.14159, 18);
        if (element_double.get_data() != 3.14159)
        {
            cout << "Incorrect result from get data. Expected 3.14159 but got: " << element_double.get_data() << endl;
        }
        
        // Negative data - int
        Element<int> element_negative(-999, 3);
        if (element_negative.get_data() != -999)
        {
            cout << "Incorrect result from get data. Expected -999 but got: " << element_negative.get_data() << endl;
        }
        
        cout << "PASSED" << endl;
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element: " << e.what() << endl;
    }
}



void test_insert()
{
<<<<<<< Updated upstream
    cout << "Testing HashTable insert()" << endl;
    
    try
    {
        // Insert into empty table which is size 0
=======

    // empty 
    try{
        HashTable<int> ht0(0);
        ht0.insert(120,678);
        if (ht0.to_string()!= ""){
            cout << "Insert into size=0 should keep empty string\nGot:\n" << ht0.to_string() << "\n";
        }
    } catch (exception& e){
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;

    }

    // one insert
    try {
        HashTable<int> ht(5);
        ht.insert(15, 6); 
        string got = ht.to_string();
        string exp = "0: \n1: (15,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Single insert\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Single insert: " << e.what() << "\n";
    }

    // multiple insert in same bucket
    try {
        HashTable<int> ht(5);
        ht.insert(15, 6);  
        ht.insert(1, 21);  
        string got = ht.to_string();
        string exp = "0: \n1: (1,21) (15,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Collision and head-insert order\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Collisions and head-insert: " << e.what() << "\n";
    }

    // multiple insert
    try {
        HashTable<int> ht(5);
        ht.insert(100, 0);  
        ht.insert(200, 2);   
        ht.insert(300, 4);   
        string got = ht.to_string();
        string exp = "0: (100,0) \n1: \n2: (200,2) \n3: \n4: (300,4) \n";
        if (got != exp) {
            cout << "Multiple buckets distribution\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Multiple bucket: " << e.what() << "\n";
    }


    // negative k
    try {
        HashTable<int> ht(5);
        ht.insert(111, -1);
        if (!ht.member(111, -1)) {
            cout << "Negative key should be stored and found\n";
        }
        ht.insert(1, 0);
        ht.insert(2, 5);
        ht.insert(3, 10);
        string s = ht.to_string();
        if (s.find("0: (3,10) (2,5) (1,0) ") == string::npos) {
            cout << "Collision order with negatives not as expected.\nGot:\n" << s << "\n";
        }
    } catch (exception& e) {
        cout << "Negative key: " << e.what() << "\n";
    }


    // k is INT_MAX
    try {
        HashTable<int> ht(7);
        int MaxNum = std::numeric_limits<int>::max();
        ht.insert(99, MaxNum);
        if (!ht.member(99, MaxNum)) {
            cout << "Large key should be found\n";
        }
    } catch (exception& e) {
        cout << "Large key: " << e.what() << "\n";
    }


    // insert string
    try {
        HashTable<string> hs(5);
        hs.insert(string("alpha"), 6); 
        string got = hs.to_string();
        string exp = "0: \n1: (alpha,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Insert string data\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "String data insert: " << e.what() << "\n";
    }


    // same k
    try {
        HashTable<int> ht(5);
        ht.insert(111, 8);
        ht.insert(222, 8); 
        string got = ht.to_string();
        if (got.find("3: (222,8) (111,8) ") == string::npos) {
            cout << "Duplicate key inserts should appear head-first in same bucket\nGot:\n" << got << "\n";
        }
    } catch (exception& e) {
        cout << "Duplicate-key insert: " << e.what() << "\n";
    }


    // insert float
    try {
        HashTable<float> hf(5);
        hf.insert(1.55, 6); 
        string got = hf.to_string();
        string exp = "0: \n1: (1.55,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Insert<float> basic\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }

       
        hf.insert(3.25, 11); 
        got = hf.to_string();
        exp = "0: \n1: (3.25,11) (1.55,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Insert<float> collision head-insert order\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Float insert: " << e.what() << "\n";
    }


    // insert bool

    try {
        HashTable<bool> hb(3);
        hb.insert(true, 4);  
        string got = hb.to_string();
        string exp = "0: \n1: (1,4) \n2: \n";
        if (got != exp){
            cout << "Insert<bool> basic\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }

        hb.insert(false, 7); 
        got = hb.to_string();
        exp = "0: \n1: (0,7) (1,4) \n2: \n";
        if (got != exp) {
            cout << "Insert<bool> collision head-insert order\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Bool insert: " << e.what() << "\n";
    }


    // insert long long
    try {
        HashTable<long long> hl(4);
        hl.insert(900000000000LL, 6); 
        string got = hl.to_string();
        string exp = "0: \n1: \n2: (900000000000,6) \n3: \n";
        if (got != exp) {
            cout << "Insert<long long> basic\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }

     
        hl.insert(800000000000LL, 10); 
        got = hl.to_string();
        exp = "0: \n1: \n2: (800000000000,10) (900000000000,6) \n3: \n";
        if (got != exp) {
            cout << "Insert<long long> collision head-insert order\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }

        
        hl.insert(700000000000LL, 1); 
        hl.insert(600000000000LL, 3); 
        got = hl.to_string();
        exp =
            "0: \n"
            "1: (700000000000,1) \n"
            "2: (800000000000,10) (900000000000,6) \n"
            "3: (600000000000,3) \n";
        if (got != exp) {
            cout << "Insert<long long> multi-bucket distribution\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "long long insert: " << e.what() << "\n";
    }

>>>>>>> Stashed changes

        HashTable<int> empty_ht(0);

        empty_ht.insert(10, 6);

        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into empty table. Expected empty string but got:\n" << empty_ht.to_string() << endl;
        }
    }

    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table: " << e.what() << endl;
    }
    
    try
    {
        // Single insert
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected:\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got:\n" << ht.to_string() << endl;
        }
        
        // Insert with collision (chaining test)
        ht.insert(1, 21);  // 21 % 5 = 1, collision with key 6
        if (ht.to_string() != "0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting with collision. Expected:\n0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n\nBut got:\n" << ht.to_string() << endl;
        }
        
        // Insert with negative key
        HashTable<string> ht_neg(5);
        ht_neg.insert("negative", -7);  // -7 % 5 = -2, then -2 + 5 = 3
        if (!ht_neg.member("negative", -7))
        {
            cout << "Incorrect result of inserting negative key. Element not found in table" << endl;
        }
        
        // Multiple inserts without collision
        HashTable<string> ht_multi(10);
        ht_multi.insert("first", 1);
        ht_multi.insert("second", 2);
        ht_multi.insert("third", 3);
        if (!ht_multi.member("first", 1) || !ht_multi.member("second", 2) || !ht_multi.member("third", 3))
        {
            cout << "Incorrect result of multiple inserts without collision" << endl;
        }
        
        // Insert with zero key
        HashTable<int> ht_zero(5);
        ht_zero.insert(999, 0);
        if (ht_zero.to_string() != "0: (999,0) \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting zero key. Expected:\n0: (999,0) \n1: \n2: \n3: \n4: \n\nBut got:\n" << ht_zero.to_string() << endl;
        }
        
        // Multiple collisions in same slot
        HashTable<string> ht_chain(5);
        ht_chain.insert("first", 3);
        ht_chain.insert("second", 8);   // 8 % 5 = 3
        ht_chain.insert("third", 13);   // 13 % 5 = 3
        if (ht_chain.to_string() != "0: \n1: \n2: \n3: (third,13) (second,8) (first,3) \n4: \n")
        {
            cout << "Incorrect result of multiple collisions. Expected:\n0: \n1: \n2: \n3: (third,13) (second,8) (first,3) \n4: \n\nBut got:\n" << ht_chain.to_string() << endl;
        }
        
        cout << "PASSED" << endl;
    }
    
    catch (exception &e)
    {
        cerr << "Error inserting into table: " << e.what() << endl;
    }
}
   








void test_remove()
{

    // remove empty
    try {
        HashTable<int> ht0(0);
        ht0.remove(123);
        if (ht0.to_string() != "") {
            cout << "Remove on size=0 should keep empty string\nGot:\n"
                 << ht0.to_string() << "\n";
        }
    } catch (exception& e) {
        cout << "Remove on size=0: " << e.what() << "\n";
    }

    // remove non-member
    try {
        HashTable<int> ht(5);
        ht.insert(15, 6);
        ht.remove(5); 
        string got = ht.to_string();
        string exp = "0: \n1: (15,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Remove non-member should not change table\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Remove non-member: " << e.what() << "\n";
    }


    // remove head
    try {
        HashTable<int> ht(5);
        ht.insert(15, 6); 
        ht.remove(6);
        string got = ht.to_string();
        string exp = "0: \n1: \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Remove head as single node\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Remove single head: " << e.what() << "\n";
    }



    // remove head, tail and then the middle one
    try {
        HashTable<int> ht(5);
        ht.insert(100, 1);   
        ht.insert(200, 6);   
        ht.insert(300, 31); 
        
        ht.remove(31);
        string got1 = ht.to_string();
        string exp1 = "0: \n1: (200,6) (100,1) \n2: \n3: \n4: \n";
        if (got1 != exp1) {
            cout << "Remove head of chain\nGot:\n" << got1 << "\nExpected:\n" << exp1 << "\n";
        }
        
        ht.remove(1);
        string got2 = ht.to_string();
        string exp2 = "0: \n1: (200,6) \n2: \n3: \n4: \n";
        if (got2 != exp2) {
            cout << "Remove tail of chain\nGot:\n" << got2 << "\nExpected:\n" << exp2 << "\n";
        }
        
        ht.remove(6);
        string got3 = ht.to_string();
        string exp3 = "0: \n1: \n2: \n3: \n4: \n";
        if (got3 != exp3) {
            cout << "Remove last node leaves empty bucket\nGot:\n" << got3 << "\nExpected:\n" << exp3 << "\n";
        }
    } catch (exception& e) {
        cout << "Remove head/middle/tail: " << e.what() << "\n";
    }


    // k is negative
    try {
        HashTable<int> ht(5);
        ht.insert(111, -1);
        if (!ht.member(111, -1)) {
            cout << "Negative key should be inserted first\n";
        }
        ht.remove(-1);
        if (ht.member(111, -1)) {
            cout << "Negative key should be removed\n";
        }
    } catch (exception& e) {
        cout << "Remove negative key: " << e.what() << "\n";
    }


    // remove same data two times but not crashing
    try {
        HashTable<int> ht(3);
        ht.insert(5, 0);
        ht.remove(0);   
        ht.remove(0);  
        string got = ht.to_string();
        string exp = "0: \n1: \n2: \n";
        if (got != exp) {
            cout << "Double remove should be safe no operation the second time\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Double remove: " << e.what() << "\n";
    }


    // remove INT_MAX key
    try {
        HashTable<int> ht(7);
        int NumMax = std::numeric_limits<int>::max();
        ht.insert(42, NumMax);
        if (!ht.member(42, NumMax)) {
            cout << "Large key should be found before remove\n";
        }
        ht.remove(NumMax);
        if (ht.member(42, NumMax)) {
            cout << "Large key should not be found after remove\n";
        }
    } catch (exception& e) {
        cout << "Remove large key: " << e.what() << "\n";
    }

    // remove when data is string
    try {
        HashTable<string> hs(5);
        hs.insert("hello", 6);
        hs.insert("world", 6); 
        hs.remove(6);          
        string got = hs.to_string();
        string exp = "0: \n1: (hello,6) \n2: \n3: \n4: \n";
        if (got != exp) {
            cout << "Remove with string data preserves remaining\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
        }
    } catch (exception& e) {
        cout << "Remove string data: " << e.what() << "\n";
    }



    // remove data is float
    try {
        HashTable<float> hf(5);
        hf.insert(1.55, 6);    
        hf.insert(3.25, 11);  
        hf.remove(11);
        {
            string got = hf.to_string();
            string exp = "0: \n1: (1.55,6) \n2: \n3: \n4: \n";
            if (got != exp) {
                cout << "Remove<float> head\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }

        
        hf.remove(6);
        {
            string got = hf.to_string();
            string exp = "0: \n1: \n2: \n3: \n4: \n";
            if (got != exp) {
                cout << "Remove<float> last node leaves empty bucket\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }
    } catch (exception& e) {
        cout << "Float remove: " << e.what() << "\n";
    }


    // remove when data is bool
    try {
        HashTable<bool> hb(3);
        hb.insert(true, 4);   
        hb.insert(false, 7);  

        hb.remove(7);
        {
            string got = hb.to_string();
            string exp = "0: \n1: (1,4) \n2: \n";
            if (got != exp) {
                cout << "Remove<bool> head\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }

        hb.remove(4);
        {
            string got = hb.to_string();
            string exp = "0: \n1: \n2: \n";
            if (got != exp) {
                cout << "Remove<bool> last node leaves empty bucket\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }
    } catch (exception& e) {
        cout << "Bool remove: " << e.what() << "\n";
    }


    // remove when data is long long
    try {
        HashTable<long long> hl(4);
        hl.insert(1000000000000LL, 2);   
        hl.insert(2000000000000LL, 6);   
        hl.insert(3000000000000LL, 10);  

        {
            string got = hl.to_string();
            string exp =
                "0: \n"
                "1: \n"
                "2: (3000000000000,10) (2000000000000,6) (1000000000000,2) \n"
                "3: \n";
            if (got != exp) {
                cout << "Setup<long long> initial chain order\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }

        hl.remove(10);
        {
            string got = hl.to_string();
            string exp =
                "0: \n"
                "1: \n"
                "2: (2000000000000,6) (1000000000000,2) \n"
                "3: \n";
            if (got != exp) {
                cout << "Remove<long long> head\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }

        hl.remove(2);
        {
            string got = hl.to_string();
            string exp =
                "0: \n"
                "1: \n"
                "2: (2000000000000,6) \n"
                "3: \n";
            if (got != exp) {
                cout << "Remove<long long> tail\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }

        hl.remove(6);
        {
            string got = hl.to_string();
            string exp =
                "0: \n"
                "1: \n"
                "2: \n"
                "3: \n";
            if (got != exp) {
                cout << "Remove<long long> last node leaves empty bucket\nGot:\n" << got << "\nExpected:\n" << exp << "\n";
            }
        }
    } catch (exception& e) {
        cout << "long long remove: " << e.what() << "\n";
    }






}










    
   







void test_member()
{
    






}







void test_login()
{
    






}

// ============================================================================
// Test Cases for member() Method
// ============================================================================


void test_member_single_element_found() {
    HashTable<string> ht(5);
    ht.insert("apple", 10);
    
    assert(ht.member("apple", 10) == true);
    cout << "test_member_single_element_found passed" << endl;
}

/**
 * Test: member_single_element_not_found_wrong_data
 * Pre-condition: HashTable contains one element
 * Post-condition: member returns false when data doesn't match
 */
void test_member_single_element_not_found_wrong_data() {
    HashTable<string> ht(5);
    ht.insert("apple", 10);
    
    assert(ht.member("orange", 10) == false);
    cout << "test_member_single_element_not_found_wrong_data passed" << endl;
}

/**
 * Test: member_single_element_not_found_wrong_key
 * Pre-condition: HashTable contains one element
 * Post-condition: member returns false when key doesn't match
 */
void test_member_single_element_not_found_wrong_key() {
    HashTable<string> ht(5);
    ht.insert("apple", 10);
    
    assert(ht.member("apple", 20) == false);
    cout << "test_member_single_element_not_found_wrong_key passed" << endl;
}

/**
 * Test: member_empty_table
 * Pre-condition: HashTable is empty
 * Post-condition: member returns false for any query
 */
void test_member_empty_table() {
    HashTable<string> ht(5);
    
    assert(ht.member("any", 0) == false);
    cout << "test_member_empty_table passed" << endl;
}

/**
 * Test: member_collision_chain
 * Pre-condition: HashTable contains multiple elements that hash to same slot
 * Post-condition: member correctly finds all elements in collision chain
 */
void test_member_collision_chain() {
    HashTable<string> ht(5);
    // 5 % 5 = 0, 10 % 5 = 0, 15 % 5 = 0 (all hash to slot 0)
    ht.insert("first", 5);
    ht.insert("second", 10);
    ht.insert("third", 15);
    
    assert(ht.member("first", 5) == true);
    assert(ht.member("second", 10) == true);
    assert(ht.member("third", 15) == true);
    assert(ht.member("wrong", 5) == false);
    cout << "test_member_collision_chain passed" << endl;
}

/**
 * Test: member_after_removal
 * Pre-condition: HashTable contained element, element was removed
 * Post-condition: member returns false for removed element
 */
void test_member_after_removal() {
    HashTable<string> ht(5);
    ht.insert("apple", 10);
    assert(ht.member("apple", 10) == true);
    
    ht.remove(10);
    assert(ht.member("apple", 10) == false);
    cout << "test_member_after_removal passed" << endl;
}

/**
 * Test: member_partial_collision_removal
 * Pre-condition: Collision chain with middle element removed
 * Post-condition: member still finds remaining elements in chain
 */
void test_member_partial_collision_removal() {
    HashTable<string> ht(5);
    ht.insert("first", 5);
    ht.insert("second", 10);
    ht.insert("third", 15);
    
    ht.remove(10);
    
    assert(ht.member("first", 5) == true);
    assert(ht.member("second", 10) == false);
    assert(ht.member("third", 15) == true);
    cout << "test_member_partial_collision_removal passed" << endl;
}

/**
 * Test: member_boundary_table_size_one
 * Pre-condition: HashTable with size 1 (all elements collide)
 * Post-condition: member correctly searches long collision chain
 */
void test_member_boundary_table_size_one() {
    HashTable<string> ht(1);
    ht.insert("first", 0);
    ht.insert("second", 1);
    ht.insert("third", 99);
    ht.insert("fourth", 100);
    
    assert(ht.member("first", 0) == true);
    assert(ht.member("second", 1) == true);
    assert(ht.member("third", 99) == true);
    assert(ht.member("fourth", 100) == true);
    assert(ht.member("missing", 50) == false);
    cout << "test_member_boundary_table_size_one passed" << endl;
}

/**
 * Test: member_multiple_templates
 * Pre-condition: HashTable with integer template type
 * Post-condition: member works correctly with different data types
 */
void test_member_multiple_templates() {
    HashTable<int> ht_int(5);
    ht_int.insert(42, 10);
    assert(ht_int.member(42, 10) == true);
    assert(ht_int.member(99, 10) == false);
    
    HashTable<double> ht_double(5);
    ht_double.insert(3.14, 20);
    assert(ht_double.member(3.14, 20) == true);
    cout << "test_member_multiple_templates passed" << endl;
}

// ============================================================================
// Test Cases for to_string() method
// ============================================================================

/**
 * Test: to_string_empty_table
 * Pre-condition: HashTable is empty with size m
 * Post-condition: to_string returns string with m slots, all empty
 */
void test_to_string_empty_table() {
    HashTable<string> ht(3);
    
    string result = ht.to_string();
    stringstream ss(result);
    string line;
    int lines = 0;
    
    while (getline(ss, line)) {
        lines++;
    }
    
    // Should have 3 lines (0:, 1:, 2:)
    assert(lines == 3);
    cout << "test_to_string_empty_table passed" << endl;
}

/**
 * Test: to_string_single_element
 * Pre-condition: HashTable contains one element
 * Post-condition: to_string shows element in correct slot with format (data,key)
 */
void test_to_string_single_element() {
    HashTable<string> ht(5);
    ht.insert("test", 28);
    // 28 % 5 = 3, so element goes to slot 3
    
    string result = ht.to_string();
    
    assert(result.find("3: (test,28)") != string::npos);
    cout << "test_to_string_single_element passed" << endl;
}

/**
 * Test: to_string_multiple_elements
 * Pre-condition: HashTable with elements in multiple different slots
 * Post-condition: to_string shows all elements in their correct slots
 */
void test_to_string_multiple_elements() {
    HashTable<string> ht(10);
    ht.insert("apple", 5);   // 5 % 10 = 5
    ht.insert("banana", 13);  // 13 % 10 = 3
    ht.insert("cherry", 21);  // 21 % 10 = 1
    
    string result = ht.to_string();
    
    assert(result.find("1: (cherry,21)") != string::npos);
    assert(result.find("3: (banana,13)") != string::npos);
    assert(result.find("5: (apple,5)") != string::npos);
    cout << "test_to_string_multiple_elements passed" << endl;
}

/**
 * Test: to_string_collision_chain
 * Pre-condition: HashTable with multiple elements hashing to same slot
 * Post-condition: to_string shows all elements in chain (newest first)
 */
void test_to_string_collision_chain() {
    HashTable<string> ht(5);
    ht.insert("first", 5);   // 5 % 5 = 0
    ht.insert("second", 10); // 10 % 5 = 0
    ht.insert("third", 15);  // 15 % 5 = 0
    
    string result = ht.to_string();
    
    // Find the slot 0 line
    size_t slot0_pos = result.find("0:");
    size_t slot1_pos = result.find("1:");
    string slot0_content = result.substr(slot0_pos, slot1_pos - slot0_pos);
    
    // All elements should be in slot 0
    assert(slot0_content.find("(third,15)") != string::npos);
    assert(slot0_content.find("(second,10)") != string::npos);
    assert(slot0_content.find("(first,5)") != string::npos);
    
    // Verify insertion order (newest at head)
    assert(slot0_content.find("third") < slot0_content.find("second"));
    assert(slot0_content.find("second") < slot0_content.find("first"));
    cout << "test_to_string_collision_chain passed" << endl;
}

/**
 * Test: to_string_after_removal
 * Pre-condition: HashTable with elements, some removed
 * Post-condition: to_string does not show removed elements
 */
void test_to_string_after_removal() {
    HashTable<string> ht(5);
    ht.insert("apple", 5);
    ht.insert("banana", 10);
    ht.insert("cherry", 15);
    
    ht.remove(10);
    
    string result = ht.to_string();
    
    assert(result.find("apple") != string::npos);
    assert(result.find("banana") == string::npos);
    assert(result.find("cherry") != string::npos);
    cout << "test_to_string_after_removal passed" << endl;
}

/**
 * Test: to_string_boundary_table_size_one
 * Pre-condition: HashTable with size 1 (all collisions)
 * Post-condition: to_string shows all elements in single slot
 */
void test_to_string_boundary_table_size_one() {
    HashTable<string> ht(1);
    ht.insert("first", 5);
    ht.insert("second", 10);
    ht.insert("third", 15);
    ht.insert("fourth", 20);
    
    string result = ht.to_string();
    stringstream ss(result);
    string line;
    int lines = 0;
    
    while (getline(ss, line)) {
        lines++;
    }
    
    // Should have only 1 line (slot 0:)
    assert(lines == 1);
    // All four elements should be in that line
    assert(result.find("(first,5)") != string::npos);
    assert(result.find("(fourth,20)") != string::npos);
    cout << "test_to_string_boundary_table_size_one passed" << endl;
}

/**
 * Test: to_string_exact_format_specification
 * Pre-condition: HashTable as specified in project requirements
 * Post-condition: to_string output matches exact required format
 */
void test_to_string_exact_format_specification() {
    HashTable<string> ht(5);
    ht.insert("test", 28);
    
    string result = ht.to_string();
    stringstream ss(result);
    string line;
    vector<string> lines;
    
    while (getline(ss, line)) {
        lines.push_back(line);
    }
    
    // Should have exactly 5 lines
    assert(lines.size() == 5);
    
    // Check format: slot number, colon, space, (data,key)
    assert(lines[0] == "0:");
    assert(lines[1] == "1:");
    assert(lines[2] == "2:");
    assert(lines[3] == "3: (test,28)");
    assert(lines[4] == "4:");
    cout << "test_to_string_exact_format_specification passed" << endl;
}

/**
 * Test: to_string_integer_data_type
 * Pre-condition: HashTable with integer data type
 * Post-condition: to_string correctly formats integer data and keys
 */
void test_to_string_integer_data_type() {
    HashTable<int> ht(5);
    ht.insert(42, 10);
    ht.insert(99, 20);
    
    string result = ht.to_string();
    
    assert(result.find("(42,10)") != string::npos);
    assert(result.find("(99,20)") != string::npos);
    cout << "test_to_string_integer_data_type passed" << endl;
}

/**
 * Test: to_string_large_collision_chain
 * Pre-condition: HashTable with many elements in one collision chain
 * Post-condition: to_string correctly displays all chain elements
 */
void test_to_string_large_collision_chain() {
    HashTable<string> ht(2);
    for (int i = 0; i < 8; i++) {
        ht.insert("data" + to_string(i), i);
    }
    
    string result = ht.to_string();
    
    // Count closing parentheses to verify all elements present
    int count = 0;
    for (char c : result) {
        if (c == ')') count++;
    }
    assert(count == 8);
    cout << "test_to_string_large_collision_chain passed" << endl;
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

    cout << "\n member method tests" << endl;
    test_member_single_element_found();
    test_member_single_element_not_found_wrong_data();
    test_member_single_element_not_found_wrong_key();
    test_member_empty_table();
    test_member_collision_chain();
    test_member_after_removal();
    test_member_partial_collision_removal();
    test_member_boundary_table_size_one();
    test_member_multiple_templates();
    
    cout << "\n to_string method test" << endl;
    test_to_string_empty_table();
    test_to_string_single_element();
    test_to_string_multiple_elements();
    test_to_string_collision_chain();
    test_to_string_after_removal();
    test_to_string_boundary_table_size_one();
    test_to_string_exact_format_specification();
    test_to_string_integer_data_type();
    test_to_string_large_collision_chain();

    cout << "Testing completed" << endl;

    return 0;
}
