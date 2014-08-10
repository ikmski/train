
#include <iostream>

#include "label.hpp"

Label::Label()
{
}

Label::Label(const std::string label)
:_label(label)
{
}

Label::~Label()
{
}

void Label::display()
{
    std::cout << "display; " << _label;
}

std::string Label::toString()
{
    return "\"" + _label + "\"";
}

