#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left"<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right"<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//1->root
/*
    null->queue
    current space in queue = 2
    1->queue
    temp = 1
    1 is popped out of the queue and now queue size is -> 1
    
*/
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout<<temp->data<<" ";
            if(temp -> left){
                q.push(temp->left);
            }

            if(temp -> right){
                q.push(temp->right);
            }
            
        }

    }
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

void buildFromLevelOrder(Node* root){
    queue<Node*> q;
    cout<<"Enter data for root" <<endl;

    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for:"<< temp -> left<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for:"<< temp -> right<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    inorder(root);
    cout<<endl;
    levelOrderTraversal(root);

    return 0;
}