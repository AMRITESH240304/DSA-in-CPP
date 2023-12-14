#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
    ~Node() {
        // Destructor implementation
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory id free for node with data " << value << endl;
    }
};

bool isPalindrome(Node* head) {
    vector<int> arr;
    Node* temp = head;

    // Storing elements of linked list in vector
    while(temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next; // Corrected: Changed temp->data to temp->next
    }

    // Checking for palindrome
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        if(arr[left] != arr[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Checking if the linked list is a palindrome
    if(isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    // Remember to free the allocated memory
    delete head;

    return 0;
}
