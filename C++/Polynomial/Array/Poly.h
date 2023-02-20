//
// Created by vivek on 27-01-2023.
//

#ifndef POLYNOMIAL_POLY_H
#define POLYNOMIAL_POLY_H
#include <cmath>
#include <ostream>

struct Term {
    int coeff{};
    int exp{};

    Term(int coeff, int exp) : coeff(coeff), exp(exp) {}

    Term() = default;
};

class Poly {
    int termsCount;
    Term *array;
public:
    explicit Poly(int termsCount);

    void input();

    friend std::ostream &operator<<(std::ostream &os, const Poly &poly);

    Poly add(const Poly& obj);

    double eval(int x);

    virtual ~Poly();
};


#endif //POLYNOMIAL_POLY_H
