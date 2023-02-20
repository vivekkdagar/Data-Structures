//
// Created by vivek on 20-02-2023.
//

#ifndef TOEPLITZ_MATRIX_TOEPLITZ_H
#define TOEPLITZ_MATRIX_TOEPLITZ_H


#include <vector>
#include <ostream>

class Toeplitz {
    std::vector<int> array;
    unsigned short dimensions;
public:
    explicit Toeplitz(unsigned short dimensions);
    void set(unsigned i, unsigned j, int val);
    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const Toeplitz &toeplitz);

    unsigned short getDimensions() const;
};


#endif //TOEPLITZ_MATRIX_TOEPLITZ_H
