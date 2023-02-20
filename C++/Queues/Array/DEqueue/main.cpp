// This is Input restricted dequeue. We can't insert using front, everything else is permitted.

#include <iostream>
#include "DEQUEUE.h"

using namespace std;

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    DEQUEUE q(5);
    for(int i : B) {
        q.enqueueRear(i);
    }
    for(int i : A) {
        q.enqueueRear(i);
    }
    for(int i : A) {
        q.dequeueFront();
    }
    cout << q;
}
