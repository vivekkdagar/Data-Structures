#include "BST.h"
#include <algorithm>
using namespace std;

int main() {
    BST tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.InOrderItr();
}