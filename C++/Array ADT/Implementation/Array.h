//
// Created by vivek on 26-01-2023.
//

#ifndef IMPLEMENTATION_ARRAY_H
#define IMPLEMENTATION_ARRAY_H

#include <ostream>

class Array {
    int *A;
    unsigned short size;
    unsigned short length;
public:
    explicit Array(unsigned short size);

    bool full() const;

    bool empty() const;

    void insert(unsigned short index, int value);

    void append(int value);

    void remove(unsigned short index);

    int LinearSearch(int key);

    int BinarySearch(int key);

    int BinarySearchR(int low, int high, int key);

    int get(unsigned short index);

    void set(unsigned short index, int value);

    int max_element();

    int min_element();

    int accumulate();

    double avg();

    bool isSorted();

    friend std::ostream &operator<<(std::ostream &os, const Array &array);

    virtual ~Array();
};


#endif //IMPLEMENTATION_ARRAY_H
