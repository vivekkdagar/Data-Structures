#include <iostream>
#include "Poly.h"

using namespace std;

int main() {
    Poly poly(3);
    poly.input();


    cout << poly.eval(1);
}
