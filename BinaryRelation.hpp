#pragma once

#include <iostream>

template<typename T, typename U>
class BinaryRelation
{
public:
    BinaryRelation();

    BinaryRelation(unsigned int initialCapacity);

    BinaryRelation(const BinaryRelation<T, U> &other);

    BinaryRelation &BinaryRelation::operator=(const BinaryRelation<T, U> &other);

    ~BinaryRelation();

    void addRelation(const T &newFirst, const U &newSecond);

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


template<typename T, typename U>
BinaryRelation<T, U>::BinaryRelation()
{
    BinaryRelation<T, U>(10);
}

template<typename T, typename U>
BinaryRelation<T, U>::BinaryRelation(unsigned int initialCapacity)
{
    fCapacity = initialCapacity;
    fSize = 0;
    fRelationsFirst = new T[initialCapacity];
    fRelationsSecond = new U[initialCapacity];
}

template<typename T, typename U>
BinaryRelation<T, U>::~BinaryRelation()
{
    delMem();
}

template<typename T, typename U>
void BinaryRelation<T, U>::delMem()
{
    delete[] fRelationsFirst;
    delete[] fRelationsSecond;
}

template<typename T, typename U>
BinaryRelation<T, U>::BinaryRelation(const BinaryRelation<T, U> &other)
{
    copy(other);
}

template<typename T, typename U>
void BinaryRelation<T, U>::copy(const BinaryRelation<T, U> &other)
{
    fRelationsFirst = new T[other.fCapacity];
    fRelationsSecond = new U[other.fCapacity];

    for (int i = 0; i < other.fSize; i++)
    {
        fRelationsFirst[i] = other.fRelationsFirst[i];
        fRelationsSecond[i] = other.fRelationsSecond[i];
    }
}

template<typename T, typename U>
BinaryRelation<T, U> &BinaryRelation<T, U>::operator=(const BinaryRelation<T, U> &other)
{
    if (this != &other)
    {
        delMem();
        copy(other);
    }
    else
    {
        return *this;
    }
}

template<typename T, typename U>
void BinaryRelation<T, U>::addRelation(const T &newFirst, const U &newSecond)
{
    if (fSize <= fCapacity - 1)
        resizeRelations(fCapacity * 2);

    fRelationsFirst[fSize] = newFirst;
    fRelationsSecond[fSize] = newSecond;
    fSize++;
}

template<typename T, typename U>
void BinaryRelation<T, U>::resizeRelations(unsigned int newCapacity)
{
    T *tempNewRelationsFirst = new T[newCapacity];
    U *tempNewRelationsSecond = new U[newCapacity];

    for (int i = 0; i < fSize; i++)
    {
        tempNewRelationsFirst[i] = fRelationsFirst[i];
        tempNewRelationsSecond[i] = fRelationsSecond[i];
    }

    delMem();

    fRelationsFirst = tempNewRelationsFirst;
    fRelationsSecond = tempNewRelationsSecond;
}

template<typename T, typename U>
void BinaryRelation<T, U>::printAllRelations()
{
    for (int i = 0; i < fSize; i++)
    {
        std::cout << fRelationsFirst[i] << " " << fRelationsSecond[i] << "\n";
    }

}
