#include <string>
#include "Card.hpp"
#include <iostream>

class Player
{
private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score;

public:
    Player(const std::string &name, std::vector<Card> cards, unsigned int score);
    Player(const std::string &name);
    static void deal_all_cards(Player &p1, Player &p2);
    static bool play(Player &p1, Player &p2);
    Card operator[](unsigned int index) const;
    unsigned int Player::turn_number;
};
