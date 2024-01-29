#include "Player.hpp"

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

    Player p1("Gerald");
    Player p2("Julien");
    Player::deal_all_cards(p1, p2);

    for (size_t i = 0; i < 16; ++i)
    {
        p1[i].print();
        std::cout << std::endl;
        p2[i].print();
        std::cout << std::endl;
    }

    // Player::play(p1, p2);
    while (!Player::play(p1, p2))
    {
        std::cout << p1 << " : " << p1.getScore() << std::endl;
        std::cout << p2 << " : " << p2.getScore() << std::endl;
    }

    Player::winner(p1, p2);
}