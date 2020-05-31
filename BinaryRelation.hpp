#pragma once

#include <iostream>

template<class T, class U>
class BinaryRelation
{
public:
    BinaryRelation();

    BinaryRelation(unsigned int initialCapacity);

    BinaryRelation(const BinaryRelation<T, U> &other);

    BinaryRelation &BinaryRelation::operator=(const BinaryRelation<T, U> &other);

    ~BinaryRelation();

    void addRelation(std::pair<T,U> newPair);

    void printAllRelations();
private:
    std::pair<T, U> *fRelations;
    unsigned int fCapacity;
    unsigned int fSize;


    void delMem();

    void copy(const BinaryRelation<T, U> &other);

    void resizeRelations(unsigned int newCapacity);

};

