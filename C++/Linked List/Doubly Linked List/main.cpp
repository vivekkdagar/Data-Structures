#include <iostream>
#include "List.h"

using namespace std;

int main() {
    vector<int> h1 = {10,20,30,50,60};
    List h(h1);
    h.insert(0, 1);
    h.insert(2,3);
    h.insert(1, 2);
    h.insert(8, 5);
    cout << "before\n";
    cout << h;
    cout << endl;
    h.reverse();
    cout << h;
}
