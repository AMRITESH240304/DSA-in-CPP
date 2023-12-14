#include <iostream>
#include <unordered_set>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // if (head == NULL)
        // {
        //     return NULL;
        // }
        // ListNode *curr = head;
        // while (curr != NULL)
        // {
        //     if ((curr->next != NULL) && (curr->val == curr->next->val))
        //     {
        //         ListNode *next_next = curr->next->next;
        //         ListNode *delNode = curr->next;
        //         delete (delNode);
        //         curr->next = next_next;
        //     }
        //     else
        //     {
        //         curr = curr->next;
        //     }
        // }
        // return head;

        if(head == NULL) return NULL;
        ListNode* curr = head;
        unordered_set<int> seen;
        ListNode* prev = NULL;

        while(curr != NULL){
            if(seen.find(curr->val) != seen.end()){
                prev->next = curr->next;
                delete curr;
            } 
            else {
                seen.insert(curr->val);
                 prev= curr;
            }
            curr = prev->next;
        }

    return head;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating the linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;

    std::cout << "Original list: ";
    printList(head);

    // Calling deleteDuplicates function
    ListNode *result = solution.deleteDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(result);

    return 0;
}
