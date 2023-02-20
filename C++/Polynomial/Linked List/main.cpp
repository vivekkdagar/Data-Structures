#include <iostream>
#include "PolyLL.h"

using namespace std;

int main() {
    PolyLL p(1, 2);
    p.add_term(2,4);
    p.add_term(5,6);
    cout << p;
}
