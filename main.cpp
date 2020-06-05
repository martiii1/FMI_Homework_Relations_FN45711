#include <iostream>
#include "BinaryRelation.hpp"
#include "KnowledgeBase.hpp"

int main()
{
    BinaryRelation<int,int> test1;
    BinaryRelation<int,int> test2;
    BinaryRelation<int,int> test3;


    test1.addRelation(1,11);
    test1.addRelation(2,22);
    test1.addRelation(3,33);

    test2.addRelation(5,55);
    test2.addRelation(6,66);
    test2.addRelation(11,1111);
    test2.addRelation(2,22);


    test1.printAllRelations();
    std::cout << "\n\n\n";

    test2.printAllRelations();
    std::cout << "\n\n\n";

    test3 = test1 ^ test2;
    test3.printAllRelations();
    std::cout << "\n\n\n";

    test2.dom();
    test2.ran();

    test1^=test2;
    test1.printAllRelations();
    std::cout << "\n\n\n";


    return 0;
}
