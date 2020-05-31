#include <iostream>
#include "BinaryRelation.hpp"

int main()
{
    BinaryRelation<int,int> test1;
    std::pair<int,int> one(1,11);
    std::pair<int,int> two(2,22);

    test1.addRelation(one);
    test1.addRelation(two);

    test1.printAllRelations();


    return 0;
}
