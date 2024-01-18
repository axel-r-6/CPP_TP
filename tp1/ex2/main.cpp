#include "Person.hpp"
#include <iostream>

int main()
{
    /*
    Person p;
    p.first_name = "Palluche";
    p.surname = "La Faluche";

    std::cout << "Person named " << p.first_name << " " << p.surname << std::endl;
    */
    /*
    Person p("Paluche", "La Faluche");

    std::cout << "Person named : " << p.get_first_name() << " " << p.get_surname() << std::endl;
    */

    unsigned int number;

    do
    {

        std::cout << "Nombre de personnes: ";
        std::cin >> number;

    } while (number < 0);

    std::vector<Person> persons;

    for (size_t i = 0; i < number; i++)
    {
        std::string first_name;
        std::string surname;
        std::cout << "Prenom :";
        std::cin >> first_name;
        std::cout << "Nom :";
        std::cin >> surname;
        Person p(first_name, surname);
        persons.push_back(p);
    }

    std::cout << "Les personnes sont ";
    for (size_t i = 0; i < number; i++)
    {
        std::cout << persons[i].get_first_name() << " " << persons[i].get_surname();

        std::cout << ((i < number - 1) ? ", " : ".");
    }
    std::cout << std::endl;
}