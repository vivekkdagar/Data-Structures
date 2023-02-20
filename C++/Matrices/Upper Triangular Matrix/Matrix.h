//
// Created by vivek on 20-02-2023.
//

#ifndef UPPER_TRIANGULAR_MATRIX_MATRIX_H
#define UPPER_TRIANGULAR_MATRIX_MATRIX_H
#include <iostream>

class Matrix {
    unsigned dimensions;
    int *array;
public:
    explicit Matrix(unsigned int dimensions);

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &triangular);

    unsigned int getDimensions() const;

    virtual ~Matrix();
};


#endif //UPPER_TRIANGULAR_MATRIX_MATRIX_H
