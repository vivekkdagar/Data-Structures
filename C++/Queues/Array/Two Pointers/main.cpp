#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    for(int i = 1; i <= 4; i++)
        q.dequeue();
    cout << q.head();
}
