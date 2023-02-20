#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> &v1, vector<int> &v2) {
    // Sorting
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    // Array to store merged array
    vector<int> v3;

    // Merging
    int i{0}, j{0};
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] > v2[j]) {
            v3.push_back(v2[j]);
            j++;
        } else if(v1[i] < v2[j]) {
            v3.push_back(v1[i]);
            i++;
        } else {
            v3.push_back(v1[i]);
            i++;
        }
    }

    // Copying over the remaining elements of v1 and v2
    for(; i < v1.size(); i++)
        v3.push_back(v1[i]);

    for(; j < v2.size(); j++)
        v3.push_back(v2[j]);

    return v3;
}

int main() {
    vector<int> v1 = {3,8,16,20,25,91,87};
    vector<int> v2 = {4,10,12,22,23};
    vector<int> v3 = merge(v1, v2);
    for(int i : v3)
        cout << i << endl;
    return 0;
}
