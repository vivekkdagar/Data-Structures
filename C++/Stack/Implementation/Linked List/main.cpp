#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stk;
    stk.push(4);
    stk.push(10);
    stk.push(422);
    stk.pop();
    cout << stk.peek();
    return 0;
}
