#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
    int getLength(ListNode* head){
        int length = 0;
        while(head != NULL){
            length++;
            head = head->next; 
        }
        return length;
    }
    public:
    ListNode* rotateRight(ListNode* head, int k) {
        //hard code what comes first to the mind
        int cnt = getLength(head);
        if(head == NULL || head->next == NULL || k==0) return head;
        if (cnt == 0 || k % cnt == 0) return head;

        k = k%cnt;
        int travel = cnt - k;
        ListNode* temp1 = head;
        ListNode* nHead = NULL;

        while(travel > 1){
            temp1 = temp1->next;
            travel--;
        }
        nHead = temp1->next;

        // while(nHead != NULL){
        //     cout<<nHead->val<< " ";
        //     nHead = nHead->next;
        // }
        // cout<<endl;

        temp1->next = NULL;
        ListNode* temp2 = nHead;

        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = head;
        // while(nHead != NULL){
        //     cout<<nHead->val<< " ";
        //     nHead = nHead->next;
        // }
        return nHead;

    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    cout << "Original List: ";
    printList(head);

    int k = 2;
    ListNode* rotatedList = solution.rotateRight(head, k);

    cout << "Rotated List (" << k << " rotations): ";
    printList(rotatedList);

    return 0;
}
