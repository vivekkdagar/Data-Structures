// Q: Find missing element in an array using hashing, similarly find duplicates in an array using hashing

#include <bits/stdc++.h>

using namespace std;

void findMissing(vector<int> v1) {
    vector<int> hashTable;

    int max = *max_element(v1.begin(), v1.end());
    hashTable.resize(max+1);

    for(int i : v1)
        hashTable[i]++;

    for(int i = *min_element(v1.begin(), v1.end()); i <= max; i++)
        if(hashTable[i] == 0)
            cout << i << " is missing\n";
}

void findDuplicates(const vector<int>& v2) {
    vector<int> hashTable;

    int max = *max_element(v2.begin(), v2.end());
    hashTable.resize(max+1);

    for(int i : v2)
        hashTable[i]++;

    for(int i = 0; i < hashTable.size(); i++)
        if(hashTable[i] > 1)
            cout << i << " is appearing " << hashTable[i] << " times\n";
}

int main() {
    vector<int> h1 = {3,7,4,9,9,12,6,11,10,10,11,11,11,11};
    findDuplicates(h1);
}
