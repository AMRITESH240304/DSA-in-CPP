#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector<int> verticalOrder(Node* root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;

        vector<int> ans;
        if (root == nullptr)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : nodes) {
            for (auto j : i.second) {
                for (auto k : j.second) {
                    ans.push_back(k);
                }
            }
        }

        return ans;
    }
};

int main() {
    // Create a sample tree
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 7;

    Solution solution;
    vector<int> result = solution.verticalOrder(root);

    // Print the vertical order traversal
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
