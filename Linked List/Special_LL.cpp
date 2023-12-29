/*
Here we are creating a linked list in which each node has 3 pointers
*/

#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* next2;
    Node* next3;
    Node(int val){
        data = val;
        next = NULL;
        next2 = NULL;
        next3 = NULL;
    }
};

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    Node* temp2 = new Node(data+1);
    Node* temp3 = new Node(data+2);
    temp->next = head;
    temp->next2 = temp2;
    temp->next3 = temp3;
    head = temp;
}

void insertAtTail(Node* &head, int data) {
    if (head == NULL) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    Node* temp2 = new Node(data + 1);
    Node* temp3 = new Node(data + 2);

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new Node(data);
    temp->next->next2 = temp2; // Set next2 for the new tail
    temp->next->next3 = temp3; // Set next3 for the new tail
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        cout << temp->next2->data << " ";
        cout << temp->next3->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtTail(head,2);
    print(head);
    return 0;
}