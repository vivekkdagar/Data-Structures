//
// Created by vivek on 27-01-2023.
//

#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H

#include <iostream>

struct Element {
    int row{};
    int col{};
    int val{};

    Element(int row, int col, int val) : row(row), col(col), val(val) {}

    Element() = default;
};

class Matrix {
    int m;          // Dimensions of matrix: mxn where m is row and n is col
    int n;
    int nonZeroCount;           // Stores the number of non-zero elements
    Element *array;
public:
    Matrix(int m, int n, int nonZeroCount);

    friend std::istream &operator>>(std::istream &is, const Matrix &m);         // Input

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);            // Printing

    Matrix add(Matrix &s);          // addition

    virtual ~Matrix();
};


#endif //SPARSE_MATRIX_MATRIX_H
