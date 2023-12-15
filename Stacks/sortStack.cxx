#include <iostream>
#include <stack>
using namespace std;


void sortedInsert(stack<int> &s,int num){
    // base case;
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sortedInsert(s,num);

    s.push(n);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortedInsert(stack,num);
}

int main(){
    stack<int> stack;
    stack.push(5);
    stack.push(3);
    stack.push(1);
    stack.push(4);
    stack.push(2);

    sortStack(stack);

    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }

}