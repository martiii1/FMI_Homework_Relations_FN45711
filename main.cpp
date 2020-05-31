#include <iostream>
#include "BinaryRelation.hpp"

int main()
{
    BinaryRelation<int,int> test1;


    test1.addRelation(1,11);
    test1.addRelation(2,22);

    test1.printAllRelations();


    return 0;
}
