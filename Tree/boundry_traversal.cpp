#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void lefts(TreeNode<int> *root, vector<int> &v)

{

    if (!root || (!root->left && !root->right))
        return;

    v.push_back(root->data);

    if (root->left)
        lefts(root->left, v);

    else if (root->right)
        lefts(root->right, v);
}

void rights(TreeNode<int> *root, vector<int> &v)

{

    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    if (root->right)
        rights(root->right, v);

    else if (root->left)
        rights(root->left, v);

    v.push_back(root->data);
}

void leaf(TreeNode<int> *root, vector<int> &v)

{

    if (!root->left && !root->right)

    {
        v.push_back(root->data);
        return;
    }

    if (!root)
        return;

    if (root->left)
        leaf(root->left, v);

    if (root->right)
        leaf(root->right, v);
}

vector<int> traverseBoundary(TreeNode<int> *root)

{

    vector<int> v;

    if (root == NULL)
        return v;

    v.push_back(root->data);

    if (root->left == NULL && root->right == NULL)

        return v;

    if (root->left)

        lefts(root->left, v);

    leaf(root, v);

    if (root->right)

        rights(root->right, v);

    return v;
}


int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    vector<int> result = traverseBoundary(root);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

