#include <iostream>
#include <string>
#include "hash_table.h"

using namespace std;

void printSeparator() {
    cout << "\n" << string(60, '=') << "\n\n";
}

int main() {
    cout << "\n*** HashTable Visualization Demo ***\n";
    
    // ========== Demo 1: 기본 삽입 ==========
    printSeparator();
    cout << "Demo 1: Basic Insertion (size=5)\n";
    cout << "Inserting: (\"apple\", 10), (\"banana\", 13), (\"cherry\", 21)\n\n";
    
    HashTable<string> ht1(5);
    ht1.insert("apple", 10);   // 10 % 5 = 0
    ht1.insert("banana", 13);  // 13 % 5 = 3
    ht1.insert("cherry", 21);  // 21 % 5 = 1
    
    cout << "HashTable Contents:\n";
    cout << ht1.to_string();
    
    // ========== Demo 2: 충돌 (Collision) ==========
    printSeparator();
    cout << "Demo 2: Collision Handling (size=5)\n";
    cout << "Inserting: (\"first\", 5), (\"second\", 10), (\"third\", 15)\n";
    cout << "All hash to slot 0 (5%5=0, 10%5=0, 15%5=0)\n\n";
    
    HashTable<string> ht2(5);
    ht2.insert("first", 5);
    cout << "After inserting 'first':\n" << ht2.to_string() << "\n";
    
    ht2.insert("second", 10);
    cout << "After inserting 'second' (collision!):\n" << ht2.to_string() << "\n";
    
    ht2.insert("third", 15);
    cout << "After inserting 'third' (collision!):\n" << ht2.to_string();
    cout << "Notice: Newest elements appear at the HEAD of the chain\n";
    
    // ========== Demo 3: Remove 연산 ==========
    printSeparator();
    cout << "Demo 3: Remove Operation\n";
    cout << "Starting with collision chain at slot 0\n\n";
    
    HashTable<string> ht3(5);
    ht3.insert("first", 5);
    ht3.insert("second", 10);
    ht3.insert("third", 15);
    
    cout << "Initial state:\n" << ht3.to_string() << "\n";
    
    ht3.remove(10);
    cout << "After removing key=10 (middle element):\n" << ht3.to_string() << "\n";
    
    ht3.remove(15);
    cout << "After removing key=15 (head element):\n" << ht3.to_string() << "\n";
    
    ht3.remove(5);
    cout << "After removing key=5 (last element):\n" << ht3.to_string();
    
    // ========== Demo 4: Member 검색 ==========
    printSeparator();
    cout << "Demo 4: Member Search\n\n";
    
    HashTable<string> ht4(5);
    ht4.insert("apple", 10);
    ht4.insert("banana", 15);
    ht4.insert("cherry", 20);
    
    cout << "HashTable Contents:\n" << ht4.to_string() << "\n";
    
    cout << "Search Results:\n";
    cout << "  member(\"apple\", 10):  " << (ht4.member("apple", 10) ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
    cout << "  member(\"banana\", 15): " << (ht4.member("banana", 15) ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
    cout << "  member(\"grape\", 10):  " << (ht4.member("grape", 10) ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
    cout << "  member(\"apple\", 99):  " << (ht4.member("apple", 99) ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
    
    // ========== Demo 5: 음수 키 처리 ==========
    printSeparator();
    cout << "Demo 5: Negative Keys\n";
    cout << "Inserting: (100, -7), (200, -12), (300, 3)\n\n";
    
    HashTable<int> ht5(5);
    ht5.insert(100, -7);   // -7 % 5 = -2 → adjusted to 3
    ht5.insert(200, -12);  // -12 % 5 = -2 → adjusted to 3
    ht5.insert(300, 3);    // 3 % 5 = 3
    
    cout << "HashTable Contents:\n";
    cout << ht5.to_string();
    cout << "Note: Negative keys are handled correctly!\n";
    cout << "  -7  → slot 3 ((-7 % 5) + 5 = 3)\n";
    cout << "  -12 → slot 3 ((-12 % 5) + 5 = 3)\n";
    cout << "  3   → slot 3 (3 % 5 = 3)\n";
    
    // ========== Demo 6: 다양한 데이터 타입 ==========
    printSeparator();
    cout << "Demo 6: Different Data Types\n\n";
    
    // Integer HashTable
    HashTable<int> ht_int(3);
    ht_int.insert(42, 5);
    ht_int.insert(99, 8);
    cout << "HashTable<int>:\n" << ht_int.to_string() << "\n";
    
    // Double HashTable
    HashTable<double> ht_double(3);
    ht_double.insert(3.14, 4);
    ht_double.insert(2.71, 7);
    cout << "HashTable<double>:\n" << ht_double.to_string() << "\n";
    
    // String HashTable
    HashTable<string> ht_str(3);
    ht_str.insert("hello", 1);
    ht_str.insert("world", 4);
    cout << "HashTable<string>:\n" << ht_str.to_string();
    
    // ========== Demo 7: 큰 충돌 체인 ==========
    printSeparator();
    cout << "Demo 7: Large Collision Chain (size=1)\n";
    cout << "All elements will collide in slot 0!\n\n";
    
    HashTable<string> ht7(1);
    ht7.insert("elem1", 5);
    ht7.insert("elem2", 10);
    ht7.insert("elem3", 15);
    ht7.insert("elem4", 20);
    ht7.insert("elem5", 25);
    
    cout << "HashTable Contents:\n";
    cout << ht7.to_string();
    cout << "All 5 elements in one chain, newest (elem5) at head!\n";
    
    printSeparator();
    cout << "*** Demo Complete! ***\n\n";
    
    return 0;

}