#include <iostream>
#include "BinaryRelation.hpp"
#include "KnowledgeBase.hpp" // not working

int main()
{
    BinaryRelation<int, int> test1;
    BinaryRelation<int, int> test2;
    BinaryRelation<int, int> test3;
    BinaryRelation<int, int> test4;
    BinaryRelation<int, int> test5;


    test1.addRelation(1, 11);
    test1.addRelation(2, 22);
    test1.addRelation(3, 33);

    test2.addRelation(5, 55);
    test2.addRelation(6, 66);
    test2.addRelation(11, 1111);
    test2.addRelation(2, 22);
    // test2.addRelation(5,555); // test2 is not partial function ( test2.function() -> false )
    // test2.addRelation(8,22);  // test2 is not injection ( test2.injection() -> false )

    std::cout << "test1\n";
    test1.printAllRelations();
    std::cout << "\n\n";

    std::cout << "test2\n";
    test2.printAllRelations();
    std::cout << "\n\n";

    std::cout << "test1 + test2\n";
    test5 = test1 + test2;
    test5.printAllRelations();
    std::cout << "\n\n";


    std::cout << "test1 * test2\n";
    test4 = test1 * test2;
    test4.printAllRelations();
    std::cout << "\n\n";

    std::cout << "test1 ^ test2\n";
    test3 = test1 ^ test2;
    test3.printAllRelations();
    std::cout << "\n\n";

    std::cout << "test1 ^= test2\n";
    test1 ^= test2;
    test1.printAllRelations();
    std::cout << "\n\n";

    test2.dom();
    test2.ran();

    std::cout << "\ntest2 injection check: ";
    std::cout << test2.injection();
    std::cout << "\ntest2 function check: ";
    std::cout << test2.function();


    return 0;
}
