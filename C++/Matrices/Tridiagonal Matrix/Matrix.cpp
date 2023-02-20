//
// Created by vivek on 20-02-2023.
//

#include "Matrix.h"

Matrix::Matrix(unsigned short dimensions) : dimensions(dimensions) {
    unsigned size = 3 * dimensions - 2;
    array.resize(size);
}

unsigned short Matrix::getDimensions() const {
    return dimensions;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i{1}; i <= 5; i++) {
        for (int j{1}; j <= 5; j++) {
            if (i - j == 1)
                os << matrix.array[i - 2] << " ";
            else if (i - j == 0)
                os << matrix.array[matrix.dimensions + i - 2] << " ";
            else if (i - j == -1)
                os << matrix.array[2 * matrix.dimensions + i - 2] << " ";
            else
                os << 0 << " ";
        }
        os << std::endl;
    }
    return os;
}

void Matrix::set(unsigned short i, unsigned short j, int value) {
    if (i - j == 1)
        this->array[i - 2] = value;
    else if (i - j == 0)
        this->array[dimensions + i - 2] = value;
    else if (i - j == -1)
        this->array[2 * dimensions + i - 2] = value;
}

int Matrix::get(unsigned short i, unsigned short j) const {
    int t = i - j;
    switch (t) {
        case 1:
            return this->array[i - 2];
        case 0:
            return this->array[dimensions + i - 2];
        case -1:
            return this->array[2 * dimensions + i - 2];
        default:
            return 0;
    }
}



Matrix::~Matrix() = default;
