#include <iostream>
#include <climits>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Define the Solution class
class Solution {
public:
    void solve(Node* root, int sum, int &maxSum, int len, int &maxlen) {
        if (root == NULL) {
            if (len > maxlen) {
                maxlen = len;
                maxSum = sum;
            } else if (len == maxlen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum = sum + root->data;
        solve(root->left, sum, maxSum, len + 1, maxlen);
        solve(root->right, sum, maxSum, len + 1, maxlen);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int maxSum = INT_MIN;

        solve(root, sum, maxSum, len, maxlen);

        return maxSum;
    }
};

// Function to create a sample binary tree
Node* createSampleTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);
    return root;
}

int main() {
    // Create a sample binary tree
    Node* root = createSampleTree();

    // Create an instance of the Solution class
    Solution solution;

    // Call the sumOfLongRootToLeafPath function and print the result
    int result = solution.sumOfLongRootToLeafPath(root);
    cout << "Maximum sum of the long root to leaf path: " << result << endl;

    // Clean up: Deallocate memory used by the tree
    // (This part is essential to avoid memory leaks)
    // ... (Add code to deallocate memory)

    return 0;
}
