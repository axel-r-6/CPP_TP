#include "Person.hpp"
#include <iostream>

int main()
{
    Person p;
    p.first_name = "Palluche";
    p.surname = "La Faluche";

    std::cout << "Person named " << p.first_name << " " << p.surname << std::endl;
}