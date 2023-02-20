//
// Created by vivek on 07-02-2023.
//

#include <iostream>
#include "List.h"

List::List(const std::vector<int> &n) {
    first = new Node(n.at(0));
    Node *last = first, *t;

    for (int i{1}; i < n.size(); i++) {
        t = new Node(n.at(i));
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    for (Node *t = list.first; t != nullptr; t = t->next)
        os << t->data << " ";
    os << std::endl;
    return os;
}

unsigned List::length() {
    int len = 0;
    for (Node *t = this->first; t != nullptr; t = t->next)
        len++;
    return len;
}

void List::insert(unsigned int index, int value) {
    Node *t;
    if (index == 0) {
        t = new Node(nullptr, value, first);
        first->prev = t;
        first = t;
    } else if (index <= this->length()) {
        Node *p = this->first;
        for (int i{0}; i < index - 1; i++)
            p = p->next;
        t = new Node(p, value, p->next);
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void List::remove(unsigned short index) {
    if (index <= this->length() and first) {
        Node *p = first;
        if (index == 1) {
            first = first->next;
            if (first)
                first->prev = nullptr;
        } else {
            for (int i{0}; i < index - 1; i++)
                p = p->next;
            p->prev->next = p->next;
            if (p->next)
                p->next->prev = p->prev;
        }
        delete p;
    } else {
        std::cerr << "Error\n";
    }
}

void List::reverse() {
    Node *p = first, *temp;
    while (p->next) {
        temp = p->next;         // store p's next
        p->next = p->prev;          // make p next point to p prev, this means make the node point backwards
        p->prev = temp;         // make backwards point to next
        p = p->prev;            // move using prev
        if (!p->next and p) {
            p->next = p->prev;
            p->prev = nullptr;
            first = p;
            break;
        }
    }
}

List::~List() {
    Node *p = first;
    while(first) {
        first = first->next;
        delete p;
        p = first;
    }
}
