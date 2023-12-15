#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve(stack<int>& mystack,int x){
    if(mystack.empty()){
        mystack.push(x);
        return;
    }

    int num = mystack.top();
    mystack.pop();
    solve(mystack,x);

    mystack.push(num);
}

stack<int> pushBottom(stack<int>& mystack,int x){
    solve(mystack,x);
    return mystack;
}
int main(){

    stack<int> mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);

    int x = 5;
    stack<int> modified = pushBottom(mystack,x);

    while(!modified.empty()){
        cout<<modified.top()<<" ";
        modified.pop();
    }
    cout<<endl;
    return 0;
}