#include <bits/stdc++.h>

using namespace std;

// Uses an auxiliary array to reverse the main array
void reverseUAuxi(vector<int> &list) {
    int t = list.size();
    vector<int> auxi{};
    auxi.resize(t);
    int i = t - 1, j = 0;
    while (i >= 0) {
        auxi[j] = list[i];
        j++;
        i--;
    }

    for (j = 0; j < t; j++)
        list[j] = auxi[j];
}

// Reverse without using auxiliary array
void reverse(vector<int> &list) {
    for(int i = 0, j = list.size()-1; i < j; i++, j--)
        std::swap(list[i],list[j]);
}

// Left shift: shift all elements to the left by one place
void lshift(vector<int> &list) {
    int t = list.size();
    for(int i = 0; i < t; i++)
        list[i] = list[i+1];
    list[t-1] = 0;
}

// Right shift: shift all elements to the right by one place
void rshift(vector<int> &list) {
    for(int t = list.size() - 1; t > 0;t--)
        list[t] = list[t-1];
    list[0] = 0;
}

// Right rotate: rotate all elements to the right by one place
void rRotate(vector<int> &list) {
    int s = list.back();
    for(int t = list.size() - 1; t > 0;t--)
        list[t] = list[t-1];
    list[0] = s;
}

// Left rotate: rotate all elements to the left by one place
void lRotate(vector<int> &list) {
    int t = list.size(), s = list.front();
    for(int i = 0; i < t; i++)
        list[i] = list[i+1];
    list[t-1] = s;
}

int main() {
    vector<int> list = {-1,-100,3,99};
    rshift(list);
    for(int i : list)
        cout << i << " ";
}
