#include <iostream>
#include "CQueue.h"

using namespace std;

int main() {
    int A[] = {1, 3, 5, 7, 9};

    CQueue cq(sizeof(A) / sizeof(A[0]) + 1);

    // Enqueue
    for (int i: A)
        cq.enqueue(i);

    // Display
    cout << cq;
    cout << endl;

    // Overflow
    cq.enqueue(10);

    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        cq.dequeue();

    // Underflow
    cq.dequeue();
}
