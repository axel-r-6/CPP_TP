#include "Card.hpp"

int main()
{
    Card c1(8, "Pique");
    c1.print();
    std::cout << "Opérateur == " << std::endl;
    Card const c2(8, "Carreau");
    std::cout << (c2 == c1) << std::endl; // -> 1
    Card const c3(10, "Carreau");
    std::cout << (c2 == c3) << std::endl; // -> 0

    std::cout << "Opérateur < " << std::endl;
    std::cout << (c1 < c2) << std::endl; // -> 0
    std::cout << (c1 < c3) << std::endl; // -> 1
    std::cout << (c3 < c1) << std::endl; // -> 0

    Card cAs(1, "Pique");
    Card c11(11, "Pique");
    Card c12(12, "Pique");
    Card c13(13, "Pique");
    cAs.print();
    c11.print();
    c12.print();
    c13.print();
}