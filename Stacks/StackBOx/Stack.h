// Stack.h

#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int size);
    void push(int element);
    void pop();
    int peek();
    bool isEmpty();
};

#endif
