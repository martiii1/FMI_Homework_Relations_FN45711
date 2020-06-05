#pragma once
#include "BinaryRelation.hpp"

#define DEFAULT_INITIAL_CAPACITY 20

template<typename T, typename U>
class KnowledgeBse
{
public:
    KnowledgeBse();
    KnowledgeBse(unsigned int initialCapacity);

private:
    BinaryRelation<T,U> *fAllRelations;
    unsigned int fSize;
    unsigned int fCapacity;


    void copy(const KnowledgeBse<T,U> &other);
    void delMem();
    void resizeKnowledgeBse(unsigned int newCapacity);
};

template<typename T, typename U>
KnowledgeBse<T, U>::KnowledgeBse()
{
    fCapacity = DEFAULT_INITIAL_CAPACITY;
    fSize = 0;
    fAllRelations = new BinaryRelation<T,U>[fCapacity];
}

template<typename T, typename U>
KnowledgeBse<T, U>::KnowledgeBse(unsigned int initialCapacity)
{
    fCapacity = initialCapacity;
    fSize = 0;
    fAllRelations = new BinaryRelation<T,U>[fCapacity];
}

template<typename T, typename U>
void KnowledgeBse<T, U>::delMem()
{
    delete [] fAllRelations;
}

template<typename T, typename U>
void KnowledgeBse<T, U>::copy(const KnowledgeBse<T,U> &other)
{
    fAllRelations = new BinaryRelation<T,U>[other.fCapacity];

    fCapacity = other.fCapacity;
    fSize = other.fSize;

    for (int i = 0; i < other.fSize; ++i)
    {
        fAllRelations[i] = other.fAllRelations[i];
    }
}

template<typename T, typename U>
void KnowledgeBse<T, U>::resizeKnowledgeBse(unsigned int newCapacity)
{
    BinaryRelation<T,U> *fAllRelationsTemp = new BinaryRelation<T,U>[newCapacity];

    for (int i = 0; i < fSize; ++i)
    {
        fAllRelationsTemp[i] = fAllRelations[i];
    }

    delMem();

    fAllRelations = fAllRelationsTemp;
}
