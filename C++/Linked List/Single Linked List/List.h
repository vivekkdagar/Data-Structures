//
// Created by vivek on 27-01-2023.
//

#ifndef SINGLE_LINKED_LIST_LIST_H
#define SINGLE_LINKED_LIST_LIST_H
#include <algorithm>
#include <vector>
#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}

    explicit Node(int data) : Node(data, nullptr) {}

    Node() : Node(0, nullptr) {}
};

class List {
    Node *head;
public:
    explicit  List(int x);

    explicit List(Node *head);

    explicit List(std::vector<int> array);

    friend std::ostream &operator<<(std::ostream &os, const List &list);

    void display_R(Node *p);            // recursive display

    int count();

    static int count_R(Node *p);            // recursive counting of nodes

    int sum();

    static int sum_R(Node *p);          // recursive sum of elements

    int max();

    static int max_R(Node *p);          // recursive find max element

    int search(int key);

    static int search_R(Node *p, int key);           // recursive searching

    Node *getHead() const;

    void insert(unsigned short index, int val);

    void append(int val);

    void SortedInsert(int val);

    void remove(unsigned short index);

    bool sorted();

    void remove_sorted();

    std::vector<int> get_list();            // returns a vector containing elements of the linked list

    void reverse_1();           // inefficient reverse

    void reverse_2();           // using sliding pointers

    void reverse_R(Node *q, Node *p);            // recursive reverse

    static void concat(Node *h1, Node *h2);            // concatenate 2 linked lists

    List merge(Node *second);         // merge 2 linked lists

    bool hasLoop();

    virtual ~List();
};


#endif //SINGLE_LINKED_LIST_LIST_H
