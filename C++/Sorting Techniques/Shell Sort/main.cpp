#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void shell_sort(vector<int> &A) {
    int n = A.size(), temp, i;
    for (int gap{n / 2}; gap >= 1; gap /= 2) {
        for (int j{gap}; j < n; j++) {
            temp = A.at(j);
            for (i = j - gap; i >= 0 and A[i] > temp; i -= gap)
                A[i + gap] = A[i];
            A[i + gap] = temp;
        }
    }
}

int main() {
    vector<int> A = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 3, 3, 3};
    shell_sort(A);
    for(int i : A)
        cout << i << " ";
}
