#pragma once

#include <iostream>
#include <cstring>

#define DEFAULT_INITIAL_CAPACITY 10

template<typename T, typename U>
class BinaryRelation
{
public:
    BinaryRelation();

    BinaryRelation(unsigned int initialCapacity);

    BinaryRelation(const BinaryRelation<T, U> &other);

    BinaryRelation &BinaryRelation::operator=(const BinaryRelation<T, U> &other);

    BinaryRelation &BinaryRelation::operator+(const BinaryRelation<T, U> &other);

    BinaryRelation<U, T> &operator!();

    bool &operator()(const T &first, const U &second);

    U &operator[](const T &first);

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

    void resizeRelations(unsigned int newCapacity); // FIX

    void removeDuplicates();

    void removePair(unsigned int pairNumber);

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

    for (int i = 0; i < other.fSize; ++i)
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

    for (int i = 0; i < fSize; ++i)
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
    for (int i = 0; i < fSize; ++i)
    {
        std::cout << fRelationsFirst[i] << " " << fRelationsSecond[i] << "\n";
    }

}


template<typename T, typename U>
bool &BinaryRelation<T, U>::operator()(const T &first, const U &second)
{
    bool inRelation = false;

    for (int i = 0; i < fSize; ++i)
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
BinaryRelation<U, T> &BinaryRelation<T, U>::operator!()
{
    BinaryRelation<U, T> *tempRelation = new BinaryRelation<U, T>(fCapacity);
    tempRelation->fCapacity = fCapacity;
    tempRelation->fSize = fSize;

    for (int i = 0; i < fSize; ++i)
    {
        tempRelation->fRelationsFirst[i] = fRelationsSecond[i];
        tempRelation->fRelationsSecond[i] = fRelationsFirst[i];
    }

    return *tempRelation;
}


template<typename T, typename U>
BinaryRelation<T, U> &BinaryRelation<T, U>::operator+(const BinaryRelation<T, U> &other)
{
    unsigned int tempCapacity = fSize + other.fSize;

    BinaryRelation<T, U> *tempRelation = new BinaryRelation<T, U>(tempCapacity);
    tempRelation->fCapacity = tempCapacity;
    tempRelation->fSize = fSize + other.fSize;

    unsigned int counter = 0;

    for (int i = 0; i < fSize; ++i)
    {
        tempRelation->fRelationsFirst[counter] = fRelationsFirst[i];
        tempRelation->fRelationsSecond[counter] = fRelationsSecond[i];
        counter++;
    }

    for (int i = 0; i < other.fSize; ++i)
    {
        tempRelation->fRelationsFirst[counter] = other.fRelationsFirst[i];
        tempRelation->fRelationsSecond[counter] = other.fRelationsSecond[i];
        counter++;
    }

    tempRelation->removeDuplicates();

    return *tempRelation;
}



template<typename T, typename U>
void BinaryRelation<T, U>::removeDuplicates()
{
    for (int i = 0; i < fSize; ++i)
    {
        for (int j = i + 1; j < fSize; ++j)
        {
            if (fRelationsFirst[i] == fRelationsFirst[j] &&
                fRelationsSecond[i] == fRelationsSecond[j])
            {
                removePair(j);
            }

        }
    }
}


template<>
void BinaryRelation<int, const char *>::removeDuplicates()
{
    for (int i = 0; i < fSize; ++i)
    {
        for (int j = i + 1; j < fSize; ++j)
        {
            if (fRelationsFirst[i] == fRelationsFirst[j] &&
                strcmp(fRelationsSecond[i],fRelationsSecond[j]) == 0)
            {
                removePair(j);
            }

        }
    }
}


template<typename T, typename U>
void BinaryRelation<T, U>::removePair(unsigned int pairNumber)
{
    if (pairNumber >= fSize)
        throw std::exception("Invalid pair number! \n");

    T *tempRelationsFirst = new T[fSize - 1];
    U *tempRelationsSecond = new U[fSize - 1];

    unsigned int newCounter = 0;
    for (int i = 0; i < fSize; ++i)
    {
        if (i == pairNumber)
            continue;

        tempRelationsFirst[newCounter] = fRelationsFirst[i];
        tempRelationsSecond[newCounter] = fRelationsSecond[i];
        newCounter++;
    }

    delMem();
    fRelationsFirst = tempRelationsFirst;
    fRelationsSecond = tempRelationsSecond;
    fSize--;
}

template<typename T, typename U>
U &BinaryRelation<T, U>::operator[](const T &first)
{
    for (int i = 0; i < fSize; ++i)
    {
        if(fRelationsFirst[i] == first)
            return fRelationsSecond[i];
    }
}
