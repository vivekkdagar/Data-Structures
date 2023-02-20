//
// Created by vivek on 18-02-2023.
//

#ifndef DIAGONAL_MATRIX_MATRIX_H
#define DIAGONAL_MATRIX_MATRIX_H


#include <vector>
#include <ostream>

class Matrix {
    const unsigned short dimension;
    std::vector<int> array;
public:
    explicit Matrix(unsigned short dimension);

    void set(unsigned short i, unsigned short j, int x);

    int get(unsigned short i, unsigned short j) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};


#endif //DIAGONAL_MATRIX_MATRIX_H
