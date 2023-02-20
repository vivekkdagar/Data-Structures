//
// Created by vivek on 14-02-2023.
//

#ifndef BINARY_SEARCH_TREES_BST_H
#define BINARY_SEARCH_TREES_BST_H

#include <stack>
#include <iostream>
#include <queue>

struct Node {
    Node *left;
    Node *right;
    int key;

    Node(Node *left, Node *right, int key) : left(left), right(right), key(key) {}
};

class BST {
    Node *root;
public:
    BST();

    void InsertItr(int key);

    Node *Insert(Node *p, int key);

    Node *Insert(int key);

    Node *SearchItr(int key);

    Node *Remove(Node *p, int key);

    Node *Search(Node *p, int key);

    Node *getRoot() const;

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

    std::vector<int> getVector();

    virtual ~BST();

    explicit BST(const std::vector<int> &pre);          // Create using preorder traversal

    void destroy(Node *p);

private:
    std::queue<Node *> Q;

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

    Node *InPre(Node *pNode);

    Node *InSucc(Node *pNode);
};


#endif //BINARY_SEARCH_TREES_BST_H
