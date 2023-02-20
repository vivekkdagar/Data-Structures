#include <iostream>
#include "USet.h"

using namespace std;

int main() {
    vector<int> A = {3,5,10,4,6};
    USet set1(A);

    vector<int> B = {12,4,7,2,5};
    USet set2(B);

    set1.Difference(set2);
    cout << set1;
}
