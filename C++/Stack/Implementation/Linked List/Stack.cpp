//
// Created by vivek on 01-01-2023.
//

#include <iostream>
#include "Stack.h"

Stack::Stack() : top(nullptr) {}            // Constructor

void Stack::push(int x) {           // Push operation: insert element into stack
    if (!top)
        top = new Node(x);
    else {
        Node *t = new Node(x);
        t->next = top;
        top = t;
    }
}

void Stack::pop() {         // Pop operation: remove element from stack
    if (!top)
        std::cerr << "Stack underflow!\n";
    else {
        if (!top->next) {
            delete top;
            top = nullptr;
        } else {
            Node *t = top;
            top = top->next;
            delete t;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Stack &stack) {            // Printing the stack
    Node *t = stack.top;
    while (t) {
        os << t->data << std::endl;
        t = t->next;
    }
    os << std::endl;
    return os;
}

int Stack::peek() {         // Getting the top element of the stack
    return top ? top->data : -1;
}

Stack::~Stack() {           // Destructor to free up heap memory used by linked list
    Node *t = this->top;
    while (t) {
        top = top->next;
        delete t;
        t = top;
    }
}

