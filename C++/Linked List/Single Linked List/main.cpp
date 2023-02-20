#include "List.h"

using namespace std;

int main() {
    vector<int> v = {2, 5, 7, 135, 1053};
    List l(v);
    vector<int> v2 = {1,2,3,4,5,6,7,8};
    List l2(v2);
    List::concat(l.getHead(), l2.getHead());
    cout << l;
}
