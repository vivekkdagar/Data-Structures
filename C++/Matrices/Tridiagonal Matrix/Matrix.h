//
// Created by vivek on 20-02-2023.
//

#ifndef TRIDIAGONAL_MATRIX_MATRIX_H
#define TRIDIAGONAL_MATRIX_MATRIX_H


#include <vector>
#include <ostream>

class Matrix {
    unsigned short dimensions;
    std::vector<int> array;
public:
    explicit Matrix(unsigned short dimensions);

    unsigned short getDimensions() const;

    void set(unsigned short i, unsigned short j, int value);

    int get(unsigned short i, unsigned short j) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    virtual ~Matrix();
};


#endif //TRIDIAGONAL_MATRIX_MATRIX_H
