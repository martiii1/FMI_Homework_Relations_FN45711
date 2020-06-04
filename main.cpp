#include <iostream>
#include "BinaryRelation.hpp"

int main()
{
    BinaryRelation<int,const char*> test11;
    BinaryRelation<int,const char*> test22;
    BinaryRelation<int,const char*> test33;


    test11.addRelation(1,"one");
    test11.addRelation(2,"two");

    test22.addRelation(5,"five");
    test22.addRelation(6,"six");
    test22.addRelation(1,"one");


    test11.printAllRelations();
    std::cout << "\n\n\n";

    test22.printAllRelations();
    std::cout << "\n\n\n";

    test33 = test11 + test22;

    test33.printAllRelations();
    std::cout << "\n\n\n";


    std::cout << test33[2];
    std::cout << "\n\n\n";

    //test33 = !test33;
    //test33.printAllRelations();
    //std::cout << "\n\n\n";


//
//    BinaryRelation<int,int> test1;
//    BinaryRelation<int,int> test2;
//    BinaryRelation<int,int> test3;
//
//
//    test1.addRelation(1,11);
//    test1.addRelation(2,22);
//
//    test2.addRelation(5,55);
//    test2.addRelation(6,66);
//    test2.addRelation(1,11);
//
//
//    test1.printAllRelations();
//    std::cout << "\n\n\n";
//
//    test2.printAllRelations();
//    std::cout << "\n\n\n";
//
//    test3 = test1 + test2;
//    test3.printAllRelations();
//    std::cout << "\n\n\n";



    return 0;
}
