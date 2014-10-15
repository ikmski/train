#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "node.hpp"

template <typename T>
class Stack
{
private:

    Node<T>* top;

public:

    Stack()
    : top(0)
    {
    }

    ~Stack() {
        if (top) {
            delete top;
            top = 0;
        }
    };

    void push(T data)
    {
        Node<T>* tmp = new Node<T>(data);
        tmp->setNext(top);
        top = tmp;
    }

    T pop()
    {
        T result = 0;
        if (top) {
            result = top->getData();
            top = top->getNext();
        }
        return result;
    }

    bool isEmpty()
    {
        return (top)?false:true;
    }

private:

    Stack(const Stack&);
    Stack& operator = (const Stack&);

};

#endif

