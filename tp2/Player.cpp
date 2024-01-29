#include "Player.hpp"
#include <algorithm>
#include <random>
#include <ostream>
#include <thread>

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

bool Player::play(Player &p1, Player &p2)
{
    auto i = Player::turn_number;
    std::cout << i << std::endl;
    if (i == p1._cards.size())
    {
        return true;
    }

    std::cout << p1._name << " a joué la carte : " << p1[i] << std::endl;
    std::cout << p2._name << " a joué la carte : " << p2[i] << std::endl;

    if (p1[i] == p2[i])
    {
        std::cout << " égalité \n";
        auto cumul = 0;
        do
        {
            if (i + 2 > p1._cards.size())
            {
                Player::turn_number += 1;
                return false;
            }
            Player::turn_number += 2;
            std::cout << " " << p1._name << "  a joué la carte : " << p1[i + 2] << std::endl;
            std::cout << " " << p2._name << "  a joué la carte : " << p2[i + 2] << std::endl;
            i = Player::turn_number;
            cumul += 2;
        } while (p1[i] == p2[i]);
        (p1[i] < p2[i]) ? p2._score += cumul : p1._score += cumul;
    }

    if (p1[i] < p2[i])
    {
        std::cout << p2._name << " gagne la manche \n"
                  << std::endl;
        p2._score++;
    }
    else
    {
        std::cout << p1._name << " gagne la manche \n"
                  << std::endl;
        p1._score++;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Player::turn_number++;

    return false;
}

unsigned int Player::getScore() const
{
    return _score;
}

void Player::winner(Player &p1, Player &p2)
{
    if (p1.getScore() == p2.getScore())
    {
        std::cout << "DRAW " << std::endl;
    }
    else
    {
        auto winner = (p1.getScore() > p2.getScore()) ? p1._name : p2._name;
        std::cout << "Winner is " << winner << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Player &p)
{
    os << p._name;
    return os;
}