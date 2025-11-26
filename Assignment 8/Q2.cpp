/*
Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST
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

Node* searchRecursive(Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(key < root->data){
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key){
    while(root != NULL && root->data != key){
        if(key < root->data){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

Node* findMin(Node* root){
    if(root == NULL) return NULL;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root){
    if(root == NULL) return NULL;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* inOrderSuccessor(Node* root, Node* node){
    if(node->right != NULL){
        return findMin(node->right);
    }
    Node* successor = NULL;
    while(root != NULL){
        if(node->data < root->data){
            successor = root;
            root = root->left;
        } else if(node->data > root->data){
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

Node* inOrderPredecessor(Node* root, Node* node){
    if(node->left != NULL){
        return findMax(node->left);
    }
    Node* predecessor = NULL;
    while(root != NULL){
        if(node->data > root->data){
            predecessor = root;
            root = root->right;
        } else if(node->data < root->data){
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

int main(){
    Node* root = NULL;
    vector<int> values = {20, 10, 30, 5, 15, 25, 35};
    for(int val : values){
        root = insert(root, val);
    }

    int key = 15;
    Node* foundNodeRec = searchRecursive(root, key);
    Node* foundNodeNonRec = searchNonRecursive(root, key);
    cout << "Search Recursive: " << (foundNodeRec ? to_string(foundNodeRec->data) : "Not Found") << endl;
    cout << "Search Non-Recursive: " << (foundNodeNonRec ? to_string(foundNodeNonRec->data) : "Not Found") << endl;

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);
    cout << "Minimum Element: " << (minNode ? to_string(minNode->data) : "Tree is empty") << endl;
    cout << "Maximum Element: " << (maxNode ? to_string(maxNode->data) : "Tree is empty") << endl;

    Node* successor = inOrderSuccessor(root, foundNodeRec);
    Node* predecessor = inOrderPredecessor(root, foundNodeRec);
    cout << "In-order Successor of " << key << ": " << (successor ? to_string(successor->data) : "No Successor") << endl;
    cout << "In-order Predecessor of " << key << ": " << (predecessor ? to_string(predecessor->data) : "No Predecessor") << endl;

    return 0;
}