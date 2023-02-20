#include <iostream>
#include "Sparse.h"

using namespace std;

int main() {
    Sparse s2(2, 2, 2);
    s2.append(0, 0, 1);
    s2.append(0, 1, 3);
    s2.display();
    cout << endl;
}
