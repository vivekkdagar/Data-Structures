#include <iostream>
#include "Circular.h"

using namespace std;

int main() {
    vector<int> h = {2, 3, 4, 5, 6, 7};
    Circular s(h);
    s.insert(0, 1);
    s.insert(4,41);
    s.insert(8, 3);
    s.remove(0);
    cout << s;
}
