#include <stdio.h>

#include "node.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "my_queue.hpp"

int main(int argc, char* argv[])
{
    Node<int> node(0);
    node.appendToTail(1);
    node.appendToTail(2);
    node.appendToTail(3);
    node.appendToTail(4);

    Stack<int> stack;
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

    Queue<int> queue;
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
