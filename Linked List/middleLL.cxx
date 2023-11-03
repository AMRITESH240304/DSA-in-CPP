#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* middleofLinkedList(Node* head);
void insertAtHead(Node* &head,int data);
int getlen(Node* head);
void print(Node* head);

int main(){
    Node* head = new Node(5);
    for(int i = 1;i<=6;i++){
        insertAtHead(head,i);
    }
    print(head);

    Node* middle = middleofLinkedList(head);
    cout << middle->data << endl;
    cout<<middle->next<<endl;


    return 0;
}

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

int getlen(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node* middleofLinkedList(Node* head){
    int len = getlen(head);
    int ans = len/2;
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }
    cout<<temp->next<<endl;
    return temp;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}