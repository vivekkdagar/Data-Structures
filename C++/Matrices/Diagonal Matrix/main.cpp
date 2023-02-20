#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix matrix(3);
    matrix.set(1,1,2);
    matrix.set(2,2,3);
    matrix.set(3,3,4);
    cout << matrix;
}
