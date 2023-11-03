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

Node* reverse(Node* &head,int k){
    if(head == NULL){
        return NULL;
    }
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int count = 0;
    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        cout<<curr -> data << " ";
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = reverse(next,k);
    }

    return prev;
}

Node* kreverse(Node* &head,int k){
    if (head == NULL){
        return NULL;
    }
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        // cout<<curr->next<<" ";
        cout<<curr->data<<" ";
        prev = curr;
        // cout<<prev->next;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = kreverse(next,k);
    }

    return prev;
}

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

int main() {
    Node* head = new Node(5);
    for(int i = 0;i < 6;i++){
        insertAtHead(head,i);
    }
    print(head);
    
    int k = 2; 
    head = kreverse(head, k);

    cout << "\nLinked List after k-reverse: ";
    print(head);
    return 0;
}
