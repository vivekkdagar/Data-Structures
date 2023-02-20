//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "Queue.h"

Queue::Queue() : front(nullptr), rear(nullptr) {}

void Queue::enqueue(int x) {
    Node *t = new Node(x, nullptr);
    if(not t)           // Heap memory is full
        std::cerr << "Queue overflow!\n";
    else {
        if(not front)
            front = t;
        else
            rear->next = t;
        rear = t;
    }
}

void Queue::dequeue() {
    if(empty())
        std::cerr << "Queue underflow!\n";
    else {
        Node *p = front;
        front = front->next ? front->next : nullptr;
        delete p;
    }
}

int Queue::head() {
    return front == nullptr ? -1 : front->data;
}

std::ostream &operator<<(std::ostream &os, const Queue &q) {
    Node* p = q.front;
    os << "[";
    while (p){
        os << p->data;
        if(p->next) {
            os << ", ";
        }
        p = p->next;
    }
    os << "]\n";
    return os;
}

Queue::~Queue() {
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
