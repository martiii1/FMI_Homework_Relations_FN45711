#include "BinaryRelation.hpp"

template<class T, class U>
BinaryRelation<T, U>::BinaryRelation()
{
    BinaryRelation<T, U>(10);
}

template<class T, class U>
BinaryRelation<T, U>::BinaryRelation(unsigned int initialCapacity)
{
    fCapacity = initialCapacity;
    fSize = 0;
    fRelations = new std::pair<T, U>[initialCapacity];
}

template<class T, class U>
BinaryRelation<T, U>::~BinaryRelation()
{
    delMem();
}

template<class T, class U>
void BinaryRelation<T, U>::delMem()
{
    delete[] fRelations;
}

template<class T, class U>
BinaryRelation<T, U>::BinaryRelation(const BinaryRelation<T, U> &other)
{
    copy(other);
}

template<class T, class U>
void BinaryRelation<T, U>::copy(const BinaryRelation<T, U> &other)
{
    fRelations = new std::pair<T, U>[other.fCapacity];

    for (int i = 0; i < other.fSize; i++)
    {
        fRelations[i] = other.fRelations[i];
    }
}

template<class T, class U>
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

template<class T, class U>
void BinaryRelation<T, U>::addRelation(std::pair<T, U> newPair)
{
    if (fSize <= fCapacity - 1)
        resizeRelations(fCapacity * 2);

    fRelations[fSize] = newPair;
    fSize++;
}

template<class T, class U>
void BinaryRelation<T, U>::resizeRelations(unsigned int newCapacity)
{
    std::pair<T, U> *tempNewRelations = new std::pair<T, U>[newCapacity];

    for (int i = 0; i < fSize; i++)
    {
        tempNewRelations[i] = fRelations[i];
    }
    delMem();

    fRelations = tempNewRelations;
}

template<class T, class U>
void BinaryRelation<T, U>::printAllRelations()
{
    for (int i = 0; i < fSize; i++)
    {
        std::cout << fRelations[i] << " " << fRelations[i] << "\n";
    }

}
