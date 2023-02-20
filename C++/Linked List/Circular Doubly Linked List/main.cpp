#include <iostream>
#include "List.h"
#include <vector>

using namespace std;


int main() {
    vector<int> h = {1,2,3,4,5,6,7};
    List s(h);
    cout << s;
}