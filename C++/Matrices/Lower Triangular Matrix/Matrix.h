//
// Created by vivek on 18-02-2023.
//

#ifndef LOWER_TRIANGULAR_MATRIX_MATRIX_H
#define LOWER_TRIANGULAR_MATRIX_MATRIX_H


#include <vector>
#include <ostream>

class Matrix {
    int nonZeroElements;
    std::vector<int> A;
    unsigned short dimensions;
public:
    explicit Matrix(unsigned short dimensions);

    void setRowMajor(unsigned short i, unsigned short j, int x);

    int getRowMajor(unsigned short i, unsigned short j) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    void setColMajor(unsigned short i, unsigned short j, int x);

    int getColMajor(unsigned short i, unsigned short j) const;

    void printColMajor();
};


#endif //LOWER_TRIANGULAR_MATRIX_MATRIX_H
