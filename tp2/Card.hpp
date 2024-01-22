#include <string>
#include <iostream>

class Card
{
private:
    unsigned int _value;
    std::string _color;

public:
    Card(const unsigned int value, const std::string &color);
    void print() const;
    int operator==(Card c) const;
    int operator<(Card c) const;
};
