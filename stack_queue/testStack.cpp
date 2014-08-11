#include <stdio.h>

#include "stack.hpp"

int main(int argc, char* argv[])
{
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


    return 0;
}
