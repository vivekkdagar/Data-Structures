//
// Created by vivek on 13-01-2023.
//

#ifndef QUADRATIC_PROBING_HASHTABLE_H
#define QUADRATIC_PROBING_HASHTABLE_H
#include "basic.h"
#define SIZE 10
using namespace basic;

class HashTable {
    std::vector<int> HT;
public:
    HashTable();

    int hash(int key);

    int probe(int key);

    void insert(int key);

    int indexOf(int key);

    bool belongs(int key);

    void remove(int key);

    virtual ~HashTable();
};


#endif //QUADRATIC_PROBING_HASHTABLE_H
