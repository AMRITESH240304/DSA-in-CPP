#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    if(head == nullptr){
        return;
    }
    unordered_set<int> seen;
    Node* curr = head; 
    Node* prev = nullptr;

    while(curr != NULL){
        if(seen.find(curr->data) != seen.end()){
            prev->next = curr->next;
            delete curr;
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main() {
    // Create a sample linked list
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{2, nullptr};
    head->next->next->next->next = new Node{4, nullptr};

    std::cout << "Linked list before removing duplicates: ";
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    removeDuplicates(head);

    std::cout << "Linked list after removing duplicates: ";
    curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    // Clean up the memory
    curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
