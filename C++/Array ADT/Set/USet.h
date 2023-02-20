//
// Created by vivek on 26-01-2023.
//

#ifndef SET_USET_H
#define SET_USET_H


#include <vector>
#include <ostream>

class USet {            // Unordered set
    std::vector<int> array;
public:
    explicit USet(const std::vector<int> &array);

    USet();

    void Union(USet src);

    void Intersection(USet src);

    void Difference(USet src);

    friend std::ostream &operator<<(std::ostream &os, const USet &set);
};


#endif //SET_USET_H
