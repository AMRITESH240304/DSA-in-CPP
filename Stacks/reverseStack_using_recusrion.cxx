#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &stack,int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }

    int x = stack.top();
    stack.pop();
    insertAtBottom(stack,num);

    stack.push(x);
}

void reverse(stack<int> &stack){
    if(stack.empty()) return;

    int num = stack.top();
    stack.pop();

    reverse(stack);
    insertAtBottom(stack,num);

}
int main(){
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    reverse(stack);

    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    return 0;
}