// Q: Finding Single (and multiple) Missing Element in an Array

#include <bits/stdc++.h>

using namespace std;

int find(const vector<int> &array) {
    for (int i{0}; i < array.size() - 1; i++)
        if (array[i] + 1 != array[i + 1]) {
            cout << "Missing Element at " << (i+1) << ": " << (array[i] + 1) << endl;
        }
    return -1;
}

int main() {
    vector<int> A = {6, 7, 8, 9, 10, 11, 13, 14, 16, 17};
    find(A);
}
