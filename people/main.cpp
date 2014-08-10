#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "percon.hpp"

int main(int argc, char* argv[])
{
    std::vector<Person> people;

    Person alice("Alice", "alice@example.com");
    Person bobby("Bobby", "bobby@example.com");
    Person chris("Chris");

    people.push_back(alice);
    people.push_back(bobby);
    people.push_back(chris);

    int size = people.size();
    for (int i = 0; i < size; ++i) {
        std::cout << people[i].toString() << std::endl;
        people[i].display();
    }

    return 0;
}
