//
// Created by vivek on 01-01-2023.
//

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <vector>
#include <ostream>

template<class T>
class Stack {
    unsigned size;
    int top;
    std::vector<T> array;
public:
    explicit Stack(unsigned int size);

    friend std::ostream &
    operator<<(std::ostream &os, const Stack &stack) {         // Overloaded operator: helps in printing.
        for (int i{stack.top}; i >= 0; i--) {
            os << stack.array.at(i) << std::endl;
        }
        os << std::endl;
        return os;
    }

    void push(T x);

    void pop();

    T peek();

    bool empty() {          // Stack empty condition
        return this->top == -1;
    }

    virtual ~Stack() {
        array.clear();
    }
};

template
class Stack<int>;

template
class Stack<char>;

template
class Stack<double>;

template
class Stack<std::string>;


#endif //ARRAY_STACK_H
