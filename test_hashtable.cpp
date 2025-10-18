#include <iostream>
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
 



}





void test_insert()
{
   



}





void test_remove()
{


    
   
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
