#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "person.hpp"

int main(int argc, char* argv[])
{
    std::vector<People::Person*> people;

    People::Person* alice = new People::Person("Alice", "alice@example.com");
    People::Person* bobby = new People::Person("Bobby", "bobby@example.com");
    People::Person* chris = new People::Person("Chris");

    people.push_back(alice);
    people.push_back(bobby);
    people.push_back(chris);

    int size = people.size();
    for (int i = 0; i < size; ++i) {
        std::cout << people[i]->toString() << std::endl;
        people[i]->display();
    }

    delete chris;
    delete bobby;
    delete alice;

    return 0;
}
