#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Constructing the tree manually using linked nodes

    // Create the root node
    struct TreeNode* root = createNode(1);

    // Create the left subtree of the root
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Create the right subtree of the root
    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // The tree structure now looks like this:
    //
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7

    // You can now perform operations on this tree, like traversal

    printf("Pre-order traversal: ");
    // Assuming you have a preOrder traversal function (as in the previous example)
    void preOrder(struct TreeNode* node); // Declare the function
    preOrder(root);
    printf("\n");

    // Remember to free the allocated memory when you are done with the tree
    // (This part is important to prevent memory leaks but is not shown here for brevity)

    return 0;
}

// Definition of the preOrder traversal function (from the previous example)
void preOrder(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
