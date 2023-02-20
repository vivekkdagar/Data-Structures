#include "HashTable.h"

// TODO: review double hashing
int main() {
    HashTable h;
    h.insert(5);
    h.insert(25);
    cout << h.getLoadFactor();
}