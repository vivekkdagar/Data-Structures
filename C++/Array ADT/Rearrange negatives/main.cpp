#include <bits/stdc++.h>

using namespace std;

// Rearranges all -ve to right side
void rearrange(vector<int> &arr) {
    int i = 0, j = arr.size() - 1;
    while(i < j) {
        while(arr[i] < 0) i++;
        while(arr[j] >= 0) j--;
        if(i < j)
            std::swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> arr = {-2,9,-51,55,-4,63,-6};
    rearrange(arr);
    for(int i : arr)
        cout << i << " ";
    return 0;
}
