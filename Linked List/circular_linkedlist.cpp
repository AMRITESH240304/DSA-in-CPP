#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
        ~Node(){
            int value = this->data;
            if(this->next == NULL){
                delete next;
                next = NULL;
            }
            cout<<"Memory id free for node with data "<<value<<endl;
        }
};

void insertNode(Node* &tail,int element,int d);
void print(Node* tail);
void deleteNode(Node* &tail,int value){
    if(tail == NULL){
        cout<<" list is empty"<<endl;
        return;
    }
    else{
        //asuming that value is present in the linked list;
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
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
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){

    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    // deleteNode(tail,3);
    // print(tail);

    if(isCircularList(tail)){
        cout<<"Linked is circular"<<endl;
    }
    else{
        cout<<"Linked is not circular"<<endl;
    }

    return 0;
}

void insertNode(Node* &tail,int element,int d){
    //assuming the elemnt is present in the list

    if(tail == NULL){
        Node* n = new Node(d);
        tail = n;
        n->next = n;
    }
    else{
        //non empty list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    } while( tail != temp);
    cout<<endl;
}