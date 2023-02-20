//
// Created by vivek on 14-02-2023.
//

#include "BST.h"

BST::BST() : root(nullptr) {}

void BST::InsertItr(int key) {
    Node *t = this->root, *r, *p = new Node(nullptr, nullptr, key);

    if (not root)
        root = p;

    while (t) {
        r = t;
        if (key == t->key)
            return;
        else if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }

    if (key < r->key)
        r->left = p;
    else
        r->right = p;
}


void BST::PreOrder(Node *p) {
    if (p) {
        std::cout << p->key << " ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

void BST::InOrder(Node *p) {
    if (p) {
        InOrder(p->left);
        std::cout << p->key << " ";
        InOrder(p->right);
    }
}

void BST::PostOrder(Node *p) {
    if (p) {
        PostOrder(p->left);
        PostOrder(p->right);
        std::cout << p->key << " ";
    }
}

int BST::height(Node *p) {
    int x{0}, y{0};
    if (not p)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return std::max(x, y) + 1;
}

void BST::LevelOrder(Node *p) {
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
        if (t->left) {
            std::cout << t->left->key << " ";
            Q.emplace(t->left);
        }

        // Same for right child
        if (t->right) {
            std::cout << t->right->key << " ";
            Q.emplace(t->right);
        }
    }
}

void BST::PreOrderItr(Node *p) {
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
        if (t->right)
            stk.push(t->right);
        if (t->left)
            stk.push(t->left);
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

void BST::InOrderItr(Node *p) {
    std::stack<Node *> stk;
    while (p or not stk.empty()) {
        if (p) {
            stk.emplace(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
            std::cout << p->key << " ";
            p = p->right;
        }
    }
    std::cout << std::endl;
}

void BST::PostOrderItr(Node *p) {
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
        if (t->left)
            stk1.push(t->left);
        if (t->right)
            stk2.push(t->right);
    }

    // While second stack is not empty
    while (not stk2.empty()) {
        t = stk2.top();
        stk2.pop();
        std::cout << t->key << " ";
    }
}

int BST::count(Node *p) {
    if (p)
        return count(p->left) + count(p->right) + 1;
    return 0;
}

int BST::sum(Node *p) {
    if (p)
        return count(p->left) + count(p->right) + p->key;
    return 0;
}

int BST::countLeafs(Node *p) {
    int x, y;
    if (p) {
        x = countLeafs(p->left);
        y = countLeafs(p->right);
        if (not p->left and not p->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

Node *BST::SearchItr(int key) {
    Node *t = root;
    while (t) {
        if (key == t->key)
            return t;
        else if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }
    return nullptr;
}

Node *BST::Search(Node *p, int key) {
    if (p) {
        if (p->key == key)
            return p;
        else if (key < p->key)
            return Search(p->left, key);
        else
            return Search(p->right, key);
    }
    return nullptr;
}

Node *BST::getRoot() const {
    return root;
}

Node *BST::Remove(Node *p, int key) {
    Node *Q;
    if (not p)
        return nullptr;

    if (not p->left and not p->right and (p->key == key)) {
        if (p == this->root)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->key)
        p->left = Remove(p->left, key);
    else if (key > p->key)
        p->right = Remove(p->right, key);
    else if (height(p->left) > height(p->right)) {
        Q = InPre(p->left);
        p->key = Q->key;
        p->left = Remove(p->left, Q->key);
    } else {
        Q = InSucc(p->right);
        p->key = Q->key;
        p->right = Remove(p->right, Q->key);
    }
    return p;
}

Node *BST::InPre(Node *pNode) {
    while (pNode and pNode->right)
        pNode = pNode->right;
    return pNode;
}

Node *BST::InSucc(Node *pNode) {
    while (pNode and pNode->left)
        pNode = pNode->left;
    return pNode;
}

BST::~BST() {
    destroy(this->root);
}

std::vector<int> BST::getVector() {
    std::stack<Node *> stk;
    std::vector<int> s;
    Node *p = this->root;
    while (p or not stk.empty()) {
        if (p) {
            stk.emplace(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
            s.push_back(p->key);
            p = p->right;
        }
    }
    return s;
}

BST::BST(const std::vector<int> &pre) {
    // Create root;
    root = new Node(nullptr, nullptr, pre.front());

    Node *t, *p = this->root;
    std::stack<Node *> stk;

    for (int i{1}; i < pre.size(); i++) {
        if (pre.at(i) < p->key) {
            t = new Node(nullptr, nullptr, pre.at(i));
            p->left = t;
            stk.push(p);
            p = t;
        } else {
            if (pre.at(i) > p->key and pre.at(i) < stk.empty() ? 32767 : stk.top()->key) {
                t = new Node(nullptr, nullptr, pre.at(i));
                p->right = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

Node *BST::Insert(Node *p, int key) {
    Node *t = nullptr;
    if (not p) {
        t = new Node(nullptr, nullptr, key);
        return t;
    }
    if (key < p->key) {
        p->left = Insert(p->left, key);
    } else if (key > p->key) {
        p->right = Insert(p->right, key);
    }
    return p;
}

static int temp{0};

Node *BST::Insert(int key) {
    if (temp < 1) {
        this->root = this->Insert(root, key);
    }
    this->Insert(root, key);
    temp++;
}

void BST::destroy(Node *p) {
    if (p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

