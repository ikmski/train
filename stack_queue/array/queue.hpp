#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#define QUEUE_SIZE 256

#include <stdexcept>

template <typename T>
class Queue
{
private:

    int head;
    int tail;
    T*  queue;

public:

    Queue()
    {
        queue = new T[QUEUE_SIZE];
        head = 0;
        tail = 0;
    }

    ~Queue() {
        delete[] queue;
    };

    void enqueue(T data)
    {
        int tmp = tail+1;
        if (QUEUE_SIZE == tmp) tmp = 0;
        if (tmp == head) {
            throw std::overflow_error("queue size overflow.");
        }

        queue[tail] = data;
        ++tail;
        if (QUEUE_SIZE == tail) tail = 0;
    }

    T dequeue()
    {
        if (head == tail) {
            throw std::range_error("queue is empty.");
        }

        T data = queue[head];
        ++head;
        return data;
    }

private:

    Queue(const Queue&);
    Queue& operator = (const Queue&);

};

#endif

