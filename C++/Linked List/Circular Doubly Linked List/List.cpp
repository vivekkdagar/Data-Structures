//
// Created by vivek on 08-02-2023.
//

#include <vector>
#include "List.h"

List::List(const std::vector<int> &arr) {
    first = new Node(first, arr.at(0), first);
    Node *last = first, *t;
    for (int i{1}; i < arr.size(); i++) {
        t = new Node(last, arr.at(i), first);
        last->next = t;
        last = t;
    }
    first->prev = last;
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    Node *t = list.first;
    os << "[ ";
    do {
        os << t->data << " ";
        t = t->next;
    } while (t != list.first);
    os << "]" << std::endl;
    return os;
}

unsigned List::length() {
    int len{0};
    Node *t = this->first;
    do {
        len++;
        t = t->next;
    } while (t != this->first);
    return len;
}

void List::insert(unsigned int index, int value) {
    if (index == 0) {
        Node *t = new Node(first->prev, value, nullptr);
        first->prev->next = t;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        Node *t = new Node(value), *p = first;
        for (int i{0}; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        t->next->prev = t;
        t->prev = p;
    }
}

void List::remove(unsigned short index) {
    if (index <= length()) {
        if (index == 1) {           // Problem
            Node *p = first->next;
            if (p == first) {
                delete p;
                first = nullptr;
            } else {
                p->prev = first->prev;
                first->prev->next = p;
                delete first;
                first = p;
            }
        } else {
            Node *q = first, *p = first;
            for (int i{0}; i < index - 1; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            p->next->prev = q;
            delete p;
        }
    }
}

void List::append(int x) {
    Node *last = first->prev;
    Node *t = new Node(last, x, first);
    last->next = t;
    last = t;
    first->prev = last;
}

void List::SortedInsert(int x) {
    Node *t = new Node(x);
    Node *p = first;
    if (length() == 1) {
        t->next = p;
        t->prev = p;
        p->prev = t;
        p->next = t;
        if (p->data > x) {
            first = t;
        }
    } else {
        Node *q = nullptr;
        while (p->data < x and p->next not_eq first) {
            q = p;
            p = p->next;
        }

        // this is the condition when the element is inserted at last
        if (p->data < x) {
            t->next = p->next;
            t->prev = p;
            p->next = t;
            t->next->prev = t;
        }

            // condition when element is inserted at the begining
        else if (!q) {
            t->next = p;
            t->prev = p->prev;
            t->prev->next = t;
            p->prev = t;
            first = t;
        }

            // condition when element is inserted any position
            // neither at last nor at begin
        else {
            t->next = p;
            t->prev = q;
            p->prev = t;
            q->next = t;
        }

    }
}

List::~List() {
    Node *t = this->first;
    do {
        first = first->next;
        delete t;
        t = first;
    } while(t not_eq first);
}
