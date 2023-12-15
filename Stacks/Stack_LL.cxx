#include <iostream>

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
                                               
// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot perform pop operation." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Top operation
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element: " << stack.peek() << std::endl;

    return 0;
}
