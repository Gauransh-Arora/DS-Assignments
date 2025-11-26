/*
Write a program to determine whether a given binary tree is a BST or not.
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
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

bool isBSTUtil(Node* node, int minVal, int maxVal){
    if(node == NULL) return true;
    if(node->data < minVal || node->data > maxVal) return false;
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root1 = NULL;
    vector<int> values = {20, 10, 30, 5, 15, 25, 35};
    for(int val : values){
        root1 = insert(root1, val);
    }

    if(isBST(root1)){
        cout << "The binary tree is a BST." << endl;
    } else {
        cout << "The binary tree is not a BST." << endl;
    }

    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);

    root2->left->right = new Node(15);

    if(isBST(root2)){
        cout << "The binary tree is a BST." << endl;
    } else {
        cout << "The binary tree is not a BST." << endl;
    }

    return 0;
}