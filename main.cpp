#include <iostream>
#include "BinaryRelation.hpp"

int main()
{
    BinaryRelation<int,int> test1;
    BinaryRelation<int,int> test2;
    BinaryRelation<int,char const*> test3;

    test3.addRelation(1, "one");
    test3.addRelation(2, "two");
    test3.addRelation(3, "three");


    test1.addRelation(1,11);
    test1.addRelation(2,22);

    test2 = test1;

    test1.printAllRelations();
    std::cout << "\n\n\n";

    test2 = !test1;

    test2.printAllRelations();
    std::cout << "\n\n\n";

    test3.printAllRelations();
    //std::cout << test2(1,21);




    return 0;
}
