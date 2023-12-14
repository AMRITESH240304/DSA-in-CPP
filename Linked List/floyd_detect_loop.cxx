#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    if (head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;

        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow -> next;

        if(slow == fast){
            return 1;
        }
    }
    return false;
}

int main() {
    // Create a linked list with a loop
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = third;  // Creating a loop

    if (detectLoop(head)) {
        std::cout << "Loop detected in the linked list." << std::endl;
    } else {
        std::cout << "No loop detected in the linked list." << std::endl;
    }

    // Clean up memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
