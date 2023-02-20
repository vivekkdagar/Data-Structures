#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    Array myArray(5);
    myArray.append(1);
    myArray.append(2);
    myArray.append(3);
    myArray.append(4);
    myArray.append(10);


    cout << myArray.isSorted();
}
