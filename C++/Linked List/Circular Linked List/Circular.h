//
// Created by vivek on 29-01-2023.
//

#ifndef CIRCULAR_LINKED_LIST_CIRCULAR_H
#define CIRCULAR_LINKED_LIST_CIRCULAR_H

#include <vector>
#include <ostream>

struct Node {
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}

    explicit Node(int data) : Node(data, nullptr) {}

    Node() : Node(0, nullptr) {}
};

class Circular {
    Node *first;
public:
    explicit Circular(const std::vector<int>& arr);

    friend std::ostream &operator<<(std::ostream &os, const Circular &circular);

    void RDisplay(Node *p);

    Node *getFirst() const;

    void insert(unsigned short pos, int val);

    void remove(unsigned short pos);

    virtual ~Circular();
};


#endif //CIRCULAR_LINKED_LIST_CIRCULAR_H
