#include <iostream>
#include <map>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    std::map<int, bool> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            Node* duplicate = curr;
            curr = curr->next; 
            delete duplicate;
        } else {
            seen[curr->data] = true; 
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Node* removeDuplicates(Node* head) {
//     if (head == nullptr) {
//         return nullptr;
//     }
    
//     Node* curr = head;
    
//     while (curr != nullptr) {
//         Node* runner = curr;
//         while (runner->next != nullptr) {
//             if (runner->next->data == curr->data) {
//                 // Duplicate found, remove the next node
//                 Node* duplicate = runner->next;
//                 runner->next = runner->next->next;
//                 delete duplicate;
//             } else {
//                 runner = runner->next;
//             }
//         }
//         curr = curr->next;
//     }
    
//     return head;
// }

Node* removeDuplicates(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    map<int, bool> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            delete prev;
            curr = prev->next; 
        } else {
            seen[curr->data] = true; 
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}


// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    std::cout << "Original Linked List: ";
    displayList(head);

    // Call the removeDuplicates function
    head = removeDuplicates(head);

    std::cout << "Linked List after removing duplicates: ";
    displayList(head);

    return 0;
}
