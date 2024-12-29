#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

// Function to create a new node 
TNode* newNode(int data) {
    TNode* node = new TNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to count the number of leaf nodes in the tree
int count_leaf(TNode *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return count_leaf(root->left) + count_leaf(root->right);
}

// Function to count the number of non-leaf nodes in the tree
int count_nonleaf(TNode *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + count_nonleaf(root->left) + count_nonleaf(root->right);
}

// Function to check if the queried node is a leaf
bool isleaf(TNode *root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value && root->left == NULL && root->right == NULL) {
        return true;
    }
    return isleaf(root->left, value) || isleaf(root->right, value);
}

int main() {
    // Constructing the binary tree
    TNode* root = newNode(14);
    root->left = newNode(4);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->right->left = newNode(14);
    root->right->right = newNode(18);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(9);
    root->left->right->left = newNode(7);
    root->right->right->left = newNode(16);
    root->right->right->left->right = newNode(17);
    root->left->right->left->left = newNode(5);
    root->left->right->left->left->left = newNode(4);
    root->left->right->left->left->right = newNode(5);

    // Test functions
    cout << "Number of leaf nodes: " << count_leaf(root) << endl;
    cout << "Number of non-leaf nodes: " << count_nonleaf(root) << endl;

    // Test the isleaf function
    int value = 9;
    if (isleaf(root, value)) {
        cout << value << " is a leaf node." << endl;
    } else {
        cout << value << " is NOT a leaf node." << endl;
    }

    return 0;
}
