//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "Queue.h"

Queue::Queue(unsigned int size) : size(size), rear(-1) {
    A = new int[this->size];
}

void Queue::enqueue(int x) {
    if (not this->full()) {
        this->rear++;
        this->A[rear] = x;
    } else {
        std::cerr << "Queue is full!\n";
    }
}

void Queue::dequeue() {
    if (not this->empty()) {
        // Shift the elements
        for (int i{0}; i < this->rear; i++)
            this->A[i] = this->A[i + 1];

        // Reduce rear
        this->rear--;
    } else
        std::cerr << "Queue is empty!\n";
}

std::ostream &operator<<(std::ostream &os, const Queue &queue) {
    os << "[";
    for (int i{0}; i <= queue.rear; i++) {
        os << queue.A[i];
        if (i not_eq queue.rear)
            os << ", ";
    }
    os << "]";
    return os;
}

int Queue::front() {            // Returns the front element
    return rear not_eq -1 ? A[0] : -1;
}

Queue::~Queue() {
    delete []A;
}


