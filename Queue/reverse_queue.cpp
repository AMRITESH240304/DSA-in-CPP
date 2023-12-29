#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    queue<int> rev(queue<int> q) {
        stack<int> s;

        while (!q.empty()) {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        while (!s.empty()) {
            int element = s.top();
            s.pop();
            q.push(element);
        }

        return q;
    }
};

int main() {
    Solution obj;
    queue<int> originalQueue;

    originalQueue.push(1);
    originalQueue.push(2);
    originalQueue.push(3);
    originalQueue.push(4);
    originalQueue.push(5);

    cout << "Original Queue: ";
    queue<int> tempQueue = originalQueue; 
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    queue<int> reversedQueue = obj.rev(originalQueue);

    cout << "Reversed Queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    
    return 0;
}
