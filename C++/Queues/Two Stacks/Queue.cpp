//
// Created by vivek on 17-02-2023.
//

#include <vector>
#include <iostream>
#include "Queue.h"

Queue::Queue() = default;

static std::deque<int> printer;

void Queue::enqueue(int x) {
    e_stk.push(x);
    printer.push_back(x);
}

int Queue::dequeue() {
    int x{-1};
    if (d_stk.empty()) {
        if (e_stk.empty()) {
            std::cerr << "Queue underflow!\n";
            return x;
        } else {
            while (not e_stk.empty()) {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }
    x = d_stk.top();
    d_stk.pop();
    printer.pop_front();
    return x;
}

std::ostream &operator<<(std::ostream &os, const Queue &queue) {
    for(int i : printer)
        os << i << " ";
    return os;
}

Queue::~Queue() {
    printer.clear();
}
