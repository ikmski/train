#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <string>

#include "label.hpp"

namespace People
{
    class Person
    {
    private:

        Label* _name;
        Label* _mail;

    public:

        Person(
            const std::string name,
            const std::string mail="");

        ~Person();

        void display();

        std::string toString();

    private:

        Person();
        Person(const Person&);
        Person& operator = (const Person&);

    };
}

#endif

