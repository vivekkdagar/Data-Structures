//
// Created by vivek on 13-01-2023.
//

#include "HashTable.h"

HashTable::HashTable() {
    HT.resize(SIZE);
}

int HashTable::hash(int key) {
    return key % SIZE;
}

int HashTable::probe(int key) {
    int idx = hash(key), i{0};
    while (HT[(idx + (i * i)) % SIZE] not_eq 0)
        i++;
    return (idx + (i * i)) % SIZE;
}

void HashTable::insert(int key) {
    int idx{hash(key)};

    if (HT[idx] not_eq 0)
        idx = this->probe(key);

    HT[idx] = key;
}

int HashTable::indexOf(int key) {
    if (key == 0)
        return -1;
    int idx = hash(key), i = 0;
    while (HT[(idx + (i * i)) % SIZE] not_eq key) {
        i++;
        if (HT[(idx + (i * i)) % SIZE] == 0)
            return -1;
    }
    return (idx + (i * i)) % SIZE;
}

bool HashTable::belongs(int key) {
    if (indexOf(key) == -1)
        return false;
    return indexOf(key) == hash(key);
}

void HashTable::remove(int key) {
    std::vector<int> temp;

    // Take out elements from the HT
    for(auto i : HT)
        if(i not_eq key and i not_eq 0)
            temp.push_back(i);

    // Clear the hashtable and fill it with 0s as it was in the beginning
    this->HT.clear();
    this->HT.resize(SIZE);

    // Insert them back into the hashtable
    for(auto i : temp)
        this->insert(i);
}

HashTable::~HashTable() = default;

