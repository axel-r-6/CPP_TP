#include <string>
#include "Card.hpp"
#include <iostream>

class Player
{
private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score;
    inline static unsigned int turn_number;

public:
    Player(const std::string &name);
    static void deal_all_cards(Player &p1, Player &p2);
    static bool play(Player &p1, Player &p2);
    Card operator[](unsigned int index) const;
    unsigned int getScore() const;
    static void winner(Player &p1, Player &p2);
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
};
