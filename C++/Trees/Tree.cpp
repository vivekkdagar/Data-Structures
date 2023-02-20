//
// Created by vivek on 14-02-2023.
//

#include "Tree.h"

Tree::Tree() : root(nullptr) {}

void Tree::sprout() {          // Make the tree grow
    int x;
    Node *p, *t;

    // Creating root
    std::cout << "Enter root's value: ";
    std::cin >> x;
    root = new Node(nullptr, x, nullptr);

    // Pushing it in queue
    Q.emplace(root);

    // Now the repeating steps start
    while (not Q.empty()) {
        p = Q.front();
        Q.pop();

        // Ask if the left child is there, -1 is used the marker to indicate left child isn't there
        std::cout << "Enter left child of " << p->key << ": ";
        std::cin >> x;
        if (x not_eq -1) {
            t = new Node(nullptr, x, nullptr);
            p->lChild = t;
            Q.emplace(t);
        }

        // Ask if the right child is there, same marker is used
        std::cout << "Enter right child of " << p->key << ": ";;
        std::cin >> x;
        if (x not_eq -1) {
            t = new Node(nullptr, x, nullptr);
            p->rChild = t;
            Q.emplace(t);
        }
    }
}

void Tree::PreOrder(Node *p) {
    if (p) {
        std::cout << p->key << " ";
        PreOrder(p->lChild);
        PreOrder(p->rChild);
    }
}

void Tree::InOrder(Node *p) {
    if (p) {
        InOrder(p->lChild);
        std::cout << p->key << " ";
        InOrder(p->rChild);
    }
}

void Tree::PostOrder(Node *p) {
    if (p) {
        PostOrder(p->lChild);
        PostOrder(p->rChild);
        std::cout << p->key << " ";
    }
}

int Tree::height(Node *p) {
    int x{0}, y{0};
    if (not p)
        return 0;
    x = height(p->lChild);
    y = height(p->rChild);
    return std::max(x, y) + 1;
}

void Tree::LevelOrder(Node *p) {
    std::queue<Node *> Q;
    Node *t;

    // Print root's data and put it in queue
    std::cout << p->key << " ";
    Q.emplace(p);

    // While Q is not empty, take an element out of queue
    while (not Q.empty()) {
        t = Q.front();
        Q.pop();

        // If it has a left child, print its data and put it back in queue
        if (t->lChild) {
            std::cout << t->lChild->key << " ";
            Q.emplace(t->lChild);
        }

        // Same for right child
        if (t->rChild) {
            std::cout << t->rChild->key << " ";
            Q.emplace(t->rChild);
        }
    }
}

void Tree::PreOrderItr(Node *p) {
    if (not p)           // In case root is nullptr
        return;

    // Create a stack and push root to it
    std::stack<Node *> stk;
    stk.push(p);

    Node *t;

    // While stack is not empty,
    while (not stk.empty()) {

        //  take an item out of stack and print it
        t = stk.top();
        std::cout << t->key << " ";
        stk.pop();

        // Push right and left child to stack
        if (t->rChild)
            stk.push(t->rChild);
        if (t->lChild)
            stk.push(t->lChild);
    }

    // Method 2
    /* void Tree::iterativePreorder(Node *p) {
        stack < Node * > stk;
        while (p != nullptr || !stk.empty()) {
            if (p != nullptr) {
                std::cout << p->data << ", ";
                stk.emplace(p);
                p = p->lchild;
            } else {
                p = stk.top();
                stk.pop();
                p = p->rchild;
            }
        }
        std::cout << std::endl;
    } */
}

void Tree::InOrderItr(Node *p) {
    std::stack<Node *> stk;
    while (p or not stk.empty()) {
        if (p) {
            stk.emplace(p);
            p = p->lChild;
        } else {
            p = stk.top();
            stk.pop();
            std::cout << p->key << " ";
            p = p->rChild;
        }
    }
    std::cout << std::endl;
}

void Tree::PostOrderItr(Node *p) {
    // Method 1
    /*{ stack<long int> stk;
        long int temp;
        while (p != nullptr || ! stk.empty()){
            if (p != nullptr){
                stk.emplace((long int)p);
                p = p->lchild;
            } else {
                temp = stk.top();
                stk.pop();
                if (temp > 0){
                    stk.emplace(-temp);
                    p = ((Node*)temp)->rchild;
                } else {
                    cout << ((Node*)(-1 * temp))->data << ", " << flush;
                    p = nullptr;
                }
            }
        }
        cout << endl;
    }*/

    // Method 2
    if (not p)
        return;

    // Create 2 stacks
    std::stack<Node *> stk1, stk2;
    Node *t;

    // push root to first stack
    stk1.push(p);

    // while first stack is not empty
    while (not stk1.empty()) {

        // Pop the top of stk1 and push it to stk2
        t = stk1.top();
        stk1.pop();
        stk2.push(t);

        // Push left and right children of removed item to stk1
        if (t->lChild)
            stk1.push(t->lChild);
        if (t->rChild)
            stk2.push(t->rChild);
    }

    // While second stack is not empty
    while (not stk2.empty()) {
        t = stk2.top();
        stk2.pop();
        std::cout << t->key << " ";
    }
}

int Tree::count(Node *p) {
    if (p)
        return count(p->lChild) + count(p->rChild) + 1;
    return 0;
}

int Tree::sum(Node *p) {
    if (p)
        return count(p->lChild) + count(p->rChild) + p->key;
    return 0;
}

int Tree::countLeafs(Node *p) {
    int x, y;
    if (p) {
        x = countLeafs(p->lChild);
        y = countLeafs(p->rChild);
        if (not p->lChild and not p->rChild)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

void Tree::destroy(Node *p) {
    if (p) {
        destroy(p->lChild);
        destroy(p->rChild);
        delete p;
    }
}

Tree::~Tree() {
    destroy(root);
}

bool Tree::exists(Node *p, int key) {
    if (p) {
        if (p->key == key)
            return true;

        /* then recur on left subtree */
        bool res1 = exists(p->lChild, key);
        // node found, no need to look further
        if (res1) return true;

        /* node is not found in left,
        so recur on right subtree */
        bool res2 = exists(p->rChild, key);

        return res2;
    }
    return false;
}


bool Tree::isStrictBinary() {
    return (countLeafs() + countD2nodes() == count());
}

unsigned short Tree::countD2nodes(Node *p) {
    int x, y;
    if (p) {
        x = countD2nodes(p->lChild);
        y = countD2nodes(p->rChild);
        if (p->lChild && p->rChild)
            return x + y + 1;
        return x + y;
    }
    return 0;
}
