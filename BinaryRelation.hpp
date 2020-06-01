#pragma once

#include <iostream>

#define DEFAULT_INITIAL_CAPACITY 10

template<typename T, typename U>
class BinaryRelation
{
public:
    BinaryRelation();

    BinaryRelation(unsigned int initialCapacity);

    BinaryRelation(const BinaryRelation<T, U> &other);

    BinaryRelation &BinaryRelation::operator=(const BinaryRelation<T, U> &other);

    BinaryRelation &operator!();

    bool &operator()(const T &first, const U &second);

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
    fCapacity = DEFAULT_INITIAL_CAPACITY;
    fSize = 0;
    fRelationsFirst = new T[fCapacity];
    fRelationsSecond = new U[fCapacity];
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
    fRelationsFirst = nullptr;
    fRelationsSecond = nullptr;

    fRelationsFirst = new T[other.fCapacity];
    fRelationsSecond = new U[other.fCapacity];

    fCapacity = other.fCapacity;
    fSize = other.fSize;

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

    return *this;
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

template<typename T, typename U>
bool &BinaryRelation<T, U>::operator()(const T &first, const U &second)
{
    bool inRelation = false;

    for (int i = 0; i < fSize; i++)
    {
        if (fRelationsFirst[i] == first && fRelationsSecond[i] == second)
        {
            inRelation = true;
            break;
        }
    }

    return inRelation;
}

template<typename T, typename U>
BinaryRelation<T, U> &BinaryRelation<T, U>::operator!()
{
    BinaryRelation<T, U> *tempRelation = new BinaryRelation<T, U>(fCapacity);
    tempRelation->fCapacity = fCapacity;
    tempRelation->fSize = fSize;

    for (int i = 0; i < fSize; i++)
    {
        tempRelation->fRelationsFirst[i] = fRelationsSecond[i];
        tempRelation->fRelationsSecond[i] = fRelationsFirst[i];
    }

    return *tempRelation;
}
