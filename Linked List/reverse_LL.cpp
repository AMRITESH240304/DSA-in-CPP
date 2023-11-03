#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* head) {
    while (head != NULL) { 
        cout << head->data << " ";
        head = head->next;
    }
}

Node* reverseLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node* head = new Node(5);
    for(int i = 0;i < 6;i++){
        insertAtHead(head,i);
    }
    
    head = reverseLL(head); 
    print(head);
    
    return 0;
}
