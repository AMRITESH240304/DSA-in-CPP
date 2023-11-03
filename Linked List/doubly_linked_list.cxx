#include <iostream>
using namespace std;
class Node{
    public:

    int data;
    Node *next;
    Node *prev;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


//function to reverse a linked list

void reverseDoublyLinkedList(Node* &head, Node* &tail) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Swap the next and prev pointers of the current node
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        // Move to the next node
        current = temp;
    }

    // Update the head and tail pointers
    temp = head;
    head = tail;
    tail = temp;
}



// void print(Node* head) {
//     Node* temp = head;
    
//     while (temp != NULL) {
//         cout << "(" << temp << ") <- " << temp->prev << " [" << temp->data << "] " << temp->next << " -> ";
//         temp = temp->next;
//     }
    
//     cout << "NULL" << endl;
// }


void insertAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    temp->prev = temp;
    head = temp;
}

void insertAtposition(Node* &head,int position,int d){
    Node* temp = new Node(d);
    Node* temp1 = head;
    for(int i=0;i<position-1;i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp->prev = temp1;
    temp1->next = temp;
}

void insertAttail(Node* &tail,int d){
    Node* temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;/*but how it is pointing to tail
    how the fuck it pointing without traversing
    bruhhhhhh howwwwwwwww
    nor chatgpt can help bitch no 
    actually bitchless 
    fucker dont have any bitchess*/
}

int main(){
    Node* node1 = new Node(10);
    Node* tail = node1;
    Node* head = node1;
    cout<<head;
    print(head);

    insertAthead(head,11);
    print(head);

    insertAthead(head,13);
    print(head);

    insertAthead(head,8);
    print(head);

    insertAttail(tail,25);
    print(head);
    insertAttail(tail,26);
    print(head);

    insertAtposition(head,2,14);
    print(head);


    reverseDoublyLinkedList(head, tail);
    cout << "Reversed List: ";
    print(head);
    return 0;
}
 