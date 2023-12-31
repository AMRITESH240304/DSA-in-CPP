#include <iostream>
#include <utility> // for pair
using namespace std;

class Solution
{
public:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

public:
    pair<bool,int> isSumTreeFast(Node* root){
        if(root == nullptr){
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }

        if(root->left == nullptr && root->right == nullptr){
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);

        bool left = leftAns.first;
        bool right = rightAns.first;

        bool cond = (root->data == leftAns.second + rightAns.second);

        pair<bool,int> ans;

        if(left && right && cond){
            ans.first = true;
            ans.second = root->data + leftAns.second + rightAns.second;
        } else {
            ans.first = false;
            ans.second = 0; // Reset the sum to 0 in case of failure
        }

        return ans;
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};

// Main function
int main() {

    Solution solution;

    Solution::Node* root = new Solution::Node(26);
    root->left = new Solution::Node(10);
    root->right = new Solution::Node(3);
    root->left->left = new Solution::Node(4);
    root->left->right = new Solution::Node(6);
    root->right->right = new Solution::Node(3);

    bool isSumTreeResult = solution.isSumTree(root);

    if(isSumTreeResult) {
        cout << "The tree is a sum tree." << endl;
    } else {
        cout << "The tree is not a sum tree." << endl;
    }

    // Perform any cleanup for allocated memory if needed

    return 0;
}
