#include <iostream>

#include "person.hpp"

People::Person::Person
(
    const std::string name,
    const std::string mail)
{
    _name = new Label(name);
    _mail = new Label(mail);
}

People::Person::~Person()
{
    delete _name;
    delete _mail;
}

void People::Person::display()
{
    _name->display();
    std::cout << " ";
    _mail->display();
    std::cout << std::endl;
}

std::string People::Person::toString()
{
    return _name->toString() + ", " + _mail->toString();
}

