//
// Created by vivek on 08-02-2023.
//

#ifndef CIRCULAR_DOUBLY_LINKED_LIST_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_LIST_H
#include <vector>
#include <ostream>

struct Node {
    Node *prev;
    int data;
    Node *next;

    Node(Node *prev, int data, Node *next) : prev(prev), data(data), next(next) {}

    explicit Node(int data) : Node(nullptr, data, nullptr) {}
};

class List {
    Node *first;
public:
    explicit List(const std::vector<int> &arr);

    friend std::ostream &operator<<(std::ostream &os, const List &list);

    unsigned length();

    void insert(unsigned index, int value);

    void remove(unsigned short index);

    void append(int x);

    void SortedInsert(int x);

    virtual ~List();
};


#endif //CIRCULAR_DOUBLY_LINKED_LIST_LIST_H
