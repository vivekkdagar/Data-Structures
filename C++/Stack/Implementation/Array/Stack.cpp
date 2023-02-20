//
// Created by vivek on 01-01-2023.
//

#include <iostream>
#include "Stack.h"

template<class T>
Stack<T>::Stack(unsigned int size):size(size) {         // Constructor
    array.resize(size);
    top = -1;
}

template<class T>
void Stack<T>::push(T x) {          // Push operation: insert element in a stack
    if (this->top == this->size - 1)            // Stack full condition
        std::cerr << "Stack overflow!\n";
    else {
        this->top++;
        this->array.at(top) = x;
    }
}

template<class T>
void Stack<T>::pop() {          // Pop operation: remove an element from a stack
    if (empty())
        std::cerr << "Stack underflow!\n";
    else {
        array.pop_back();
        this->top--;
    }
}

template<>
int Stack<int>::peek() {            // Get top element of stack when stack is of int type
    return empty() ? -1 : array.at(top);
}

template<>
char Stack<char>::peek() {            // Get top element of stack when stack is of char type
    return empty() ? ' ' : array.at(top);
}

template<>
double Stack<double>::peek() {            // Get top element of stack when stack is of double type
    return empty() ? -1 : array.at(top);
}

template<>
std::string Stack<std::string>::peek() {            // Get top element of stack when stack is of string type
    return empty() ? "" : array.at(top);
}
