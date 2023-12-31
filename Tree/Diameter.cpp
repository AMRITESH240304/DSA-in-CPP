#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::pair<int, int> dia(TreeNode* node) {
        if (node == nullptr) {
            std::pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        std::pair<int, int> p;
        std::pair<int, int> leftAns = dia(node->left);
        std::pair<int, int> rightAns = dia(node->right);
        int ld = leftAns.first;
        int lh = leftAns.second;
        int rd = rightAns.first;
        int rh = rightAns.second;
        p.first = std::max(lh + rh, std::max(ld, rd));
        p.second = 1 + std::max(lh, rh);
        return p;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = dia(root).first;
        return ans;
    }
};

// Utility function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // Add more nodes as needed to create the desired tree structure
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createSampleTree();

    int diameter = solution.diameterOfBinaryTree(root);
    std::cout << "Diameter of the binary tree is: " << diameter << std::endl;
    return 0;
}
