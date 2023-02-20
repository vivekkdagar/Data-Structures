//
// Created by vivek on 18-02-2023.
//

#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned short dimension) : dimension(dimension) {
    array.resize(dimension);
}

void Matrix::set(unsigned short i, unsigned short j, int x) {
    if (i == j)
        this->array[i - 1] = x;
}

int Matrix::get(unsigned short i, unsigned short j) const {
    return (i == j) ? this->array[i - 1] : 0;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i{1}; i <= matrix.dimension; i++) {
        for (int j{1}; j <= matrix.dimension; j++)
            os << matrix.get(i, j) << " ";
        os << std::endl;
    }
    return os;
}
