//
// Created by vivek on 12-01-2023.
//

#ifndef CHAINING_HASHTABLE_H
#define CHAINING_HASHTABLE_H
#define SIZE 10

#include <vector>

struct Node {
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}
};

class HashTable {
    std::vector<Node *> HT;
public:
    HashTable();

    int hash(int key);

    void insert(int key);

    int search(int key);

    int remove(int key);

    virtual ~HashTable();

private:
    int indexOf(int key);
};


#endif //CHAINING_HASHTABLE_H
