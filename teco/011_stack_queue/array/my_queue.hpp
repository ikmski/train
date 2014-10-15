#ifndef _MY_QUEUE_HPP_
#define _MY_QUEUE_HPP_

#include "stack.hpp"

template <typename T>
class MyQueue
{
private:

    Stack<T> stack_new;
    Stack<T> stack_old;

public:

    MyQueue()
    {
    }

    ~MyQueue()
    {
    };

    void enqueue(T data)
    {
        while (!stack_old.isEmpty()) {
            stack_new.push(stack_old.pop());
        }
        stack_new.push(data);
    }

    T dequeue()
    {
        while (!stack_new.isEmpty()) {
            stack_old.push(stack_new.pop());
        }
        return stack_old.pop();
    }

private:

    MyQueue(const MyQueue&);
    MyQueue& operator = (const MyQueue&);

};

#endif

