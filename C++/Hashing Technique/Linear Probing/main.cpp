#include "hashtable.h"

using namespace std;


int main() {

    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A) / sizeof(A[0]);

    // Hash Table
    HashTable HT1;
    HT1.insert(26);
    HT1.insert(30);
    HT1.insert(45);
    HT1.insert(23);
    HT1.insert(25);
    HT1.insert(43);
    HT1.insert(74);
    HT1.insert(21);
    HT1.insert(1);
    cout << HT1.getLoadFactor();
    cout << endl << HT1.indexOf(25);
    return 0;
}