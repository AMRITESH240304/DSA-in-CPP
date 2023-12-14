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

void push_to_node(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* add_two_list(Node* head,Node* secondList){
    int num1=0,num2 = 0;

    while(head->next != NULL){
        // cout<<head->data<<endl;
        num1 += head->data;
        num1 *= 10;
        head = head->next;
    }
    num1 += head->data;
    // cout<<"value of num1 "<<num1<<endl;

    while(secondList->next != NULL){
        num2 += secondList->data;
        num2 *= 10;
        secondList = secondList->next;
    }
    num2 += secondList->data;
    // cout<<"value of num2 "<<num2<<endl;

    int num3 = num1+num2;
    // cout<<"value of num3 "<<num3<<endl;

    Node* temp = NULL;

    while(num3 != 0){
        int last = num3%10;
        push_to_node(temp,last);
        num3=num3/10;
    }

    return temp;
}

int main(){
    Node* head = new Node(5);
    Node* secondList = new Node(2);

    for(int i = 0;i<4;i++){
        push_to_node(head,i);
    }

    for(int i = 0;i<4;i++){
        push_to_node(head,i);
    }

    for(int i=0;i<2;i++){
        push_to_node(secondList,i);
    }

    print(head);
    print(secondList);

    Node* ans = add_two_list(head,secondList);

    cout<<"The sum is : ";
    print(ans);
    
    return 0;
}