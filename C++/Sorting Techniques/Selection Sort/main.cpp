#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selection_sort(vector<int> &array) {
    int comparisons{0}, swaps{0};
    for (unsigned lastUnsortedIndex = array.size() - 1; lastUnsortedIndex > 0; lastUnsortedIndex--) {
        int max = 0;
        for (int i{1}; i <= lastUnsortedIndex; i++) {
            comparisons++;
            if (array.at(i) > array.at(max))
                max = i;
        }
        swap(array.at(lastUnsortedIndex), array.at(max));
        swaps++;
    }
    cout << "Comparisons: " << comparisons << "\nSwaps: " << swaps << endl;
}

int main() {
    vector<int> h = {13, 11, 9, 7, 8, 2, 1};
    selection_sort(h);
    for (int i: h)
        cout << i << " ";
}
