#include <iostream>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtTail(Node* &head,int d);

void InsertAtHead(Node* &head,int d){
    Node* temphead = new Node(d);
    temphead -> next = head;
    head = temphead;
}

void InsertAtPosition(Node* &head,int position,int d){
    if(position == 1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL){
        InsertAtTail(head,d);
        return;
    }

    Node* nodetoInsert = new Node(d);
    nodetoInsert -> next = temp -> next;
    temp -> next = nodetoInsert;
}

void InsertAtTail(Node* &head,int d){
    // if(head == NULL){
    //     head = new Node(d);
    //     return;
    // }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = new Node(d);
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

bool isCircularList(Node* head){

    if(head == NULL){
        return false;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
 
    if(temp == head){
        return true;
    }

    return false;
}

bool detectloop(Node* head){
    if(head==NULL){
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            cout<<"Loop present at element "<<temp->data<<endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// bool floyds(Node* head){

//     if(head == NULL){
//         return false;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(slow != NULL && fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             fast = fast->next;
//         }
//         slow = slow->next;
//         if(slow == fast){
//             return 1;
//         }
//     }
//     return false;
// }

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;

    // Detect loop using Floyd's algorithm
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            loopExists = true;
            break;
        }
    }

    // If no loop exists, return NULL
    if(!loopExists){
        return NULL;
    }

    // Reset one of the pointers to the head
    slow = head;

    // Move both pointers at the same pace until they meet at the starting node of the loop
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


void deleteNode(int position,Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    Node* nodetoDelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete nodetoDelete;
}
int main(){
    Node* head = new Node(5);
    Node* tail = head;
    // cout << node1 -> data << endl;
    // cout<< node1 -> next << endl;
    // cout<<head; //head is pointer to node 
    print(head);
    InsertAtHead(head,12);
    print(head);
    InsertAtTail(head,15);
    print(head);
    InsertAtPosition(head,4,22);
    print(head);
    // deleteNode(2,head);
    // print(head);

    if(isCircularList(head)){
        cout<<"Linked is circular"<<endl;
    }
    else{
        cout<<"Linked is not circular"<<endl;
    }
    tail->next = head->next; // Create a loop from the third node to the second node

    Node* loopStart = getStartingNode(head);
    if (loopStart != NULL) {
        cout << "Starting node of the loop is at element " << loopStart->data << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }
    return 0;
}