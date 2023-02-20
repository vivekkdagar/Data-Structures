#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<char> stk(5);
    stk.push('2');
    stk.push('s');
    stk.push('4');
    stk.push('5');
    stk.push('t');
    cout << stk.peek();
}
