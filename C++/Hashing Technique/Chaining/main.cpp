/* This type of hashing can have multiple collisions which can ultimately impact the searching time.*/

#include "basic.h"
#include "HashTable.h"

using namespace basic;

int main() {
    int A[] = {2,12,22,32,432};
    HashTable H;
    for (int i: A)
        H.insert(i);


    cout << H.remove(2) << endl;
    cout << H.remove(7) << endl;
    return 0;
}
