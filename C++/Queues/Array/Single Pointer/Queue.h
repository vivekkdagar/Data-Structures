//
// Created by vivek on 17-02-2023.
//

#ifndef SINGLE_POINTER_QUEUE_H
#define SINGLE_POINTER_QUEUE_H


#include <ostream>

class Queue {
    int rear;
    unsigned int size;
    int *A;
public:
    explicit Queue(unsigned int size);

    bool full() const {
        return this->rear == size - 1;
    }

    bool empty() const {
        return this->rear == -1;
    }

    void enqueue(int x);

    void dequeue();

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue);

    int front();

    virtual ~Queue();
};


#endif //SINGLE_POINTER_QUEUE_H
