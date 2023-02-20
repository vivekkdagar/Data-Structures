#include "HashTable.h"

HashTable::HashTable() {
    HT.resize(SIZE);
}

int HashTable::hash(int key) {
    return key % SIZE;
}

int HashTable::prime_hash(int key) {
    return PRIME - (key % PRIME);
}

int HashTable::double_hash(int key) {
    int idx = hash(key), i = 0;
    while (this->HT[(idx + (i * prime_hash(key))) % SIZE] not_eq 0)
        i++;
    return (idx + i * prime_hash(key)) % SIZE;
}

void HashTable::insert(int key) {
    int idx = hash(key);
    if (HT[idx] not_eq 0)
        idx = this->double_hash(key);
    HT[idx] = key;
}

double HashTable::getLoadFactor() {
    double count{0};
    for(auto i : HT)
        if(i not_eq 0)
            count++;
    return count/SIZE;
}


