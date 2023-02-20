//
// Created by vivek on 01-01-2023.
//

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <ostream>

struct Node {
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}          // Constructor for node

};

class Stack {
    Node *top;
public:
    explicit Stack();

    void push(int x);

    void pop();

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack);

    int peek();

    virtual ~Stack();
};


#endif //LINKED_LIST_STACK_H
