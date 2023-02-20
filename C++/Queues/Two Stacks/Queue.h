//
// Created by vivek on 17-02-2023.
//

#ifndef TWO_STACKS_QUEUE_H
#define TWO_STACKS_QUEUE_H


#include <stack>
#include <ostream>

class Queue {
    std::stack<int> e_stk;
    std::stack<int> d_stk;
public:
    Queue();

    void enqueue(int x);

    int dequeue();

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue);

    virtual ~Queue();
};


#endif //TWO_STACKS_QUEUE_H
