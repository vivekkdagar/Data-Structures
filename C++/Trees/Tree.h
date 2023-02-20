//
// Created by vivek on 14-02-2023.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#include <stack>
#include <iostream>
#include <queue>

struct Node {
    Node *lChild{};
    int key{};
    Node *rChild{};

    Node(Node *lChild, int key, Node *rChild) : lChild(lChild), key(key), rChild(rChild) {}

    explicit Node(int key) : Node(nullptr, key, nullptr) {}

    Node() = default;
};

class Tree {
    Node *root;
public:
    Tree();

    void sprout();          // Make the tree grow

    void PreOrder() { this->PreOrder(this->root); }

    void InOrder() { this->InOrder(this->root); }

    void PostOrder() { this->PostOrder(this->root); }

    int height() { return this->height(this->root); }

    void PreOrderItr() { this->PreOrderItr(this->root); }

    void LevelOrder() { this->LevelOrder(this->root); }

    void InOrderItr() { this->InOrderItr(this->root); }

    void PostOrderItr() { this->PostOrderItr(this->root); }

    int count() { return this->count(this->root); }

    int sum() { return this->sum(this->root); }

    int countLeafs() { return this->countLeafs(this->root); }

    bool exists(int key) { return this->exists(this->root, key); }

    bool isStrictBinary();

    unsigned short countD2nodes() { return this->countD2nodes(this->root); }

    virtual ~Tree();

private:
    std::queue<Node *> Q;

    bool exists(Node *p, int key);

    void PreOrder(Node *p);

    void PreOrderItr(Node *p);

    void InOrder(Node *p);

    void PostOrder(Node *p);

    int height(Node *p);

    void LevelOrder(Node *p);

    void InOrderItr(Node *p);

    void PostOrderItr(Node *p);

    int count(Node *p);

    int sum(Node *p);

    int countLeafs(Node *p);

    void destroy(Node *p);

    unsigned short countD2nodes(Node *p);
};


#endif //TREES_TREE_H
