#include <iostream>
#include <vector>
using namespace std;

class Queue{

    int* arr;
    int front;
    int rear;
    int size;
public:
    Queue(){
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(front == rear) return true;
        else return false;
    }

    void enqueue(int data){
        if (rear == size ){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            return -1;
        }
        else {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front ==  rear){
                front = 0;
                rear = 0;
            }
        return ans;
        }
    }

    int qfront(){
        if(front == rear) return -1;
        else return arr[front];
    }
};


int main(){
    Queue q;
    q.enqueue(22);
    q.enqueue(33);
    q.enqueue(44);
    cout<<q.qfront()<<endl;
    q.dequeue();
    cout<<q.qfront()<<endl;
    
    return 0;
}