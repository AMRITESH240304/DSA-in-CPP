#include <iostream>
#include <stack>
using namespace std;
 
class Stack{

    public: 
    int *arr;
    int top;
    int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top >1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow" <<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }

    int peek(){
        if(top >= 0 && top < size){
            return arr[top];
        }
        else{
            cout <<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }
};

int main(){
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<<st.peek()<<endl;
    return 0;
}

// int main(){

//     stack<int> s;

//     s.push(2);
//     s.push(3);

//     s.pop();
//     cout<< "printing top element "<<s.top()<<endl;

//     if(s.empty()){
//         cout<<"stack is empty "<<endl;
//     }
//     else{
//         cout<<"Stack is not empty "<<endl;
//     }

//     return 0;
// }