#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 1. Pre-order Traversal: Root -> Left -> Right
void preOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data); // Process the root
    preOrder(node->left);      // Traverse the left subtree
    preOrder(node->right);     // Traverse the right subtree
}

// 2. In-order Traversal: Left -> Root -> Right
void inOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);       // Traverse the left subtree
    printf("%d ", node->data); // Process the root
    inOrder(node->right);      // Traverse the right subtree
}

// 3. Post-order Traversal: Left -> Right -> Root
void postOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postOrder(node->left);      // Traverse the left subtree
    postOrder(node->right);     // Traverse the right subtree
    printf("%d ", node->data); // Process the root
}

int main() {
    // Create a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
