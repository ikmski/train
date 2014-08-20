#ifndef _STACK_HPP_
#define _STACK_HPP_

#define STACK_SIZE 256

#include <stdexcept>

template <typename T>
class Stack
{
private:

    int idx;
    T*  stack;

public:

    Stack()
    {
        stack = new T[STACK_SIZE];
        idx = 0;
    }

    ~Stack() {
        delete[] stack;
    };

    void push(T data)
    {
        if (idx > STACK_SIZE) {
            throw std::overflow_error("stack size overflow.");
        }
        stack[idx] = data;
        ++idx;
    }

    T pop()
    {
        if (idx < 1) {
            throw std::range_error("stack is empty.");
        }
        --idx;
        return stack[idx];
    }

    bool isEmpty()
    {
        return (0 == idx);
    }

private:

    Stack(const Stack&);
    Stack& operator = (const Stack&);

};

#endif

