#include <iostream>
#include "Tree.h"

using namespace std;

int main() {

    Tree tll;
    tll.root = tll.RInsert(tll.root, 50);
    tll.root = tll.RInsert(tll.root, 40);
    tll.root = tll.RInsert(tll.root, 20);
    tll.root = tll.RInsert(tll.root,10);
    tll.root = tll.RInsert(tll.root, 42);
    tll.root = tll.RInsert(tll.root, 46);
    tll.Remove(tll.root, 40);
    tll.Inorder();
    cout << endl;

}
