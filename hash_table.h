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
#include <algorithm>

template<typename T>
class MinQueue {
private:
    int capacity;
    int heap_size;
    T* heap;

    int parent(int i) { 
        return (i - 1) / 2; 
    }
    int left(int i) { 
        return 2 * i + 1; 
    }
    int right(int i) { 
        return 2 * i + 2; 
    }

    void resize() {
    if (capacity == 0) {
        capacity = 10;
    } else {
        capacity = capacity * 2;
    }
    T* newHeap = new T[capacity];
    for (int i = 0; i < heap_size; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

public:
    MinQueue();
    MinQueue(T* A, int n);
    ~MinQueue();

    void insert(T x);
    T min();
    T extract_min();
    void decrease_key(int i, T k);

    void min_heapify(int i);
    void build_heap();

    void sort(T* A);
    std::string to_string();

    void set(int i, T val);
    void allocate(int n);
};

#include "minqueue.cpp"

#endif