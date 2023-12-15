// Stack.cpp

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
}

void Stack::push(int element) {
    if (size - top > 1) {
        top++;
        arr[top] = element;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

void Stack::pop() {
    if (top >= 0) {
        top--;
    } else {
        cout << "Stack UnderFlow" << endl;
    }
}

int Stack::peek() {
    if (top >= 0 && top < size) {
        return arr[top];
    } else {
        cout << "Stack is empty" << endl;
        return -1;
    }
}

bool Stack::isEmpty() {
    return top == -1;
}
