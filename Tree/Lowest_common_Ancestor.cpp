#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)//we traverse till the root and then return the root of NULL or element found
            return root;
        auto ansl=lowestCommonAncestor(root->left,p,q);
        auto ansr=lowestCommonAncestor(root->right,p,q);
        if(ansl==NULL) //if one side is null we return other side
            return ansr;
        else if(ansr==NULL)
            return ansl;
        else //if both null we return root(NULL)
            return root;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;

    // Example: Find the lowest common ancestor of nodes with values 5 and 1
    TreeNode* p = root->left;   // Node with value 5
    TreeNode* q = root->right;  // Node with value 1

    TreeNode* result = solution.lowestCommonAncestor(root, p, q);

    // Output the result
    if (result != NULL) {
        std::cout << "Lowest Common Ancestor: " << result->val << std::endl;
    } else {
        std::cout << "No common ancestor found." << std::endl;
    }

    // Clean up: Delete the dynamically allocated nodes (optional)
    // Note: In a real-world scenario, you might want to use smart pointers or another memory management approach.
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
