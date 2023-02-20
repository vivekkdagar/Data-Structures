#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

void insertion_sort(vector<int> &array) {
    int firstUnsortedIdx, j, newElement, shifts{0};           // passes will be n-1 where n is the size of the array
    for (firstUnsortedIdx = 1; firstUnsortedIdx < array.size(); firstUnsortedIdx++) {
        newElement = array.at(firstUnsortedIdx);            // to be inserted
        int sortedIdx;
        for (sortedIdx = firstUnsortedIdx; sortedIdx > 0 and array.at(sortedIdx - 1) > newElement; sortedIdx--) {
            array.at(sortedIdx) = array.at(sortedIdx - 1);
            shifts++;
        }
        array.at(sortedIdx) = newElement;
    }
    cout << "Passes are: " << firstUnsortedIdx << "\nShifts are: " << shifts << "\n";
}

int main() {
    vector<int> h = {13, 11, 7, 9, 5, 2, 1};
    insertion_sort(h);
    for (int i: h)
        cout << i << " ";
}
