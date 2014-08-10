#ifndef _LABEL_HPP_
#define _LABEL_HPP_

#include <string>

class Label
{
private:

    std::string _label;

public:

    Label();
    Label(const std::string label);

    ~Label();

    void display();

    std::string toString();

private:

    Label(const Label&);
    Label& operator = (const Label&);

};

#endif

