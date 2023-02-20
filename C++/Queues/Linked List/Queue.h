//
// Created by vivek on 17-02-2023.
//

#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <ostream>

struct Node {
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}

    Node() : Node(-1, nullptr) {}
};

class Queue {
    Node *front;
    Node *rear;
public:
    Queue();

    void enqueue(int x);

    bool empty() const {
        return front == nullptr;
    }

    void dequeue();

    int head();         // Return the first element

    friend std::ostream &operator<<(std::ostream &os, const Queue &q);

    virtual ~Queue();
};


#endif //LINKED_LIST_QUEUE_H
