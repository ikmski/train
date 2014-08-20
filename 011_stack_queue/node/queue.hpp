#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "node.hpp"

template <typename T>
class Queue
{
private:

    Node<T>* head;
    Node<T>* tail;

public:

    Queue()
    : head(0), tail(0)
    {
    }

    ~Queue() {
        if (head) {
            delete head;
            head = 0;
        }
        if (tail) {
            delete tail;
            tail = 0;
        }
    };

    void enqueue(T data)
    {
        if (!head) {
            tail = new Node<T>(data);
            head = tail;
        }
        else {
            Node<T>* tmp = new Node<T>(data);
            tail->setNext(tmp);
            tail = tail->getNext();
        }
    }

    T dequeue()
    {
        T result = 0;
        if (head) {
            result = head->getData();
            head = head->getNext();
        }

        return result;
    }

private:

    Queue(const Queue&);
    Queue& operator = (const Queue&);

};

#endif

