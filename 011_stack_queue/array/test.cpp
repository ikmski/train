#include <stdio.h>

#include "stack.hpp"
#include "queue.hpp"
#include "my_queue.hpp"

int main(int argc, char* argv[])
{
    Stack<int> stack;
    Queue<int> queue;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());
    printf("%d\n", stack.pop());

    printf("\n");

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    printf("%d\n", queue.dequeue());
    printf("%d\n", queue.dequeue());
    printf("%d\n", queue.dequeue());
    printf("%d\n", queue.dequeue());
    printf("%d\n", queue.dequeue());

    printf("\n");

    MyQueue<int> myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    printf("%d\n", myQueue.dequeue());
    printf("%d\n", myQueue.dequeue());
    printf("%d\n", myQueue.dequeue());
    printf("%d\n", myQueue.dequeue());
    printf("%d\n", myQueue.dequeue());

    return 0;
}
