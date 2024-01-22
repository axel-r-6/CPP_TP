#include "Player.hpp"
#include <algorithm>
#include <random>
#include <ostream>

Player::Player(const std::string &name, std::vector<Card> cards, unsigned int score)
    : _name(name), _cards(cards), _score(score){};

Player::Player(const std::string &name)
    : _name(name){};

void Player::deal_all_cards(Player &p1, Player &p2)
{
    std::vector<std::string> colors;
    colors.push_back("Pique");
    colors.push_back("Trefle");
    colors.push_back("Coeur");
    colors.push_back("Carreau");
    std::vector<Card> all_cards;
    for (size_t i = 7; i <= 14; i++)
    {
        for (auto color : colors)
        {
            all_cards.emplace_back(i, color);
        };
    };
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(time(0)));
    auto mid = all_cards.capacity() / 2;
    for (size_t i = 0; i < all_cards.capacity(); i++)
    {
        if (i < all_cards.capacity() / 2)
        {
            p1._cards.emplace_back(all_cards[i]);
        }
        else
        {
            p2._cards.emplace_back(all_cards[i]);
        }
    }
};

Card Player::operator[](unsigned int index) const
{
    if (index > 16)
    {
        std::cerr << "Index out of Bounds" << std::endl;
    }
    return _cards[index];
};

static bool play(Player &p1, Player &p2)
{
}