#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;

                if (frontNode->left) {
                    q.push(frontNode->left);
                }

                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
            result.push_back(ans);
            leftToRight = !leftToRight;
        }
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution solution;
    
    TreeNode* root = createSampleTree(); 

    vector<vector<int>> zigzagOrder = solution.zigzagLevelOrder(root);

    // Displaying the result
    cout << "Zigzag level order traversal:" << endl;
    for (const auto& level : zigzagOrder) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
