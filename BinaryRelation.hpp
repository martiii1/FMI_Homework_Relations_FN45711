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

    void addRelation(T newFirst, U newSecond);

    void printAllRelations();
private:
    T *fRelationsFirst;
    U *fRelationsSecond;

    unsigned int fCapacity;
    unsigned int fSize;


    void delMem();

    void copy(const BinaryRelation<T, U> &other);

    void resizeRelations(unsigned int newCapacity);

};

