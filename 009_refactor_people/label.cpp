
#include <iostream>

#include "label.hpp"

People::Label::Label()
{
}

People::Label::Label(const std::string label)
:_label(label)
{
}

People::Label::~Label()
{
}

void People::Label::display()
{
    std::cout << "display; " << _label;
}

std::string People::Label::toString()
{
    return "\"" + _label + "\"";
}

