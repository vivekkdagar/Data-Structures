#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    cout << q;
}
