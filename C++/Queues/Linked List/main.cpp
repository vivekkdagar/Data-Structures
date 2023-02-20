#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    int A[] = {1, 3, 5, 7, 9};

    Queue q;

    for (int i : A){
        q.enqueue(i);
    }

  cout << q.head();

}
