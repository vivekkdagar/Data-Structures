#include "hashtable.h"
#include <bits/stdc++.h>
using namespace std;


int main() {

    // Hash Table
    HashTable HT1;
    HT1.insert(26);
    HT1.insert(30);
    HT1.insert(45);
    HT1.insert(23);
    HT1.insert(25);
    HT1.insert(43);
    HT1.insert(74);
    HT1.remove(74);
    HT1.remove(23);
    HT1.remove(45);
//    index = HT1.indexOf(35);
//    cout << "key found at: " << index << endl;

    return 0;
}