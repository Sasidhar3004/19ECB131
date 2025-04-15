#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int key;
    struct node *left, *right;
    bool isThreaded;
};

struct node *newNode(int key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->isThreaded = false;
    return temp;
}

struct node *createThreaded(struct node *root) {
    if (!root) return NULL;

    if (root->left) {
        struct node *l = createThreaded(root->left);

        l->right = root;
        l->isThreaded = true;
    }

    if (root->right && !root->isThreaded)
        return createThreaded(root->right);

    return root;
}

struct node *leftMost(struct node *root) {
    while (root && root->left)
        root = root->left;
    return root;
}

void inOrder(struct node *root) {
    struct node *cur = leftMost(root);
    while (cur) {
        printf("%d ", cur->key);

        if (cur->isThreaded)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    createThreaded(root);

    printf("Inorder traversal of created threaded tree: ");
    inOrder(root);
    printf("\n");
    return 0;
}
