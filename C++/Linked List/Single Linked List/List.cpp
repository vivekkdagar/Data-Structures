//
// Created by vivek on 27-01-2023.
//

#include <iostream>
#include "List.h"

List::List(int x) {
    head = new Node(x);
}

List::List(Node *head) : head(head) {}

List::List(std::vector<int> array) {
    head = new Node(array.at(0));
    Node *last = head, *t;

    for (int i{1}; i < array.size(); i++) {
        t = new Node(array.at(i));
        last->next = t;
        last = t;
    }
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    Node *t = list.head;
    os << "[";
    while (t) {
        os << t->data;
        if (t->next != nullptr)
            os << ", ";
        t = t->next;
    }
    os << "]";
    return os;
}

void List::display_R(Node *p) {
    if (p) {
        std::cout << p->data << " ";
        display_R(p->next);
    }
}

int List::count() {
    int len = 0;
    Node *t = head;
    while (t) {
        len++;
        t = t->next;
    }
    return len;
}

int List::count_R(Node *p) {
    if (p)
        return count_R(p->next) + 1;
    else
        return 0;
}

int List::sum() {
    int sum = 0;
    Node *t = head;
    while (t) {
        sum += (t->data);
        t = t->next;
    }
    return sum;
}

int List::sum_R(Node *p) {
    if (p)
        return sum_R(p->next) + p->data;
    else
        return 0;
}

int List::max() {
    int max = INT32_MIN;
    Node *t = head;
    while (t)
        if (t->data > max)
            max = t->data;
    return max;
}

int List::max_R(Node *p) {
    if (not p)
        return INT32_MIN;

    int x{0};
    x = max_R(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

int List::search(int key) {
    Node *t = head;
    while (t) {
        if (t->data == key)
            return key;
        t = t->next;
    }
    return -1;
}

int List::search_R(Node *p, int key) {
    if (!p)
        return -1;
    if (p->data == key)
        return key;
    return search_R(p->next, key);
}

Node *List::getHead() const {
    return head;
}

void List::insert(unsigned short index, int val) {
    if (index <= this->count()) {
        if (index == 0) {
            if (!head)
                head = new Node(val);
            else {
                Node *t = new Node(val, head);
                head = t;
            }
        } else if (index == this->count()) {
            append(val);
        } else {
            Node *t = head;
            for (int i{0}; i < index - 1; i++)
                t = t->next;
            Node *n = new Node(val);
            n->next = t->next;
            t->next = n;
        };
    } else {
        std::cerr << "Invalid index";
    }
}

void List::append(int val) {
    if (!head)
        head = new Node(val);
    else {
        Node *last = head;
        while (last->next)
            last = last->next;
        Node *t = new Node(val);
        last->next = t;
    }
}

void List::SortedInsert(int val) {
    Node *t = new Node(val);
    if (!head)
        head = t;
    else {
        Node *s = head, *q;
        while (s && s->data < val) {
            q = s;
            s = s->next;
        }
        if (s == head) {
            t->next = head;
            head = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

void List::remove(unsigned short index) {
    if (index > this->count())
        return;

    Node *q = nullptr;
    if (index == 0) {
        Node *p = head;
        if (head->next)
            head = head->next;
        else
            head = nullptr;
        delete p;
    } else {
        Node *p = head;
        for (int i{0}; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
}

bool List::sorted() {
    int x = head->data;
    Node *p = head->next;
    while (p) {
        if (x > p->data)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void List::remove_sorted() {
    Node *p = head, *q = head->next;
    while (q) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

std::vector<int> List::get_list() {
    std::vector<int> l2;
    Node *t = head;
    while (t) {
        l2.push_back(t->data);
        t = t->next;
    }
    return l2;
}

void List::reverse_1() {            // similar to what we do with arrays
    std::vector<int> list = this->get_list();
    std::reverse(list.begin(), list.end());
    this->head = List(list).getHead();
}

void List::reverse_2() {            // Using sliding pointers
    Node *p = head, *q = nullptr, *r = nullptr;
    while (p) {
        // Sliding the pointers
        r = q;
        q = p;
        p = p->next;

        // Modifying the links
        q->next = r;
    }
    head = q;
}

void List::reverse_R(Node *q, Node *p) {
    if (!p) {
        reverse_R(p, p->next);
        p->next = q;
    } else
        head = q;
}

void List::concat(Node *h1, Node *h2) {
    Node *p = h1;
    while (p->next)
        p = p->next;
    p->next = h2;
}

List List::merge(Node *second) {
    Node *third, *last;
    if (this->head->data < second->data) {
        third = last = head;
        head = head->next;
        last->next = nullptr;
    } else {
        third = last = second;
        second = second->next;
        last->next = nullptr;
    }
    while (this->head && second) {
        if (head->data < second->data) {
            last->next = head;
            last = head;
            head = head->next;
            last->next = nullptr;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
    }

    if (head)
        last->next = head;
    else
        last->next = second;

    return List(third);
}

bool List::hasLoop() {
    Node *p, *q;
    p = q = head;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : nullptr;
    } while (p && q);
    return p == q;
}

List::~List() {
    Node *p = this->head;
    while(p) {
        head = head->next;
        delete p;
        p = head;
    }
}

