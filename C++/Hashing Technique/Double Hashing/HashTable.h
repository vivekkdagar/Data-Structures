//
// Created by vivek on 13-01-2023.
//

#ifndef DOUBLE_HASHING_HASHTABLE_H
#define DOUBLE_HASHING_HASHTABLE_H

#include "basic.h"

#define SIZE 10
#define PRIME 7

using namespace basic;

class HashTable {
    std::vector<int> HT;
public:
    HashTable();

    int hash(int key);

    int prime_hash(int key);

    int double_hash(int key);

    void insert(int key);

    double getLoadFactor();
};


#endif //DOUBLE_HASHING_HASHTABLE_H
