#include <iostream>
#include <vector>

using namespace std;

// This will be O(n) if the list is already sorted
void bubble_sort(vector<int> &array) {
    bool flag;
    unsigned short pass{0}, comp{0};
    for (unsigned lastUnsortedIndex = array.size() - 1; lastUnsortedIndex > 0; lastUnsortedIndex--) {
        flag = false;
        pass++;
        for (int i{0}; i < lastUnsortedIndex; i++)
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                flag = true;
                comp++;
            }
        if (not flag)
            break;
    }
    cout << "Passes: " << pass << "\nComparisons: " << comp << endl;
}

int main() {
    vector<int> h = {8, 5, 7, 3, 2};
    bubble_sort(h);
    for (int i: h)
        cout << i << " ";
}