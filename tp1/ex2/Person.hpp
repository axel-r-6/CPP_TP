#include <string>

class Person
{

public:
    Person()
    {
    }

    Person(const std::string &firstname, const std::string &surname)
        : _first_name(firstname), _surname(surname){};

    std::string get_first_name() const
    {
        return _first_name;
    };

    std::string get_surname() const
    {
        return _surname;
    };

private:
    std::string _first_name;
    std::string _surname;
};