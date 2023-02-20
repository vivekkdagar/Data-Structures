//
// Created by vivek on 09-02-2023.
//

#ifndef AVL_TREES_TREE_H
#define AVL_TREES_TREE_H

#include <algorithm>

struct Node {
    Node *lChild;
    int data;
    int height;
    Node *rChild;

    Node(Node *lChild, int data, int height, Node *rChild) : lChild(lChild), data(data), height(height),
                                                             rChild(rChild) {}
};

class Tree {
public:
    Node *root;
public:
    Tree();

    Node *RInsert(Node *p, int key);

    static int NodeHeight(Node *pNode);

    static int BalanceFactor(Node *pNode);

    Node *LLRotation(Node *p);

    Node *LRRotation(Node *p);

    Node *RLRotation(Node *pNode);

    Node *RRRotation(Node *pNode);

    void Inorder() { this->Inorder(this->root); }

    Node *Remove(Node *p, int key);

    virtual ~Tree();

private:
    void Inorder(Node *p);

    Node* InPre(Node *p);

    Node *InSucc(Node *pNode);

    void destroy(Node *p);
};


#endif //AVL_TREES_TREE_H
