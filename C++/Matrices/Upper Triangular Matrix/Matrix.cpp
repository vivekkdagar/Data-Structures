//
// Created by vivek on 20-02-2023.
//

#include "Matrix.h"

Matrix::Matrix(unsigned int dimensions) : dimensions(dimensions) {
    array = new int[dimensions * (dimensions + 1) /
                    2];         // n * (n+1)/2 non 0 elements are in a upper or lower triangular matrix
}

void Matrix::set(unsigned int i, unsigned int j, int value) {
    if (i <= j)
        array[((i - 1) * dimensions - (i - 2) * (i - 1) / 2) + (j - i)] = value;         // row major mapping formula
}

int Matrix::get(unsigned int i, unsigned int j) const {
    if (i <= j)
        return array[((i - 1) * dimensions - (i - 2) * (i - 1) / 2) + (j - i)];
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Matrix &triangular) {
    for (int i{1}; i <= triangular.getDimensions(); i++) {
        for (int j{1}; j <= triangular.getDimensions(); j++)
            os << triangular.get(i, j) << " ";
        os << "\n";
    }
    return os;
}

unsigned int Matrix::getDimensions() const {
    return dimensions;
}

Matrix::~Matrix() {
    delete[]array;
}