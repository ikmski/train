
#include "person.hpp"

Person::Person
(
    const std::string name,
    const std::string mail="")
{
    Label _name(name);
    Label _mail(mail);
}

Person::~Person()
{
}

void Person::display()
{
    _name.display();
    _mail.display();
}

void Person::toString()
{
    _name.toString();
    _mail.toString();
}

