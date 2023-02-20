//
// Created by vivek on 20-02-2023.
//

#ifndef SYMMETRIC_MATRIX_SYMMETRIC_H
#define SYMMETRIC_MATRIX_SYMMETRIC_H
#include <vector>
#include <ostream>

class Symmetric {
    unsigned dimensions;
    std::vector<int> array;
public:
    explicit Symmetric(unsigned int dimensions);

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const Symmetric &triangular);

    unsigned int getDimensions() const;

    virtual ~Symmetric();


};


#endif //SYMMETRIC_MATRIX_SYMMETRIC_H
