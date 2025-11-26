/*
Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
    Node(int val, Node* l, Node* r){
        data = val;
        left = l;
        right = r;
    }
};

Node* insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    } else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return root;
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    } else if(key > root->data){
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while(temp && temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root = NULL;
    vector<int> values = {20, 10, 30, 5, 15, };
    for(int val : values){
        root = insert(root, val);
    }

    cout << "Max Depth of BST: " << maxDepth(root) << endl;
    cout << "Min Depth of BST: " << minDepth(root) << endl;

    int delKey = 10;
    root = deleteNode(root, delKey);
    cout << "After deleting " << delKey << ", Max Depth of BST: " << maxDepth(root) << endl;
    cout << "After deleting " << delKey << ", Min Depth of BST: " << minDepth(root) << endl;

    return 0;
}