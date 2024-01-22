#include "Card.hpp"

Card::Card(const unsigned int value, const std::string &color)
    : _value(value), _color(color) {}

void Card::print() const
{
    switch (_value)
    {
    case 14:
        std::cout << "As de " << _color << std::endl;
        break;
    case 11:
        std::cout << "Valet de " << _color << std::endl;
        break;

    case 12:
        std::cout << "Dame de " << _color << std::endl;
        break;
    case 13:
        std::cout << "Roi de " << _color << std::endl;
        break;

    default:
        std::cout << _value << " de " << _color << std::endl;
        break;
    }
}

int Card::operator==(Card c) const
{
    return (_value == c._value);
}

int Card::operator<(Card c) const
{
    return (_value < c._value);
}

std::ostream &operator<<(std::ostream &os, const Card &c)
{
    os << c._value << " de " << c._color;
    return os;
}