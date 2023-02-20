//
// Created by vivek on 27-01-2023.
//

#include <iostream>
#include "Poly.h"

Poly::Poly(int termsCount) : termsCount(termsCount) {
    array = new Term[termsCount];
}

void Poly::input() {
    int x, y;
    std::cout << "Enter coefficient and exponent of all terms: ";
    for (int i{0}; i < termsCount; i++) {
        std::cin >> x >> y;
        array[i] = Term(x, y);
    }
}

std::ostream &operator<<(std::ostream &os, const Poly &poly) {
    for (int i{0}; i < poly.termsCount; i++) {
        os << "(" << poly.array[i].coeff << "x)^" << poly.array[i].exp;
        if (i != poly.termsCount - 1)
            os << " + ";
        else
            os << " ";
    }
    return os;
}

Poly Poly::add(const Poly& obj) {
    Poly sum(this->termsCount + obj.termsCount);

    int i{0}, j{0}, k{0};
    while (i < this->termsCount && j < obj.termsCount) {
        if (this->array[i].exp > obj.array[j].exp)
            sum.array[k++] = this->array[i++];
        else if (this->array[i].exp < obj.array[j].exp)
            sum.array[k++] = obj.array[j++];
        else {
            sum.array[k].exp = this->array[i].exp;
            sum.array[k++].coeff = this->array[i++].coeff + obj.array[j++].coeff;
        }
    }

    while (i < this->termsCount)
        sum.array[k++] = this->array[i++];

    while (j < obj.termsCount)
        sum.array[k++] = obj.array[j++];

    sum.termsCount = k;
    return sum;
}

double Poly::eval(int x) {
    double res;
    for(int i{0}; i < this->termsCount; i++)
        res += (this->array[i].coeff * pow(x, this->array[i].exp));
    return res;
}

Poly::~Poly() {
    delete[]array;
}





