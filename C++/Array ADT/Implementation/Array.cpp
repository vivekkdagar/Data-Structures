//
// Created by vivek on 26-01-2023.
//

#include <iostream>
#include "Array.h"

Array::Array(unsigned short size) : size(size), length(0) {
    A = new int[size];
}

bool Array::full() const {
    return length == size;
}

bool Array::empty() const {
    return this->length == 0;
}

void Array::insert(unsigned short index, int value) {
    if (!full()) {
        if (index == this->length)
            append(value);
        else if (index < length) {
            for (int i = this->length; i > index; i--)
                this->A[i] = this->A[i - 1];
            this->A[index] = value;
            this->length++;
        } else {
            std::cerr << "Invalid index\n";
        }
    } else {
        std::cerr << "Array full!\n";
    }
}

void Array::append(int value) {
    if (not full())
        this->A[length++] = value;
    else
        std::cerr << "Array full!\n";
}

void Array::remove(unsigned short index) {
    if (index < length) {
        for (int i{index}; i < this->length - 1; i++) {
            this->A[i] = this->A[i + 1];
        }
        this->length--;
    } else {
        std::cerr << "Invalid index\n";
    }
}

int Array::LinearSearch(int key) {
    for (int i{0}; i < this->length; i++)
        if (this->A[i] == key) {
            // std::swap(A[i], A[0]);          // For optimization of linear search
            return i;
        }
    return -1;
}

int Array::BinarySearch(int key) {
    int low = 0, high = this->length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (this->A[mid] == key)
            return mid;
        if (this->A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::BinarySearchR(int low, int high, int key) {
    int mid;
    if (low <= high) {
        mid = (low + high) / 2;
        if (this->A[mid] == key)
            return mid;
        else if (this->A[mid] > key)
            return this->BinarySearchR(low, mid - 1, key);
        return this->BinarySearchR(mid + 1, high, key);
    }
    return -1;
}

int Array::get(unsigned short index) {
    if (index < this->length)
        return this->A[index];
    return -1;
}

void Array::set(unsigned short index, int value) {
    if (index < this->length)
        this->A[index] = value;
    else
        std::cerr << "Invalid index\n";
}

int Array::max_element() {
    int max = this->A[0];
    for (int i{1}; i < this->length; i++) {
        if (max < this->A[i])
            max = this->A[i];
    }
    return max;
}

int Array::min_element() {
    int min = this->A[0];
    for (int i{1}; i < this->length; i++) {
        if (min > this->A[i])
            min = this->A[i];
    }
    return min;
}

int Array::accumulate() {
    int sum = 0;
    for (int i = 0; i < this->length; i++)
        sum += this->A[i];
    return sum;
}

double Array::avg() {
    return (double) (this->accumulate()) / this->length;
}

bool Array::isSorted() {
    for (int i{0}; i < this->length - 1; i++)
        if (this->A[i] > this->A[i + 1])
            return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Array &array) {
    os << "[";
    for (int i{0}; i < array.length; i++) {
        os << array.A[i];
        if (i != array.length - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

Array::~Array() {
    delete[]A;
}
